  /* This file generated by /builddir/build/BUILD/ATLAS/x86_64_base/..//tune/threads/probe_nthr.c */
#ifndef ATLAS_NTHREADS_H
   #define ATLAS_NTHREADS_H

#include "pthread.h"
   #define ATL_NTHREADS 4
   #define ATL_NTHRPOW2 2
   #ifdef ATL_LAUNCHORDER
       static int ATL_launchorder[4] = {0,2,1,3};
   #endif

#endif
