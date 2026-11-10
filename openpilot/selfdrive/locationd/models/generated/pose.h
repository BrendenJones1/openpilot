#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_162071913396464737);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3928897807539259508);
void pose_H_mod_fun(double *state, double *out_4191715453033274374);
void pose_f_fun(double *state, double dt, double *out_7907487023000628501);
void pose_F_fun(double *state, double dt, double *out_1715083770350127674);
void pose_h_4(double *state, double *unused, double *out_6882480817021255843);
void pose_H_4(double *state, double *unused, double *out_3437554450978561767);
void pose_h_10(double *state, double *unused, double *out_1643725073239354950);
void pose_H_10(double *state, double *unused, double *out_5699037409662724186);
void pose_h_13(double *state, double *unused, double *out_1956402051470484468);
void pose_H_13(double *state, double *unused, double *out_4173076757338139162);
void pose_h_14(double *state, double *unused, double *out_4352481585600692322);
void pose_H_14(double *state, double *unused, double *out_525686405360922762);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}