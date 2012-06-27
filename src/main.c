#include"functions.h"

int main(int argc,char *argv[]) {

	if (argc > 1) {
		
		if(verif(argv,argc)){
		printHelp();
		}else{
			int i=1;
			while(argc > i){
			if(!optionT(argv[i]))
			translate(argv[i++]);
			}
		}
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
