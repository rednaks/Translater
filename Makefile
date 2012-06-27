obj = bin/obj
src = src
bin = bin
init = mkdir -p bin/obj
debug = 
flags = -Wall -O3 -lcurl  $(debug)

$(bin)/translater : $(obj)/functions.o $(obj)/main.o
	@echo "\033[1m[CC]\033[0m translater"
	@gcc $(obj)/functions.o $(obj)/main.o -o $(bin)/translater $(flags)
	
$(obj)/functions.o : $(src)/functions.c $(src)/functions.h
	@$(init)
	@echo "\033[1m[CC]\033[0m function.o"
	@gcc -c $(src)/functions.c -o $(obj)/functions.o $(flags)

$(obj)/main.o : $(src)/functions.h  $(src)/main.c
	@$(init)
	@echo "\033[1m[CC]\033[0m main.o"
	@gcc -c $(src)/main.c -o $(obj)/main.o $(flags) 

clean :
	@echo "\033[31mCleaning all\033[0m"
	@rm $(obj)/*.o $(bin)/translater

install:
	@echo "\033[1mInstalling ...\033[0m"
	@install $(bin)/translater /usr/bin/
