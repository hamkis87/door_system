PROG = main.exe 
SRC = main.cpp DoorSystem.cpp Card.cpp 
CC=g++
CFLAGS = -g
LIBS = 

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean