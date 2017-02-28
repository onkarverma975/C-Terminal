CC=gcc
DEPS = fun_dex.h
CFLAGS=-I.
OBJ = main.c execute.c built_in.c read_line.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

shell: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
