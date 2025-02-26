﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory>

#define MAX_SIZE 100
#define MA_MON_MAX 10
#define TEN_MON_MAX 50
#define MA_SV_MAX 15
#define HO_TEN_MAX 100

// Cấu trúc môn học
typedef struct {
    char maMon[MA_MON_MAX];
    char tenMon[TEN_MON_MAX];
    int soTinChi;
    float diem;
} MonHoc;

// Cấu trúc sinh viên
typedef struct {
    char maSV[MA_SV_MAX];
    char hoTen[HO_TEN_MAX];
    MonHoc diemMon[5];
    float diemTBC;
} SinhVien;

// Hàm nhập thông tin môn học
void nhapMonHoc(MonHoc* mon) {
    printf("Nhap ma mon: ");
    scanf_s("%s", mon->maMon, (unsigned)_countof(mon->maMon));
    printf("Nhap ten mon: ");
    getchar(); // Đọc ký tự newline còn lại
    fgets(mon->tenMon, sizeof(mon->tenMon), stdin);
    mon->tenMon[strcspn(mon->tenMon, "\n")] = '\0';
    printf("Nhap so tin chi: ");
    scanf_s("%d", &mon->soTinChi);
    printf("Nhap diem: ");
    scanf_s("%f", &mon->diem);
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma so sinh vien: ");
        scanf_s("%s", ds[i].maSV, (unsigned)_countof(ds[i].maSV));
        printf("Ho ten sinh vien: ");
        getchar(); // Đọc ký tự newline còn lại
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = '\0';

        printf("Nhap thong tin diem mon lap trinh:\n");
        nhapMonHoc(&ds[i].diemMon[0]);

        printf("Nhap thong tin diem mon toan A1:\n");
        nhapMonHoc(&ds[i].diemMon[1]);

        printf("Nhap thong tin diem mon toan A2:\n");
        nhapMonHoc(&ds[i].diemMon[2]);

        printf("Nhap thong tin diem mon vat ly ky thuat:\n");
        nhapMonHoc(&ds[i].diemMon[3]);

        printf("Nhap thong tin diem mon anh van:\n");
        nhapMonHoc(&ds[i].diemMon[4]);

        // Tính điểm trung bình tích lũy
        ds[i].diemTBC = 0;
        for (int j = 0; j < 5; j++) {
            ds[i].diemTBC += ds[i].diemMon[j].diem * ds[i].diemMon[j].soTinChi;
        }
        int tongTinChi = 0;
        for (int j = 0; j < 5; j++) {
            tongTinChi += ds[i].diemMon[j].soTinChi;
        }
        ds[i].diemTBC /= tongTinChi;
    }
}

// Hàm xuất thông tin môn học
void xuatMonHoc(MonHoc mon) {
    printf("Ma mon: %s - Ten mon: %s - So tin chi: %d - Diem: %.2f\n",
        mon.maMon, mon.tenMon, mon.soTinChi, mon.diem);
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ma SV: %s - Ho ten: %s - Diem TBC: %.2f\n", ds[i].maSV, ds[i].hoTen, ds[i].diemTBC);
        for (int j = 0; j < 5; j++) {
            xuatMonHoc(ds[i].diemMon[j]);
        }
    }
}

// Hàm tìm sinh viên theo mã số
int timSinhVienTheoMa(SinhVien ds[], int n, char* maSV) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSV, maSV) == 0) {
            return i;
        }
    }
    return -1; // Không tìm thấy
}

// Hàm tìm sinh viên có điểm trung bình cao nhất
SinhVien sinhVienMaxTBC(SinhVien ds[], int n) {
    SinhVien max = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTBC > max.diemTBC) {
            max = ds[i];
        }
    }
    return max;
}

// Hàm thêm sinh viên vào danh sách
void themSinhVien(SinhVien ds[], int* n, SinhVien sv) {
    ds[*n] = sv;
    (*n)++;
}

// Hàm xóa sinh viên khỏi danh sách theo chỉ số
void xoaSinhVien(SinhVien ds[], int* n, int index) {
    for (int i = index; i < (*n) - 1; i++) {
        ds[i] = ds[i + 1];
    }
    (*n)--;
}

// Hàm sắp xếp danh sách sinh viên theo điểm trung bình tăng dần
void sapXepTangDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].diemTBC > ds[j + 1].diemTBC) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm trung bình giảm dần
void sapXepGiamDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].diemTBC < ds[j + 1].diemTBC) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// Hàm xếp loại học tập
void xepLoaiHocTap(float diemTBC) {
    if (diemTBC >= 8.5) {
        printf("Xep loai: Xuat sac\n");
    }
    else if (diemTBC >= 7.0) {
        printf("Xep loai: Gioi\n");
    }
    else if (diemTBC >= 5.5) {
        printf("Xep loai: Kha\n");
    }
    else if (diemTBC >= 4.0) {
        printf("Xep loai: Trung binh\n");
    }
    else {
        printf("Xep loai: Yeu\n");
    }
}

// Hàm thống kê số môn đậu và rớt của sinh viên
void thongKeMon(SinhVien sv) {
    int monDat = 0;
    int monRot = 0;
    for (int i = 0; i < 5; i++) {
        if (sv.diemMon[i].diem >= 5.0) {
            monDat++;
        }
        else {
            monRot++;
        }
    }
    printf("Sinh vien %s co %d mon dat va %d mon rot.\n", sv.hoTen, monDat, monRot);
}

#define FILE_NAME "sinhvien.txt"

