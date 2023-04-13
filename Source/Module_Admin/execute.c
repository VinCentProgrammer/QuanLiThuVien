// File xây dựng function - Admin

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

typedef struct Sach
{
    char maSach[5];
    char tenSach[100];
    char tacGia[100];
    char theLoai[100];
    int slSachHienCo;
} Sach;

Sach danhSachSach[1000];
int slDauSach = 0;

// Ham Xu Li Chuoi
void xoaXuongDong(char c[]);
int chuHoa(char c);
int chuThuong(char c);
int dauCach(char c);
int so(char c);
int ktMaSach(char *maSach);
int ktMaSachTonTai(Sach sach[], int slDauSach, char *maSach);
int ktTenSach(char *tenSach);
int ktTacGia(char *tenTacGia);
int ktTheLoai(char *theLoai);
int ktDanhSachSachTonTai(int slDauSach);
int chonTheLoai(Sach sachTmp);

// Ham Nhap
void nhapMaSach(Sach *sachTmp);
void nhapTenSach(Sach *sachTmp);
void nhapTacGia(Sach *sachTmp);
void nhapTheLoai(Sach *sachTmp);
void nhapSoLuongHienTai(Sach *sachTmp);
Sach nhapThongTinSach();

// Ham Hien Thi
void lietKeSach(Sach sach[], int slDauSach);
void hienThiDanhSachSach(Sach sach[], int slDauSach);

// Sap Xep
void sapXepTheoTenSachGiamDan(Sach sach[], int slDauSach);
void sapXepTheoTenSachTangDan(Sach sach[], int slDauSach);

// Ham Tim Kiem
void timKiemTheoTheLoai(Sach sach[], int slDauSach);
void timKiemTheoMa(Sach sach[], int slDauSach);

// Ham Cap Nhat
void capNhapSachThem(Sach sach[], int slDauSach);
void capNhapSachBot(Sach sach[], int slDauSach);

// Ham Xoa
void xoaSachTheoMa(Sach sach[], int *slDauSach);

// Ham ghi file

int ktTenFile(char *tenFile);
void ghiSachVaoFile(Sach sach[], int slDauSach);
void docSachTuFile(Sach sach[], int slDauSach);

// Ham menu
int MenuSach();

void thoat();

int functionMainAdmin()
{
    while (1)
    {
        int chon = MenuSach();
        switch (chon)
        {
        case 1:
            danhSachSach[++slDauSach] = nhapThongTinSach();
            thoat();
            break;
        case 2:
            hienThiDanhSachSach(danhSachSach, slDauSach);
            thoat();
            break;
        case 3:
            sapXepTheoTenSachTangDan(danhSachSach, slDauSach);
            thoat();
            break;
        case 4:
            sapXepTheoTenSachGiamDan(danhSachSach, slDauSach);
            thoat();
            break;
        case 5:
            timKiemTheoTheLoai(danhSachSach, slDauSach);
            thoat();
            break;
        case 6:
            timKiemTheoMa(danhSachSach, slDauSach);
            thoat();
            break;
        case 7:
            capNhapSachThem(danhSachSach, slDauSach);
            thoat();
            break;
        case 8:
            capNhapSachBot(danhSachSach, slDauSach);
            thoat();
            break;
        case 9:
            xoaSachTheoMa(danhSachSach, &slDauSach);
            thoat();
            break;
        case 10:
            ghiSachVaoFile(danhSachSach, slDauSach);
            thoat();
            break;
        case 11:
            docSachTuFile(danhSachSach, slDauSach);
            thoat();
            break;
        case 12:
            goto dieuHuongRaMainMenu;
        case 0:
            goto dieuHuongRaMainMenuDeThoat;
        default:
            printf("Lua chon khong hop le!!!\n");
        }
    }
dieuHuongRaMainMenu:
    return 1;
dieuHuongRaMainMenuDeThoat:
    return -1;
}

void thoat()
{
    printf("\nNhan Enter de tiep tuc!\n");
    getch();
    system("cls");
}

