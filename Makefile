CC=gcc
CFLAGS=-I/usr/local/includ -g -Wall
LDFLAGS=-L/usr/local/lib -lallegro_font -lallegro_ttf -lallegro_image -lallegro_primitives -lallegro
SOURCES=main.c splash.c levelselector.c
OBJ=main.o splash.o levelselector.o
TARGET=game

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	$(RM) *~ *.o $(TARGET)

game: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

$(OBJ): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)
