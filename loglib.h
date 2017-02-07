/**
 * Created by aria on 1/28/17.
 */

#ifndef LC_3B_ASSEMBLY_PRINTTOOLS_H
#define LC_3B_ASSEMBLY_PRINTTOOLS_H

#include <stdbool.h>

#define ANRM  "\x1B[0m"
#define ARED  "\x1B[31m"
#define AGRN  "\x1B[32m"
#define AYEL  "\x1B[33m"
#define ABLU  "\x1B[34m"
#define AMAG  "\x1B[35m"
#define ACYN  "\x1B[36m"
#define AWHT  "\x1B[37m"

enum DATA_TYPE{
    PTR,
    CHAR,
    INT_8,
    INT_16,
    INT_32,
    INT_64,
    UINT_8,
    UINT_16,
    UINT_32,
    UINT_64,
    STR,
    INT,
    LONG,
    LONG_INT,
    ULONG,
    ULONG_INT,
    S,
    I,
    L,
    C,
    P,
    I8,
    I16,
    I32,
    I64,
    UI,
    UI8,
    UI16,
    UI32,
    UI64,
    UL,
    ULI,
    LI,
    N,
    ENDL,
    T,
    TAB
};

enum LOG_LEVELS{
    DEBUG,
    INFO,
    WARN,
    ERROR,
    NONE
};

const static char * enumStrings[] = {"DEBUG", "INFO", "WARN", "ERROR"};


void loggingMsg(enum LOG_LEVELS lvl, char * msg);

/**
 * Example:
 *       logging(DEBUG,
 *               1,
 *               S, "Some message"
 *       );
 * @param lvl
 *          logging level of this file
 * @param num
 *          number of message arguments
 * @param ...
 *          message arguments
 *          (S, ""
 *              or
 *          I, 1
 *              or
 *          C, 'a')
 */
void logging(enum LOG_LEVELS lvl, int num, ...);

void print(int num, ...);

void println(int num, ...);


#endif /*LC_3B_ASSEMBLY_PRINTTOOLS_H*/
