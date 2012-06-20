obj = bin/obj
src = src
bin = bin


translater : functions.o main.o
	gcc $(obj)/functions.o $(obj)/main.o -o $(bin)/translater
	
functions.o : $(src)/functions.c $(src)/functions.h
	gcc -c $(src)/functions.c -o $(obj)/functions.o

main.o : $(src)/functions.h  $(src)/main.c
	gcc -c $(src)/main.c -o $(obj)/main.o

clean :
	rm $(obj)/*.o
