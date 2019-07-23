#ifndef ATLAS_SMVN_L0_H
#define ATLAS_SMVN_L0_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

#endif
void ATL_smvnk__900003(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900003_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900002(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900002_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

static ATL_mvkern_t ATL_GetMVNKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, int *DOTBASED,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (M >= 96)
         {
            *minM = 96;   *minN = 1;
            *mu = 96;     *nu = 1;
            *alignX = 16;  *alignY = 16;
            *ALIGNX2A = 0;
            *FNU = 1;
            *CacheElts = 16384;
            *mvk_b0 = ATL_smvnk__900003_b0;
            *DOTBASED = 0;
            return(ATL_smvnk__900003);
         } /* end if on minimal N guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 96;   *minN = 1;
   *mu = 96;     *nu = 1;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 16384;
   *mvk_b0 = ATL_smvnk__900002_b0;
   *DOTBASED = 0;
   return(ATL_smvnk__900002);
}

#define ATL_GetPartMVN(A_, lda_, mb_, nb_) { *(mb_) = 4032; *(nb_) = 1; }

#endif  /* end protection around header file contents */
