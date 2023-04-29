#include<stdio.h>
#include<string.h>
#include<ctype.h>
#pragma pack(1)
#define MaxWords 1024
#define Maxlength 64

typedef struct{
	char word[Maxlength]; //luu tu word de duyet
	long count; //so lan xuat hien cua tu word 
} WordEntry; //luu tan suat xuat hien cua tu nao do 

void checkNewWord(WordEntry Words[], int &nWord, char *word){
	int n = nWord;
	WordEntry newWord;
	if(word == NULL || strlen(word) == 0) return ;
	while(n--){
		if(strcmp(Words[n].word, word) == 0){
			Words[n].count++;
			return ;
		}
	}
	if(nWord < MaxWords){
		strcpy(newWord.word, word);
		newWord.count = 1;
		Words[nWord++] = newWord;
		//nWord++;
	}
}

void countEachWord(FILE *InFile, WordEntry Words[], int &nWord){
	char word[Maxlength] = "";
	int ch; //dung int de gan Word[len]=0, Word=0;
	int len = 0;
	while(!feof(InFile)){///////////////////////////////////////////////////////
		ch = fgetc(InFile);
		if(ch == EOF) break;
		ch = tolower(ch);
		if('a' <= ch && ch <= 'z'){
			word[len++] = ch;//them  ky tu hien hanh
		//	len++;
		}
		else{
			word[len]=0;              //word="Tuyet0"
			checkNewWord(Words, nWord, word);
			word[0] = 0;              //dua chuoi ve rong, xet tu ke tiep
			len = 0;
		}
	}
}

void showWords(FILE *OutFile, WordEntry Words[], int nWord){
	for(int i = 0; i < nWord; i++){
		fprintf(OutFile, "%s : %ld time(s)\n", Words[i].word, Words[i].count); //OutFile de ghi ==>"wt"
	}
}

int main(){
	WordEntry Words[MaxWords];
	int nWord;
	FILE *InFile=fopen("DataTuyet.txt","rt");
	if(InFile !=NULL){
		countEachWord(InFile, Words, nWord);
		showWords(stdout,Words,nWord);
		fclose(InFile);
	}
	return 1;
}




















