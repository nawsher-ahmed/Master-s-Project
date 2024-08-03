#ifndef RTW_HEADER_Model2_h_
#define RTW_HEADER_Model2_h_

#include "rtwtypes.h"

// Define a struct with an integer value
typedef struct {
    real_T I; // Assuming you want a real_T value here as per your original struct
} ExtU_Model2_T;

// Define a struct with a real_T value and initialize it
typedef struct {
    real_T U;
} ExtY_Model2_T;

// Initialize instances of the structs with values
static const ExtU_Model2_T default_input = { 10.0 }; // Initialize with a real value
static const ExtY_Model2_T default_output = { 20.0 }; // Initialize with a real value

#endif /* RTW_HEADER_Model2_h_ */

