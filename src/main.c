#include "../include/tensor_field.h"
#include "../include/eigen_solver.h"
#include "../include/data_loader.h"
#include "../include/visualization.h"
#include <stdio.h>

int main() {
    printf("Initializing tensor...\n");
    TensorField T = init_tensor();
    printf("Tensor initialized.\n");

    printf("Loading real data...\n");
    load_real_data("data/real_data.txt", &T);
    printf("Real data loaded.\n");

    printf("Computing eigenvalues...\n");
    compute_eigenvalues(&T);
    printf("Eigenvalues computed.\n");

    printf("Saving data for visualization...\n");
    save_data_for_visualization("plots/tensor_plot.gp", &T);
    printf("Data saved for visualization.\n");

    return 0;
}

