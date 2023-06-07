#include <omp.h>
#include <stdio.h>

#define WIDTH 3840
#define HEIGHT 2160
#define TOTAL_PIXELS WIDTH *HEIGHT
#define NUM_FRAMES 60
#define SUBSAMP_PIXELS TOTAL_PIXELS / 4

unsigned char R[TOTAL_PIXELS], G[TOTAL_PIXELS], B[TOTAL_PIXELS];
unsigned char Y[TOTAL_PIXELS], U[TOTAL_PIXELS], V[TOTAL_PIXELS];

unsigned char U_sub[SUBSAMP_PIXELS], V_sub[SUBSAMP_PIXELS];

#define TIME_MEASURE(command, time_taken)           \
  do {                                              \
    double start_time_macro = omp_get_wtime();      \
    command;                                        \
    double end_time_macro = omp_get_wtime();        \
    time_taken = end_time_macro - start_time_macro; \
  } while (0)
