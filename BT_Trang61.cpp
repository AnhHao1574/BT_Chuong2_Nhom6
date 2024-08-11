#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

// Hàm ki?m tra s? nguyên t?
bool KTraSNT(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm ki?m tra m?ng có ch?a toàn b? s? nguyên t?
bool KTraMang(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (!KTraSNT(arr[i])) return false;
    }
    return true;
}

// Hàm ki?m tra m?ng có ð?i x?ng không
bool KTTraMangDoiXung(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) return false;
    }
    return true;
}

// Hàm ki?m tra m?ng có tãng d?n, gi?m d?n hay không tãng không gi?m
void KTraMangTangGiam(int arr[], int size) {
    bool tangdan = true, giamdan = true;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) tangdan = false;
        if (arr[i] < arr[i + 1]) giamdan = false;
    }

    if (tangdan) printf("Mang tang dan.\n");
    else if (giamdan) printf("Mang giam dan.\n");
    else printf("Mang khong tang khong giam.\n");
}

int main() {
    int size, choice;
    int arr[MAX];

    do {
        printf("\nMenu:\n");
        printf("1. Nhap mang\n");
        printf("2. Kiem tra mang chua toan bo so nguyen to\n");
        printf("3. Kiem tra mang doi xung\n");
        printf("4. Kiem tra mang tang dan, giam dan hay khong tang khong giam\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            // Nh?p kích thý?c m?ng
            printf("Nhap so luong phan tu cua mang: ");
            scanf_s("%d", &size);

            // Nh?p các ph?n t? c?a m?ng
            printf("Nhap cac phan tu cua mang:\n");
            for (int i = 0; i < size; i++) {
                printf("Phan tu %d: ", i + 1);
                scanf_s("%d", &arr[i]);
            }

            // Xu?t m?ng
            printf("Mang vua nhap:\n");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2:
            // Ki?m tra m?ng có ch?a toàn b? s? nguyên t?
            if (KTraMang(arr, size)) {
                printf("Mang chua toan bo so nguyen to.\n");
            }
            else {
                printf("Mang khong chua toan bo so nguyen to.\n");
            }
            break;
        case 3:
            // Ki?m tra m?ng có ð?i x?ng không
            if (KTTraMangDoiXung(arr, size)) {
                printf("Mang doi xung.\n");
            }
            else {
                printf("Mang khong doi xung.\n");
            }
            break;
        case 4:
            // Ki?m tra m?ng có tãng d?n, gi?m d?n hay không tãng không gi?m
            KTraMangTangGiam(arr, size);
            break;
        case 5:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 5);

    return 0;
}
