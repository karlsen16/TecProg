
CC				= g++
BIN 			= ./bin
INC				= ./include
OBJ 			= ./obj
SRC 			= ./src
CFLAGS 		= -c -Wall -w
LFLAGS 		= -Wall -w
MAIN			= Main
DEFN			= stdafx Principal lUniversidade elUniversidade Universidade \
						lDepartamento elDepartamento Departamento \
						lDisciplina elDisciplina Disciplina Professor \
						lAluno elAluno Aluno Pessoa
MODS			= $(MAIN) $(DEFN)
EXEC			= $(BIN)/$(MAIN)
SRCS			= $(addsuffix .cpp, $(addprefix $(SRC)/,$(MODS)))
OBJS			= $(addsuffix .o, $(addprefix $(OBJ)/,$(MODS)))
HEAD			= $(addsuffix .h, $(addprefix $(INC)/,$(DEFN)))

all: $(OBJS) $(EXEC)

new: clean all run

neu: all run

$(OBJ)/%.o:	$(SRC)/%.cpp $(HEAD)
	$(CC) $(CFLAGS) $< -I$(INC) -o $@

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

run:
	$(EXEC)

clean:
	rm $(OBJ)/*
	rm $(EXEC)
