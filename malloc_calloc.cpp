#include <stdio.h>
// Thý vi?n này c?n ð? c?p phát b? nh? ð?ng
#include <stdlib.h>
 
int main()
{
    int n, i, *ptr, sum = 0;//ptr la tro -> cap phat va dung nhu mang (ko biét so luong) 
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
 
    // N?u không th? c?p phát, 
    // hàm malloc s? tr? v? con tr? NULL
    if (ptr == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
    printf("Nhap cac gia tri: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Tong = %d", sum);
 
    // Gi?i phóng vùng nh? cho con tr?
    free(ptr);
    return 0;
}
 
 
#include <stdio.h>
// Thý vi?n này c?n ð? c?p phát b? nh? ð?ng
#include <stdlib.h>
 
int main()
{
    int n, i, *ptr, sum = 0;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
 
    // N?u không th? c?p phát, 
    // hàm calloc s? tr? v? con tr? NULL
    if (ptr == NULL)
    {
        printf("Co loi! khong the cap phat bo nho.");
        exit(0);
    }
    printf("Nhap cac gia tri: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Tong = %d", sum);
 
    // Gi?i phóng vùng nh? cho con tr?
    free(ptr);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, i , n1, n2;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n1);
    ptr = (int*) malloc(n1 * sizeof(int));
    printf("Dia chi cua vung nho vua cap phat: %u", ptr);
    
    printf("\nNhap lai so luong phan tu: ");
    scanf("%d", &n2);
    // phân b? l?i vùng nh?
    ptr = (int*) realloc(ptr, n2 * sizeof(int));
    printf("Dia chi cua vung nho duoc cap phat lai: %u", ptr);
    // gi?i phóng
    free(ptr);
    return 0;
}
