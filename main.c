#include "main.h"

#include "calculate/rgbyuv.h"
#include "calculate/subsample.h"
#include "calculate/upsample.h"
#include "io/io.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <input_filename>\n", argv[0]);
    return 1;
  }

  char *input_filename = argv[1];
  double time_taken;

  double program_start = omp_get_wtime();

  /** --------------------------- Čitanje RGB videa --------------------------- */

  printf("[AARSVP-LAB03] Starting - Reading from file: %s\n", input_filename);

  TIME_MEASURE({
    readFile(input_filename);
    parallelMapRGBtoYUV();
  },
               time_taken);

  printf("[AARSVP-LAB03] Finished reading in %f seconds\n", time_taken);

  /** --------------------------- spremanje cistog YUV videa --------------------------- */

  TIME_MEASURE(writeYUVFile(), time_taken);

  printf("[AARSVP-LAB03] Finished writing output-raw.yuv in %f seconds\n", time_taken);

  /** --------------------------- poduzorkovanje --------------------------- */

  TIME_MEASURE(parallelCalculateSubsample(), time_taken);

  printf("[AARSVP-LAB03] Finished processing subsampling 4:2:0 in %f seconds\n", time_taken);

  TIME_MEASURE(writeYUVSubsampleFile(), time_taken);

  printf("[AARSVP-LAB03] Finished writing to output-subsample.yuv in %f seconds\n", time_taken);

  /** --------------------------- naduzorkovanje --------------------------- */

  TIME_MEASURE(parallelUpsample(), time_taken);

  printf("[AARSVP-LAB03] Finished processing upsampling in %f seconds\n", time_taken);

  TIME_MEASURE(writeYUVUpsampleFile(), time_taken);

  printf("[AARSVP-LAB03] Finished writing to output-upsample.yuv in %f seconds\n", time_taken);

  double total_time_taken = omp_get_wtime() - program_start;
  printf("[AARSVP-LAB03] Completed in total of %f seconds\n", total_time_taken);

  return 0;
}
