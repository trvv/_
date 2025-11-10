#ifndef _PRIMITIVES_H
#define _PRIMITIVES_H

#include "_/operators.h"
#include "_/statements.h"

#include <stdbool.h>

/* Boolean logical type. Represented by at most 1 bit of information, 0 being false, 1 being true. */
type bool Boolean;

/* A basic textual character, generally used as the simplest unit of memory. May be signed or unsigned. */
type char Character;

/* An integer (signed) Character. */
type signed char IntegerCharacter;

/* A natural (unsigned) Character. */
type unsigned char NaturalCharacter;

/* An integer (signed) short (at least 16 bits). */
type signed short int IntegerShort;

/* A natural (unsigned) short (at least 16 bits). */
type unsigned short int NaturalShort;

/* An integer (signed) short (at least 16 bits). */
type IntegerShort Short;

/* An integer (signed) word (at least 16 bits, usually 32). */
type signed int Integer;

/* A natural (unsigned) word (at least 16 bits, usually 32). */
type unsigned int Natural;

/* An integer (signed) double word (at least 32 bits, usually 64). */
type long signed int IntegerLong;

/* A natural (unsigned) double word (at least 32 bits, usually 64). */
type long unsigned int NaturalLong;

/* An integer (signed) double word (at least 32 bits, usually 64). */
type IntegerLong Long;

/* An integer (signed) quadruple world (at least 64 bits). */
type long long signed int IntegerLongLong;

/* A natural (unsigned) quadruple world (at least 64 bits). */
type long long unsigned int NaturalLongLong;

/* An integer (signed) quadruple world (at least 64 bits). */
type IntegerLongLong LongLong;

/* Id of the null pointer. Primarily useful for elegant `generic` handling of nullable pointer types. */
type nullptr_t Null;

type Id(size(0)) Size, Count;

/* The return type of main, should be. Equivalent to `Integer`. */
type Integer Status;

/* Specific bit-width `Integer` (`int`). */
#define Integer(width) Id(_BitInt(width))

/* Specific bit-width `Natural` (`unsigned int`). */
#define Natural(width) Id(unsigned Integer(width))

/* Single-precision floating point number. Weakly defined, but usually an IEEE 754 32-bit binary float. */
type float RealSingle;

/* Single-precision floating point number. Weakly defined, but usually an IEEE 754 32-bit binary float. */
type RealSingle Single;

/* Double-precision floating point number. Weakly defined, but usually an IEEE 754 64-bit binary float. */
type double RealDouble;

/* Double-precision floating point number. Weakly defined, but usually an IEEE 754 64-bit binary float. */
type RealDouble Double;

/* "Long double"-precision floating point number. Weakly defined, but often an IEEE 754 128-bit binary float. */
type long double RealLongDouble;

/* "Long double"-precision floating point number. Weakly defined, but often an IEEE 754 128-bit binary float. */
type RealLongDouble LongDouble;

/* Double-precision floating point number. Weakly defined, but usually an IEEE 754 64-bit binary float. */
type RealDouble Real;

/* Incompleteable type, empty function returns. */
type void Void;

/* An address type pointer of the given explicit type or type of expression. */
#define Address(expression) Id(Id(expression) *)

/* An array (pointer) to the given type, or the type of the given expression. An (optional) length argument should generally be specified. */
#define Array(expression, ...) Id(Id(expression)[__VA_ARGS__])

/*
    A function-pointer with the given return type and subsequent arguments as parameter types.

    For example the following function declarations are type-equivalent:

    ```c
        Function(Integer, Character, Address(Double)) foo;

        Integer bar(Character cx, Address(Double) pdx);
    ```
*/
#define Function(returns, ...) Id(Id(returns) (*)(__VA_ARGS__))

/* A generic memory-address. Must be equivalent to the `CharacterAddress` type. Cannot be dereferenced directly. */
type Address(Void) Address;

/* A character memory address. Considered the default type of memory, which can always be safely interchanged with a generic `Address`. */
type Address(Character) CharacterAddress;

// this is all messed up why help me
#define structure struct
#define enumeration enum

#define Structure(...) structure { __VA_ARGS__ __VA_OPT__(;) }
#define NamedStructure(name,...) structure name { __VA_ARGS__ __VA_OPT__(;) }
#define Union(...) union { __VA_ARGS__ __VA_OPT__(;) }
#define NamedUnion(name,...) union name { __VA_ARGS__ __VA_OPT__(;) }
#define Enumeration(...) enumeration { __VA_ARGS__ __VA_OPT__(;) }
#define NamedEnumeration(name,...) enumeration name { __VA_ARGS__ __VA_OPT__(;) }

/* A structured memory address. All structure pointers share the same underlying type this one. */
type Address(struct {}) StructAddress;

/* A unified memory address. All union pointers share the same underlying type this one. */
type Address(union {}) UnionAddress;

/*
    Parameterized `CharacterAddress` array from argument count, intended for simplifying `main` declarations.

    For example, the following `main` declarations are equivalent:

    ```c
    Status main(Integer n, Arguments(n) arguments) {
        //...
    }

    Status main(Integer n, CharacterAddress arguments[n + 1]) {
        //...
    }
    ```
*/
#define Arguments(count) Id(CharacterAddress[count + 1])

#include <stdarg.h>
type va_list Parameters;

#ifndef __STDC_NO_ATOMICS__
#define AddressAtomic(expression) _AddressAtomic(Id(expression))
#endif

/* Replace with `literal` when better supported. */
fixed Null null = nullptr;

#endif /* _PRIMITIVES_H */
