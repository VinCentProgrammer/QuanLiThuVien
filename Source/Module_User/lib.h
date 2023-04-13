// // File khai báo hàm nguyên mẫu - User
#include "execute.c"

// Ham kiem tra
int ktMssv(char *mssv);
int dauNoi(char c);
int ktLopHoc(char lopHoc[]);
int ktNgay(char *ngay);

// // Ham nhap
void nhapMssv(sinhVien *sv);
void nhapHoVaTen(sinhVien *sv);
void nhapLopHoc(sinhVien *sv);
void xoaChuoi(char *chuoi);
void nhapNgayMuon(sinhVien *sv);
int ktSachCoHeThong(Sach sach[], int slDauSach, char *tenSach);
void nhapThongTinSachMuon(sinhVien *sv, Sach sach[], int slDauSach);
sinhVien nhapThongTinSinhVien();

// // Ham hien thi
void lietKeSV(sinhVien sv[], int slsv);
void hienThiSV(sinhVien sv[], int slsv);

// // Sap Xep
void sapXepTheoTenSvGiamDan(sinhVien sv[], int slsv);
void sapXepTheoTenSvTangDan(sinhVien sv[], int slsv);

// // Ham Tim Kiem
void timKiemSvTheoMssv(sinhVien sv[], int slsv);
void timKiemSvTheoTen(sinhVien sv[], int slsv);

// // Ham Xoa
int ktMssvTontai(sinhVien sv[], int slsv, char *mssv);
void xoaSvTheoMssv(sinhVien sv[], int *slsv);

// // Ham ghi file
void ghiSvVaoFile(sinhVien sv[], int slsv);

// // Ham menu
int MenuSv();
