CC = clang
CFLAGS = -Werror -Wall -Wextra -Wconversion -Wdouble-promotion -Wstrict-prototypes -pedantic 
LFLAGS = 
LDLIBS = -lm
EXEC = colorb
TEST = iotest

HEADERS = io.h bmp.h 

all: $(EXEC) $(TEST)

$(TEST): $(TEST).o io.o
	$(CC) $^ $(LFLAGS) -o $@

$(EXEC): $(EXEC).o io.o bmp.o
	$(CC) $^ $(LFLAGS) -o $@ $(LDLIBS)

%.o: %.c $(HEADERS)
	$(CC) $^ $(CFLAGS) -c $<

clean:
	rm -rf $(EXEC) $(TEST) *.o *.gch

format:
	clang-format -i -style=file *.[ch]

.PHONY: all clean format
