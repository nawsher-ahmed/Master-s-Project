#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "Model2.h"

void write_to_buffer_ExtU_Model2_T(const struct ExtU_Model2_T *data, char *buffer);
void read_from_buffer_ExtU_Model2_T(struct ExtU_Model2_T *data, const char *buffer);
void write_to_buffer_ExtY_Model2_T(const struct ExtY_Model2_T *data, char *buffer);
void read_from_buffer_ExtY_Model2_T(struct ExtY_Model2_T *data, const char *buffer);

#endif /* ADAPTER_H_ */
