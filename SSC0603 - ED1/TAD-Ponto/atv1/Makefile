APPS = ./
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./


all:
	gcc -c $(SRC)/Ponto.c  -I $(INCLUDE)/ -o $(OBJ)/ponto.o
	gcc $(APPS)/main.c $(OBJ)/ponto.o -I $(INCLUDE) -o $(BIN)/ponto.exe -lm

run:
	$(BIN)/ponto.exe

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*.exe