// Hàm ghi danh sách sinh viên vào file
void ghiDanhSachSinhVienVaoFile(SinhVien ds[], int n) {
    FILE* file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Loi mo file.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\n%s\n", ds[i].maSV, ds[i].hoTen);
        for (int j = 0; j < 5; j++) {
            fprintf(file, "%s\n%s\n%d\n%.2f\n",
                ds[i].diemMon[j].maMon, ds[i].diemMon[j].tenMon,
                ds[i].diemMon[j].soTinChi, ds[i].diemMon[j].diem);
        }
        fprintf(file, "%.2f\n", ds[i].diemTBC);
    }
    fclose(file);
}

// Hàm đọc danh sách sinh viên từ file
int docDanhSachSinhVienTuFile(SinhVien ds[]) {
    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Loi mo file.\n");
        return 0;
    }
    int n = 0;
    while (fgets(ds[n].maSV, MA_SV_MAX, file) != NULL) {
        ds[n].maSV[strcspn(ds[n].maSV, "\n")] = '\0'; // Loại bỏ ký tự newline
        fgets(ds[n].hoTen, HO_TEN_MAX, file);
        ds[n].hoTen[strcspn(ds[n].hoTen, "\n")] = '\0'; // Loại bỏ ký tự newline
        for (int j = 0; j < 5; j++) {
            fgets(ds[n].diemMon[j].maMon, MA_MON_MAX, file);
            ds[n].diemMon[j].maMon[strcspn(ds[n].diemMon[j].maMon, "\n")] = '\0'; // Loại bỏ ký tự newline
            fgets(ds[n].diemMon[j].tenMon, TEN_MON_MAX, file);
            ds[n].diemMon[j].tenMon[strcspn(ds[n].diemMon[j].tenMon, "\n")] = '\0'; // Loại bỏ ký tự newline
            fscanf(file, "%d", &ds[n].diemMon[j].soTinChi);
            fscanf(file, "%f", &ds[n].diemMon[j].diem);
            fgetc(file); // Đọc ký tự newline còn lại
        }
        fscanf(file, "%f", &ds[n].diemTBC);
        fgetc(file); // Đọc ký tự newline còn lại
        n++;
    }
    fclose(file);
    return n;
}

// Hàm hiển thị menu và xử lý lựa chọn
void hienThiMenu() {
    printf("----- Menu -----\n");
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Tim sinh vien theo ma so\n");
    printf("4. Tim sinh vien co diem trung binh cao nhat\n");
    printf("5. Them sinh vien\n");
    printf("6. Xoa sinh vien\n");
    printf("7. Sap xep danh sach sinh vien tang dan theo diem TBC\n");
    printf("8. Sap xep danh sach sinh vien giam dan theo diem TBC\n");
    printf("9. Xep loai hoc tap\n");
    printf("10. Thong ke so mon dau va rot cua sinh vien\n");
    printf("11. Ghi danh sach sinh vien vao file\n");
    printf("12. Doc danh sach sinh vien tu file\n");
    printf("0. Thoat\n");
    printf("----------------\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    SinhVien ds[MAX_SIZE];
    int n = 0;
    int luaChon;

    do {
        hienThiMenu();
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Nhap so luong sinh vien: ");
            scanf_s("%d", &n);
            nhapDanhSachSinhVien(ds, n);
            break;
        case 2:
            printf("Danh sach sinh vien:\n");
            xuatDanhSachSinhVien(ds, n);
            break;
        case 3: {
            char maSV[MA_SV_MAX];
            printf("Nhap ma sinh vien can tim: ");
            scanf_s("%s", maSV, (unsigned)_countof(maSV));
            int index = timSinhVienTheoMa(ds, n, maSV);
            if (index != -1) {
                printf("Thong tin sinh vien:\n");
                xuatDanhSachSinhVien(&ds[index], 1);
            }
            else {
                printf("Sinh vien voi ma %s khong ton tai.\n", maSV);
            }
            break;
        }
        case 4: {
            SinhVien maxTBC = sinhVienMaxTBC(ds, n);
            printf("Sinh vien co diem trung binh cao nhat:\n");
            xuatDanhSachSinhVien(&maxTBC, 1);
            break;
        }
        case 5: {
            SinhVien svMoi;
            printf("Nhap thong tin sinh vien moi:\n");
            nhapDanhSachSinhVien(&svMoi, 1);
            themSinhVien(ds, &n, svMoi);
            break;
        }
        case 6: {
            int xoaIndex;
            printf("Nhap chi so sinh vien can xoa: ");
            scanf_s("%d", &xoaIndex);
            if (xoaIndex >= 0 && xoaIndex < n) {
                xoaSinhVien(ds, &n, xoaIndex);
            }
            else {
                printf("Chi so sinh vien khong hop le.\n");
            }
            break;
        }
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
            float diemTBC;
            printf("Nhap diem trung binh cua sinh vien de xep loai: ");
            scanf_s("%f", &diemTBC);
            xepLoaiHocTap(diemTBC);
            break;
        }
        case 10: {
            char maSV[MA_SV_MAX];
            printf("Nhap ma sinh vien de thong ke so mon: ");
            scanf_s("%s", maSV, (unsigned)_countof(maSV));
            int index = timSinhVienTheoMa(ds, n, maSV);
            if (index != -1) {
                thongKeMon(ds[index]);
            }
            else {
                printf("Sinh vien voi ma %s khong ton tai.\n", maSV);
            }
            break;
        }
        case 11:
            ghiDanhSachSinhVienVaoFile(ds, n);
            printf("Danh sach sinh vien da duoc ghi vao file.\n");
            break;
        case 12: {
            int soSinhVienDocTuFile = docDanhSachSinhVienTuFile(ds);
            printf("Danh sach sinh vien doc tu file:\n");
            xuatDanhSachSinhVien(ds, soSinhVienDocTuFile);
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

    return 0;
}
