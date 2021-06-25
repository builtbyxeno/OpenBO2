/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
==============
jqProfGetThread
==============
*/
jqProfThread *jqProfGetThread(unsigned __int64 id)
{
  int v1; // eax
  _QWORD *v2; // ecx
  signed __int32 v3; // esi
  jqProfThread *result; // eax
  char *v5; // esi

  v1 = 0;
  if ( jqProfThreadCount <= 0 )
  {
LABEL_5:
    v3 = _InterlockedIncrement(&jqProfThreadCount);
    if ( v3 <= 128 )
    {
      v5 = (char *)&jqProfThreads + 256 * v3;
      *(_QWORD *)v5 = id;
      *((_DWORD *)v5 + 32) = 0;
      memset(v5 + 132, 0, 0x7Cu);
      _snprintf(v5 + 8, 0x78u, "Thread 0x%x", (_DWORD)id);
      result = (jqProfThread *)v5;
    }
    else
    {
      jqProfThreadCount = 128;
      result = NULL;
    }
  }
  else
  {
    v2 = &jqProfThreads;
    while ( *v2 != id )
    {
      ++v1;
      v2 += 32;
      if ( v1 >= jqProfThreadCount )
        goto LABEL_5;
    }
    result = (jqProfThread *)((char *)&jqProfThreads + 256 * v1);
  }
  return result;
}

/*
==============
jqProfSetThreadName
==============
*/
void jqProfSetThreadName(unsigned __int64 id, const char *Name)
{
  jqProfThread *v2; // eax

  v2 = jqProfGetThread(id);
  _snprintf(v2->Name, 0x78u, "%s", Name);
}

/*
==============
jqProfBeginCapture
==============
*/
void jqProfBeginCapture()
{
  jqProfFrame = 0;
  jqProfEventCur = jqProf.EventBuffer;
  jqProfStartTime = tlPcGetTick().QuadPart;
}

/*
==============
jqProfPrintf
==============
*/
void jqProfPrintf(int fd, _iobuf *jqProfFile, const char *Format, ...)
{
  char Work[512]; // [esp+4h] [ebp-204h]
  va_list ap; // [esp+21Ch] [ebp+14h]

  va_start(ap, Format);
  _vsnprintf(Work, 0x200u, Format, ap);
  if ( fd < 0 )
    fwrite(Work, strlen(Work), 1u, jqProfFile);
}

/*
==============
jqProfEndCaptureWrite
==============
*/
void jqProfEndCaptureWrite(_iobuf *jqProfFile, int fd)
{
  int v2; // ebx
  char *v3; // edi
  unsigned __int32 v4; // ebx
  jqProfEvent *v5; // ecx
  bool v6; // cf
  jqProfEvent *v7; // edi
  int v8; // eax
  unsigned __int64 v9; // kr00_8
  jqProfThread *v10; // esi
  bool v11; // zf
  signed int v12; // eax
  int v13; // eax
  char *v14; // eax
  int v15; // [esp+14h] [ebp-8h]
  jqProfEvent *EventLast; // [esp+18h] [ebp-4h]

  jqProfPrintf(fd, jqProfFile, "JQProf=1,TICKS_PER_MS=%f\n", tlPcTicksPerMS);
  jqProfPrintf(fd, jqProfFile, "#,Thread,Level,Start,Stop,Time,Description,Color\n");
  v2 = jqProfThreadCount;
  if ( jqProfThreadCount > 0 )
  {
    v3 = byte_823D8B4;
    do
    {
      *((_DWORD *)v3 - 1) = 0;
      memset(v3, 0, 0x7Cu);
      v3 += 256;
      --v2;
    }
    while ( v2 );
  }
  v4 = _InterlockedExchangeAdd((volatile signed __int32 *)&jqProfEventCur, 0x80u);
  *(_DWORD *)(v4 + 8) = -1;
  *(_DWORD *)(v4 + 12) = -1;
  v5 = jqProf.EventBuffer;
  EventLast = (jqProfEvent *)v4;
  if ( jqProf.EventBuffer < (jqProfEvent *)v4 )
  {
    do
    {
      if ( SLODWORD(v5->ThreadId) >= 0 )
      {
        v6 = LODWORD(v5->Tick) < (unsigned int)jqProfStartTime;
        LODWORD(v5->Tick) -= jqProfStartTime;
        HIDWORD(v5->Tick) -= v6 + HIDWORD(jqProfStartTime);
      }
      else
      {
        v5->Tick -= (unsigned int)jqProfStartTime;
      }
      ++v5;
    }
    while ( (unsigned int)v5 < v4 );
  }
  v7 = jqProf.EventBuffer;
  if ( jqProf.EventBuffer < (jqProfEvent *)v4 )
  {
    do
    {
      v8 = HIDWORD(v7->ThreadId);
      v9 = v7->ThreadId;
      v10 = jqProfGetThread(v7->ThreadId);
      if ( v10 )
      {
        if ( !strncmp(v7->Description, "$frame", 6u) )
        {
          jqProfPrintf(
            fd,
            jqProfFile,
            "%d,%s,%d,%llu,%llu,%llu,%s,%08x\n",
            v7 - jqProf.EventBuffer,
            v10->Name,
            v10->StackLevel,
            LODWORD(v7->Tick),
            HIDWORD(v7->Tick),
            LODWORD(v7->Tick),
            HIDWORD(v7->Tick),
            0,
            0,
            v7->Description,
            v7->Color);
        }
        else
        {
          v11 = strcmp(v7->Description, "$end") == 0;
          v12 = v10->StackLevel;
          if ( v11 )
          {
            if ( v12 > 0 )
            {
              v13 = v12 - 1;
              v15 = v13;
              v10->StackLevel = v13;
              v14 = (char *)v10->Stack[v13];
              if ( v14 )
                jqProfPrintf(
                  fd,
                  jqProfFile,
                  "%d,%s,%d,%llu,%llu,%llu,%s,%08x\n",
                  (v14 - (char *)jqProf.EventBuffer) >> 7,
                  v10->Name,
                  v15,
                  *((_DWORD *)v14 + 2),
                  *((_DWORD *)v14 + 3),
                  LODWORD(v7->Tick),
                  HIDWORD(v7->Tick),
                  v7->Tick - *((_QWORD *)v14 + 1),
                  v14 + 32,
                  *((_DWORD *)v14 + 4));
            }
            v10->Stack[v10->StackLevel] = NULL;
          }
          else if ( v12 < 30 )
          {
            v10->Stack[v12] = v7;
            ++v10->StackLevel;
          }
        }
        v4 = (unsigned __int32)EventLast;
      }
      ++v7;
    }
    while ( (unsigned int)v7 < v4 );
  }
  fflush(jqProfFile);
  tlPrintf("jqProf: Capture complete.  Recorded %d events.\n", (signed int)(v4 - (unsigned int)jqProf.EventBuffer) >> 7);
}

