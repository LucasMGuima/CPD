OMP_NUM_THREADS=4
export OMP_NUM_THREADS

make: ./source/main.c
	gcc ./source/main.c -o ola.exe -fopenmp

run: 
	@ ./ola.exe

clean:
	@ rm -f ./ola.exe