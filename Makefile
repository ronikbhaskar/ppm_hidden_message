main: hidden_message.o image_decoder.o
	gcc -Wall hidden_message.o -o hidden_message
	gcc -Wall image_decoder.o -o image_decoder

hidden_message.o: hidden_message.c hidden_message.h
	gcc -Wall -c hidden_message.c -o hidden_message.o

image_decoder.o: image_decoder.c image_decoder.h
	gcc -Wall -c image_decoder.c -o image_decoder.o	

clean:
	rm -f hidden_message.o hidden_message image_decoder.o image_decoder