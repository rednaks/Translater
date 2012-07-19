#include"functions.h"

void translate(char *s) {

	CURL *handle=curl_easy_init();
	char url[2000]={'\0'};
	urlEncode(s);
	sprintf(url,"%s%s","http://translate.rednaks.tn/?text=",s);
	if (handle){

		curl_easy_setopt(handle,CURLOPT_URL,url);
		curl_easy_perform(handle);
		curl_easy_cleanup(handle);

	}
	//printf("le texte est :%s ",s);
	else 
		printf("erreur lors de l'initialisation de la fonction curl_easy_init()\n");
		
}

/* To be able to get The entire line, scanf cant to it very well*/
void getLine(char *stream)
{
	int i=0;
	char c;
	while((c = getchar())!='\n')
	{
		stream[i++]=c;
	}
		stream[i]='\0';
}

/*Very basic url Encoding, Only spaces are supported now
feel free to hack
*/
void urlEncode(char *str)
{
	int l = strlen(str);
	int i;
	for(i=0;i<l;i++)
	{
		if(str[i]==' ')
			str[i]='+';
	}

}

int optionHelp (char* s) {

	if(!strncmp(s,"--help",6)) 
	{
		return 1;
	}else{
		return 0;
	}
}

int verif (char *tab[],int n) {

	int i;
	for(i=0;i<n;i++)
		{
			if(optionHelp(tab[i])) return 1;
		}
	return 0;

}

int optionT (char *s) {

	if(!strncmp(s,"--",2)) 
	{
		return 1;
	}else{
		return 0;
	}
}

void printHelp(){
	
	printf("To see the help :\n\ttranslater --help\n\n\tIf you want to use this command, all you have to do is to execute the commande translate, in this case you will just translate only one sentence. If you want to translate many sentences, just give it to the command as arguments\n\n\tExemple :\n\t\ttranslater [sentence1] [sentence2] [sentence3] ..\n\n ENJOY ! ! !! <3\n");

}
