main: main.o histo.o
	gcc -Wall -o main main.o histo.o

main.o: main.c histo.h
	gcc -Wall -c main.c

histo.o: histo.c histo.h
	gcc -Wall -c histo.c

clean:
	rm main main.o histo.o
