all: message

message: message.c cipher.o
	gcc -o $@ $^

cipher.o: cipher.c
	gcc -c -o $@ $<

.PHONY: clean

clean:
	rm message
	rm cipher.o
