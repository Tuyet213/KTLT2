#include<stdio.h>
int main(){
	FILE* fp = fopen("xoa.txt","wt");
//	fprintf(fp, "0123456");
//	rewind(fp);
//	fprintf(fp, "******");
	fprintf(fp, "1234567890");
	fseek(fp, -5L, 1);
	fprintf(fp, "*");

} 
