#include "../include/visualization.h"
#include <stdio.h>
#include <stdlib.h>

void save_data_for_visualization(const char *filename, const TensorField *T) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fprintf(file, "%lf ", T->data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

