#ifndef _STATEMENTS_H
#define _STATEMENTS_H

#include "_/operators.h"

/* Logically inverted `if` statement. */
#define unless(expression) if (not(expression))

/* Logically inverted `while` statement. */
#define until(expression) while (not(expression))

/* Block that will never evaluate (under normal control flow). */
#define never if (false)

/* Block that will always evaluate (under normal control flow). */
#define always if (true)

/* Block that will loop forever (under normal control flow). */
#define forever while (true)

/* Type-declaration gloss. Types follow the same syntax as regular variable
   declarations so we treat the keyword like a type itself (capitalized). */
#define type typedef

#endif
