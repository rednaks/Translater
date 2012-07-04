#include"functions.h"
 
int main(int argc,char *argv[]) {

	if (argc > 1) {
		int v = verif(argv,argc);
		if(v==1)
		{
			printHelp();
		}
		else if (v==2)
		{
			printf("Translate to specific lang\n");
		}
		else if (v==3)
			printf("Error lang\n");
		else{
			int i=0;
			while(argc > ++i){
			if(!optionT(argv[i]))
			translate(argv[i]);
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
