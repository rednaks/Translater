#include"functions.h"

int main(int argc,char *argv[]) {

	if (argc !=1) {
		translate(argv[1]);
	}else
	{
		char *text=NULL;
		text = (char *)malloc(sizeof(char)*100);
		printf("Give a text to translate : \n");
		getLine(text);
		translate(text);
		free(text);
	}
	return 0;

}
