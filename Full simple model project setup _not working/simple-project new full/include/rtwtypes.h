#ifndef RTWTYPES_H
#define RTWTYPES_H

#include <stdint.h>

typedef double real_T;
typedef float real32_T;
typedef int8_t int8_T;
typedef uint8_T uint8_T;
typedef int16_T int16_T;
typedef uint16_T uint16_T;
typedef int32_T int32_T;
typedef uint32_T uint32_T;
typedef int64_T int64_T;
typedef uint64_T uint64_T;
typedef unsigned char boolean_T;
typedef int32_T int_T;
typedef char char_T;
typedef double time_T;

typedef enum {
    MAJOR_TIME_STEP,
    MINOR_TIME_STEP
} SimTimeStep;

#endif /* RTWTYPES_H */


