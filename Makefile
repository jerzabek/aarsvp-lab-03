build: *.c
	gcc -Wall -Werror -fopenmp -g -o build **/*.c *.c

clean:
	rm output-*.yuv
	rm build.exe