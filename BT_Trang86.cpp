#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

// Hàm hoán đổi hai giá trị
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp một mảng theo thứ tự tăng dần
void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

// Hàm sắp xếp một mảng theo thứ tự giảm dần
void sapXepGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

// Hàm sắp xếp các dòng của ma trận
void sapXepDinhDangDauVaoMaTran(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        int temp[MAX_SIZE];
        for (int j = 0; j < m; j++) {
            temp[j] = a[i][j];
        }
        if (i % 2 == 0) {
            sapXepTang(temp, m);
        }
        else {
            sapXepGiam(temp, m);
        }
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[j];
        }
    }
}

// Hàm sắp xếp các cột theo thứ tự tăng dần hoặc giảm dần
void sapXepCot(int a[MAX_SIZE][MAX_SIZE], int n, int m, int cot, int tang) {
    int temp[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][cot];
    }

    if (tang) {
        sapXepTang(temp, n);
    }
    else {
        sapXepGiam(temp, n);
    }

    for (int i = 0; i < n; i++) {
        a[i][cot] = temp[i];
    }
}

// Hàm sắp xếp các cột của ma trận
void sapXepCotDinhDang(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int j = 0; j < m; j++) {
        sapXepCot(a, n, m, j, j % 2 == 0);
    }
}

// Hàm sắp xếp ma trận theo dạng zic-zac
void sapXepZicZac(int a[MAX_SIZE][MAX_SIZE], int n, int m, int tang) {
    int temp[MAX_SIZE];
    int index = 0;

    // Đưa toàn bộ phần tử vào mảng tạm
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[index++] = a[i][j];
        }
    }

    // Sắp xếp mảng tạm theo thứ tự tăng dần hoặc giảm dần
    if (tang) {
        sapXepTang(temp, n * m);
    }
    else {
        sapXepGiam(temp, n * m);
    }

    // Đưa các phần tử đã sắp xếp vào ma trận theo zic-zac
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                a[i][j] = temp[index++];
            }
        }
        else {
            for (int j = m - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void menu() {
    printf("Menu:\n");
    printf("1. Sap xep cac dong cua ma tran\n");
    printf("2. Sap xep cac cot cua ma tran\n");
    printf("3. Sap xep ma tran theo dang zic-zac\n");
    printf("0. Thoat\n");
}

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int n, m;
    int choice, tang;

    // Nhập kích thước ma trận
    printf("Nhap so dong (n): ");
    scanf_s("%d", &n);
    printf("Nhap so cot (m): ");
    scanf_s("%d", &m);

    // Nhập ma trận
    printf("Nhap ma tran (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    do {
        menu();
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Ma tran sau khi sap xep cac dong:\n");
            sapXepDinhDangDauVaoMaTran(a, n, m);
            xuatMaTran(a, n, m);
            break;
        case 2:
            printf("Ma tran sau khi sap xep cac cot:\n");
            sapXepCotDinhDang(a, n, m);
            xuatMaTran(a, n, m);
            break;
        case 3:
            printf("Chon sap xep tang dan (1) hay giam dan (0): ");
            scanf_s("%d", &tang);
            printf("Ma tran sau khi sap xep zic-zac:\n");
            sapXepZicZac(a, n, m, tang);
            xuatMaTran(a, n, m);
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
