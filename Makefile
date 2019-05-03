# all: stadium.o main.o

# %: %.cc
# 	g++ -std=c++11 $< -o $@

# %: %.c
# 	gcc $< -o $@

CC=gcc
CFLAGS=-I. -pthread -std=c99
DEPS = stadium.h
OBJ = stadium.o main.o 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

