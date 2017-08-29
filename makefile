exe:	main.cpp
	g++ main.cpp src/*.cpp -Iincludes -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_gfx -std=c++11

run:
	./a.out

r:
	./a.out

clean:
	rm a.out

c:
	rm a.out

