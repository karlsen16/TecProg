
COMP			= g++
BIN 			= ./bin
INCLUDE		= ./include
OBJ 			= ./obj
SRC 			= ./src
FLAGS 		= -c -Wall
ARQV			= Pessoa
ARQP			= Principal

all: comp app

new: clean all run

neu: all run

comp: $(OBJ)/main.o $(OBJ)/$(ARQV).o $(OBJ)/$(ARQP).o

app: $(BIN)/main

$(OBJ)/%.o:	$(SRC)/%.cpp $(INCLUDE)/$(ARQV).h $(INCLUDE)/$(ARQP).h
	$(COMP) $(FLAGS) $< -I $(INCLUDE) -o $@

$(BIN)/%: $(OBJ)/%.o $(OBJ)/$(ARQV).o $(OBJ)/$(ARQP).o
	$(COMP) $< $(OBJ)/$(ARQV).o $(OBJ)/$(ARQP).o -I $(INCLUDE) -o $@

run:
	$(BIN)/main

clean:
	rm $(OBJ)/*
	rm $(BIN)/*
