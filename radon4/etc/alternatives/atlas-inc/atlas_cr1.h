#ifndef ATLAS_CR1_L0_H
#define ATLAS_CR1_L0_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_cgerk__900006
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_cgerk__3
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);
void ATL_cgerk__900007
   (ATL_CINT, ATL_CINT, const float*, const float*, float*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 3)
         {
            if (M >= 8)
            {
               *minM = 8;   *minN = 3;
               *mu = 8;     *nu = 3;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 0;
               return(ATL_cgerk__900006);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   if ((((((((size_t)(A))) >> 3)) << 3)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 4)
         {
            if (M >= 9)
            {
               *minM = 9;   *minN = 4;
               *mu = 8;     *nu = 4;
               *alignX = 4;  *alignY = 8;
               *ALIGNX2A = 1;
               *FNU = 1;
               *CacheElts = 0;
               return(ATL_cgerk__3);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 1;   *minN = 2;
   *mu = 1;     *nu = 2;
   *alignX = 4;  *alignY = 4;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 0;
   return(ATL_cgerk__900007);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 0; (nb_) = 0; }

#endif  /* end protection around header file contents */
