#ifndef _DEBUG_UTILS_H_
#define _DEBUG_UTILS_H_

/*
 * Bit flags for DEBUG()
 */
#define DB_GENERAL 0x0001
 // #define DB_a        0x0002
 // #define DB_b        0x0004
 // #define DB_c        0x0008
 // #define DB_d        0x0010
 // #define DB_e        0x0020
 // #define DB_f        0x0040
 // #define DB_g        0x0080
 // #define DB_h        0x0100
 // #define DB_i        0x0200
 // #define DB_j        0x0400
 // #define DB_k        0x0800
 // #define DB_l        0x1000

extern unsigned int dbflags;

/*
 * DEBUG() is for conditionally printing debug messages to the console.
 *
 * The idea is to put lots of lines of the form
 *
 *      DEBUG(DB_GENERAL, "Current EXP: %d\n", curr_exp);
 */
#define DEBUG(d, ...) ((dbflags & (d)) ? printf(__VA_ARGS__) : 0)

#endif