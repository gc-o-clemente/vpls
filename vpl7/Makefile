CC = g++
CFLAGS = -std=c++11 -Wall

all: vpl_execution

vpl_execution: main.o Processo.o FilaProcessos.o
	$(CC) $(CFLAGS) main.o Processo.o FilaProcessos.o -o vpl_execution

main.o: main.cpp avaliacao_basica_controle.hpp
	$(CC) $(CFLAGS) -c main.cpp

Processo.o: Processo.cpp Processo.hpp
	$(CC) $(CFLAGS) -c Processo.cpp

FilaProcessos.o: FilaProcessos.cpp FilaProcessos.hpp Processo.hpp
	$(CC) $(CFLAGS) -c FilaProcessos.cpp

clean:
	rm -f *.o vpl_execution
	