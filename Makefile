OBJ = main.o Funciones.o Servicio.o
CFLAGS = -ansi -Wall -g

simutransusb: $(OBJ)
	gcc $(CFLAGS) $< -o $@

main.o: main.c
	gcc -c $(CFLAGS) $< -o $@

Funciones.o: Funciones.c
	gcc -c $(CFLAGS) $< -o $@

Servicio.o: Servicio.c
	gcc -c $(CFLAGS) $< -o $@	


clean:
	rm -rf ./*.o simutransusb