// Ham Xu Li Chuoi
void xoaXuongDong(char c[])
{
    if (c[strlen(c) - 1] == '\n')
    {
        c[strlen(c) - 1] = '\0';
    }
}

int chuHoa(char c)
{
    return c >= 'A' && c <= 'Z';
}

int chuThuong(char c)
{
    return c >= 'a' && c <= 'z';
}

int dauCach(char c)
{
    return c == ' ';
}

int so(char c)
{
    return c >= '0' && c <= '9';
}

int ktMaSach(char *maSach)
{
    if (isdigit(maSach[0]) && isdigit(maSach[1]) && isdigit(maSach[2]) && chuHoa(maSach[3]))
        return 1;
    return 0;
}

int ktMaSachTonTai(Sach sach[], int slDauSach, char *maSach)
{
    for (int i = 1; i <= slDauSach; i++)
    {
        if (strcmp(maSach, sach[i].maSach) == 0)
            return 0;
    }
    return 1;
}

int ktTenSach(char *tenSach)
{
    if (chuHoa(tenSach[0]))
    {
        for (int i = 0; i <= strlen(tenSach) - 2; i++)
        {
            if (!(chuHoa(tenSach[i]) && chuThuong(tenSach[i + 1])) && !(chuThuong(tenSach[i]) && chuThuong(tenSach[i + 1])) && !(chuThuong(tenSach[i]) && dauCach(tenSach[i + 1])) && !(dauCach(tenSach[i]) && chuHoa(tenSach[i + 1])) && !(dauCach(tenSach[i]) && so(tenSach[i + 1])))
                return 0;
        }
        return 1;
    }
    return 0;
}

int ktTacGia(char *tenTacGia)
{
    if (chuHoa(tenTacGia[0]))
    {
        for (int i = 0; i <= strlen(tenTacGia) - 2; i++)
        {
            if (!(chuHoa(tenTacGia[i]) && chuThuong(tenTacGia[i + 1])) && !(chuThuong(tenTacGia[i]) && chuThuong(tenTacGia[i + 1])) && !(chuThuong(tenTacGia[i]) && dauCach(tenTacGia[i + 1])) && !(dauCach(tenTacGia[i]) && chuHoa(tenTacGia[i + 1])))
                return 0;
        }
        return 1;
    }
    return 0;
}

int ktTheLoai(char *theLoai)
{
    if (strcmp(theLoai, "Giao Trinh") != 0 && strcmp(theLoai, "Phat Trien Ban Than") != 0 && strcmp(theLoai, "Khoa Hoc Vien Tuong") != 0 && strcmp(theLoai, "Khac") != 0)
        return 0;
    return 1;
}

int ktDanhSachSachTonTai(int slDauSach)
{
    if (slDauSach == 0)
        return 0;
    return 1;
}

int chonTheLoai(Sach sachTmp)
{
    int chonTheLoai;
    printf("\n+-------------------------------------------------------------+");
    printf("\n|0. Giao Trinh:: |1. Phat Trien Ban Than |2. Khoa Hoc |3. Khac|");
    printf("\n|                                                             |");
    printf("\n|                    Chon the loai sach                       |");
    printf("\n+-------------------------------------------------------------+\n");
    scanf("%d", &chonTheLoai);
    return chonTheLoai;
}

// Ham Nhap
void nhapMaSach(Sach *sachTmp)
{
    bool flag1, flag2;
    do
    {
        flag1 = true;
        flag2 = true;

        printf("Nhap ma sach: ");
        fflush(stdin);
        fgets(sachTmp->maSach, sizeof(sachTmp->maSach), stdin);
        xoaXuongDong(sachTmp->maSach);

        if (!ktMaSach(sachTmp->maSach))
        {
            flag1 = false;
            printf("\n+----------------------------------------------------------+");
            printf("\n|   Ma sach co 3 so lien tiep va 1 chu in hoa (VD: 000D)   |");
            printf("\n+----------------------------------------------------------+\n\n");
        }
        else if (!ktMaSachTonTai(danhSachSach, slDauSach, sachTmp->maSach))
        {
            flag2 = false;
            printf("\n+----------------------------------------------------------+");
            printf("\n|            Ma sach da ton tai trong he thong!!!          |");
            printf("\n+----------------------------------------------------------+\n\n");
        }
    } while (flag1 == false || flag2 == false);
}

