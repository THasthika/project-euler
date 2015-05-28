CC := g++
SRC	:= $(wildcard src/*.cc)
OBJ	:= $(addprefix obj/,$(notdir $(SRC:.cc=.o)))
LD_FLAGS := ##-lSDL2 -lGL
CC_FLAGS := -I./inc -std=c++11
EXE := bin/main

$(EXE): $(OBJ)
	mkdir -p bin
	$(CC) $(OBJ) -o $@ $(LD_FLAGS)

obj/%.o: src/%.cc
	mkdir -p obj
	$(CC) -c $< -o $@ $(CC_FLAGS)

clean: clean-obj clean-bin
	
clean-bin:
	rm bin/*

clean-obj:
	rm obj/*