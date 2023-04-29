#include<stdio.h>
void Move(int n , char a, char b, char c ){
    if(n==1){
        printf("\t%c-------%c\n",a,c);
        return;
    }
    Move(n-1,a,c,b);
    Move(1,a,b,c);
    Move(n-1,b,a,c);
    }
int main(){
    char a='A', b='B', c='C';
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    Move(n,a,b,c);
}

