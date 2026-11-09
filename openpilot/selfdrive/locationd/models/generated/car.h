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
void car_err_fun(double *nom_x, double *delta_x, double *out_1219971614518250164);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2519811554954093883);
void car_H_mod_fun(double *state, double *out_5466981997076297265);
void car_f_fun(double *state, double dt, double *out_9014929315491492668);
void car_F_fun(double *state, double dt, double *out_413829705495657398);
void car_h_25(double *state, double *unused, double *out_191111347167670748);
void car_H_25(double *state, double *unused, double *out_3022387675152275978);
void car_h_24(double *state, double *unused, double *out_8740225053863857224);
void car_H_24(double *state, double *unused, double *out_959935476245491920);
void car_h_30(double *state, double *unused, double *out_649312709326232410);
void car_H_30(double *state, double *unused, double *out_5540720633659524605);
void car_h_26(double *state, double *unused, double *out_5047264790607861422);
void car_H_26(double *state, double *unused, double *out_719115643721780246);
void car_h_27(double *state, double *unused, double *out_5451618523913286087);
void car_H_27(double *state, double *unused, double *out_7764314704843467822);
void car_h_29(double *state, double *unused, double *out_5113852899042216344);
void car_H_29(double *state, double *unused, double *out_6050951977973916789);
void car_h_28(double *state, double *unused, double *out_531305315392855666);
void car_H_28(double *state, double *unused, double *out_968552960904386215);
void car_h_31(double *state, double *unused, double *out_8213210513073112883);
void car_H_31(double *state, double *unused, double *out_3053033637029236406);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}