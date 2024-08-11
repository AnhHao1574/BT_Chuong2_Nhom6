#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 50

typedef struct {
    int tu;
    int mau;
} PhanSo;

int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

// H�m t?i gi?n ph�n s?
void toiGianPhanSo(PhanSo* ps) {
    int gcd = ucln(ps->tu, ps->mau);
    ps->tu /= gcd;
    ps->mau /= gcd;
}

// H�m nh?p danh s�ch c�c ph�n s?
void nhapDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        printf("Nhap tu so: ");
        scanf_s("%d", &ds[i].tu);
        do {
            printf("Nhap mau so (khac 0): ");
            scanf_s("%d", &ds[i].mau);
            if (ds[i].mau == 0) {
                printf("Mau so phai khac 0. Vui long nhap lai.\n");
            }
        } while (ds[i].mau == 0);
        toiGianPhanSo(&ds[i]);
    }
}

// H�m xu?t m?t ph�n s?
void xuatPhanSo(PhanSo ps) {
    if (ps.mau == 1) {
        printf("%d ", ps.tu);
    }
    else {
        printf("%d/%d ", ps.tu, ps.mau);
    }
}

// H�m xu?t danh s�ch c�c ph�n s?
void xuatDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(ds[i]);
    }
    printf("\n");
}

// H�m t�nh gi� tr? c?a ph�n s? d�?i d?ng s? th?c
double giaTriPhanSo(PhanSo ps) {
    return (double)ps.tu / ps.mau;
}

// H�m t?m ph�n s? c� gi� tr? l?n nh?t
PhanSo phanSoMax(PhanSo ds[], int n) {
    PhanSo max = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(ds[i]) > giaTriPhanSo(max)) {
            max = ds[i];
        }
    }
    return max;
}

// H�m t?m ph�n s? c� gi� tr? nh? nh?t
PhanSo phanSoMin(PhanSo ds[], int n) {
    PhanSo min = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(ds[i]) < giaTriPhanSo(min)) {
            min = ds[i];
        }
    }
    return min;
}

// H�m t�nh t?ng c?a c�c ph�n s?
PhanSo tongDanhSachPhanSo(PhanSo ds[], int n) {
    PhanSo tong = { 0, 1 };
    for (int i = 0; i < n; i++) {
        tong.tu = tong.tu * ds[i].mau + ds[i].tu * tong.mau;
        tong.mau = tong.mau * ds[i].mau;
        toiGianPhanSo(&tong);
    }
    return tong;
}

// H�m t�nh t�ch c?a c�c ph�n s?
PhanSo tichDanhSachPhanSo(PhanSo ds[], int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tu = tich.tu * ds[i].tu;
        tich.mau = tich.mau * ds[i].mau;
        toiGianPhanSo(&tich);
    }
    return tich;
}

// H�m xu?t ngh?ch �?o gi� tr? c?a c�c ph�n s?
void nghichDaoDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        if (ds[i].tu == 0) {
            printf("Nghich dao cua phan so %d/%d la 0\n", ds[i].tu, ds[i].mau);
        }
        else {
            printf("Nghich dao cua phan so %d/%d la %d/%d\n", ds[i].tu, ds[i].mau, ds[i].mau, ds[i].tu);
        }
    }
}

// H�m s?p x?p m?ng ph�n s? t�ng d?n theo ph��ng ph�p s?p x?p n?i b?t
void sapXepTangDan(PhanSo ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (giaTriPhanSo(ds[j]) > giaTriPhanSo(ds[j + 1])) {
                PhanSo temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// H�m s?p x?p m?ng ph�n s? gi?m d?n theo ph��ng ph�p s?p x?p n?i b?t
void sapXepGiamDan(PhanSo ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (giaTriPhanSo(ds[j]) < giaTriPhanSo(ds[j + 1])) {
                PhanSo temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

int main() {
    PhanSo ds[MAX_SIZE];
    int n;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Nhap danh sach phan so\n");
        printf("2. Xuat danh sach phan so\n");
        printf("3. Tim phan so co gia tri lon nhat\n");
        printf("4. Tim phan so co gia tri nho nhat\n");
        printf("5. Tinh tong cac phan so\n");
        printf("6. Tinh tich cac phan so\n");
        printf("7. Xuat nghich dao cua cac phan so\n");
        printf("8. Sap xep danh sach phan so tang dan\n");
        printf("9. Sap xep danh sach phan so giam dan\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong phan so (n <= 50): ");
            scanf_s("%d", &n);
            if (n <= 0 || n > MAX_SIZE) {
                printf("So luong phan so khong hop le.\n");
            }
            else {
                nhapDanhSachPhanSo(ds, n);
            }
            break;

        case 2:
            printf("Danh sach phan so:\n");
            xuatDanhSachPhanSo(ds, n);
            break;

        case 3: {
            PhanSo max = phanSoMax(ds, n);
            printf("Phan so co gia tri lon nhat: ");
            xuatPhanSo(max);
            printf("\n");
            break;
        }

        case 4: {
            PhanSo min = phanSoMin(ds, n);
            printf("Phan so co gia tri nho nhat: ");
            xuatPhanSo(min);
            printf("\n");
            break;
        }

        case 5: {
            PhanSo tong = tongDanhSachPhanSo(ds, n);
            printf("Tong cua cac phan so: ");
            xuatPhanSo(tong);
            printf("\n");
            break;
        }

        case 6: {
            PhanSo tich = tichDanhSachPhanSo(ds, n);
            printf("Tich cua cac phan so: ");
            xuatPhanSo(tich);
            printf("\n");
            break;
        }

        case 7:
            printf("Nghich dao cua cac phan so:\n");
            nghichDaoDanhSachPhanSo(ds, n);
            break;

        case 8:
            sapXepTangDan(ds, n);
            printf("Danh sach phan so sau khi sap xep tang dan:\n");
            xuatDanhSachPhanSo(ds, n);
            break;

        case 9:
            sapXepGiamDan(ds, n);
            printf("Danh sach phan so sau khi sap xep giam dan:\n");
            xuatDanhSachPhanSo(ds, n);
            break;

        case 0:
            printf("Thoat chuong trinh...\n");
            break;

        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
