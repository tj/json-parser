
SRC = src/json.c test/json.c
OBJ = $(SRC:.c=.o)

CFLAGS = -std=c99

test-json: $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	rm test-json

.PHONY: clean