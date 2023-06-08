# AARSVP (HPC)

## Treća laboratorijska vježba

Optimizacija [druge laboratorijske vježbe](https://github.com/jerzabek/aarsvp-lab-02).

Izlazne datoteke nakon pokretanja programa su `output-raw.yuv`, `output-subsample.yuv` te `output-upsample.yuv`.

Pretpostavljeno je da ulazna datoteka ima veličinu 3840x2160 u formatu zadanom u zadatku.

### Compile

```sh
$ make
```

### Clean

Uklanje artefakata

```sh
$ make clean
```

### Run

```sh
$ ./build.exe video/rgb_video.yuv
```

Pokretanje pomoću SLURM okruženja (potrebno za UNIRI Bura superračunalo)

```sh
$ sbatch slurm_script.sh
```