// File xây dựng hàm - User
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "../Module_Admin/execute.c"

typedef struct Ngay
{
    char ngay[3];
    char thang[3];
    char nam[5];
} Ngay;

typedef struct ThongTinSach
{
    char tenSach[100];
} ThongTinSach;

typedef struct TrangThaiDoc
{
    Ngay ngayMuon;
    Ngay ngayTra;
    ThongTinSach thongTinSach[3];
    int slSachMuon;
} trangThai;

typedef struct SinhVien
{
    char mssv[11];    // 6351071011
    char hoVaTen[50]; // Ha Van Dung
    char lopHoc[100]; // CNTT-K63
    trangThai trangThaiDoc;
} sinhVien;

sinhVien danhSachSinhVien[1000];
int slsv = 0;

// Ham kiem tra
int ktMssv(char *mssv)
{
    if (strlen(mssv) != 10)
        return 0;
    for (int i = 0; i < strlen(mssv); i++)
    {
        if (!so(mssv[i]))
            return 0;
    }
    return 1;
}

int dauNoi(char c)
{
    return c == '-';
}

int ktLopHoc(char lopHoc[])
{
    // CNTT-K63
    if (!chuHoa(lopHoc[0]))
        return 0;
    for (int i = 0; i <= strlen(lopHoc) - 2; i++)
    {
        if (!(chuHoa(lopHoc[i]) && chuHoa(lopHoc[i + 1])) && !(chuHoa(lopHoc[i]) && so(lopHoc[i + 1])) && !(so(lopHoc[i]) && so(lopHoc[i + 1])) && !(chuHoa(lopHoc[i]) && dauNoi(lopHoc[i + 1])) && !(dauNoi(lopHoc[i]) && chuHoa(lopHoc[i + 1])))
            return 0;
    }
    return 1;
}

int ktNgay(char *ngay)
{
    // 21/12/2004
    if (strlen(ngay) != 10)
        return 0;
    for (int i = 0; i <= strlen(ngay) - 2; i++)
    {
        if (!(so(ngay[i]) && so(ngay[i + 1])) && !(so(ngay[i]) && ngay[i + 1] == '/') && !(so(ngay[i + 1]) && ngay[i] == '/'))
            return 0;
    }
    return 1;
}

// // Ham nhap
void nhapMssv(sinhVien *sv)
{
    do
    {
        printf("Nhap ma so sinh vien: ");
        fflush(stdin);
        fgets(sv->mssv, sizeof(sv->mssv), stdin);
        xoaXuongDong(sv->mssv);
        if (!ktMssv(sv->mssv))
        {
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|               Ma so sinh vien phai co 10 chu so (VD: 6351071011)           |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }
    } while (!ktMssv(sv->mssv));
}
void nhapHoVaTen(sinhVien *sv)
{
    do
    {
        printf("Nhap ho ten sinh vien: ");
        fflush(stdin);
        fgets(sv->hoVaTen, sizeof(sv->hoVaTen), stdin);
        xoaXuongDong(sv->hoVaTen);
        if (!ktTacGia(sv->hoVaTen))
        {
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|       Ten sinh vien co chu cai bat dau moi tu in hoa (VD: Luong The Vinh)  |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }
    } while (!ktTacGia(sv->hoVaTen));
}
void nhapLopHoc(sinhVien *sv)
{
    do
    {
        printf("Nhap lop hoc sinh vien: ");
        fflush(stdin);
        fgets(sv->lopHoc, sizeof(sv->lopHoc), stdin);
        xoaXuongDong(sv->lopHoc);
        if (!ktLopHoc(sv->lopHoc))
        {
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|                Lop hoc co dinh dang (VD: CNTT-K63 hoac KINHTE-K63)         |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }
    } while (!ktLopHoc(sv->lopHoc));
}

void xoaChuoi(char *chuoi)
{
    for (int i = 0; i < strlen(chuoi); i++)
    {
        chuoi[i] = '\0';
    }
    xoaXuongDong(chuoi);
}

