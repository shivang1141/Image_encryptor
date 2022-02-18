CC = g++
CFLAGS =      -Wall -Werror -std=c++0x -pedantic
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system 

.PHONY: all clean

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic $(LFLAGS)

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	$(CC) -c $< $(CFLAGS)
LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) -c $< $(CFLAGS)
clean:
	rm LFSR.o PhotoMagic.o PhotoMagic 
