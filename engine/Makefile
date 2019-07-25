GCC=g++-5
FLAGS=-g -std=c++17 -Wall 
LINKER_FLAGS=-lstdc++fs -pthread -I /home/klee/klee_src/include/klee/Internal/ADT/ 
TARGET=main
OBJS= master.cpp klee_to_afl.cpp KTest.cpp

$(TARGET): $(OBJS)
	$(GCC) $(FLAGS) -o $(TARGET) $(OBJS) $(LINKER_FLAGS)

clean:
	rm $(TARGET)
