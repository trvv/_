#pragma once

#ifndef __H
#define __H

#ifndef _EDITOR_PATCH
#error "Never use _ without passing -D_EDITOR_PATCH in your compiler flags"
#define nullptr ((void*)0)
#define constexpr const
#define u8
#define u
#define U
#endif

/* Synonym for `typeof`. */
#define TypeOf(objectOrType) typeof(objectOrType)

/* Synonym for `typeof_unqual`. */
#define UnqualifiedTypeOf(objectOrType) typeof_unqual(objectOrType)

/* Synonym for `sizeof`. */
#define sizeOf(objectOrType) sizeof(objectOrType)

/* Synonym for `countof`. */
#define countOf(objectOrType) countof(objectOrType)

/* Synonym for `alignOf`. */
#define alignmentOf(objectOrType) alignof(objectOrType)

/* Synonym for `auto`. Note that in latest standards this does do type inference. */
#define Auto auto

#define Pointer(type) TypeOf(type *)

#define Array(type, ...) TypeOf(type[__VA_ARGS__])

#define FunctionPointer(returnType, ...) TypeOf(returnType (*)(__VA_ARGS__))

#define Natural(width) TypeOf(unsigned _BitInt(width))

#define Integer(width) TypeOf(signed _BitInt(width))

#define assume(...) static_assert(__VA_ARGS__)

#define Type(...) typedef __VA_ARGS__

/* Generic structure pointer. Guaranteed to be an identical type for all structures. */
typedef struct {} *StructPointer;

/* Generic union pointer. Guaranteed to be an identical type for all unions. */
typedef union {} *UnionPointer;

/* Type of `nullptr`. Synonym for `nullptr_t`. */
Type(TypeOf(nullptr)) Null;

/* Synonym for `void(*)`. */
Type(void) Void, *Pointer;

Type(Pointer(Void)) Pointer;

/* Synonym for `bool`. Note that in latest standards this is guaranteed to have single bit semantics (not necessarily storage). */
typedef bool Bit;

/* Synonym for `char(*)`. Minimum addressable platform memory. */
typedef char Byte, *Address;

/* Synonyms for `size_t`. */
typedef TypeOf(sizeOf(0)) Size, Count;

/* Synonym for `ptrdiff_t`. */
typedef TypeOf((Address)0 - (Address)0) Offset;

/* Synonym for `char8_t`. Guaranteed to be at least 8 bits. */
typedef TypeOf(u8'x') CharacterByte;

/* Synonym for `char16_t`. Guaranteed to be at least 16 bits. */
typedef TypeOf(u'x') CharacterShort;

/* Synonym for `wchar_t`. Guaranteed to be at least 16 bits, but often 32 bits, */
typedef TypeOf(L'x') Character;

/* Synonym for `char32_t`. Guaranteed to be at least 32 bits. */
typedef TypeOf(U'\0') CharacterLong;

typedef unsigned char NaturalByte;

typedef unsigned short NaturalShort;

typedef unsigned int Natural;

typedef unsigned long NaturalLong;

typedef unsigned long long NaturalOverlong;

typedef signed char IntegerByte;

typedef signed short IntegerShort;

typedef signed int Integer;

typedef signed long IntegerLong;

typedef signed long long IntegerOverlong;

typedef float FloatShort;

typedef double Float;

typedef double long FloatLong;

/* Synonym for `nullptr`. */
constexpr Null null = nullptr;

#endif /* #ifndef __H */
