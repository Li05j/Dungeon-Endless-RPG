#ifndef _DEBUG_UTILS_H_
#define _DEBUG_UTILS_H_

/*
 * Bit flags for DEBUG()
 */
#define DB_GENERAL 0x0001
// #define DB_SYSCALL     0x0002
// #define DB_INTERRUPT   0x0004
// #define DB_DEVICE      0x0008
// #define DB_THREADS     0x0010
// #define DB_VM          0x0020
// #define DB_EXEC        0x0040
// #define DB_VFS         0x0080
// #define DB_SFS         0x0100
// #define DB_NET         0x0200
// #define DB_NETFS       0x0400
// #define DB_KMALLOC     0x0800
// #define DB_SYNCPROB    0x1000

extern unsigned int dbflags;

/*
 * DEBUG() is for conditionally printing debug messages to the console.
 *
 * The idea is that you put lots of lines of the form
 *
 *      DEBUG(DB_GENERAL, "Current EXP: %d\n", curr_exp);
 *
 * DEBUG is a varargs macro. These were added to the language in C99.
 */
#define DEBUG(d, ...) ((dbflags & (d)) ? printf(__VA_ARGS__) : 0)

#endif