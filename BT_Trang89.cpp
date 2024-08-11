#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

// Hàm tính tổng các phần tử nằm trên đường chéo chính
int tongDuongCheoChinh(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][i];
    }
    return tong;
}

// Hàm tính tổng các phần tử nằm trên đường chéo phụ
int tongDuongCheoPhu(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][n - 1 - i];
    }
    return tong;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo chính
int tongPhiaTrenDuongCheoChinh(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo phụ
int tongPhiaTrenDuongCheoPhu(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void menu() {
    printf("Menu:\n");
    printf("1. Tinh tong cac phan tu nam tren duong cheo chinh\n");
    printf("2. Tinh tong cac phan tu nam tren duong cheo phu\n");
    printf("3. Tinh tong cac phan tu nam phia tren duong cheo chinh\n");
    printf("4. Tinh tong cac phan tu nam phia tren duong cheo phu\n");
    printf("0. Thoat\n");
}

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int n;
    int choice;

    // Nhập kích thước ma trận
    printf("Nhap so dong/so cot (n): ");
    scanf_s("%d", &n);

    // Nhập ma trận
    printf("Nhap ma tran (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    do {
        menu();
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Tong cac phan tu nam tren duong cheo chinh: %d\n", tongDuongCheoChinh(a, n));
            break;
        case 2:
            printf("Tong cac phan tu nam tren duong cheo phu: %d\n", tongDuongCheoPhu(a, n));
            break;
        case 3:
            printf("Tong cac phan tu nam phia tren duong cheo chinh: %d\n", tongPhiaTrenDuongCheoChinh(a, n));
            break;
        case 4:
            printf("Tong cac phan tu nam phia tren duong cheo phu: %d\n", tongPhiaTrenDuongCheoPhu(a, n));
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 0);

    return 0;
}
