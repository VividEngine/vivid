libvivid.a: vivid.o
	ar rcs libvivid.a vivid.o

vivid.o: vivid.c vivid.h
	gcc -c vivid.c -o vivid.o -Iinclude -Llib -lSDL3 -lSDL3_ttf -lSDL3_image

clean:
	rm -f vivid.o libvivid.a