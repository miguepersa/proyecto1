OBJ = main.o Funciones.o Servicio.o Parada.o Autobus.o
CFLAGS = -ansi -Wall -g -lpthread
CC = gcc

simutransusb: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

Funciones.o: Funciones.c Servicio.h Parada.h
	$(CC) -c $(CFLAGS) $< -o $@

Servicio.o: Servicio.c
	$(CC) -c $(CFLAGS) $< -o $@

Parada.o: Parada.c Settings.h Autobus.h
	$(CC) -c $(CFLAGS) $< -o $@

Autobus.o: Autobus.c 
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm -rf ./*.o simutransusb
	