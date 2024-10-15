 
all: gen_square gen_sinus gen_rampe signals

gen_square : gen_square.c
	gcc -Wall gen_square.c -o gen_square

gen_sinus : gen_sinus.c
	gcc -Wall gen_sinus.c -o gen_sinus

gen_rampe : gen_rampe.c
	gcc -Wall gen_rampe.c -o gen_rampe

signals : signals.c
	gcc -Wall signals.c -o signals

clean:
	rm -f gen_square gen_rampe gen_sinus signals
