#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory>

#define MAX_SIZE 100
#define FILE_NAME "sinhvien.txt"

// Khai báo c?u trúc sinh viên
typedef struct {
    int stt;
    char maSV[15];
    char hoTen[100];
    float diemTieuLuan;
    float diemThi;
    float diemTongKet;
} SinhVien;

// Hàm nh?p danh sách sinh viên
void nhapDanhSachSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        ds[i].stt = i + 1;
        printf("Ma so sinh vien: ");
        scanf_s("%s", ds[i].maSV, (unsigned)_countof(ds[i].maSV));
        printf("Ho ten sinh vien: ");
        getchar();
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = '\0';
        printf("Diem tieu luan: ");
        scanf_s("%f", &ds[i].diemTieuLuan);
        printf("Diem thi ket thuc mon: ");
        scanf_s("%f", &ds[i].diemThi);
        ds[i].diemTongKet = 0.3 * ds[i].diemTieuLuan + 0.7 * ds[i].diemThi;
    }
}

// Hàm xu?t danh sách sinh viên
void xuatDanhSachSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("S%d - Ma SV: %s - Ho ten: %s - Diem TL: %.2f - Diem Thi: %.2f - Diem TK: %.2f\n",
            ds[i].stt, ds[i].maSV, ds[i].hoTen, ds[i].diemTieuLuan, ds[i].diemThi, ds[i].diemTongKet);
    }
}

// Hàm t?m sinh viên có ði?m t?ng k?t cao nh?t
SinhVien sinhVienMax(SinhVien ds[], int n) {
    SinhVien max = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTongKet > max.diemTongKet) {
            max = ds[i];
        }
    }
    return max;
}

// Hàm t?m sinh viên có ði?m t?ng k?t th?p nh?t
SinhVien sinhVienMin(SinhVien ds[], int n) {
    SinhVien min = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTongKet < min.diemTongKet) {
            min = ds[i];
        }
    }
    return min;
}

// Hàm ð?m s? sinh viên ð?t và không ð?t
void demSinhVienDatVaKhongDat(SinhVien ds[], int n, int* dat, int* khongDat) {
    *dat = 0;
    *khongDat = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diemTongKet >= 5.0) {
            (*dat)++;
        }
        else {
            (*khongDat)++;
        }
    }
}

// Hàm chuy?n ð?i ði?m t? h? 10 sang h? 4
float chuyenDiemH10SangH4(float diemH10) {
    if (diemH10 >= 9.0) return 4.0;
    if (diemH10 >= 8.0) return 3.7;
    if (diemH10 >= 7.0) return 3.3;
    if (diemH10 >= 6.5) return 3.0;
    if (diemH10 >= 6.0) return 2.7;
    if (diemH10 >= 5.5) return 2.3;
    if (diemH10 >= 5.0) return 2.0;
    if (diemH10 >= 4.0) return 1.0;
    return 0.0;
}

// Hàm xu?t ði?m h? 4 c?a sinh viên
void xuatDiemH4(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        float diemH4 = chuyenDiemH10SangH4(ds[i].diemTongKet);
        printf("S%d - Ma SV: %s - Ho ten: %s - Diem TK: %.2f - Diem H4: %.2f\n",
            ds[i].stt, ds[i].maSV, ds[i].hoTen, ds[i].diemTongKet, diemH4);
    }
}

// Hàm s?p x?p danh sách sinh viên theo ði?m t?ng k?t tãng d?n
void sapXepTangDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].diemTongKet > ds[j + 1].diemTongKet) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// Hàm s?p x?p danh sách sinh viên theo ði?m t?ng k?t gi?m d?n
void sapXepGiamDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].diemTongKet < ds[j + 1].diemTongKet) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// Hàm tính ði?m trung b?nh c?a t?t c? sinh viên
float tinhDiemTrungBinh(SinhVien ds[], int n) {
    float tong = 0.0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].diemTongKet;
    }
    return n > 0 ? tong / n : 0.0;
}

