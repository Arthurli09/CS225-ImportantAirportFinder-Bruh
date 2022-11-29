CXX=clang++
INCLUDES=-Iincludes/
CXX_FLAGS=-std=c++2a -g -O0 -I -nostartfiles 

exec: bin/exec
tests: bin/tests

bin/exec: entry/main.cpp src/readFile.cpp src/graph.cpp includes/readFile.h includes/graph.h 
	$(CXX) $(CXX_FLAGS) $(INCLUDES) entry/main.cpp src/readFile.cpp src/graph.cpp -o $@

bin/tests: tests/tests_part1.cpp src/readFile.cpp obj/catch.o src/graph.cpp includes/readFile.h includes/graph.h 
	$(CXX) $(CXX_FLAGS) $(INCLUDES) tests/tests_part1.cpp obj/catch.o src/readFile.cpp src/graph.cpp -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -f bin/exec
	rm -f bin/tests
