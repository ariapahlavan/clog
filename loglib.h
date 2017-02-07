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


/**
 * PTR         ---->   Pointer
 * CHAR        ---->   Character
 * INT_8       ---->   8-bit integer (decimal and hex format)
 * INT_16      ---->   16-bit integer (decimal and hex format)
 * INT_32      ---->   32-bit integer (decimal and hex format)
 * INT_64      ---->   64-bit integer (decimal and hex format)
 * UINT_8      ---->   8-bit unsigned integer (decimal and hex format)
 * UINT_16     ---->   16-bit unsigned integer (decimal and hex format)
 * UINT_32     ---->   32-bit unsigned integer (decimal and hex format)
 * UINT_64     ---->   64-bit unsigned integer (decimal and hex format)
 * STR         ---->   String
 * INT         ---->   Integer (decimal and hex format)
 * LONG        ---->   Long (decimal and hex format)
 * LONG_INT    ---->   Long integer (decimal and hex format)
 * ULONG       ---->   Unsigned long (decimal and hex format)
 * ULONG_INT   ---->   Unsigned long integer (decimal and hex format)
 * S           ---->   String
 * I           ---->   Integer (decimal and hex format)
 * Id          ---->   Integer (decimal format)
 * Ix          ---->   Integer (hex format)
 * L           ---->   Long (decimal and hex format)
 * C           ---->   Character
 * P           ---->   Pointer
 * I8          ---->   8-bit integer (decimal and hex format)
 * I16         ---->   16-bit integer (decimal and hex format)
 * I32         ---->   32-bit integer (decimal and hex format)
 * I64         ---->   64-bit integer (decimal and hex format)
 * UI          ---->   Unsigned Integer (decimal and hex format)
 * UI8         ---->   8-bit unsigned integer (decimal and hex format)
 * UI16        ---->   16-bit unsigned integer (decimal and hex format)
 * UI32        ---->   32-bit unsigned integer (decimal and hex format)
 * UI64        ---->   64-bit unsigned integer (decimal and hex format)
 * UL          ---->   Unsigned Long (decimal and hex format)
 * ULI         ---->   Unsigned long Integer (decimal and hex format)
 * LI          ---->   Long integer (decimal and hex format)
 * N           ---->   New line
 * ENDL        ---->   New line
 * T           ---->   Tab
 * TAB         ---->   Tab
 * EOL         ---->   End of log
 *
 * Clarification:
 *      decimal and hex format:     16 (0x10)
 *      decimal format:             16
 *      hex format:                 0x10
 */
enum DATA_TYPE {
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
