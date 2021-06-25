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
phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::find
==============
*/
auto_rigid_body *__thiscall phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::find(phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body> *this, centity_t *const *key)
{
  auto_rigid_body *result; // eax
  centity_t *v3; // edx
  centity_t *v4; // ecx

  result = this->m_tree_root;
  if ( this->m_tree_root )
  {
    v3 = *key;
    do
    {
      v4 = result->cent;
      if ( v3 == v4 )
        break;
      result = v3 >= v4 ? result->m_avl_node_info.m_right : result->m_avl_node_info.m_left;
    }
    while ( result );
  }
  return result;
}

/*
==============
phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::add
==============
*/
void __thiscall phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::add(phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body> *this, centity_t *const *key, auto_rigid_body *data)
{
  auto_rigid_body *v3; // eax
  phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::stack_item *v4; // ebx
  auto_rigid_body *v5; // edi
  centity_t *v6; // ecx
  auto_rigid_body **v7; // edi
  bool v8; // zf
  auto_rigid_body **v9; // esi
  auto_rigid_body *v10; // eax
  int v11; // ecx
  int v12; // eax
  auto_rigid_body *v13; // ecx
  auto_rigid_body *v14; // eax
  auto_rigid_body *v15; // eax
  int v16; // edi
  auto_rigid_body *v17; // eax
  int v18; // edi
  BOOL v19; // edx
  bool v20; // al
  int v21; // eax
  auto_rigid_body *v22; // ecx
  auto_rigid_body *v23; // edx
  auto_rigid_body *v24; // eax
  auto_rigid_body *v25; // eax
  int v26; // edi
  phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::stack_item *cur_item; // [esp+Ch] [ebp-108h]
  phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::stack_item the_stack[32]; // [esp+10h] [ebp-104h]

  v3 = data;
  cur_item = (phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::stack_item *)data;
  v4 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  if ( this->m_tree_root )
  {
    do
    {
      v5 = *v4->m_node;
      if ( (signed int)(((char *)v4 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             103,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v6 = v5->cent;
      if ( *key >= v6 )
      {
        if ( *key <= v6
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               112,
               "key > accessor::get_avl_key(root)",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v4->m_child = 1;
        v7 = &v5->m_avl_node_info.m_right;
      }
      else
      {
        v4->m_child = -1;
        v7 = &v5->m_avl_node_info.m_left;
      }
      v8 = *v7 == NULL;
      v4[1].m_node = v7;
      ++v4;
    }
    while ( !v8 );
    v3 = (auto_rigid_body *)cur_item;
  }
  *v4->m_node = v3;
  v3->m_avl_node_info.m_left = NULL;
  v3->m_avl_node_info.m_right = NULL;
  v3->m_avl_node_info.m_balance = 0;
  if ( v4 > the_stack )
  {
    do
    {
      v9 = v4[-1].m_node;
      (*v9)->m_avl_node_info.m_balance += v4[-1].m_child;
      v10 = *v9;
      v11 = (*v9)->m_avl_node_info.m_balance;
      --v4;
      cur_item = v4;
      if ( v11 == -2 )
      {
        v12 = v10->m_avl_node_info.m_left->m_avl_node_info.m_balance;
        if ( v12 != -1
          && v12 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               130,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_left)->m_balance == -1 || accessor::get_avl_node(a"
               "ccessor::get_avl_node(root)->m_left)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v13 = *v9;
        v14 = (*v9)->m_avl_node_info.m_left;
        if ( v14->m_avl_node_info.m_balance == 1 )
        {
          v15 = v14->m_avl_node_info.m_right;
          (*v9)->m_avl_node_info.m_left->m_avl_node_info.m_right = v15->m_avl_node_info.m_left;
          v15->m_avl_node_info.m_left = v13->m_avl_node_info.m_left;
          v13->m_avl_node_info.m_left->m_avl_node_info.m_balance += v15->m_avl_node_info.m_balance <= 0 ? 1 : v15->m_avl_node_info.m_balance + -1;
          v4 = cur_item;
          v16 = -v13->m_avl_node_info.m_left->m_avl_node_info.m_balance;
          v15->m_avl_node_info.m_balance += v16 < 0 || v13->m_avl_node_info.m_left->m_avl_node_info.m_balance == 0 ? 1 : v16 + -1;
          v13->m_avl_node_info.m_left = v15;
        }
        v17 = (*v9)->m_avl_node_info.m_left;
        (*v9)->m_avl_node_info.m_left = v17->m_avl_node_info.m_right;
        v18 = -v17->m_avl_node_info.m_balance;
        v19 = v18 < 0 || v17->m_avl_node_info.m_balance == 0;
        v17->m_avl_node_info.m_right = *v9;
        (*v9)->m_avl_node_info.m_balance += v19 ? 1 : v18 + 1;
        v17->m_avl_node_info.m_balance += (*v9)->m_avl_node_info.m_balance <= 0 ? 1 : (*v9)->m_avl_node_info.m_balance
                                                                                    + 1;
        *v9 = v17;
        if ( !v17->m_avl_node_info.m_balance )
          continue;
        v20 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                134,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      else
      {
        if ( v11 != 2 )
          continue;
        v21 = v10->m_avl_node_info.m_right->m_avl_node_info.m_balance;
        if ( v21 != -1
          && v21 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               138,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_right)->m_balance == -1 || accessor::get_avl_node("
               "accessor::get_avl_node(root)->m_right)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v22 = *v9;
        v23 = (*v9)->m_avl_node_info.m_right;
        if ( v23->m_avl_node_info.m_balance == -1 )
        {
          v24 = v23->m_avl_node_info.m_left;
          v23->m_avl_node_info.m_left = v24->m_avl_node_info.m_right;
          v24->m_avl_node_info.m_right = v22->m_avl_node_info.m_right;
          v22->m_avl_node_info.m_right->m_avl_node_info.m_balance += -v24->m_avl_node_info.m_balance < 0
                                                                  || v24->m_avl_node_info.m_balance == 0 ? 1 : -v24->m_avl_node_info.m_balance + 1;
          v4 = cur_item;
          v24->m_avl_node_info.m_balance += v22->m_avl_node_info.m_right->m_avl_node_info.m_balance <= 0 ? 1 : v22->m_avl_node_info.m_right->m_avl_node_info.m_balance + 1;
          v22->m_avl_node_info.m_right = v24;
        }
        v25 = (*v9)->m_avl_node_info.m_right;
        (*v9)->m_avl_node_info.m_right = v25->m_avl_node_info.m_left;
        v26 = v25->m_avl_node_info.m_balance;
        v25->m_avl_node_info.m_left = *v9;
        (*v9)->m_avl_node_info.m_balance += v26 <= 0 ? 1 : v26 + -1;
        v25->m_avl_node_info.m_balance += -(*v9)->m_avl_node_info.m_balance < 0 || (*v9)->m_avl_node_info.m_balance == 0 ? 1 : -(*v9)->m_avl_node_info.m_balance + -1;
        *v9 = v25;
        if ( !v25->m_avl_node_info.m_balance )
          continue;
        v20 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                142,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      if ( v20 )
        __debugbreak();
    }
    while ( (*v9)->m_avl_node_info.m_balance && v4 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::remove
==============
*/
void __thiscall phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::remove(phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body> *this, centity_t *const *key)
{
  phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::stack_item *v2; // edi
  auto_rigid_body *v3; // esi
  centity_t *v4; // ecx
  auto_rigid_body **v5; // esi
  auto_rigid_body *v6; // ecx
  auto_rigid_body **v7; // eax
  auto_rigid_body *v8; // edx
  bool v9; // zf
  auto_rigid_body *v10; // ecx
  auto_rigid_body *v11; // eax
  auto_rigid_body *v12; // eax
  auto_rigid_body **v13; // esi
  auto_rigid_body *v14; // eax
  int v15; // ecx
  auto_rigid_body *v16; // ecx
  auto_rigid_body *v17; // ecx
  int v18; // edi
  auto_rigid_body *v19; // eax
  int v20; // edx
  BOOL v21; // ebx
  int v22; // eax
  bool v23; // al
  auto_rigid_body *v24; // ecx
  auto_rigid_body *v25; // ecx
  auto_rigid_body *v26; // eax
  int v27; // edx
  int v28; // eax
  phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::stack_item *right_item; // [esp+Ch] [ebp-108h]
  phys_inplace_avl_tree<centity_t const *,auto_rigid_body,auto_rigid_body>::stack_item the_stack[32]; // [esp+10h] [ebp-104h]

  v2 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = *v2->m_node;
      if ( !v3 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h", 161, "root", (const char *)&pBlock) )
        __debugbreak();
      if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             162,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v4 = v3->cent;
      if ( *key >= v4 )
        break;
      v2->m_child = -1;
      v2[1].m_node = &v3->m_avl_node_info.m_left;
      ++v2;
    }
    if ( *key <= v4 )
      break;
    v2->m_child = 1;
    v2[1].m_node = &v3->m_avl_node_info.m_right;
    ++v2;
  }
  if ( *key != v4
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
         176,
         "key == accessor::get_avl_key(root)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v5 = v2->m_node;
  v6 = *v2->m_node;
  v7 = &v6->m_avl_node_info.m_right;
  if ( v6->m_avl_node_info.m_right )
  {
    v8 = *v7;
    v2->m_child = 1;
    ++v2;
    v9 = v8->m_avl_node_info.m_left == NULL;
    v2->m_node = v7;
    right_item = v2;
    if ( !v9 )
    {
      do
      {
        if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               191,
               "cur_item + 1 - the_stack < 32",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v10 = *v2->m_node;
        v11 = v10->m_avl_node_info.m_left;
        v2->m_child = -1;
        v2[1].m_node = &v10->m_avl_node_info.m_left;
        ++v2;
      }
      while ( v11->m_avl_node_info.m_left );
    }
    v12 = *v2->m_node;
    *v2->m_node = v12->m_avl_node_info.m_right;
    v12->m_avl_node_info.m_left = (*v5)->m_avl_node_info.m_left;
    v12->m_avl_node_info.m_right = (*v5)->m_avl_node_info.m_right;
    v12->m_avl_node_info.m_balance = (*v5)->m_avl_node_info.m_balance;
    right_item->m_node = &v12->m_avl_node_info.m_right;
  }
  else
  {
    v12 = v6->m_avl_node_info.m_left;
  }
  *v5 = v12;
  if ( v2 > the_stack )
  {
    do
    {
      v13 = v2[-1].m_node;
      (*v13)->m_avl_node_info.m_balance -= v2[-1].m_child;
      v14 = *v13;
      v15 = (*v13)->m_avl_node_info.m_balance;
      --v2;
      right_item = v2;
      if ( v15 == -2 )
      {
        v16 = v14->m_avl_node_info.m_left;
        if ( v16->m_avl_node_info.m_balance == 1 )
        {
          v17 = v16->m_avl_node_info.m_right;
          v14->m_avl_node_info.m_left->m_avl_node_info.m_right = v17->m_avl_node_info.m_left;
          v17->m_avl_node_info.m_left = v14->m_avl_node_info.m_left;
          v14->m_avl_node_info.m_left->m_avl_node_info.m_balance += v17->m_avl_node_info.m_balance <= 0 ? 1 : v17->m_avl_node_info.m_balance + -1;
          v18 = -v14->m_avl_node_info.m_left->m_avl_node_info.m_balance;
          v17->m_avl_node_info.m_balance += v18 < 0 || v14->m_avl_node_info.m_left->m_avl_node_info.m_balance == 0 ? 1 : v18 + -1;
          v2 = right_item;
          v14->m_avl_node_info.m_left = v17;
        }
        v19 = (*v13)->m_avl_node_info.m_left;
        (*v13)->m_avl_node_info.m_left = v19->m_avl_node_info.m_right;
        v20 = -v19->m_avl_node_info.m_balance;
        v21 = v20 < 0 || v19->m_avl_node_info.m_balance == 0;
        v19->m_avl_node_info.m_right = *v13;
        (*v13)->m_avl_node_info.m_balance += v21 ? 1 : v20 + 1;
        v19->m_avl_node_info.m_balance += (*v13)->m_avl_node_info.m_balance <= 0 ? 1 : (*v13)->m_avl_node_info.m_balance
                                                                                     + 1;
        *v13 = v19;
        v22 = v19->m_avl_node_info.m_balance;
        if ( !v22 || v22 == 1 )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                218,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == +1",
                (const char *)&pBlock);
      }
      else
      {
        if ( v15 != 2 )
          continue;
        v24 = v14->m_avl_node_info.m_right;
        if ( v24->m_avl_node_info.m_balance == -1 )
        {
          v25 = v24->m_avl_node_info.m_left;
          v14->m_avl_node_info.m_right->m_avl_node_info.m_left = v25->m_avl_node_info.m_right;
          v25->m_avl_node_info.m_right = v14->m_avl_node_info.m_right;
          v14->m_avl_node_info.m_right->m_avl_node_info.m_balance += -v25->m_avl_node_info.m_balance < 0
                                                                  || v25->m_avl_node_info.m_balance == 0 ? 1 : -v25->m_avl_node_info.m_balance + 1;
          v2 = right_item;
          v25->m_avl_node_info.m_balance += v14->m_avl_node_info.m_right->m_avl_node_info.m_balance <= 0 ? 1 : v14->m_avl_node_info.m_right->m_avl_node_info.m_balance + 1;
          v14->m_avl_node_info.m_right = v25;
        }
        v26 = (*v13)->m_avl_node_info.m_right;
        (*v13)->m_avl_node_info.m_right = v26->m_avl_node_info.m_left;
        v27 = v26->m_avl_node_info.m_balance;
        v26->m_avl_node_info.m_left = *v13;
        (*v13)->m_avl_node_info.m_balance += v27 <= 0 ? 1 : v27 + -1;
        v26->m_avl_node_info.m_balance += -(*v13)->m_avl_node_info.m_balance < 0
                                       || (*v13)->m_avl_node_info.m_balance == 0 ? 1 : -(*v13)->m_avl_node_info.m_balance
                                                                                     + -1;
        *v13 = v26;
        v28 = v26->m_avl_node_info.m_balance;
        if ( !v28 || v28 == -1 )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                225,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == -1",
                (const char *)&pBlock);
      }
      if ( v23 )
        __debugbreak();
    }
    while ( !(*v13)->m_avl_node_info.m_balance && v2 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::find
==============
*/
broad_phase_environment_info *__thiscall phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::find(phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor> *this, bpei_database_id *key)
{
  broad_phase_environment_info *result; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  bool v5; // cf
  unsigned int v6; // edi

  result = this->m_tree_root;
  if ( this->m_tree_root )
  {
    v3 = key->m_id1;
    do
    {
      v4 = result->m_database_id.m_id1;
      v5 = v3 < v4;
      if ( v3 == v4 )
      {
        v6 = key->m_id2;
        if ( v6 == result->m_database_id.m_id2 )
          return result;
        v5 = v3 < v4;
        if ( v3 == v4 )
          v5 = v6 < result->m_database_id.m_id2;
      }
      if ( v5 )
        result = result->m_avl_tree_node.m_left;
      else
        result = result->m_avl_tree_node.m_right;
    }
    while ( result );
  }
  return result;
}

/*
==============
phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::add
==============
*/
void __thiscall phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::add(phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor> *this, bpei_database_id *key, broad_phase_environment_info *data)
{
  bool v3; // zf
  broad_phase_environment_info *v4; // eax
  phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::stack_item *v5; // ebx
  broad_phase_environment_info *v6; // esi
  unsigned int v7; // ecx
  unsigned int v8; // edx
  bool v9; // cf
  broad_phase_environment_info **v10; // esi
  bool v11; // cf
  broad_phase_environment_info **v12; // esi
  broad_phase_environment_info *v13; // eax
  int v14; // ecx
  int v15; // eax
  broad_phase_environment_info *v16; // ecx
  broad_phase_environment_info *v17; // eax
  broad_phase_environment_info *v18; // eax
  int v19; // edi
  broad_phase_environment_info *v20; // eax
  int v21; // edi
  BOOL v22; // edx
  bool v23; // al
  int v24; // eax
  broad_phase_environment_info *v25; // ecx
  broad_phase_environment_info *v26; // edx
  broad_phase_environment_info *v27; // eax
  broad_phase_environment_info *v28; // eax
  int v29; // edi
  phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::stack_item *cur_item; // [esp+Ch] [ebp-108h]
  phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::stack_item the_stack[32]; // [esp+10h] [ebp-104h]

  v3 = this->m_tree_root == NULL;
  v4 = data;
  cur_item = (phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::stack_item *)data;
  v5 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  if ( !v3 )
  {
    do
    {
      v6 = *v5->m_node;
      if ( (signed int)(((char *)v5 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             103,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v7 = key->m_id1;
      v8 = v6->m_database_id.m_id1;
      v9 = key->m_id1 < v8;
      if ( key->m_id1 == v8 )
        v9 = key->m_id2 < v6->m_database_id.m_id2;
      if ( v9 )
      {
        v5->m_child = -1;
        v10 = &v6->m_avl_tree_node.m_left;
      }
      else
      {
        v11 = v8 < v7;
        if ( v8 == v7 )
          v11 = v6->m_database_id.m_id2 < key->m_id2;
        if ( !v11
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               112,
               "key > accessor::get_avl_key(root)",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v5->m_child = 1;
        v10 = &v6->m_avl_tree_node.m_right;
      }
      v3 = *v10 == NULL;
      v5[1].m_node = v10;
      ++v5;
    }
    while ( !v3 );
    v4 = (broad_phase_environment_info *)cur_item;
  }
  *v5->m_node = v4;
  v4->m_avl_tree_node.m_left = NULL;
  v4->m_avl_tree_node.m_right = NULL;
  v4->m_avl_tree_node.m_balance = 0;
  v4->m_database_id = *key;
  if ( v5 > the_stack )
  {
    do
    {
      v12 = v5[-1].m_node;
      (*v12)->m_avl_tree_node.m_balance += v5[-1].m_child;
      v13 = *v12;
      v14 = (*v12)->m_avl_tree_node.m_balance;
      --v5;
      cur_item = v5;
      if ( v14 == -2 )
      {
        v15 = v13->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
        if ( v15 != -1
          && v15 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               130,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_left)->m_balance == -1 || accessor::get_avl_node(a"
               "ccessor::get_avl_node(root)->m_left)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v16 = *v12;
        v17 = (*v12)->m_avl_tree_node.m_left;
        if ( v17->m_avl_tree_node.m_balance == 1 )
        {
          v18 = v17->m_avl_tree_node.m_right;
          (*v12)->m_avl_tree_node.m_left->m_avl_tree_node.m_right = v18->m_avl_tree_node.m_left;
          v18->m_avl_tree_node.m_left = v16->m_avl_tree_node.m_left;
          v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance += v18->m_avl_tree_node.m_balance <= 0 ? 1 : v18->m_avl_tree_node.m_balance + -1;
          v5 = cur_item;
          v19 = -v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
          v18->m_avl_tree_node.m_balance += v19 < 0 || v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance == 0 ? 1 : v19 + -1;
          v16->m_avl_tree_node.m_left = v18;
        }
        v20 = (*v12)->m_avl_tree_node.m_left;
        (*v12)->m_avl_tree_node.m_left = v20->m_avl_tree_node.m_right;
        v21 = -v20->m_avl_tree_node.m_balance;
        v22 = v21 < 0 || v20->m_avl_tree_node.m_balance == 0;
        v20->m_avl_tree_node.m_right = *v12;
        (*v12)->m_avl_tree_node.m_balance += v22 ? 1 : v21 + 1;
        v20->m_avl_tree_node.m_balance += (*v12)->m_avl_tree_node.m_balance <= 0 ? 1 : (*v12)->m_avl_tree_node.m_balance
                                                                                     + 1;
        *v12 = v20;
        if ( !v20->m_avl_tree_node.m_balance )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                134,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      else
      {
        if ( v14 != 2 )
          continue;
        v24 = v13->m_avl_tree_node.m_right->m_avl_tree_node.m_balance;
        if ( v24 != -1
          && v24 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               138,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_right)->m_balance == -1 || accessor::get_avl_node("
               "accessor::get_avl_node(root)->m_right)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v25 = *v12;
        v26 = (*v12)->m_avl_tree_node.m_right;
        if ( v26->m_avl_tree_node.m_balance == -1 )
        {
          v27 = v26->m_avl_tree_node.m_left;
          v26->m_avl_tree_node.m_left = v27->m_avl_tree_node.m_right;
          v27->m_avl_tree_node.m_right = v25->m_avl_tree_node.m_right;
          v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance += -v27->m_avl_tree_node.m_balance < 0
                                                                  || v27->m_avl_tree_node.m_balance == 0 ? 1 : -v27->m_avl_tree_node.m_balance + 1;
          v5 = cur_item;
          v27->m_avl_tree_node.m_balance += v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance <= 0 ? 1 : v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance + 1;
          v25->m_avl_tree_node.m_right = v27;
        }
        v28 = (*v12)->m_avl_tree_node.m_right;
        (*v12)->m_avl_tree_node.m_right = v28->m_avl_tree_node.m_left;
        v29 = v28->m_avl_tree_node.m_balance;
        v28->m_avl_tree_node.m_left = *v12;
        (*v12)->m_avl_tree_node.m_balance += v29 <= 0 ? 1 : v29 + -1;
        v28->m_avl_tree_node.m_balance += -(*v12)->m_avl_tree_node.m_balance < 0
                                       || (*v12)->m_avl_tree_node.m_balance == 0 ? 1 : -(*v12)->m_avl_tree_node.m_balance
                                                                                     + -1;
        *v12 = v28;
        if ( !v28->m_avl_tree_node.m_balance )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                142,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      if ( v23 )
        __debugbreak();
    }
    while ( (*v12)->m_avl_tree_node.m_balance && v5 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::find
==============
*/
phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *__thiscall phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::find(phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor> *this, phys_gjk_geom_id_pair_key *key)
{
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *result; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  bool v5; // cf
  unsigned int v6; // edi

  result = this->m_tree_root;
  if ( this->m_tree_root )
  {
    v3 = key->m_id1;
    do
    {
      v4 = result->m_key.m_id1;
      v5 = v3 < v4;
      if ( v3 == v4 )
      {
        v6 = key->m_id2;
        if ( v6 == result->m_key.m_id2 )
          return result;
        v5 = v3 < v4;
        if ( v3 == v4 )
          v5 = v6 < result->m_key.m_id2;
      }
      if ( v5 )
        result = result->m_avl_tree_node.m_left;
      else
        result = result->m_avl_tree_node.m_right;
    }
    while ( result );
  }
  return result;
}

/*
==============
phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::add
==============
*/
void __thiscall phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::add(phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor> *this, phys_gjk_geom_id_pair_key *key, phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *data)
{
  bool v3; // zf
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v4; // eax
  phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::stack_item *v5; // ebx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v6; // esi
  unsigned int v7; // ecx
  unsigned int v8; // edx
  bool v9; // cf
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal **v10; // esi
  bool v11; // cf
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal **v12; // esi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v13; // eax
  int v14; // ecx
  int v15; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v16; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v17; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v18; // eax
  int v19; // edi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v20; // eax
  int v21; // edi
  BOOL v22; // edx
  bool v23; // al
  int v24; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v25; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v26; // edx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v27; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v28; // eax
  int v29; // edi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v30; // [esp+Ch] [ebp-10Ch]
  phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::stack_item *cur_item; // [esp+10h] [ebp-108h]
  phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::stack_item the_stack[32]; // [esp+14h] [ebp-104h]

  v3 = this->m_tree_root == NULL;
  v4 = data;
  v30 = data;
  v5 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  if ( !v3 )
  {
    do
    {
      v6 = *v5->m_node;
      if ( (signed int)(((char *)v5 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             103,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v7 = key->m_id1;
      v8 = v6->m_key.m_id1;
      v9 = key->m_id1 < v8;
      if ( key->m_id1 == v8 )
        v9 = key->m_id2 < v6->m_key.m_id2;
      if ( v9 )
      {
        v5->m_child = -1;
        v10 = &v6->m_avl_tree_node.m_left;
      }
      else
      {
        v11 = v8 < v7;
        if ( v8 == v7 )
          v11 = v6->m_key.m_id2 < key->m_id2;
        if ( !v11
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               112,
               "key > accessor::get_avl_key(root)",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v5->m_child = 1;
        v10 = &v6->m_avl_tree_node.m_right;
      }
      v3 = *v10 == NULL;
      v5[1].m_node = v10;
      cur_item = v5 + 1;
      ++v5;
    }
    while ( !v3 );
    v4 = v30;
  }
  *v5->m_node = v4;
  v4->m_avl_tree_node.m_left = NULL;
  v4->m_avl_tree_node.m_right = NULL;
  v4->m_avl_tree_node.m_balance = 0;
  v4->m_key = *key;
  if ( v5 > the_stack )
  {
    do
    {
      v12 = v5[-1].m_node;
      (*v12)->m_avl_tree_node.m_balance += v5[-1].m_child;
      v13 = *v12;
      v14 = (*v12)->m_avl_tree_node.m_balance;
      --v5;
      cur_item = v5;
      if ( v14 == -2 )
      {
        v15 = v13->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
        if ( v15 != -1
          && v15 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               130,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_left)->m_balance == -1 || accessor::get_avl_node(a"
               "ccessor::get_avl_node(root)->m_left)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v16 = *v12;
        v17 = (*v12)->m_avl_tree_node.m_left;
        if ( v17->m_avl_tree_node.m_balance == 1 )
        {
          v18 = v17->m_avl_tree_node.m_right;
          (*v12)->m_avl_tree_node.m_left->m_avl_tree_node.m_right = v18->m_avl_tree_node.m_left;
          v18->m_avl_tree_node.m_left = v16->m_avl_tree_node.m_left;
          v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance += v18->m_avl_tree_node.m_balance <= 0 ? 1 : v18->m_avl_tree_node.m_balance + -1;
          v5 = cur_item;
          v19 = -v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
          v18->m_avl_tree_node.m_balance += v19 < 0 || v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance == 0 ? 1 : v19 + -1;
          v16->m_avl_tree_node.m_left = v18;
        }
        v20 = (*v12)->m_avl_tree_node.m_left;
        (*v12)->m_avl_tree_node.m_left = v20->m_avl_tree_node.m_right;
        v21 = -v20->m_avl_tree_node.m_balance;
        v22 = v21 < 0 || v20->m_avl_tree_node.m_balance == 0;
        v20->m_avl_tree_node.m_right = *v12;
        (*v12)->m_avl_tree_node.m_balance += v22 ? 1 : v21 + 1;
        v20->m_avl_tree_node.m_balance += (*v12)->m_avl_tree_node.m_balance <= 0 ? 1 : (*v12)->m_avl_tree_node.m_balance
                                                                                     + 1;
        *v12 = v20;
        if ( !v20->m_avl_tree_node.m_balance )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                134,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      else
      {
        if ( v14 != 2 )
          continue;
        v24 = v13->m_avl_tree_node.m_right->m_avl_tree_node.m_balance;
        if ( v24 != -1
          && v24 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               138,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_right)->m_balance == -1 || accessor::get_avl_node("
               "accessor::get_avl_node(root)->m_right)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v25 = *v12;
        v26 = (*v12)->m_avl_tree_node.m_right;
        if ( v26->m_avl_tree_node.m_balance == -1 )
        {
          v27 = v26->m_avl_tree_node.m_left;
          v26->m_avl_tree_node.m_left = v27->m_avl_tree_node.m_right;
          v27->m_avl_tree_node.m_right = v25->m_avl_tree_node.m_right;
          v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance += -v27->m_avl_tree_node.m_balance < 0
                                                                  || v27->m_avl_tree_node.m_balance == 0 ? 1 : -v27->m_avl_tree_node.m_balance + 1;
          v5 = cur_item;
          v27->m_avl_tree_node.m_balance += v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance <= 0 ? 1 : v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance + 1;
          v25->m_avl_tree_node.m_right = v27;
        }
        v28 = (*v12)->m_avl_tree_node.m_right;
        (*v12)->m_avl_tree_node.m_right = v28->m_avl_tree_node.m_left;
        v29 = v28->m_avl_tree_node.m_balance;
        v28->m_avl_tree_node.m_left = *v12;
        (*v12)->m_avl_tree_node.m_balance += v29 <= 0 ? 1 : v29 + -1;
        v28->m_avl_tree_node.m_balance += -(*v12)->m_avl_tree_node.m_balance < 0
                                       || (*v12)->m_avl_tree_node.m_balance == 0 ? 1 : -(*v12)->m_avl_tree_node.m_balance
                                                                                     + -1;
        *v12 = v28;
        if ( !v28->m_avl_tree_node.m_balance )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                142,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      if ( v23 )
        __debugbreak();
    }
    while ( (*v12)->m_avl_tree_node.m_balance && v5 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::remove
==============
*/
void __thiscall phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::remove(phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor> *this, bpei_database_id *key)
{
  phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::stack_item *v2; // ebx
  broad_phase_environment_info *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edx
  bool v6; // cf
  bool v7; // cf
  broad_phase_environment_info **v8; // esi
  broad_phase_environment_info *v9; // ecx
  broad_phase_environment_info **v10; // eax
  broad_phase_environment_info *v11; // edx
  bool v12; // zf
  broad_phase_environment_info *v13; // ecx
  broad_phase_environment_info *v14; // eax
  broad_phase_environment_info *v15; // eax
  broad_phase_environment_info **v16; // esi
  broad_phase_environment_info *v17; // eax
  int v18; // ecx
  broad_phase_environment_info *v19; // ecx
  broad_phase_environment_info *v20; // ecx
  int v21; // edi
  broad_phase_environment_info *v22; // eax
  int v23; // edi
  BOOL v24; // edx
  int v25; // eax
  bool v26; // al
  broad_phase_environment_info *v27; // ecx
  broad_phase_environment_info *v28; // ecx
  broad_phase_environment_info *v29; // eax
  int v30; // edi
  int v31; // eax
  phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::stack_item *right_item; // [esp+Ch] [ebp-108h]
  phys_inplace_avl_tree<bpei_database_id,broad_phase_environment_info,broad_phase_environment_info::avl_tree_accessor>::stack_item the_stack[32]; // [esp+10h] [ebp-104h]

  v2 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = *v2->m_node;
      if ( !v3 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h", 161, "root", (const char *)&pBlock) )
        __debugbreak();
      if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             162,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v4 = key->m_id1;
      v5 = v3->m_database_id.m_id1;
      v6 = key->m_id1 < v5;
      if ( key->m_id1 == v5 )
        v6 = key->m_id2 < v3->m_database_id.m_id2;
      if ( !v6 )
        break;
      v2->m_child = -1;
      v2[1].m_node = &v3->m_avl_tree_node.m_left;
      ++v2;
    }
    v7 = v5 < v4;
    if ( v5 == v4 )
      v7 = v3->m_database_id.m_id2 < key->m_id2;
    if ( !v7 )
      break;
    v2->m_child = 1;
    v2[1].m_node = &v3->m_avl_tree_node.m_right;
    ++v2;
  }
  if ( (key->m_id1 != v3->m_database_id.m_id1 || key->m_id2 != v3->m_database_id.m_id2)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
         176,
         "key == accessor::get_avl_key(root)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v8 = v2->m_node;
  v9 = *v2->m_node;
  v10 = &v9->m_avl_tree_node.m_right;
  if ( v9->m_avl_tree_node.m_right )
  {
    v11 = *v10;
    v2->m_child = 1;
    ++v2;
    v12 = v11->m_avl_tree_node.m_left == NULL;
    v2->m_node = v10;
    right_item = v2;
    if ( !v12 )
    {
      do
      {
        if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               191,
               "cur_item + 1 - the_stack < 32",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v13 = *v2->m_node;
        v14 = v13->m_avl_tree_node.m_left;
        v2->m_child = -1;
        v2[1].m_node = &v13->m_avl_tree_node.m_left;
        ++v2;
      }
      while ( v14->m_avl_tree_node.m_left );
    }
    v15 = *v2->m_node;
    *v2->m_node = v15->m_avl_tree_node.m_right;
    v15->m_avl_tree_node.m_left = (*v8)->m_avl_tree_node.m_left;
    v15->m_avl_tree_node.m_right = (*v8)->m_avl_tree_node.m_right;
    v15->m_avl_tree_node.m_balance = (*v8)->m_avl_tree_node.m_balance;
    right_item->m_node = &v15->m_avl_tree_node.m_right;
  }
  else
  {
    v15 = v9->m_avl_tree_node.m_left;
  }
  *v8 = v15;
  if ( v2 > the_stack )
  {
    do
    {
      v16 = v2[-1].m_node;
      (*v16)->m_avl_tree_node.m_balance -= v2[-1].m_child;
      v17 = *v16;
      v18 = (*v16)->m_avl_tree_node.m_balance;
      --v2;
      right_item = v2;
      if ( v18 == -2 )
      {
        v19 = v17->m_avl_tree_node.m_left;
        if ( v19->m_avl_tree_node.m_balance == 1 )
        {
          v20 = v19->m_avl_tree_node.m_right;
          v17->m_avl_tree_node.m_left->m_avl_tree_node.m_right = v20->m_avl_tree_node.m_left;
          v20->m_avl_tree_node.m_left = v17->m_avl_tree_node.m_left;
          v17->m_avl_tree_node.m_left->m_avl_tree_node.m_balance += v20->m_avl_tree_node.m_balance <= 0 ? 1 : v20->m_avl_tree_node.m_balance + -1;
          v2 = right_item;
          v21 = -v17->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
          v20->m_avl_tree_node.m_balance += v21 < 0 || v17->m_avl_tree_node.m_left->m_avl_tree_node.m_balance == 0 ? 1 : v21 + -1;
          v17->m_avl_tree_node.m_left = v20;
        }
        v22 = (*v16)->m_avl_tree_node.m_left;
        (*v16)->m_avl_tree_node.m_left = v22->m_avl_tree_node.m_right;
        v23 = -v22->m_avl_tree_node.m_balance;
        v24 = v23 < 0 || v22->m_avl_tree_node.m_balance == 0;
        v22->m_avl_tree_node.m_right = *v16;
        (*v16)->m_avl_tree_node.m_balance += v24 ? 1 : v23 + 1;
        v22->m_avl_tree_node.m_balance += (*v16)->m_avl_tree_node.m_balance <= 0 ? 1 : (*v16)->m_avl_tree_node.m_balance
                                                                                     + 1;
        *v16 = v22;
        v25 = v22->m_avl_tree_node.m_balance;
        if ( !v25 || v25 == 1 )
          continue;
        v26 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                218,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == +1",
                (const char *)&pBlock);
      }
      else
      {
        if ( v18 != 2 )
          continue;
        v27 = v17->m_avl_tree_node.m_right;
        if ( v27->m_avl_tree_node.m_balance == -1 )
        {
          v28 = v27->m_avl_tree_node.m_left;
          v17->m_avl_tree_node.m_right->m_avl_tree_node.m_left = v28->m_avl_tree_node.m_right;
          v28->m_avl_tree_node.m_right = v17->m_avl_tree_node.m_right;
          v17->m_avl_tree_node.m_right->m_avl_tree_node.m_balance += -v28->m_avl_tree_node.m_balance < 0
                                                                  || v28->m_avl_tree_node.m_balance == 0 ? 1 : -v28->m_avl_tree_node.m_balance + 1;
          v2 = right_item;
          v28->m_avl_tree_node.m_balance += v17->m_avl_tree_node.m_right->m_avl_tree_node.m_balance <= 0 ? 1 : v17->m_avl_tree_node.m_right->m_avl_tree_node.m_balance + 1;
          v17->m_avl_tree_node.m_right = v28;
        }
        v29 = (*v16)->m_avl_tree_node.m_right;
        (*v16)->m_avl_tree_node.m_right = v29->m_avl_tree_node.m_left;
        v30 = v29->m_avl_tree_node.m_balance;
        v29->m_avl_tree_node.m_left = *v16;
        (*v16)->m_avl_tree_node.m_balance += v30 <= 0 ? 1 : v30 + -1;
        v29->m_avl_tree_node.m_balance += -(*v16)->m_avl_tree_node.m_balance < 0
                                       || (*v16)->m_avl_tree_node.m_balance == 0 ? 1 : -(*v16)->m_avl_tree_node.m_balance
                                                                                     + -1;
        *v16 = v29;
        v31 = v29->m_avl_tree_node.m_balance;
        if ( !v31 || v31 == -1 )
          continue;
        v26 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                225,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == -1",
                (const char *)&pBlock);
      }
      if ( v26 )
        __debugbreak();
    }
    while ( !(*v16)->m_avl_tree_node.m_balance && v2 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::remove
==============
*/
void __thiscall phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::remove(phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor> *this, phys_gjk_geom_id_pair_key *key)
{
  phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::stack_item *v2; // ebx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edx
  bool v6; // cf
  bool v7; // cf
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal **v8; // esi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v9; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal **v10; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v11; // edx
  bool v12; // zf
  int v13; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v14; // eax
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal **v15; // esi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v16; // eax
  int v17; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v18; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v19; // ecx
  int v20; // edi
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v21; // eax
  int v22; // edi
  BOOL v23; // edx
  int v24; // eax
  bool v25; // al
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v26; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v27; // ecx
  phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal *v28; // eax
  int v29; // edi
  int v30; // eax
  phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::stack_item *right_item; // [esp+Ch] [ebp-10Ch]
  phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::stack_item *cur_item; // [esp+10h] [ebp-108h]
  phys_inplace_avl_tree<phys_gjk_geom_id_pair_key,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal,phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal::avl_tree_accessor>::stack_item the_stack[32]; // [esp+14h] [ebp-104h]

  v2 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = *v2->m_node;
      if ( !v3 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h", 161, "root", (const char *)&pBlock) )
        __debugbreak();
      if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             162,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v4 = key->m_id1;
      v5 = v3->m_key.m_id1;
      v6 = key->m_id1 < v5;
      if ( key->m_id1 == v5 )
        v6 = key->m_id2 < v3->m_key.m_id2;
      if ( !v6 )
        break;
      v2->m_child = -1;
      v2[1].m_node = &v3->m_avl_tree_node.m_left;
      ++v2;
      cur_item = v2;
    }
    v7 = v5 < v4;
    if ( v5 == v4 )
      v7 = v3->m_key.m_id2 < key->m_id2;
    if ( !v7 )
      break;
    v2->m_child = 1;
    v2[1].m_node = &v3->m_avl_tree_node.m_right;
    ++v2;
    cur_item = v2;
  }
  if ( (key->m_id1 != v3->m_key.m_id1 || key->m_id2 != v3->m_key.m_id2)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
         176,
         "key == accessor::get_avl_key(root)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v8 = v2->m_node;
  v9 = *v2->m_node;
  v10 = &v9->m_avl_tree_node.m_right;
  if ( v9->m_avl_tree_node.m_right )
  {
    v11 = *v10;
    v2->m_child = 1;
    ++v2;
    v12 = v11->m_avl_tree_node.m_left == NULL;
    v2->m_node = v10;
    right_item = v2;
    if ( !v12 )
    {
      do
      {
        if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               191,
               "cur_item + 1 - the_stack < 32",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v13 = (int)&(*v2->m_node)->m_avl_tree_node;
        v2->m_child = -1;
        ++v2;
        cur_item = v2;
        v2->m_node = (phys_heap_gjk_cache_system_avl_tree::phys_gjk_cache_info_internal **)v13;
      }
      while ( *(_DWORD *)(*(_DWORD *)v13 + 128) );
    }
    v14 = *v2->m_node;
    *v2->m_node = v14->m_avl_tree_node.m_right;
    v14->m_avl_tree_node.m_left = (*v8)->m_avl_tree_node.m_left;
    v14->m_avl_tree_node.m_right = (*v8)->m_avl_tree_node.m_right;
    v14->m_avl_tree_node.m_balance = (*v8)->m_avl_tree_node.m_balance;
    right_item->m_node = &v14->m_avl_tree_node.m_right;
  }
  else
  {
    v14 = v9->m_avl_tree_node.m_left;
  }
  *v8 = v14;
  if ( v2 > the_stack )
  {
    do
    {
      v15 = v2[-1].m_node;
      (*v15)->m_avl_tree_node.m_balance -= v2[-1].m_child;
      v16 = *v15;
      v17 = (*v15)->m_avl_tree_node.m_balance;
      --v2;
      cur_item = v2;
      if ( v17 == -2 )
      {
        v18 = v16->m_avl_tree_node.m_left;
        if ( v18->m_avl_tree_node.m_balance == 1 )
        {
          v19 = v18->m_avl_tree_node.m_right;
          v16->m_avl_tree_node.m_left->m_avl_tree_node.m_right = v19->m_avl_tree_node.m_left;
          v19->m_avl_tree_node.m_left = v16->m_avl_tree_node.m_left;
          v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance += v19->m_avl_tree_node.m_balance <= 0 ? 1 : v19->m_avl_tree_node.m_balance + -1;
          v2 = cur_item;
          v20 = -v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
          v19->m_avl_tree_node.m_balance += v20 < 0 || v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance == 0 ? 1 : v20 + -1;
          v16->m_avl_tree_node.m_left = v19;
        }
        v21 = (*v15)->m_avl_tree_node.m_left;
        (*v15)->m_avl_tree_node.m_left = v21->m_avl_tree_node.m_right;
        v22 = -v21->m_avl_tree_node.m_balance;
        v23 = v22 < 0 || v21->m_avl_tree_node.m_balance == 0;
        v21->m_avl_tree_node.m_right = *v15;
        (*v15)->m_avl_tree_node.m_balance += v23 ? 1 : v22 + 1;
        v21->m_avl_tree_node.m_balance += (*v15)->m_avl_tree_node.m_balance <= 0 ? 1 : (*v15)->m_avl_tree_node.m_balance
                                                                                     + 1;
        *v15 = v21;
        v24 = v21->m_avl_tree_node.m_balance;
        if ( !v24 || v24 == 1 )
          continue;
        v25 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                218,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == +1",
                (const char *)&pBlock);
      }
      else
      {
        if ( v17 != 2 )
          continue;
        v26 = v16->m_avl_tree_node.m_right;
        if ( v26->m_avl_tree_node.m_balance == -1 )
        {
          v27 = v26->m_avl_tree_node.m_left;
          v16->m_avl_tree_node.m_right->m_avl_tree_node.m_left = v27->m_avl_tree_node.m_right;
          v27->m_avl_tree_node.m_right = v16->m_avl_tree_node.m_right;
          v16->m_avl_tree_node.m_right->m_avl_tree_node.m_balance += -v27->m_avl_tree_node.m_balance < 0
                                                                  || v27->m_avl_tree_node.m_balance == 0 ? 1 : -v27->m_avl_tree_node.m_balance + 1;
          v2 = cur_item;
          v27->m_avl_tree_node.m_balance += v16->m_avl_tree_node.m_right->m_avl_tree_node.m_balance <= 0 ? 1 : v16->m_avl_tree_node.m_right->m_avl_tree_node.m_balance + 1;
          v16->m_avl_tree_node.m_right = v27;
        }
        v28 = (*v15)->m_avl_tree_node.m_right;
        (*v15)->m_avl_tree_node.m_right = v28->m_avl_tree_node.m_left;
        v29 = v28->m_avl_tree_node.m_balance;
        v28->m_avl_tree_node.m_left = *v15;
        (*v15)->m_avl_tree_node.m_balance += v29 <= 0 ? 1 : v29 + -1;
        v28->m_avl_tree_node.m_balance += -(*v15)->m_avl_tree_node.m_balance < 0
                                       || (*v15)->m_avl_tree_node.m_balance == 0 ? 1 : -(*v15)->m_avl_tree_node.m_balance
                                                                                     + -1;
        *v15 = v28;
        v30 = v28->m_avl_tree_node.m_balance;
        if ( !v30 || v30 == -1 )
          continue;
        v25 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                225,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == -1",
                (const char *)&pBlock);
      }
      if ( v25 )
        __debugbreak();
    }
    while ( !(*v15)->m_avl_tree_node.m_balance && v2 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::find
==============
*/
rigid_body_constraint_contact *__thiscall phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::find(phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor> *this, rigid_body_pair_key *key)
{
  rigid_body_constraint_contact *result; // eax
  rigid_body *v3; // edx
  rigid_body *v4; // ecx
  bool v5; // cf
  rigid_body *v6; // edi

  result = this->m_tree_root;
  if ( this->m_tree_root )
  {
    v3 = key->m_b1;
    do
    {
      v4 = result->m_avl_key.m_b1;
      v5 = v3 < v4;
      if ( v3 == v4 )
      {
        v6 = key->m_b2;
        if ( v6 == result->m_avl_key.m_b2 )
          return result;
        v5 = v3 < v4;
        if ( v3 == v4 )
          v5 = v6 < result->m_avl_key.m_b2;
      }
      if ( v5 )
        result = result->m_avl_tree_node.m_left;
      else
        result = result->m_avl_tree_node.m_right;
    }
    while ( result );
  }
  return result;
}

/*
==============
phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::add
==============
*/
void __thiscall phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::add(phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor> *this, rigid_body_pair_key *key, rigid_body_constraint_contact *data)
{
  bool v3; // zf
  rigid_body_constraint_contact *v4; // eax
  phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::stack_item *v5; // ebx
  rigid_body_constraint_contact *v6; // esi
  rigid_body *v7; // ecx
  rigid_body *v8; // edx
  bool v9; // cf
  rigid_body_constraint_contact **v10; // esi
  bool v11; // cf
  rigid_body_constraint_contact **v12; // esi
  rigid_body_constraint_contact *v13; // eax
  int v14; // ecx
  int v15; // eax
  rigid_body_constraint_contact *v16; // ecx
  rigid_body_constraint_contact *v17; // eax
  rigid_body_constraint_contact *v18; // eax
  int v19; // edi
  rigid_body_constraint_contact *v20; // eax
  int v21; // edi
  BOOL v22; // edx
  char v23; // al
  int v24; // eax
  rigid_body_constraint_contact *v25; // ecx
  rigid_body_constraint_contact *v26; // edx
  rigid_body_constraint_contact *v27; // eax
  rigid_body_constraint_contact *v28; // eax
  int v29; // edi
  phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::stack_item *cur_item; // [esp+Ch] [ebp-108h]
  phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::stack_item the_stack[32]; // [esp+10h] [ebp-104h]

  v3 = this->m_tree_root == NULL;
  v4 = data;
  cur_item = (phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::stack_item *)data;
  v5 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  if ( !v3 )
  {
    do
    {
      v6 = *v5->m_node;
      if ( (signed int)(((char *)v5 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             103,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v7 = key->m_b1;
      v8 = v6->m_avl_key.m_b1;
      v9 = key->m_b1 < v8;
      if ( key->m_b1 == v8 )
        v9 = key->m_b2 < v6->m_avl_key.m_b2;
      if ( v9 )
      {
        v5->m_child = -1;
        v10 = &v6->m_avl_tree_node.m_left;
      }
      else
      {
        v11 = v8 < v7;
        if ( v8 == v7 )
          v11 = v6->m_avl_key.m_b2 < key->m_b2;
        if ( !v11
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               112,
               "key > accessor::get_avl_key(root)",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v5->m_child = 1;
        v10 = &v6->m_avl_tree_node.m_right;
      }
      v3 = *v10 == NULL;
      v5[1].m_node = v10;
      ++v5;
    }
    while ( !v3 );
    v4 = (rigid_body_constraint_contact *)cur_item;
  }
  *v5->m_node = v4;
  v4->m_avl_tree_node.m_left = NULL;
  v4->m_avl_tree_node.m_right = NULL;
  v4->m_avl_tree_node.m_balance = 0;
  v4->m_avl_key = *key;
  if ( v5 > the_stack )
  {
    do
    {
      v12 = v5[-1].m_node;
      (*v12)->m_avl_tree_node.m_balance += v5[-1].m_child;
      v13 = *v12;
      v14 = (*v12)->m_avl_tree_node.m_balance;
      --v5;
      cur_item = v5;
      if ( v14 == -2 )
      {
        v15 = v13->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
        if ( v15 != -1
          && v15 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               130,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_left)->m_balance == -1 || accessor::get_avl_node(a"
               "ccessor::get_avl_node(root)->m_left)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v16 = *v12;
        v17 = (*v12)->m_avl_tree_node.m_left;
        if ( v17->m_avl_tree_node.m_balance == 1 )
        {
          v18 = v17->m_avl_tree_node.m_right;
          (*v12)->m_avl_tree_node.m_left->m_avl_tree_node.m_right = v18->m_avl_tree_node.m_left;
          v18->m_avl_tree_node.m_left = v16->m_avl_tree_node.m_left;
          v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance += v18->m_avl_tree_node.m_balance <= 0 ? 1 : v18->m_avl_tree_node.m_balance + -1;
          v5 = cur_item;
          v19 = -v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
          v18->m_avl_tree_node.m_balance += v19 < 0 || v16->m_avl_tree_node.m_left->m_avl_tree_node.m_balance == 0 ? 1 : v19 + -1;
          v16->m_avl_tree_node.m_left = v18;
        }
        v20 = (*v12)->m_avl_tree_node.m_left;
        (*v12)->m_avl_tree_node.m_left = v20->m_avl_tree_node.m_right;
        v21 = -v20->m_avl_tree_node.m_balance;
        v22 = v21 < 0 || v20->m_avl_tree_node.m_balance == 0;
        v20->m_avl_tree_node.m_right = *v12;
        (*v12)->m_avl_tree_node.m_balance += v22 ? 1 : v21 + 1;
        v20->m_avl_tree_node.m_balance += (*v12)->m_avl_tree_node.m_balance <= 0 ? 1 : (*v12)->m_avl_tree_node.m_balance
                                                                                     + 1;
        *v12 = v20;
        if ( !v20->m_avl_tree_node.m_balance )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                134,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      else
      {
        if ( v14 != 2 )
          continue;
        v24 = v13->m_avl_tree_node.m_right->m_avl_tree_node.m_balance;
        if ( v24 != -1
          && v24 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               138,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_right)->m_balance == -1 || accessor::get_avl_node("
               "accessor::get_avl_node(root)->m_right)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v25 = *v12;
        v26 = (*v12)->m_avl_tree_node.m_right;
        if ( v26->m_avl_tree_node.m_balance == -1 )
        {
          v27 = v26->m_avl_tree_node.m_left;
          v26->m_avl_tree_node.m_left = v27->m_avl_tree_node.m_right;
          v27->m_avl_tree_node.m_right = v25->m_avl_tree_node.m_right;
          v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance += -v27->m_avl_tree_node.m_balance < 0
                                                                  || v27->m_avl_tree_node.m_balance == 0 ? 1 : -v27->m_avl_tree_node.m_balance + 1;
          v5 = cur_item;
          v27->m_avl_tree_node.m_balance += v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance <= 0 ? 1 : v25->m_avl_tree_node.m_right->m_avl_tree_node.m_balance + 1;
          v25->m_avl_tree_node.m_right = v27;
        }
        v28 = (*v12)->m_avl_tree_node.m_right;
        (*v12)->m_avl_tree_node.m_right = v28->m_avl_tree_node.m_left;
        v29 = v28->m_avl_tree_node.m_balance;
        v28->m_avl_tree_node.m_left = *v12;
        (*v12)->m_avl_tree_node.m_balance += v29 <= 0 ? 1 : v29 + -1;
        v28->m_avl_tree_node.m_balance += -(*v12)->m_avl_tree_node.m_balance < 0
                                       || (*v12)->m_avl_tree_node.m_balance == 0 ? 1 : -(*v12)->m_avl_tree_node.m_balance
                                                                                     + -1;
        *v12 = v28;
        if ( !v28->m_avl_tree_node.m_balance )
          continue;
        v23 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                142,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      if ( v23 )
        __debugbreak();
    }
    while ( (*v12)->m_avl_tree_node.m_balance && v5 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::remove
==============
*/
void __thiscall phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::remove(phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor> *this, rigid_body_pair_key *key)
{
  phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::stack_item *v2; // ebx
  rigid_body_constraint_contact *v3; // esi
  rigid_body *v4; // ecx
  rigid_body *v5; // edx
  bool v6; // cf
  bool v7; // cf
  rigid_body_constraint_contact **v8; // esi
  rigid_body_constraint_contact *v9; // ecx
  rigid_body_constraint_contact **v10; // eax
  rigid_body_constraint_contact *v11; // edx
  bool v12; // zf
  rigid_body_constraint_contact *v13; // ecx
  rigid_body_constraint_contact *v14; // eax
  rigid_body_constraint_contact *v15; // eax
  rigid_body_constraint_contact **v16; // esi
  rigid_body_constraint_contact *v17; // eax
  int v18; // ecx
  rigid_body_constraint_contact *v19; // ecx
  rigid_body_constraint_contact *v20; // ecx
  int v21; // edi
  rigid_body_constraint_contact *v22; // eax
  int v23; // edi
  BOOL v24; // edx
  int v25; // eax
  char v26; // al
  rigid_body_constraint_contact *v27; // ecx
  rigid_body_constraint_contact *v28; // ecx
  rigid_body_constraint_contact *v29; // eax
  int v30; // edi
  int v31; // eax
  phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::stack_item *right_item; // [esp+Ch] [ebp-108h]
  phys_inplace_avl_tree<rigid_body_pair_key,rigid_body_constraint_contact,rigid_body_constraint_contact::avl_tree_accessor>::stack_item the_stack[32]; // [esp+10h] [ebp-104h]

  v2 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  while ( 1 )
  {
    while ( 1 )
    {
      v3 = *v2->m_node;
      if ( !v3 && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h", 161, "root", (const char *)&pBlock) )
        __debugbreak();
      if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             162,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v4 = key->m_b1;
      v5 = v3->m_avl_key.m_b1;
      v6 = key->m_b1 < v5;
      if ( key->m_b1 == v5 )
        v6 = key->m_b2 < v3->m_avl_key.m_b2;
      if ( !v6 )
        break;
      v2->m_child = -1;
      v2[1].m_node = &v3->m_avl_tree_node.m_left;
      ++v2;
    }
    v7 = v5 < v4;
    if ( v5 == v4 )
      v7 = v3->m_avl_key.m_b2 < key->m_b2;
    if ( !v7 )
      break;
    v2->m_child = 1;
    v2[1].m_node = &v3->m_avl_tree_node.m_right;
    ++v2;
  }
  if ( (key->m_b1 != v3->m_avl_key.m_b1 || key->m_b2 != v3->m_avl_key.m_b2)
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
         176,
         "key == accessor::get_avl_key(root)",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v8 = v2->m_node;
  v9 = *v2->m_node;
  v10 = &v9->m_avl_tree_node.m_right;
  if ( v9->m_avl_tree_node.m_right )
  {
    v11 = *v10;
    v2->m_child = 1;
    ++v2;
    v12 = v11->m_avl_tree_node.m_left == NULL;
    v2->m_node = v10;
    right_item = v2;
    if ( !v12 )
    {
      do
      {
        if ( (signed int)(((char *)v2 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               191,
               "cur_item + 1 - the_stack < 32",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v13 = *v2->m_node;
        v14 = v13->m_avl_tree_node.m_left;
        v2->m_child = -1;
        v2[1].m_node = &v13->m_avl_tree_node.m_left;
        ++v2;
      }
      while ( v14->m_avl_tree_node.m_left );
    }
    v15 = *v2->m_node;
    *v2->m_node = v15->m_avl_tree_node.m_right;
    v15->m_avl_tree_node.m_left = (*v8)->m_avl_tree_node.m_left;
    v15->m_avl_tree_node.m_right = (*v8)->m_avl_tree_node.m_right;
    v15->m_avl_tree_node.m_balance = (*v8)->m_avl_tree_node.m_balance;
    right_item->m_node = &v15->m_avl_tree_node.m_right;
  }
  else
  {
    v15 = v9->m_avl_tree_node.m_left;
  }
  *v8 = v15;
  if ( v2 > the_stack )
  {
    do
    {
      v16 = v2[-1].m_node;
      (*v16)->m_avl_tree_node.m_balance -= v2[-1].m_child;
      v17 = *v16;
      v18 = (*v16)->m_avl_tree_node.m_balance;
      --v2;
      right_item = v2;
      if ( v18 == -2 )
      {
        v19 = v17->m_avl_tree_node.m_left;
        if ( v19->m_avl_tree_node.m_balance == 1 )
        {
          v20 = v19->m_avl_tree_node.m_right;
          v17->m_avl_tree_node.m_left->m_avl_tree_node.m_right = v20->m_avl_tree_node.m_left;
          v20->m_avl_tree_node.m_left = v17->m_avl_tree_node.m_left;
          v17->m_avl_tree_node.m_left->m_avl_tree_node.m_balance += v20->m_avl_tree_node.m_balance <= 0 ? 1 : v20->m_avl_tree_node.m_balance + -1;
          v2 = right_item;
          v21 = -v17->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
          v20->m_avl_tree_node.m_balance += v21 < 0 || v17->m_avl_tree_node.m_left->m_avl_tree_node.m_balance == 0 ? 1 : v21 + -1;
          v17->m_avl_tree_node.m_left = v20;
        }
        v22 = (*v16)->m_avl_tree_node.m_left;
        (*v16)->m_avl_tree_node.m_left = v22->m_avl_tree_node.m_right;
        v23 = -v22->m_avl_tree_node.m_balance;
        v24 = v23 < 0 || v22->m_avl_tree_node.m_balance == 0;
        v22->m_avl_tree_node.m_right = *v16;
        (*v16)->m_avl_tree_node.m_balance += v24 ? 1 : v23 + 1;
        v22->m_avl_tree_node.m_balance += (*v16)->m_avl_tree_node.m_balance <= 0 ? 1 : (*v16)->m_avl_tree_node.m_balance
                                                                                     + 1;
        *v16 = v22;
        v25 = v22->m_avl_tree_node.m_balance;
        if ( !v25 || v25 == 1 )
          continue;
        v26 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                218,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == +1",
                (const char *)&pBlock);
      }
      else
      {
        if ( v18 != 2 )
          continue;
        v27 = v17->m_avl_tree_node.m_right;
        if ( v27->m_avl_tree_node.m_balance == -1 )
        {
          v28 = v27->m_avl_tree_node.m_left;
          v17->m_avl_tree_node.m_right->m_avl_tree_node.m_left = v28->m_avl_tree_node.m_right;
          v28->m_avl_tree_node.m_right = v17->m_avl_tree_node.m_right;
          v17->m_avl_tree_node.m_right->m_avl_tree_node.m_balance += -v28->m_avl_tree_node.m_balance < 0
                                                                  || v28->m_avl_tree_node.m_balance == 0 ? 1 : -v28->m_avl_tree_node.m_balance + 1;
          v2 = right_item;
          v28->m_avl_tree_node.m_balance += v17->m_avl_tree_node.m_right->m_avl_tree_node.m_balance <= 0 ? 1 : v17->m_avl_tree_node.m_right->m_avl_tree_node.m_balance + 1;
          v17->m_avl_tree_node.m_right = v28;
        }
        v29 = (*v16)->m_avl_tree_node.m_right;
        (*v16)->m_avl_tree_node.m_right = v29->m_avl_tree_node.m_left;
        v30 = v29->m_avl_tree_node.m_balance;
        v29->m_avl_tree_node.m_left = *v16;
        (*v16)->m_avl_tree_node.m_balance += v30 <= 0 ? 1 : v30 + -1;
        v29->m_avl_tree_node.m_balance += -(*v16)->m_avl_tree_node.m_balance < 0
                                       || (*v16)->m_avl_tree_node.m_balance == 0 ? 1 : -(*v16)->m_avl_tree_node.m_balance
                                                                                     + -1;
        *v16 = v29;
        v31 = v29->m_avl_tree_node.m_balance;
        if ( !v31 || v31 == -1 )
          continue;
        v26 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                225,
                "accessor::get_avl_node(root)->m_balance == 0 || accessor::get_avl_node(root)->m_balance == -1",
                (const char *)&pBlock);
      }
      if ( v26 )
        __debugbreak();
    }
    while ( !(*v16)->m_avl_tree_node.m_balance && v2 > the_stack );
  }
}

/*
==============
phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor>::add
==============
*/
void __thiscall phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor>::add(phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *this, user_rigid_body *const *key, pulse_sum_constraint_solver::temp_user_rigid_body *data)
{
  pulse_sum_constraint_solver::temp_user_rigid_body *v3; // eax
  phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor>::stack_item *v4; // ebx
  pulse_sum_constraint_solver::temp_user_rigid_body *v5; // edi
  user_rigid_body *v6; // ecx
  pulse_sum_constraint_solver::temp_user_rigid_body **v7; // edi
  bool v8; // zf
  pulse_sum_constraint_solver::temp_user_rigid_body **v9; // esi
  pulse_sum_constraint_solver::temp_user_rigid_body *v10; // eax
  int v11; // ecx
  int v12; // eax
  pulse_sum_constraint_solver::temp_user_rigid_body *v13; // ecx
  pulse_sum_constraint_solver::temp_user_rigid_body *v14; // eax
  pulse_sum_constraint_solver::temp_user_rigid_body *v15; // eax
  int v16; // edi
  pulse_sum_constraint_solver::temp_user_rigid_body *v17; // eax
  int v18; // edi
  BOOL v19; // edx
  char v20; // al
  int v21; // eax
  pulse_sum_constraint_solver::temp_user_rigid_body *v22; // ecx
  pulse_sum_constraint_solver::temp_user_rigid_body *v23; // edx
  pulse_sum_constraint_solver::temp_user_rigid_body *v24; // eax
  pulse_sum_constraint_solver::temp_user_rigid_body *v25; // eax
  int v26; // edi
  phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor>::stack_item *cur_item; // [esp+Ch] [ebp-108h]
  phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor>::stack_item the_stack[32]; // [esp+10h] [ebp-104h]

  v3 = data;
  cur_item = (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor>::stack_item *)data;
  v4 = the_stack;
  the_stack[0].m_node = &this->m_tree_root;
  if ( this->m_tree_root )
  {
    do
    {
      v5 = *v4->m_node;
      if ( (signed int)(((char *)v4 - (char *)the_stack + 8) & 0xFFFFFFF8) >= 256
        && _tlAssert(
             "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
             103,
             "cur_item + 1 - the_stack < 32",
             (const char *)&pBlock) )
      {
        __debugbreak();
      }
      v6 = v5->m_avl_key;
      if ( *key >= v6 )
      {
        if ( *key <= v6
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               112,
               "key > accessor::get_avl_key(root)",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v4->m_child = 1;
        v7 = &v5->m_avl_tree_node.m_right;
      }
      else
      {
        v4->m_child = -1;
        v7 = &v5->m_avl_tree_node.m_left;
      }
      v8 = *v7 == NULL;
      v4[1].m_node = v7;
      ++v4;
    }
    while ( !v8 );
    v3 = (pulse_sum_constraint_solver::temp_user_rigid_body *)cur_item;
  }
  *v4->m_node = v3;
  v3->m_avl_tree_node.m_left = NULL;
  v3->m_avl_tree_node.m_right = NULL;
  v3->m_avl_tree_node.m_balance = 0;
  v3->m_avl_key = *key;
  if ( v4 > the_stack )
  {
    do
    {
      v9 = v4[-1].m_node;
      (*v9)->m_avl_tree_node.m_balance += v4[-1].m_child;
      v10 = *v9;
      v11 = (*v9)->m_avl_tree_node.m_balance;
      --v4;
      cur_item = v4;
      if ( v11 == -2 )
      {
        v12 = v10->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
        if ( v12 != -1
          && v12 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               130,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_left)->m_balance == -1 || accessor::get_avl_node(a"
               "ccessor::get_avl_node(root)->m_left)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v13 = *v9;
        v14 = (*v9)->m_avl_tree_node.m_left;
        if ( v14->m_avl_tree_node.m_balance == 1 )
        {
          v15 = v14->m_avl_tree_node.m_right;
          (*v9)->m_avl_tree_node.m_left->m_avl_tree_node.m_right = v15->m_avl_tree_node.m_left;
          v15->m_avl_tree_node.m_left = v13->m_avl_tree_node.m_left;
          v13->m_avl_tree_node.m_left->m_avl_tree_node.m_balance += v15->m_avl_tree_node.m_balance <= 0 ? 1 : v15->m_avl_tree_node.m_balance + -1;
          v4 = cur_item;
          v16 = -v13->m_avl_tree_node.m_left->m_avl_tree_node.m_balance;
          v15->m_avl_tree_node.m_balance += v16 < 0 || v13->m_avl_tree_node.m_left->m_avl_tree_node.m_balance == 0 ? 1 : v16 + -1;
          v13->m_avl_tree_node.m_left = v15;
        }
        v17 = (*v9)->m_avl_tree_node.m_left;
        (*v9)->m_avl_tree_node.m_left = v17->m_avl_tree_node.m_right;
        v18 = -v17->m_avl_tree_node.m_balance;
        v19 = v18 < 0 || v17->m_avl_tree_node.m_balance == 0;
        v17->m_avl_tree_node.m_right = *v9;
        (*v9)->m_avl_tree_node.m_balance += v19 ? 1 : v18 + 1;
        v17->m_avl_tree_node.m_balance += (*v9)->m_avl_tree_node.m_balance <= 0 ? 1 : (*v9)->m_avl_tree_node.m_balance
                                                                                    + 1;
        *v9 = v17;
        if ( !v17->m_avl_tree_node.m_balance )
          continue;
        v20 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                134,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      else
      {
        if ( v11 != 2 )
          continue;
        v21 = v10->m_avl_tree_node.m_right->m_avl_tree_node.m_balance;
        if ( v21 != -1
          && v21 != 1
          && _tlAssert(
               "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
               138,
               "accessor::get_avl_node(accessor::get_avl_node(root)->m_right)->m_balance == -1 || accessor::get_avl_node("
               "accessor::get_avl_node(root)->m_right)->m_balance == 1",
               (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v22 = *v9;
        v23 = (*v9)->m_avl_tree_node.m_right;
        if ( v23->m_avl_tree_node.m_balance == -1 )
        {
          v24 = v23->m_avl_tree_node.m_left;
          v23->m_avl_tree_node.m_left = v24->m_avl_tree_node.m_right;
          v24->m_avl_tree_node.m_right = v22->m_avl_tree_node.m_right;
          v22->m_avl_tree_node.m_right->m_avl_tree_node.m_balance += -v24->m_avl_tree_node.m_balance < 0
                                                                  || v24->m_avl_tree_node.m_balance == 0 ? 1 : -v24->m_avl_tree_node.m_balance + 1;
          v4 = cur_item;
          v24->m_avl_tree_node.m_balance += v22->m_avl_tree_node.m_right->m_avl_tree_node.m_balance <= 0 ? 1 : v22->m_avl_tree_node.m_right->m_avl_tree_node.m_balance + 1;
          v22->m_avl_tree_node.m_right = v24;
        }
        v25 = (*v9)->m_avl_tree_node.m_right;
        (*v9)->m_avl_tree_node.m_right = v25->m_avl_tree_node.m_left;
        v26 = v25->m_avl_tree_node.m_balance;
        v25->m_avl_tree_node.m_left = *v9;
        (*v9)->m_avl_tree_node.m_balance += v26 <= 0 ? 1 : v26 + -1;
        v25->m_avl_tree_node.m_balance += -(*v9)->m_avl_tree_node.m_balance < 0 || (*v9)->m_avl_tree_node.m_balance == 0 ? 1 : -(*v9)->m_avl_tree_node.m_balance + -1;
        *v9 = v25;
        if ( !v25->m_avl_tree_node.m_balance )
          continue;
        v20 = _tlAssert(
                "c:\\t6\\code\\tl\\physics\\include\\phys_avl_tree.h",
                142,
                "accessor::get_avl_node(root)->m_balance == 0",
                (const char *)&pBlock);
      }
      if ( v20 )
        __debugbreak();
    }
    while ( (*v9)->m_avl_tree_node.m_balance && v4 > the_stack );
  }
}

