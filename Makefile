all:execute

execute:executar_para_cubicos
	./showg -A cub12.g6 > entrada.txt
	./OCN7 12 85 114 < entrada.txt > saida4.out

executar_para_cubicos:ftest
	gcc showg.c -o showg

ftest:bib.o OCN7.o
	g++ -o OCN7 bib.o OCN7.o -pthread

bib.o:bib.c bib.h
	gcc -c -o bib.o bib.c

OCN7.o:OCN7.cpp
	g++ -c -o OCN7.o OCN7.cpp