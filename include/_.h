/*                 __
				  /\ \
 __  __    ___    \_\ \     __   _ __   ____    ___    ___   _ __    __
/\ \/\ \ /' _ `\  /'_` \  /'__`\/\`'__\/',__\  /'___\ / __`\/\`'__\/'__`\
\ \ \_\ \/\ \/\ \/\ \L\ \/\  __/\ \ \//\__, `\/\ \__//\ \L\ \ \ \//\  __/
 \ \____/\ \_\ \_\ \___,_\ \____\\ \_\\/\____/\ \____\ \____/\ \_\\ \____\
  \/___/  \/_/\/_/\/__,_ /\/____/ \/_/ \/___/  \/____/\/___/  \/_/ \/____/ */

#ifndef UNDERSCORE_H
#define UNDERSCORE_H

/* va_list, va_copy, va_arg, va_start, va_end */
#include <stdarg.h>

/* offsetof, nullptr_t, ptrdiff_t, size_t */
#include <stddef.h>

// BEGIN MACROS //

/* Evaluates to the in-memory alignment of an object or type. */
#define alignment(...) alignof(__VA_ARGS__)

/* Precedes a block that always executes. */
#define always if (true)

/* Evaluates to the base address of an instance of structure `T` via the field
 * name `field` and the field address `x`. */
#define container(x, field, ...) \
    ((TypeOf(__VA_ARGS__)*)((Byte*)(x) - offset(T, field)))

/* Writes a string containing an expression and its evluation to stderr. Will
 * only evaluate the relevant expression once. Obviously will only work if
 * <stdio.h> has been included in the project or if fputs and fprintf have been
 * defined elsewhere. */
#define debug(...) do {                                         \
        fputs(#__VA_ARGS__ ": ", stderr);                       \
	    fprintf(stderr, specifier(__VA_ARGS__), (__VA_ARGS__)); \
	    fputc('\n', stderr);                                    \
    } done

/* Precedes a loop that never executes or follows a do-loop that only executes
 * once. */
#define done while (false)

/* Evaluates to an expression specified by the (given type or) type of the
 * given object. */
#define generic(...) _Generic(__VA_ARGS__)

/* Evaluates to the in-memory length of an array or array type. */
#define length(...) (size(__VA_ARGS__) / size(*__VA_ARGS__))

/* Precedes an inferred declaration-definition. */
#define let auto

/* Precedes a loop that will not end without an explicit break. */
#define loop while (true)

/* Precedes a block that will never execute. */
#define never if (false)

/* Evaluates to the null pointer. */
#define null nullptr

/* Evaluates to the in-memory offset of `field` from the origin of
 * structure `T`. */
#define offset(field, ...) offsetof(TypeOf(__VA_ARGS__), field)

/* Evaluates to the in-memory size of an object or type. */
#define size(...) sizeof(__VA_ARGS__)

/* Evaluates to a literal string containing a format specifier for the given
 * type.
 * [TODO] Complete this. */
#define specifier(...) generic((__VA_ARGS__), \
        Byte * : "\"%s\"", \
        default : "%p" \
    )

/* Evaluates to the type of a type. Used for aliasing. */
#define Type(...) typedef TypeOf(__VA_ARGS__)

/* Evaluates to the type of its argument, or its identity if it is a type. */
#define TypeOf(...) typeof(__VA_ARGS__)

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

/* Type of a boolean value, defined as only using a single byte (though it is
 * possibly and usually padded to a single byte). If you want actualy single
 * bits in structures use these in conjunction with a bitfield. */
Type(bool) Bit;

/* Type of the native machine byte (usually 8 bits, but not always). */
Type(char) Byte;

/* Type of the native object with the greatest alignment. */
Type(max_align_t) MaximallyAligned;

/* Type of the null pointer. */
Type(TypeOf(null)) Null;

/* Type of pointer arithmetic. */
Type(ptrdiff_t) Offset;

/* Type of a variadic argument list. */
Type(va_list) Val;

/* Type that has no values. */
Type(void) Void;

/* Type of unsigned size of objects. */
Type(size_t) Size;

/* Type of UTF8 codepoint. */
Type(*u8"") Utf8;

/* Type of UTF16 codepoint. */
Type(*u"") Utf16;

/* Type of UTF32 codepoint. */
Type(*U"") Utf32;

#endif // #ifndef UNDERSCORE_H
