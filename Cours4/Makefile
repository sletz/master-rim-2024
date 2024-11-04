 
all: gen_square gen_sinus gen_sawtooth signals

gen_square : gen_square.c
	gcc -Wall gen_square.c -o gen_square

gen_sinus : gen_sinus.c
	gcc -Wall gen_sinus.c -o gen_sinus

gen_sawtooth : gen_sawtooth.c
	gcc -Wall gen_sawtooth.c -o gen_sawtooth

signals : signals.c
	gcc -Wall signals.c -o signals

clean:
	rm -f gen_square gen_sawtooth gen_sinus signals
