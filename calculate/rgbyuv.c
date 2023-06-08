#include "rgbyuv.h"

void mapRGBtoYUV(int index) {
  Y[index] = 0.257 * R[index] + 0.504 * G[index] + 0.098 * B[index] + 16;
  U[index] = -0.148 * R[index] - 0.291 * G[index] + 0.439 * B[index] + 128;
  V[index] = 0.439 * R[index] - 0.368 * G[index] - 0.071 * B[index] + 128;
}

void parallelMapRGBtoYUV() {
#pragma omp parallel
  {
#pragma omp single
    {
#pragma omp taskloop grainsize(GRAIN_SIZE_NUM)
      for (int i = 0; i < TOTAL_PIXELS; ++i) {
        {
          mapRGBtoYUV(i);
        }
      }
    }
  }
}