
COMP			= g++
BIN 			= ./bin
INCLUDE		= ./include
OBJ 			= ./obj
SRC 			= ./src
FLAGS 		= -c -Wall
ARQV			= exercicios

all: comp app

new: clean all run

neu: all run

comp: $(OBJ)/main.o $(OBJ)/$(ARQV).o

app: $(BIN)/main

$(OBJ)/%.o:	$(SRC)/%.cpp $(INCLUDE)/$(ARQV).h
	$(COMP) $(FLAGS) $< -I $(INCLUDE) -o $@

$(BIN)/%: $(OBJ)/%.o $(OBJ)/$(ARQV).o
	$(COMP) $< $(OBJ)/$(ARQV).o -I $(INCLUDE) -o $@

run:
	$(BIN)/main

clean:
	rm $(OBJ)/*
	rm $(BIN)/*
