#pragma once

#include "types.h"

//t6/code/src_noserver/vehicle/nitrous_vehicle.cpp
// bool __thiscall NitrousVehicle::is_peeling_out(NitrousVehicle *this);
// void __thiscall NitrousVehicle::destructible_damage(NitrousVehicle *this, const char *notifyLabel, int damageStage);
// phys_vec3 *__thiscall NitrousVehicle::get_velocity(NitrousVehicle *this, phys_vec3 *result);
// double __thiscall NitrousVehicle::_get_stuck_accel_factor(NitrousVehicle *this, float delta_t);
// void __thiscall NitrousVehicle::remove_wheels(NitrousVehicle *this);
// void __thiscall NitrousVehicle::update_braking_and_acceleration(NitrousVehicle *this, const float __formal);
// double __thiscall NitrousVehicle::get_max_speed(NitrousVehicle *this, bool include_perks);
// void __thiscall NitrousVehicle::update_control_from_network(NitrousVehicle *this, LerpEntityStateVehicle *vehicleState);
// void __thiscall NitrousVehicle::GetEntityPose(NitrousVehicle *this, vec3_t *origin, vec3_t *angles, const int curTime, bool isDriver);
void CG_SetVehDriverInputs(const LocalClientNum_t localClientNum, playerState_s *ps, usercmd_s *cmd);
int Phys_ObjCreateNitrousVehicle(const phys_mat44 *po, const vec3_t *velocity, const vec3_t *translation, const PhysPreset *physPreset, gjk_geom_list_t *gjk_geom_list, int entnum);
// void __thiscall NitrousVehicle::pause_physics(NitrousVehicle *this, bool shutdown);
// void NitrousVehicle::_setup_wheels(NitrousVehicle *this, unsigned int a2, LocalClientNum_t localClientNum);
// void __thiscall NitrousVehicle::_update_orientation_constraint(NitrousVehicle *this);
// ;
// void __thiscall NitrousVehicle::_update_boost(NitrousVehicle *this, const float delta_t);
// void __thiscall NitrousVehicle::_update_friction(NitrousVehicle *this, const float delta_t);
// void __thiscall NitrousVehicle::_update_fakey_stuff(NitrousVehicle *this, const float delta_t);
// void __thiscall NitrousVehicle::start_path(NitrousVehicle *this, int attach_mode);
// void __thiscall NitrousVehicle::end_path(NitrousVehicle *this);
// ;
// void NitrousVehicle::update_steering(NitrousVehicle *this, float delta_t, float a3, const float a4);
// ;
void G_SetVehDriverInputs(const LocalClientNum_t localClientNum, playerState_s *ps, usercmd_s *cmd);
// void __thiscall NitrousVehicle::init(NitrousVehicle *this, gentity_t *owner, const VehicleParameter *parameter);
// void __thiscall NitrousVehicle::init(NitrousVehicle *this, LocalClientNum_t localClientNum, centity_t *owner, const VehicleParameter *parameter);
// ;
// void NitrousVehicle::frame_epilog_all_systems(const float delta_t);
// void NitrousVehicle::reinit_parms(int a1, int a2);
// void NitrousVehicle::debug_render_all(int a1);
void G_ClearVehicleInputs();
// void __thiscall NitrousVehicle::unpause_physics(NitrousVehicle *this);
// void NitrousVehicle::_update_prolog(NitrousVehicle *this@<ecx>, const char *a2@<edi>, const float delta_t);
// void NitrousVehicle::frame_prolog_all_systems(const float delta_t);
// void NitrousVehicle::reset_vehicle_physics();
// void NitrousVehicle::remove_vehicle(NitrousVehicle *const v);
void Vehicle_Launch(const LocalClientNum_t localClientNum, centity_t *cent, const vec3_t *hitp, const vec3_t *force, const bool relative);
// void __thiscall NitrousVehicle::NitrousVehicle(NitrousVehicle *this);
// NitrousVehicle **NitrousVehicle::add_vehicle(int id);
void debug_render(unsigned int a1, PhysObjUserData *userData);

//#include "vehicle/nitrous_vehicle.h"

//t6/code/src_noserver/vehicle/nitrous_vehicle_constraint.cpp
rigid_body_constraint_custom_path *path_constraint_create(rigid_body *rb);
void path_constraint_destroy(rigid_body_constraint_custom_path *vpc);
void path_constraint_update(rigid_body_constraint_custom_path *vpc, const NitrousVehicle *nitrousVehicle);

//t6/code/src_noserver/vehicle/nitrous_vehicle_controller.cpp
// void __thiscall NitrousVehicleController::UpdateControlsTank(NitrousVehicleController *this, NitrousVehicle *rbveh);
// double __thiscall NitrousVehicleController::GetJumpCharge(NitrousVehicleController *this);
// ;
float StunRandomBrake(const usercmd_s *cmd, float desired_brake, float last_brake);
// void __thiscall NitrousVehicleController::UpdateStun(NitrousVehicleController *this, NitrousVehicle *rbveh, float delta_t);
// void NitrousVehicleController::UpdateControlsDefault(NitrousVehicleController *this, int a2, NitrousVehicle *rbveh, const float delta_t);
// ;
// void __thiscall NitrousVehicleController::SetScriptTarget(NitrousVehicleController *this, NitrousVehicle *rbveh, const phys_vec3 *goal_position, const float goal_radius, const float goal_speed, const bool stopAtGoal);
// ;
// ;
// ;
// void __thiscall NitrousVehicleController::UpdateControlsStrafeMode(NitrousVehicleController *this, NitrousVehicle *rbveh);
// void __thiscall NitrousVehicleController::UpdateControlsHorse(NitrousVehicleController *this, NitrousVehicle *rbveh, const float delta_t);
// void NitrousVehicleController::UpdateControls(NitrousVehicleController *this, unsigned int a2, NitrousVehicle *rbveh, float delta_t);

//t6/code/src_noserver/vehicle/nitrous_vehicle_effects.cpp
void GetWheelStateColor(WheelEffectState state, vec4_t *color, float rate);
// void __thiscall NitrousVehicle::_update_wheel_effect_states(NitrousVehicle *this, const float delta_t);
// ;

