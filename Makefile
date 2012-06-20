obj = bin/obj
src = src
bin = bin
init = mkdir -p bin/obj
debug = 
flags = -Wall -O3 $(debug)

translater : functions.o main.o
	gcc $(flags) $(obj)/functions.o $(obj)/main.o -o $(bin)/translater
	
functions.o : $(src)/functions.c $(src)/functions.h
	$(init)
	gcc $(flags) -c $(src)/functions.c -o $(obj)/functions.o

main.o : $(src)/functions.h  $(src)/main.c
	$(init)
	gcc -c $(flags) $(src)/main.c -o $(obj)/main.o

clean :
	rm $(obj)/*.o
