OMP_NUM_THREADS=4
export OMP_NUM_THREADS

ex01:
	gcc ./source/maiorElemento.c -o ex_01.exe -fopenmp
	@ ./ex_01.exe
	@ rm -f ./ex_01.exe

ex02:
	gcc ./source/somaVetor.c -o ex_02.exe -fopenmp
	@ ./ex_02.exe
	@ rm -f ./ex_02.exe

ex03:
	gcc ./source/menorElemento.c -o ex_03.exe -fopenmp
	@ ./ex_03.exe
	@ rm -f ./ex_03.exe
	
clean:
	@ rm -f ./*.exe