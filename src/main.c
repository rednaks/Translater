#include"functions.h"

int main(int argc,char *argv[]) {

	char *text=NULL;
	text = (char *)malloc(sizeof(char)*100);
	printf("Give a text to translate : \n");
	scanf("%s",text);
	printf("DEBUG : %s\n",text);
	translate(text);
	free(text);
	return 0;

}
