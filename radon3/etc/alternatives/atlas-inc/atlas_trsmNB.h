#ifndef ATLAS_TRSMNB_H
   #define ATLAS_TRSMNB_H

   #ifdef SREAL
      #define TRSM_NB 216
   #elif defined(DREAL)
      #define TRSM_NB 120
   #elif defined(SCPLX)
      #define TRSM_NB 152
   #elif defined(DCPLX)
      #define TRSM_NB 40
   #endif

#endif
