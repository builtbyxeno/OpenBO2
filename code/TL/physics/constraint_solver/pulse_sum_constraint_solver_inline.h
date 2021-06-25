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
pulse_sum_constraint_solver::solve_iterative
==============
*/
void __thiscall pulse_sum_constraint_solver::solve_iterative(pulse_sum_constraint_solver *this, const int max_iters, const float max_error_sq)
{
  int v3; // ebx
  pulse_sum_constraint_solver *v4; // edi
  pulse_sum_normal *v5; // esi
  pulse_sum_point *i; // esi
  pulse_sum_angular *j; // esi
  pulse_sum_wheel *k; // esi
  pulse_sum_contact *l; // esi
  float error_sq; // [esp+0h] [ebp-4h]

  v3 = 0;
  v4 = this;
  error_sq = max_error_sq + max_error_sq;
  while ( v3 <= max_iters )
  {
    if ( max_error_sq >= (double)error_sq )
      break;
    v5 = v4->m_list_pulse_sum_normal.m_first;
    ++v3;
    for ( error_sq = 0.0; v5; v5 = v5->m_next_link )
      pulse_sum_normal::SOLVER_apply_relaxation(v5, &error_sq, 1);
    for ( i = v4->m_list_pulse_sum_point.m_first; i; i = i->m_next_link )
      pulse_sum_point::SOLVER_apply_relaxation(i, &error_sq);
    for ( j = v4->m_list_pulse_sum_angular.m_first; j; j = j->m_next_link )
      pulse_sum_angular::SOLVER_apply_relaxation(j, &error_sq);
    for ( k = v4->m_list_pulse_sum_wheel.m_first; k; k = k->m_next_link )
      pulse_sum_wheel::SOLVER_apply_relaxation(k, &error_sq);
    for ( l = v4->m_list_pulse_sum_contact.m_first; l; l = l->m_next_link )
      pulse_sum_contact::SOLVER_apply_relaxation(l, &error_sq);
  }
}

