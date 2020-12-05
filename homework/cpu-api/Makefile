
all: p1 p2 p3 p4 p5 p6 p7 p8 man_p8

clean:
	rm -f p1 p2 p3 p4 p5 p6 p7 p8 man_p8 *.output

p1: p1.c
	gcc -o p1 p1.c -Wall

p2: p2.c
	gcc -o p2 p2.c -Wall -pthread

p3: p3.c
	gcc -o p3 p3.c -Wall

p4: p4.c
	gcc -o p4 p4.c -Wall

p5: p5.c
	gcc -o p5 p5.c -Wall

p6: p6.c
	gcc -o p6 p6.c -Wall

p7: p7.c
	gcc -o p7 p7.c -Wall

p8: p8.c
	gcc -o p8 p8.c -Wall

man_p8: man_p8.c
	gcc -o man_p8 man_p8.c -Wall