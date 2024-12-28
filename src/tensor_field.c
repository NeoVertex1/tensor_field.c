#include "tensor_field.h"
#include <math.h>
#include <stdio.h>

TensorField init_tensor() {
    TensorField T = {{
        {PSI, EPSILON, 0, M_PI},
        {EPSILON, XI, TAU, 0},
        {0, TAU, M_PI, EPSILON},
        {M_PI, 0, EPSILON, PSI}
    }};
    return T;
}

void print_tensor(const TensorField *T) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%lf ", T->data[i][j]);
        }
        printf("\n");
    }
}

