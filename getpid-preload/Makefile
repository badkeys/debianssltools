all:
	gcc -fPIC -g -c -Wall getpid.c
	gcc -shared -Wl,-soname,getpid.so -o getpid.so getpid.o -lc
