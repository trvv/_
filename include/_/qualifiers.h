#ifndef _QUALIFIERS_H
#define _QUALIFIERS_H

#include "_/operators.h"

#define align(size) alignas(size)

#define unique restrict

#ifndef __STDC_NO_ATOMICS__
#define atomic _Atomic
#endif

// #define volatile volatile
// #define labile volatile // this one is just funny :)

#define fixed const

#endif /* _QUALIFIERS_H */