void nhapNgayMuon(sinhVien *sv)
{
    char strNgay[3];
    char strThang[3];
    char strNam[5];
    char strNgayMuon[20];

    int ok = 1;
    do
    {
        ok = 1;

        printf("Nhap ngay - thang - nam muon sach: \n");

        printf("Ngay: ");
        fflush(stdin);
        fgets(sv->trangThaiDoc.ngayMuon.ngay, sizeof(sv->trangThaiDoc.ngayMuon.ngay), stdin);
        xoaXuongDong(sv->trangThaiDoc.ngayMuon.ngay);

        printf("Thang: ");
        fflush(stdin);
        fgets(sv->trangThaiDoc.ngayMuon.thang, sizeof(sv->trangThaiDoc.ngayMuon.thang), stdin);
        xoaXuongDong(sv->trangThaiDoc.ngayMuon.thang);

        printf("Nam: ");
        fflush(stdin);
        fgets(sv->trangThaiDoc.ngayMuon.nam, sizeof(sv->trangThaiDoc.ngayMuon.nam), stdin);
        xoaXuongDong(sv->trangThaiDoc.ngayMuon.nam);

        strcpy(strNgay, sv->trangThaiDoc.ngayMuon.ngay);
        strcpy(strThang, sv->trangThaiDoc.ngayMuon.thang);
        strcpy(strNam, sv->trangThaiDoc.ngayMuon.nam);

        strcat(strNgayMuon, strNgay);
        strcat(strNgayMuon, "/");
        strcat(strNgayMuon, strThang);
        strcat(strNgayMuon, "/");
        strcat(strNgayMuon, strNam);

        if (!ktNgay(strNgayMuon))
        {
            ok = 0;
            xoaChuoi(strNgayMuon);
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|                          Ngay co dinh dang (VD: 21/02/2023)                |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }
    } while (ok == 0);
}

int ktSachCoHeThong(Sach sach[], int slDauSach, char *tenSach)
{
    for (int i = 1; i <= slDauSach; i++)
    {
        if (strcmp(tenSach, sach[i].tenSach) == 0)
        {
            return 1;
            break;
        }
    }
    return 0;
}

void nhapThongTinSachMuon(sinhVien *sv, Sach sach[], int slDauSach)
{
    hienThiDanhSachSach(danhSachSach, slDauSach);
    printf("\n");

    do
    {
        printf("Nhap so luong sach muon (Toi da 3 cuon): ");
        scanf("%d", &sv->trangThaiDoc.slSachMuon);
    } while (sv->trangThaiDoc.slSachMuon <= 0 || sv->trangThaiDoc.slSachMuon > 3);

    int i = 1;
    while (i <= sv->trangThaiDoc.slSachMuon)
    {
        char tenSach[100];
        do
        {
            printf("Nhap ten sach muon muon: ");
            fflush(stdin);
            fgets(tenSach, sizeof(tenSach), stdin);
            xoaXuongDong(tenSach);

            if (!ktTenSach(tenSach))
            {
                printf("\n+----------------------------------------------------------------------------+");
                printf("\n|Ten sach co chu cai bat dau moi tu in hoa, co the chua so (VD: Giai Tich 2) |");
                printf("\n+----------------------------------------------------------------------------+\n\n");
            }
        } while (!ktTenSach(tenSach));

        int check = 0;
        for (int j = 0; j < slDauSach; j++)
        {
            if (strcmp(sach[j].tenSach, tenSach) == 0)
            {
                check = 1;
                strcpy(sv->trangThaiDoc.thongTinSach[i].tenSach, tenSach);
                sach[j].slSachHienCo -= 1;
                break;
            }
        }

        if (check == 0)
        {
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|                   Sach nay khong co trong thu vien!!!                      |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }
        else
        {
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|                         Muon sach thanh cong !!!                           |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }

        i++;
    }
}

