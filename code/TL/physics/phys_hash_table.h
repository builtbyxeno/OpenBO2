/*
==============
minspec_hash_table<phys_slot_pool,64>::add
==============
*/
void __thiscall minspec_hash_table<phys_slot_pool,64>::add(minspec_hash_table<phys_slot_pool,64> *this, unsigned int key, phys_slot_pool *entry_to_add)
{
  minspec_hash_table<phys_slot_pool,64> *v3; // esi
  phys_slot_pool *v4; // edx
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  phys_slot_pool *i; // eax
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // edi
  phys_slot_pool *v16; // ecx
  int v17; // edx
  phys_slot_pool *entry_list[64]; // [esp+Ch] [ebp-210h]
  unsigned int v19; // [esp+10Ch] [ebp-110h]
  unsigned int total_collisions; // [esp+110h] [ebp-10Ch]
  unsigned int mod_i; // [esp+114h] [ebp-108h]
  unsigned int collision_counts[64]; // [esp+118h] [ebp-104h]

  v3 = this;
  v4 = v3->m_hash_table[key % v3->m_mod];
  if ( v4 )
  {
    while ( v4->m_map_key != key )
    {
      v4 = v4->m_hash_next;
      if ( !v4 )
        goto LABEL_7;
    }
    if ( _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\phys_hash_table.h",
           38,
           "find(key) == NULL",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
  }
LABEL_7:
  entry_list[0] = entry_to_add;
  v5 = 1;
  v6 = 0;
  do
  {
    for ( i = v3->m_hash_table[v6]; i; ++v5 )
    {
      entry_list[v5] = i;
      i = i->m_hash_next;
    }
    v3->m_hash_table[v6++] = NULL;
  }
  while ( v6 < 0x40 );
  v3->m_mod = v5;
  v3->m_highest_collision = 100000;
  v3->m_total_collisions = 100000;
  v8 = v5;
  mod_i = v5;
  if ( v5 < 0x40 )
  {
    v19 = 100000;
    do
    {
      if ( v8 )
        memset(collision_counts, 0, 4 * v8);
      v9 = 0;
      v10 = 0;
      v11 = 0;
      total_collisions = 0;
      if ( v5 )
      {
        do
        {
          v12 = entry_list[v11]->m_map_key % mod_i;
          v13 = ++collision_counts[v12];
          if ( v13 > v10 )
            v10 = collision_counts[v12];
          total_collisions += v13;
          ++v11;
        }
        while ( v11 < v5 );
        v8 = mod_i;
        v9 = total_collisions;
      }
      if ( v9 < v19 )
      {
        v3->m_mod = v8;
        v3->m_highest_collision = v10;
        v19 = v9;
        v3->m_total_collisions = v9;
      }
      mod_i = ++v8;
    }
    while ( v8 < 0x40 );
  }
  v14 = v3->m_mod;
  if ( (!v14 || v14 >= 0x40)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_hash_table.h",
         83,
         "m_mod > 0 && m_mod < TABLE_SIZE",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v15 = 0;
  if ( v5 )
  {
    do
    {
      v16 = entry_list[v15];
      v17 = v16->m_map_key % v3->m_mod;
      ++v15;
      v16->m_hash_next = v3->m_hash_table[v17];
      v3->m_hash_table[v17] = v16;
    }
    while ( v15 < v5 );
  }
}

