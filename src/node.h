#ifndef NODE_H
#define NODE_H

#include "mujoco.h"
#include "glfw3.h"
#include "main.h"
#include <stdio.h>

struct _cassie_body_id_t_
{
    uint16_t id;
};
typedef struct _cassie_body_id_t_ cassie_body_id_t;

struct _node_body_id_t_
{
    uint16_t id;
};
typedef struct _node_body_id_t_ node_body_id_t;


typedef mjtNum* v3_t;


#include "node.h"

int node_get_frame_from_node_body_id(
    traj_info_t* traj_info,
    timeline_t* timeline,
    node_body_id_t node_id);
void node_calc_frame_lowhigh(
    int* low_frame,
    int* high_frame,
    int rootframe,
    int numposes,
    traj_info_t* traj_info);
void node_calclate_global_target_using_transformation_type(
    traj_info_t* traj_info,
    timeline_t* timeline,
    v3_t global_body_init_xpos_at_rootframe,
    v3_t global_body_target_xpos,
    v3_t rootframe_transform_vector,
    int rootframe,
    int frame_offset,
    cassie_body_id_t body_id);
void node_calculate_arbitrary_target_using_scale_type(
    traj_info_t* traj_info,
    double* final_curr,
    double* root_transformation,
    double* init_curr,
    double* init_root,
    int vector_size,
    double scalefactor);
double node_calculate_filter_from_frame_offset(
    double frame_offset,
    double sigma,
    double nodeheight);
void node_calculate_rootframe_transformation_vector(
    traj_info_t* traj_info,
    timeline_t* timeline,
    v3_t rootframe_transform_vector,
    cassie_body_id_t body_id,
    node_body_id_t node_id);
double node_caluclate_jointdiff(
    traj_info_t* traj_info,
    v3_t body_init_xpos);
void node_compare_looped_filters(
    traj_info_t* traj_info,
    int rootframe,
    int* currframe,
    int* frame_offset);
void node_dropped_jointmove(
    traj_info_t* traj_info,
    cassie_body_id_t body_id,
    node_body_id_t node_id);
void node_dropped_positional(
    traj_info_t* traj_info,
    cassie_body_id_t body_id,
    node_body_id_t node_id);
node_body_id_t node_get_body_id_from_node_index(
    int index);
node_body_id_t node_get_body_id_from_real_body_id(
    int real);
v3_t node_get_body_xpos_by_frame(
    traj_info_t* traj_info,
    timeline_t* timeline,
    int frame,
    cassie_body_id_t id);
v3_t node_get_body_xpos_curr(
    traj_info_t* traj_info,
    cassie_body_id_t id);
cassie_body_id_t node_get_cassie_id_from_index(
    int i);
v3_t node_get_qpos_by_node_id(
    traj_info_t* traj_info,
    node_body_id_t id);
void node_perform_ik_on_xpos_transformation(
    traj_info_t* traj_info,
    timeline_t* overwrite,
    ik_solver_params_t* params,
    cassie_body_id_t body_id,
    int frame,
    int frameoffset,
    v3_t target,
    double* ik_iter_total);
void node_perform_pert(
    traj_info_t* traj_info,
    ik_solver_params_t* params,
    v3_t rootframe_transform_vector,
    cassie_body_id_t body_id,
    int rootframe);
void node_position_initial_positional(
    traj_info_t* traj_info,
    cassie_body_id_t body_id);
void node_position_initial_using_cassie_body(
    traj_info_t* traj_info,
    cassie_body_id_t body_id);
void node_position_jointid(
    traj_info_t* traj_info,
    cassie_body_id_t body_id);
void node_position_jointmove(
    traj_info_t* traj_info,
    cassie_body_id_t body_id,
    int rootframe,
    double jointdiff);
void node_refine_pert(
    traj_info_t* traj_info,
    ik_solver_params_t* params);
void node_scale_visually_jointmove(
    traj_info_t* traj_info,
    cassie_body_id_t body_id,
    node_body_id_t node_id);
void node_scale_visually_positional(
    traj_info_t* traj_info,
    cassie_body_id_t body_id,
    node_body_id_t node_id);

#endif

