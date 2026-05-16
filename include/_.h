/*                 __
				  /\ \
 __  __    ___    \_\ \     __   _ __   ____    ___    ___   _ __    __
/\ \/\ \ /' _ `\  /'_` \  /'__`\/\`'__\/',__\  /'___\ / __`\/\`'__\/'__`\
\ \ \_\ \/\ \/\ \/\ \L\ \/\  __/\ \ \//\__, `\/\ \__//\ \L\ \ \ \//\  __/
 \ \____/\ \_\ \_\ \___,_\ \____\\ \_\\/\____/\ \____\ \____/\ \_\\ \____\
  \/___/  \/_/\/_/\/__,_ /\/____/ \/_/ \/___/  \/____/\/___/  \/_/ \/____/.h */

#ifndef _H
#define _H

/* Only including libraries available to freestanding C implementations. */

/* va_list, va_copy, va_arg, va_start, va_end */
#include <stdarg.h>

#include <stdbool.h>

/* offsetof, nullptr_t, ptrdiff_t, size_t */
#include <stddef.h>

#include <stdint.h>

// BEGIN MACROS //

/* Evaluates to the in-memory alignment of an object or type. */
#define alignment(...) alignof(__VA_ARGS__)

/* Precedes a block that always executes. */
#define always if (true)

#define bits(...) (size(__VA_ARGS__) * CHAR_BIT)

/* Evaluates to the base address of an instance of structure `T` via the field
 * name `field` and the field address `x`. */
#define container(x, field, ...) \
	((TypeOf(__VA_ARGS__) *)((Byte *)(x) - offset(T, field)))

/* Writes a string containing an expression and its evluation to stderr. Will
 * only evaluate the relevant expression once. Obviously will only work if
 * <stdio.h> has been included in the project or if fputs and fprintf have been
 * defined elsewhere. */
#define debug(...)                                                             \
	do                                                                         \
	{                                                                          \
		fputs(typeNameOf(quote(__VA_ARGS__) " == (" __VA_ARGS__) ")", stderr); \
		fprintf(stderr, specifier(__VA_ARGS__), (__VA_ARGS__));                \
		fputs(";\n", stderr);                                                  \
	}                                                                          \
	done

/* Precedes a loop that never executes or follows a do-loop that only executes
 * once. */
#define done while (false)

/* Evaluates to an expression specified by the (given type or) type of the
 * given object. */
#define generic(...) _Generic(__VA_ARGS__)

#define Integer(width) TypeOf(signed _BitInt(width))

/* Evaluates to the in-memory length of an array or array type. */
#define length(...) (size(__VA_ARGS__) / size(*__VA_ARGS__))

/* Precedes a loop that will not end without an explicit break. */
#define loop while (true)

#define Natural(width) TypeOf(unsigned _BitInt(width))

/* Precedes a block that will never execute. */
#define never if (false)

/* Evaluates to the null pointer. */
#define null nullptr

/* Evaluates to the in-memory offset of `field` from the origin of
 * structure `T`. */
#define offset(field, ...) offsetof(TypeOf(__VA_ARGS__), field)

#define paste(a, b) rawpaste(a, b)

#define quote(...) rawquote(__VA_ARGS__)

#define rawpaste(a, b) a##b

#define rawquote(...) #__VA_ARGS__

/* Evaluates to the in-memory size of an object or type. */
#define size(...) sizeof(__VA_ARGS__)

/* Evaluates to a literal string containing a format specifier for the given
 * type.
 * [TODO] Complete this. */
#define specifier(...) generic((__VA_ARGS__),     \
							   Byte * : "\"%s\"", \
							   default : "%p")

/* Evaluates to the type of a type. Used for aliasing. */
#define Type(...) typedef TypeOf(__VA_ARGS__)

#define typeNameOf(...) generic((__VA_ARGS__), default : "Unknown")

/* Evaluates to the type of its argument, or its identity if it is a type. */
#define TypeOf(...) typeof(__VA_ARGS__)

/* Evaluates to the unqualified type of a type. Used for aliasing. */
#define UnqualifiedType(...) typedef UnqualifiedTypeOf(__VA_ARGS__)

/* Evaluates to the type of its argument without qualifiers, or to the
 * unqualified version of itself if it is a type. */
#define UnqualifiedTypeOf(...) typeof_unqual(__VA_ARGS__)

/* Evaluates to a copy of an instance of Val. */
#define Val_copy(target, source) va_copy(target, source)

/* Ends access lifetime of a Val. */
#define Val_end(val) va_end(val)

/* Evaluates to the next argument from a Val with type `Type` and moves
 * its index forward. */
#define Val_pop(val, Type) va_arg(val, Type)

/* Begins access lifetime of a Val. */
#define Val_start(val, ...) va_start(val __VA_OPT__(, ) __VA_ARGS__)

// END MACROS //

/* Type of a boolean value, defined as only using a single bit (though it is
 * possibly and usually padded to a single byte). If you want actualy single
 * bits in structures use these in conjunction with a bitfield. */
Type(bool) Bit;

/* Type of the native machine byte (usually 8 bits). */
Type(char) Byte;

Type(signed int) Integer;

Type(signed char) IntegerByte;

Type(signed long) IntegerLong;

Type(signed long long) IntegerLonger;

Type(intmax_t) IntegerLongest;

Type(intptr_t) IntegerPointer;

Type(signed short) IntegerShort;

/* Type of the native object with the greatest alignment. */
Type(max_align_t) MaximallyAligned;

Type(unsigned int) Natural;

Type(unsigned char) NaturalByte;

Type(unsigned long) NaturalLong;

Type(unsigned long long) NaturalLonger;

Type(uintmax_t) NaturalLongest;

Type(uintptr_t) NaturalPointer;

Type(unsigned short) NaturalShort;

/* Type of the null pointer. */
Type(null) Null;

/* Type of pointer arithmetic. */
Type((Byte *)0 - (Byte *)0) Offset;

/* Type of a variadic argument list. */
Type(va_list) Val;

/* Type that has no values. */
Type(void) Void;

Type(double) Real;

Type(long double) RealLong;

Type(float) RealShort;

/* Type of unsigned size of objects. */
Type(size(0)) Size;

/* Type of UTF16 codepoint. */
Type(*u"") Utf16;

/* Type of UTF32 codepoint. */
Type(*U"") Utf32;

/* Type of UTF8 codepoint. */
Type(*u8"") Utf8;

#endif // #ifndef _H
