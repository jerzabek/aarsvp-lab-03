#!/bin/bash
#SBATCH --job-name=aarsvp_lab03_0036526653
#SBATCH --time=00:10:00
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=16
#SBATCH --mem-per-cpu=2048MB
#SBATCH -o omp-%j.out
#SBATCH --partition=computes_thin

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

./build rgb_video.yuv
