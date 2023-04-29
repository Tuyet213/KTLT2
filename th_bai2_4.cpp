#include<stdio.h>
#include<stdlib.h>

struct HocPhan{
	char ma[255], ten[255];
	int sotc;	
};
HocPhan *ds;
int n;

void Read_File() {
	FILE* f = fopen("HocPhan.txt","r");
	if(f != NULL){
		fscanf(f, "%d\n", &n);
		char temp[255];	
		ds = (HocPhan *)malloc(n * sizeof(HocPhan));  
		for(int i = 0; i < n; i++){
			fgets(ds[i].ma, 255, f);	
			fgets(ds[i].ten, 255, f);				
			fgets(temp, 255, f);
			ds[i].sotc =atoi(temp);			
		}		
		fclose(f);
	}else
		printf("Err!");
}

void Show_List(){	
	printf("So hoc phan: %d\n",n);
	printf("Danh sach cac hoc phan:\n");
	for(int i = 0; i < n; i++){
		printf("%s", ds[i].ma);
		printf("%s", ds[i].ten);	
		printf("%d\n", ds[i].sotc);				
	}
}

void Sort_List(){	
	printf("\nThuc hien sap xep:\n");
	HocPhan lop;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(ds[i].sotc < ds[j].sotc){
				lop = ds[i];
				ds[i] = ds[j];
				ds[j] = lop;	
			}
}

void Append_File(){
	FILE* f = fopen("HocPhan.txt","r+");
	if(f != NULL){
		n++;
		fprintf(f, "%d\n", n);
		fseek(f, 0, SEEK_END);//dua con tro file toi vi tri cuoi file
		HocPhan temp;
		printf("nhap thong tin hoc phan can them:\n");
		printf("ma hoc phan:");
		gets(temp.ma); //nhan dl tu ban phim
		fprintf(f,"\n");//xuong dong trong file 
		fputs(temp.ma,f);//ghi vao file
		fprintf(f,"\n");//xuong dong trong file 
		printf("ten hoc phan:");
		gets(temp.ten);
		fputs(temp.ten, f);
		fprintf(f,"\n");
		printf("so tin chi:");
		scanf("%d",&temp.sotc);
		fprintf(f,"%d\n", temp.sotc);			
		fclose(f);
	}
	else
		printf("Err!");
}

int main(){		
	Read_File();	
	Show_List();		
	Append_File();
	Read_File();
	Show_List();
	return 0;	
}
