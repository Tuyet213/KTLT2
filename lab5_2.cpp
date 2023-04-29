#include<stdio.h>

void nhapmang(int a[], int &n){
	do{
		printf("Nhap n: ");
		scanf("%d",&n);
	}while(n<=5||n>=100);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void xuatmang(int a[], int n){
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}

void hoanvi(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void sapxep(int a[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j]) hoanvi(a[i],a[j]);
}

//a

int tim(int a[], int x, int l, int r){
	if(l<=r){
		int m=(l+r)/2;
		if(a[m]==x) return m;
		if(a[m]<x) return tim(a,x,m+1,r);
		else return tim(a,x,l,m-1);
	}
	return -1;
//	if(l==r){
//		if(a[l]==x) return l;
//		else return -1;
//	}
//	int m=(l+r)/2;
//	if(a[m]==x) return m;
//	if(a[m]<x)	return tim(a,x,m+1,r);
//	else return tim(a,x,l,m-1);
}

//b

int dem(int a[], int x, int l, int r){
	if(l==r){
		if(a[l]==x) return 1;
		else return 0;
	}
	int m=(l+r)/2;
	return dem(a,x,l,m)+dem(a,x,m+1,r);
}


//c

int max(int a[], int l, int r){
	if(l==r) return a[l];
	int m=(l+r)/2;
	int max1=max(a,l,m);
	int max2=max(a,m+1,r);
	if(max1>max2) return max1;
	else return max2;
//	if(max(a,l,m)>max(a,m+1,r)) return max(a,l,m);
//	else return max(a,m+1,r);
}

int max_index(int a[], int l, int r, int &index){
	if(l==r){
		index=l;
		return a[l];
	}
	int m=(l+r)/2;
	int b,c;
	int max1=max_index(a,l,m,b);
	int max2=max_index(a,m+1,r,c);
	if(max1>max2) {
		index=b;
		return max1;
	}
	else {
		index=c;
		return max2;
	}
}
int Find(int a[], int l, int r, int x){
	if(l==r){
		if(a[l]==x) return l;
		else return -1; 
	}
	int m=(l+r)/2;
	if(x>a[m]){
		return Find(a,m+1,r,x);
	}
	if(x<a[m]){
		return Find(a,l,m-1,x);
	}
	if(x==a[m]) return m;
}

int main(){
	int a[30];
	int n;
	int x;
	nhapmang(a,n);
	sapxep(a,n);
	xuatmang(a,n);
	printf("\nNhap x: ");
	scanf("%d",&x);
//	printf("Vi tri cua %d la %d",x,tim(a,x,0,n-1));
	printf("Vi tri cua %d la %d",x,Find(a,0,n-1,x));
//	printf("So luong %d trong mang la: %d",x,tim(a,x,0,n-1));
//	printf("\nGia tri lon  nhat la %d",max_index(a,0,n-1,x));
//	printf("\n%d",x);
	return 1;
}
