#pragma once

#include <cstdint>
#ifndef PRELUDE_H
#define PRELUDE_H

#define Any auto

#define Atomic(type) Identity(_Atomic Identity(type))

#define Constant(type) Identity(const Identity(type))

#define Identity(...) typeof(__VA_ARGS__)

#define Integer(width) Identity(_BitInt(width))

#define Natural(width) Identity(unsigned _BitInt(width))

#define paste(left, right) rawPaste(left, right)

#define quote(...) rawQuote(__VA_ARGS__)

#define rawPaste(left, right) left##right

#define rawQuote(...) #__VA_ARGS__

#define Restrict(type) Identity(restrict Identity(type))

#define Type(type) typedef Identity(type)

#define UnqualifiedIdentity(typeOrValue) typeof_unqual(typeOrValue)

#define Volatile(type) Identity(volatile Identity(type))

#define Pointer(type) Identity(Identity(type) *)

#define size(...) (sizeof(__VA_ARGS__))

Type(nullptr) Null;

// constexpr Null null = nullptr;
#define null nullptr

Type(void) Void;

Type(Pointer(Void)) Pointer;

Type(unsigned char) ByteNatural, Byte;
Type(signed char) ByteInteger;
Type(unsigned short) ShortNatural, Short;
Type(signed short) ShortInteger;
Type(unsigned int) Natural;
Type(signed int) Integer;
Type(unsigned long) LongNatural, Long;
Type(signed long) LongInteger;
Type(unsigned long long) OverlongNatural, Overlong;
Type(signed long long) OverlongInteger;

// not necessarily an nt string, but it can be used for that and string of
// bytes seems generic enough terminology. if you want a "String" compatible

#define struct(name, ...)     \
	typedef struct name name; \
	__VA_ARGS__ struct name
#define union(name, ...)     \
	typedef union name name; \
	__VA_ARGS__ union name
#define enum(name, ...)     \
	typedef enum name name; \
	enum name __VA_OPT__( :) __VA_ARGS__

Type(size(0)) Size, Count;

Type(Pointer(Byte)) String;

Type((String)0 - (String)0) Offset;

#include <stdint.h>

Type(intptr_t) IntegerAddress;
Type(uintptr_t) NaturalAddress, Address;

// kind of a misnomer. stuck at 128 bit for abi compatibility iirc
Type(intmax_t) IntegerMaximum;
Type(uintmax_t) NaturalMaximum, Maximum;

#ifdef INT8_WIDTH
Type(int8_t) Integer8;
#define Integer8(value) INT8_C(value)
#define hasInteger8 true
#else
#define hasInteger8 false
#endif
#ifdef UINT8_WIDTH
Type(uint8_t) Natural8, Octet;
#define Natural8(value) UINT8_C(value)
#define hasNatural8 true
#else
#define hasNatural8 false
#endif
#ifdef INT16_WIDTH
Type(int16_t) Integer16;
#define Integer16(value) INT16_C(value)
#endif

Type(float) RealShort;
Type(_Complex float) ComplexShort;
Type(double) Real;
Type(_Complex double) Complex;
Type(long double) RealLong;
Type(_Complex long double) ComplexLong;

#endif // PRELUDE_H
