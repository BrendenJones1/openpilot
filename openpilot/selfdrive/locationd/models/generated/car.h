#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8305237537462500954);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1081087899676357520);
void car_H_mod_fun(double *state, double *out_2522554699800313251);
void car_f_fun(double *state, double dt, double *out_5954447520291527369);
void car_F_fun(double *state, double dt, double *out_5881157363307498544);
void car_h_25(double *state, double *unused, double *out_6966633517650276617);
void car_H_25(double *state, double *unused, double *out_4669713637077693663);
void car_h_24(double *state, double *unused, double *out_7101186449596420188);
void car_H_24(double *state, double *unused, double *out_1984491821030492094);
void car_h_30(double *state, double *unused, double *out_7842661027805252649);
void car_H_30(double *state, double *unused, double *out_9197409967205301861);
void car_h_26(double *state, double *unused, double *out_2384085934000915939);
void car_H_26(double *state, double *unused, double *out_8411216955951749887);
void car_h_27(double *state, double *unused, double *out_3929847466205943932);
void car_H_27(double *state, double *unused, double *out_7074570794703824844);
void car_h_29(double *state, double *unused, double *out_2840987760144407004);
void car_H_29(double *state, double *unused, double *out_8687178622890909677);
void car_h_28(double *state, double *unused, double *out_2239399631470262972);
void car_H_28(double *state, double *unused, double *out_4677166433749111365);
void car_h_31(double *state, double *unused, double *out_4019551791810386674);
void car_H_31(double *state, double *unused, double *out_9037425058185101363);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}