/*
==============
pulse_sum_constraint_solver::add_urb
==============
*/
void __thiscall pulse_sum_constraint_solver::add_urb(pulse_sum_constraint_solver *this, phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *turb_search_tree, phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *list_turb, phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *list_urbri, rigid_body_constraint *rbc)
{
  user_rigid_body **v5; // edi
  pulse_sum_constraint_solver *v6; // edx
  rigid_body *v7; // eax
  phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *v8; // esi
  user_rigid_body *v9; // ecx
  user_rigid_body *v10; // eax
  pulse_sum_constraint_solver::user_rigid_body_restore_info *v11; // eax
  pulse_sum_constraint_solver *v12; // [esp+4h] [ebp-4h]

  v5 = (user_rigid_body **)rbc;
  v6 = this;
  v12 = this;
  if ( rbc->b1 && rbc->b1->m_flags & 0x20 || (v7 = rbc->b2, v5 = (user_rigid_body **)&rbc->b2, v7) && v7->m_flags & 0x20 )
  {
    if ( v5 )
    {
      v8 = (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)turb_search_tree->m_tree_root;
      if ( !turb_search_tree->m_tree_root )
        goto LABEL_18;
      v9 = *v5;
      do
      {
        v10 = (user_rigid_body *)&v8[109].m_first->m_last_position;
        if ( v9 == v10 )
          break;
        v8 = (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)(v9 >= v10 ? v8[111].m_first : v8[110].m_first);
      }
      while ( v8 );
      if ( !v8 )
      {
LABEL_18:
        v8 = (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)phys_transient_allocator::allocate(
                                                                                           &v6->m_solver_memory_allocator,
                                                                                           464,
                                                                                           16,
                                                                                           0,
                                                                                           SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
        user_rigid_body::operator=((user_rigid_body *)v8, *v5);
        phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor>::add(
          turb_search_tree,
          v5,
          (pulse_sum_constraint_solver::temp_user_rigid_body *)v8);
        v8[108].m_first = list_turb->m_first;
        v6 = v12;
        list_turb->m_first = (pulse_sum_constraint_solver::temp_user_rigid_body *)v8;
      }
      v11 = (pulse_sum_constraint_solver::user_rigid_body_restore_info *)phys_transient_allocator::allocate(
                                                                           &v6->m_solver_memory_allocator,
                                                                           12,
                                                                           4,
                                                                           0,
                                                                           SOLVER_MEMORY_ALLOCATOR_ERROR_MSG);
      v11->m_rbc_urb = v5;
      v11->m_original_urb = *v5;
      *v5 = (user_rigid_body *)v8;
      v11->m_next_link = list_urbri->m_first;
      list_urbri->m_first = v11;
    }
  }
}

/*
==============
rbint::setup_constraint
==============
*/
void rbint::setup_constraint(rigid_body *rb, pulse_sum_node *psn)
{
  if ( !rb
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_constraint_solver_inline.h",
         123,
         "rb",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  if ( rb->m_inv_mass <= 0.0000099999997
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_constraint_solver_inline.h",
         124,
         "rb->get_inv_mass() > 0.00001f",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  nuge::tensor_transform_principle(&rb->m_inv_inertia, &rb->m_mat, &psn->m_world_inv_inertia);
  rb->m_node = psn;
  psn->m_rb = rb;
  psn->m_inv_mass = rb->m_inv_mass;
}

/*
==============
pulse_sum_constraint_solver::solve_constraints
==============
*/
void __userpurge pulse_sum_constraint_solver::solve_constraints(pulse_sum_constraint_solver *this@<ecx>, int a2@<ebp>, rigid_body *const head)
{
  pulse_sum_constraint_solver *v3; // edi
  pulse_sum_node *i; // esi
  pulse_sum_normal *j; // esi
  double v6; // st7
  float *v7; // ecx
  double v8; // st7
  float delta_t; // ST0C_4
  pulse_sum_point *k; // esi
  phys_vec3 *v11; // eax
  double v12; // st7
  pulse_sum_angular *l; // esi
  pulse_sum_node *v14; // eax
  float *v15; // ecx
  float *v16; // eax
  double v17; // st7
  float *v18; // eax
  double v19; // st7
  double v20; // st7
  double v21; // st7
  pulse_sum_wheel *m; // esi
  pulse_sum_contact *n; // esi
  rigid_body_constraint_point *ii; // eax
  rigid_body_constraint_hinge *jj; // eax
  rigid_body_constraint_distance *kk; // eax
  rigid_body_constraint_ragdoll *ll; // eax
  rigid_body_constraint_wheel *mm; // eax
  rigid_body_constraint_angular_actuator *nn; // eax
  rigid_body_constraint_upright *i1; // eax
  rigid_body_constraint_custom_orientation *i2; // eax
  rigid_body_constraint_custom_path *i3; // eax
  rigid_body_constraint_contact *i4; // eax
  pulse_sum_normal *i5; // eax
  float *v35; // edx
  pulse_sum_point *i6; // eax
  float *v37; // ecx
  double v38; // st7
  pulse_sum_cache *v39; // edx
  pulse_sum_cache *v40; // ecx
  pulse_sum_angular *i7; // eax
  float *v42; // edx
  pulse_sum_wheel *i8; // eax
  float *v44; // ecx
  double v45; // st7
  pulse_sum_normal *v46; // ecx
  float *v47; // edx
  pulse_sum_normal *v48; // ecx
  float *v49; // edx
  pulse_sum_contact *i9; // esi
  pulse_sum_node *v51; // esi
  rigid_body *v52; // eax
  float v53; // ecx
  pulse_sum_node *i10; // edi
  rigid_body *v55; // eax
  float v56; // [esp+14h] [ebp-2Ch]
  float v57; // [esp+18h] [ebp-28h]
  float v58; // [esp+1Ch] [ebp-24h]
  double v59; // [esp+24h] [ebp-1Ch]
  float v60; // [esp+30h] [ebp-10h]
  int v61; // [esp+34h] [ebp-Ch]
  int v62; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  v61 = a2;
  v62 = retaddr;
  v3 = this;
  for ( i = this->m_list_pulse_sum_node.m_first; i; i = i->m_next_link )
  {
    rbint::euler_integrate_velocity(COERCE_FLOAT(&v61), i->m_rb, v3->m_si.m_delta_t);
    i->t_vel.x = PHYS_ZERO_VEC_97.x;
    i->t_vel.y = PHYS_ZERO_VEC_97.y;
    i->t_vel.z = PHYS_ZERO_VEC_97.z;
    i->a_vel.x = PHYS_ZERO_VEC_97.x;
    i->a_vel.y = PHYS_ZERO_VEC_97.y;
    i->a_vel.z = PHYS_ZERO_VEC_97.z;
  }
  for ( j = v3->m_list_pulse_sum_normal.m_first; j; j = j->m_next_link )
  {
    v60 = v3->m_si.m_delta_t;
    v59 = j->m_right_side;
    v6 = pulse_sum_normal::get_vel(j, (int)&v61);
    v7 = &j->m_pulse_sum_cache->m_pulse_sum;
    j->m_right_side = v59 - v6;
    v60 = *v7 * v60;
    v8 = v60;
    j->m_pulse_sum = v60;
    delta_t = v8;
    j->m_pulse_sum = pulse_sum_normal::clamp_pulse_sum(j, delta_t);
    pulse_sum_normal::apply(j, &j->m_pulse_sum);
  }
  for ( k = v3->m_list_pulse_sum_point.m_first; k; k = k->m_next_link )
  {
    v60 = v3->m_si.m_delta_t;
    v11 = pulse_sum_point::get_vel(k, (int)&v61, (phys_vec3 *)&v56);
    k->m_right_side.x = k->m_right_side.x - v11->x;
    k->m_right_side.y = k->m_right_side.y - v11->y;
    k->m_right_side.z = k->m_right_side.z - v11->z;
    v12 = v60;
    k->m_pulse_sum.x = k->m_pulse_sum_cache->m_pulse_sum * v60;
    k->m_pulse_sum.y = k->m_pulse_sum_cache[1].m_pulse_sum * v12;
    k->m_pulse_sum.z = v12 * k->m_pulse_sum_cache[2].m_pulse_sum;
    pulse_sum_point::apply(k, &k->m_pulse_sum);
  }
  for ( l = v3->m_list_pulse_sum_angular.m_first; l; l = l->m_next_link )
  {
    v14 = l->m_b2;
    *((float *)&v59 + 1) = v3->m_si.m_delta_t;
    if ( v14 )
      v15 = &v14->m_rb->m_a_vel.x;
    else
      v15 = &l->m_b2_ap.x;
    v16 = &l->m_b1->m_rb->m_last_position.x;
    v56 = v16[40] - *v15;
    v57 = v16[41] - v15[1];
    v17 = v16[42];
    v18 = &l->m_pulse_sum_cache->m_pulse_sum;
    v58 = v17 - v15[2];
    v19 = l->m_right_side;
    v60 = l->m_ud.y * v57 + l->m_ud.x * v56 + l->m_ud.z * v58;
    l->m_right_side = v19 - v60;
    *((float *)&v59 + 1) = *v18 * *((float *)&v59 + 1);
    v20 = *((float *)&v59 + 1);
    l->m_pulse_sum = *((float *)&v59 + 1);
    *((float *)&v59 + 1) = v20;
    if ( l->m_pulse_sum_max < (double)l->m_pulse_sum_min
      && _tlAssert(
           "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_angular_inline.h",
           40,
           "m_pulse_sum_min <= m_pulse_sum_max",
           (const char *)&pBlock) )
    {
      __debugbreak();
    }
    v21 = *((float *)&v59 + 1);
    if ( l->m_pulse_sum_min <= (double)*((float *)&v59 + 1) )
    {
      if ( l->m_pulse_sum_max < v21 )
        v21 = l->m_pulse_sum_max;
    }
    else
    {
      v21 = l->m_pulse_sum_min;
    }
    v60 = v21;
    l->m_pulse_sum = v60;
    pulse_sum_angular::apply(l, &l->m_pulse_sum);
  }
  for ( m = v3->m_list_pulse_sum_wheel.m_first; m; m = m->m_next_link )
    pulse_sum_wheel::SOLVER_solver_prolog(m, v3->m_si.m_delta_t);
  for ( n = v3->m_list_pulse_sum_contact.m_first; n; n = n->m_next_link )
    pulse_sum_contact::SOLVER_solver_prolog(n, (pulse_sum_contact_point *)&v61, v3->m_si.m_delta_t);
  pulse_sum_constraint_solver::solve_iterative(v3, v3->m_si.m_max_vel_iters, v3->m_si.m_max_vel_error_sq);
  for ( ii = head->m_partition_node.m_rbc_point_first; ii; ii = (rigid_body_constraint_point *)ii->m_next )
  {
    ii->m_ps_cache_list[0].m_pulse_sum = 0.0;
    ii->m_ps_cache_list[1].m_pulse_sum = 0.0;
    ii->m_ps_cache_list[2].m_pulse_sum = 0.0;
  }
  for ( jj = head->m_partition_node.m_rbc_hinge_first; jj; jj = (rigid_body_constraint_hinge *)jj->m_next )
  {
    jj->m_ps_cache[0].m_pulse_sum = 0.0;
    jj->m_ps_cache[1].m_pulse_sum = 0.0;
    jj->m_ps_cache[2].m_pulse_sum = 0.0;
    jj->m_ps_cache[3].m_pulse_sum = 0.0;
    jj->m_ps_cache[4].m_pulse_sum = 0.0;
    jj->m_ps_cache[5].m_pulse_sum = 0.0;
    jj->m_ps_cache[6].m_pulse_sum = 0.0;
    jj->m_ps_cache[7].m_pulse_sum = 0.0;
  }
  for ( kk = head->m_partition_node.m_rbc_dist_first; kk; kk = (rigid_body_constraint_distance *)kk->m_next )
  {
    kk->m_ps_cache_list[0].m_pulse_sum = 0.0;
    kk->m_ps_cache_list[1].m_pulse_sum = 0.0;
    kk->m_ps_cache_list[2].m_pulse_sum = 0.0;
  }
  for ( ll = head->m_partition_node.m_rbc_ragdoll_first; ll; ll = (rigid_body_constraint_ragdoll *)ll->m_next )
  {
    ll->m_ps_cache_list[0].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[1].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[2].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[3].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[4].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[5].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[6].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[7].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[8].m_pulse_sum = 0.0;
    ll->m_ps_cache_list[9].m_pulse_sum = 0.0;
  }
  for ( mm = head->m_partition_node.m_rbc_wheel_first; mm; mm = (rigid_body_constraint_wheel *)mm->m_next )
  {
    mm->m_ps_cache_list[0].m_pulse_sum = 0.0;
    mm->m_ps_cache_list[1].m_pulse_sum = 0.0;
    mm->m_ps_cache_list[2].m_pulse_sum = 0.0;
    mm->m_ps_cache_list[3].m_pulse_sum = 0.0;
  }
  for ( nn = head->m_partition_node.m_rbc_angular_actuator_first;
        nn;
        nn = (rigid_body_constraint_angular_actuator *)nn->m_next )
  {
    nn->m_ps_cache_list[0].m_pulse_sum = 0.0;
    nn->m_ps_cache_list[1].m_pulse_sum = 0.0;
    nn->m_ps_cache_list[2].m_pulse_sum = 0.0;
  }
  for ( i1 = head->m_partition_node.m_rbc_upright_first; i1; i1 = (rigid_body_constraint_upright *)i1->m_next )
    i1->m_ps_cache_list[0].m_pulse_sum = 0.0;
  for ( i2 = head->m_partition_node.m_rbc_custom_orientation_first;
        i2;
        i2 = (rigid_body_constraint_custom_orientation *)i2->m_next )
  {
    i2->m_ps_cache_list[0].m_pulse_sum = 0.0;
    i2->m_ps_cache_list[1].m_pulse_sum = 0.0;
    i2->m_ps_cache_list[2].m_pulse_sum = 0.0;
    i2->m_ps_cache_list[3].m_pulse_sum = 0.0;
    i2->m_ps_cache_list[4].m_pulse_sum = 0.0;
  }
  for ( i3 = head->m_partition_node.m_rbc_custom_path_first; i3; i3 = (rigid_body_constraint_custom_path *)i3->m_next )
  {
    i3->m_list_psc[0].m_pulse_sum = 0.0;
    i3->m_list_psc[1].m_pulse_sum = 0.0;
    i3->m_list_psc[2].m_pulse_sum = 0.0;
    i3->m_list_psc[3].m_pulse_sum = 0.0;
  }
  for ( i4 = head->m_partition_node.m_rbc_contact_first; i4; i4 = (rigid_body_constraint_contact *)i4->m_next )
    ;
  for ( i5 = v3->m_list_pulse_sum_normal.m_first; i5; i5 = i5->m_next_link )
  {
    v35 = &i5->m_pulse_sum_cache->m_pulse_sum;
    *((float *)&v59 + 1) = i5->m_pulse_sum / v3->m_si.m_delta_t;
    *v35 = *((float *)&v59 + 1);
    i5->m_right_side = i5->m_big_dirt + i5->m_right_side;
  }
  for ( i6 = v3->m_list_pulse_sum_point.m_first; i6; i6 = i6->m_next_link )
  {
    v37 = &i6->m_pulse_sum_cache->m_pulse_sum;
    *((float *)&v59 + 1) = v3->m_si.m_delta_t;
    v38 = *((float *)&v59 + 1);
    *((float *)&v59 + 1) = i6->m_pulse_sum.x / *((float *)&v59 + 1);
    *v37 = *((float *)&v59 + 1);
    v39 = i6->m_pulse_sum_cache;
    *((float *)&v59 + 1) = i6->m_pulse_sum.y / v38;
    LODWORD(v39[1].m_pulse_sum) = *(pulse_sum_cache *)((char *)&v59 + 4);
    v40 = i6->m_pulse_sum_cache;
    *((float *)&v59 + 1) = i6->m_pulse_sum.z / v38;
    LODWORD(v40[2].m_pulse_sum) = *(pulse_sum_cache *)((char *)&v59 + 4);
    i6->m_right_side.x = i6->m_big_dirt.x + i6->m_right_side.x;
    i6->m_right_side.y = i6->m_big_dirt.y + i6->m_right_side.y;
    i6->m_right_side.z = i6->m_big_dirt.z + i6->m_right_side.z;
  }
  for ( i7 = v3->m_list_pulse_sum_angular.m_first; i7; i7 = i7->m_next_link )
  {
    v42 = &i7->m_pulse_sum_cache->m_pulse_sum;
    *((float *)&v59 + 1) = i7->m_pulse_sum / v3->m_si.m_delta_t;
    *v42 = *((float *)&v59 + 1);
    i7->m_right_side = i7->m_big_dirt + i7->m_right_side;
  }
  for ( i8 = v3->m_list_pulse_sum_wheel.m_first; i8; i8 = i8->m_next_link )
  {
    v44 = &i8->m_suspension.m_pulse_sum_cache->m_pulse_sum;
    *((float *)&v59 + 1) = v3->m_si.m_delta_t;
    v45 = *((float *)&v59 + 1);
    *((float *)&v59 + 1) = i8->m_suspension.m_pulse_sum / *((float *)&v59 + 1);
    *v44 = *((float *)&v59 + 1);
    i8->m_suspension.m_right_side = i8->m_suspension.m_big_dirt + i8->m_suspension.m_right_side;
    v46 = i8->m_side;
    if ( v46 )
    {
      v47 = &v46->m_pulse_sum_cache->m_pulse_sum;
      *((float *)&v59 + 1) = v46->m_pulse_sum / v45;
      *v47 = *((float *)&v59 + 1);
      v46->m_right_side = v46->m_big_dirt + v46->m_right_side;
      v48 = i8->m_fwd;
      if ( v48 )
      {
        v49 = &v48->m_pulse_sum_cache->m_pulse_sum;
        *((float *)&v59 + 1) = v48->m_pulse_sum / v45;
        *v49 = *((float *)&v59 + 1);
        v48->m_right_side = v48->m_big_dirt + v48->m_right_side;
      }
    }
  }
  for ( i9 = v3->m_list_pulse_sum_contact.m_first; i9; i9 = i9->m_next_link )
    pulse_sum_contact::SOLVER_solver_intermediate(i9, v3->m_si.m_delta_t);
  pulse_sum_constraint_solver::solve_iterative(v3, v3->m_si.m_max_vel_pos_iters, v3->m_si.m_max_vel_pos_error_sq);
  v51 = v3->m_list_pulse_sum_node.m_first;
  LODWORD(v60) = 1;
  if ( v51 )
  {
    do
    {
      rbint::add_vel(v51->m_rb, &v51->t_vel, &v51->a_vel);
      rbint::euler_integrate_pos((int)&v61, v51->m_rb, v3->m_si.m_delta_t);
      rbint::update_stability(v51->m_rb, v3->m_si.m_delta_t);
      if ( v60 == 0.0 || (v52 = v51->m_rb, !(v52->m_flags & 4)) || v52->m_flags & 0x40 )
        v53 = 0.0;
      else
        LODWORD(v53) = 1;
      v51 = v51->m_next_link;
      v60 = v53;
    }
    while ( v51 );
  }
  else
  {
    v53 = v60;
  }
  for ( i10 = v3->m_list_pulse_sum_node.m_first; i10; i10 = i10->m_next_link )
  {
    v55 = i10->m_rb;
    if ( v53 == 0.0 )
      v55->m_flags &= 0xFFFFFFF7;
    else
      v55->m_flags |= 8u;
  }
}

/*
==============
pulse_sum_constraint_solver::execute_constraint_solver
==============
*/
void __userpurge pulse_sum_constraint_solver::execute_constraint_solver(pulse_sum_constraint_solver *this@<ecx>, pulse_sum_constraint_solver::temp_user_rigid_body *a2@<ebp>, rigid_body *const head)
{
  rigid_body *v3; // esi
  pulse_sum_constraint_solver *v4; // edi
  rigid_body *v5; // ecx
  double i; // st7
  double v7; // st6
  rigid_body_constraint_point *j; // esi
  rigid_body_constraint_hinge *k; // esi
  rigid_body_constraint_distance *l; // esi
  rigid_body_constraint_ragdoll *m; // esi
  rigid_body_constraint_wheel *ii; // esi
  rigid_body_constraint_angular_actuator *jj; // esi
  rigid_body_constraint_upright *kk; // esi
  rigid_body_constraint_custom_orientation *ll; // esi
  rigid_body_constraint_custom_path *mm; // esi
  rigid_body_constraint_contact *nn; // esi
  int v18; // ecx
  phys_transient_allocator::block_header *v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  phys_link_list<pulse_sum_wheel> *v25; // eax
  phys_link_list<pulse_sum_contact> *v26; // eax
  rigid_body *v27; // eax
  rigid_body *v28; // eax
  rigid_body *v29; // eax
  pulse_sum_node **v30; // edx
  rigid_body_constraint_point *i1; // esi
  rigid_body_constraint_hinge *i2; // esi
  rigid_body_constraint_distance *i3; // esi
  rigid_body_constraint_ragdoll *i4; // esi
  rigid_body_constraint_wheel *i5; // esi
  rigid_body_constraint_angular_actuator *i6; // esi
  rigid_body_constraint_upright *i7; // esi
  rigid_body_constraint_custom_orientation *i8; // esi
  rigid_body_constraint_custom_path *i9; // esi
  rigid_body_constraint_contact *i10; // esi
  float i11; // esi
  double v42; // st7
  rigid_body *v43; // ecx
  rigid_body_constraint_point *i12; // eax
  rigid_body_constraint_hinge *i13; // eax
  rigid_body_constraint_distance *v46; // esi
  rigid_body_constraint_ragdoll *i14; // eax
  rigid_body_constraint_wheel *i15; // eax
  rigid_body_constraint_angular_actuator *i16; // esi
  rigid_body_constraint_upright *i17; // eax
  rigid_body_constraint_custom_orientation *i18; // eax
  rigid_body_constraint_custom_path *i19; // eax
  rigid_body_constraint_contact *i20; // eax
  int v54; // eax
  float i21; // eax
  rigid_body_constraint_point *i22; // esi
  rigid_body_constraint_hinge *i23; // eax
  rigid_body_constraint_distance *i24; // eax
  rigid_body_constraint_ragdoll *i25; // eax
  rigid_body_constraint_wheel *i26; // esi
  rigid_body_constraint_angular_actuator *i27; // eax
  rigid_body_constraint_upright *i28; // esi
  rigid_body_constraint_custom_orientation *i29; // eax
  rigid_body_constraint_custom_path *i30; // eax
  rigid_body_constraint_contact *i31; // esi
  rigid_body *v66; // esi
  int v67; // [esp+18h] [ebp-9Ch]
  int v68; // [esp+58h] [ebp-5Ch]
  char *v69; // [esp+5Ch] [ebp-58h]
  int v70; // [esp+60h] [ebp-54h]
  phys_transient_allocator::allocator_state saved_allocator_state; // [esp+64h] [ebp-50h]
  int v72; // [esp+80h] [ebp-34h]
  const char *v73; // [esp+84h] [ebp-30h]
  float v74; // [esp+88h] [ebp-2Ch]
  int step; // [esp+8Ch] [ebp-28h]
  phys_transient_allocator *v76; // [esp+90h] [ebp-24h]
  rigid_body *n; // [esp+94h] [ebp-20h]
  int sub_steps; // [esp+98h] [ebp-1Ch]
  float theta_factor; // [esp+9Ch] [ebp-18h]
  float delta_t; // [esp+A0h] [ebp-14h]
  float max_delta_t; // [esp+A4h] [ebp-10h]
  phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> turb_search_tree; // [esp+A8h] [ebp-Ch]
  phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> list_urbri; // [esp+ACh] [ebp-8h]
  pulse_sum_constraint_solver::user_rigid_body_restore_info *retaddr; // [esp+B4h] [ebp+0h]

  turb_search_tree.m_tree_root = a2;
  list_urbri.m_first = retaddr;
  v3 = head;
  v4 = this;
  if ( *(float *)&head == 0.0
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_constraint_solver_inline.h",
         153,
         "head",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  v5 = head->m_partition_node.m_next_node;
  sub_steps = SLODWORD(head->m_max_delta_t);
  for ( i = *(float *)&sub_steps; v5; v5 = v5->m_partition_node.m_next_node )
  {
    if ( v5->m_max_delta_t < i )
    {
      sub_steps = SLODWORD(v5->m_max_delta_t);
      i = *(float *)&sub_steps;
    }
  }
  v7 = v4->m_outside_delta_t;
  step = (signed int)(v7 / i);
  if ( (double)step * i < v7 )
    ++step;
  v74 = (double)step;
  if ( v4->m_outside_delta_t > i * v74
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_constraint_solver_inline.h",
         162,
         "m_outside_delta_t <= max_delta_t * sub_steps",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  sub_steps = SLODWORD(v4->m_outside_delta_t);
  theta_factor = 0.0;
  max_delta_t = 0.0;
  delta_t = 0.0;
  if ( v4->m_solver_memory_allocator.m_cur
    && _tlAssert(
         "c:\\t6\\code\\tl\\physics\\include\\constraint_solver\\pulse_sum_constraint_solver_inline.h",
         171,
         "m_solver_memory_allocator.is_empty()",
         (const char *)&pBlock) )
  {
    __debugbreak();
  }
  do
  {
    rbint::solver_prolog(v3, *(const float *)&sub_steps);
    rigid_body::swap_last_position(v3);
    v3 = v3->m_partition_node.m_next_node;
  }
  while ( v3 );
  for ( j = head->m_partition_node.m_rbc_point_first; j; j = (rigid_body_constraint_point *)j->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&j->b1);
  for ( k = head->m_partition_node.m_rbc_hinge_first; k; k = (rigid_body_constraint_hinge *)k->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&k->b1);
  for ( l = head->m_partition_node.m_rbc_dist_first; l; l = (rigid_body_constraint_distance *)l->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&l->b1);
  for ( m = head->m_partition_node.m_rbc_ragdoll_first; m; m = (rigid_body_constraint_ragdoll *)m->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&m->b1);
  for ( ii = head->m_partition_node.m_rbc_wheel_first; ii; ii = (rigid_body_constraint_wheel *)ii->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&ii->b1);
  for ( jj = head->m_partition_node.m_rbc_angular_actuator_first;
        jj;
        jj = (rigid_body_constraint_angular_actuator *)jj->m_next )
  {
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&jj->b1);
  }
  for ( kk = head->m_partition_node.m_rbc_upright_first; kk; kk = (rigid_body_constraint_upright *)kk->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&kk->b1);
  for ( ll = head->m_partition_node.m_rbc_custom_orientation_first;
        ll;
        ll = (rigid_body_constraint_custom_orientation *)ll->m_next )
  {
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&ll->b1);
  }
  for ( mm = head->m_partition_node.m_rbc_custom_path_first; mm; mm = (rigid_body_constraint_custom_path *)mm->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&mm->b1);
  for ( nn = head->m_partition_node.m_rbc_contact_first; nn; nn = (rigid_body_constraint_contact *)nn->m_next )
    pulse_sum_constraint_solver::add_urb(
      v4,
      (phys_inplace_avl_tree<user_rigid_body *,pulse_sum_constraint_solver::temp_user_rigid_body,pulse_sum_constraint_solver::temp_user_rigid_body::avl_tree_accessor> *)&theta_factor,
      (phys_simple_link_list<pulse_sum_constraint_solver::temp_user_rigid_body> *)&max_delta_t,
      (phys_simple_link_list<pulse_sum_constraint_solver::user_rigid_body_restore_info> *)&delta_t,
      (rigid_body_constraint *)&nn->b1);
  v18 = (int)v4->m_solver_memory_allocator.m_first_block;
  v69 = v4->m_solver_memory_allocator.m_cur;
  v19 = (phys_transient_allocator::block_header *)v4->m_solver_memory_allocator.m_total_memory_allocated;
  v76 = &v4->m_solver_memory_allocator;
  v68 = v18;
  v20 = (int)v4->m_solver_memory_allocator.m_end;
  v21 = v4->m_psys_max_vel_iters;
  saved_allocator_state.m_first_block = v19;
  v70 = v20;
  v22 = step;
  v23 = v21 / step;
  if ( v23 <= 1 )
    v23 = 1;
  v4->m_si.m_max_vel_iters = v23;
  v24 = v4->m_psys_max_vel_pos_iters / v22;
  if ( v24 <= 1 )
    v24 = 1;
  v4->m_si.m_max_vel_pos_iters = v24;
  v4->m_si.m_max_vel_error_sq = 0.1156;
  v72 = 0;
  v4->m_si.m_max_vel_pos_error_sq = 2.8900001;
  v4->m_si.m_delta_t = *(float *)&sub_steps / v74;
  if ( v22 > 0 )
  {
    do
    {
      phys_transient_allocator::reset_to_state(v76, (phys_transient_allocator::allocator_state *)&v68);
      v4->m_list_pulse_sum_node.m_first = NULL;
      v4->m_list_pulse_sum_node.m_alloc_count = 0;
      v4->m_list_pulse_sum_node.m_last_next_ptr = &v4->m_list_pulse_sum_node.m_first;
      v4->m_list_pulse_sum_normal.m_first = NULL;
      v4->m_list_pulse_sum_normal.m_alloc_count = 0;
      v4->m_list_pulse_sum_normal.m_last_next_ptr = &v4->m_list_pulse_sum_normal.m_first;
      v4->m_list_pulse_sum_point.m_first = NULL;
      v4->m_list_pulse_sum_point.m_alloc_count = 0;
      v4->m_list_pulse_sum_point.m_last_next_ptr = &v4->m_list_pulse_sum_point.m_first;
      v4->m_list_pulse_sum_angular.m_first = NULL;
      v4->m_list_pulse_sum_angular.m_alloc_count = 0;
      v4->m_list_pulse_sum_angular.m_last_next_ptr = &v4->m_list_pulse_sum_angular.m_first;
      v25 = &v4->m_list_pulse_sum_wheel;
      v25->m_first = NULL;
      v25->m_alloc_count = 0;
      v25->m_last_next_ptr = &v25->m_first;
      v26 = &v4->m_list_pulse_sum_contact;
      v26->m_first = NULL;
      v26->m_alloc_count = 0;
      v26->m_last_next_ptr = &v26->m_first;
      v74 = *(float *)&head;
      do
      {
        v73 = SOLVER_MEMORY_ALLOCATOR_ERROR_MSG;
        transient_allocator_update_largest_size(128);
        v27 = (rigid_body *)((_DWORD)(v76->m_cur + 15) & 0xFFFFFFF0);
        if ( (char *)&v27->m_gravity_acc_vec > v76->m_end
          || (v76->m_cur = (char *)&v27->m_gravity_acc_vec, (n = v27) == NULL) )
        {
          phys_transient_allocator::resize(v76);
          v28 = (rigid_body *)((_DWORD)(v76->m_cur + 15) & 0xFFFFFFF0);
          if ( (char *)&v28->m_gravity_acc_vec <= v76->m_end )
          {
            v76->m_cur = (char *)&v28->m_gravity_acc_vec;
            n = v28;
            if ( v28 )
              goto LABEL_55;
          }
          else
          {
            n = NULL;
          }
          if ( _tlAssert(
                 "c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h",
                 79,
                 "ptr",
                 "transient allocation too large, increase block_size.") )
          {
            __debugbreak();
          }
          if ( _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_transient_allocator.h", 81, "ptr || no_error", v73) )
            __debugbreak();
          if ( !n )
            n = NULL;
        }
LABEL_55:
        if ( !v4->m_list_pulse_sum_node.m_last_next_ptr
          && _tlAssert("c:\\t6\\code\\tl\\physics\\include\\phys_mem.h", 230, "m_last_next_ptr", (const char *)&pBlock) )
        {
          __debugbreak();
        }
        v29 = n;
        n->m_last_position.x = 0.0;
        v30 = v4->m_list_pulse_sum_node.m_last_next_ptr;
        ++v4->m_list_pulse_sum_node.m_alloc_count;
        *v30 = (pulse_sum_node *)v29;
        delta_t = *(float *)&v29;
        v4->m_list_pulse_sum_node.m_last_next_ptr = (pulse_sum_node **)v29;
        rbint::setup_constraint((rigid_body *)LODWORD(v74), (pulse_sum_node *)LODWORD(delta_t));
        v74 = *(float *)(LODWORD(v74) + 344);
      }
      while ( v74 != 0.0 );
      for ( i1 = head->m_partition_node.m_rbc_point_first; i1; i1 = (rigid_body_constraint_point *)i1->m_next )
        rigid_body_constraint_point::setup_constraint(i1, (int)&turb_search_tree, v4, v4->m_si.m_delta_t);
      for ( i2 = head->m_partition_node.m_rbc_hinge_first; i2; i2 = (rigid_body_constraint_hinge *)i2->m_next )
        rigid_body_constraint_hinge::setup_constraint(i2, (int)&turb_search_tree, v4, v4->m_si.m_delta_t);
      for ( i3 = head->m_partition_node.m_rbc_dist_first; i3; i3 = (rigid_body_constraint_distance *)i3->m_next )
        rigid_body_constraint_distance::setup_constraint(i3, (int)&turb_search_tree, v4, v4->m_si.m_delta_t);
      for ( i4 = head->m_partition_node.m_rbc_ragdoll_first; i4; i4 = (rigid_body_constraint_ragdoll *)i4->m_next )
        rigid_body_constraint_ragdoll::setup_constraint(i4, (int)&turb_search_tree, v4, v4->m_si.m_delta_t);
      for ( i5 = head->m_partition_node.m_rbc_wheel_first; i5; i5 = (rigid_body_constraint_wheel *)i5->m_next )
        rigid_body_constraint_wheel::setup_constraint(i5, (int)&turb_search_tree, v4, v4->m_si.m_delta_t);
      for ( i6 = head->m_partition_node.m_rbc_angular_actuator_first;
            i6;
            i6 = (rigid_body_constraint_angular_actuator *)i6->m_next )
      {
        rigid_body_constraint_angular_actuator::setup_constraint(
          i6,
          (phys_mat44 *)&turb_search_tree,
          v4,
          v4->m_si.m_delta_t);
      }
      for ( i7 = head->m_partition_node.m_rbc_upright_first; i7; i7 = (rigid_body_constraint_upright *)i7->m_next )
        rigid_body_constraint_upright::setup_constraint(i7, (int)&turb_search_tree, v4, v4->m_si.m_delta_t);
      for ( i8 = head->m_partition_node.m_rbc_custom_orientation_first;
            i8;
            i8 = (rigid_body_constraint_custom_orientation *)i8->m_next )
      {
        rigid_body_constraint_custom_orientation::setup_constraint(i8, v4, v4->m_si.m_delta_t);
      }
      for ( i9 = head->m_partition_node.m_rbc_custom_path_first; i9; i9 = (rigid_body_constraint_custom_path *)i9->m_next )
        rigid_body_constraint_custom_path::setup_constraint(i9, v4, v4->m_si.m_delta_t);
      for ( i10 = head->m_partition_node.m_rbc_contact_first; i10; i10 = (rigid_body_constraint_contact *)i10->m_next )
        rigid_body_constraint_contact::setup_constraint(i10, v4, v4->m_si.m_delta_t);
      pulse_sum_constraint_solver::solve_constraints(v4, (int)&turb_search_tree, head);
      for ( i11 = max_delta_t; i11 != 0.0; i11 = *(float *)(LODWORD(i11) + 432) )
      {
        v73 = (const char *)LODWORD(v4->m_si.m_delta_t);
        v42 = *(float *)&v73;
        *(float *)&saved_allocator_state.m_cur = *(float *)(LODWORD(i11) + 144) * *(float *)&v73;
        *(float *)&saved_allocator_state.m_end = *(float *)(LODWORD(i11) + 148) * *(float *)&v73;
        *(float *)&saved_allocator_state.m_total_memory_allocated = *(float *)(LODWORD(i11) + 152) * *(float *)&v73;
        *(float *)(LODWORD(i11) + 96) = *(float *)(LODWORD(i11) + 96) + *(float *)&saved_allocator_state.m_cur;
        *(float *)(LODWORD(i11) + 100) = *(float *)(LODWORD(i11) + 100) + *(float *)&saved_allocator_state.m_end;
        *(float *)(LODWORD(i11) + 104) = *(float *)(LODWORD(i11) + 104)
                                       + *(float *)&saved_allocator_state.m_total_memory_allocated;
        theta_factor = v42;
        make_rotate((phys_mat44 *)&v67, (phys_vec3 *)(LODWORD(i11) + 160), theta_factor, 1000.0);
        phys_multiply_mat(
          (int)&turb_search_tree,
          (phys_mat44 *)(LODWORD(i11) + 48),
          (phys_mat44 *)&v67,
          (phys_mat44 *)(LODWORD(i11) + 48));
      }
      v43 = head;
      for ( i12 = head->m_partition_node.m_rbc_point_first; i12; i12 = (rigid_body_constraint_point *)i12->m_next )
        ;
      for ( i13 = head->m_partition_node.m_rbc_hinge_first; i13; i13 = (rigid_body_constraint_hinge *)i13->m_next )
        ;
      v46 = head->m_partition_node.m_rbc_dist_first;
      if ( v46 )
      {
        do
        {
          rigid_body_constraint_distance::inner_update(v46, v4->m_si.m_delta_t);
          v46 = (rigid_body_constraint_distance *)v46->m_next;
        }
        while ( v46 );
        v43 = head;
      }
      for ( i14 = v43->m_partition_node.m_rbc_ragdoll_first; i14; i14 = (rigid_body_constraint_ragdoll *)i14->m_next )
        ;
      for ( i15 = v43->m_partition_node.m_rbc_wheel_first; i15; i15 = (rigid_body_constraint_wheel *)i15->m_next )
        ;
      for ( i16 = v43->m_partition_node.m_rbc_angular_actuator_first;
            i16;
            i16 = (rigid_body_constraint_angular_actuator *)i16->m_next )
      {
        rigid_body_constraint_angular_actuator::inner_update(i16, COERCE_FLOAT(&turb_search_tree), v4->m_si.m_delta_t);
      }
      for ( i17 = head->m_partition_node.m_rbc_upright_first; i17; i17 = (rigid_body_constraint_upright *)i17->m_next )
        ;
      for ( i18 = head->m_partition_node.m_rbc_custom_orientation_first;
            i18;
            i18 = (rigid_body_constraint_custom_orientation *)i18->m_next )
      {
        ;
      }
      for ( i19 = head->m_partition_node.m_rbc_custom_path_first;
            i19;
            i19 = (rigid_body_constraint_custom_path *)i19->m_next )
      {
        ;
      }
      for ( i20 = head->m_partition_node.m_rbc_contact_first; i20; i20 = (rigid_body_constraint_contact *)i20->m_next )
        ;
      v54 = v4->m_solver_memory_allocator.m_total_memory_allocated;
      if ( v4->m_memory_high_water > v54 )
        v54 = v4->m_memory_high_water;
      v4->m_memory_high_water = v54;
      ++v72;
    }
    while ( v72 < step );
  }
  for ( i21 = delta_t; i21 != 0.0; i21 = *(float *)LODWORD(i21) )
    **(_DWORD **)(LODWORD(i21) + 4) = *(_DWORD *)(LODWORD(i21) + 8);
  for ( i22 = head->m_partition_node.m_rbc_point_first; i22; i22 = (rigid_body_constraint_point *)i22->m_next )
    rigid_body_constraint_point::epilog_vel_constraint(i22, *(const float *)&sub_steps);
  for ( i23 = head->m_partition_node.m_rbc_hinge_first; i23; i23 = (rigid_body_constraint_hinge *)i23->m_next )
    ;
  for ( i24 = head->m_partition_node.m_rbc_dist_first; i24; i24 = (rigid_body_constraint_distance *)i24->m_next )
    ;
  for ( i25 = head->m_partition_node.m_rbc_ragdoll_first; i25; i25 = (rigid_body_constraint_ragdoll *)i25->m_next )
    ;
  for ( i26 = head->m_partition_node.m_rbc_wheel_first; i26; i26 = (rigid_body_constraint_wheel *)i26->m_next )
    rigid_body_constraint_wheel::epilog_vel_constraint(i26, (int)&turb_search_tree, *(const float *)&sub_steps);
  for ( i27 = head->m_partition_node.m_rbc_angular_actuator_first;
        i27;
        i27 = (rigid_body_constraint_angular_actuator *)i27->m_next )
  {
    ;
  }
  for ( i28 = head->m_partition_node.m_rbc_upright_first; i28; i28 = (rigid_body_constraint_upright *)i28->m_next )
    rigid_body_constraint_upright::epilog_vel_constraint(i28, *(const float *)&sub_steps);
  for ( i29 = head->m_partition_node.m_rbc_custom_orientation_first;
        i29;
        i29 = (rigid_body_constraint_custom_orientation *)i29->m_next )
  {
    ;
  }
  for ( i30 = head->m_partition_node.m_rbc_custom_path_first; i30; i30 = (rigid_body_constraint_custom_path *)i30->m_next )
    ;
  for ( i31 = head->m_partition_node.m_rbc_contact_first; i31; i31 = (rigid_body_constraint_contact *)i31->m_next )
  {
    rigid_body_constraint_contact::update_smallest_lambda(i31);
    i31->m_list_contact_point_info_buffer_2.m_first = i31->m_list_contact_point_info_buffer_1.m_first;
    i31->m_list_contact_point_info_buffer_1.m_first = NULL;
  }
  v66 = head;
  do
  {
    v66->m_force_sum.x = PHYS_ZERO_VEC_97.x;
    v66->m_force_sum.y = PHYS_ZERO_VEC_97.y;
    v66->m_force_sum.z = PHYS_ZERO_VEC_97.z;
    v66->m_torque_sum.x = PHYS_ZERO_VEC_97.x;
    v66->m_torque_sum.y = PHYS_ZERO_VEC_97.y;
    v66->m_torque_sum.z = PHYS_ZERO_VEC_97.z;
    rigid_body::update_last_position(v66);
    v66 = v66->m_partition_node.m_next_node;
  }
  while ( v66 );
  phys_transient_allocator::reset(v76);
}

