#ifndef _GLOSS_H
#define _GLOSS_H

#define struct(name) typedef struct name name, *name##Address; struct name
#define enum(name, ...) __VA_OPT__(enum name : __VA_ARGS__;) typedef enum name name, *name##Address; enum name __VA_OPT__(:) __VA_ARGS__
#define union(name, ...) typedef union name name, *name##Address; union name

#endif /* _GLOSS_H */
