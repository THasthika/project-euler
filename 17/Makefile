CC := g++
SRC	:= $(wildcard src/*.cpp)
OBJ	:= $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
LD_FLAGS := ##-lSDL2 -lGL
CC_FLAGS := -I./inc
EXE := bin/main

$(EXE): $(OBJ)
	mkdir -p bin
	$(CC) $(OBJ) -o $@ $(LD_FLAGS)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CC) -c $< -o $@ $(CC_FLAGS)

clean: clean-obj clean-bin
	
clean-bin:
	rm bin/*

clean-obj:
	rm obj/*