#include "subsample.h"

/**
 * Matrica:
 * U_UpperLeft U_UpperRight
 * U_LowerLeft U_LowerRight
 *
 * Ovo uzmemo i izračunamo prosjek, isto tako za V
 */
void calculateSubsample(int i, int j, int width, unsigned char *U, unsigned char *V) {
  int index = i * width + j;
  int subsample_index = (i / 2) * (width / 2) + (j / 2);

  unsigned char U_UpperLeft = U[index];
  unsigned char U_UpperRight = U[index + 1];
  unsigned char U_LowerLeft = U[index + width];
  unsigned char U_LowerRight = U[index + width + 1];

  unsigned char V_UpperLeft = V[index];
  unsigned char V_UpperRight = V[index + 1];
  unsigned char V_LowerLeft = V[index + width];
  unsigned char V_LowerRight = V[index + width + 1];

  unsigned char U_avg = (U_UpperLeft + U_UpperRight + U_LowerLeft + U_LowerRight) / 4.0;
  unsigned char V_avg = (V_UpperLeft + V_UpperRight + V_LowerLeft + V_LowerRight) / 4.0;

  U_sub[subsample_index] = U_avg;
  V_sub[subsample_index] = V_avg;
}

void parallelCalculateSubsample() {
#pragma omp parallel
  {
#pragma omp single
    {
      for (int frame = 0; frame < NUM_FRAMES; ++frame) {
#pragma omp taskloop collapse(2) grainsize(GRAIN_SIZE_NUM)
        for (int i = 0; i < HEIGHT; i += 2) {
          for (int j = 0; j < WIDTH; j += 2) {
            {
              calculateSubsample(i, j, WIDTH, U, V);
            }
          }
        }
      }
    }
  }
}