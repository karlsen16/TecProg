
CC				= g++
BIN 			= ./bin
INC				= ./include
OBJ 			= ./obj
SRC 			= ./src
INCLUDE		= -I./include
CFLAGS 		= -c -Wall
LFLAGS 		= -Wall
MAIN			= Main
DEFN			= Principal Pessoa
MODS			= $(MAIN) $(DEFN)
SRCS			= $(addsuffix .cpp, $(addprefix $(SRC)/,$(MODS)))
OBJS			= $(addsuffix .o, $(addprefix $(OBJ)/,$(MODS)))
HEAD			= $(addsuffix .h, $(addprefix $(INC)/,$(DEFN)))

#default:
	#$(MAIN) \
	#$(DEFN) \
	#$(MODS) \
	#$(SRCS) \
	#$(OBJS) \
	#$(HEAD)

all: comp app

new: clean all run

neu: all run

comp: $(OBJS)

app: $(BIN)/$(MAIN)

$(OBJ)/%.o:	$(SRC)/%.cpp $(HEAD)
	$(CC) $(CFLAGS) $< $(INCLUDE) -o $@

$(BIN)/%: $(OBJS)
	$(CC) $(OBJS) -o $@

run:
	$(BIN)/$(MAIN)

clean:
	rm $(OBJ)/*
	rm $(BIN)/*
