#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Hàm ki?m tra ch? s? ð?u c?a s? nguyên
int chuSoDau(int x) {
    while (x >= 10) {
        x /= 10;
    }
    return x;
}

// Hàm tính t?ng các ph?n t? có ch? s? ð?u là ch? s? l?
int tongSoLeDau(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int dau = chuSoDau(abs(a[i][j]));
            if (dau % 2 != 0) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Hàm ki?m tra s? hoàn thi?n
bool laSoHoanThien(int n) {
    if (n <= 1) return false;
    int tong = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return tong == n;
}

// Hàm li?t kê các s? hoàn thi?n trong ma tr?n
void lietKeSoHoanThien(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    printf("Cac so hoan thien trong ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Hàm tính t?ng các ph?n t? l?n hõn tr? tuy?t ð?i c?a ph?n t? li?n sau nó
int tongLonHonTuyetDoiSau(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] > abs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Hàm tính t?ng giá tr? trên d?ng k
int tongTrenDongK(int a[MAX_SIZE][MAX_SIZE], int m, int n, int k) {
    if (k < 0 || k >= m) {
        printf("Chi so dong k khong hop le.\n");
        return 0;
    }
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[k][j];
    }
    return tong;
}

// Hàm tính t?ng các giá tr? n?m trên biên c?a ma tr?n
int tongBien(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int tong = 0;
    // Tính t?ng hàng ð?u và hàng cu?i
    for (int j = 0; j < n; j++) {
        tong += a[0][j];
        if (m > 1) {
            tong += a[m - 1][j];
        }
    }
    // Tính t?ng c?t ð?u và c?t cu?i
    for (int i = 1; i < m - 1; i++) {
        tong += a[i][0];
        if (n > 1) {
            tong += a[i][n - 1];
        }
    }
    return tong;
}

// Hàm ð?m t?n su?t xu?t hi?n c?a giá tr? x
int demTanSuat(int a[MAX_SIZE][MAX_SIZE], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                dem++;
            }
        }
    }
    return dem;
}

// Hàm ki?m tra s? nguyên t?
bool laSoNguyenTo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm ð?m s? lý?ng các ph?n t? là s? ch?n, s? l?, s? âm, s? dýõng, s? nguyên t?
void demPhanTu(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int chan = 0, le = 0, am = 0, duong = 0, nguyenTo = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                chan++;
            }
            else {
                le++;
            }
            if (a[i][j] < 0) {
                am++;
            }
            else if (a[i][j] > 0) {
                duong++;
            }
            if (laSoNguyenTo(abs(a[i][j]))) {
                nguyenTo++;
            }
        }
    }

    printf("So luong so chan: %d\n", chan);
    printf("So luong so le: %d\n", le);
    printf("So luong so am: %d\n", am);
    printf("So luong so duong: %d\n", duong);
    printf("So luong so nguyen to: %d\n", nguyenTo);
}

void main() {
    int a[MAX_SIZE][MAX_SIZE];
    int m, n;

    // Nh?p kích thý?c ma tr?n
    printf("Nhap so hang m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);

    // Nh?p ma tr?n
    printf("Nhap ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("2. Liet ke cac so hoan thien trong ma tran\n");
        printf("3. Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau\n");
        printf("4. Tinh tong gia tri tren dong k\n");
        printf("5. Tinh tong cac gia tri nam tren bien cua ma tran\n");
        printf("6. Dem tan suat xuat hien cua gia tri x\n");
        printf("7. Dem so luong cac phan tu (so chan, le, am, duong, nguyen to)\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            int tong = tongSoLeDau(a, m, n);
            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tong);
            break;
        }
        case 2: {
            lietKeSoHoanThien(a, m, n);
            break;
        }
        case 3: {
            int tong = tongLonHonTuyetDoiSau(a, m, n);
            printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", tong);
            break;
        }
        case 4: {
            int k;
            printf("Nhap chi so dong k: ");
            scanf_s("%d", &k);
            int tong = tongTrenDongK(a, m, n, k);
            printf("Tong gia tri tren dong k: %d\n", tong);
            break;
        }
        case 5: {
            int tong = tongBien(a, m, n);
            printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tong);
            break;
        }
        case 6: {
            int x;
            printf("Nhap gia tri x: ");
            scanf_s("%d", &x);
            int tanSuat = demTanSuat(a, m, n, x);
            printf("Tan suat xuat hien cua gia tri %d: %d\n", x, tanSuat);
            break;
        }
        case 7: {
            demPhanTu(a, m, n);
            break;
        }
        case 8:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);
}
