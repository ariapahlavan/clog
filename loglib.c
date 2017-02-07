/**
 * Created by aria on 1/28/17.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include "loglib.h"


#define EMPTY_VAL 0
#define LOG_LEVEL DEBUG

void printList(int num, va_list valist) {
    int i;
    num *= 2;

    enum DATA_TYPE T;
    void *V;

    /* access all the arguments assigned to valist */
    for (i = 0; i < num;) {
        T = va_arg(valist, enum DATA_TYPE);

        if (T == N || T == ENDL) {
            V = EMPTY_VAL;
            T == ENDL ? i += 2 : 0;
        } else {
            V = va_arg(valist, void *);
            i += 2;
        }

        output(V, T);
    }
}

void print(int num, ...) {
    va_list valist;

    /* initialize valist for num number of arguments */
    va_start(valist, num);

    printList(num, valist);

    /* clean memory reserved for valist */
    va_end(valist);
}

void println(int num, ...) {
    va_list valist;

    /* initialize valist for num number of arguments */
    va_start(valist, num);

    printList(num, valist);

    /* clean memory reserved for valist */
    va_end(valist);

    output(EMPTY_VAL, ENDL);
}

void outputDouble(double value) {
    printf("%f", value);
}

void output(void *V, enum DATA_TYPE Type) {
    switch (Type) {
        case P:
        case PTR:
            printf("%p", (int *) V);
            break;
        case C:
        case CHAR:
            printf("%c", (char) V);
            break;
        case S:
        case STR:
            printf("%s", (char *) V);
            break;
        case I8:
        case INT_8:
            printf("%d %s(0x%X)%s", (int8_t) V, AWHT, (int8_t) V, ANRM);
            break;
        case I16:
        case INT_16:
            printf("%d %s(0x%X)%s", (int16_t) V, AWHT, (int16_t) V, ANRM);
            break;
        case I32:
        case INT_32:
            printf("%d %s(0x%X)%s", (int32_t) V, AWHT, (int32_t) V, ANRM);
            break;
        case I64:
        case INT_64:
            printf("%ld %s(0x%lX)%s", (int64_t) V, AWHT, (int64_t) V, ANRM);
            break;
        case UI8:
        case UINT_8:
            printf("%u %s(0x%X)%s", (uint8_t) V, AWHT, (uint8_t) V, ANRM);
            break;
        case UI16:
        case UINT_16:
            printf("%u %s(0x%X)%s", (uint16_t) V, AWHT, (uint16_t) V, ANRM);
            break;
        case UI32:
        case UINT_32:
            printf("%u %s(0x%X)%s", (uint32_t) V, AWHT, (uint32_t) V, ANRM);
            break;
        case UI64:
        case UINT_64:
            printf("%llu %s(0x%llX)%s", (uint64_t) V, AWHT, (uint64_t) V, ANRM);
            break;
        case I:
        case INT:
            printf("%d %s(0x%X)%s", (int) V, AWHT, (int) V, ANRM);
            break;
        case Id:
            printf("%d", (int) V);
            break;
        case Ix:
            printf("0x%X", (int) V);
            break;
        case L:
        case LONG:
            printf("%ld %s(0x%lX)%s", (long) V, AWHT, (long) V, ANRM);
            break;
        case LI:
        case LONG_INT:
            printf("%ld %s(0x%lX)%s", (long int) V, AWHT, (long int) V, ANRM);
            break;
        case UL:
        case ULONG:
            printf("%lu %s(0x%lX)%s", (unsigned long) V, AWHT, (unsigned long) V, ANRM);
            break;
        case ULI:
        case ULONG_INT:
            printf("%lu %s(0x%lX)%s", (unsigned long int) V, AWHT, (unsigned long int) V, ANRM);
            break;
        case N:
        case ENDL:
            printf("\n");
            break;
        case T:
        case TAB:
            printf("\t");
            break;
        default:
            printf("INVALID ARGUMENTS\n");
    }
}

void loggingMsg(const char *msg, enum DATA_TYPE t, const char *func, int line, enum LOG_LEVELS lvl) {
    if (lvl >= LOG_LEVEL) {
        int curLogNum = getLogNum();
        setColorPrint(lvl);
        printf("[%s]: func:'%s' → line:%d (%d)%s\n%s", enumStrings[lvl], func, line, curLogNum, ANRM, msg);
        setColorPrint(lvl);
        printf(" (%d)%s\n", curLogNum, ANRM);
    }
}

