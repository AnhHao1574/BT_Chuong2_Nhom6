#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void interchangeSortSonguyen(int arr[], int n);
void interchangeSortSoThuc(float arr[], int n);
void interchangeSortKytu(char arr[], int n);
void interchangeSortChuoiKyTu(char arr[][100], int n);

void main() {
    int choice;
    int intArr[] = { 5, 2, 9, 1, 5, 6 };
    float floatArr[] = { 2.5, 3.1, 1.4, 6.7 };
    char charArr[] = { 'z', 'a', 'e', 'b' };
    char strArr[4][100] = { "banana", "apple", "cherry", "date" };

    int nInt = sizeof(intArr) / sizeof(intArr[0]);
    int nFloat = sizeof(floatArr) / sizeof(floatArr[0]);
    int nChar = sizeof(charArr) / sizeof(charArr[0]);
    int nString = sizeof(strArr) / sizeof(strArr[0]);

    do {
        printf("\nMenu:\n");
        printf("1. Sap xep so nguyen tang dan\n");
        printf("2. Sap xep so thuc tang dan\n");
        printf("3. Sap xep ky tu tang dan\n");
        printf("4. Sap xep chuoi ky tu tang dan\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            interchangeSortSonguyen(intArr, nInt);
            printf("Sap xep so nguyen tang dan: ");
            for (int i = 0; i < nInt; i++) {
                printf("%d ", intArr[i]);
            }
            printf("\n");
            break;
        case 2:
            interchangeSortSoThuc(floatArr, nFloat);
            printf("Sap xep so thuc tang dan: ");
            for (int i = 0; i < nFloat; i++) {
                printf("%.2f ", floatArr[i]);
            }
            printf("\n");
            break;
        case 3:
            interchangeSortKytu(charArr, nChar);
            printf("Sap xep ky tu tang dan: ");
            for (int i = 0; i < nChar; i++) {
                printf("%c ", charArr[i]);
            }
            printf("\n");
            break;
        case 4:
            interchangeSortChuoiKyTu(strArr, nString);
            printf("Sap xep chuoi ky tu tang dan: ");
            for (int i = 0; i < nString; i++) {
                printf("%s ", strArr[i]);
            }
            printf("\n");
            break;
        case 5:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 5);
}

// Hàm s?p x?p s? nguyên tãng
void interchangeSortSonguyen(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm s?p x?p s? th?c tãng
void interchangeSortSoThuc(float arr[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm s?p x?p k? t? tãng
void interchangeSortKytu(char arr[], int n) {
    int i, j;
    char temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm s?p x?p chu?i k? t? tãng
void interchangeSortChuoiKyTu(char arr[][100], int n) {
    int i, j;
    char temp[100];
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}
