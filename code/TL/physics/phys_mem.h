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
phys_free_list<NitrousVehicle>::debug_remove
==============
*/
void __thiscall phys_free_list<NitrousVehicle>::debug_remove(phys_free_list<NitrousVehicle> *this, phys_free_list<NitrousVehicle>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<NitrousVehicle> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           422,
           "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].m_phys_user_data = (PhysObjUserData *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_simple_allocator<gjk_cylinder_t>::free
==============
*/
void __thiscall phys_simple_allocator<gjk_cylinder_t>::free(phys_simple_allocator<gjk_cylinder_t> *this, gjk_cylinder_t *slot)
{
  phys_simple_allocator<gjk_cylinder_t> *v2; // edi
  bool v3; // zf

  v2 = this;
  if ( slot )
  {
    PMM_VALIDATE(slot, 0xA0u, 0x10u);
    --v2->m_count;
    v3 = (slot->m_flags & 1) == 0;
    slot->vfptr = (phys_gjk_geomVtbl *)&gjk_base_t::`vftable';
    if ( !v3
      && _tlAssert(
           "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
           87,
           "!get_flag(FLAG_TEMP_ALLOCATION)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    PMM_FREE(slot, 0xA0u, 0x10u);
  }
}

/*
==============
phys_simple_allocator<gjk_double_sphere_t>::free
==============
*/
void __thiscall phys_simple_allocator<gjk_double_sphere_t>::free(phys_simple_allocator<gjk_double_sphere_t> *this, gjk_double_sphere_t *slot)
{
  phys_simple_allocator<gjk_double_sphere_t> *v2; // edi
  bool v3; // zf

  v2 = this;
  if ( slot )
  {
    PMM_VALIDATE(slot, 0x90u, 0x10u);
    --v2->m_count;
    v3 = (slot->m_flags & 1) == 0;
    slot->vfptr = (phys_gjk_geomVtbl *)&gjk_base_t::`vftable';
    if ( !v3
      && _tlAssert(
           "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
           87,
           "!get_flag(FLAG_TEMP_ALLOCATION)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    PMM_FREE(slot, 0x90u, 0x10u);
  }
}

/*
==============
phys_simple_allocator<gjk_polygon_cylinder_t>::free
==============
*/
void __thiscall phys_simple_allocator<gjk_polygon_cylinder_t>::free(phys_simple_allocator<gjk_polygon_cylinder_t> *this, gjk_polygon_cylinder_t *slot)
{
  phys_simple_allocator<gjk_polygon_cylinder_t> *v2; // edi
  bool v3; // zf

  v2 = this;
  if ( slot )
  {
    PMM_VALIDATE(slot, 0x80u, 0x10u);
    --v2->m_count;
    v3 = (slot->m_flags & 1) == 0;
    slot->vfptr = (phys_gjk_geomVtbl *)&gjk_base_t::`vftable';
    if ( !v3
      && _tlAssert(
           "c:\\t6\\code\\src_noserver\\physics\\phys_colgeom.h",
           87,
           "!get_flag(FLAG_TEMP_ALLOCATION)",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    PMM_FREE(slot, 0x80u, 0x10u);
  }
}

/*
==============
phys_link_list<gjk_geom_info_t>::add
==============
*/
void __thiscall phys_link_list<gjk_geom_info_t>::add(phys_link_list<gjk_geom_info_t> *this, gjk_geom_info_t *p)
{
  phys_link_list<gjk_geom_info_t> *v2; // esi
  gjk_geom_info_t **v3; // edx

  v2 = this;
  if ( !this->m_last_next_ptr
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  p->m_next_link = NULL;
  v3 = v2->m_last_next_ptr;
  ++v2->m_alloc_count;
  *v3 = p;
  v2->m_last_next_ptr = &p->m_next_link;
}

/*
==============
phys_free_list<PhysObjUserData>::debug_remove
==============
*/
void __thiscall phys_free_list<PhysObjUserData>::debug_remove(phys_free_list<PhysObjUserData> *this, phys_free_list<PhysObjUserData>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<PhysObjUserData> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           422,
           "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].body = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<PhysObjUserData>::remove_all
==============
*/
void __thiscall phys_free_list<PhysObjUserData>::remove_all(phys_free_list<PhysObjUserData> *this)
{
  phys_free_list<PhysObjUserData> *v1; // esi
  phys_free_list<PhysObjUserData>::T_internal *v2; // edi
  phys_free_list<PhysObjUserData>::T_internal_base *v3; // eax
  phys_free_list<PhysObjUserData>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<PhysObjUserData> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<PhysObjUserData>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
      __debugbreak();
    --v1->m_list_count;
    phys_free_list<PhysObjUserData>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x160u, 0x10u);
  }
}

/*
==============
phys_free_list<RagdollBody>::debug_remove
==============
*/
void __thiscall phys_free_list<RagdollBody>::debug_remove(phys_free_list<RagdollBody> *this, phys_free_list<RagdollBody>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<RagdollBody> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           422,
           "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].references = T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<VehicleParameter>::debug_remove
==============
*/
void __thiscall phys_free_list<VehicleParameter>::debug_remove(phys_free_list<VehicleParameter> *this, phys_free_list<VehicleParameter>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<VehicleParameter> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           422,
           "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    LODWORD(v3->m_ptr_list[--v3->m_ptr_list_count][1].m_speed_max) = T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<PhysObjUserData>::~phys_free_list<PhysObjUserData>
==============
*/
void __thiscall phys_free_list<PhysObjUserData>::~phys_free_list<PhysObjUserData>(phys_free_list<PhysObjUserData> *this)
{
  phys_free_list<PhysObjUserData> *v1; // esi

  v1 = this;
  phys_free_list<PhysObjUserData>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<PhysObjUserData> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<PhysObjUserData> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<PhysObjUserData>::add
==============
*/
PhysObjUserData *__thiscall phys_free_list<PhysObjUserData>::add(phys_free_list<PhysObjUserData> *this, const int no_error, const char *error_msg)
{
  phys_free_list<PhysObjUserData> *v3; // esi
  char *v4; // eax
  int v5; // edx
  signed int v6; // edx
  PhysObjUserData *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x160u, 0x10u);
  if ( v4 )
  {
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 7) = 0;
    *((_DWORD *)v4 + 44) = 0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<PhysObjUserData>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<PhysObjUserData>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 84) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 84) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (PhysObjUserData *)(v4 + 16);
    }
    result = (PhysObjUserData *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<RagdollBody>::remove_all
==============
*/
void __thiscall phys_free_list<RagdollBody>::remove_all(phys_free_list<RagdollBody> *this)
{
  phys_free_list<RagdollBody> *v1; // esi
  phys_free_list<RagdollBody>::T_internal *v2; // edi
  phys_free_list<RagdollBody>::T_internal_base *v3; // eax
  phys_free_list<RagdollBody>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<RagdollBody> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<RagdollBody>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
      __debugbreak();
    --v1->m_list_count;
    phys_free_list<RagdollBody>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0xCE0u, 4u);
  }
}

/*
==============
phys_free_list<VehicleParameter>::remove_all
==============
*/
void __thiscall phys_free_list<VehicleParameter>::remove_all(phys_free_list<VehicleParameter> *this)
{
  phys_free_list<VehicleParameter> *v1; // esi
  phys_free_list<VehicleParameter>::T_internal *v2; // edi
  phys_free_list<VehicleParameter>::T_internal_base *v3; // eax
  phys_free_list<VehicleParameter>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<VehicleParameter> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<VehicleParameter>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
      __debugbreak();
    --v1->m_list_count;
    phys_free_list<VehicleParameter>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x108u, 4u);
  }
}

/*
==============
phys_free_list<NitrousVehicle>::remove_all
==============
*/
void __thiscall phys_free_list<NitrousVehicle>::remove_all(phys_free_list<NitrousVehicle> *this)
{
  phys_free_list<NitrousVehicle> *v1; // esi
  phys_free_list<NitrousVehicle>::T_internal *v2; // edi
  phys_free_list<NitrousVehicle>::T_internal_base *v3; // eax
  phys_free_list<NitrousVehicle>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<NitrousVehicle> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<NitrousVehicle>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
      __debugbreak();
    --v1->m_list_count;
    phys_free_list<NitrousVehicle>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x490u, 0x10u);
  }
}

/*
==============
phys_free_list<RagdollBody>::~phys_free_list<RagdollBody>
==============
*/
void __thiscall phys_free_list<RagdollBody>::~phys_free_list<RagdollBody>(phys_free_list<RagdollBody> *this)
{
  phys_free_list<RagdollBody> *v1; // esi

  v1 = this;
  phys_free_list<RagdollBody>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<RagdollBody> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<RagdollBody> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<VehicleParameter>::~phys_free_list<VehicleParameter>
==============
*/
void __thiscall phys_free_list<VehicleParameter>::~phys_free_list<VehicleParameter>(phys_free_list<VehicleParameter> *this)
{
  phys_free_list<VehicleParameter> *v1; // esi

  v1 = this;
  phys_free_list<VehicleParameter>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<VehicleParameter> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<VehicleParameter> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<NitrousVehicle>::~phys_free_list<NitrousVehicle>
==============
*/
void __thiscall phys_free_list<NitrousVehicle>::~phys_free_list<NitrousVehicle>(phys_free_list<NitrousVehicle> *this)
{
  phys_free_list<NitrousVehicle> *v1; // esi

  v1 = this;
  phys_free_list<NitrousVehicle>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<NitrousVehicle> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<NitrousVehicle> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<RagdollBody>::add
==============
*/
RagdollBody *__thiscall phys_free_list<RagdollBody>::add(phys_free_list<RagdollBody> *this, const int no_error, const char *error_msg)
{
  phys_free_list<RagdollBody> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  RagdollBody *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0xCE0u, 4u);
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<RagdollBody>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<RagdollBody>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 823) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 823) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (RagdollBody *)(v4 + 8);
    }
    result = (RagdollBody *)(v4 + 8);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_simple_allocator<gjkcc_info>::free
==============
*/
void __thiscall phys_simple_allocator<gjkcc_info>::free(phys_simple_allocator<gjkcc_info> *this, gjkcc_info *slot)
{
  phys_simple_allocator<gjkcc_info> *v2; // edi

  v2 = this;
  if ( slot )
  {
    PMM_VALIDATE(slot, 0x200u, 0x10u);
    --v2->m_count;
    if ( slot->m_gjk_query_output.m_allocator.m_first_block )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
             69,
             "m_first_block == NULL",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    bpei_database_t::purge_database(&slot->m_gjk_query_output.m_bpei_database);
    phys_heap_gjk_cache_system_avl_tree::shutdown(&slot->m_gjk_cache);
    PMM_FREE(slot, 0x200u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_contact>::ptr_array_read
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_contact>::ptr_array_read(phys_free_list<rigid_body_constraint_contact> *this, rigid_body_constraint_contact **ptr_array, const int ptr_array_size)
{
  phys_free_list<rigid_body_constraint_contact> *v3; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v4; // eax
  rigid_body_constraint_contact **v5; // ecx

  v3 = this;
  if ( ptr_array_size != this->m_list_count
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         516,
         "ptr_array_size == m_list_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4 = v3->m_dummy_head.m_next_T_internal;
  if ( v4 != (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)v3 )
  {
    v5 = ptr_array;
    do
    {
      *v5 = (rigid_body_constraint_contact *)&v4[1];
      v4 = v4->m_next_T_internal;
      ++v5;
    }
    while ( v4 != (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)v3 );
  }
}

/*
==============
phys_free_list<rigid_body_constraint_contact>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_contact>::debug_remove(phys_free_list<rigid_body_constraint_contact> *this, phys_free_list<rigid_body_constraint_contact>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_contact> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<user_rigid_body>::debug_remove
==============
*/
void __thiscall phys_free_list<user_rigid_body>::debug_remove(phys_free_list<user_rigid_body> *this, phys_free_list<user_rigid_body>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<user_rigid_body> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    LODWORD(v3->m_ptr_list[--v3->m_ptr_list_count][1].m_last_position.x) = T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body>::debug_remove(phys_free_list<rigid_body> *this, phys_free_list<rigid_body>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    LODWORD(v3->m_ptr_list[--v3->m_ptr_list_count][1].m_last_position.x) = T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body_constraint_contact>::ptr_array_write
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_contact>::ptr_array_write(phys_free_list<rigid_body_constraint_contact> *this, rigid_body_constraint_contact **ptr_array, const int ptr_array_size)
{
  phys_free_list<rigid_body_constraint_contact> *v3; // edi
  rigid_body_constraint_contact **v4; // edx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v5; // eax
  rigid_body_constraint_contact **v6; // esi
  rigid_body_constraint_contact *v7; // ecx

  v3 = this;
  if ( ptr_array_size != this->m_list_count
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         523,
         "ptr_array_size == m_list_count",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( ptr_array_size > 0 )
  {
    v4 = ptr_array;
    v5 = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)&(*ptr_array)[-1].m_avl_key;
    v6 = &ptr_array[ptr_array_size - 1];
    v5->m_prev_T_internal = &v3->m_dummy_head;
    v3->m_dummy_head.m_next_T_internal = v5;
    if ( ptr_array < v6 )
    {
      do
      {
        v7 = v4[1];
        ++v4;
        v7 = (rigid_body_constraint_contact *)((char *)v7 - 8);
        v5->m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)v7;
        v7->b1 = (rigid_body *)v5;
        v5 = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)v7;
      }
      while ( v4 < v6 );
    }
    v5->m_next_T_internal = &v3->m_dummy_head;
    v3->m_dummy_head.m_prev_T_internal = v5;
  }
}

/*
==============
phys_free_list<user_rigid_body>::remove
==============
*/
void __thiscall phys_free_list<user_rigid_body>::remove(phys_free_list<user_rigid_body> *this, phys_free_list<user_rigid_body>::T_internal *data)
{
  phys_free_list<user_rigid_body> *v2; // edi
  phys_free_list<user_rigid_body>::T_internal_base *v3; // eax
  phys_free_list<user_rigid_body>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<user_rigid_body>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0x1D0u, 0x10u);
}

/*
==============
phys_free_list<rigid_body>::remove
==============
*/
void __thiscall phys_free_list<rigid_body>::remove(phys_free_list<rigid_body> *this, phys_free_list<rigid_body>::T_internal *data)
{
  phys_free_list<rigid_body> *v2; // edi
  phys_free_list<rigid_body>::T_internal_base *v3; // eax
  phys_free_list<rigid_body>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<rigid_body>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0x180u, 0x10u);
}

/*
==============
phys_free_list<rigid_body_constraint_point>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_point>::debug_remove(phys_free_list<rigid_body_constraint_point> *this, phys_free_list<rigid_body_constraint_point>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_point> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<broad_phase_group>::debug_remove
==============
*/
void __thiscall phys_free_list<broad_phase_group>::debug_remove(phys_free_list<broad_phase_group> *this, phys_free_list<broad_phase_group>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<broad_phase_group> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    LODWORD(v3->m_ptr_list[--v3->m_ptr_list_count][1].m_trace_aabb_min_whace.x) = T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body_constraint_ragdoll>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_ragdoll>::debug_remove(phys_free_list<rigid_body_constraint_ragdoll> *this, phys_free_list<rigid_body_constraint_ragdoll>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_ragdoll> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body_constraint_wheel>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_wheel>::debug_remove(phys_free_list<rigid_body_constraint_wheel> *this, phys_free_list<rigid_body_constraint_wheel>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_wheel> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body_constraint_custom_orientation>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_orientation>::debug_remove(phys_free_list<rigid_body_constraint_custom_orientation> *this, phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_custom_orientation> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body_constraint_custom_path>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_path>::debug_remove(phys_free_list<rigid_body_constraint_custom_path> *this, phys_free_list<rigid_body_constraint_custom_path>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_custom_path> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body_constraint_angular_actuator>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_angular_actuator>::debug_remove(phys_free_list<rigid_body_constraint_angular_actuator> *this, phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_angular_actuator> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<rigid_body_constraint_upright>::debug_remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_upright>::debug_remove(phys_free_list<rigid_body_constraint_upright> *this, phys_free_list<rigid_body_constraint_upright>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<rigid_body_constraint_upright> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].b1 = (rigid_body *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<user_rigid_body>::remove_all
==============
*/
void __thiscall phys_free_list<user_rigid_body>::remove_all(phys_free_list<user_rigid_body> *this)
{
  phys_free_list<user_rigid_body> *v1; // esi
  phys_free_list<user_rigid_body>::T_internal *v2; // edi
  phys_free_list<user_rigid_body>::T_internal_base *v3; // eax
  phys_free_list<user_rigid_body>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<user_rigid_body> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<user_rigid_body>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<user_rigid_body>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x1D0u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body>::remove_all(phys_free_list<rigid_body> *this)
{
  phys_free_list<rigid_body> *v1; // esi
  phys_free_list<rigid_body>::T_internal *v2; // edi
  phys_free_list<rigid_body>::T_internal_base *v3; // eax
  phys_free_list<rigid_body>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x180u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_contact>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_contact>::remove(phys_free_list<rigid_body_constraint_contact> *this, phys_free_list<rigid_body_constraint_contact>::T_internal *data)
{
  phys_free_list<rigid_body_constraint_contact> *v2; // edi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v3; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v4; // eax

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<rigid_body_constraint_contact>::debug_remove(v2, data);
  v3 = data->m_prev_T_internal;
  v4 = data->m_next_T_internal;
  v3->m_next_T_internal = v4;
  v4->m_prev_T_internal = v3;
  rigid_body_constraint_contact::~rigid_body_constraint_contact(&data->m_data);
  PMM_FREE(data, 0x38u, 4u);
}

/*
==============
phys_free_list<rigid_body_constraint_contact>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_contact>::remove_all(phys_free_list<rigid_body_constraint_contact> *this)
{
  phys_free_list<rigid_body_constraint_contact> *v1; // edi
  phys_free_list<rigid_body_constraint_contact>::T_internal *v2; // esi
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v3; // ecx
  phys_free_list<rigid_body_constraint_contact>::T_internal_base *v4; // eax

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_contact> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_contact>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_contact>::debug_remove(v1, v2);
    v3 = v2->m_prev_T_internal;
    v4 = v2->m_next_T_internal;
    v3->m_next_T_internal = v4;
    v4->m_prev_T_internal = v3;
    rigid_body_constraint_contact::~rigid_body_constraint_contact(&v2->m_data);
    PMM_FREE(v2, 0x38u, 4u);
  }
}

/*
==============
phys_free_list<broad_phase_group>::remove
==============
*/
void __thiscall phys_free_list<broad_phase_group>::remove(phys_free_list<broad_phase_group> *this, phys_free_list<broad_phase_group>::T_internal *data)
{
  phys_free_list<broad_phase_group> *v2; // edi
  phys_free_list<broad_phase_group>::T_internal_base *v3; // eax
  phys_free_list<broad_phase_group>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<broad_phase_group>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0x80u, 0x10u);
}

/*
==============
phys_free_list<rigid_body_constraint_ragdoll>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_ragdoll>::remove(phys_free_list<rigid_body_constraint_ragdoll> *this, phys_free_list<rigid_body_constraint_ragdoll>::T_internal *data)
{
  phys_free_list<rigid_body_constraint_ragdoll> *v2; // edi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<rigid_body_constraint_ragdoll>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0x140u, 0x10u);
}

/*
==============
phys_free_list<rigid_body_constraint_wheel>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_wheel>::remove(phys_free_list<rigid_body_constraint_wheel> *this, phys_free_list<rigid_body_constraint_wheel>::T_internal *data)
{
  phys_free_list<rigid_body_constraint_wheel> *v2; // edi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<rigid_body_constraint_wheel>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0xF0u, 0x10u);
}

/*
==============
phys_free_list<rigid_body_constraint_custom_path>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_path>::remove(phys_free_list<rigid_body_constraint_custom_path> *this, phys_free_list<rigid_body_constraint_custom_path>::T_internal *data)
{
  phys_free_list<rigid_body_constraint_custom_path> *v2; // edi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<rigid_body_constraint_custom_path>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0xA0u, 0x10u);
}

/*
==============
phys_free_list<rigid_body_constraint_angular_actuator>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_angular_actuator>::remove(phys_free_list<rigid_body_constraint_angular_actuator> *this, phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *data)
{
  phys_free_list<rigid_body_constraint_angular_actuator> *v2; // edi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<rigid_body_constraint_angular_actuator>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0xE0u, 0x10u);
}

/*
==============
phys_free_list<rigid_body_constraint_upright>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_upright>::remove(phys_free_list<rigid_body_constraint_upright> *this, phys_free_list<rigid_body_constraint_upright>::T_internal *data)
{
  phys_free_list<rigid_body_constraint_upright> *v2; // edi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<rigid_body_constraint_upright>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0xD0u, 0x10u);
}

/*
==============
phys_free_list<user_rigid_body>::~phys_free_list<user_rigid_body>
==============
*/
void __thiscall phys_free_list<user_rigid_body>::~phys_free_list<user_rigid_body>(phys_free_list<user_rigid_body> *this)
{
  phys_free_list<user_rigid_body> *v1; // esi

  v1 = this;
  phys_free_list<user_rigid_body>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<user_rigid_body> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<user_rigid_body> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body>::~phys_free_list<rigid_body>
==============
*/
void __thiscall phys_free_list<rigid_body>::~phys_free_list<rigid_body>(phys_free_list<rigid_body> *this)
{
  phys_free_list<rigid_body> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_contact>::~phys_free_list<rigid_body_constraint_contact>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_contact>::~phys_free_list<rigid_body_constraint_contact>(phys_free_list<rigid_body_constraint_contact> *this)
{
  phys_free_list<rigid_body_constraint_contact> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_contact>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_contact> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_contact> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_point>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_point>::remove_all(phys_free_list<rigid_body_constraint_point> *this)
{
  phys_free_list<rigid_body_constraint_point> *v1; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal *v2; // edi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_point> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_point>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_point>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x70u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_distance>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_distance>::remove_all(phys_free_list<broad_phase_group> *this)
{
  phys_free_list<broad_phase_group> *v1; // esi
  phys_free_list<broad_phase_group>::T_internal *v2; // edi
  phys_free_list<broad_phase_group>::T_internal_base *v3; // eax
  phys_free_list<broad_phase_group>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<broad_phase_group> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<broad_phase_group>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<broad_phase_group>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x80u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_ragdoll>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_ragdoll>::remove_all(phys_free_list<rigid_body_constraint_ragdoll> *this)
{
  phys_free_list<rigid_body_constraint_ragdoll> *v1; // esi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal *v2; // edi
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_ragdoll> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_ragdoll>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x140u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_wheel>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_wheel>::remove_all(phys_free_list<rigid_body_constraint_wheel> *this)
{
  phys_free_list<rigid_body_constraint_wheel> *v1; // esi
  phys_free_list<rigid_body_constraint_wheel>::T_internal *v2; // edi
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_wheel>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_wheel> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_wheel>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_wheel>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0xF0u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_custom_orientation>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_orientation>::remove_all(phys_free_list<rigid_body_constraint_custom_orientation> *this)
{
  phys_free_list<rigid_body_constraint_custom_orientation> *v1; // esi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v2; // edi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_custom_orientation> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_custom_orientation>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x40u, 4u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_custom_path>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_path>::remove_all(phys_free_list<rigid_body_constraint_custom_path> *this)
{
  phys_free_list<rigid_body_constraint_custom_path> *v1; // esi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal *v2; // edi
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_custom_path> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_custom_path>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_custom_path>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0xA0u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_angular_actuator>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_angular_actuator>::remove_all(phys_free_list<rigid_body_constraint_angular_actuator> *this)
{
  phys_free_list<rigid_body_constraint_angular_actuator> *v1; // esi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *v2; // edi
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_angular_actuator> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_angular_actuator>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0xE0u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_upright>::remove_all
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_upright>::remove_all(phys_free_list<rigid_body_constraint_upright> *this)
{
  phys_free_list<rigid_body_constraint_upright> *v1; // esi
  phys_free_list<rigid_body_constraint_upright>::T_internal *v2; // edi
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v3; // eax
  phys_free_list<rigid_body_constraint_upright>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<rigid_body_constraint_upright> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<rigid_body_constraint_upright>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<rigid_body_constraint_upright>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0xD0u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_point>::~phys_free_list<rigid_body_constraint_point>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_point>::~phys_free_list<rigid_body_constraint_point>(phys_free_list<rigid_body_constraint_point> *this)
{
  phys_free_list<rigid_body_constraint_point> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_point>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_point> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_point> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_wheel>::~phys_free_list<rigid_body_constraint_wheel>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_wheel>::~phys_free_list<rigid_body_constraint_wheel>(phys_free_list<rigid_body_constraint_wheel> *this)
{
  phys_free_list<rigid_body_constraint_wheel> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_wheel>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_wheel> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_wheel> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_ragdoll>::~phys_free_list<rigid_body_constraint_ragdoll>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_ragdoll>::~phys_free_list<rigid_body_constraint_ragdoll>(phys_free_list<rigid_body_constraint_ragdoll> *this)
{
  phys_free_list<rigid_body_constraint_ragdoll> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_ragdoll>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_ragdoll> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_ragdoll> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_custom_orientation>::~phys_free_list<rigid_body_constraint_custom_orientation>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_orientation>::~phys_free_list<rigid_body_constraint_custom_orientation>(phys_free_list<rigid_body_constraint_custom_orientation> *this)
{
  phys_free_list<rigid_body_constraint_custom_orientation> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_custom_orientation>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_custom_orientation> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_custom_orientation> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_custom_path>::~phys_free_list<rigid_body_constraint_custom_path>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_path>::~phys_free_list<rigid_body_constraint_custom_path>(phys_free_list<rigid_body_constraint_custom_path> *this)
{
  phys_free_list<rigid_body_constraint_custom_path> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_custom_path>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_custom_path> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_custom_path> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_angular_actuator>::~phys_free_list<rigid_body_constraint_angular_actuator>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_angular_actuator>::~phys_free_list<rigid_body_constraint_angular_actuator>(phys_free_list<rigid_body_constraint_angular_actuator> *this)
{
  phys_free_list<rigid_body_constraint_angular_actuator> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_angular_actuator>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_angular_actuator> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_angular_actuator> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_upright>::~phys_free_list<rigid_body_constraint_upright>
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_upright>::~phys_free_list<rigid_body_constraint_upright>(phys_free_list<rigid_body_constraint_upright> *this)
{
  phys_free_list<rigid_body_constraint_upright> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_upright>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_upright> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<rigid_body_constraint_upright> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<rigid_body_constraint_point>::add
==============
*/
rigid_body_constraint_point *__thiscall phys_free_list<rigid_body_constraint_point>::add(phys_free_list<rigid_body_constraint_point> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_point> *v3; // esi
  char *v4; // eax
  phys_free_list<rigid_body_constraint_point> **v5; // ecx
  rigid_body_constraint_point *result; // eax
  int v7; // edx
  signed int v8; // edx

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x70u, 0x10u);
  v5 = (phys_free_list<rigid_body_constraint_point> **)v4;
  if ( v4 )
  {
    result = (rigid_body_constraint_point *)(v4 + 16);
    result->m_ps_cache_list[0].m_pulse_sum = 0.0;
    result->m_ps_cache_list[1].m_pulse_sum = 0.0;
    result->m_ps_cache_list[2].m_pulse_sum = 0.0;
    result->m_stress = 0.0;
    result->m_spring_enabled = 0;
    result->m_spring_k = 0.0;
    result->m_damp_k = 0.0;
    *v5 = v3;
    v5[1] = (phys_free_list<rigid_body_constraint_point> *)v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_point>::T_internal_base *)v5;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_point>::T_internal_base *)v5;
    v7 = v3->m_list_count_high_water;
    if ( v7 <= v3->m_list_count )
      v7 = v3->m_list_count;
    v3->m_list_count_high_water = v7;
    v8 = v3->m_ptr_list_count;
    if ( v8 >= 256 )
    {
      v5[24] = (phys_free_list<rigid_body_constraint_point> *)-1;
    }
    else
    {
      v5[24] = (phys_free_list<rigid_body_constraint_point> *)v8;
      v3->m_ptr_list[v3->m_ptr_list_count++] = result;
    }
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_custom_orientation>::add
==============
*/
rigid_body_constraint_custom_orientation *__thiscall phys_free_list<rigid_body_constraint_custom_orientation>::add(phys_free_list<rigid_body_constraint_custom_orientation> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_custom_orientation> *v3; // esi
  char *v4; // eax
  phys_free_list<rigid_body_constraint_custom_orientation> **v5; // ecx
  rigid_body_constraint_custom_orientation *result; // eax
  int v7; // edx
  signed int v8; // edx

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x40u, 4u);
  v5 = (phys_free_list<rigid_body_constraint_custom_orientation> **)v4;
  if ( v4 )
  {
    result = (rigid_body_constraint_custom_orientation *)(v4 + 8);
    result->m_ps_cache_list[0].m_pulse_sum = 0.0;
    result->m_ps_cache_list[1].m_pulse_sum = 0.0;
    result->m_ps_cache_list[2].m_pulse_sum = 0.0;
    result->m_ps_cache_list[3].m_pulse_sum = 0.0;
    result->m_ps_cache_list[4].m_pulse_sum = 0.0;
    *(_WORD *)&result->m_active = 0;
    result->m_torque_resistance_pitch_roll = 50.0;
    result->m_torque_resistance_yaw = 10.0;
    result->m_torque_resistance_yaw_max_collision_speed = 1.0;
    result->m_upright_strength = 50.0;
    *v5 = v3;
    v5[1] = (phys_free_list<rigid_body_constraint_custom_orientation> *)v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *)v5;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *)v5;
    v7 = v3->m_list_count_high_water;
    if ( v7 <= v3->m_list_count )
      v7 = v3->m_list_count;
    v3->m_list_count_high_water = v7;
    v8 = v3->m_ptr_list_count;
    if ( v8 >= 256 )
    {
      v5[15] = (phys_free_list<rigid_body_constraint_custom_orientation> *)-1;
    }
    else
    {
      v5[15] = (phys_free_list<rigid_body_constraint_custom_orientation> *)v8;
      v3->m_ptr_list[v3->m_ptr_list_count++] = result;
    }
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body>::add
==============
*/
rigid_body *__thiscall phys_free_list<rigid_body>::add(phys_free_list<rigid_body> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  rigid_body *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x180u, 0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 92) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 92) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body *)(v4 + 16);
    }
    result = (rigid_body *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_contact>::add
==============
*/
rigid_body_constraint_contact *__thiscall phys_free_list<rigid_body_constraint_contact>::add(phys_free_list<rigid_body_constraint_contact> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_contact> *v3; // esi
  char *v4; // eax
  int v5; // edx
  signed int v6; // edx
  rigid_body_constraint_contact *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x38u, 4u);
  if ( v4 )
  {
    *((_DWORD *)v4 + 5) = 0;
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 7) = 0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_contact>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 13) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 13) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body_constraint_contact *)(v4 + 8);
    }
    result = (rigid_body_constraint_contact *)(v4 + 8);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_point>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_point>::remove(phys_free_list<rigid_body_constraint_point> *this, rigid_body_constraint_point *data_)
{
  phys_free_list<rigid_body_constraint_point> *v2; // edi
  phys_free_list<rigid_body_constraint_point>::T_internal *v3; // esi
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v4; // eax
  phys_free_list<rigid_body_constraint_point>::T_internal_base *v5; // ecx

  v2 = this;
  if ( data_ )
  {
    v3 = (phys_free_list<rigid_body_constraint_point>::T_internal *)&data_[-1].m_spring_k;
    PMM_VALIDATE(&data_[-1].m_spring_k, 0x70u, 0x10u);
    if ( data_ == (rigid_body_constraint_point *)16 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v2->m_list_count;
    phys_free_list<rigid_body_constraint_point>::debug_remove(v2, v3);
    v4 = v3->m_next_T_internal;
    v5 = v3->m_prev_T_internal;
    v5->m_next_T_internal = v4;
    v4->m_prev_T_internal = v5;
    PMM_FREE(v3, 0x70u, 0x10u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_custom_orientation>::remove
==============
*/
void __thiscall phys_free_list<rigid_body_constraint_custom_orientation>::remove(phys_free_list<rigid_body_constraint_custom_orientation> *this, rigid_body_constraint_custom_orientation *data_)
{
  phys_free_list<rigid_body_constraint_custom_orientation> *v2; // edi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *v3; // esi
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v4; // eax
  phys_free_list<rigid_body_constraint_custom_orientation>::T_internal_base *v5; // ecx

  v2 = this;
  if ( data_ )
  {
    v3 = (phys_free_list<rigid_body_constraint_custom_orientation>::T_internal *)&data_[-1].m_torque_resistance_yaw_max_collision_speed;
    PMM_VALIDATE(&data_[-1].m_torque_resistance_yaw_max_collision_speed, 0x40u, 4u);
    if ( data_ == (rigid_body_constraint_custom_orientation *)8 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v2->m_list_count;
    phys_free_list<rigid_body_constraint_custom_orientation>::debug_remove(v2, v3);
    v4 = v3->m_next_T_internal;
    v5 = v3->m_prev_T_internal;
    v5->m_next_T_internal = v4;
    v4->m_prev_T_internal = v5;
    PMM_FREE(v3, 0x40u, 4u);
  }
}

/*
==============
phys_free_list<rigid_body_constraint_hinge>::add
==============
*/
rigid_body_constraint_hinge *__thiscall phys_free_list<rigid_body_constraint_hinge>::add(phys_free_list<rigid_body_constraint_hinge> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_hinge> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  rigid_body_constraint_hinge *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0xF0u, 0x10u);
  if ( v4 )
  {
    *((float *)v4 + 46) = 0.0;
    *((float *)v4 + 47) = 0.0;
    *((float *)v4 + 48) = 0.0;
    *((float *)v4 + 49) = 0.0;
    *((float *)v4 + 50) = 0.0;
    *((float *)v4 + 51) = 0.0;
    *((float *)v4 + 52) = 0.0;
    *((float *)v4 + 53) = 0.0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_hinge>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_hinge>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 56) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 56) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body_constraint_hinge *)(v4 + 16);
    }
    result = (rigid_body_constraint_hinge *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_distance>::add
==============
*/
rigid_body_constraint_distance *__thiscall phys_free_list<rigid_body_constraint_distance>::add(phys_free_list<rigid_body_constraint_distance> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_distance> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  rigid_body_constraint_distance *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x80u, 0x10u);
  if ( v4 )
  {
    *((float *)v4 + 22) = 0.0;
    *((float *)v4 + 23) = 0.0;
    *((float *)v4 + 24) = 0.0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_distance>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_distance>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 28) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 28) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body_constraint_distance *)(v4 + 16);
    }
    result = (rigid_body_constraint_distance *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_ragdoll>::add
==============
*/
rigid_body_constraint_ragdoll *__thiscall phys_free_list<rigid_body_constraint_ragdoll>::add(phys_free_list<rigid_body_constraint_ragdoll> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_ragdoll> *v3; // esi
  char *v4; // eax
  phys_free_list<rigid_body_constraint_ragdoll> **v5; // ecx
  rigid_body_constraint_ragdoll *result; // eax
  int v7; // edx
  signed int v8; // edx

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x140u, 0x10u);
  v5 = (phys_free_list<rigid_body_constraint_ragdoll> **)v4;
  if ( v4 )
  {
    result = (rigid_body_constraint_ragdoll *)(v4 + 16);
    result->m_ps_cache_list[0].m_pulse_sum = 0.0;
    result->m_ps_cache_list[1].m_pulse_sum = 0.0;
    result->m_ps_cache_list[2].m_pulse_sum = 0.0;
    result->m_ps_cache_list[3].m_pulse_sum = 0.0;
    result->m_ps_cache_list[4].m_pulse_sum = 0.0;
    result->m_ps_cache_list[5].m_pulse_sum = 0.0;
    result->m_ps_cache_list[6].m_pulse_sum = 0.0;
    result->m_ps_cache_list[7].m_pulse_sum = 0.0;
    result->m_ps_cache_list[8].m_pulse_sum = 0.0;
    result->m_ps_cache_list[9].m_pulse_sum = 0.0;
    result->m_flags = 0;
    result->m_joint_limits_count = 0;
    *v5 = v3;
    v5[1] = (phys_free_list<rigid_body_constraint_ragdoll> *)v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *)v5;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_ragdoll>::T_internal_base *)v5;
    v7 = v3->m_list_count;
    if ( v3->m_list_count_high_water > v7 )
      v7 = v3->m_list_count_high_water;
    v3->m_list_count_high_water = v7;
    v8 = v3->m_ptr_list_count;
    if ( v8 >= 256 )
    {
      v5[76] = (phys_free_list<rigid_body_constraint_ragdoll> *)-1;
    }
    else
    {
      v5[76] = (phys_free_list<rigid_body_constraint_ragdoll> *)v8;
      v3->m_ptr_list[v3->m_ptr_list_count++] = result;
    }
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_wheel>::add
==============
*/
rigid_body_constraint_wheel *__thiscall phys_free_list<rigid_body_constraint_wheel>::add(phys_free_list<rigid_body_constraint_wheel> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_wheel> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  rigid_body_constraint_wheel *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0xF0u, 0x10u);
  if ( v4 )
  {
    *((float *)v4 + 49) = 0.0;
    *((float *)v4 + 50) = 0.0;
    *((float *)v4 + 51) = 0.0;
    *((float *)v4 + 52) = 0.0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_wheel>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_wheel>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 56) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 56) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body_constraint_wheel *)(v4 + 16);
    }
    result = (rigid_body_constraint_wheel *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_custom_path>::add
==============
*/
rigid_body_constraint_custom_path *__thiscall phys_free_list<rigid_body_constraint_custom_path>::add(phys_free_list<rigid_body_constraint_custom_path> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_custom_path> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  rigid_body_constraint_custom_path *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0xA0u, 0x10u);
  if ( v4 )
  {
    *((float *)v4 + 31) = 0.0;
    *((float *)v4 + 32) = 0.0;
    *((float *)v4 + 33) = 0.0;
    *((float *)v4 + 34) = 0.0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_custom_path>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 36) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 36) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body_constraint_custom_path *)(v4 + 16);
    }
    result = (rigid_body_constraint_custom_path *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_angular_actuator>::add
==============
*/
rigid_body_constraint_angular_actuator *__thiscall phys_free_list<rigid_body_constraint_angular_actuator>::add(phys_free_list<rigid_body_constraint_angular_actuator> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_angular_actuator> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  rigid_body_constraint_angular_actuator *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0xE0u, 0x10u);
  if ( v4 )
  {
    *((float *)v4 + 47) = 0.0;
    *((float *)v4 + 48) = 0.0;
    *((float *)v4 + 49) = 0.0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_angular_actuator>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 52) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 52) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body_constraint_angular_actuator *)(v4 + 16);
    }
    result = (rigid_body_constraint_angular_actuator *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<rigid_body_constraint_upright>::add
==============
*/
rigid_body_constraint_upright *__thiscall phys_free_list<rigid_body_constraint_upright>::add(phys_free_list<rigid_body_constraint_upright> *this, const int no_error, const char *error_msg)
{
  phys_free_list<rigid_body_constraint_upright> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  rigid_body_constraint_upright *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0xD0u, 0x10u);
  if ( v4 )
  {
    *((float *)v4 + 44) = 0.0;
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<rigid_body_constraint_upright>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<rigid_body_constraint_upright>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 48) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 48) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (rigid_body_constraint_upright *)(v4 + 16);
    }
    result = (rigid_body_constraint_upright *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<user_rigid_body>::add
==============
*/
user_rigid_body *__thiscall phys_free_list<user_rigid_body>::add(phys_free_list<user_rigid_body> *this, const int no_error, const char *error_msg)
{
  phys_free_list<user_rigid_body> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  user_rigid_body *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x1D0u, 0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<user_rigid_body>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<user_rigid_body>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 112) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 112) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (user_rigid_body *)(v4 + 16);
    }
    result = (user_rigid_body *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<broad_phase_info>::debug_remove
==============
*/
void __thiscall phys_free_list<broad_phase_info>::debug_remove(phys_free_list<broad_phase_info> *this, phys_free_list<broad_phase_info>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<broad_phase_info> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    LODWORD(v3->m_ptr_list[--v3->m_ptr_list_count][1].m_trace_aabb_min_whace.x) = T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_free_list<broad_phase_collision_pair>::debug_remove
==============
*/
void __thiscall phys_free_list<broad_phase_collision_pair>::debug_remove(phys_free_list<broad_phase_collision_pair> *this, phys_free_list<broad_phase_collision_pair>::T_internal *T_i)
{
  int v2; // eax
  phys_free_list<broad_phase_collision_pair> *v3; // esi

  v2 = T_i->m_ptr_list_index;
  v3 = this;
  if ( v2 != -1 )
  {
    if ( (v2 < 0 || v2 >= 256)
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
           421,
           "T_i->m_ptr_list_index >= 0 && T_i->m_ptr_list_index < PTR_LIST_SIZE",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    if ( v3->m_ptr_list[T_i->m_ptr_list_index] != &T_i->m_data )
    {
      if ( _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
             422,
             "m_ptr_list[T_i->m_ptr_list_index] == &T_i->m_data",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
    }
    v3->m_ptr_list[--v3->m_ptr_list_count][1].m_bpi1 = (broad_phase_info *)T_i->m_ptr_list_index;
    v3->m_ptr_list[T_i->m_ptr_list_index] = v3->m_ptr_list[v3->m_ptr_list_count];
  }
}

/*
==============
phys_link_list<phys_collision_pair>::add_mt
==============
*/
void __thiscall phys_link_list<phys_collision_pair>::add_mt(phys_link_list<phys_collision_pair> *this, phys_collision_pair *p)
{
  phys_link_list<phys_collision_pair> *v2; // edi
  volatile signed __int32 *v3; // esi
  _DWORD *v4; // ecx

  v2 = this;
  v3 = (volatile signed __int32 *)&this->m_last_next_ptr;
  if ( !this->m_last_next_ptr
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 239, "m_last_next_ptr", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  p->m_next_link = NULL;
  _InterlockedExchangeAdd(&v2->m_alloc_count, 1u);
  do
    v4 = (_DWORD *)*v3;
  while ( (_DWORD *)_InterlockedCompareExchange(v3, (signed __int32)p, *v3) != v4 );
  *v4 = p;
}

/*
==============
phys_free_list<broad_phase_info>::remove
==============
*/
void __thiscall phys_free_list<broad_phase_info>::remove(phys_free_list<broad_phase_info> *this, phys_free_list<broad_phase_info>::T_internal *data)
{
  phys_free_list<broad_phase_info> *v2; // edi
  phys_free_list<broad_phase_info>::T_internal_base *v3; // eax
  phys_free_list<broad_phase_info>::T_internal_base *v4; // ecx

  v2 = this;
  if ( !data && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
    __debugbreak();
  --v2->m_list_count;
  phys_free_list<broad_phase_info>::debug_remove(v2, data);
  v3 = data->m_next_T_internal;
  v4 = data->m_prev_T_internal;
  v4->m_next_T_internal = v3;
  v3->m_prev_T_internal = v4;
  PMM_FREE(data, 0x90u, 0x10u);
}

/*
==============
phys_free_list<broad_phase_info>::add
==============
*/
broad_phase_info *__thiscall phys_free_list<broad_phase_info>::add(phys_free_list<broad_phase_info> *this, const int no_error, const char *error_msg)
{
  phys_free_list<broad_phase_info> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  broad_phase_info *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x90u, 0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<broad_phase_info>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<broad_phase_info>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 32) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 32) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (broad_phase_info *)(v4 + 16);
    }
    result = (broad_phase_info *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<broad_phase_info>::remove_all
==============
*/
void __thiscall phys_free_list<broad_phase_info>::remove_all(phys_free_list<broad_phase_info> *this)
{
  phys_free_list<broad_phase_info> *v1; // esi
  phys_free_list<broad_phase_info>::T_internal *v2; // edi
  phys_free_list<broad_phase_info>::T_internal_base *v3; // eax
  phys_free_list<broad_phase_info>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<broad_phase_info> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<broad_phase_info>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<broad_phase_info>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x90u, 0x10u);
  }
}

/*
==============
phys_free_list<broad_phase_group>::add
==============
*/
broad_phase_group *__thiscall phys_free_list<broad_phase_group>::add(phys_free_list<broad_phase_group> *this, const int no_error, const char *error_msg)
{
  phys_free_list<broad_phase_group> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  broad_phase_group *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x80u, 0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<broad_phase_group>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<broad_phase_group>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 28) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 28) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (broad_phase_group *)(v4 + 16);
    }
    result = (broad_phase_group *)(v4 + 16);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<broad_phase_collision_pair>::add
==============
*/
broad_phase_collision_pair *__thiscall phys_free_list<broad_phase_collision_pair>::add(phys_free_list<broad_phase_collision_pair> *this, const int no_error, const char *error_msg)
{
  phys_free_list<broad_phase_collision_pair> *v3; // esi
  char *v4; // eax
  int v5; // ecx
  signed int v6; // ecx
  broad_phase_collision_pair *result; // eax

  v3 = this;
  v4 = (char *)PMM_ALLOC(0x18u, 4u);
  if ( v4 )
  {
    *(_DWORD *)v4 = v3;
    *((_DWORD *)v4 + 1) = v3->m_dummy_head.m_next_T_internal;
    v3->m_dummy_head.m_next_T_internal->m_prev_T_internal = (phys_free_list<broad_phase_collision_pair>::T_internal_base *)v4;
    ++v3->m_list_count;
    v3->m_dummy_head.m_next_T_internal = (phys_free_list<broad_phase_collision_pair>::T_internal_base *)v4;
    v5 = v3->m_list_count_high_water;
    if ( v5 <= v3->m_list_count )
      v5 = v3->m_list_count;
    v3->m_list_count_high_water = v5;
    v6 = v3->m_ptr_list_count;
    if ( v6 >= 256 )
    {
      *((_DWORD *)v4 + 5) = -1;
    }
    else
    {
      *((_DWORD *)v4 + 5) = v6;
      v3->m_ptr_list[v3->m_ptr_list_count++] = (broad_phase_collision_pair *)(v4 + 8);
    }
    result = (broad_phase_collision_pair *)(v4 + 8);
  }
  else
  {
    if ( !no_error && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 470, "no_error", error_msg) )
      __debugbreak();
    result = NULL;
  }
  return result;
}

/*
==============
phys_free_list<broad_phase_collision_pair>::remove
==============
*/
void __thiscall phys_free_list<broad_phase_collision_pair>::remove(phys_free_list<broad_phase_collision_pair> *this, broad_phase_collision_pair *data_)
{
  phys_free_list<broad_phase_collision_pair> *v2; // edi
  phys_free_list<broad_phase_collision_pair>::T_internal *v3; // esi
  phys_free_list<broad_phase_collision_pair>::T_internal_base *v4; // eax
  phys_free_list<broad_phase_collision_pair>::T_internal_base *v5; // ecx

  v2 = this;
  if ( data_ )
  {
    v3 = (phys_free_list<broad_phase_collision_pair>::T_internal *)&data_[-1].m_bpi2;
    PMM_VALIDATE(&data_[-1].m_bpi2, 0x18u, 4u);
    if ( data_ == (broad_phase_collision_pair *)8 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v2->m_list_count;
    phys_free_list<broad_phase_collision_pair>::debug_remove(v2, v3);
    v4 = v3->m_next_T_internal;
    v5 = v3->m_prev_T_internal;
    v5->m_next_T_internal = v4;
    v4->m_prev_T_internal = v5;
    PMM_FREE(v3, 0x18u, 4u);
  }
}

/*
==============
phys_free_list<broad_phase_collision_pair>::remove_all
==============
*/
void __thiscall phys_free_list<broad_phase_collision_pair>::remove_all(phys_free_list<broad_phase_collision_pair> *this)
{
  phys_free_list<broad_phase_collision_pair> *v1; // esi
  phys_free_list<broad_phase_collision_pair>::T_internal *v2; // edi
  phys_free_list<broad_phase_collision_pair>::T_internal_base *v3; // eax
  phys_free_list<broad_phase_collision_pair>::T_internal_base *v4; // ecx

  v1 = this;
  while ( (phys_free_list<broad_phase_collision_pair> *)v1->m_dummy_head.m_next_T_internal != v1 )
  {
    v2 = (phys_free_list<broad_phase_collision_pair>::T_internal *)v1->m_dummy_head.m_next_T_internal;
    if ( !v2 )
    {
      if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 477, "data", (const char *)&pBlock) )
        __debugbreak();
    }
    --v1->m_list_count;
    phys_free_list<broad_phase_collision_pair>::debug_remove(v1, v2);
    v3 = v2->m_next_T_internal;
    v4 = v2->m_prev_T_internal;
    v4->m_next_T_internal = v3;
    v3->m_prev_T_internal = v4;
    PMM_FREE(v2, 0x18u, 4u);
  }
}

/*
==============
phys_free_list<broad_phase_info>::~phys_free_list<broad_phase_info>
==============
*/
void __thiscall phys_free_list<broad_phase_info>::~phys_free_list<broad_phase_info>(phys_free_list<broad_phase_info> *this)
{
  phys_free_list<broad_phase_info> *v1; // esi

  v1 = this;
  phys_free_list<broad_phase_info>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<broad_phase_info> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<broad_phase_info> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<broad_phase_group>::~phys_free_list<broad_phase_group>
==============
*/
void __thiscall phys_free_list<broad_phase_group>::~phys_free_list<broad_phase_group>(phys_free_list<broad_phase_group> *this)
{
  phys_free_list<broad_phase_group> *v1; // esi

  v1 = this;
  phys_free_list<rigid_body_constraint_distance>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<broad_phase_group> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<broad_phase_group> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_free_list<broad_phase_collision_pair>::~phys_free_list<broad_phase_collision_pair>
==============
*/
void __thiscall phys_free_list<broad_phase_collision_pair>::~phys_free_list<broad_phase_collision_pair>(phys_free_list<broad_phase_collision_pair> *this)
{
  phys_free_list<broad_phase_collision_pair> *v1; // esi

  v1 = this;
  phys_free_list<broad_phase_collision_pair>::remove_all(this);
  if ( v1->m_list_count
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 448, "m_list_count == 0", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<broad_phase_collision_pair> *)v1->m_dummy_head.m_next_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         449,
         "m_dummy_head.m_next_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( (phys_free_list<broad_phase_collision_pair> *)v1->m_dummy_head.m_prev_T_internal != v1
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         450,
         "m_dummy_head.m_prev_T_internal == &m_dummy_head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v1->m_list_count_high_water = 0;
  v1->m_ptr_list_count = 0;
}

/*
==============
phys_memory_heap::set_buffer
==============
*/
void __thiscall phys_memory_heap::set_buffer(phys_memory_heap *this, void *const start, const int size, const int alignment)
{
  phys_memory_heap *v4; // esi

  v4 = this;
  if ( this->m_buffer_start
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 33, "m_buffer_start == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v4->m_buffer_end
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 34, "m_buffer_end == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( v4->m_buffer_cur
    && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 35, "m_buffer_cur == NULL", (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( size <= 0 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 36, "size > 0", (const char *)&pBlock) )
    __debugbreak();
  if ( (unsigned int)start % alignment
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_mem.h",
         37,
         "((size_t)start) % alignment == 0",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v4->m_buffer_start = (char *)start;
  v4->m_buffer_cur = (char *)start;
  v4->m_user_start = (char *)start;
  v4->m_buffer_end = (char *)start + size;
}

