#ifndef ATLAS_DMVN_L1_H
#define ATLAS_DMVN_L1_H

#include "atlas_type.h"

#ifndef ATL_MVKERN_DEF
   #define ATL_MVKERN_DEF
   typedef void (*ATL_mvkern_t)
      (ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

#endif
void ATL_dmvnk__900009(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvnk__900009_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvnk__900003(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvnk__900003_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvnk__900008(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);
void ATL_dmvnk__900008_b0(ATL_CINT, ATL_CINT, const double*, ATL_CINT, const double*, double*);

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
         if (N >= 8)
         {
            if (M >= 24)
            {
               *minM = 24;   *minN = 8;
               *mu = 24;     *nu = 8;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 2048;
               *mvk_b0 = ATL_dmvnk__900009_b0;
               *DOTBASED = 0;
               return(ATL_dmvnk__900009);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   if ((((((((size_t)(A))) >> 4)) << 4)) == (size_t)(A))
   {
      if ((((((ATL_MulBySize(lda)) >> 4)) << 4)) == ATL_MulBySize(lda))
      {
         if (N >= 2)
         {
            if (M >= 16)
            {
               *minM = 16;   *minN = 2;
               *mu = 16;     *nu = 2;
               *alignX = 16;  *alignY = 16;
               *ALIGNX2A = 0;
               *FNU = 1;
               *CacheElts = 2048;
               *mvk_b0 = ATL_dmvnk__900003_b0;
               *DOTBASED = 0;
               return(ATL_dmvnk__900003);
            } /* end if on minimal N guard */
         } /* end if on minimal M guard */
      } /* end if on lda multiple restriction */
   } /* end if on align of A */
   *minM = 24;   *minN = 8;
   *mu = 24;     *nu = 8;
   *alignX = 16;  *alignY = 16;
   *ALIGNX2A = 0;
   *FNU = 1;
   *CacheElts = 2048;
   *mvk_b0 = ATL_dmvnk__900008_b0;
   *DOTBASED = 0;
   return(ATL_dmvnk__900008);
}

#define ATL_GetPartMVN(A_, lda_, mb_, nb_) { *(mb_) = 96; *(nb_) = 8; }

#endif  /* end protection around header file contents */
