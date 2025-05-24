all: main

main: main.c
	gcc main.c -o ./build/main

clean:
	rm -f ./build/main

.PHONY: all clean
