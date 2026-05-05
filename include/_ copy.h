/*                 __
				  /\ \
 __  __    ___    \_\ \     __   _ __   ____    ___    ___   _ __    __
/\ \/\ \ /' _ `\  /'_` \  /'__`\/\`'__\/',__\  /'___\ / __`\/\`'__\/'__`\
\ \ \_\ \/\ \/\ \/\ \L\ \/\  __/\ \ \//\__, `\/\ \__//\ \L\ \ \ \//\  __/
 \ \____/\ \_\ \_\ \___,_\ \____\\ \_\\/\____/\ \____\ \____/\ \_\\ \____\
  \/___/  \/_/\/_/\/__,_ /\/____/ \/_/ \/___/  \/____/\/___/  \/_/ \/____/ */

#ifndef UNDERSCORE_H
#define UNDERSCORE_H

#include <float.h>
// #include <iso646.h> // Should not be included
#include <limits.h>
// #include <stdalign.h> // This doesn't do anything in C23+
#include <stdarg.h>
// #include <stdbit.h> // Not supported by clangd
// #include <stdbool.h>	 // This doesn't do anything in C23+
#include <stddef.h>
#include <stdint.h>
// #include <stdnoreturn.h> // This doesn't do anything in C23+

/* For ease of reading type definitions. */
#define Type(T) typedef TypeOf(T)

/* Syntax prettification. */
#define let auto
#define forever for (;;)
#define done while (false) // This should only be used for do-loops
#define always if (true)
#define never if (false)
#define typeSwitch _Generic

#define sizeOf(...) sizeof(__VA_ARGS__)
#define offsetOf(...) offsetof(__VA_ARGS__)
#define lengthOf(...) (sizeOf(__VA_ARGS__) / sizeOf(*__VA_ARGS__))
#define TypeOf(...) TypeOf(__VA_ARGS__)
#define unqualifiedTypeOf(...) TypeOf_unqual(__VA_ARGS__)
#define alignmentOf(...) alignof(__VA_ARGS__)
#define Aligned(T, N) alignas(N) T
#define Constant(T) const T
#define Volatile(T) volatile T
#define Restricted(T) restrict T
#define ConstantExpression(T) constexpr T

#define formatOf(x) typeSwitch((x), Byte * : "\"%s\"", default : "%p")

#define debug(x)                         \
	do                                   \
	{                                    \
		fputs(#x ": ", stderr);          \
		fprintf(stderr, formatOf(x), x); \
		fputc('\n', stderr);             \
	}                                    \
	done

Type(void *) Pointer;

// constexpr Null null = nullptr;
#define null nullptr

Type(ptrdiff_t) Offset;

Type(size_t) Size;

Type(max_align_t) MaximallyAligned;

Type(*u8"") Utf8;
Type(*u"") Utf16;
Type(*U"") Utf32;

Type(bool) Bit;

Type(char) Byte;

Type(signed) Integer;
Type(signed char) IntegerByte;
Type(signed short) IntegerShort, Short;
Type(signed long) IntegerLong, Long;
Type(signed long long) IntegerOverlong, Overlong;
#define IntegerExact(width) TypeOf(int##width##_t)
Type(IntegerExact(ptr)) IntegerPointer;
Type(IntegerExact(max)) IntegerMaximum;
// gate exact types
Type(IntegerExact(8)) Integer8;
Type(IntegerExact(16)) Integer16;
Type(IntegerExact(32)) Integer32;
Type(IntegerExact(64)) Integer64;
#define Integer(width) TypeOf(signed _BitInt(width))

Type(unsigned) Natural;
Type(unsigned char) NaturalByte;
Type(unsigned short) NaturalShort;
Type(unsigned long) NaturalLong;
Type(unsigned long long) NaturalOverlong;
#define NaturalExact(width) TypeOf(uint##width##_t)
Type(NaturalExact(ptr)) NaturalPointer;
Type(NaturalExact(max)) NaturalMaximum;
// gate exact types
Type(NaturalExact(8)) Natural8;
Type(NaturalExact(16)) Natural16;
Type(NaturalExact(32)) Natural32;
Type(NaturalExact(64)) Natural64;
#define Natural(width) TypeOf(unsigned _BitInt(width))

Type(double) Real, RealDouble, Double;
Type(float) RealSingle, Single;
Type(double long) RealLongDouble, LongDouble;
#define RealExact(width) TypeOf(_Float##width)

#ifndef __STDC_NO_COMPLEX__
Type(_Complex double) Complex;
Type(_Complex float) ComplexShort;
Type(_Complex double long) ComplexLong;
#define ComplexExact(width) TypeOf(_Complex _Float##width)
#endif

// not the real macro hint
#ifdef __STDC_DECIMAL__
Type(_Decimal32) Decimal32;
Type(_Decimal64) Decimal, Decimal64;
Type(_Decimal128) Decimal128;
#endif

#endif // #ifndef UNDERSCORE_H
