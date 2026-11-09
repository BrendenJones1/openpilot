#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1893066262074101492);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5108622378397263891);
void pose_H_mod_fun(double *state, double *out_8501408524920025174);
void pose_f_fun(double *state, double dt, double *out_6089450380884689027);
void pose_F_fun(double *state, double dt, double *out_991092191689553148);
void pose_h_4(double *state, double *unused, double *out_8457711863185147516);
void pose_H_4(double *state, double *unused, double *out_6744925647688056418);
void pose_h_10(double *state, double *unused, double *out_5107656030105349980);
void pose_H_10(double *state, double *unused, double *out_343328804276289840);
void pose_h_13(double *state, double *unused, double *out_5909685414932039417);
void pose_H_13(double *state, double *unused, double *out_4091187217704794269);
void pose_h_14(double *state, double *unused, double *out_3776433797215708635);
void pose_H_14(double *state, double *unused, double *out_3662137215392684122);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}