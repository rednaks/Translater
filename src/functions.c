#include"functions.h"

void translate(char *s) {

	CURL *handle=curl_easy_init();

	if (handle){

		curl_easy_setopt(handle,CURLOPT_URL,"http://rednaks.alwaysdata.net/translate/?text=salut");
		curl_easy_perform(handle);
		curl_easy_cleanup(handle);

	}
	//printf("le texte est :%s ",s);
	else 
		printf("erreur lors de l'initialisation de la fonction curl_easy_init()\n");
	
	
}
