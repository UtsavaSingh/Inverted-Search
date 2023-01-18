OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))
Inverted_search.exe:$(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o
