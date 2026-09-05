all:
	gcc -c ListaSequencial.c -o ListaSequencial.o
	gcc main.c ListaSequencial.o -o Lista.a -lm
	
run:
	./Lista.a
	
clean:
	rm -f *.o
	rm -f *.a
