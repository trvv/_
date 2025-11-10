#ifndef _OPERATORS_H
#define _OPERATORS_H

/* Logical AND. */
#define and &&

/* Logical OR. */
#define or ||

/* Logical NOT. */
#define not !

/* Reflect the address of an lvalue. */
#define address(lvalue) (&(lvalue))

/* Access the value at an address. */
#define value(address) (*(address))

/* Reflect an explicit type or the type of a given expression without qualifiers (e.g. `const`, `restrict`). */
#define Unqualify(expression) typeof_unqual(expression)

/* Reflect an explicit type or the type of a given expression. */
#define Id(expression) typeof(expression)

/* Report the storage size of an explicit type or the type of a given expression. */
#define size(expression) (sizeof(expression))

/* Report the storage alignment of an explicit type or the type of a given expression. */
#define alignment(expression) (alignof(expression))

/* Type selection statement. */
#define polymorphic _Generic

#define null(expression) ((Id(expression)){})

#define related(a, b) generic(null(Id(a) *), Id(b) * : 1, default : 0)
#define relatedUnqualified(a, b) generic(null(Unqualified(a) *), Unqualified(b) * : 1, default : 0)

#endif
