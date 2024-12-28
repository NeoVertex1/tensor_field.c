#include "../include/data_loader.h"
#include <stdio.h>
#include <stdlib.h>

void load_real_data(const char *filename, TensorField *T) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (fscanf(file, "%lf", &T->data[i][j]) != 1) {
                fprintf(stderr, "Error reading data at [%d][%d]\n", i, j);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
}

