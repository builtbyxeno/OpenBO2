/*
 * Copyright (c) 2020-2021 OpenIW
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
==============
nuge::tensor_transform_principle
==============
*/
void nuge::tensor_transform_principle(phys_vec3 *diag, phys_mat44 *mat, phys_mat44 *tensor)
{
  float left_zrow_4; // ST60_4
  float left_zrow_8; // ST64_4
  float left_zrow_12; // ST68_4
  float v6; // ST7C_4
  float v7; // ST40_4
  float v8; // ST44_4
  float v9; // ST48_4
  float v10; // ST7C_4
  float left_yrow_4; // ST50_4
  float left_yrow_8; // ST54_4
  float left_yrow_12; // ST58_4
  float v14; // ST7C_4
  double v15; // st7
  float x__4; // ST20_4
  double v17; // st5
  float x__8; // ST24_4
  double v19; // st6
  float x__12; // ST28_4
  float v21; // ST7C_4
  double v22; // st3
  float v23; // ST50_4
  double v24; // st2
  float v25; // ST54_4
  double v26; // st4
  float v27; // ST58_4
  float v28; // ST40_4
  float v29; // ST44_4
  float v30; // ST48_4
  float z__4; // ST30_4
  float z__8; // ST34_4
  float z__12; // ST38_4
  float y__4; // ST10_4
  float y__8; // ST14_4
  float y__12; // ST18_4
  float v37; // ST7C_4
  float v38; // ST50_4
  float v39; // ST54_4
  float v40; // ST58_4
  float v41; // ST7C_4
  float v42; // ST30_4
  float v43; // ST34_4
  float v44; // ST38_4
  float v45; // ST7C_4
  float v46; // ST20_4
  float v47; // ST24_4
  float v48; // ST28_4
  float v49; // ST40_4
  float v50; // ST44_4
  float v51; // ST48_4
  float v52; // ST00_4
  float v53; // ST04_4
  float v54; // ST08_4
  float v55; // ST7C_4
  float v56; // ST50_4
  float v57; // ST54_4
  double v58; // rt1
  float v59; // ST58_4
  double v60; // st3
  float v61; // ST30_4
  float v62; // ST34_4
  float v63; // ST38_4
  float v64; // ST7C_4
  float v65; // ST20_4
  float v66; // ST24_4
  float v67; // ST28_4
  float v68; // ST40_4
  float v69; // ST44_4
  float v70; // ST48_4
  float v71; // ST20_4
  float v72; // ST24_4
  float v73; // ST28_4

  left_zrow_4 = mat->x.x * diag->x;
  left_zrow_8 = diag->x * mat->x.y;
  left_zrow_12 = diag->x * mat->x.z;
  v6 = diag->y;
  v7 = mat->y.x * v6;
  v8 = mat->y.y * v6;
  v9 = v6 * mat->y.z;
  v10 = diag->z;
  left_yrow_4 = mat->z.x * v10;
  left_yrow_8 = mat->z.y * v10;
  left_yrow_12 = v10 * mat->z.z;
  v14 = mat->z.x;
  v15 = left_yrow_4;
  x__4 = left_yrow_4 * v14;
  v17 = left_yrow_8;
  x__8 = left_yrow_8 * v14;
  v19 = left_yrow_12;
  x__12 = v14 * left_yrow_12;
  v21 = mat->y.x;
  v22 = v7;
  v23 = v21 * v7;
  v24 = v8;
  v25 = v8 * v21;
  v26 = v9;
  v27 = v21 * v9;
  v28 = mat->x.x * left_zrow_4;
  v29 = left_zrow_8 * mat->x.x;
  v30 = left_zrow_12 * mat->x.x;
  z__4 = v28 + v23;
  z__8 = v29 + v25;
  z__12 = v30 + v27;
  y__4 = z__4 + x__4;
  y__8 = z__8 + x__8;
  y__12 = z__12 + x__12;
  v37 = mat->z.y;
  v38 = v37 * v15;
  v39 = v17 * v37;
  v40 = v19 * v37;
  v41 = mat->y.y;
  v42 = v41 * v22;
  v43 = v24 * v41;
  v44 = v26 * v41;
  v45 = mat->x.y;
  v46 = v45 * left_zrow_4;
  v47 = left_zrow_8 * v45;
  v48 = left_zrow_12 * v45;
  v49 = v46 + v42;
  v50 = v47 + v43;
  v51 = v48 + v44;
  v52 = v49 + v38;
  v53 = v50 + v39;
  v54 = v51 + v40;
  v55 = mat->z.z;
  v56 = v15 * v55;
  v57 = v17 * v55;
  v58 = v22;
  v59 = v55 * v19;
  v60 = mat->y.z;
  v61 = v58 * v60;
  v62 = v24 * v60;
  v63 = v26 * v60;
  v64 = mat->x.z;
  v65 = v64 * left_zrow_4;
  v66 = left_zrow_8 * v64;
  v67 = v64 * left_zrow_12;
  v68 = v65 + v61;
  v69 = v66 + v62;
  v70 = v67 + v63;
  v71 = v68 + v56;
  v72 = v69 + v57;
  v73 = v70 + v59;
  tensor->x.x = y__4;
  tensor->x.y = y__8;
  tensor->x.z = y__12;
  tensor->y.x = v52;
  tensor->y.y = v53;
  tensor->y.z = v54;
  tensor->z.x = v71;
  tensor->z.y = v72;
  tensor->z.z = v73;
}

