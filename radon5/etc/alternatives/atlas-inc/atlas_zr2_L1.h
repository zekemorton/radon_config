#ifndef ATLAS_ZR2_L1_H
#define ATLAS_ZR2_L1_H

#include "atlas_type.h"

typedef void (*ATL_r2kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_zger2k__3
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_zger2k__900005
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);

static ATL_r2kern_t ATL_GetR2Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         *minM = 0;   *minN = 0;
         *mu = 2;     *nu = 3;
         *alignX = 16;  *alignY = 16;
         *ALIGNX2A = 0;
         *FNU = 1;
         *CacheElts = 1024;
         return(ATL_zger2k__3);
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 16;   *minN = 2;
   *mu = 16;     *nu = 2;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 1024;
   return(ATL_zger2k__900005);
}

#define ATL_GetPartR2(A_, lda_, mb_, nb_) { (mb_) = 160; (nb_) = 2; }

#endif  /* end protection around header file contents */