sinhVien nhapThongTinSinhVien()
{
    sinhVien svTmp;
    // Nhap ma so sinh vien
    nhapMssv(&svTmp);
    // Nhap ho va ten
    nhapHoVaTen(&svTmp);
    // Nhap lop hoc
    nhapLopHoc(&svTmp);
    // Nhap ngay thang nam muon sach
    nhapNgayMuon(&svTmp);
    // Nhap ten sach muon muon
    nhapThongTinSachMuon(&svTmp, danhSachSach, slDauSach);
    return svTmp;
}

// // Ham hien thi
void lietKeSV(sinhVien sv[], int slsv)
{
    for (int i = 1; i <= slsv; i++)
    {
        if (ktMssv(sv[i].mssv))
        {
            char tenSachMuon[3][50];

            for (int k = 1; k <= sv[i].trangThaiDoc.slSachMuon; k++)
            {
                strcpy(tenSachMuon[i], sv[i].trangThaiDoc.thongTinSach[k].tenSach);
            }

            printf("\n   |%-10s|%-40s|%-20s|%-5s/%-5s/%-5s|%-10s, %-10s, %-10s|", sv[i].mssv, sv[i].hoVaTen, sv[i].lopHoc, sv[i].trangThaiDoc.ngayMuon.ngay, sv[i].trangThaiDoc.ngayMuon.thang, sv[i].trangThaiDoc.ngayMuon.nam, (sv[i].trangThaiDoc.thongTinSach[1].tenSach != NULL) ? sv[i].trangThaiDoc.thongTinSach[1].tenSach : "0", (sv[i].trangThaiDoc.thongTinSach[2].tenSach != NULL) ? sv[i].trangThaiDoc.thongTinSach[2].tenSach : "0", (sv[i].trangThaiDoc.thongTinSach[3].tenSach != NULL) ? sv[i].trangThaiDoc.thongTinSach[3].tenSach : "0");
        }
    }
}

void hienThiSV(sinhVien sv[], int slsv)
{
    if (slsv != 0)
    {
        printf("   +--------------------------------------------------------------------------------------------------------+");
        printf("\n   | Mssv |     Ho Va Ten         |    Lop Hoc    |   Ngay muon sach    |             Sach muon             |\n");
        printf("   +--------------------------------------------------------------------------------------------------------+");
        lietKeSV(sv, slsv);
        printf("\n   +--------------------------------------------------------------------------------------------------------+");
    }
    else
        printf("Chua co sinh vien muon sach!!!\n");
}