void nhapTenSach(Sach *sachTmp)
{
    do
    {
        printf("Nhap ten sach: ");
        fflush(stdin);
        fgets(sachTmp->tenSach, sizeof(sachTmp->tenSach), stdin);
        xoaXuongDong(sachTmp->tenSach);
        if (!ktTenSach(sachTmp->tenSach))
        {
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|Ten sach co chu cai bat dau moi tu in hoa, co the chua so (VD: Giai Tich 2) |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }
    } while (!ktTenSach(sachTmp->tenSach));
}

void nhapTacGia(Sach *sachTmp)
{
    do
    {
        printf("Nhap tac gia sach: ");
        fflush(stdin);
        fgets(sachTmp->tacGia, sizeof(sachTmp->tacGia), stdin);
        xoaXuongDong(sachTmp->tacGia);
        if (!ktTacGia(sachTmp->tacGia))
        {
            printf("\n+------------------------------------------------------------------+");
            printf("\n|Ten tac gia co chu cai bat dau moi tu in hoa (VD: Luong The Vinh) |");
            printf("\n+------------------------------------------------------------------+\n\n");
        }
    } while (!ktTacGia(sachTmp->tacGia));
}

void nhapTheLoai(Sach *sachTmp)
{
    do
    {
        printf("Nhap the loai sach: ");
        fflush(stdin);
        fgets(sachTmp->theLoai, sizeof(sachTmp->theLoai), stdin);
        xoaXuongDong(sachTmp->theLoai);
        if (!ktTheLoai(sachTmp->theLoai))
        {
            printf("\n+----------------------------------------------------------------------------+");
            printf("\n|The Loai bao gom Giao Trinh, Phat Trien Ban Than, Khoa Hoc Vien Tuong, Khac |");
            printf("\n+----------------------------------------------------------------------------+\n\n");
        }
    } while (!ktTheLoai(sachTmp->theLoai));
}

void nhapSoLuongHienTai(Sach *sachTmp)
{
    printf("Nhap so luong sach hien tai: ");
    scanf("%d", &sachTmp->slSachHienCo);
}

Sach nhapThongTinSach()
{
    Sach sachTmp;

    // Nhap ma sach
    nhapMaSach(&sachTmp);
    // Nhap ten sach
    nhapTenSach(&sachTmp);
    // Nhap tac gia
    nhapTacGia(&sachTmp);
    // Nhap the loai
    nhapTheLoai(&sachTmp);
    // Nhap so luong sach hien tai
    nhapSoLuongHienTai(&sachTmp);
    return sachTmp;
}

// Ham Hien Thi
void lietKeSach(Sach sach[], int slDauSach)
{
    for (int i = 1; i <= slDauSach; i++)
    {
        if (ktMaSach(sach[i].maSach))
        {
            printf("\n   |%-10s|%-40s|%-20s|%-20s|%-10d|", sach[i].maSach, sach[i].tenSach, sach[i].tacGia, sach[i].theLoai, sach[i].slSachHienCo);
        }
    }
}

void hienThiDanhSachSach(Sach sach[], int slDauSach)
{
    if (!ktDanhSachSachTonTai(slDauSach))
    {
        printf("\n+------------------------------------------------------------------+");
        printf("\n|             Hien chua co danh sach sach ton tai!!!               |");
        printf("\n+------------------------------------------------------------------+\n\n");
        return;
    }
    else
    {
        printf("   +--------------------------------------------------------------------------------------------------------+");
        printf("\n   | Ma sach  |                Ten sach                |      Tac gia       |      The loai      |SL hien co|\n");
        printf("   +--------------------------------------------------------------------------------------------------------+");
        lietKeSach(sach, slDauSach);
        printf("\n   +--------------------------------------------------------------------------------------------------------+");
    }
}

