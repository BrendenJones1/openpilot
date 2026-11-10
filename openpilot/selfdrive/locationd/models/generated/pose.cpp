#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_162071913396464737) {
   out_162071913396464737[0] = delta_x[0] + nom_x[0];
   out_162071913396464737[1] = delta_x[1] + nom_x[1];
   out_162071913396464737[2] = delta_x[2] + nom_x[2];
   out_162071913396464737[3] = delta_x[3] + nom_x[3];
   out_162071913396464737[4] = delta_x[4] + nom_x[4];
   out_162071913396464737[5] = delta_x[5] + nom_x[5];
   out_162071913396464737[6] = delta_x[6] + nom_x[6];
   out_162071913396464737[7] = delta_x[7] + nom_x[7];
   out_162071913396464737[8] = delta_x[8] + nom_x[8];
   out_162071913396464737[9] = delta_x[9] + nom_x[9];
   out_162071913396464737[10] = delta_x[10] + nom_x[10];
   out_162071913396464737[11] = delta_x[11] + nom_x[11];
   out_162071913396464737[12] = delta_x[12] + nom_x[12];
   out_162071913396464737[13] = delta_x[13] + nom_x[13];
   out_162071913396464737[14] = delta_x[14] + nom_x[14];
   out_162071913396464737[15] = delta_x[15] + nom_x[15];
   out_162071913396464737[16] = delta_x[16] + nom_x[16];
   out_162071913396464737[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3928897807539259508) {
   out_3928897807539259508[0] = -nom_x[0] + true_x[0];
   out_3928897807539259508[1] = -nom_x[1] + true_x[1];
   out_3928897807539259508[2] = -nom_x[2] + true_x[2];
   out_3928897807539259508[3] = -nom_x[3] + true_x[3];
   out_3928897807539259508[4] = -nom_x[4] + true_x[4];
   out_3928897807539259508[5] = -nom_x[5] + true_x[5];
   out_3928897807539259508[6] = -nom_x[6] + true_x[6];
   out_3928897807539259508[7] = -nom_x[7] + true_x[7];
   out_3928897807539259508[8] = -nom_x[8] + true_x[8];
   out_3928897807539259508[9] = -nom_x[9] + true_x[9];
   out_3928897807539259508[10] = -nom_x[10] + true_x[10];
   out_3928897807539259508[11] = -nom_x[11] + true_x[11];
   out_3928897807539259508[12] = -nom_x[12] + true_x[12];
   out_3928897807539259508[13] = -nom_x[13] + true_x[13];
   out_3928897807539259508[14] = -nom_x[14] + true_x[14];
   out_3928897807539259508[15] = -nom_x[15] + true_x[15];
   out_3928897807539259508[16] = -nom_x[16] + true_x[16];
   out_3928897807539259508[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4191715453033274374) {
   out_4191715453033274374[0] = 1.0;
   out_4191715453033274374[1] = 0.0;
   out_4191715453033274374[2] = 0.0;
   out_4191715453033274374[3] = 0.0;
   out_4191715453033274374[4] = 0.0;
   out_4191715453033274374[5] = 0.0;
   out_4191715453033274374[6] = 0.0;
   out_4191715453033274374[7] = 0.0;
   out_4191715453033274374[8] = 0.0;
   out_4191715453033274374[9] = 0.0;
   out_4191715453033274374[10] = 0.0;
   out_4191715453033274374[11] = 0.0;
   out_4191715453033274374[12] = 0.0;
   out_4191715453033274374[13] = 0.0;
   out_4191715453033274374[14] = 0.0;
   out_4191715453033274374[15] = 0.0;
   out_4191715453033274374[16] = 0.0;
   out_4191715453033274374[17] = 0.0;
   out_4191715453033274374[18] = 0.0;
   out_4191715453033274374[19] = 1.0;
   out_4191715453033274374[20] = 0.0;
   out_4191715453033274374[21] = 0.0;
   out_4191715453033274374[22] = 0.0;
   out_4191715453033274374[23] = 0.0;
   out_4191715453033274374[24] = 0.0;
   out_4191715453033274374[25] = 0.0;
   out_4191715453033274374[26] = 0.0;
   out_4191715453033274374[27] = 0.0;
   out_4191715453033274374[28] = 0.0;
   out_4191715453033274374[29] = 0.0;
   out_4191715453033274374[30] = 0.0;
   out_4191715453033274374[31] = 0.0;
   out_4191715453033274374[32] = 0.0;
   out_4191715453033274374[33] = 0.0;
   out_4191715453033274374[34] = 0.0;
   out_4191715453033274374[35] = 0.0;
   out_4191715453033274374[36] = 0.0;
   out_4191715453033274374[37] = 0.0;
   out_4191715453033274374[38] = 1.0;
   out_4191715453033274374[39] = 0.0;
   out_4191715453033274374[40] = 0.0;
   out_4191715453033274374[41] = 0.0;
   out_4191715453033274374[42] = 0.0;
   out_4191715453033274374[43] = 0.0;
   out_4191715453033274374[44] = 0.0;
   out_4191715453033274374[45] = 0.0;
   out_4191715453033274374[46] = 0.0;
   out_4191715453033274374[47] = 0.0;
   out_4191715453033274374[48] = 0.0;
   out_4191715453033274374[49] = 0.0;
   out_4191715453033274374[50] = 0.0;
   out_4191715453033274374[51] = 0.0;
   out_4191715453033274374[52] = 0.0;
   out_4191715453033274374[53] = 0.0;
   out_4191715453033274374[54] = 0.0;
   out_4191715453033274374[55] = 0.0;
   out_4191715453033274374[56] = 0.0;
   out_4191715453033274374[57] = 1.0;
   out_4191715453033274374[58] = 0.0;
   out_4191715453033274374[59] = 0.0;
   out_4191715453033274374[60] = 0.0;
   out_4191715453033274374[61] = 0.0;
   out_4191715453033274374[62] = 0.0;
   out_4191715453033274374[63] = 0.0;
   out_4191715453033274374[64] = 0.0;
   out_4191715453033274374[65] = 0.0;
   out_4191715453033274374[66] = 0.0;
   out_4191715453033274374[67] = 0.0;
   out_4191715453033274374[68] = 0.0;
   out_4191715453033274374[69] = 0.0;
   out_4191715453033274374[70] = 0.0;
   out_4191715453033274374[71] = 0.0;
   out_4191715453033274374[72] = 0.0;
   out_4191715453033274374[73] = 0.0;
   out_4191715453033274374[74] = 0.0;
   out_4191715453033274374[75] = 0.0;
   out_4191715453033274374[76] = 1.0;
   out_4191715453033274374[77] = 0.0;
   out_4191715453033274374[78] = 0.0;
   out_4191715453033274374[79] = 0.0;
   out_4191715453033274374[80] = 0.0;
   out_4191715453033274374[81] = 0.0;
   out_4191715453033274374[82] = 0.0;
   out_4191715453033274374[83] = 0.0;
   out_4191715453033274374[84] = 0.0;
   out_4191715453033274374[85] = 0.0;
   out_4191715453033274374[86] = 0.0;
   out_4191715453033274374[87] = 0.0;
   out_4191715453033274374[88] = 0.0;
   out_4191715453033274374[89] = 0.0;
   out_4191715453033274374[90] = 0.0;
   out_4191715453033274374[91] = 0.0;
   out_4191715453033274374[92] = 0.0;
   out_4191715453033274374[93] = 0.0;
   out_4191715453033274374[94] = 0.0;
   out_4191715453033274374[95] = 1.0;
   out_4191715453033274374[96] = 0.0;
   out_4191715453033274374[97] = 0.0;
   out_4191715453033274374[98] = 0.0;
   out_4191715453033274374[99] = 0.0;
   out_4191715453033274374[100] = 0.0;
   out_4191715453033274374[101] = 0.0;
   out_4191715453033274374[102] = 0.0;
   out_4191715453033274374[103] = 0.0;
   out_4191715453033274374[104] = 0.0;
   out_4191715453033274374[105] = 0.0;
   out_4191715453033274374[106] = 0.0;
   out_4191715453033274374[107] = 0.0;
   out_4191715453033274374[108] = 0.0;
   out_4191715453033274374[109] = 0.0;
   out_4191715453033274374[110] = 0.0;
   out_4191715453033274374[111] = 0.0;
   out_4191715453033274374[112] = 0.0;
   out_4191715453033274374[113] = 0.0;
   out_4191715453033274374[114] = 1.0;
   out_4191715453033274374[115] = 0.0;
   out_4191715453033274374[116] = 0.0;
   out_4191715453033274374[117] = 0.0;
   out_4191715453033274374[118] = 0.0;
   out_4191715453033274374[119] = 0.0;
   out_4191715453033274374[120] = 0.0;
   out_4191715453033274374[121] = 0.0;
   out_4191715453033274374[122] = 0.0;
   out_4191715453033274374[123] = 0.0;
   out_4191715453033274374[124] = 0.0;
   out_4191715453033274374[125] = 0.0;
   out_4191715453033274374[126] = 0.0;
   out_4191715453033274374[127] = 0.0;
   out_4191715453033274374[128] = 0.0;
   out_4191715453033274374[129] = 0.0;
   out_4191715453033274374[130] = 0.0;
   out_4191715453033274374[131] = 0.0;
   out_4191715453033274374[132] = 0.0;
   out_4191715453033274374[133] = 1.0;
   out_4191715453033274374[134] = 0.0;
   out_4191715453033274374[135] = 0.0;
   out_4191715453033274374[136] = 0.0;
   out_4191715453033274374[137] = 0.0;
   out_4191715453033274374[138] = 0.0;
   out_4191715453033274374[139] = 0.0;
   out_4191715453033274374[140] = 0.0;
   out_4191715453033274374[141] = 0.0;
   out_4191715453033274374[142] = 0.0;
   out_4191715453033274374[143] = 0.0;
   out_4191715453033274374[144] = 0.0;
   out_4191715453033274374[145] = 0.0;
   out_4191715453033274374[146] = 0.0;
   out_4191715453033274374[147] = 0.0;
   out_4191715453033274374[148] = 0.0;
   out_4191715453033274374[149] = 0.0;
   out_4191715453033274374[150] = 0.0;
   out_4191715453033274374[151] = 0.0;
   out_4191715453033274374[152] = 1.0;
   out_4191715453033274374[153] = 0.0;
   out_4191715453033274374[154] = 0.0;
   out_4191715453033274374[155] = 0.0;
   out_4191715453033274374[156] = 0.0;
   out_4191715453033274374[157] = 0.0;
   out_4191715453033274374[158] = 0.0;
   out_4191715453033274374[159] = 0.0;
   out_4191715453033274374[160] = 0.0;
   out_4191715453033274374[161] = 0.0;
   out_4191715453033274374[162] = 0.0;
   out_4191715453033274374[163] = 0.0;
   out_4191715453033274374[164] = 0.0;
   out_4191715453033274374[165] = 0.0;
   out_4191715453033274374[166] = 0.0;
   out_4191715453033274374[167] = 0.0;
   out_4191715453033274374[168] = 0.0;
   out_4191715453033274374[169] = 0.0;
   out_4191715453033274374[170] = 0.0;
   out_4191715453033274374[171] = 1.0;
   out_4191715453033274374[172] = 0.0;
   out_4191715453033274374[173] = 0.0;
   out_4191715453033274374[174] = 0.0;
   out_4191715453033274374[175] = 0.0;
   out_4191715453033274374[176] = 0.0;
   out_4191715453033274374[177] = 0.0;
   out_4191715453033274374[178] = 0.0;
   out_4191715453033274374[179] = 0.0;
   out_4191715453033274374[180] = 0.0;
   out_4191715453033274374[181] = 0.0;
   out_4191715453033274374[182] = 0.0;
   out_4191715453033274374[183] = 0.0;
   out_4191715453033274374[184] = 0.0;
   out_4191715453033274374[185] = 0.0;
   out_4191715453033274374[186] = 0.0;
   out_4191715453033274374[187] = 0.0;
   out_4191715453033274374[188] = 0.0;
   out_4191715453033274374[189] = 0.0;
   out_4191715453033274374[190] = 1.0;
   out_4191715453033274374[191] = 0.0;
   out_4191715453033274374[192] = 0.0;
   out_4191715453033274374[193] = 0.0;
   out_4191715453033274374[194] = 0.0;
   out_4191715453033274374[195] = 0.0;
   out_4191715453033274374[196] = 0.0;
   out_4191715453033274374[197] = 0.0;
   out_4191715453033274374[198] = 0.0;
   out_4191715453033274374[199] = 0.0;
   out_4191715453033274374[200] = 0.0;
   out_4191715453033274374[201] = 0.0;
   out_4191715453033274374[202] = 0.0;
   out_4191715453033274374[203] = 0.0;
   out_4191715453033274374[204] = 0.0;
   out_4191715453033274374[205] = 0.0;
   out_4191715453033274374[206] = 0.0;
   out_4191715453033274374[207] = 0.0;
   out_4191715453033274374[208] = 0.0;
   out_4191715453033274374[209] = 1.0;
   out_4191715453033274374[210] = 0.0;
   out_4191715453033274374[211] = 0.0;
   out_4191715453033274374[212] = 0.0;
   out_4191715453033274374[213] = 0.0;
   out_4191715453033274374[214] = 0.0;
   out_4191715453033274374[215] = 0.0;
   out_4191715453033274374[216] = 0.0;
   out_4191715453033274374[217] = 0.0;
   out_4191715453033274374[218] = 0.0;
   out_4191715453033274374[219] = 0.0;
   out_4191715453033274374[220] = 0.0;
   out_4191715453033274374[221] = 0.0;
   out_4191715453033274374[222] = 0.0;
   out_4191715453033274374[223] = 0.0;
   out_4191715453033274374[224] = 0.0;
   out_4191715453033274374[225] = 0.0;
   out_4191715453033274374[226] = 0.0;
   out_4191715453033274374[227] = 0.0;
   out_4191715453033274374[228] = 1.0;
   out_4191715453033274374[229] = 0.0;
   out_4191715453033274374[230] = 0.0;
   out_4191715453033274374[231] = 0.0;
   out_4191715453033274374[232] = 0.0;
   out_4191715453033274374[233] = 0.0;
   out_4191715453033274374[234] = 0.0;
   out_4191715453033274374[235] = 0.0;
   out_4191715453033274374[236] = 0.0;
   out_4191715453033274374[237] = 0.0;
   out_4191715453033274374[238] = 0.0;
   out_4191715453033274374[239] = 0.0;
   out_4191715453033274374[240] = 0.0;
   out_4191715453033274374[241] = 0.0;
   out_4191715453033274374[242] = 0.0;
   out_4191715453033274374[243] = 0.0;
   out_4191715453033274374[244] = 0.0;
   out_4191715453033274374[245] = 0.0;
   out_4191715453033274374[246] = 0.0;
   out_4191715453033274374[247] = 1.0;
   out_4191715453033274374[248] = 0.0;
   out_4191715453033274374[249] = 0.0;
   out_4191715453033274374[250] = 0.0;
   out_4191715453033274374[251] = 0.0;
   out_4191715453033274374[252] = 0.0;
   out_4191715453033274374[253] = 0.0;
   out_4191715453033274374[254] = 0.0;
   out_4191715453033274374[255] = 0.0;
   out_4191715453033274374[256] = 0.0;
   out_4191715453033274374[257] = 0.0;
   out_4191715453033274374[258] = 0.0;
   out_4191715453033274374[259] = 0.0;
   out_4191715453033274374[260] = 0.0;
   out_4191715453033274374[261] = 0.0;
   out_4191715453033274374[262] = 0.0;
   out_4191715453033274374[263] = 0.0;
   out_4191715453033274374[264] = 0.0;
   out_4191715453033274374[265] = 0.0;
   out_4191715453033274374[266] = 1.0;
   out_4191715453033274374[267] = 0.0;
   out_4191715453033274374[268] = 0.0;
   out_4191715453033274374[269] = 0.0;
   out_4191715453033274374[270] = 0.0;
   out_4191715453033274374[271] = 0.0;
   out_4191715453033274374[272] = 0.0;
   out_4191715453033274374[273] = 0.0;
   out_4191715453033274374[274] = 0.0;
   out_4191715453033274374[275] = 0.0;
   out_4191715453033274374[276] = 0.0;
   out_4191715453033274374[277] = 0.0;
   out_4191715453033274374[278] = 0.0;
   out_4191715453033274374[279] = 0.0;
   out_4191715453033274374[280] = 0.0;
   out_4191715453033274374[281] = 0.0;
   out_4191715453033274374[282] = 0.0;
   out_4191715453033274374[283] = 0.0;
   out_4191715453033274374[284] = 0.0;
   out_4191715453033274374[285] = 1.0;
   out_4191715453033274374[286] = 0.0;
   out_4191715453033274374[287] = 0.0;
   out_4191715453033274374[288] = 0.0;
   out_4191715453033274374[289] = 0.0;
   out_4191715453033274374[290] = 0.0;
   out_4191715453033274374[291] = 0.0;
   out_4191715453033274374[292] = 0.0;
   out_4191715453033274374[293] = 0.0;
   out_4191715453033274374[294] = 0.0;
   out_4191715453033274374[295] = 0.0;
   out_4191715453033274374[296] = 0.0;
   out_4191715453033274374[297] = 0.0;
   out_4191715453033274374[298] = 0.0;
   out_4191715453033274374[299] = 0.0;
   out_4191715453033274374[300] = 0.0;
   out_4191715453033274374[301] = 0.0;
   out_4191715453033274374[302] = 0.0;
   out_4191715453033274374[303] = 0.0;
   out_4191715453033274374[304] = 1.0;
   out_4191715453033274374[305] = 0.0;
   out_4191715453033274374[306] = 0.0;
   out_4191715453033274374[307] = 0.0;
   out_4191715453033274374[308] = 0.0;
   out_4191715453033274374[309] = 0.0;
   out_4191715453033274374[310] = 0.0;
   out_4191715453033274374[311] = 0.0;
   out_4191715453033274374[312] = 0.0;
   out_4191715453033274374[313] = 0.0;
   out_4191715453033274374[314] = 0.0;
   out_4191715453033274374[315] = 0.0;
   out_4191715453033274374[316] = 0.0;
   out_4191715453033274374[317] = 0.0;
   out_4191715453033274374[318] = 0.0;
   out_4191715453033274374[319] = 0.0;
   out_4191715453033274374[320] = 0.0;
   out_4191715453033274374[321] = 0.0;
   out_4191715453033274374[322] = 0.0;
   out_4191715453033274374[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7907487023000628501) {
   out_7907487023000628501[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7907487023000628501[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7907487023000628501[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7907487023000628501[3] = dt*state[12] + state[3];
   out_7907487023000628501[4] = dt*state[13] + state[4];
   out_7907487023000628501[5] = dt*state[14] + state[5];
   out_7907487023000628501[6] = state[6];
   out_7907487023000628501[7] = state[7];
   out_7907487023000628501[8] = state[8];
   out_7907487023000628501[9] = state[9];
   out_7907487023000628501[10] = state[10];
   out_7907487023000628501[11] = state[11];
   out_7907487023000628501[12] = state[12];
   out_7907487023000628501[13] = state[13];
   out_7907487023000628501[14] = state[14];
   out_7907487023000628501[15] = state[15];
   out_7907487023000628501[16] = state[16];
   out_7907487023000628501[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1715083770350127674) {
   out_1715083770350127674[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1715083770350127674[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1715083770350127674[2] = 0;
   out_1715083770350127674[3] = 0;
   out_1715083770350127674[4] = 0;
   out_1715083770350127674[5] = 0;
   out_1715083770350127674[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1715083770350127674[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1715083770350127674[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1715083770350127674[9] = 0;
   out_1715083770350127674[10] = 0;
   out_1715083770350127674[11] = 0;
   out_1715083770350127674[12] = 0;
   out_1715083770350127674[13] = 0;
   out_1715083770350127674[14] = 0;
   out_1715083770350127674[15] = 0;
   out_1715083770350127674[16] = 0;
   out_1715083770350127674[17] = 0;
   out_1715083770350127674[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1715083770350127674[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1715083770350127674[20] = 0;
   out_1715083770350127674[21] = 0;
   out_1715083770350127674[22] = 0;
   out_1715083770350127674[23] = 0;
   out_1715083770350127674[24] = 0;
   out_1715083770350127674[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1715083770350127674[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1715083770350127674[27] = 0;
   out_1715083770350127674[28] = 0;
   out_1715083770350127674[29] = 0;
   out_1715083770350127674[30] = 0;
   out_1715083770350127674[31] = 0;
   out_1715083770350127674[32] = 0;
   out_1715083770350127674[33] = 0;
   out_1715083770350127674[34] = 0;
   out_1715083770350127674[35] = 0;
   out_1715083770350127674[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1715083770350127674[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1715083770350127674[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1715083770350127674[39] = 0;
   out_1715083770350127674[40] = 0;
   out_1715083770350127674[41] = 0;
   out_1715083770350127674[42] = 0;
   out_1715083770350127674[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1715083770350127674[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1715083770350127674[45] = 0;
   out_1715083770350127674[46] = 0;
   out_1715083770350127674[47] = 0;
   out_1715083770350127674[48] = 0;
   out_1715083770350127674[49] = 0;
   out_1715083770350127674[50] = 0;
   out_1715083770350127674[51] = 0;
   out_1715083770350127674[52] = 0;
   out_1715083770350127674[53] = 0;
   out_1715083770350127674[54] = 0;
   out_1715083770350127674[55] = 0;
   out_1715083770350127674[56] = 0;
   out_1715083770350127674[57] = 1;
   out_1715083770350127674[58] = 0;
   out_1715083770350127674[59] = 0;
   out_1715083770350127674[60] = 0;
   out_1715083770350127674[61] = 0;
   out_1715083770350127674[62] = 0;
   out_1715083770350127674[63] = 0;
   out_1715083770350127674[64] = 0;
   out_1715083770350127674[65] = 0;
   out_1715083770350127674[66] = dt;
   out_1715083770350127674[67] = 0;
   out_1715083770350127674[68] = 0;
   out_1715083770350127674[69] = 0;
   out_1715083770350127674[70] = 0;
   out_1715083770350127674[71] = 0;
   out_1715083770350127674[72] = 0;
   out_1715083770350127674[73] = 0;
   out_1715083770350127674[74] = 0;
   out_1715083770350127674[75] = 0;
   out_1715083770350127674[76] = 1;
   out_1715083770350127674[77] = 0;
   out_1715083770350127674[78] = 0;
   out_1715083770350127674[79] = 0;
   out_1715083770350127674[80] = 0;
   out_1715083770350127674[81] = 0;
   out_1715083770350127674[82] = 0;
   out_1715083770350127674[83] = 0;
   out_1715083770350127674[84] = 0;
   out_1715083770350127674[85] = dt;
   out_1715083770350127674[86] = 0;
   out_1715083770350127674[87] = 0;
   out_1715083770350127674[88] = 0;
   out_1715083770350127674[89] = 0;
   out_1715083770350127674[90] = 0;
   out_1715083770350127674[91] = 0;
   out_1715083770350127674[92] = 0;
   out_1715083770350127674[93] = 0;
   out_1715083770350127674[94] = 0;
   out_1715083770350127674[95] = 1;
   out_1715083770350127674[96] = 0;
   out_1715083770350127674[97] = 0;
   out_1715083770350127674[98] = 0;
   out_1715083770350127674[99] = 0;
   out_1715083770350127674[100] = 0;
   out_1715083770350127674[101] = 0;
   out_1715083770350127674[102] = 0;
   out_1715083770350127674[103] = 0;
   out_1715083770350127674[104] = dt;
   out_1715083770350127674[105] = 0;
   out_1715083770350127674[106] = 0;
   out_1715083770350127674[107] = 0;
   out_1715083770350127674[108] = 0;
   out_1715083770350127674[109] = 0;
   out_1715083770350127674[110] = 0;
   out_1715083770350127674[111] = 0;
   out_1715083770350127674[112] = 0;
   out_1715083770350127674[113] = 0;
   out_1715083770350127674[114] = 1;
   out_1715083770350127674[115] = 0;
   out_1715083770350127674[116] = 0;
   out_1715083770350127674[117] = 0;
   out_1715083770350127674[118] = 0;
   out_1715083770350127674[119] = 0;
   out_1715083770350127674[120] = 0;
   out_1715083770350127674[121] = 0;
   out_1715083770350127674[122] = 0;
   out_1715083770350127674[123] = 0;
   out_1715083770350127674[124] = 0;
   out_1715083770350127674[125] = 0;
   out_1715083770350127674[126] = 0;
   out_1715083770350127674[127] = 0;
   out_1715083770350127674[128] = 0;
   out_1715083770350127674[129] = 0;
   out_1715083770350127674[130] = 0;
   out_1715083770350127674[131] = 0;
   out_1715083770350127674[132] = 0;
   out_1715083770350127674[133] = 1;
   out_1715083770350127674[134] = 0;
   out_1715083770350127674[135] = 0;
   out_1715083770350127674[136] = 0;
   out_1715083770350127674[137] = 0;
   out_1715083770350127674[138] = 0;
   out_1715083770350127674[139] = 0;
   out_1715083770350127674[140] = 0;
   out_1715083770350127674[141] = 0;
   out_1715083770350127674[142] = 0;
   out_1715083770350127674[143] = 0;
   out_1715083770350127674[144] = 0;
   out_1715083770350127674[145] = 0;
   out_1715083770350127674[146] = 0;
   out_1715083770350127674[147] = 0;
   out_1715083770350127674[148] = 0;
   out_1715083770350127674[149] = 0;
   out_1715083770350127674[150] = 0;
   out_1715083770350127674[151] = 0;
   out_1715083770350127674[152] = 1;
   out_1715083770350127674[153] = 0;
   out_1715083770350127674[154] = 0;
   out_1715083770350127674[155] = 0;
   out_1715083770350127674[156] = 0;
   out_1715083770350127674[157] = 0;
   out_1715083770350127674[158] = 0;
   out_1715083770350127674[159] = 0;
   out_1715083770350127674[160] = 0;
   out_1715083770350127674[161] = 0;
   out_1715083770350127674[162] = 0;
   out_1715083770350127674[163] = 0;
   out_1715083770350127674[164] = 0;
   out_1715083770350127674[165] = 0;
   out_1715083770350127674[166] = 0;
   out_1715083770350127674[167] = 0;
   out_1715083770350127674[168] = 0;
   out_1715083770350127674[169] = 0;
   out_1715083770350127674[170] = 0;
   out_1715083770350127674[171] = 1;
   out_1715083770350127674[172] = 0;
   out_1715083770350127674[173] = 0;
   out_1715083770350127674[174] = 0;
   out_1715083770350127674[175] = 0;
   out_1715083770350127674[176] = 0;
   out_1715083770350127674[177] = 0;
   out_1715083770350127674[178] = 0;
   out_1715083770350127674[179] = 0;
   out_1715083770350127674[180] = 0;
   out_1715083770350127674[181] = 0;
   out_1715083770350127674[182] = 0;
   out_1715083770350127674[183] = 0;
   out_1715083770350127674[184] = 0;
   out_1715083770350127674[185] = 0;
   out_1715083770350127674[186] = 0;
   out_1715083770350127674[187] = 0;
   out_1715083770350127674[188] = 0;
   out_1715083770350127674[189] = 0;
   out_1715083770350127674[190] = 1;
   out_1715083770350127674[191] = 0;
   out_1715083770350127674[192] = 0;
   out_1715083770350127674[193] = 0;
   out_1715083770350127674[194] = 0;
   out_1715083770350127674[195] = 0;
   out_1715083770350127674[196] = 0;
   out_1715083770350127674[197] = 0;
   out_1715083770350127674[198] = 0;
   out_1715083770350127674[199] = 0;
   out_1715083770350127674[200] = 0;
   out_1715083770350127674[201] = 0;
   out_1715083770350127674[202] = 0;
   out_1715083770350127674[203] = 0;
   out_1715083770350127674[204] = 0;
   out_1715083770350127674[205] = 0;
   out_1715083770350127674[206] = 0;
   out_1715083770350127674[207] = 0;
   out_1715083770350127674[208] = 0;
   out_1715083770350127674[209] = 1;
   out_1715083770350127674[210] = 0;
   out_1715083770350127674[211] = 0;
   out_1715083770350127674[212] = 0;
   out_1715083770350127674[213] = 0;
   out_1715083770350127674[214] = 0;
   out_1715083770350127674[215] = 0;
   out_1715083770350127674[216] = 0;
   out_1715083770350127674[217] = 0;
   out_1715083770350127674[218] = 0;
   out_1715083770350127674[219] = 0;
   out_1715083770350127674[220] = 0;
   out_1715083770350127674[221] = 0;
   out_1715083770350127674[222] = 0;
   out_1715083770350127674[223] = 0;
   out_1715083770350127674[224] = 0;
   out_1715083770350127674[225] = 0;
   out_1715083770350127674[226] = 0;
   out_1715083770350127674[227] = 0;
   out_1715083770350127674[228] = 1;
   out_1715083770350127674[229] = 0;
   out_1715083770350127674[230] = 0;
   out_1715083770350127674[231] = 0;
   out_1715083770350127674[232] = 0;
   out_1715083770350127674[233] = 0;
   out_1715083770350127674[234] = 0;
   out_1715083770350127674[235] = 0;
   out_1715083770350127674[236] = 0;
   out_1715083770350127674[237] = 0;
   out_1715083770350127674[238] = 0;
   out_1715083770350127674[239] = 0;
   out_1715083770350127674[240] = 0;
   out_1715083770350127674[241] = 0;
   out_1715083770350127674[242] = 0;
   out_1715083770350127674[243] = 0;
   out_1715083770350127674[244] = 0;
   out_1715083770350127674[245] = 0;
   out_1715083770350127674[246] = 0;
   out_1715083770350127674[247] = 1;
   out_1715083770350127674[248] = 0;
   out_1715083770350127674[249] = 0;
   out_1715083770350127674[250] = 0;
   out_1715083770350127674[251] = 0;
   out_1715083770350127674[252] = 0;
   out_1715083770350127674[253] = 0;
   out_1715083770350127674[254] = 0;
   out_1715083770350127674[255] = 0;
   out_1715083770350127674[256] = 0;
   out_1715083770350127674[257] = 0;
   out_1715083770350127674[258] = 0;
   out_1715083770350127674[259] = 0;
   out_1715083770350127674[260] = 0;
   out_1715083770350127674[261] = 0;
   out_1715083770350127674[262] = 0;
   out_1715083770350127674[263] = 0;
   out_1715083770350127674[264] = 0;
   out_1715083770350127674[265] = 0;
   out_1715083770350127674[266] = 1;
   out_1715083770350127674[267] = 0;
   out_1715083770350127674[268] = 0;
   out_1715083770350127674[269] = 0;
   out_1715083770350127674[270] = 0;
   out_1715083770350127674[271] = 0;
   out_1715083770350127674[272] = 0;
   out_1715083770350127674[273] = 0;
   out_1715083770350127674[274] = 0;
   out_1715083770350127674[275] = 0;
   out_1715083770350127674[276] = 0;
   out_1715083770350127674[277] = 0;
   out_1715083770350127674[278] = 0;
   out_1715083770350127674[279] = 0;
   out_1715083770350127674[280] = 0;
   out_1715083770350127674[281] = 0;
   out_1715083770350127674[282] = 0;
   out_1715083770350127674[283] = 0;
   out_1715083770350127674[284] = 0;
   out_1715083770350127674[285] = 1;
   out_1715083770350127674[286] = 0;
   out_1715083770350127674[287] = 0;
   out_1715083770350127674[288] = 0;
   out_1715083770350127674[289] = 0;
   out_1715083770350127674[290] = 0;
   out_1715083770350127674[291] = 0;
   out_1715083770350127674[292] = 0;
   out_1715083770350127674[293] = 0;
   out_1715083770350127674[294] = 0;
   out_1715083770350127674[295] = 0;
   out_1715083770350127674[296] = 0;
   out_1715083770350127674[297] = 0;
   out_1715083770350127674[298] = 0;
   out_1715083770350127674[299] = 0;
   out_1715083770350127674[300] = 0;
   out_1715083770350127674[301] = 0;
   out_1715083770350127674[302] = 0;
   out_1715083770350127674[303] = 0;
   out_1715083770350127674[304] = 1;
   out_1715083770350127674[305] = 0;
   out_1715083770350127674[306] = 0;
   out_1715083770350127674[307] = 0;
   out_1715083770350127674[308] = 0;
   out_1715083770350127674[309] = 0;
   out_1715083770350127674[310] = 0;
   out_1715083770350127674[311] = 0;
   out_1715083770350127674[312] = 0;
   out_1715083770350127674[313] = 0;
   out_1715083770350127674[314] = 0;
   out_1715083770350127674[315] = 0;
   out_1715083770350127674[316] = 0;
   out_1715083770350127674[317] = 0;
   out_1715083770350127674[318] = 0;
   out_1715083770350127674[319] = 0;
   out_1715083770350127674[320] = 0;
   out_1715083770350127674[321] = 0;
   out_1715083770350127674[322] = 0;
   out_1715083770350127674[323] = 1;
}
void h_4(double *state, double *unused, double *out_6882480817021255843) {
   out_6882480817021255843[0] = state[6] + state[9];
   out_6882480817021255843[1] = state[7] + state[10];
   out_6882480817021255843[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3437554450978561767) {
   out_3437554450978561767[0] = 0;
   out_3437554450978561767[1] = 0;
   out_3437554450978561767[2] = 0;
   out_3437554450978561767[3] = 0;
   out_3437554450978561767[4] = 0;
   out_3437554450978561767[5] = 0;
   out_3437554450978561767[6] = 1;
   out_3437554450978561767[7] = 0;
   out_3437554450978561767[8] = 0;
   out_3437554450978561767[9] = 1;
   out_3437554450978561767[10] = 0;
   out_3437554450978561767[11] = 0;
   out_3437554450978561767[12] = 0;
   out_3437554450978561767[13] = 0;
   out_3437554450978561767[14] = 0;
   out_3437554450978561767[15] = 0;
   out_3437554450978561767[16] = 0;
   out_3437554450978561767[17] = 0;
   out_3437554450978561767[18] = 0;
   out_3437554450978561767[19] = 0;
   out_3437554450978561767[20] = 0;
   out_3437554450978561767[21] = 0;
   out_3437554450978561767[22] = 0;
   out_3437554450978561767[23] = 0;
   out_3437554450978561767[24] = 0;
   out_3437554450978561767[25] = 1;
   out_3437554450978561767[26] = 0;
   out_3437554450978561767[27] = 0;
   out_3437554450978561767[28] = 1;
   out_3437554450978561767[29] = 0;
   out_3437554450978561767[30] = 0;
   out_3437554450978561767[31] = 0;
   out_3437554450978561767[32] = 0;
   out_3437554450978561767[33] = 0;
   out_3437554450978561767[34] = 0;
   out_3437554450978561767[35] = 0;
   out_3437554450978561767[36] = 0;
   out_3437554450978561767[37] = 0;
   out_3437554450978561767[38] = 0;
   out_3437554450978561767[39] = 0;
   out_3437554450978561767[40] = 0;
   out_3437554450978561767[41] = 0;
   out_3437554450978561767[42] = 0;
   out_3437554450978561767[43] = 0;
   out_3437554450978561767[44] = 1;
   out_3437554450978561767[45] = 0;
   out_3437554450978561767[46] = 0;
   out_3437554450978561767[47] = 1;
   out_3437554450978561767[48] = 0;
   out_3437554450978561767[49] = 0;
   out_3437554450978561767[50] = 0;
   out_3437554450978561767[51] = 0;
   out_3437554450978561767[52] = 0;
   out_3437554450978561767[53] = 0;
}
void h_10(double *state, double *unused, double *out_1643725073239354950) {
   out_1643725073239354950[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1643725073239354950[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1643725073239354950[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5699037409662724186) {
   out_5699037409662724186[0] = 0;
   out_5699037409662724186[1] = 9.8100000000000005*cos(state[1]);
   out_5699037409662724186[2] = 0;
   out_5699037409662724186[3] = 0;
   out_5699037409662724186[4] = -state[8];
   out_5699037409662724186[5] = state[7];
   out_5699037409662724186[6] = 0;
   out_5699037409662724186[7] = state[5];
   out_5699037409662724186[8] = -state[4];
   out_5699037409662724186[9] = 0;
   out_5699037409662724186[10] = 0;
   out_5699037409662724186[11] = 0;
   out_5699037409662724186[12] = 1;
   out_5699037409662724186[13] = 0;
   out_5699037409662724186[14] = 0;
   out_5699037409662724186[15] = 1;
   out_5699037409662724186[16] = 0;
   out_5699037409662724186[17] = 0;
   out_5699037409662724186[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5699037409662724186[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5699037409662724186[20] = 0;
   out_5699037409662724186[21] = state[8];
   out_5699037409662724186[22] = 0;
   out_5699037409662724186[23] = -state[6];
   out_5699037409662724186[24] = -state[5];
   out_5699037409662724186[25] = 0;
   out_5699037409662724186[26] = state[3];
   out_5699037409662724186[27] = 0;
   out_5699037409662724186[28] = 0;
   out_5699037409662724186[29] = 0;
   out_5699037409662724186[30] = 0;
   out_5699037409662724186[31] = 1;
   out_5699037409662724186[32] = 0;
   out_5699037409662724186[33] = 0;
   out_5699037409662724186[34] = 1;
   out_5699037409662724186[35] = 0;
   out_5699037409662724186[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5699037409662724186[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5699037409662724186[38] = 0;
   out_5699037409662724186[39] = -state[7];
   out_5699037409662724186[40] = state[6];
   out_5699037409662724186[41] = 0;
   out_5699037409662724186[42] = state[4];
   out_5699037409662724186[43] = -state[3];
   out_5699037409662724186[44] = 0;
   out_5699037409662724186[45] = 0;
   out_5699037409662724186[46] = 0;
   out_5699037409662724186[47] = 0;
   out_5699037409662724186[48] = 0;
   out_5699037409662724186[49] = 0;
   out_5699037409662724186[50] = 1;
   out_5699037409662724186[51] = 0;
   out_5699037409662724186[52] = 0;
   out_5699037409662724186[53] = 1;
}
void h_13(double *state, double *unused, double *out_1956402051470484468) {
   out_1956402051470484468[0] = state[3];
   out_1956402051470484468[1] = state[4];
   out_1956402051470484468[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4173076757338139162) {
   out_4173076757338139162[0] = 0;
   out_4173076757338139162[1] = 0;
   out_4173076757338139162[2] = 0;
   out_4173076757338139162[3] = 1;
   out_4173076757338139162[4] = 0;
   out_4173076757338139162[5] = 0;
   out_4173076757338139162[6] = 0;
   out_4173076757338139162[7] = 0;
   out_4173076757338139162[8] = 0;
   out_4173076757338139162[9] = 0;
   out_4173076757338139162[10] = 0;
   out_4173076757338139162[11] = 0;
   out_4173076757338139162[12] = 0;
   out_4173076757338139162[13] = 0;
   out_4173076757338139162[14] = 0;
   out_4173076757338139162[15] = 0;
   out_4173076757338139162[16] = 0;
   out_4173076757338139162[17] = 0;
   out_4173076757338139162[18] = 0;
   out_4173076757338139162[19] = 0;
   out_4173076757338139162[20] = 0;
   out_4173076757338139162[21] = 0;
   out_4173076757338139162[22] = 1;
   out_4173076757338139162[23] = 0;
   out_4173076757338139162[24] = 0;
   out_4173076757338139162[25] = 0;
   out_4173076757338139162[26] = 0;
   out_4173076757338139162[27] = 0;
   out_4173076757338139162[28] = 0;
   out_4173076757338139162[29] = 0;
   out_4173076757338139162[30] = 0;
   out_4173076757338139162[31] = 0;
   out_4173076757338139162[32] = 0;
   out_4173076757338139162[33] = 0;
   out_4173076757338139162[34] = 0;
   out_4173076757338139162[35] = 0;
   out_4173076757338139162[36] = 0;
   out_4173076757338139162[37] = 0;
   out_4173076757338139162[38] = 0;
   out_4173076757338139162[39] = 0;
   out_4173076757338139162[40] = 0;
   out_4173076757338139162[41] = 1;
   out_4173076757338139162[42] = 0;
   out_4173076757338139162[43] = 0;
   out_4173076757338139162[44] = 0;
   out_4173076757338139162[45] = 0;
   out_4173076757338139162[46] = 0;
   out_4173076757338139162[47] = 0;
   out_4173076757338139162[48] = 0;
   out_4173076757338139162[49] = 0;
   out_4173076757338139162[50] = 0;
   out_4173076757338139162[51] = 0;
   out_4173076757338139162[52] = 0;
   out_4173076757338139162[53] = 0;
}
void h_14(double *state, double *unused, double *out_4352481585600692322) {
   out_4352481585600692322[0] = state[6];
   out_4352481585600692322[1] = state[7];
   out_4352481585600692322[2] = state[8];
}
void H_14(double *state, double *unused, double *out_525686405360922762) {
   out_525686405360922762[0] = 0;
   out_525686405360922762[1] = 0;
   out_525686405360922762[2] = 0;
   out_525686405360922762[3] = 0;
   out_525686405360922762[4] = 0;
   out_525686405360922762[5] = 0;
   out_525686405360922762[6] = 1;
   out_525686405360922762[7] = 0;
   out_525686405360922762[8] = 0;
   out_525686405360922762[9] = 0;
   out_525686405360922762[10] = 0;
   out_525686405360922762[11] = 0;
   out_525686405360922762[12] = 0;
   out_525686405360922762[13] = 0;
   out_525686405360922762[14] = 0;
   out_525686405360922762[15] = 0;
   out_525686405360922762[16] = 0;
   out_525686405360922762[17] = 0;
   out_525686405360922762[18] = 0;
   out_525686405360922762[19] = 0;
   out_525686405360922762[20] = 0;
   out_525686405360922762[21] = 0;
   out_525686405360922762[22] = 0;
   out_525686405360922762[23] = 0;
   out_525686405360922762[24] = 0;
   out_525686405360922762[25] = 1;
   out_525686405360922762[26] = 0;
   out_525686405360922762[27] = 0;
   out_525686405360922762[28] = 0;
   out_525686405360922762[29] = 0;
   out_525686405360922762[30] = 0;
   out_525686405360922762[31] = 0;
   out_525686405360922762[32] = 0;
   out_525686405360922762[33] = 0;
   out_525686405360922762[34] = 0;
   out_525686405360922762[35] = 0;
   out_525686405360922762[36] = 0;
   out_525686405360922762[37] = 0;
   out_525686405360922762[38] = 0;
   out_525686405360922762[39] = 0;
   out_525686405360922762[40] = 0;
   out_525686405360922762[41] = 0;
   out_525686405360922762[42] = 0;
   out_525686405360922762[43] = 0;
   out_525686405360922762[44] = 1;
   out_525686405360922762[45] = 0;
   out_525686405360922762[46] = 0;
   out_525686405360922762[47] = 0;
   out_525686405360922762[48] = 0;
   out_525686405360922762[49] = 0;
   out_525686405360922762[50] = 0;
   out_525686405360922762[51] = 0;
   out_525686405360922762[52] = 0;
   out_525686405360922762[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_162071913396464737) {
  err_fun(nom_x, delta_x, out_162071913396464737);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3928897807539259508) {
  inv_err_fun(nom_x, true_x, out_3928897807539259508);
}
void pose_H_mod_fun(double *state, double *out_4191715453033274374) {
  H_mod_fun(state, out_4191715453033274374);
}
void pose_f_fun(double *state, double dt, double *out_7907487023000628501) {
  f_fun(state,  dt, out_7907487023000628501);
}
void pose_F_fun(double *state, double dt, double *out_1715083770350127674) {
  F_fun(state,  dt, out_1715083770350127674);
}
void pose_h_4(double *state, double *unused, double *out_6882480817021255843) {
  h_4(state, unused, out_6882480817021255843);
}
void pose_H_4(double *state, double *unused, double *out_3437554450978561767) {
  H_4(state, unused, out_3437554450978561767);
}
void pose_h_10(double *state, double *unused, double *out_1643725073239354950) {
  h_10(state, unused, out_1643725073239354950);
}
void pose_H_10(double *state, double *unused, double *out_5699037409662724186) {
  H_10(state, unused, out_5699037409662724186);
}
void pose_h_13(double *state, double *unused, double *out_1956402051470484468) {
  h_13(state, unused, out_1956402051470484468);
}
void pose_H_13(double *state, double *unused, double *out_4173076757338139162) {
  H_13(state, unused, out_4173076757338139162);
}
void pose_h_14(double *state, double *unused, double *out_4352481585600692322) {
  h_14(state, unused, out_4352481585600692322);
}
void pose_H_14(double *state, double *unused, double *out_525686405360922762) {
  H_14(state, unused, out_525686405360922762);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
