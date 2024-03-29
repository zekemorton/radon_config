#ifndef ATLAS_DR1_L1_H
#define ATLAS_DR1_L1_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_dgerk__6
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_dgerk__1
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
   {
      *minM = 0;   *minN = 0;
      *mu = 8;     *nu = 4;
      *alignX = 8;  *alignY = 8;
      *ALIGNX2A = 1;
      *FNU = 0;
      *CacheElts = 2048;
      return(ATL_dgerk__6);
   } /* end if on lda multiple restriction */
   *minM = 0;   *minN = 0;
   *mu = 16;     *nu = 1;
   *alignX = 8;  *alignY = 8;
   *ALIGNX2A = 0;
   *FNU = 0;
   *CacheElts = 2048;
   return(ATL_dgerk__1);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 496; (nb_) = 1; }

#endif  /* end protection around header file contents */
