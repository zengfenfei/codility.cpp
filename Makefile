bins:= $(wildcard src/*.cpp)
bins:=$(bins:src/%.cpp=bin/%)

all: $(bins)

$(bins): bin/% : src/%.cpp
	@mkdir -p bin
	g++ -o $@ $<