CXX=clang++
CXX_FLAGS=-std=c++2a -g -O0 -I -nostartfiles

exec: bin/exec
bin/exec: src/main.cpp src/readFile.cpp src/graph.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -f bin/*
