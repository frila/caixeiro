CC=gcc

FLAGS=-Wall

INC=api/inc -Iapi/inc/helpers
SRC=api/src
OBJ=obj
BIN=bin

NAME=caixeiro.bin

OBJS=$(OBJ)/tour.o $(OBJ)/main-serial.o $(OBJ)/main-parallel.o $(OBJ)/rdwt.o

all: $(OBJS)
	$(CC) -o $(BIN)/$(NAME) $(OBJS) -I$(INC) $(FLAGS)

$(OBJ)/main-parallel.o: main-parallel.c
	$(CC) -o $(OBJ)/main-parallel.o -c main-parallel.c -I$(INC) $(FLAGS)

$(OBJ)/main-serial.o: main-serial.c
	$(CC) -o $(OBJ)/main-serial.o -c main-serial.c -I$(INC) $(FLAGS)

$(OBJ)/tour.o: $(SRC)/tour.c
	$(CC) -o $(OBJ)/tour.o -c $(SRC)/tour.c -I$(INC) $(FLAGS)

$(OBJ)/rdwt.o: $(SRC)/helpers/rdwt.c
	$(CC) -o $(OBJ)/rdwt.o -c $(SRC)/helpers/rdwt.c -I$(INC) $(FLAGS)


clear:
	rm -rf $(OBJ) $(BIN)/$(NAME)
	mkdir $(OBJ) 