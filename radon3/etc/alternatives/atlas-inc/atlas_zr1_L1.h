#ifndef ATLAS_ZR1_L1_H
#define ATLAS_ZR1_L1_H

#include "atlas_type.h"

typedef void (*ATL_r1kern_t)
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_zgerk__900006
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_zgerk__900003
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);
void ATL_zgerk__900005
   (ATL_CINT, ATL_CINT, const double*, const double*, double*, ATL_CINT);

static ATL_r1kern_t ATL_GetR1Kern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 4)
         {
            if (M >= 4)
            {
               *minM = 4;   *minN = 4;
               *mu = 4;     *nu = 4;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 1024;
               return(ATL_zgerk__900006);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (M >= 24)
         {
            *minM = 24;   *minN = 1;
            *mu = 24;     *nu = 1;
            *alignX = 16;  *alignY = 16;
            *ALIGNX2A = 0;
            *FNU = 1;
            *CacheElts = 1024;
            return(ATL_zgerk__900003);
         } /* end if on minimal N guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 4;   *minN = 4;
   *mu = 4;     *nu = 4;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 1024;
   return(ATL_zgerk__900005);
}

#define ATL_GetPartR1(A_, lda_, mb_, nb_) { (mb_) = 100; (nb_) = 4; }

#endif  /* end protection around header file contents */
