

#ifndef RTWTYPES_H
#define RTWTYPES_H

#include <stdint.h>

typedef double real_T;
typedef float real32_T;
typedef int8_t int8_T;
typedef uint8_t uint8_T;
typedef int16_t int16_T;
typedef uint16_t uint16_T;
typedef int32_t int32_T;
typedef uint32_T uint32_T;
typedef int64_t int64_T;
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

