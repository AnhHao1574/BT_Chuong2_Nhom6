#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Khai báo các hàm trý?c khi s? d?ng
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int timMax(int a[], int n);
int timMin(int a[], int n);
int demChan(int a[], int n);
int demLe(int a[], int n);
int timKiemTuyenTinh(int a[], int n, int x);
int timKiemNhiPhan(int a[], int n, int x);
int demSoLanXuatHien(int a[], int n, int x);
int demLonHonX(int a[], int n, int x);
int tongMang(int a[], int n);
bool KTraSNT(int n);
void xuatSNT(int a[], int n);
bool KTraSoHoanThien(int n);
void xuatSoHoanThien(int a[], int n);
void xuatViTriChan(int a[], int n);
void xuatViTriLe(int a[], int n);
void xuatMaxMinViTri(int a[], int n);

int main() {
    int n;
    int a[MAX];

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Nhap mang va tinh cac gia tri\n");
        printf("2. Tim kiem tuyen tinh\n");
        printf("3. Tim kiem nhi phan\n");
        printf("4. Dem so lan xuat hien\n");
        printf("5. Dem so phan tu lon hon x\n");
        printf("6. Tinh tong cac phan tu trong mang\n");
        printf("7. Xuat cac so nguyen to, so hoan thien, cac vi tri chan, le, va gia tri max/min\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            printf("Nhap so luong phan tu cua mang: ");
            scanf_s("%d", &n);

            nhapMang(a, n);

            printf("Mang vua nhap: ");
            xuatMang(a, n);

            int max = timMax(a, n);
            int min = timMin(a, n);
            printf("Gia tri lon nhat cua mang: %d\n", max);
            printf("Gia tri nho nhat cua mang: %d\n", min);

            int soChan = demChan(a, n);
            int soLe = demLe(a, n);
            printf("So phan tu chan: %d\n", soChan);
            printf("So phan tu le: %d\n", soLe);
            break;
        }
        case 2: {
            int x;
            printf("Nhap gia tri can tim kiem: ");
            scanf_s("%d", &x);

            int viTri = timKiemTuyenTinh(a, n, x);
            if (viTri != -1) {
                printf("(Tim kiem tuyen tinh)\nGia tri %d duoc tim thay o vi tri %d.\n", x, viTri);
            }
            else {
                printf("Gia tri %d khong ton tai trong mang.\n", x);
            }
            break;
        }
        case 3: {
            int x;
            printf("Nhap gia tri can tim kiem: ");
            scanf_s("%d", &x);

            int viTri = timKiemNhiPhan(a, n, x);
            if (viTri != -1) {
                printf("(Tim kiem nhi phan)\nGia tri %d duoc tim thay o vi tri %d.\n", x, viTri);
            }
            else {
                printf("Gia tri %d khong ton tai trong mang.\n", x);
            }
            break;
        }
        case 4: {
            int x;
            printf("Nhap gia tri can tim kiem: ");
            scanf_s("%d", &x);

            int soLan = demSoLanXuatHien(a, n, x);
            printf("Gia tri %d xuat hien %d lan trong mang.\n", x, soLan);
            break;
        }
        case 5: {
            int x;
            printf("Nhap gia tri x: ");
            scanf_s("%d", &x);

            int soLonHonX = demLonHonX(a, n, x);
            printf("So luong phan tu lon hon %d trong mang: %d\n", x, soLonHonX);
            break;
        }
        case 6: {
            int tong = tongMang(a, n);
            printf("Tong cac phan tu trong mang: %d\n", tong);
            break;
        }
        case 7: {
            xuatSNT(a, n);
            xuatSoHoanThien(a, n);
            xuatViTriChan(a, n);
            xuatViTriLe(a, n);
            xuatMaxMinViTri(a, n);
            break;
        }
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 8);

    return 0;
}

// Hàm nh?p m?ng
void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf_s("%d", &a[i]);
    }
}

// Hàm xu?t m?ng
void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm t?m giá tr? l?n nh?t c?a m?ng
int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Hàm t?m giá tr? nh? nh?t c?a m?ng
int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// Hàm ð?m s? ph?n t? ch?n trong m?ng
int demChan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Hàm ð?m s? ph?n t? l? trong m?ng
int demLe(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

// Hàm t?m ki?m tuy?n tính
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i; // Tr? v? v? trí ð?u tiên t?m th?y
        }
    }
    return -1; // Không t?m th?y
}

// Hàm t?m ki?m nh? phân (yêu c?u m?ng ð? ðý?c s?p x?p)
int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Không t?m th?y
}

// Hàm ð?m s? l?n xu?t hi?n c?a ph?n t? x trong m?ng
int demSoLanXuatHien(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

// Hàm ð?m s? ph?n t? l?n hõn x trong m?ng
int demLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

// Hàm tính t?ng các ph?n t? c?a m?ng
int tongMang(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

// Hàm ki?m tra s? nguyên t?
bool KTraSNT(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm xu?t các s? nguyên t? trong m?ng
void xuatSNT(int a[], int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (KTraSNT(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Hàm ki?m tra s? hoàn thi?n
bool KTraSoHoanThien(int n) {
    if (n < 1) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

// Hàm xu?t các s? hoàn thi?n trong m?ng
void xuatSoHoanThien(int a[], int n) {
    printf("Cac so hoan thien trong mang: ");
    for (int i = 0; i < n; i++) {
        if (KTraSoHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Hàm xu?t các ph?n t? ? v? trí ch?n trong m?ng
void xuatViTriChan(int a[], int n) {
    printf("Cac phan tu o vi tri chan trong mang: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm xu?t các ph?n t? ? v? trí l? trong m?ng
void xuatViTriLe(int a[], int n) {
    printf("Cac phan tu o vi tri le trong mang: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm xu?t giá tr? max/min kèm v? trí c?a giá tr? ðó trong m?ng
void xuatMaxMinViTri(int a[], int n) {
    int max = a[0], min = a[0];
    int maxP = 0, minP = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            maxP = i;
        }
        if (a[i] < min) {
            min = a[i];
            minP = i;
        }
    }
    printf("Gia tri lon nhat trong mang: %d, vi tri: %d\n", max, maxP);
    printf("Gia tri nho nhat trong mang: %d, vi tri: %d\n", min, minP);
}
