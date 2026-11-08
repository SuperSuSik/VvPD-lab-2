CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -O0
TARGET = vpd_lab2_multifile
OBJ = main_multifile.o device.o timer.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main_multifile.o: main_multifile.c device.h timer.h
	$(CC) $(CFLAGS) -c main_multifile.c -o main_multifile.o

device.o: device.c device.h
	$(CC) $(CFLAGS) -c device.c -o device.o

timer.o: timer.c timer.h
	$(CC) $(CFLAGS) -c timer.c -o timer.o

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: run clean