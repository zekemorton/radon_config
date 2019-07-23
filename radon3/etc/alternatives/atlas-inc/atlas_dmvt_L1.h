#ifndef ATLAS_DMVT_L1_H
#define ATLAS_DMVT_L1_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

#endif
void ATL_dmvtk__900008(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvtk__900008_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvtk__2(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvtk__2_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvtk__900007(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvtk__900007_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

static ATL_mvkern_t ATL_GetMVTKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, 
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 8)
         {
            if (M >= 8)
            {
               *minM = 8;   *minN = 8;
               *mu = 8;     *nu = 8;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 2048;
               *mvk_b0 = ATL_dmvtk__900008_b0;
               return(ATL_dmvtk__900008);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
   {
      if (N >= 8)
      {
         *minM = 0;   *minN = 8;
         *mu = 2;     *nu = 8;
         *alignX = 8;  *alignY = 16;
         *ALIGNX2A = 1;
         *FNU = 0;
         *CacheElts = 2048;
         *mvk_b0 = ATL_dmvtk__2_b0;
         return(ATL_dmvtk__2);
      } /* end if on minimal M guard */
   } /* end if on lda multiple restriction */
   *minM = 8;   *minN = 8;
   *mu = 8;     *nu = 8;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 2048;
   *mvk_b0 = ATL_dmvtk__900007_b0;
   return(ATL_dmvtk__900007);
}

#define ATL_GetPartMVT(A_, lda_, mb_, nb_) { *(mb_) = 112; *(nb_) = 8; }

#endif  /* end protection around header file contents */
