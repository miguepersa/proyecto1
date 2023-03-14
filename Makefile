OBJ = main.o Ruta.o
CFLAGS = -ansi -Wall -g

simutransusb: $(OBJ)
	gcc $(CFLAGS) $< -o $@

main.o: main.c
	gcc -c $(CFLAGS) $< -o $@

Ruta.o: Ruta.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -rf ./*.o simutransusb