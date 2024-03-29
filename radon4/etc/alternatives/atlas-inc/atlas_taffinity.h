/* Generated by /builddir/build/BUILD/ATLAS/x86_64_base/..//CONFIG/src/probe_aff.c */
#ifndef ATL_TAFFINITY_H
   #define ATL_TAFFINITY_H

#define _GNU_SOURCE 1 /* what manpage says you need to get CPU_SET */
#define __USE_GNU   1 /* what actually works on linuxes I've seen */
#include <sched.h>    /* must be included with above defs before pthread.h */

#define ATL_HAS_AFFINITY 1
#define ATL_PAFF_SETAFFNP 1
#define ATL_PAFF_LAUNCH 1  /* affinity can be set during thread launch */
#define ATL_AFF_NUMID 32
#define ATL_AFF_IDSTRIDE 1
#define ATL_RANK_IS_PROCESSORID 1 /* good IDs [0,31] */

#endif /* end multiple inclusion guard */
