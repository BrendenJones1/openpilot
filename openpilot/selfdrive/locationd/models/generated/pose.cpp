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
void err_fun(double *nom_x, double *delta_x, double *out_1893066262074101492) {
   out_1893066262074101492[0] = delta_x[0] + nom_x[0];
   out_1893066262074101492[1] = delta_x[1] + nom_x[1];
   out_1893066262074101492[2] = delta_x[2] + nom_x[2];
   out_1893066262074101492[3] = delta_x[3] + nom_x[3];
   out_1893066262074101492[4] = delta_x[4] + nom_x[4];
   out_1893066262074101492[5] = delta_x[5] + nom_x[5];
   out_1893066262074101492[6] = delta_x[6] + nom_x[6];
   out_1893066262074101492[7] = delta_x[7] + nom_x[7];
   out_1893066262074101492[8] = delta_x[8] + nom_x[8];
   out_1893066262074101492[9] = delta_x[9] + nom_x[9];
   out_1893066262074101492[10] = delta_x[10] + nom_x[10];
   out_1893066262074101492[11] = delta_x[11] + nom_x[11];
   out_1893066262074101492[12] = delta_x[12] + nom_x[12];
   out_1893066262074101492[13] = delta_x[13] + nom_x[13];
   out_1893066262074101492[14] = delta_x[14] + nom_x[14];
   out_1893066262074101492[15] = delta_x[15] + nom_x[15];
   out_1893066262074101492[16] = delta_x[16] + nom_x[16];
   out_1893066262074101492[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5108622378397263891) {
   out_5108622378397263891[0] = -nom_x[0] + true_x[0];
   out_5108622378397263891[1] = -nom_x[1] + true_x[1];
   out_5108622378397263891[2] = -nom_x[2] + true_x[2];
   out_5108622378397263891[3] = -nom_x[3] + true_x[3];
   out_5108622378397263891[4] = -nom_x[4] + true_x[4];
   out_5108622378397263891[5] = -nom_x[5] + true_x[5];
   out_5108622378397263891[6] = -nom_x[6] + true_x[6];
   out_5108622378397263891[7] = -nom_x[7] + true_x[7];
   out_5108622378397263891[8] = -nom_x[8] + true_x[8];
   out_5108622378397263891[9] = -nom_x[9] + true_x[9];
   out_5108622378397263891[10] = -nom_x[10] + true_x[10];
   out_5108622378397263891[11] = -nom_x[11] + true_x[11];
   out_5108622378397263891[12] = -nom_x[12] + true_x[12];
   out_5108622378397263891[13] = -nom_x[13] + true_x[13];
   out_5108622378397263891[14] = -nom_x[14] + true_x[14];
   out_5108622378397263891[15] = -nom_x[15] + true_x[15];
   out_5108622378397263891[16] = -nom_x[16] + true_x[16];
   out_5108622378397263891[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8501408524920025174) {
   out_8501408524920025174[0] = 1.0;
   out_8501408524920025174[1] = 0.0;
   out_8501408524920025174[2] = 0.0;
   out_8501408524920025174[3] = 0.0;
   out_8501408524920025174[4] = 0.0;
   out_8501408524920025174[5] = 0.0;
   out_8501408524920025174[6] = 0.0;
   out_8501408524920025174[7] = 0.0;
   out_8501408524920025174[8] = 0.0;
   out_8501408524920025174[9] = 0.0;
   out_8501408524920025174[10] = 0.0;
   out_8501408524920025174[11] = 0.0;
   out_8501408524920025174[12] = 0.0;
   out_8501408524920025174[13] = 0.0;
   out_8501408524920025174[14] = 0.0;
   out_8501408524920025174[15] = 0.0;
   out_8501408524920025174[16] = 0.0;
   out_8501408524920025174[17] = 0.0;
   out_8501408524920025174[18] = 0.0;
   out_8501408524920025174[19] = 1.0;
   out_8501408524920025174[20] = 0.0;
   out_8501408524920025174[21] = 0.0;
   out_8501408524920025174[22] = 0.0;
   out_8501408524920025174[23] = 0.0;
   out_8501408524920025174[24] = 0.0;
   out_8501408524920025174[25] = 0.0;
   out_8501408524920025174[26] = 0.0;
   out_8501408524920025174[27] = 0.0;
   out_8501408524920025174[28] = 0.0;
   out_8501408524920025174[29] = 0.0;
   out_8501408524920025174[30] = 0.0;
   out_8501408524920025174[31] = 0.0;
   out_8501408524920025174[32] = 0.0;
   out_8501408524920025174[33] = 0.0;
   out_8501408524920025174[34] = 0.0;
   out_8501408524920025174[35] = 0.0;
   out_8501408524920025174[36] = 0.0;
   out_8501408524920025174[37] = 0.0;
   out_8501408524920025174[38] = 1.0;
   out_8501408524920025174[39] = 0.0;
   out_8501408524920025174[40] = 0.0;
   out_8501408524920025174[41] = 0.0;
   out_8501408524920025174[42] = 0.0;
   out_8501408524920025174[43] = 0.0;
   out_8501408524920025174[44] = 0.0;
   out_8501408524920025174[45] = 0.0;
   out_8501408524920025174[46] = 0.0;
   out_8501408524920025174[47] = 0.0;
   out_8501408524920025174[48] = 0.0;
   out_8501408524920025174[49] = 0.0;
   out_8501408524920025174[50] = 0.0;
   out_8501408524920025174[51] = 0.0;
   out_8501408524920025174[52] = 0.0;
   out_8501408524920025174[53] = 0.0;
   out_8501408524920025174[54] = 0.0;
   out_8501408524920025174[55] = 0.0;
   out_8501408524920025174[56] = 0.0;
   out_8501408524920025174[57] = 1.0;
   out_8501408524920025174[58] = 0.0;
   out_8501408524920025174[59] = 0.0;
   out_8501408524920025174[60] = 0.0;
   out_8501408524920025174[61] = 0.0;
   out_8501408524920025174[62] = 0.0;
   out_8501408524920025174[63] = 0.0;
   out_8501408524920025174[64] = 0.0;
   out_8501408524920025174[65] = 0.0;
   out_8501408524920025174[66] = 0.0;
   out_8501408524920025174[67] = 0.0;
   out_8501408524920025174[68] = 0.0;
   out_8501408524920025174[69] = 0.0;
   out_8501408524920025174[70] = 0.0;
   out_8501408524920025174[71] = 0.0;
   out_8501408524920025174[72] = 0.0;
   out_8501408524920025174[73] = 0.0;
   out_8501408524920025174[74] = 0.0;
   out_8501408524920025174[75] = 0.0;
   out_8501408524920025174[76] = 1.0;
   out_8501408524920025174[77] = 0.0;
   out_8501408524920025174[78] = 0.0;
   out_8501408524920025174[79] = 0.0;
   out_8501408524920025174[80] = 0.0;
   out_8501408524920025174[81] = 0.0;
   out_8501408524920025174[82] = 0.0;
   out_8501408524920025174[83] = 0.0;
   out_8501408524920025174[84] = 0.0;
   out_8501408524920025174[85] = 0.0;
   out_8501408524920025174[86] = 0.0;
   out_8501408524920025174[87] = 0.0;
   out_8501408524920025174[88] = 0.0;
   out_8501408524920025174[89] = 0.0;
   out_8501408524920025174[90] = 0.0;
   out_8501408524920025174[91] = 0.0;
   out_8501408524920025174[92] = 0.0;
   out_8501408524920025174[93] = 0.0;
   out_8501408524920025174[94] = 0.0;
   out_8501408524920025174[95] = 1.0;
   out_8501408524920025174[96] = 0.0;
   out_8501408524920025174[97] = 0.0;
   out_8501408524920025174[98] = 0.0;
   out_8501408524920025174[99] = 0.0;
   out_8501408524920025174[100] = 0.0;
   out_8501408524920025174[101] = 0.0;
   out_8501408524920025174[102] = 0.0;
   out_8501408524920025174[103] = 0.0;
   out_8501408524920025174[104] = 0.0;
   out_8501408524920025174[105] = 0.0;
   out_8501408524920025174[106] = 0.0;
   out_8501408524920025174[107] = 0.0;
   out_8501408524920025174[108] = 0.0;
   out_8501408524920025174[109] = 0.0;
   out_8501408524920025174[110] = 0.0;
   out_8501408524920025174[111] = 0.0;
   out_8501408524920025174[112] = 0.0;
   out_8501408524920025174[113] = 0.0;
   out_8501408524920025174[114] = 1.0;
   out_8501408524920025174[115] = 0.0;
   out_8501408524920025174[116] = 0.0;
   out_8501408524920025174[117] = 0.0;
   out_8501408524920025174[118] = 0.0;
   out_8501408524920025174[119] = 0.0;
   out_8501408524920025174[120] = 0.0;
   out_8501408524920025174[121] = 0.0;
   out_8501408524920025174[122] = 0.0;
   out_8501408524920025174[123] = 0.0;
   out_8501408524920025174[124] = 0.0;
   out_8501408524920025174[125] = 0.0;
   out_8501408524920025174[126] = 0.0;
   out_8501408524920025174[127] = 0.0;
   out_8501408524920025174[128] = 0.0;
   out_8501408524920025174[129] = 0.0;
   out_8501408524920025174[130] = 0.0;
   out_8501408524920025174[131] = 0.0;
   out_8501408524920025174[132] = 0.0;
   out_8501408524920025174[133] = 1.0;
   out_8501408524920025174[134] = 0.0;
   out_8501408524920025174[135] = 0.0;
   out_8501408524920025174[136] = 0.0;
   out_8501408524920025174[137] = 0.0;
   out_8501408524920025174[138] = 0.0;
   out_8501408524920025174[139] = 0.0;
   out_8501408524920025174[140] = 0.0;
   out_8501408524920025174[141] = 0.0;
   out_8501408524920025174[142] = 0.0;
   out_8501408524920025174[143] = 0.0;
   out_8501408524920025174[144] = 0.0;
   out_8501408524920025174[145] = 0.0;
   out_8501408524920025174[146] = 0.0;
   out_8501408524920025174[147] = 0.0;
   out_8501408524920025174[148] = 0.0;
   out_8501408524920025174[149] = 0.0;
   out_8501408524920025174[150] = 0.0;
   out_8501408524920025174[151] = 0.0;
   out_8501408524920025174[152] = 1.0;
   out_8501408524920025174[153] = 0.0;
   out_8501408524920025174[154] = 0.0;
   out_8501408524920025174[155] = 0.0;
   out_8501408524920025174[156] = 0.0;
   out_8501408524920025174[157] = 0.0;
   out_8501408524920025174[158] = 0.0;
   out_8501408524920025174[159] = 0.0;
   out_8501408524920025174[160] = 0.0;
   out_8501408524920025174[161] = 0.0;
   out_8501408524920025174[162] = 0.0;
   out_8501408524920025174[163] = 0.0;
   out_8501408524920025174[164] = 0.0;
   out_8501408524920025174[165] = 0.0;
   out_8501408524920025174[166] = 0.0;
   out_8501408524920025174[167] = 0.0;
   out_8501408524920025174[168] = 0.0;
   out_8501408524920025174[169] = 0.0;
   out_8501408524920025174[170] = 0.0;
   out_8501408524920025174[171] = 1.0;
   out_8501408524920025174[172] = 0.0;
   out_8501408524920025174[173] = 0.0;
   out_8501408524920025174[174] = 0.0;
   out_8501408524920025174[175] = 0.0;
   out_8501408524920025174[176] = 0.0;
   out_8501408524920025174[177] = 0.0;
   out_8501408524920025174[178] = 0.0;
   out_8501408524920025174[179] = 0.0;
   out_8501408524920025174[180] = 0.0;
   out_8501408524920025174[181] = 0.0;
   out_8501408524920025174[182] = 0.0;
   out_8501408524920025174[183] = 0.0;
   out_8501408524920025174[184] = 0.0;
   out_8501408524920025174[185] = 0.0;
   out_8501408524920025174[186] = 0.0;
   out_8501408524920025174[187] = 0.0;
   out_8501408524920025174[188] = 0.0;
   out_8501408524920025174[189] = 0.0;
   out_8501408524920025174[190] = 1.0;
   out_8501408524920025174[191] = 0.0;
   out_8501408524920025174[192] = 0.0;
   out_8501408524920025174[193] = 0.0;
   out_8501408524920025174[194] = 0.0;
   out_8501408524920025174[195] = 0.0;
   out_8501408524920025174[196] = 0.0;
   out_8501408524920025174[197] = 0.0;
   out_8501408524920025174[198] = 0.0;
   out_8501408524920025174[199] = 0.0;
   out_8501408524920025174[200] = 0.0;
   out_8501408524920025174[201] = 0.0;
   out_8501408524920025174[202] = 0.0;
   out_8501408524920025174[203] = 0.0;
   out_8501408524920025174[204] = 0.0;
   out_8501408524920025174[205] = 0.0;
   out_8501408524920025174[206] = 0.0;
   out_8501408524920025174[207] = 0.0;
   out_8501408524920025174[208] = 0.0;
   out_8501408524920025174[209] = 1.0;
   out_8501408524920025174[210] = 0.0;
   out_8501408524920025174[211] = 0.0;
   out_8501408524920025174[212] = 0.0;
   out_8501408524920025174[213] = 0.0;
   out_8501408524920025174[214] = 0.0;
   out_8501408524920025174[215] = 0.0;
   out_8501408524920025174[216] = 0.0;
   out_8501408524920025174[217] = 0.0;
   out_8501408524920025174[218] = 0.0;
   out_8501408524920025174[219] = 0.0;
   out_8501408524920025174[220] = 0.0;
   out_8501408524920025174[221] = 0.0;
   out_8501408524920025174[222] = 0.0;
   out_8501408524920025174[223] = 0.0;
   out_8501408524920025174[224] = 0.0;
   out_8501408524920025174[225] = 0.0;
   out_8501408524920025174[226] = 0.0;
   out_8501408524920025174[227] = 0.0;
   out_8501408524920025174[228] = 1.0;
   out_8501408524920025174[229] = 0.0;
   out_8501408524920025174[230] = 0.0;
   out_8501408524920025174[231] = 0.0;
   out_8501408524920025174[232] = 0.0;
   out_8501408524920025174[233] = 0.0;
   out_8501408524920025174[234] = 0.0;
   out_8501408524920025174[235] = 0.0;
   out_8501408524920025174[236] = 0.0;
   out_8501408524920025174[237] = 0.0;
   out_8501408524920025174[238] = 0.0;
   out_8501408524920025174[239] = 0.0;
   out_8501408524920025174[240] = 0.0;
   out_8501408524920025174[241] = 0.0;
   out_8501408524920025174[242] = 0.0;
   out_8501408524920025174[243] = 0.0;
   out_8501408524920025174[244] = 0.0;
   out_8501408524920025174[245] = 0.0;
   out_8501408524920025174[246] = 0.0;
   out_8501408524920025174[247] = 1.0;
   out_8501408524920025174[248] = 0.0;
   out_8501408524920025174[249] = 0.0;
   out_8501408524920025174[250] = 0.0;
   out_8501408524920025174[251] = 0.0;
   out_8501408524920025174[252] = 0.0;
   out_8501408524920025174[253] = 0.0;
   out_8501408524920025174[254] = 0.0;
   out_8501408524920025174[255] = 0.0;
   out_8501408524920025174[256] = 0.0;
   out_8501408524920025174[257] = 0.0;
   out_8501408524920025174[258] = 0.0;
   out_8501408524920025174[259] = 0.0;
   out_8501408524920025174[260] = 0.0;
   out_8501408524920025174[261] = 0.0;
   out_8501408524920025174[262] = 0.0;
   out_8501408524920025174[263] = 0.0;
   out_8501408524920025174[264] = 0.0;
   out_8501408524920025174[265] = 0.0;
   out_8501408524920025174[266] = 1.0;
   out_8501408524920025174[267] = 0.0;
   out_8501408524920025174[268] = 0.0;
   out_8501408524920025174[269] = 0.0;
   out_8501408524920025174[270] = 0.0;
   out_8501408524920025174[271] = 0.0;
   out_8501408524920025174[272] = 0.0;
   out_8501408524920025174[273] = 0.0;
   out_8501408524920025174[274] = 0.0;
   out_8501408524920025174[275] = 0.0;
   out_8501408524920025174[276] = 0.0;
   out_8501408524920025174[277] = 0.0;
   out_8501408524920025174[278] = 0.0;
   out_8501408524920025174[279] = 0.0;
   out_8501408524920025174[280] = 0.0;
   out_8501408524920025174[281] = 0.0;
   out_8501408524920025174[282] = 0.0;
   out_8501408524920025174[283] = 0.0;
   out_8501408524920025174[284] = 0.0;
   out_8501408524920025174[285] = 1.0;
   out_8501408524920025174[286] = 0.0;
   out_8501408524920025174[287] = 0.0;
   out_8501408524920025174[288] = 0.0;
   out_8501408524920025174[289] = 0.0;
   out_8501408524920025174[290] = 0.0;
   out_8501408524920025174[291] = 0.0;
   out_8501408524920025174[292] = 0.0;
   out_8501408524920025174[293] = 0.0;
   out_8501408524920025174[294] = 0.0;
   out_8501408524920025174[295] = 0.0;
   out_8501408524920025174[296] = 0.0;
   out_8501408524920025174[297] = 0.0;
   out_8501408524920025174[298] = 0.0;
   out_8501408524920025174[299] = 0.0;
   out_8501408524920025174[300] = 0.0;
   out_8501408524920025174[301] = 0.0;
   out_8501408524920025174[302] = 0.0;
   out_8501408524920025174[303] = 0.0;
   out_8501408524920025174[304] = 1.0;
   out_8501408524920025174[305] = 0.0;
   out_8501408524920025174[306] = 0.0;
   out_8501408524920025174[307] = 0.0;
   out_8501408524920025174[308] = 0.0;
   out_8501408524920025174[309] = 0.0;
   out_8501408524920025174[310] = 0.0;
   out_8501408524920025174[311] = 0.0;
   out_8501408524920025174[312] = 0.0;
   out_8501408524920025174[313] = 0.0;
   out_8501408524920025174[314] = 0.0;
   out_8501408524920025174[315] = 0.0;
   out_8501408524920025174[316] = 0.0;
   out_8501408524920025174[317] = 0.0;
   out_8501408524920025174[318] = 0.0;
   out_8501408524920025174[319] = 0.0;
   out_8501408524920025174[320] = 0.0;
   out_8501408524920025174[321] = 0.0;
   out_8501408524920025174[322] = 0.0;
   out_8501408524920025174[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6089450380884689027) {
   out_6089450380884689027[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6089450380884689027[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6089450380884689027[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6089450380884689027[3] = dt*state[12] + state[3];
   out_6089450380884689027[4] = dt*state[13] + state[4];
   out_6089450380884689027[5] = dt*state[14] + state[5];
   out_6089450380884689027[6] = state[6];
   out_6089450380884689027[7] = state[7];
   out_6089450380884689027[8] = state[8];
   out_6089450380884689027[9] = state[9];
   out_6089450380884689027[10] = state[10];
   out_6089450380884689027[11] = state[11];
   out_6089450380884689027[12] = state[12];
   out_6089450380884689027[13] = state[13];
   out_6089450380884689027[14] = state[14];
   out_6089450380884689027[15] = state[15];
   out_6089450380884689027[16] = state[16];
   out_6089450380884689027[17] = state[17];
}
void F_fun(double *state, double dt, double *out_991092191689553148) {
   out_991092191689553148[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_991092191689553148[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_991092191689553148[2] = 0;
   out_991092191689553148[3] = 0;
   out_991092191689553148[4] = 0;
   out_991092191689553148[5] = 0;
   out_991092191689553148[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_991092191689553148[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_991092191689553148[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_991092191689553148[9] = 0;
   out_991092191689553148[10] = 0;
   out_991092191689553148[11] = 0;
   out_991092191689553148[12] = 0;
   out_991092191689553148[13] = 0;
   out_991092191689553148[14] = 0;
   out_991092191689553148[15] = 0;
   out_991092191689553148[16] = 0;
   out_991092191689553148[17] = 0;
   out_991092191689553148[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_991092191689553148[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_991092191689553148[20] = 0;
   out_991092191689553148[21] = 0;
   out_991092191689553148[22] = 0;
   out_991092191689553148[23] = 0;
   out_991092191689553148[24] = 0;
   out_991092191689553148[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_991092191689553148[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_991092191689553148[27] = 0;
   out_991092191689553148[28] = 0;
   out_991092191689553148[29] = 0;
   out_991092191689553148[30] = 0;
   out_991092191689553148[31] = 0;
   out_991092191689553148[32] = 0;
   out_991092191689553148[33] = 0;
   out_991092191689553148[34] = 0;
   out_991092191689553148[35] = 0;
   out_991092191689553148[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_991092191689553148[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_991092191689553148[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_991092191689553148[39] = 0;
   out_991092191689553148[40] = 0;
   out_991092191689553148[41] = 0;
   out_991092191689553148[42] = 0;
   out_991092191689553148[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_991092191689553148[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_991092191689553148[45] = 0;
   out_991092191689553148[46] = 0;
   out_991092191689553148[47] = 0;
   out_991092191689553148[48] = 0;
   out_991092191689553148[49] = 0;
   out_991092191689553148[50] = 0;
   out_991092191689553148[51] = 0;
   out_991092191689553148[52] = 0;
   out_991092191689553148[53] = 0;
   out_991092191689553148[54] = 0;
   out_991092191689553148[55] = 0;
   out_991092191689553148[56] = 0;
   out_991092191689553148[57] = 1;
   out_991092191689553148[58] = 0;
   out_991092191689553148[59] = 0;
   out_991092191689553148[60] = 0;
   out_991092191689553148[61] = 0;
   out_991092191689553148[62] = 0;
   out_991092191689553148[63] = 0;
   out_991092191689553148[64] = 0;
   out_991092191689553148[65] = 0;
   out_991092191689553148[66] = dt;
   out_991092191689553148[67] = 0;
   out_991092191689553148[68] = 0;
   out_991092191689553148[69] = 0;
   out_991092191689553148[70] = 0;
   out_991092191689553148[71] = 0;
   out_991092191689553148[72] = 0;
   out_991092191689553148[73] = 0;
   out_991092191689553148[74] = 0;
   out_991092191689553148[75] = 0;
   out_991092191689553148[76] = 1;
   out_991092191689553148[77] = 0;
   out_991092191689553148[78] = 0;
   out_991092191689553148[79] = 0;
   out_991092191689553148[80] = 0;
   out_991092191689553148[81] = 0;
   out_991092191689553148[82] = 0;
   out_991092191689553148[83] = 0;
   out_991092191689553148[84] = 0;
   out_991092191689553148[85] = dt;
   out_991092191689553148[86] = 0;
   out_991092191689553148[87] = 0;
   out_991092191689553148[88] = 0;
   out_991092191689553148[89] = 0;
   out_991092191689553148[90] = 0;
   out_991092191689553148[91] = 0;
   out_991092191689553148[92] = 0;
   out_991092191689553148[93] = 0;
   out_991092191689553148[94] = 0;
   out_991092191689553148[95] = 1;
   out_991092191689553148[96] = 0;
   out_991092191689553148[97] = 0;
   out_991092191689553148[98] = 0;
   out_991092191689553148[99] = 0;
   out_991092191689553148[100] = 0;
   out_991092191689553148[101] = 0;
   out_991092191689553148[102] = 0;
   out_991092191689553148[103] = 0;
   out_991092191689553148[104] = dt;
   out_991092191689553148[105] = 0;
   out_991092191689553148[106] = 0;
   out_991092191689553148[107] = 0;
   out_991092191689553148[108] = 0;
   out_991092191689553148[109] = 0;
   out_991092191689553148[110] = 0;
   out_991092191689553148[111] = 0;
   out_991092191689553148[112] = 0;
   out_991092191689553148[113] = 0;
   out_991092191689553148[114] = 1;
   out_991092191689553148[115] = 0;
   out_991092191689553148[116] = 0;
   out_991092191689553148[117] = 0;
   out_991092191689553148[118] = 0;
   out_991092191689553148[119] = 0;
   out_991092191689553148[120] = 0;
   out_991092191689553148[121] = 0;
   out_991092191689553148[122] = 0;
   out_991092191689553148[123] = 0;
   out_991092191689553148[124] = 0;
   out_991092191689553148[125] = 0;
   out_991092191689553148[126] = 0;
   out_991092191689553148[127] = 0;
   out_991092191689553148[128] = 0;
   out_991092191689553148[129] = 0;
   out_991092191689553148[130] = 0;
   out_991092191689553148[131] = 0;
   out_991092191689553148[132] = 0;
   out_991092191689553148[133] = 1;
   out_991092191689553148[134] = 0;
   out_991092191689553148[135] = 0;
   out_991092191689553148[136] = 0;
   out_991092191689553148[137] = 0;
   out_991092191689553148[138] = 0;
   out_991092191689553148[139] = 0;
   out_991092191689553148[140] = 0;
   out_991092191689553148[141] = 0;
   out_991092191689553148[142] = 0;
   out_991092191689553148[143] = 0;
   out_991092191689553148[144] = 0;
   out_991092191689553148[145] = 0;
   out_991092191689553148[146] = 0;
   out_991092191689553148[147] = 0;
   out_991092191689553148[148] = 0;
   out_991092191689553148[149] = 0;
   out_991092191689553148[150] = 0;
   out_991092191689553148[151] = 0;
   out_991092191689553148[152] = 1;
   out_991092191689553148[153] = 0;
   out_991092191689553148[154] = 0;
   out_991092191689553148[155] = 0;
   out_991092191689553148[156] = 0;
   out_991092191689553148[157] = 0;
   out_991092191689553148[158] = 0;
   out_991092191689553148[159] = 0;
   out_991092191689553148[160] = 0;
   out_991092191689553148[161] = 0;
   out_991092191689553148[162] = 0;
   out_991092191689553148[163] = 0;
   out_991092191689553148[164] = 0;
   out_991092191689553148[165] = 0;
   out_991092191689553148[166] = 0;
   out_991092191689553148[167] = 0;
   out_991092191689553148[168] = 0;
   out_991092191689553148[169] = 0;
   out_991092191689553148[170] = 0;
   out_991092191689553148[171] = 1;
   out_991092191689553148[172] = 0;
   out_991092191689553148[173] = 0;
   out_991092191689553148[174] = 0;
   out_991092191689553148[175] = 0;
   out_991092191689553148[176] = 0;
   out_991092191689553148[177] = 0;
   out_991092191689553148[178] = 0;
   out_991092191689553148[179] = 0;
   out_991092191689553148[180] = 0;
   out_991092191689553148[181] = 0;
   out_991092191689553148[182] = 0;
   out_991092191689553148[183] = 0;
   out_991092191689553148[184] = 0;
   out_991092191689553148[185] = 0;
   out_991092191689553148[186] = 0;
   out_991092191689553148[187] = 0;
   out_991092191689553148[188] = 0;
   out_991092191689553148[189] = 0;
   out_991092191689553148[190] = 1;
   out_991092191689553148[191] = 0;
   out_991092191689553148[192] = 0;
   out_991092191689553148[193] = 0;
   out_991092191689553148[194] = 0;
   out_991092191689553148[195] = 0;
   out_991092191689553148[196] = 0;
   out_991092191689553148[197] = 0;
   out_991092191689553148[198] = 0;
   out_991092191689553148[199] = 0;
   out_991092191689553148[200] = 0;
   out_991092191689553148[201] = 0;
   out_991092191689553148[202] = 0;
   out_991092191689553148[203] = 0;
   out_991092191689553148[204] = 0;
   out_991092191689553148[205] = 0;
   out_991092191689553148[206] = 0;
   out_991092191689553148[207] = 0;
   out_991092191689553148[208] = 0;
   out_991092191689553148[209] = 1;
   out_991092191689553148[210] = 0;
   out_991092191689553148[211] = 0;
   out_991092191689553148[212] = 0;
   out_991092191689553148[213] = 0;
   out_991092191689553148[214] = 0;
   out_991092191689553148[215] = 0;
   out_991092191689553148[216] = 0;
   out_991092191689553148[217] = 0;
   out_991092191689553148[218] = 0;
   out_991092191689553148[219] = 0;
   out_991092191689553148[220] = 0;
   out_991092191689553148[221] = 0;
   out_991092191689553148[222] = 0;
   out_991092191689553148[223] = 0;
   out_991092191689553148[224] = 0;
   out_991092191689553148[225] = 0;
   out_991092191689553148[226] = 0;
   out_991092191689553148[227] = 0;
   out_991092191689553148[228] = 1;
   out_991092191689553148[229] = 0;
   out_991092191689553148[230] = 0;
   out_991092191689553148[231] = 0;
   out_991092191689553148[232] = 0;
   out_991092191689553148[233] = 0;
   out_991092191689553148[234] = 0;
   out_991092191689553148[235] = 0;
   out_991092191689553148[236] = 0;
   out_991092191689553148[237] = 0;
   out_991092191689553148[238] = 0;
   out_991092191689553148[239] = 0;
   out_991092191689553148[240] = 0;
   out_991092191689553148[241] = 0;
   out_991092191689553148[242] = 0;
   out_991092191689553148[243] = 0;
   out_991092191689553148[244] = 0;
   out_991092191689553148[245] = 0;
   out_991092191689553148[246] = 0;
   out_991092191689553148[247] = 1;
   out_991092191689553148[248] = 0;
   out_991092191689553148[249] = 0;
   out_991092191689553148[250] = 0;
   out_991092191689553148[251] = 0;
   out_991092191689553148[252] = 0;
   out_991092191689553148[253] = 0;
   out_991092191689553148[254] = 0;
   out_991092191689553148[255] = 0;
   out_991092191689553148[256] = 0;
   out_991092191689553148[257] = 0;
   out_991092191689553148[258] = 0;
   out_991092191689553148[259] = 0;
   out_991092191689553148[260] = 0;
   out_991092191689553148[261] = 0;
   out_991092191689553148[262] = 0;
   out_991092191689553148[263] = 0;
   out_991092191689553148[264] = 0;
   out_991092191689553148[265] = 0;
   out_991092191689553148[266] = 1;
   out_991092191689553148[267] = 0;
   out_991092191689553148[268] = 0;
   out_991092191689553148[269] = 0;
   out_991092191689553148[270] = 0;
   out_991092191689553148[271] = 0;
   out_991092191689553148[272] = 0;
   out_991092191689553148[273] = 0;
   out_991092191689553148[274] = 0;
   out_991092191689553148[275] = 0;
   out_991092191689553148[276] = 0;
   out_991092191689553148[277] = 0;
   out_991092191689553148[278] = 0;
   out_991092191689553148[279] = 0;
   out_991092191689553148[280] = 0;
   out_991092191689553148[281] = 0;
   out_991092191689553148[282] = 0;
   out_991092191689553148[283] = 0;
   out_991092191689553148[284] = 0;
   out_991092191689553148[285] = 1;
   out_991092191689553148[286] = 0;
   out_991092191689553148[287] = 0;
   out_991092191689553148[288] = 0;
   out_991092191689553148[289] = 0;
   out_991092191689553148[290] = 0;
   out_991092191689553148[291] = 0;
   out_991092191689553148[292] = 0;
   out_991092191689553148[293] = 0;
   out_991092191689553148[294] = 0;
   out_991092191689553148[295] = 0;
   out_991092191689553148[296] = 0;
   out_991092191689553148[297] = 0;
   out_991092191689553148[298] = 0;
   out_991092191689553148[299] = 0;
   out_991092191689553148[300] = 0;
   out_991092191689553148[301] = 0;
   out_991092191689553148[302] = 0;
   out_991092191689553148[303] = 0;
   out_991092191689553148[304] = 1;
   out_991092191689553148[305] = 0;
   out_991092191689553148[306] = 0;
   out_991092191689553148[307] = 0;
   out_991092191689553148[308] = 0;
   out_991092191689553148[309] = 0;
   out_991092191689553148[310] = 0;
   out_991092191689553148[311] = 0;
   out_991092191689553148[312] = 0;
   out_991092191689553148[313] = 0;
   out_991092191689553148[314] = 0;
   out_991092191689553148[315] = 0;
   out_991092191689553148[316] = 0;
   out_991092191689553148[317] = 0;
   out_991092191689553148[318] = 0;
   out_991092191689553148[319] = 0;
   out_991092191689553148[320] = 0;
   out_991092191689553148[321] = 0;
   out_991092191689553148[322] = 0;
   out_991092191689553148[323] = 1;
}
void h_4(double *state, double *unused, double *out_8457711863185147516) {
   out_8457711863185147516[0] = state[6] + state[9];
   out_8457711863185147516[1] = state[7] + state[10];
   out_8457711863185147516[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6744925647688056418) {
   out_6744925647688056418[0] = 0;
   out_6744925647688056418[1] = 0;
   out_6744925647688056418[2] = 0;
   out_6744925647688056418[3] = 0;
   out_6744925647688056418[4] = 0;
   out_6744925647688056418[5] = 0;
   out_6744925647688056418[6] = 1;
   out_6744925647688056418[7] = 0;
   out_6744925647688056418[8] = 0;
   out_6744925647688056418[9] = 1;
   out_6744925647688056418[10] = 0;
   out_6744925647688056418[11] = 0;
   out_6744925647688056418[12] = 0;
   out_6744925647688056418[13] = 0;
   out_6744925647688056418[14] = 0;
   out_6744925647688056418[15] = 0;
   out_6744925647688056418[16] = 0;
   out_6744925647688056418[17] = 0;
   out_6744925647688056418[18] = 0;
   out_6744925647688056418[19] = 0;
   out_6744925647688056418[20] = 0;
   out_6744925647688056418[21] = 0;
   out_6744925647688056418[22] = 0;
   out_6744925647688056418[23] = 0;
   out_6744925647688056418[24] = 0;
   out_6744925647688056418[25] = 1;
   out_6744925647688056418[26] = 0;
   out_6744925647688056418[27] = 0;
   out_6744925647688056418[28] = 1;
   out_6744925647688056418[29] = 0;
   out_6744925647688056418[30] = 0;
   out_6744925647688056418[31] = 0;
   out_6744925647688056418[32] = 0;
   out_6744925647688056418[33] = 0;
   out_6744925647688056418[34] = 0;
   out_6744925647688056418[35] = 0;
   out_6744925647688056418[36] = 0;
   out_6744925647688056418[37] = 0;
   out_6744925647688056418[38] = 0;
   out_6744925647688056418[39] = 0;
   out_6744925647688056418[40] = 0;
   out_6744925647688056418[41] = 0;
   out_6744925647688056418[42] = 0;
   out_6744925647688056418[43] = 0;
   out_6744925647688056418[44] = 1;
   out_6744925647688056418[45] = 0;
   out_6744925647688056418[46] = 0;
   out_6744925647688056418[47] = 1;
   out_6744925647688056418[48] = 0;
   out_6744925647688056418[49] = 0;
   out_6744925647688056418[50] = 0;
   out_6744925647688056418[51] = 0;
   out_6744925647688056418[52] = 0;
   out_6744925647688056418[53] = 0;
}
void h_10(double *state, double *unused, double *out_5107656030105349980) {
   out_5107656030105349980[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5107656030105349980[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5107656030105349980[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_343328804276289840) {
   out_343328804276289840[0] = 0;
   out_343328804276289840[1] = 9.8100000000000005*cos(state[1]);
   out_343328804276289840[2] = 0;
   out_343328804276289840[3] = 0;
   out_343328804276289840[4] = -state[8];
   out_343328804276289840[5] = state[7];
   out_343328804276289840[6] = 0;
   out_343328804276289840[7] = state[5];
   out_343328804276289840[8] = -state[4];
   out_343328804276289840[9] = 0;
   out_343328804276289840[10] = 0;
   out_343328804276289840[11] = 0;
   out_343328804276289840[12] = 1;
   out_343328804276289840[13] = 0;
   out_343328804276289840[14] = 0;
   out_343328804276289840[15] = 1;
   out_343328804276289840[16] = 0;
   out_343328804276289840[17] = 0;
   out_343328804276289840[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_343328804276289840[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_343328804276289840[20] = 0;
   out_343328804276289840[21] = state[8];
   out_343328804276289840[22] = 0;
   out_343328804276289840[23] = -state[6];
   out_343328804276289840[24] = -state[5];
   out_343328804276289840[25] = 0;
   out_343328804276289840[26] = state[3];
   out_343328804276289840[27] = 0;
   out_343328804276289840[28] = 0;
   out_343328804276289840[29] = 0;
   out_343328804276289840[30] = 0;
   out_343328804276289840[31] = 1;
   out_343328804276289840[32] = 0;
   out_343328804276289840[33] = 0;
   out_343328804276289840[34] = 1;
   out_343328804276289840[35] = 0;
   out_343328804276289840[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_343328804276289840[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_343328804276289840[38] = 0;
   out_343328804276289840[39] = -state[7];
   out_343328804276289840[40] = state[6];
   out_343328804276289840[41] = 0;
   out_343328804276289840[42] = state[4];
   out_343328804276289840[43] = -state[3];
   out_343328804276289840[44] = 0;
   out_343328804276289840[45] = 0;
   out_343328804276289840[46] = 0;
   out_343328804276289840[47] = 0;
   out_343328804276289840[48] = 0;
   out_343328804276289840[49] = 0;
   out_343328804276289840[50] = 1;
   out_343328804276289840[51] = 0;
   out_343328804276289840[52] = 0;
   out_343328804276289840[53] = 1;
}
void h_13(double *state, double *unused, double *out_5909685414932039417) {
   out_5909685414932039417[0] = state[3];
   out_5909685414932039417[1] = state[4];
   out_5909685414932039417[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4091187217704794269) {
   out_4091187217704794269[0] = 0;
   out_4091187217704794269[1] = 0;
   out_4091187217704794269[2] = 0;
   out_4091187217704794269[3] = 1;
   out_4091187217704794269[4] = 0;
   out_4091187217704794269[5] = 0;
   out_4091187217704794269[6] = 0;
   out_4091187217704794269[7] = 0;
   out_4091187217704794269[8] = 0;
   out_4091187217704794269[9] = 0;
   out_4091187217704794269[10] = 0;
   out_4091187217704794269[11] = 0;
   out_4091187217704794269[12] = 0;
   out_4091187217704794269[13] = 0;
   out_4091187217704794269[14] = 0;
   out_4091187217704794269[15] = 0;
   out_4091187217704794269[16] = 0;
   out_4091187217704794269[17] = 0;
   out_4091187217704794269[18] = 0;
   out_4091187217704794269[19] = 0;
   out_4091187217704794269[20] = 0;
   out_4091187217704794269[21] = 0;
   out_4091187217704794269[22] = 1;
   out_4091187217704794269[23] = 0;
   out_4091187217704794269[24] = 0;
   out_4091187217704794269[25] = 0;
   out_4091187217704794269[26] = 0;
   out_4091187217704794269[27] = 0;
   out_4091187217704794269[28] = 0;
   out_4091187217704794269[29] = 0;
   out_4091187217704794269[30] = 0;
   out_4091187217704794269[31] = 0;
   out_4091187217704794269[32] = 0;
   out_4091187217704794269[33] = 0;
   out_4091187217704794269[34] = 0;
   out_4091187217704794269[35] = 0;
   out_4091187217704794269[36] = 0;
   out_4091187217704794269[37] = 0;
   out_4091187217704794269[38] = 0;
   out_4091187217704794269[39] = 0;
   out_4091187217704794269[40] = 0;
   out_4091187217704794269[41] = 1;
   out_4091187217704794269[42] = 0;
   out_4091187217704794269[43] = 0;
   out_4091187217704794269[44] = 0;
   out_4091187217704794269[45] = 0;
   out_4091187217704794269[46] = 0;
   out_4091187217704794269[47] = 0;
   out_4091187217704794269[48] = 0;
   out_4091187217704794269[49] = 0;
   out_4091187217704794269[50] = 0;
   out_4091187217704794269[51] = 0;
   out_4091187217704794269[52] = 0;
   out_4091187217704794269[53] = 0;
}
void h_14(double *state, double *unused, double *out_3776433797215708635) {
   out_3776433797215708635[0] = state[6];
   out_3776433797215708635[1] = state[7];
   out_3776433797215708635[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3662137215392684122) {
   out_3662137215392684122[0] = 0;
   out_3662137215392684122[1] = 0;
   out_3662137215392684122[2] = 0;
   out_3662137215392684122[3] = 0;
   out_3662137215392684122[4] = 0;
   out_3662137215392684122[5] = 0;
   out_3662137215392684122[6] = 1;
   out_3662137215392684122[7] = 0;
   out_3662137215392684122[8] = 0;
   out_3662137215392684122[9] = 0;
   out_3662137215392684122[10] = 0;
   out_3662137215392684122[11] = 0;
   out_3662137215392684122[12] = 0;
   out_3662137215392684122[13] = 0;
   out_3662137215392684122[14] = 0;
   out_3662137215392684122[15] = 0;
   out_3662137215392684122[16] = 0;
   out_3662137215392684122[17] = 0;
   out_3662137215392684122[18] = 0;
   out_3662137215392684122[19] = 0;
   out_3662137215392684122[20] = 0;
   out_3662137215392684122[21] = 0;
   out_3662137215392684122[22] = 0;
   out_3662137215392684122[23] = 0;
   out_3662137215392684122[24] = 0;
   out_3662137215392684122[25] = 1;
   out_3662137215392684122[26] = 0;
   out_3662137215392684122[27] = 0;
   out_3662137215392684122[28] = 0;
   out_3662137215392684122[29] = 0;
   out_3662137215392684122[30] = 0;
   out_3662137215392684122[31] = 0;
   out_3662137215392684122[32] = 0;
   out_3662137215392684122[33] = 0;
   out_3662137215392684122[34] = 0;
   out_3662137215392684122[35] = 0;
   out_3662137215392684122[36] = 0;
   out_3662137215392684122[37] = 0;
   out_3662137215392684122[38] = 0;
   out_3662137215392684122[39] = 0;
   out_3662137215392684122[40] = 0;
   out_3662137215392684122[41] = 0;
   out_3662137215392684122[42] = 0;
   out_3662137215392684122[43] = 0;
   out_3662137215392684122[44] = 1;
   out_3662137215392684122[45] = 0;
   out_3662137215392684122[46] = 0;
   out_3662137215392684122[47] = 0;
   out_3662137215392684122[48] = 0;
   out_3662137215392684122[49] = 0;
   out_3662137215392684122[50] = 0;
   out_3662137215392684122[51] = 0;
   out_3662137215392684122[52] = 0;
   out_3662137215392684122[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1893066262074101492) {
  err_fun(nom_x, delta_x, out_1893066262074101492);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5108622378397263891) {
  inv_err_fun(nom_x, true_x, out_5108622378397263891);
}
void pose_H_mod_fun(double *state, double *out_8501408524920025174) {
  H_mod_fun(state, out_8501408524920025174);
}
void pose_f_fun(double *state, double dt, double *out_6089450380884689027) {
  f_fun(state,  dt, out_6089450380884689027);
}
void pose_F_fun(double *state, double dt, double *out_991092191689553148) {
  F_fun(state,  dt, out_991092191689553148);
}
void pose_h_4(double *state, double *unused, double *out_8457711863185147516) {
  h_4(state, unused, out_8457711863185147516);
}
void pose_H_4(double *state, double *unused, double *out_6744925647688056418) {
  H_4(state, unused, out_6744925647688056418);
}
void pose_h_10(double *state, double *unused, double *out_5107656030105349980) {
  h_10(state, unused, out_5107656030105349980);
}
void pose_H_10(double *state, double *unused, double *out_343328804276289840) {
  H_10(state, unused, out_343328804276289840);
}
void pose_h_13(double *state, double *unused, double *out_5909685414932039417) {
  h_13(state, unused, out_5909685414932039417);
}
void pose_H_13(double *state, double *unused, double *out_4091187217704794269) {
  H_13(state, unused, out_4091187217704794269);
}
void pose_h_14(double *state, double *unused, double *out_3776433797215708635) {
  h_14(state, unused, out_3776433797215708635);
}
void pose_H_14(double *state, double *unused, double *out_3662137215392684122) {
  H_14(state, unused, out_3662137215392684122);
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
