#include "io.h"
#include "../main.h"

void readFile(char *input_filename) {
  FILE *fp = fopen(input_filename, "rb");

  for (int frame = 0; frame < NUM_FRAMES; ++frame) {
    fread(R, 1, TOTAL_PIXELS, fp);
    fread(G, 1, TOTAL_PIXELS, fp);
    fread(B, 1, TOTAL_PIXELS, fp);
  }

  fclose(fp);
}

void writeYUVFile() {
  FILE *fp_out = fopen("output-raw.yuv", "wb");

  for (int frame = 0; frame < NUM_FRAMES; ++frame) {
    fwrite(Y, 1, TOTAL_PIXELS, fp_out);
    fwrite(U, 1, TOTAL_PIXELS, fp_out);
    fwrite(V, 1, TOTAL_PIXELS, fp_out);
  }

  fclose(fp_out);
}

void writeYUVSubsampleFile() {
  FILE *fp_out_subsample = fopen("output-subsample.yuv", "wb");

  for (int frame = 0; frame < NUM_FRAMES; ++frame) {
    fwrite(Y, 1, TOTAL_PIXELS, fp_out_subsample);
    fwrite(U_sub, 1, TOTAL_PIXELS / 4, fp_out_subsample);
    fwrite(V_sub, 1, TOTAL_PIXELS / 4, fp_out_subsample);
  }

  fclose(fp_out_subsample);
}

void writeYUVUpsampleFile() {
  FILE *fp_out_upsample = fopen("output-upsample.yuv", "wb");

  for (int frame = 0; frame < NUM_FRAMES; ++frame) {
    fwrite(Y, 1, TOTAL_PIXELS, fp_out_upsample);
    fwrite(U, 1, TOTAL_PIXELS, fp_out_upsample);
    fwrite(V, 1, TOTAL_PIXELS, fp_out_upsample);
  }

  fclose(fp_out_upsample);
}
