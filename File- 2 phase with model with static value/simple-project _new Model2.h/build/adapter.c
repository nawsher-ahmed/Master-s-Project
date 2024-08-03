#include "adapter.h"
#include <string.h>

void write_to_buffer_ExtU_Model2_T(const struct ExtU_Model2_T *data, char *buffer) {
    memcpy(buffer + 0, &data->I, sizeof(:));
    memcpy(buffer + 32, &data->U, sizeof(:));
}

void read_from_buffer_ExtU_Model2_T(struct ExtU_Model2_T *data, const char *buffer) {
    memcpy(&data->I, buffer + 0, sizeof(:));
    memcpy(&data->U, buffer + 32, sizeof(:));
}

void write_to_buffer_ExtY_Model2_T(const struct ExtY_Model2_T *data, char *buffer) {
}

void read_from_buffer_ExtY_Model2_T(struct ExtY_Model2_T *data, const char *buffer) {
}

