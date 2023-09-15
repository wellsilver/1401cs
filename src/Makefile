
all: run
run: out/main.o activate clean
build: out/main.o

out/main.o:
	g++ main.cpp -l sdl2 -o out/main.o

activate:
	./out/main.o

clean:
	rm out/main.o