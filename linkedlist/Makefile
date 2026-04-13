LIBNAME=liblinkedlist.a
TARGET:${LIBNAME} exe
${LIBNAME}:linkedlist.o
	ar rs ${LIBNAME} linkedlist.o
exe:main.o ${LIBNAME}
	gcc -g main.o -o exe -L . -llinkedlist
linkedlist.o:linkedlist.c
	gcc -g -c -I . linkedlist.c -o linkedlist.o
main.o:main.c
	gcc -g -c -I . main.c -o main.o
clean:
	rm *.o
	rm exe
	rm ${LIBNAME}