// Hàm ghi danh sách sinh viên vào file
void ghiDanhSachSinhVienVaoFile(SinhVien ds[], int n) {
    FILE* file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "S%d - Ma SV: %s - Ho ten: %s - Diem TL: %.2f - Diem Thi: %.2f - Diem TK: %.2f\n",
            ds[i].stt, ds[i].maSV, ds[i].hoTen, ds[i].diemTieuLuan, ds[i].diemThi, ds[i].diemTongKet);
    }
    fclose(file);
}

// Hàm ð?c danh sách sinh viên t? file
int docDanhSachSinhVienTuFile(SinhVien ds[]) {
    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return 0;
    }
    int n = 0;
    while (fscanf(file, "S%d - Ma SV: %s - Ho ten: %99[^\n] - Diem TL: %f - Diem Thi: %f - Diem TK: %f\n",
        &ds[n].stt, ds[n].maSV, ds[n].hoTen, &ds[n].diemTieuLuan, &ds[n].diemThi, &ds[n].diemTongKet) != EOF) {
        n++;
    }
    fclose(file);
    return n;
}

// Hàm hi?n th? menu
void hienThiMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Tim sinh vien co diem tong ket cao nhat\n");
    printf("4. Tim sinh vien co diem tong ket thap nhat\n");
    printf("5. Dem so sinh vien dat va khong dat\n");
    printf("6. Xuat diem he 4 cua cac sinh vien\n");
    printf("7. Sap xep danh sach sinh vien theo diem tong ket tang dan\n");
    printf("8. Sap xep danh sach sinh vien theo diem tong ket giam dan\n");
    printf("9. Tinh diem trung binh cua cac sinh vien\n");
    printf("10. Ghi danh sach sinh vien vao file\n");
    printf("11. Doc danh sach sinh vien tu file\n");
    printf("0. Thoat\n");
    printf("================\n");
    printf("Nhap lua chon cua ban: ");
}

void main() {
    SinhVien ds[MAX_SIZE];
    int n = 0;
    int dat, khongDat;
    int luaChon;

    do {
        hienThiMenu();
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Nhap so luong sinh vien (n <= 100): ");
            scanf_s("%d", &n);
            if (n <= 0 || n > MAX_SIZE) {
                printf("So luong sinh vien khong hop le.\n");
            }
            else {
                nhapDanhSachSinhVien(ds, n);
            }
            break;
        case 2:
            printf("Danh sach sinh vien:\n");
            xuatDanhSachSinhVien(ds, n);
            break;
        case 3: {
            SinhVien max = sinhVienMax(ds, n);
            printf("Sinh vien co diem tong ket cao nhat:\n");
            xuatDanhSachSinhVien(&max, 1);
            break;
        }
        case 4: {
            SinhVien min = sinhVienMin(ds, n);
            printf("Sinh vien co diem tong ket thap nhat:\n");
            xuatDanhSachSinhVien(&min, 1);
            break;
        }
        case 5:
            demSinhVienDatVaKhongDat(ds, n, &dat, &khongDat);
            printf("So sinh vien dat: %d\n", dat);
            printf("So sinh vien khong dat: %d\n", khongDat);
            break;
        case 6:
            printf("Diem he 4 cua cac sinh vien:\n");
            xuatDiemH4(ds, n);
            break;
        case 7:
            sapXepTangDan(ds, n);
            printf("Danh sach sinh vien sau khi sap xep tang dan:\n");
            xuatDanhSachSinhVien(ds, n);
            break;
        case 8:
            sapXepGiamDan(ds, n);
            printf("Danh sach sinh vien sau khi sap xep giam dan:\n");
            xuatDanhSachSinhVien(ds, n);
            break;
        case 9: {
            float diemTrungBinh = tinhDiemTrungBinh(ds, n);
            printf("Diem trung binh cua cac sinh vien: %.2f\n", diemTrungBinh);
            break;
        }
        case 10:
            ghiDanhSachSinhVienVaoFile(ds, n);
            printf("Danh sach sinh vien da duoc ghi vao file %s\n", FILE_NAME);
            break;
        case 11: {
            int soSinhVienDocTuFile = docDanhSachSinhVienTuFile(ds);
            printf("Danh sach sinh vien doc tu file:\n");
            xuatDanhSachSinhVien(ds, soSinhVienDocTuFile);
            n = soSinhVienDocTuFile;  // Cap nhat lai so luong sinh vien
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (luaChon != 0);
}
