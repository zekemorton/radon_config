#ifndef DMM_H
   #define DMM_H

   #define ATL_mmMULADD
   #define ATL_mmLAT 4
   #define ATL_mmMU  4
   #define ATL_mmNU  1
   #define ATL_mmKU  2
   #define MB 40
   #define NB 40
   #define KB 40
   #define NBNB 1600
   #define MBNB 1600
   #define MBKB 1600
   #define NBKB 1600
   #define NB2 80
   #define NBNB2 3200

   #define ATL_MulByNB(N_) ((N_) * 40)
   #define ATL_DivByNB(N_) ((N_) / 40)
   #define ATL_MulByNBNB(N_) ((N_) * 1600)
   #define NBmm ATL_dJIK40x40x40TN40x40x0_a1_b1
   #define NBmm_b1 ATL_dJIK40x40x40TN40x40x0_a1_b1
   #define NBmm_b0 ATL_dJIK40x40x40TN40x40x0_a1_b0
   #define NBmm_bX ATL_dJIK40x40x40TN40x40x0_a1_bX

#endif
