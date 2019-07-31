CC=gcc

make: linkedlist.c
	$(CC) linkedlist.c -o linkedlist

clean:
	rm linkedlist