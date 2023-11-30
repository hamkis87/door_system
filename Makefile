PROG = main.exe 
SRC = main.cpp DoorSystem.cpp Card.cpp Utilities.cpp
CC=g++
CFLAGS = -g -std=c++17
LIBS = 

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean