#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Khai báo c?u trúc phân s?
typedef struct {
    int tu; // T? s?
    int mau; // M?u s?
} PhanSo;

// Hàm nh?p phân s?
void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf_s("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf_s("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. vui long nhap lai !.\n");
        }
    } while (ps->mau == 0);
}

// Hàm xu?t phân s?
void xuatPhanSo(PhanSo ps) {
    if (ps.mau == 1) {
        printf("%d\n", ps.tu);
    }
    else {
        printf("%d/%d\n", ps.tu, ps.mau);
    }
}

// Hàm t?m ý?c s? chung l?n nh?t (ÝCLN)
int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

// Hàm t?i gi?n phân s?
void toiGianPhanSo(PhanSo* ps) {
    int gcd = ucln(ps->tu, ps->mau);
    ps->tu /= gcd;
    ps->mau /= gcd;
}

// Hàm tính t?ng c?a hai phân s?
PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính hi?u c?a hai phân s?
PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính tích c?a hai phân s?
PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.tu;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính thýõng c?a hai phân s?
PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau;
    ketQua.mau = ps1.mau * ps2.tu;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

int main() {
    PhanSo ps1, ps2, ketQua;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Nhap phan so thu nhat\n");
        printf("2. Nhap phan so thu hai\n");
        printf("3. Xuat phan so thu nhat\n");
        printf("4. Xuat phan so thu hai\n");
        printf("5. Tinh tong hai phan so\n");
        printf("6. Tinh hieu hai phan so\n");
        printf("7. Tinh tich hai phan so\n");
        printf("8. Tinh thuong hai phan so\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap phan so thu nhat:\n");
            nhapPhanSo(&ps1);
            break;
        case 2:
            printf("Nhap phan so thu hai:\n");
            nhapPhanSo(&ps2);
            break;
        case 3:
            printf("Phan so thu nhat: ");
            xuatPhanSo(ps1);
            break;
        case 4:
            printf("Phan so thu hai: ");
            xuatPhanSo(ps2);
            break;
        case 5:
            ketQua = tongPhanSo(ps1, ps2);
            printf("Tong cua hai phan so: ");
            xuatPhanSo(ketQua);
            break;
        case 6:
            ketQua = hieuPhanSo(ps1, ps2);
            printf("Hieu cua hai phan so: ");
            xuatPhanSo(ketQua);
            break;
        case 7:
            ketQua = tichPhanSo(ps1, ps2);
            printf("Tich cua hai phan so: ");
            xuatPhanSo(ketQua);
            break;
        case 8:
            ketQua = thuongPhanSo(ps1, ps2);
            printf("Thuong cua hai phan so: ");
            xuatPhanSo(ketQua);
            break;
        case 9:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 9);

    return 0;
}
