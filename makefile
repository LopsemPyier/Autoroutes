CFLAGS=-Wall -pedantic -std=c99
LDFLAGS=

.PHONY: all run clean mrproper

types.o: types.h types.c
	mkdir -p build
	gcc $(CFLAGS) -c types.c -o build/types.o

display.o: display.h display.c types.h
	mkdir -p build
	gcc $(CFLAGS) -c display.c -o build/display.o

main.o: main.c display.h types.h
	mkdir -p build
	gcc $(CFLAGS) -c main.c -o build/main.o

autoroutes: main.o display.o types.o
	mkdir -p build
	gcc $(LDFLAGS) -o build/autoroutes "build/main.o" "build/display.o" "build/types.o"

all: autoroutes

run: all
	./build/autoroutes

clean:
	rm -f build/*.o core

mrproper: clean
	rm -rf build