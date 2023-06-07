#include "upsample.h"

void parallelUpsample() {
#pragma omp parallel
  {
#pragma omp single
    {
      for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
#pragma omp task
          {
            int index = i * WIDTH + j;

            int subsample_index = (i / 2) * (WIDTH / 2) + (j / 2);

            U[index] = U_sub[subsample_index];
            V[index] = V_sub[subsample_index];
          }
        }
      }
    }
  }
}
