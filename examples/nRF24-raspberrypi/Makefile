all: main

C_SOURCE_DIR = ../..

# Link to make executable.
main: nRF24.o main.o network.o $(C_SOURCE_DIR)/nRF24.h
	gcc -g -o main main.o nRF24.o network.o -lbcm2835

# Compile object code for main.c
main.o: main.c $(C_SOURCE_DIR)/nRF24.h
	gcc -c -g main.c -lbcm2835 -I$(C_SOURCE_DIR)/

# Compile object code for nRF24.c library.
nRF24.o: $(C_SOURCE_DIR)/nRF24.c $(C_SOURCE_DIR)/nRF24.h
	gcc -c -g $(C_SOURCE_DIR)/nRF24.c -lbcm2835

# Compile object code for network.c library.
network.o: $(C_SOURCE_DIR)/network.c $(C_SOURCE_DIR)/network.h $(C_SOURCE_DIR)/nRF24.h
	gcc -c -g $(C_SOURCE_DIR)/network.c 

clean:
	rm *.o main


