#ifndef FUNC_H
#define FUNC_H 
#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include <string.h>


void translate(char *);
void getLine(char *);
void urlEncode(char *);
int optionHelp(char *);
int verif(char *[],int);
int optionT(char *);
void printHelp();
/**************************************************/
int optionLang(char *);
int langExist(char *); 
/**************************************************/

#endif
