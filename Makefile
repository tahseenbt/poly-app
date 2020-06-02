# a file to compile only the updated modules
polyapp: polyapp.o utils.o poly.o
	gcc -o polyapp polyapp.o utils.o poly.o
polyapp.o: polyapp.c
	gcc -c polyapp.c
utils.o: utils.c
	gcc -c utils.c
poly.o: poly.c
	gcc -c poly.c
