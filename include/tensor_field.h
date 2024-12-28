#ifndef TENSOR_FIELD_H
#define TENSOR_FIELD_H

#define PSI 44.8
#define XI 3721.8
#define EPSILON 0.28082
#define TAU 64713.97
#define M_PI 3.141592653589793

typedef struct {
    double data[4][4];
} TensorField;

TensorField init_tensor();
void print_tensor(const TensorField *T);

#endif

