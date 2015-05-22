CC=gcc

FLAGS=-Wall

INC=api/inc
SRC=api/src
OBJ=obj
BIN=bin

NAME=caixeiro.bin

OBJS=$(OBJ)/tour.o $(OBJ)/main.o

all: $(OBJS)
	$(CC) -o $(BIN)/$(NAME) $(OBJS) -I$(INC) $(FLAGS)

$(OBJ)/main.o: main.c
	$(CC) -o $(OBJ)/main.o -c main.c -I$(INC) $(FLAGS)

$(OBJ)/tour.o: $(SRC)/tour.c
	$(CC) -o $(OBJ)/tour.o -c $(SRC)/tour.c -I$(INC) $(FLAGS)

clear:
	rm -rf $(OBJ) $(BIN)/$(NAME)
	mkdir $(OBJ) 