/*
==============
jqProfEndCapture
==============
*/
void jqProfEndCapture(const char *Name)
{
  char *v1; // esi
  int v2; // eax
  signed int v3; // esi
  _iobuf *i; // eax
  _BYTE *v5; // eax
  _iobuf *v6; // eax
  char TempPath[256]; // [esp+4h] [ebp-304h]
  char SysPath[256]; // [esp+104h] [ebp-204h]
  char Path[256]; // [esp+204h] [ebp-104h]

  v1 = (char *)Name;
  if ( dword_8245868 )
  {
    if ( !Name )
      v1 = "capture";
    strchr(v1, 46);
    if ( v2 )
      _snprintf(Path, 0x100u, "%s", v1);
    else
      _snprintf(Path, 0x100u, "%s.jqprof", v1);
    v3 = 1;
    _snprintf(SysPath, 0x100u, "%s", Path);
    for ( i = fopen(SysPath, "rb"); i; i = fopen(SysPath, "rb") )
    {
      fclose(i);
      _snprintf(TempPath, 0x100u, "%s", Path);
      strrchr(TempPath, 46);
      if ( v3 <= 1 )
        *v5 = 0;
      else
        *(v5 - 3) = 0;
      _snprintf(Path, 0x100u, "%s%03d.jqprof", TempPath, v3++);
      _snprintf(SysPath, 0x100u, "%s", Path);
    }
    tlPrintf("JQProf: Saving CPU capture to '%s'...\n", Path);
    v6 = fopen(SysPath, "w");
    jqProfFile = v6;
    if ( v6 )
    {
      jqProfEndCaptureWrite(v6, -1);
      fclose(jqProfFile);
    }
    else
    {
      tlPrintf("JQProf: Unable to open '%s' for write.\n", Path);
    }
  }
}

/*
==============
jqProfInit
==============
*/
void jqProfInit(unsigned int MaxEvents, void *Buffer)
{
  jqProf.EventBuffer = (jqProfEvent *)Buffer;
  dword_8245868 = MaxEvents;
  jqProfEventCur = (struct jqProfEvent *)Buffer;
  dword_8245864 = (int)&jqProfEventCur;
}

/*
==============
jqProfBeginNamedEvent
==============
*/
void jqProfBeginNamedEvent(unsigned int Color, const char *Description)
{
  unsigned __int32 v2; // esi
  jqProfEvent *v3; // eax

  if ( dword_8245868 )
  {
    v2 = _InterlockedExchangeAdd((volatile signed __int32 *)dword_8245864, 0x80u);
    v3 = &jqProf.EventBuffer[dword_8245868];
    if ( v2 < (unsigned int)v3 )
    {
      *(_DWORD *)v2 = GetCurrentThreadId();
      *(_DWORD *)(v2 + 4) = 0;
      *(_LARGE_INTEGER *)(v2 + 8) = tlPcGetTick();
      *(_DWORD *)(v2 + 16) = Color;
      _snprintf((char *)(v2 + 32), 0x60u, "%s", Description);
    }
    else
    {
      *(_DWORD *)dword_8245864 = v3;
    }
  }
}

/*
==============
jqProfEndNamedEvent
==============
*/
void jqProfEndNamedEvent()
{
  jqProfBeginNamedEvent(0, "$end");
}

/*
==============
jqCheckCaptureSignal
==============
*/
void jqCheckCaptureSignal(void)
{
    ;
}

/*
==============
jqProfMarkFrame
==============
*/
void jqProfMarkFrame()
{
  char work[40]; // [esp+0h] [ebp-2Ch]

  _snprintf(work, 0x28u, "$frame%d", jqProfFrame);
  jqProfBeginNamedEvent(0, work);
  ++jqProfFrame;
}

/*
==============
jqProfGetInfo
==============
*/
jqProfInfo *jqProfGetInfo()
{
  return &jqProf;
}

