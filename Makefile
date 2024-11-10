all: final

final: main.o numbers.o add.o
	@echo "linking and producing final"
	gcc -m32 main.o numbers.o add.o -o final

main.o: main.c
	@echo "compiling main file"
	gcc -m32 -c main.c

numbers.o: numbers.c
	@echo "compiling numbers file"
	gcc -m32 -c numbers.c

add.o: add.s
	@echo "compiling add file"
	nasm -f elf -o add.o add.s
clean:
	@echo "cleaning"
	rm *.o final part1

part1 : part1.o
	gcc -m32 part1.o -o part1
part1.o : part1.c
	@echo "compiling debugger file"
	gcc -m32 -c part1.c
