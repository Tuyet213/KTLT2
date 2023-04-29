#include<stdio.h>
#include<string.h> 
#include<ctype.h> //dung strpcy(&,&) strcmp(&,&)
#pragma pack(1)
#define Maxwords 1024
#define MaxLength 64

typedef struct{
	char word[MaxLength];
	int count;
} WORD;

void checkNewWord(WORD WordArr[], int &nArr, char *Word){
	if(Word[0]==NULL) return;
//	if(Word==NULL||strlen(Word)==0) return;
	WORD newWord;
	for(int i=0;i<nArr;i++){
		if(strcmp(WordArr[i].word,Word)==0){
			 WordArr[i].count++;
			 return;
		}
	}
	if(nArr<MaxLength){
		strcpy(newWord.word,Word);
		newWord.count=1;
		WordArr[nArr++]=newWord;
	}
	
}

void countEachWord(FILE *f, WORD WordArr[], int &nArr){
	char ch;
	int len=0;
	char Word[MaxLength]="";
	while(!feof(f)){
		ch=fgetc(f);
	//	if(ch==EOF) break;
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'){
			Word[len++]=ch;
		}	
		else{
			Word[len]=NULL;
			checkNewWord(WordArr,nArr, Word);
			len=0;
			Word[0]=NULL;
		}
	}
	
}

void showWord(FILE *f, WORD WordArr[],int nArr){
	for(int i=0;i<nArr;i++){
		fprintf(stdout,"%s----%d time(s)\n",WordArr[i].word, WordArr[i].count);
	}
}

int main(){
	FILE *f=fopen("DataTuyet.txt","rt");
	WORD WordArr[Maxwords];
	int nArr;
	if(f!=NULL){
		countEachWord(f,WordArr,nArr);
		showWord(stdout,WordArr,nArr);
		fclose(f);
	}
	else printf("Khong mo duoc file.\n");
	return 1;
}













