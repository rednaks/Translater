#include"functions.h"

void translate(char *s) {

	CURL *handle=curl_easy_init();
	char url[2000]={'\0'};
	sprintf(url,"%s%s","http://rednaks.alwaysdata.net/translate/?text=",s);
	if (handle){

		curl_easy_setopt(handle,CURLOPT_URL,url);
		curl_easy_perform(handle);
		curl_easy_cleanup(handle);

	}
	//printf("le texte est :%s ",s);
	else 
		printf("erreur lors de l'initialisation de la fonction curl_easy_init()\n");
		
}
