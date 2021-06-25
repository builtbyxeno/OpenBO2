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
phys_sys::get_rbc_point_alloc_count
==============
*/
int phys_sys::get_rbc_point_alloc_count()
{
  return g_physics_system->m_list_rbc_point.m_list_count;
}

/*
==============
phys_sys::get_rbc_hinge_alloc_count
==============
*/
int phys_sys::get_rbc_hinge_alloc_count()
{
  return g_physics_system->m_list_rbc_hinge.m_list_count;
}

/*
==============
phys_sys::get_rbc_dist_alloc_count
==============
*/
int phys_sys::get_rbc_dist_alloc_count()
{
  return g_physics_system->m_list_rbc_dist.m_list_count;
}

/*
==============
phys_sys::get_rbc_ragdoll_alloc_count
==============
*/
int phys_sys::get_rbc_ragdoll_alloc_count()
{
  return g_physics_system->m_list_rbc_ragdoll.m_list_count;
}

/*
==============
phys_sys::get_rbc_wheel_alloc_count
==============
*/
int phys_sys::get_rbc_wheel_alloc_count()
{
  return g_physics_system->m_list_rbc_wheel.m_list_count;
}

/*
==============
phys_sys::get_rbc_angular_actuator_alloc_count
==============
*/
int phys_sys::get_rbc_angular_actuator_alloc_count()
{
  return g_physics_system->m_list_rbc_angular_actuator.m_list_count;
}

/*
==============
phys_sys::get_rbc_upright_alloc_count
==============
*/
int phys_sys::get_rbc_upright_alloc_count()
{
  return g_physics_system->m_list_rbc_upright.m_list_count;
}

/*
==============
phys_sys::get_rbc_custom_orientation_alloc_count
==============
*/
int phys_sys::get_rbc_custom_orientation_alloc_count()
{
  return g_physics_system->m_list_rbc_custom_orientation.m_list_count;
}

/*
==============
phys_sys::get_rbc_custom_path_alloc_count
==============
*/
int phys_sys::get_rbc_custom_path_alloc_count()
{
  return g_physics_system->m_list_rbc_custom_path.m_list_count;
}

/*
==============
phys_sys::get_rbc_contact_alloc_count
==============
*/
int phys_sys::get_rbc_contact_alloc_count()
{
  return g_physics_system->m_list_rbc_contact.m_list_count;
}

