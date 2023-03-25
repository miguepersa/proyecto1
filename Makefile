OBJ = main.o Funciones.o Servicio.o Parada.o Autobus.o
CFLAGS = -ansi -Wall -g

simutransusb: $(OBJ)
	gcc $(CFLAGS) $^ -o $@

main.o: main.c
	gcc -c $(CFLAGS) $< -o $@

Funciones.o: Funciones.c
	gcc -c $(CFLAGS) $< -o $@

Servicio.o: Servicio.c
	gcc -c $(CFLAGS) $< -o $@

Parada.o: Parada.c 
	gcc -c $(CFLAGS) $< -o $@

Autobus.o: Autobus.c
	gcc -c $(CFLAGS) $< -o $@


clean:
	rm -rf ./*.o simutransusb
	