// Sap Xep
void sapXepTheoTenSachGiamDan(Sach sach[], int slDauSach)
{
    if (slDauSach != 0)
    {
        printf("\n    +------------------------------------------Truoc sap xep giam dan----------------------------------------+\n");
        hienThiDanhSachSach(danhSachSach, slDauSach);
        for (int i = 1; i <= slDauSach - 1; i++)
        {
            for (int j = i + 1; j <= slDauSach; j++)
            {
                if (strcmp(sach[i].tenSach, sach[j].tenSach) < 0)
                {
                    Sach sachTmp;
                    sachTmp = sach[i];
                    sach[i] = sach[j];
                    sach[j] = sachTmp;
                }
            }
        }
        printf("\n");
        printf("\n    +------------------------------------------Sau sap xep giam dan------------------------------------------+\n");
        hienThiDanhSachSach(danhSachSach, slDauSach);
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

void sapXepTheoTenSachTangDan(Sach sach[], int slDauSach)
{
    if (slDauSach != 0)
    {
        printf("\n    +------------------------------------------Truoc sap xep tang dan----------------------------------------+\n");
        hienThiDanhSachSach(danhSachSach, slDauSach);
        for (int i = 1; i <= slDauSach - 1; i++)
        {
            for (int j = i + 1; j <= slDauSach; j++)
            {
                if (strcmp(sach[i].tenSach, sach[j].tenSach) > 0)
                {
                    Sach sachTmp;
                    sachTmp = sach[i];
                    sach[i] = sach[j];
                    sach[j] = sachTmp;
                }
            }
        }
        printf("\n");
        printf("\n    +------------------------------------------Sau sap xep tang dan----------------------------------------+\n");
        hienThiDanhSachSach(danhSachSach, slDauSach);
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

// Ham Tim Kiem
void timKiemTheoTheLoai(Sach sach[], int slDauSach)
{
    if (slDauSach != 0)
    {
        hienThiDanhSachSach(sach, slDauSach);
        printf("\n");

        // Nhap the loai
        char tenTheLoai[100];
        do
        {
            printf("Nhap the loai sach: ");
            fflush(stdin);
            fgets(tenTheLoai, sizeof(tenTheLoai), stdin);
            xoaXuongDong(tenTheLoai);
            if (!ktTheLoai(tenTheLoai))
            {
                printf("\n+----------------------------------------------------------------------------+");
                printf("\n|The Loai bao gom Giao Trinh, Phat Trien Ban Than, Khoa Hoc Vien Tuong, Khac |");
                printf("\n+----------------------------------------------------------------------------+\n\n");
            }
        } while (!ktTheLoai(tenTheLoai));

        int ok = 0, k = 0;
        Sach dsTmp[slDauSach];

        for (int i = 1; i <= slDauSach; i++)
        {
            if (strcmp(sach[i].theLoai, tenTheLoai) == 0)
            {
                ok = 1;
                dsTmp[++k] = sach[i];
            }
        }

        if (!ok)
            printf("Khong co sach co the loai %s trong he thong !!!\n", tenTheLoai);
        else
        {
            printf("\n");
            hienThiDanhSachSach(dsTmp, k);
        }
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

void timKiemTheoMa(Sach sach[], int slDauSach)
{
    if (slDauSach != 0)
    {
        hienThiDanhSachSach(sach, slDauSach);
        printf("\n");
        // Nhap ma sach
        char strMaSach[10];
        do
        {
            printf("Nhap ma sach: ");
            fflush(stdin);
            fgets(strMaSach, sizeof(strMaSach), stdin);
            xoaXuongDong(strMaSach);

            if (!ktMaSach(strMaSach))
            {
                printf("\n+----------------------------------------------------------+");
                printf("\n|   Ma sach co 3 so lien tiep va 1 chu in hoa (VD: 000D)   |");
                printf("\n+----------------------------------------------------------+\n\n");
            }
        } while (!ktMaSach(strMaSach));

        int ok = 0, k = 0;
        Sach dsTmp[slDauSach];

        for (int i = 1; i <= slDauSach; i++)
        {
            if (strcmp(sach[i].maSach, strMaSach) == 0)
            {
                ok = 1;
                dsTmp[++k] = sach[i];
            }
        }

        if (!ok)
            printf("Khong co sach co ma %s trong he thong !!!\n", strMaSach);
        else
        {
            printf("\n");
            hienThiDanhSachSach(dsTmp, k);
        }
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

// Ham Cap Nhat
void capNhapSachThem(Sach sach[], int slDauSach)
{
    if (slDauSach != 0)
    {
        hienThiDanhSachSach(sach, slDauSach);
        printf("\n");

        int slThem;
        printf("Nhap so luong muon them vao: ");
        scanf("%d", &slThem);

        // Nhap ma sach

        char strMaSach[5];
        int check = 1;
        do
        {
            printf("Nhap ma sach: ");
            fflush(stdin);
            fgets(strMaSach, sizeof(strMaSach), stdin);
            xoaXuongDong(strMaSach);

            if (!ktMaSach(strMaSach))
            {
                check = 0;
                printf("\n+----------------------------------------------------------+");
                printf("\n|   Ma sach co 3 so lien tiep va 1 chu in hoa (VD: 000D)   |");
                printf("\n+----------------------------------------------------------+\n\n");
            }
            else
                check = 1;
        } while (check == 0);

        int ok = 0;
        if (ktMaSachTonTai(sach, slDauSach, strMaSach) == 0)
        {
            for (int i = 1; i <= slDauSach; i++)
            {
                if (strcmp(sach[i].maSach, strMaSach) == 0)
                {
                    ok = 1;
                    sach[i].slSachHienCo += slThem;
                }
            }
        }
        else
            printf("Khong co sach co ma %s trong he thong!!!\n", strMaSach);

        if (ok == 1)
        {
            hienThiDanhSachSach(sach, slDauSach);
            printf("\nDa them so luong sach co ma %s thanh cong !!!\n", strMaSach);
        }
        else
            printf("Them khong thanh cong!!!\n");
    }
    else
        printf("Chua ton tai sach trong he thong!!!\n");
}

void capNhapSachBot(Sach sach[], int slDauSach)
{
    if (slDauSach != 0)
    {
        hienThiDanhSachSach(sach, slDauSach);
        printf("\n");

        int slBot;
        printf("Nhap so luong muon bot: ");
        scanf("%d", &slBot);
        // Nhap ma sach

        char strMaSach[5];

        int check = 1;

        do
        {
            printf("Nhap ma sach: ");
            fflush(stdin);
            fgets(strMaSach, sizeof(strMaSach), stdin);
            xoaXuongDong(strMaSach);

            if (!ktMaSach(strMaSach))
            {
                check = 0;
                printf("\n+----------------------------------------------------------+");
                printf("\n|   Ma sach co 3 so lien tiep va 1 chu in hoa (VD: 000D)   |");
                printf("\n+----------------------------------------------------------+\n\n");
            }
            else
                check = 1;
        } while (check == 0);

        int ok = 0;
        if (ktMaSachTonTai(sach, slDauSach, strMaSach) == 0)
        {
            for (int i = 1; i <= slDauSach; i++)
            {
                if (strcmp(sach[i].maSach, strMaSach) == 0)
                {
                    ok = 1;
                    sach[i].slSachHienCo -= slBot;
                }
            }
        }
        else
            printf("Khong co sach co ma %s trong he thong!!!\n", strMaSach);

        if (ok == 1)
        {
            hienThiDanhSachSach(sach, slDauSach);
            printf("\nDa giam so luong sach co ma %s thanh cong !!!\n", strMaSach);
        }
        else
            printf("Giam khong thanh cong!!!\n");
    }
    else
        printf("Chua ton tai sach trong he thong !!!\n");
}

// Ham Xoa
void xoaSachTheoMa(Sach sach[], int *slDauSach)
{
    if (*slDauSach != 0)
    {
        hienThiDanhSachSach(sach, *slDauSach);
        printf("\n");

        // Nhap ma sach

        char strMaSach[5];

        int check = 1;

        do
        {
            printf("Nhap ma sach: ");
            fflush(stdin);
            fgets(strMaSach, sizeof(strMaSach), stdin);
            xoaXuongDong(strMaSach);

            if (!ktMaSach(strMaSach))
            {
                check = 0;
                printf("\n+----------------------------------------------------------+");
                printf("\n|   Ma sach co 3 so lien tiep va 1 chu in hoa (VD: 000D)   |");
                printf("\n+----------------------------------------------------------+\n\n");
            }
            else
                check = 1;
        } while (check == 0);

        int ok = 0;
        if (!ktMaSachTonTai(sach, *slDauSach, strMaSach))
        {
            for (int i = 1; i <= *slDauSach; i++)
            {
                int index;
                if (strcmp(sach[i].maSach, strMaSach) == 0)
                {
                    ok = 1;
                    index = i;

                    if (index == *slDauSach)
                    {
                        sach[index] = sach[*slDauSach];
                    }
                    else
                    {
                        sach[index] = sach[index + 1];
                    }
                    *slDauSach -= 1;
                    break;
                }
            }
        }
        else
            printf("Khong co sach co ma %s trong he thong!!!\n", strMaSach);

        if (ok == 1)
        {
            hienThiDanhSachSach(sach, *slDauSach);
            printf("\nDa xoa sach co ma %s thanh cong !!!\n", strMaSach);
        }
        else
            printf("Xoa khong thanh cong!!!\n");
    }
    else
        printf("Chua ton tai sach trong he thong !!!\n");
}

// Ham ghi file

int ktTenFile(char *tenFile)
{
    if (strstr(tenFile, ".txt") || strstr(tenFile, ".bin"))
        return 1;
    return 0;
}

void ghiSachVaoFile(Sach sach[], int slDauSach)
{
    if (slDauSach != 0)
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

        fprintf(f, "%d\n", slDauSach);

        for (int i = 1; i <= slDauSach; i++)
        {
            fprintf(f, "\n   |%-10s|%-40s|%-20s|%-20s|%-10d|", sach[i].maSach, sach[i].tenSach, sach[i].tacGia, sach[i].theLoai, sach[i].slSachHienCo);
        }

        fclose(f);
    }
    else
        printf("Chua co sach ton tai trong he thong!!!\n");
}

void docSachTuFile(Sach sach[], int slDauSach)
{
    // Nhap ten File muon doc

    char tenFile[100];
    do
    {
        printf("Nhap ten file muon doc: ");
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
        f = fopen(tenFile, "r");
    }
    else
        f = fopen(tenFile, "rb");

    if (f == NULL)
    {
        printf("Khong co file can doc \n");
        exit(1);
    }

    fscanf(f, "%d\n", &slDauSach);
    for (int i = 1; i <= slDauSach; i++)
    {
        fscanf(f, "\n   |%-10s|%-40s|%-20s|%-20s|%-10d|", &sach[i].maSach, &sach[i].tenSach, &sach[i].tacGia, &sach[i].theLoai, &sach[i].slSachHienCo);
    }

    fclose(f);
}

// Ham menu
int MenuSach()
{
    printf("\n	        CHUONG TRINH QUAN LI THU VIEN - UTC2 - IT K63");
    printf("\n	+----------------------------------------------------------------+");
    printf("\n	|                     Quan li thong tin sach                     |");
    printf("\n	+----------------------------------------------------------------+");
    printf("\n	|1. Nhap thong tin sach          | 6. Tim kiem theo the ma       |");
    printf("\n	|2. Hien thi danh sach hien co   | 7. Cap nhap sach them         |");
    printf("\n	|3. Sap xep ten sach tang dan    | 8. Cap nhat sach bot          |");
    printf("\n	|4. Sap xep ten sach giam dan    | 9. Xoa sach                   |");
    printf("\n	|5. Tim kiem theo the loai       |10. Ghi vao File |11. Doc File |");
    printf("\n	+----------------------------------------------------------------+");
    printf("\n	|   12. Quay lai Menu chinh      |  0. Thoat chuong trinh        |");
    printf("\n	+----------------------------------------------------------------+");

    int chon;
    printf("\nNhap lua chon: ");
    scanf("%d", &chon);
    return chon;
}