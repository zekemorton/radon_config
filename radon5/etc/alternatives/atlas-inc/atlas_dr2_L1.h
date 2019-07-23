#ifndef ATLAS_DR2_L1_H
#define ATLAS_DR2_L1_H

#include "atlas_type.h"

typedef void (*ATL_r2kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_dger2k__3
   (ATL_CINT, ATL_CINT, const double*, const double*, const double*,
    const double*, double*, ATL_CINT);
void ATL_dger2k__900005
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
         if (N >= 2)
         {
            *minM = 0;   *minN = 2;
            *mu = 2;     *nu = 2;
            *alignX = 16;  *alignY = 16;
            *ALIGNX2A = 0;
            *FNU = 1;
            *CacheElts = 1925;
            return(ATL_dger2k__3);
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 24;   *minN = 3;
   *mu = 24;     *nu = 3;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 1925;
   return(ATL_dger2k__900005);
}

#define ATL_GetPartR2(A_, lda_, mb_, nb_) { (mb_) = 216; (nb_) = 3; }

#endif  /* end protection around header file contents */
