CC = g++
CFLAGS=-std=c++11 -Wall -Iinclude

all: vpl_execution

vpl_execution: build/main.o build/Circulo.o build/Ponto.o
	$(CC) $(CFLAGS) build/main.o build/Circulo.o build/Ponto.o -o vpl_execution

build/main.o: src/main.cpp include/Circulo.hpp include/Ponto.hpp
	$(CC) $(CFLAGS) -c src/main.cpp -o build/main.o

build/Circulo.o: src/entidades/Circulo.cpp include/Circulo.hpp
	$(CC) $(CFLAGS) -c src/entidades/Circulo.cpp -o build/Circulo.o

build/Ponto.o: src/entidades/Ponto.cpp include/Ponto.hpp
	$(CC) $(CFLAGS) -c src/entidades/Ponto.cpp -o build/Ponto.o

clean:
	rm -f build/*.o vpl_execution