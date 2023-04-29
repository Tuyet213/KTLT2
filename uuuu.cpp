#include <stdio.h>
int &getx(int &x){
x += 2;
return x;
}
int main(){
int x = 5;
getx(x)= 10;
printf("%d",x);
}

