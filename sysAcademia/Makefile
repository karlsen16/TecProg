
CC				= g++
INC				= ./include
OBJ 			= ./obj
SRC 			= ./src
CFLAGS 		= -c -Wall
LFLAGS 		= -Wall
MAIN			= Main
DEFN			= stdafx Principal Menu Dados Entidade Pessoa \
						Universidade Departamento Disciplina Professor Aluno
HEAD			= Lista Elemento
MODS			= $(MAIN) $(DEFN)
ALLE 			= $(DEFN) $(HEAD)
SRCS			= $(addsuffix .cpp, $(addprefix $(SRC)/,$(MODS)))
OBJS			= $(addsuffix .o, $(addprefix $(OBJ)/,$(MODS)))
INCS			= $(addsuffix .h, $(addprefix $(INC)/,$(ALLE)))

all: $(OBJS) ./$(MAIN)

new: clean all run

neu: all run

$(OBJ)/%.o:	$(SRC)/%.cpp $(INCS)
	$(CC) $(CFLAGS) $< -I$(INC) -o $@

./$(MAIN): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

run:
	./$(MAIN)

clean:
	rm $(OBJ)/*
	rm ./$(MAIN)
