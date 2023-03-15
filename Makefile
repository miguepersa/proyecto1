OBJ = main.o Parada.o
CFLAGS = -ansi -Wall -g

simutransusb: $(OBJ)
	gcc $(CFLAGS) $< -o $@

main.o: main.c
	gcc -c $(CFLAGS) $< -o $@

Parada.o: Parada.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -rf ./*.o simutransusb