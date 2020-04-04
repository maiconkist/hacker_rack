CC := g++
CFLAGS := -Wall -g -O3

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS  := $(wildcard ~/sync/projects/c++/hacker_rank/challenges/*.cpp)
PROGS := $(basename $(SRCS))

all: $(PROGS)

clean:
	rm -rf $(PROGS)

.PHONY: all clean
