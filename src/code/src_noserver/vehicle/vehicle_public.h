#pragma once

#include "types.h"

//t6/code/src_noserver/vehicle/nitrous_vehicle.cpp
// bool NitrousVehicle::is_peeling_out(NitrousVehicle *notthis);
// void NitrousVehicle::destructible_damage(NitrousVehicle *notthis, const char *notifyLabel, int damageStage);
// phys_vec3 *NitrousVehicle::get_velocity(NitrousVehicle *notthis, phys_vec3 *result);
// double NitrousVehicle::_get_stuck_accel_factor(NitrousVehicle *notthis, float delta_t);
// void NitrousVehicle::remove_wheels(NitrousVehicle *notthis);
// void NitrousVehicle::update_braking_and_acceleration(NitrousVehicle *notthis, const float __formal);
// double NitrousVehicle::get_max_speed(NitrousVehicle *notthis, bool include_perks);
// void NitrousVehicle::update_control_from_network(NitrousVehicle *notthis, LerpEntityStateVehicle *vehicleState);
// void NitrousVehicle::GetEntityPose(NitrousVehicle *notthis, vec3_t *origin, vec3_t *angles, const int curTime, bool isDriver);
void CG_SetVehDriverInputs(const LocalClientNum_t localClientNum, playerState_s *ps, usercmd_s *cmd);
int Phys_ObjCreateNitrousVehicle(const phys_mat44 *po, const vec3_t *velocity, const vec3_t *translation, const PhysPreset *physPreset, gjk_geom_list_t *gjk_geom_list, int entnum);
// void NitrousVehicle::pause_physics(NitrousVehicle *notthis, bool shutdown);
// void NitrousVehicle::_setup_wheels(NitrousVehicle *notthis, unsigned int a2, LocalClientNum_t localClientNum);
// void NitrousVehicle::_update_orientation_constraint(NitrousVehicle *notthis);
// void NitrousVehicle::_update_gravity(NitrousVehicle *notthis, unsigned int a2, const float delta_t);
// void NitrousVehicle::_update_boost(NitrousVehicle *notthis, const float delta_t);
// void NitrousVehicle::_update_friction(NitrousVehicle *notthis, const float delta_t);
// void NitrousVehicle::_update_fakey_stuff(NitrousVehicle *notthis, const float delta_t);
// void NitrousVehicle::start_path(NitrousVehicle *notthis, int attach_mode);
// void NitrousVehicle::end_path(NitrousVehicle *notthis);
// void NitrousVehicle::debug_render(NitrousVehicle *notthis, int a2);
// void NitrousVehicle::update_steering(NitrousVehicle *notthis, float delta_t, float a3, const float a4);
// void NitrousVehicle::update_from_network(NitrousVehicle *notthis, int a2, trajectory_t pos, trajectory_t apos, LerpEntityStateVehicle *vehicleState, float timeDifference);
void G_SetVehDriverInputs(const LocalClientNum_t localClientNum, playerState_s *ps, usercmd_s *cmd);
// void NitrousVehicle::init(NitrousVehicle *notthis, gentity_t *owner, const VehicleParameter *parameter);
// void NitrousVehicle::init(NitrousVehicle *notthis, LocalClientNum_t localClientNum, centity_t *owner, const VehicleParameter *parameter);
// void NitrousVehicle::update_parms(NitrousVehicle *notthis, int a2, int params, const VehicleParameter *initialization, bool a5);
// void NitrousVehicle::frame_epilog_all_systems(const float delta_t);
// void NitrousVehicle::reinit_parms(int a1, int a2);
// void NitrousVehicle::debug_render_all(int a1);
void G_ClearVehicleInputs();
// void NitrousVehicle::unpause_physics(NitrousVehicle *notthis);
// void NitrousVehicle::_update_prolog(NitrousVehicle *notthis, const char *a2, const float delta_t);
// void NitrousVehicle::frame_prolog_all_systems(const float delta_t);
// void NitrousVehicle::reset_vehicle_physics();
// void NitrousVehicle::remove_vehicle(NitrousVehicle *const v);
void Vehicle_Launch(const LocalClientNum_t localClientNum, centity_t *cent, const vec3_t *hitp, const vec3_t *force, const bool relative);
// void NitrousVehicle::NitrousVehicle(NitrousVehicle *notthis);
// NitrousVehicle **NitrousVehicle::add_vehicle(int id);
void debug_render(unsigned int a1, PhysObjUserData *userData);

//#include "vehicle/nitrous_vehicle.h"

//t6/code/src_noserver/vehicle/nitrous_vehicle_constraint.cpp
rigid_body_constraint_custom_path *path_constraint_create(rigid_body *rb);
void path_constraint_destroy(rigid_body_constraint_custom_path *vpc);
void path_constraint_update(rigid_body_constraint_custom_path *vpc, const NitrousVehicle *nitrousVehicle);

//t6/code/src_noserver/vehicle/nitrous_vehicle_controller.cpp
// void NitrousVehicleController::UpdateControlsTank(NitrousVehicleController *notthis, NitrousVehicle *rbveh);
// double NitrousVehicleController::GetJumpCharge(NitrousVehicleController *notthis);
// void NitrousVehicleController::UpdateVehicleInputs(NitrousVehicleController *notthis, unsigned int a2, NitrousVehicle *rbveh, float target_yaw, float target_accel, float forward_preference);
float StunRandomBrake(const usercmd_s *cmd, float desired_brake, float last_brake);
// void NitrousVehicleController::UpdateStun(NitrousVehicleController *notthis, NitrousVehicle *rbveh, float delta_t);
// void NitrousVehicleController::UpdateControlsDefault(NitrousVehicleController *notthis, int a2, NitrousVehicle *rbveh, const float delta_t);
// void NitrousVehicleController::UpdateControlsSpiderBot(NitrousVehicleController *notthis, unsigned int a2, NitrousVehicle *rbveh, const float delta_t);
// void NitrousVehicleController::SetScriptTarget(NitrousVehicleController *notthis, NitrousVehicle *rbveh, const phys_vec3 *goal_position, const float goal_radius, const float goal_speed, const bool stopAtGoal);
// void NitrousVehicleController::UpdateJump(NitrousVehicleController *notthis, int a2, NitrousVehicle *rbveh, const float delta_t);
// void NitrousVehicleController::UpdateApplyBoatAccel(NitrousVehicleController *notthis, int a2, NitrousVehicle *rbveh, const float delta_t);
// void NitrousVehicleController::UpdateScriptVehicleControl(NitrousVehicleController *notthis, unsigned int a2, long double rbveh, NitrousVehicle *a4, const float delta_t);
// void NitrousVehicleController::UpdateControlsStrafeMode(NitrousVehicleController *notthis, NitrousVehicle *rbveh);
// void NitrousVehicleController::UpdateControlsHorse(NitrousVehicleController *notthis, NitrousVehicle *rbveh, const float delta_t);
// void NitrousVehicleController::UpdateControls(NitrousVehicleController *notthis, unsigned int a2, NitrousVehicle *rbveh, float delta_t);

//t6/code/src_noserver/vehicle/nitrous_vehicle_effects.cpp
void GetWheelStateColor(WheelEffectState state, vec4_t *color, float rate);
// void NitrousVehicle::_update_wheel_effect_states(NitrousVehicle *notthis, const float delta_t);
// void NitrousVehicle::debug_render_effects(NitrousVehicle *notthis, int a2);

