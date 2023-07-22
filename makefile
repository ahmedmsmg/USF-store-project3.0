tshirt_store2: tshirt_store2.o tshirt.o read_line.o
	gcc -o tshirt_store2 read_line.o tshirt.o tshirt_store2.o
tshirt_store2.o: tshirt_store2.c tshirt.h read_line.h
	gcc -c tshirt_store2.c
tshirt.o: tshirt.c tshirt.h read_line.h
	gcc -c tshirt.c
read_line.o: read_line.c read_line.h
	gcc -c read_line.c
clean:
	rm tshirt.o read_line.o tshirt_store2.o tshirt_store2
