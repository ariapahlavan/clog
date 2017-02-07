/**
 * Created by aria on 1/28/17.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "loglib.h"


#define EMPTY_VAL 0
#define LOG_LEVEL DEBUG


void printLogLabel(enum LOG_LEVELS lvl);

void outputDouble(double value);

void output(void *V, enum DATA_TYPE Type);

void printList(int num, va_list valist);

void printLog(int num, va_list valist);

void colorPrint(enum LOG_LEVELS lvl, const char *txt);

void printList(int num, va_list valist){
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

void printLog(int num, va_list valist){
    int i;
    num *= 2;

    enum DATA_TYPE T;
    void *V;

    for (i = 0; i < num;) {
        T = va_arg(valist, enum DATA_TYPE);

        if (T == N || T == ENDL) {
            V = EMPTY_VAL;
            T == ENDL ? i += 2 : 0;
            output(V, T);
            printf("\t\t ");
        } else {
            V = va_arg(valist, void *);
            i += 2;
            output(V, T);
        }
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
            printf("%d", (int8_t) V);
            break;
        case I16:
        case INT_16:
            printf("%d", (int16_t) V);
            break;
        case I32:
        case INT_32:
            printf("%d", (int32_t) V);
            break;
        case I64:
        case INT_64:
            printf("%d", (int64_t) V);
            break;
        case UI8:
        case UINT_8:
            printf("%u", (__uint8_t) V);
            break;
        case UI16:
        case UINT_16:
            printf("%u", (__uint16_t) V);
            break;
        case UI32:
        case UINT_32:
            printf("%u", (__uint32_t) V);
            break;
        case UI64:
        case UINT_64:
            printf("%u", (__uint64_t) V);
            break;
        case I:
        case INT:
            printf("%d", (int) V);
            break;
        case L:
        case LONG:
            printf("%ld", (long) V);
            break;
        case LI:
        case LONG_INT:
            printf("%ld", (long int) V);
            break;
        case UL:
        case ULONG:
            printf("%lu", (unsigned long) V);
            break;
        case ULI:
        case ULONG_INT:
            printf("%lu", (unsigned long int) V);
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

void loggingMsg(enum LOG_LEVELS lvl, char *msg) {
    printLogLabel(lvl);
    printf("%s", msg);
    colorPrint(lvl, "\n---------------------------\n");
}

void logging(enum LOG_LEVELS lvl, int num, ...) {
    va_list valist;

    /* initialize valist for num number of arguments */
    va_start(valist, num);

    if (lvl >= LOG_LEVEL) {
        printLogLabel(lvl);
        if (lvl == INFO || lvl == WARN) printf(" ");
        printLog(num, valist);
        colorPrint(lvl, "\n---------------------------\n");
    }

    /* clean memory reserved for valist */
    va_end(valist);

}

void printLogLabel(enum LOG_LEVELS lvl) {
    printf("[");
    colorPrint(lvl, enumStrings[lvl]);
    printf("]: ");
}

void colorPrint(enum LOG_LEVELS lvl, const char *txt) {
    switch (lvl) {
        case DEBUG:
            printf(AGRN "%s%s", txt, ANRM);
            break;
        case INFO:
            printf(ABLU "%s%s", txt, ANRM);
            break;
        case WARN:
            printf(AYEL "%s%s", txt, ANRM);
            break;
        case ERROR:
            printf(ARED "%s%s", txt, ANRM);
            break;
    }
}