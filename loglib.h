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
#define debug EOL, __FUNCTION__, __LINE__, DEBUG
#define info EOL, __FUNCTION__, __LINE__, INFO
#define warn EOL, __FUNCTION__, __LINE__, WARN
#define error EOL, __FUNCTION__, __LINE__, ERROR
#define MAX_LOG_DEF_ARGS 4


enum DATA_TYPE {
    INSTRUCTION,
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
    Id,
    Ix,
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
    TAB,
    EOL
};

enum LOG_LEVELS{
    DEBUG,
    INFO,
    WARN,
    ERROR,
    NONE
};

const static char * enumStrings[] = {"DEBUG", "INFO", "WARN", "ERROR"};


/**
 * log your message with any number of arguments: string(S), int(I), int8_t(I8),
 *      double(D), long(L), Char(C), pointer(P), etc.,
 *      suffixed with proper log level: debug, info, warn, error
 *
 *
 *
 * Example 1:
 *
 *       logging(S, "My age is: ", Id, 23, debug);
 *
 * OUTPUT: [DEBUG]: <Caller Function> -> <Line Number> (<Log Number>)
 *         My age is 23  (<Log Number>)
 *
 *
 *
 * Example 2:
 *
 *       logging(C, 'c', S, " is not a valid character.", ENDL,
 *               S, "exit with error code ", I, 4, error);
 *
 * OUTPUT: [ERROR]: <Caller Function> -> <Line Number> (<Log Number>)
 *         c is not a valid character.
 *         exit with error code 4 (0x4) (<Log Number>)
 *
 */
void logging(int num, ...);

void loggingMsg(const char *msg, enum DATA_TYPE t, const char *func, int line, enum LOG_LEVELS lvl);

void print(int num, ...);

void println(int num, ...);


#endif /*LC_3B_ASSEMBLY_PRINTTOOLS_H*/