// // Sap Xep
void sapXepTheoTenSvGiamDan(sinhVien sv[], int slsv)
{
    if (slsv != 0)
    {
        printf("\n +------------------------------------------Truoc sap xep giam dan----------------------------------------+\n");
        hienThiSV(danhSachSinhVien, slsv);
        for (int i = 1; i <= slsv - 1; i++)
        {
            for (int j = i + 1; j <= slsv; j++)
            {
                if (strcmp(sv[i].hoVaTen, sv[j].hoVaTen) < 0)
                {
                    sinhVien sinhVienTmp;
                    sinhVienTmp = sv[i];
                    sv[i] = sv[j];
                    sv[j] = sinhVienTmp;
                }
            }
        }
        printf("\n");
        printf("\n +------------------------------------------Sau sap xep giam dan------------------------------------------+\n");
        hienThiSV(danhSachSinhVien, slsv);
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

void sapXepTheoTenSvTangDan(sinhVien sv[], int slsv)
{
    if (slsv != 0)
    {
        printf("\n +------------------------------------------Truoc sap xep tang dan----------------------------------------+\n");
        hienThiSV(danhSachSinhVien, slsv);
        for (int i = 1; i <= slsv - 1; i++)
        {
            for (int j = i + 1; j <= slsv; j++)
            {
                if (strcmp(sv[i].hoVaTen, sv[j].hoVaTen) > 0)
                {
                    sinhVien sinhVienTmp;
                    sinhVienTmp = sv[i];
                    sv[i] = sv[j];
                    sv[j] = sinhVienTmp;
                }
            }
        }
        printf("\n");
        printf("\n +------------------------------------------Sau sap xep tang dan------------------------------------------+\n");
        hienThiSV(danhSachSinhVien, slsv);
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

// // Ham Tim Kiem
void timKiemSvTheoMssv(sinhVien sv[], int slsv)
{
    if (slsv != 0)
    {
        hienThiSV(danhSachSinhVien, slsv);

        // Nhap ma so sinh vien
        char mssv[20];
        do
        {
            printf("Nhap ma so sinh vien: ");
            fflush(stdin);
            fgets(mssv, sizeof(mssv), stdin);
            xoaXuongDong(mssv);
            if (!ktMssv(mssv))
            {
                printf("\n+----------------------------------------------------------------------------+");
                printf("\n|               Ma so sinh vien phai co 10 chu so (VD: 6351071011)           |");
                printf("\n+----------------------------------------------------------------------------+\n\n");
            }
        } while (!ktMssv(mssv));

        int ok = 0, k = 0;
        sinhVien dsTmp[slsv];

        for (int i = 1; i <= slsv; i++)
        {
            if (strcmp(sv[i].mssv, mssv) == 0)
            {
                ok = 1;
                dsTmp[++k] = sv[i];
            }
        }

        if (!ok)
            printf("Khong co sinh vien co ma %s trong he thong !!!\n", mssv);
        else
        {
            printf("\n");
            hienThiSV(dsTmp, k);
        }
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}
void timKiemSvTheoTen(sinhVien sv[], int slsv)
{
    if (slsv != 0)
    {
        hienThiSV(danhSachSinhVien, slsv);

        // Nhap ten sinh vien
        char tenSinhVien[50];
        do
        {
            printf("Nhap ho ten sinh vien: ");
            fflush(stdin);
            fgets(tenSinhVien, sizeof(tenSinhVien), stdin);
            xoaXuongDong(tenSinhVien);
            if (!ktTacGia(tenSinhVien))
            {
                printf("\n+----------------------------------------------------------------------------+");
                printf("\n|       Ten sinh vien co chu cai bat dau moi tu in hoa (VD: Luong The Vinh)  |");
                printf("\n+----------------------------------------------------------------------------+\n\n");
            }
        } while (!ktTacGia(tenSinhVien));

        int ok = 0, k = 0;
        sinhVien dsTmp[slsv];

        for (int i = 1; i <= slsv; i++)
        {
            if (strcmp(sv[i].hoVaTen, tenSinhVien) == 0)
            {
                ok = 1;
                dsTmp[++k] = sv[i];
            }
        }

        if (!ok)
            printf("Khong co sinh vien co ten %s trong he thong !!!\n", tenSinhVien);
        else
        {
            printf("\n");
            hienThiSV(dsTmp, k);
        }
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

// // Ham Xoa

int ktMssvTontai(sinhVien sv[], int slsv, char *mssv)
{
    for (int i = 1; i <= slsv; i++)
    {
        if (strcmp(mssv, sv[i].mssv) == 0)
            return 0;
    }
    return 1;
}

void xoaSvTheoMssv(sinhVien sv[], int *slsv)
{
    if (*slsv != 0)
    {
        hienThiSV(danhSachSinhVien, *slsv);
        printf("\n");

        // Nhap mssv

        char mssv[20];

        int check = 1;

        do
        {
            printf("Nhap ma so sinh vien: ");
            fflush(stdin);
            fgets(mssv, sizeof(mssv), stdin);
            xoaXuongDong(mssv);

            if (!ktMssv(mssv))
            {
                check = 0;
                printf("\n+----------------------------------------------------------------------------+");
                printf("\n|               Ma so sinh vien phai co 10 chu so (VD: 6351071011)           |");
                printf("\n+----------------------------------------------------------------------------+\n\n");
            }
            else
                check = 1;
        } while (check == 0);

        int ok = 0;
        if (ktMssvTontai(sv, *slsv, mssv) == 0)
        {
            for (int i = 1; i <= *slsv; i++)
            {
                int index;
                if (strcmp(sv[i].mssv, mssv) == 0)
                {
                    ok = 1;
                    index = i;

                    if (index == *slsv)
                    {
                        sv[index] = sv[*slsv];
                    }
                    else
                    {
                        sv[index] = sv[index + 1];
                    }
                    *slsv -= 1;
                    break;
                }
            }
        }
        else
            printf("Khong co sinh vien co ma %s trong he thong!!!\n", mssv);

        if (ok == 1)
        {
            hienThiSV(danhSachSinhVien, *slsv);
            printf("\nDa xoa sinh vien co ma %s thanh cong !!!\n", mssv);
        }
        else
            printf("Xoa khong thanh cong!!!\n");
    }
    else
        printf("Chua ton tai sinh vien trong he thong !!!\n");
}

// // Ham ghi file

void ghiSvVaoFile(sinhVien sv[], int slsv)
{
    if (slsv != 0)
    {
        // Nhap ten File

        char tenFile[100];
        do
        {
            printf("Nhap ten file: ");
            fflush(stdin);
            fgets(tenFile, sizeof(tenFile), stdin);
            xoaXuongDong(tenFile);

            if (!ktTenFile(tenFile))
            {
                printf("\n+----------------------------------------------------------+");
                printf("\n|   Ten File co dinh dang tenFile.txt hoac tenFile.bin     |");
                printf("\n+----------------------------------------------------------+\n\n");
            }
        } while (!ktTenFile(tenFile));

        FILE *f;

        if (strstr(tenFile, ".txt"))
        {
            f = fopen(tenFile, "w");
        }
        else
            f = fopen(tenFile, "wb");

        if (f == NULL)
        {
            printf("Loi mo hoac tao file \n");
            exit(1);
        }
        for (int i = 1; i <= slsv; i++)
        {
            char tenSachMuon[3][50];

            for (int k = 1; k <= sv[i].trangThaiDoc.slSachMuon; k++)
            {
                strcpy(tenSachMuon[i], sv[i].trangThaiDoc.thongTinSach[k].tenSach);
            }

            fprintf(f, "\n   |%-10s|%-40s|%-20s|%-5s/%-5s/%-5s|%-10s, %-10s, %-10s|", sv[i].mssv, sv[i].hoVaTen, sv[i].lopHoc, sv[i].trangThaiDoc.ngayMuon.ngay, sv[i].trangThaiDoc.ngayMuon.thang, sv[i].trangThaiDoc.ngayMuon.nam, (sv[i].trangThaiDoc.thongTinSach[1].tenSach != NULL) ? sv[i].trangThaiDoc.thongTinSach[1].tenSach : "0", (sv[i].trangThaiDoc.thongTinSach[2].tenSach != NULL) ? sv[i].trangThaiDoc.thongTinSach[2].tenSach : "0", (sv[i].trangThaiDoc.thongTinSach[3].tenSach != NULL) ? sv[i].trangThaiDoc.thongTinSach[3].tenSach : "0");
        }

        fclose(f);
    }
    else
        printf("Chua co sinh vien ton tai trong he thong!!!\n");
}

// // Ham menu
int MenuSv()
{
    printf("\n	        CHUONG TRINH QUAN LI THU VIEN - UTC2 - IT K63");
    printf("\n	+----------------------------------------------------------------+");
    printf("\n	|                   Quan li sinh vien muon sach                  |");
    printf("\n	+----------------------------------------------------------------+");
    printf("\n	|1. Nhap thong tin sinh vien     | 6. Tim kiem theo the ten SV   |");
    printf("\n	|2. Hien thi sinh vien hien co   | 7. Xoa sinh vien              |");
    printf("\n	|3. Sap xep ten sinh vien giam   | 8. Ghi sinh vien vao file     |");
    printf("\n	|4. Sap xep ten sinh vien tang   |                               |");
    printf("\n	|5. Tim kiem theo the mssv       |                               |");
    printf("\n	+----------------------------------------------------------------+");
    printf("\n	|   9. Quay lai Menu chinh       |  0. Thoat chuong trinh        |");
    printf("\n	+----------------------------------------------------------------+");

    int chon;
    printf("\nNhap lua chon: ");
    scanf("%d", &chon);
    return chon;
}