void logging(int num, ...) {
    va_list valist;
    char *func;
    int line, cur_indx = 0, i;
    enum LOG_LEVELS lvl;
    void *values[100];
    enum DATA_TYPE tags[100];
    enum DATA_TYPE tag;

    /* initialize valist for num number of arguments */
    va_start(valist, MAX_LOG_DEF_ARGS);
    if (num == EOL) return;

    tags[cur_indx] = num;
    values[cur_indx] = va_arg(valist, void *);
    cur_indx++;

    while ((tag = va_arg(valist, enum DATA_TYPE)) != EOL) {
        tags[cur_indx] = tag;
        if (tag == ENDL || tag == N || tag == TAB || tag == T) {
            cur_indx++;
            continue;
        }
        values[cur_indx] = va_arg(valist, void *);
        cur_indx++;
    }
    func = va_arg(valist, char *);
    line = va_arg(valist, int);
    lvl = va_arg(valist, enum LOG_LEVELS);

    printLog(func, line, lvl, cur_indx, values, tags, true);

    /* clean memory reserved for valist */
    va_end(valist);

}

void printLog(const char *func, int line, enum LOG_LEVELS level, int length, void *const *values,
              const enum DATA_TYPE *tags, bool header) {
    int i;
    enum DATA_TYPE tag;
    void *val;
    if (level >= LOG_LEVEL) {
        int curLogNum = getLogNum();

        if (header) {
            setColorPrint(level);
            printf("[%s]: func:'%s' → line:%d (%d)\n" ANRM, enumStrings[level], func, line, curLogNum);
        }

        /* access all the arguments assigned to valist */
        for (i = 0; i < length; i++) {
            tag = tags[i];

            if (tag == N || tag == ENDL || tag == TAB || tag == T)
                val = EMPTY_VAL;
            else
                val = values[i];

            output(val, tag);
        }

        setColorPrint(level);
        printf(" (%d)\n" ANRM, curLogNum);
    }
}

void loggingMsgNoHeader(const char *msg, enum DATA_TYPE t, const char *func, int line, enum LOG_LEVELS lvl) {
    if (lvl >= LOG_LEVEL) {
        int curLogNum = getLogNum();
        printf("%s", msg);
        setColorPrint(lvl);
        printf(" (%d)%s\n", curLogNum, ANRM);
    }
}

void loggingNoHeader(int num, ...) {
    va_list valist;
    char *func;
    int line, cur_indx = 0, i;
    enum LOG_LEVELS lvl;
    void *values[100];
    enum DATA_TYPE tags[100];
    enum DATA_TYPE tag;

    /* initialize valist for num number of arguments */
    va_start(valist, MAX_LOG_DEF_ARGS);
    if (num == EOL) return;

    tags[cur_indx] = num;
    values[cur_indx] = va_arg(valist, void *);
    cur_indx++;

    while ((tag = va_arg(valist, enum DATA_TYPE)) != EOL) {
        tags[cur_indx] = tag;
        if (tag == ENDL || tag == N || tag == TAB || tag == T) {
            cur_indx++;
            continue;
        }
        values[cur_indx] = va_arg(valist, void *);
        cur_indx++;
    }
    func = va_arg(valist, char *);
    line = va_arg(valist, int);
    lvl = va_arg(valist, enum LOG_LEVELS);


    printLog(func, line, lvl, cur_indx, values, tags, false);

    /* clean memory reserved for valist */
    va_end(valist);

}

int getLogNum() {
    static int logNum = 0;
    return logNum++;
}

void colorPrint(enum LOG_LEVELS lvl, const char *txt) {
    switch (lvl) {
        case DEBUG:
            printf(ACYN "%s" ANRM, txt);
            break;
        case INFO:
            printf(ABLU "%s" ANRM, txt);
            break;
        case WARN:
            printf(AYEL "%s" ANRM, txt);
            break;
        case ERROR:
            printf(ARED "%s" ANRM, txt);
            break;
    }
}

void setColorPrint(enum LOG_LEVELS lvl) {
    switch (lvl) {
        case DEBUG:
            printf(ACYN "");
            break;
        case INFO:
            printf(ABLU "");
            break;
        case WARN:
            printf(AYEL "");
            break;
        case ERROR:
            printf(ARED "");
            break;
    }
}
