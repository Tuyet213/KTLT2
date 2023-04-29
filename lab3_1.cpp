#include<stdio.h>
#include<math.h>

//a
int S_a_lap(int a, int n){
	int S=1;
	for(int i=1;i<=n;i++) S=S*a;
	return S;
}

int S_a_dequy(int a, int n){
	if(n==1) return a;
	return S_a_dequy(a,n-1)*a;
}

//b
int S_b_lap(int n){
	int S=0;
	for(int i=1;i<=n;i++){
		S+=pow(i,2);
	}
	return S;
}

int S_b_dequy(int n){
	if(n==1) return 1;
	return S_b_dequy(n-1)+pow(n,2);
}

//c
int dem_lap(int n){
	int dem=0;
	while(n>0){
		dem++;
		n=n/10;
	}
	return dem;
}

int dem_dequy(int n){
	if(n<10) return 1;
	return dem_dequy(n/10)+1;
}

//d
int fibo_lap(int n){
	int a=1;
	int b=1;
	int temp;
	for(int i=3;i<=n;i++){
		temp=a+b;
		a=b;
		b=temp;
	}
	return temp;
}

int fibo_dequy(int n){
	if(n==1||n==2) return 1;
	return fibo_dequy(n-1)+fibo_dequy(n-2);
}

//e
int UCLN_lap(int a, int b){
	int temp;
	if(a<b) {
		temp=a;
		a=b;
		b=temp;
	}
	while(a%b){
		temp=a%b;
		a=b;
		b=temp;
	}
	return b;
}

int UCLN_dequy(int a, int b){
	int temp;
	if(a<b) {
		temp=a;
		a=b;
		b=temp;
	}
	if(a%b==0) return b;
	return UCLN_dequy(b,a%b);
}

int main(){
	int n;
	int a;
	int b;
//	printf("Nhap gia tri n: ");
//	scanf("%d",&n);
//	printf("Nhap gia tri a: ");
//	scanf("%d",&a);
//	printf("%d %d ",S_a_lap(a,n),S_a_dequy(a,n));
//	printf("\n%d %d ",S_b_lap(n),S_b_dequy(n));
	
//	do{
//		printf("Nhap gia tri n: ");
//		scanf("%d",&n);
//	}while(n<=10||n>=1000);
//	printf("\n%d %d ",dem_lap(n),dem_dequy(n));
//	printf("\n%d %d",fibo_lap(n),fibo_dequy(n));

	printf("Nhap a, b: ");
	scanf("%d%d",&a,&b);
	printf("%d %d",UCLN_lap(a,b),UCLN_dequy(a,b));
	return 1;
}
