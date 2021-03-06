#ifndef PDIK_H
#define PDIK_H

#ifndef CASSIE_QPOS_SIZE
#define CASSIE_QPOS_SIZE 35
#endif

#include "mujoco.h"
#include <stdio.h>

struct _pdikdata_t_
{
	mjModel* m;
    mjData* d;
    int32_t max_doik;
    int32_t doik;
    double lowscore;
    int body_id;
    double target_body[3];
    double pd_k;
    double pd_b;
    int frame;
};
typedef struct _pdikdata_t_ pdikdata_t;

double apply_pd_controller(double k1, double k2, double* forces, double* xcurr, double* vcurr, double* xtarget);
void pdik_per_step_control(pdikdata_t* t);

#endif

