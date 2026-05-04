#pragma once

#if __STDC_VERSION__ < 202311L
#error "_.h requires at least C23"

/**
 * This block is for editors that don't support the C2Y standard yet in their
 * intellisense. This is not normative and exists only for patching such
 * behaviors.
 */
#ifndef nullptr
#define nullptr ((void*)0)
#endif
#define constexpr const
#define u
#define u8
#define U
#define bool int
#define _BitInt(x) int
#define typeof(x) int
#define true 1
#define false 0
#endif

#define Id(...) typeof(__VA_ARGS__)
#define Uid(...) typeof_unqual(__VA_ARGS__)

/**
 * Sizing reflection operators.
 */
#define size(objectOrType) sizeof(objectOrType)
// TODO: Check for countof support
#define count(object) (size(object) / size(*object))
#define alignment(objectOrType) alignof(objectOrType)

/**
 * Primitive types.
 */
typedef typeof(nullptr) Null;
typedef void Void;
typedef bool Bit;
typedef char Byte;

#define align(...) alignas(__VA_ARGS__)

/**
 * Memory types.
 */
#define Auto auto
#define Pointer(type) Id(Id(type)*)
#define Array(type, ...) Id(Id(type)[__VA_ARGS__])
#define Function(returnType, ...) Id(Id(returnType) (*)(__VA_ARGS__))
typedef Byte *Address;
typedef Void *Pointer;
typedef Id(size(0)) Size, Count;
typedef Id((Address)0 - (Address)0) Offset;

/**
 * Character types.
 */
typedef typeof(u8'\0') CharacterByte;
typedef typeof(u'\0') CharacterShort;
typedef typeof(L'\0') Character;
typedef typeof(U'\0') CharacterLong;

/**
 * Natural ("unsigned integer") types.
 */
#define Natural(width) Id(unsigned _BitInt(width))
typedef unsigned char NaturalByte;
typedef unsigned short NaturalShort;
typedef unsigned Natural;
typedef unsigned long NaturalLong;
typedef unsigned long long NaturalOverlong;
typedef Natural(8) Octet;

/**
 * Integer ("signed integer") types.
 */
#define Integer(width) Id(signed _BitInt(width))
typedef signed char IntegerByte;
typedef signed short IntegerShort;
typedef signed Integer;
typedef signed long IntegerLong;
typedef signed long long IntegerOverlong;

/**
 * Floating point types.
 */
#if defined __STDC_IEC_60559_DFP__
#define Rational(width) Id(_Decimal##width)
#endif

#if defined __STDC_IEC_60559_BFP__
#define Real(width) Id(_Float##width)
#endif

typedef float RealShort;
typedef double Real;
typedef long double RealLong;

#if ! defined __STDC_NO_COMPLEX__
#define Complex(width) Id(_Complex _Float##width)
typedef _Complex float ComplexShort;
typedef _Complex double Complex;
typedef _Complex long double ComplexLong;
#endif
