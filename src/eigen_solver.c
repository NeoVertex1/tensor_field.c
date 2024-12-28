#include "../include/eigen_solver.h"
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_eigen.h>
#include <stdio.h>
#include <stdlib.h>

void compute_eigenvalues(const TensorField *T) {
    // Allocate memory for GSL structures
    gsl_matrix *matrix = gsl_matrix_alloc(4, 4);
    gsl_vector *eval = gsl_vector_alloc(4);
    gsl_matrix *evec = gsl_matrix_alloc(4, 4); // Include eigenvectors
    gsl_eigen_symmv_workspace *w = gsl_eigen_symmv_alloc(4);

    // Check for allocation failures
    if (!matrix || !eval || !evec || !w) {
        fprintf(stderr, "Error: Memory allocation for eigenvalue computation failed.\n");
        if (matrix) gsl_matrix_free(matrix);
        if (eval) gsl_vector_free(eval);
        if (evec) gsl_matrix_free(evec);
        if (w) gsl_eigen_symmv_free(w);
        exit(EXIT_FAILURE);
    }

    // Copy tensor data into the GSL matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gsl_matrix_set(matrix, i, j, T->data[i][j]);
        }
    }

    // Compute eigenvalues and eigenvectors
    printf("Computing eigenvalues and eigenvectors...\n");
    int status = gsl_eigen_symmv(matrix, eval, evec, w);

    if (status != GSL_SUCCESS) {
        fprintf(stderr, "Error: gsl_eigen_symmv failed with status %d.\n", status);
        gsl_matrix_free(matrix);
        gsl_vector_free(eval);
        gsl_matrix_free(evec);
        gsl_eigen_symmv_free(w);
        exit(EXIT_FAILURE);
    }

    // Print eigenvalues
    printf("Eigenvalues:\n");
    for (int i = 0; i < 4; i++) {
        printf("%g\n", gsl_vector_get(eval, i));
    }

    // Cleanup
    gsl_matrix_free(matrix);
    gsl_vector_free(eval);
    gsl_matrix_free(evec);
    gsl_eigen_symmv_free(w);
}

