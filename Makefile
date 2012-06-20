obj = bin/obj
src = src
bin = bin
init = mkdir -p bin/obj
debug = 
flags = -Wall -O3 -lcurl  $(debug)

translater : functions.o main.o
	gcc $(obj)/functions.o $(obj)/main.o -o $(bin)/translater $(flags)
	
functions.o : $(src)/functions.c $(src)/functions.h
	$(init)
	gcc -c $(src)/functions.c -o $(obj)/functions.o $(flags)

main.o : $(src)/functions.h  $(src)/main.c
	$(init)
	gcc -c $(src)/main.c -o $(obj)/main.o $(flags) 

clean :
	rm $(obj)/*.o
