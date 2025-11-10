#ifndef _META_H
#define _META_H

/* Convert argument(s) to a literal string. */
#define QUOTE(...) _QUOTE(__VA_ARGS__)
#define _QUOTE(...) #__VA_ARGS__

/* Concatenate argument tokens. */
#define PASTE(A, B) _PASTE(A, B)
#define _PASTE(A, B) A##B

/* Reflect the number of arguments as integer constant. (Maximum: 32) */
#define COUNT(...) _COUNT(__VA_ARGS__, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
                          20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _COUNT(_32, _31, _30, _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, _19, _18, _17, \
               _16, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...) N

/* Reflect arguments. */
#define ID(...) __VA_ARGS__

/* Reflect only the first argument. */
#define FIRST(...) _FIRST(__VA_ARGS__, )
#define _FIRST(A, ...) A

/* Reflect all but the first argument. */
#define REST(...) _REST(__VA_ARGS__)
#define _REST(A, ...) __VA_ARGS__

/* Sequence expressions relative to a subsequent block. */
#define SEQUENCE(before, after) for (int _sequence = (before, 1); _sequence; _sequence = (after, 0))

#endif /* _META_H */
