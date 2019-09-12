
CC				= g++
BIN 			= ./bin
INC				= ./include
OBJ 			= ./obj
SRC 			= ./src
CFLAGS 		= -c -Wall -w
LFLAGS 		= -Wall -w
MAIN			= Main
DEFN			= stdafx Principal Menu Dados Entidade Pessoa \
						Universidade Departamento Disciplina Professor Aluno
HEAD			= Lista Elemento
MODS			= $(MAIN) $(DEFN)
ALLE 			= $(DEFN) $(HEAD)
EXEC			= $(BIN)/$(MAIN)
SRCS			= $(addsuffix .cpp, $(addprefix $(SRC)/,$(MODS)))
OBJS			= $(addsuffix .o, $(addprefix $(OBJ)/,$(MODS)))
INCS			= $(addsuffix .h, $(addprefix $(INC)/,$(ALLE)))

all: $(OBJS) $(EXEC)

new: clean all run

neu: all run

$(OBJ)/%.o:	$(SRC)/%.cpp $(INCS)
	$(CC) $(CFLAGS) $< -I$(INC) -o $@

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

run:
	$(EXEC)

clean:
	rm $(OBJ)/*
	rm $(EXEC)
