#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1219971614518250164) {
   out_1219971614518250164[0] = delta_x[0] + nom_x[0];
   out_1219971614518250164[1] = delta_x[1] + nom_x[1];
   out_1219971614518250164[2] = delta_x[2] + nom_x[2];
   out_1219971614518250164[3] = delta_x[3] + nom_x[3];
   out_1219971614518250164[4] = delta_x[4] + nom_x[4];
   out_1219971614518250164[5] = delta_x[5] + nom_x[5];
   out_1219971614518250164[6] = delta_x[6] + nom_x[6];
   out_1219971614518250164[7] = delta_x[7] + nom_x[7];
   out_1219971614518250164[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2519811554954093883) {
   out_2519811554954093883[0] = -nom_x[0] + true_x[0];
   out_2519811554954093883[1] = -nom_x[1] + true_x[1];
   out_2519811554954093883[2] = -nom_x[2] + true_x[2];
   out_2519811554954093883[3] = -nom_x[3] + true_x[3];
   out_2519811554954093883[4] = -nom_x[4] + true_x[4];
   out_2519811554954093883[5] = -nom_x[5] + true_x[5];
   out_2519811554954093883[6] = -nom_x[6] + true_x[6];
   out_2519811554954093883[7] = -nom_x[7] + true_x[7];
   out_2519811554954093883[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5466981997076297265) {
   out_5466981997076297265[0] = 1.0;
   out_5466981997076297265[1] = 0.0;
   out_5466981997076297265[2] = 0.0;
   out_5466981997076297265[3] = 0.0;
   out_5466981997076297265[4] = 0.0;
   out_5466981997076297265[5] = 0.0;
   out_5466981997076297265[6] = 0.0;
   out_5466981997076297265[7] = 0.0;
   out_5466981997076297265[8] = 0.0;
   out_5466981997076297265[9] = 0.0;
   out_5466981997076297265[10] = 1.0;
   out_5466981997076297265[11] = 0.0;
   out_5466981997076297265[12] = 0.0;
   out_5466981997076297265[13] = 0.0;
   out_5466981997076297265[14] = 0.0;
   out_5466981997076297265[15] = 0.0;
   out_5466981997076297265[16] = 0.0;
   out_5466981997076297265[17] = 0.0;
   out_5466981997076297265[18] = 0.0;
   out_5466981997076297265[19] = 0.0;
   out_5466981997076297265[20] = 1.0;
   out_5466981997076297265[21] = 0.0;
   out_5466981997076297265[22] = 0.0;
   out_5466981997076297265[23] = 0.0;
   out_5466981997076297265[24] = 0.0;
   out_5466981997076297265[25] = 0.0;
   out_5466981997076297265[26] = 0.0;
   out_5466981997076297265[27] = 0.0;
   out_5466981997076297265[28] = 0.0;
   out_5466981997076297265[29] = 0.0;
   out_5466981997076297265[30] = 1.0;
   out_5466981997076297265[31] = 0.0;
   out_5466981997076297265[32] = 0.0;
   out_5466981997076297265[33] = 0.0;
   out_5466981997076297265[34] = 0.0;
   out_5466981997076297265[35] = 0.0;
   out_5466981997076297265[36] = 0.0;
   out_5466981997076297265[37] = 0.0;
   out_5466981997076297265[38] = 0.0;
   out_5466981997076297265[39] = 0.0;
   out_5466981997076297265[40] = 1.0;
   out_5466981997076297265[41] = 0.0;
   out_5466981997076297265[42] = 0.0;
   out_5466981997076297265[43] = 0.0;
   out_5466981997076297265[44] = 0.0;
   out_5466981997076297265[45] = 0.0;
   out_5466981997076297265[46] = 0.0;
   out_5466981997076297265[47] = 0.0;
   out_5466981997076297265[48] = 0.0;
   out_5466981997076297265[49] = 0.0;
   out_5466981997076297265[50] = 1.0;
   out_5466981997076297265[51] = 0.0;
   out_5466981997076297265[52] = 0.0;
   out_5466981997076297265[53] = 0.0;
   out_5466981997076297265[54] = 0.0;
   out_5466981997076297265[55] = 0.0;
   out_5466981997076297265[56] = 0.0;
   out_5466981997076297265[57] = 0.0;
   out_5466981997076297265[58] = 0.0;
   out_5466981997076297265[59] = 0.0;
   out_5466981997076297265[60] = 1.0;
   out_5466981997076297265[61] = 0.0;
   out_5466981997076297265[62] = 0.0;
   out_5466981997076297265[63] = 0.0;
   out_5466981997076297265[64] = 0.0;
   out_5466981997076297265[65] = 0.0;
   out_5466981997076297265[66] = 0.0;
   out_5466981997076297265[67] = 0.0;
   out_5466981997076297265[68] = 0.0;
   out_5466981997076297265[69] = 0.0;
   out_5466981997076297265[70] = 1.0;
   out_5466981997076297265[71] = 0.0;
   out_5466981997076297265[72] = 0.0;
   out_5466981997076297265[73] = 0.0;
   out_5466981997076297265[74] = 0.0;
   out_5466981997076297265[75] = 0.0;
   out_5466981997076297265[76] = 0.0;
   out_5466981997076297265[77] = 0.0;
   out_5466981997076297265[78] = 0.0;
   out_5466981997076297265[79] = 0.0;
   out_5466981997076297265[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_9014929315491492668) {
   out_9014929315491492668[0] = state[0];
   out_9014929315491492668[1] = state[1];
   out_9014929315491492668[2] = state[2];
   out_9014929315491492668[3] = state[3];
   out_9014929315491492668[4] = state[4];
   out_9014929315491492668[5] = dt*(stiffness_front*(-state[2] - state[3] + state[7])*state[0]/state[1] + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/state[4] + ((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4])*state[6] - 9.8100000000000005*state[8]) + state[5];
   out_9014929315491492668[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_9014929315491492668[7] = state[7];
   out_9014929315491492668[8] = state[8];
}
void F_fun(double *state, double dt, double *out_413829705495657398) {
   out_413829705495657398[0] = 1;
   out_413829705495657398[1] = 0;
   out_413829705495657398[2] = 0;
   out_413829705495657398[3] = 0;
   out_413829705495657398[4] = 0;
   out_413829705495657398[5] = 0;
   out_413829705495657398[6] = 0;
   out_413829705495657398[7] = 0;
   out_413829705495657398[8] = 0;
   out_413829705495657398[9] = 0;
   out_413829705495657398[10] = 1;
   out_413829705495657398[11] = 0;
   out_413829705495657398[12] = 0;
   out_413829705495657398[13] = 0;
   out_413829705495657398[14] = 0;
   out_413829705495657398[15] = 0;
   out_413829705495657398[16] = 0;
   out_413829705495657398[17] = 0;
   out_413829705495657398[18] = 0;
   out_413829705495657398[19] = 0;
   out_413829705495657398[20] = 1;
   out_413829705495657398[21] = 0;
   out_413829705495657398[22] = 0;
   out_413829705495657398[23] = 0;
   out_413829705495657398[24] = 0;
   out_413829705495657398[25] = 0;
   out_413829705495657398[26] = 0;
   out_413829705495657398[27] = 0;
   out_413829705495657398[28] = 0;
   out_413829705495657398[29] = 0;
   out_413829705495657398[30] = 1;
   out_413829705495657398[31] = 0;
   out_413829705495657398[32] = 0;
   out_413829705495657398[33] = 0;
   out_413829705495657398[34] = 0;
   out_413829705495657398[35] = 0;
   out_413829705495657398[36] = 0;
   out_413829705495657398[37] = 0;
   out_413829705495657398[38] = 0;
   out_413829705495657398[39] = 0;
   out_413829705495657398[40] = 1;
   out_413829705495657398[41] = 0;
   out_413829705495657398[42] = 0;
   out_413829705495657398[43] = 0;
   out_413829705495657398[44] = 0;
   out_413829705495657398[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/state[1] + (-stiffness_front - stiffness_rear)*state[5]/state[4] + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/state[4]);
   out_413829705495657398[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/pow(state[1], 2);
   out_413829705495657398[47] = -dt*stiffness_front*state[0]/state[1];
   out_413829705495657398[48] = -dt*stiffness_front*state[0]/state[1];
   out_413829705495657398[49] = dt*(-(-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/pow(state[4], 2) + (-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/pow(state[4], 2) - 1)*state[6]);
   out_413829705495657398[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/state[4] + 1;
   out_413829705495657398[51] = dt*((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4]);
   out_413829705495657398[52] = dt*stiffness_front*state[0]/state[1];
   out_413829705495657398[53] = -9.8100000000000005*dt;
   out_413829705495657398[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_413829705495657398[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_413829705495657398[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_413829705495657398[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_413829705495657398[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_413829705495657398[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_413829705495657398[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_413829705495657398[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_413829705495657398[62] = 0;
   out_413829705495657398[63] = 0;
   out_413829705495657398[64] = 0;
   out_413829705495657398[65] = 0;
   out_413829705495657398[66] = 0;
   out_413829705495657398[67] = 0;
   out_413829705495657398[68] = 0;
   out_413829705495657398[69] = 0;
   out_413829705495657398[70] = 1;
   out_413829705495657398[71] = 0;
   out_413829705495657398[72] = 0;
   out_413829705495657398[73] = 0;
   out_413829705495657398[74] = 0;
   out_413829705495657398[75] = 0;
   out_413829705495657398[76] = 0;
   out_413829705495657398[77] = 0;
   out_413829705495657398[78] = 0;
   out_413829705495657398[79] = 0;
   out_413829705495657398[80] = 1;
}
void h_25(double *state, double *unused, double *out_191111347167670748) {
   out_191111347167670748[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3022387675152275978) {
   out_3022387675152275978[0] = 0;
   out_3022387675152275978[1] = 0;
   out_3022387675152275978[2] = 0;
   out_3022387675152275978[3] = 0;
   out_3022387675152275978[4] = 0;
   out_3022387675152275978[5] = 0;
   out_3022387675152275978[6] = 1;
   out_3022387675152275978[7] = 0;
   out_3022387675152275978[8] = 0;
}
void h_24(double *state, double *unused, double *out_8740225053863857224) {
   out_8740225053863857224[0] = state[4];
   out_8740225053863857224[1] = state[5];
}
void H_24(double *state, double *unused, double *out_959935476245491920) {
   out_959935476245491920[0] = 0;
   out_959935476245491920[1] = 0;
   out_959935476245491920[2] = 0;
   out_959935476245491920[3] = 0;
   out_959935476245491920[4] = 1;
   out_959935476245491920[5] = 0;
   out_959935476245491920[6] = 0;
   out_959935476245491920[7] = 0;
   out_959935476245491920[8] = 0;
   out_959935476245491920[9] = 0;
   out_959935476245491920[10] = 0;
   out_959935476245491920[11] = 0;
   out_959935476245491920[12] = 0;
   out_959935476245491920[13] = 0;
   out_959935476245491920[14] = 1;
   out_959935476245491920[15] = 0;
   out_959935476245491920[16] = 0;
   out_959935476245491920[17] = 0;
}
void h_30(double *state, double *unused, double *out_649312709326232410) {
   out_649312709326232410[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5540720633659524605) {
   out_5540720633659524605[0] = 0;
   out_5540720633659524605[1] = 0;
   out_5540720633659524605[2] = 0;
   out_5540720633659524605[3] = 0;
   out_5540720633659524605[4] = 1;
   out_5540720633659524605[5] = 0;
   out_5540720633659524605[6] = 0;
   out_5540720633659524605[7] = 0;
   out_5540720633659524605[8] = 0;
}
void h_26(double *state, double *unused, double *out_5047264790607861422) {
   out_5047264790607861422[0] = state[7];
}
void H_26(double *state, double *unused, double *out_719115643721780246) {
   out_719115643721780246[0] = 0;
   out_719115643721780246[1] = 0;
   out_719115643721780246[2] = 0;
   out_719115643721780246[3] = 0;
   out_719115643721780246[4] = 0;
   out_719115643721780246[5] = 0;
   out_719115643721780246[6] = 0;
   out_719115643721780246[7] = 1;
   out_719115643721780246[8] = 0;
}
void h_27(double *state, double *unused, double *out_5451618523913286087) {
   out_5451618523913286087[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7764314704843467822) {
   out_7764314704843467822[0] = 0;
   out_7764314704843467822[1] = 0;
   out_7764314704843467822[2] = 0;
   out_7764314704843467822[3] = 1;
   out_7764314704843467822[4] = 0;
   out_7764314704843467822[5] = 0;
   out_7764314704843467822[6] = 0;
   out_7764314704843467822[7] = 0;
   out_7764314704843467822[8] = 0;
}
void h_29(double *state, double *unused, double *out_5113852899042216344) {
   out_5113852899042216344[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6050951977973916789) {
   out_6050951977973916789[0] = 0;
   out_6050951977973916789[1] = 1;
   out_6050951977973916789[2] = 0;
   out_6050951977973916789[3] = 0;
   out_6050951977973916789[4] = 0;
   out_6050951977973916789[5] = 0;
   out_6050951977973916789[6] = 0;
   out_6050951977973916789[7] = 0;
   out_6050951977973916789[8] = 0;
}
void h_28(double *state, double *unused, double *out_531305315392855666) {
   out_531305315392855666[0] = state[0];
}
void H_28(double *state, double *unused, double *out_968552960904386215) {
   out_968552960904386215[0] = 1;
   out_968552960904386215[1] = 0;
   out_968552960904386215[2] = 0;
   out_968552960904386215[3] = 0;
   out_968552960904386215[4] = 0;
   out_968552960904386215[5] = 0;
   out_968552960904386215[6] = 0;
   out_968552960904386215[7] = 0;
   out_968552960904386215[8] = 0;
}
void h_31(double *state, double *unused, double *out_8213210513073112883) {
   out_8213210513073112883[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3053033637029236406) {
   out_3053033637029236406[0] = 0;
   out_3053033637029236406[1] = 0;
   out_3053033637029236406[2] = 0;
   out_3053033637029236406[3] = 0;
   out_3053033637029236406[4] = 0;
   out_3053033637029236406[5] = 0;
   out_3053033637029236406[6] = 0;
   out_3053033637029236406[7] = 0;
   out_3053033637029236406[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1219971614518250164) {
  err_fun(nom_x, delta_x, out_1219971614518250164);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2519811554954093883) {
  inv_err_fun(nom_x, true_x, out_2519811554954093883);
}
void car_H_mod_fun(double *state, double *out_5466981997076297265) {
  H_mod_fun(state, out_5466981997076297265);
}
void car_f_fun(double *state, double dt, double *out_9014929315491492668) {
  f_fun(state,  dt, out_9014929315491492668);
}
void car_F_fun(double *state, double dt, double *out_413829705495657398) {
  F_fun(state,  dt, out_413829705495657398);
}
void car_h_25(double *state, double *unused, double *out_191111347167670748) {
  h_25(state, unused, out_191111347167670748);
}
void car_H_25(double *state, double *unused, double *out_3022387675152275978) {
  H_25(state, unused, out_3022387675152275978);
}
void car_h_24(double *state, double *unused, double *out_8740225053863857224) {
  h_24(state, unused, out_8740225053863857224);
}
void car_H_24(double *state, double *unused, double *out_959935476245491920) {
  H_24(state, unused, out_959935476245491920);
}
void car_h_30(double *state, double *unused, double *out_649312709326232410) {
  h_30(state, unused, out_649312709326232410);
}
void car_H_30(double *state, double *unused, double *out_5540720633659524605) {
  H_30(state, unused, out_5540720633659524605);
}
void car_h_26(double *state, double *unused, double *out_5047264790607861422) {
  h_26(state, unused, out_5047264790607861422);
}
void car_H_26(double *state, double *unused, double *out_719115643721780246) {
  H_26(state, unused, out_719115643721780246);
}
void car_h_27(double *state, double *unused, double *out_5451618523913286087) {
  h_27(state, unused, out_5451618523913286087);
}
void car_H_27(double *state, double *unused, double *out_7764314704843467822) {
  H_27(state, unused, out_7764314704843467822);
}
void car_h_29(double *state, double *unused, double *out_5113852899042216344) {
  h_29(state, unused, out_5113852899042216344);
}
void car_H_29(double *state, double *unused, double *out_6050951977973916789) {
  H_29(state, unused, out_6050951977973916789);
}
void car_h_28(double *state, double *unused, double *out_531305315392855666) {
  h_28(state, unused, out_531305315392855666);
}
void car_H_28(double *state, double *unused, double *out_968552960904386215) {
  H_28(state, unused, out_968552960904386215);
}
void car_h_31(double *state, double *unused, double *out_8213210513073112883) {
  h_31(state, unused, out_8213210513073112883);
}
void car_H_31(double *state, double *unused, double *out_3053033637029236406) {
  H_31(state, unused, out_3053033637029236406);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
