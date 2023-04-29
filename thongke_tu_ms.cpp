#include<stdio.h>
#include<string.h>
#include<ctype.h>
#pragma pack(1)
#define MaxWords 1024
#define MaxLength 64

typedef struct{
	char word[MaxLength];
	int count;
} WORD_COUNT;

//kiem tra tu do moi so voi mang luu tu khong, neu dung tang count, sai thi them vao mang vaf count=1

void checkNewWord(WORD_COUNT WordArr[], int &nArr, char *Word){
//	int n=nArr;
	WORD_COUNT newWord;
	if(Word==NULL||strlen(Word)==0) return;
	for(int i=0;i<nArr;i++){  // dung ham strcmp de so sanh 2 tu
		if(strcmp(Word,WordArr[i].word)==0){
			WordArr[i].count++;
			return; //neu ko return tai day==>Word ko bang tu nao==>Word la tu moi==>them vao mang
		}
	}
	if(nArr<MaxLength){  //dung strcpy de chep tu moi vao newWord
		strcpy(newWord.word,Word);
		newWord.count=1;
		WordArr[nArr++]=newWord;
	}
}

void countEachWord(FILE *InFile, WORD_COUNT WordArr[], int &nArr){
	char Word[MaxLength]="";
	int ch;
	int len=0;
	while(!feof(InFile)){
		ch=fgetc(InFile);
		if(ch==EOF) break;
		ch=tolower(ch);
		if(ch>='a'&&ch<='z'){
			Word[len++]=ch;
		}
		else{
			Word[len]=NULL; //Word[len]=0;
			checkNewWord(WordArr, nArr, Word);
			len=0;
			Word[0]=NULL;//Word[0]=0;
		}
		
	}
}

void showWords(FILE *OutFile,  WORD_COUNT WordArr[], int &nArr){
	for(int i=0;i<nArr;i++){
		fprintf(OutFile,"%s: %d\n",WordArr[i].word,WordArr[i].count);
	}
}

int main(){
	FILE *f=fopen("DataTuyet.txt","rt");
	int nArr;
	if(f!=NULL){
		WORD_COUNT WordArr[MaxWords];
		countEachWord(f, WordArr, nArr);
		showWords(stdout,WordArr,nArr);
		fclose(f);
	}
	
}
























