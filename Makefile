jeux:maingame.o fonction_g.o
	gcc -o jeux maingame.o fonction_g.o -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf `sdl-config --libs` -g
maingame.o:maingame.c
	gcc -c maingame.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf `sdl-config --cflags` -g
fonction_g.o:fonction_g.c
	gcc -c fonction_g.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf `sdl-config --cflags` -g