/*
==============
phys_sys::create_rbc_point
==============
*/
rigid_body_constraint_point *phys_sys::create_rbc_point(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_point> *v3; // esi
  rigid_body_constraint_point *result; // eax

  v3 = &g_physics_system->m_list_rbc_point;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_point>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_point, INCREASE phys_mem_info::m_num_rbc_point.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_custom_orientation
==============
*/
rigid_body_constraint_custom_orientation *phys_sys::create_rbc_custom_orientation(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_custom_orientation> *v3; // esi
  rigid_body_constraint_custom_orientation *result; // eax

  v3 = &g_physics_system->m_list_rbc_custom_orientation;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_custom_orientation>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_custom_orientation, INCREASE phys_mem_info::m_num_rbc_custom_orientation.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_contact
==============
*/
rigid_body_constraint_contact *phys_sys::create_rbc_contact(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  return create(
           &g_physics_system->m_list_rbc_contact,
           NULL,
           b1,
           b2,
           no_error,
           "OUT_OF_MEMORY, rbc_contact, INCREASE phys_mem_info::m_num_rbc_contact.");
}

/*
==============
phys_sys::destroy_all_rbc_point
==============
*/
void phys_sys::destroy_all_rbc_point()
{
  phys_free_list<rigid_body_constraint_point>::remove_all(&g_physics_system->m_list_rbc_point);
}

/*
==============
phys_sys::destroy_all_rbc_hinge
==============
*/
void phys_sys::destroy_all_rbc_hinge()
{
  phys_free_list<rigid_body_constraint_wheel>::remove_all((phys_free_list<rigid_body_constraint_wheel> *)&g_physics_system->m_list_rbc_hinge);
}

/*
==============
phys_sys::destroy_all_rbc_dist
==============
*/
void phys_sys::destroy_all_rbc_dist()
{
  phys_free_list<rigid_body_constraint_distance>::remove_all((phys_free_list<broad_phase_group> *)&g_physics_system->m_list_rbc_dist);
}

/*
==============
phys_sys::destroy_all_rbc_ragdoll
==============
*/
void phys_sys::destroy_all_rbc_ragdoll()
{
  phys_free_list<rigid_body_constraint_ragdoll>::remove_all(&g_physics_system->m_list_rbc_ragdoll);
}

/*
==============
phys_sys::destroy_all_rbc_wheel
==============
*/
void phys_sys::destroy_all_rbc_wheel()
{
  phys_free_list<rigid_body_constraint_wheel>::remove_all(&g_physics_system->m_list_rbc_wheel);
}

/*
==============
phys_sys::destroy_all_rbc_angular_actuator
==============
*/
void phys_sys::destroy_all_rbc_angular_actuator()
{
  phys_free_list<rigid_body_constraint_angular_actuator>::remove_all(&g_physics_system->m_list_rbc_angular_actuator);
}

/*
==============
phys_sys::destroy_all_rbc_upright
==============
*/
void phys_sys::destroy_all_rbc_upright()
{
  phys_free_list<rigid_body_constraint_upright>::remove_all(&g_physics_system->m_list_rbc_upright);
}

/*
==============
phys_sys::destroy_all_rbc_custom_orientation
==============
*/
void phys_sys::destroy_all_rbc_custom_orientation()
{
  phys_free_list<rigid_body_constraint_custom_orientation>::remove_all(&g_physics_system->m_list_rbc_custom_orientation);
}

/*
==============
phys_sys::destroy_all_rbc_custom_path
==============
*/
void phys_sys::destroy_all_rbc_custom_path()
{
  phys_free_list<rigid_body_constraint_custom_path>::remove_all(&g_physics_system->m_list_rbc_custom_path);
}

/*
==============
phys_sys::create_rbc_hinge
==============
*/
rigid_body_constraint_hinge *phys_sys::create_rbc_hinge(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_hinge> *v3; // esi
  rigid_body_constraint_hinge *result; // eax

  v3 = &g_physics_system->m_list_rbc_hinge;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_hinge>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_hinge, INCREASE phys_mem_info::m_num_rbc_hinge.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_dist
==============
*/
rigid_body_constraint_distance *phys_sys::create_rbc_dist(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_distance> *v3; // esi
  rigid_body_constraint_distance *result; // eax

  v3 = &g_physics_system->m_list_rbc_dist;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_distance>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_dist, INCREASE phys_mem_info::m_num_rbc_dist.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_ragdoll
==============
*/
rigid_body_constraint_ragdoll *phys_sys::create_rbc_ragdoll(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_ragdoll> *v3; // esi
  rigid_body_constraint_ragdoll *result; // eax

  v3 = &g_physics_system->m_list_rbc_ragdoll;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_ragdoll>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_ragdoll, INCREASE phys_mem_info::m_num_rbc_ragdoll.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_wheel
==============
*/
rigid_body_constraint_wheel *phys_sys::create_rbc_wheel(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_wheel> *v3; // esi
  rigid_body_constraint_wheel *result; // eax

  v3 = &g_physics_system->m_list_rbc_wheel;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_wheel>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_wheel, INCREASE phys_mem_info::m_num_rbc_wheel.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_angular_actuator
==============
*/
rigid_body_constraint_angular_actuator *phys_sys::create_rbc_angular_actuator(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_angular_actuator> *v3; // esi
  rigid_body_constraint_angular_actuator *result; // eax

  v3 = &g_physics_system->m_list_rbc_angular_actuator;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_angular_actuator>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_angular_actuator, INCREASE phys_mem_info::m_num_rbc_angular_actuator.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_upright
==============
*/
rigid_body_constraint_upright *phys_sys::create_rbc_upright(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_upright> *v3; // esi
  rigid_body_constraint_upright *result; // eax

  v3 = &g_physics_system->m_list_rbc_upright;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_upright>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_upright, INCREASE phys_mem_info::m_num_rbc_upright.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::create_rbc_custom_path
==============
*/
rigid_body_constraint_custom_path *phys_sys::create_rbc_custom_path(rigid_body *const b1, rigid_body *const b2, const int no_error)
{
  phys_free_list<rigid_body_constraint_custom_path> *v3; // esi
  rigid_body_constraint_custom_path *result; // eax

  v3 = &g_physics_system->m_list_rbc_custom_path;
  physics_system::validate_member(g_physics_system, b1);
  physics_system::validate_member(g_physics_system, b2);
  result = phys_free_list<rigid_body_constraint_custom_path>::add(
             v3,
             no_error,
             "OUT_OF_MEMORY, rbc_custom_path, INCREASE phys_mem_info::m_num_rbc_custom_path.");
  if ( result )
  {
    result->b1 = b1;
    result->b2 = b2;
  }
  return result;
}

/*
==============
phys_sys::destroy_all_rigid_body
==============
*/
void phys_sys::destroy_all_rigid_body()
{
  phys_free_list<rigid_body_constraint_point>::remove_all(&g_physics_system->m_list_rbc_point);
  phys_free_list<rigid_body_constraint_wheel>::remove_all((phys_free_list<rigid_body_constraint_wheel> *)&g_physics_system->m_list_rbc_hinge);
  phys_free_list<rigid_body_constraint_distance>::remove_all((phys_free_list<broad_phase_group> *)&g_physics_system->m_list_rbc_dist);
  phys_free_list<rigid_body_constraint_ragdoll>::remove_all(&g_physics_system->m_list_rbc_ragdoll);
  phys_free_list<rigid_body_constraint_wheel>::remove_all(&g_physics_system->m_list_rbc_wheel);
  phys_free_list<rigid_body_constraint_angular_actuator>::remove_all(&g_physics_system->m_list_rbc_angular_actuator);
  phys_free_list<rigid_body_constraint_upright>::remove_all(&g_physics_system->m_list_rbc_upright);
  phys_free_list<rigid_body_constraint_custom_orientation>::remove_all(&g_physics_system->m_list_rbc_custom_orientation);
  phys_free_list<rigid_body_constraint_custom_path>::remove_all(&g_physics_system->m_list_rbc_custom_path);
  phys_free_list<rigid_body_constraint_contact>::remove_all(&g_physics_system->m_list_rbc_contact);
  phys_free_list<rigid_body>::remove_all(&g_physics_system->m_list_rigid_body);
}

/*
==============
phys_sys::destroy_all_rbc_contact
==============
*/
void phys_sys::destroy_all_rbc_contact()
{
  phys_free_list<rigid_body_constraint_contact>::remove_all(&g_physics_system->m_list_rbc_contact);
}

