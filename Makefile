obj = bin/obj
src = src
bin = bin
init = mkdir -p bin/obj
debug = 
flags = -Wall -lcurl -std=c99
ifeq ($(debug),true)
cflags := $(flags) -O0 -g
else
cflags := $(flags) -O3
endif

all: $(bin)/translater

$(bin)/translater : $(obj)/functions.o $(obj)/main.o
	@echo "\033[1m[CC]\033[0m translater"
	@gcc $(obj)/functions.o $(obj)/main.o -o $(bin)/translater $(cflags)
	
$(obj)/functions.o : $(src)/functions.c $(src)/functions.h
	@$(init)
	@echo "\033[1m[CC]\033[0m function.o"
	@gcc -c $(src)/functions.c -o $(obj)/functions.o $(cflags)

$(obj)/main.o : $(src)/functions.h  $(src)/main.c
	@$(init)
	@echo "\033[1m[CC]\033[0m main.o"
	@gcc -c $(src)/main.c -o $(obj)/main.o $(cflags) 

clean :
	@echo "\033[31mCleaning all\033[0m"
	@rm $(obj)/*.o $(bin)/translater

install: all
	@echo "\033[1mInstalling ...\033[0m"
	@install $(bin)/translater /usr/bin/
