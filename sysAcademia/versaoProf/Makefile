
CC				= g++
SRC 			= ./
CFLAGS 		    = -c -Wall -w
LFLAGS 		    = -Wall -w
MAIN			= Main
DEFN			= stdafx Principal Pessoa Professor\
                  ListaUniversidades ElUniversidade Universidade \
				  ListaDepartamentos ElDepartamento Departamento \
				  ListaDisciplinas ElDisciplina Disciplina \
				  ListaAlunos ElAluno Aluno 
MODS			= $(MAIN) $(DEFN)
EXEC			= ./$(MAIN)
SRCS			= $(addsuffix .cpp, $(addprefix ./,$(MODS)))
OBJS			= $(addsuffix .o, $(addprefix ./,$(MODS)))
HEAD			= $(addsuffix .h, $(addprefix ./,$(DEFN)))

all: $(OBJS) $(EXEC)

new: clean all run

neu: all run

./%.o:	./%.cpp $(HEAD)
	$(CC) $(CFLAGS) $< -o $@

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

run:
	$(EXEC)

clean:
	rm ./*.o
	rm $(EXEC)
