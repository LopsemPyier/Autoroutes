CFLAGS=-Wall -pedantic -std=c99
LDFLAGS=

.PHONY: all run clean mrproper

types.o: types.h types.c
	gcc $(CFLAGS) -c types.c

display.o: display.h display.c types.h
	gcc $(CFLAGS) -c display.c

main.o: main.c display.h types.h
	gcc $(CFLAGS) -c main.c

autoroutes: main.o display.o types.o
	gcc $(LDFLAGS) -o autoroutes main.o display.o types.o

all: autoroutes

run: all
	./autoroutes

clean:
	rm -f *.o core

mrproper: clean
	rm -f autoroutes