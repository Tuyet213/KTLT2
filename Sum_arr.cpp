#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	if(argc>=2){
		int S=0;
		for(int i=1;i<argc;i++) S+=atoi(argv[i]);
		printf("Tong cua %d so la %d.",argc-1,S);
	}
	else printf("Sai.");
	return 0;
} 
