#ifndef _SPECIFIERS_H
#define _SPECIFIERS_H

/* Compile-time-constant storage specifier. */
#define literal constexpr

/* Externally linked storage specifier. */
#define external extern

/* No linkage and automatic storage duration (block-scoped). When used without type specifiers the type will be inferred automatically. */
#define local auto

/* Internally linked and static lifetime storage specifier. */
#define internal static

/* Will (probably) not be kept in memory, so don't count on it. */
#define ephemeral register

/* Specify a declaration as being thread-local. May be combined with `internal` or `external`. */
#define several thread_local

#endif /* _SPECIFIERS_H */
