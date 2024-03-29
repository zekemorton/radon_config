#ifndef ATLAS_SMVN_L1_H
#define ATLAS_SMVN_L1_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

#endif
void ATL_smvnk__2(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__2_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900005(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900005_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900007(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900007_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900004(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);
void ATL_smvnk__900004_b0(ATL_CINT, ATL_CINT, const float*, ATL_CINT, const float*, float*);

static ATL_mvkern_t ATL_GetMVNKern
   (ATL_CINT M, ATL_CINT N, const void *A, ATL_CINT lda,
    ATL_mvkern_t *mvk_b0, int *DOTBASED,
    int *mu, int *nu, int *minM, int *minN, int *alignX, int *ALIGNX2A,
    int *alignY, int *FNU, ATL_INT *CacheElts) 
{
   if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
   {
      *minM = 0;   *minN = 0;
      *mu = 8;     *nu = 4;
      *alignX = 4;  *alignY = 16;
      *ALIGNX2A = 1;
      *FNU = 0;
      *CacheElts = 4014;
      *mvk_b0 = ATL_smvnk__2_b0;
      *DOTBASED = 0;
      return(ATL_smvnk__2);
   } /* end if on lda multiple restriction */
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 8)
         {
            if (M >= 48)
            {
               *minM = 48;   *minN = 8;
               *mu = 48;     *nu = 8;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 4014;
               *mvk_b0 = ATL_smvnk__900005_b0;
               *DOTBASED = 0;
               return(ATL_smvnk__900005);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 4)
         {
            if (M >= 64)
            {
               *minM = 64;   *minN = 4;
               *mu = 64;     *nu = 4;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 4014;
               *mvk_b0 = ATL_smvnk__900007_b0;
               *DOTBASED = 0;
               return(ATL_smvnk__900007);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 48;   *minN = 8;
   *mu = 48;     *nu = 8;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 4014;
   *mvk_b0 = ATL_smvnk__900004_b0;
   *DOTBASED = 0;
   return(ATL_smvnk__900004);
}

#define ATL_GetPartMVN(A_, lda_, mb_, nb_) { *(mb_) = 192; *(nb_) = 8; }

#endif  /* end protection around header file contents */
