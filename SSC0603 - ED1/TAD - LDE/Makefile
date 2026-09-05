all:
	gcc -c ListaDinEncad.c -o ListaDinEncad.o
	gcc main.c ListaDinEncad.o -o Lista.a -lm
	
run:
	./Lista.a
	
clean:
	rm -f *.o
	rm -f *.a