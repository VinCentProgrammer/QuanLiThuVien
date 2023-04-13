// // File xay dung ham - LOGIN

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void xoaXuongDong1(char c[])
{
    if (c[strlen(c) - 1] == '\n')
    {
        c[strlen(c) - 1] = '\0';
    }
}

struct DangNhapAdmin
{
    char tenDangNhap[50];
    char matKhau[10];
} DangNhap;

int ktTenDangNhap(char tenDangNhap[])
{
    if (strlen(tenDangNhap) >= 10)
    {
        for (int i = 0; i < strlen(tenDangNhap); i++)
        {
            if (!isalpha(tenDangNhap[i]) && !isdigit(tenDangNhap[i]) && tenDangNhap[i] != '_')
                return 0;
        }
        return 1;
    }
    return 0;
}

int ktMatKhau(char matKhau[])
{
    if (strlen(matKhau) == 8)
    {
        for (int i = 0; i < strlen(matKhau); i++)
        {
            if (!isdigit(matKhau[i]))
                return 0;
        }
        return 1;
    }
    return 0;
}

void kiemTra()
{
    printf("\n+-------+");
    printf("\n| LOGIN |");
    printf("\n+-------+\n\n");
    do
    {
        printf("TEN DANG NHAP: ");
        fflush(stdin);
        fgets(DangNhap.tenDangNhap, sizeof(DangNhap.tenDangNhap) - 1, stdin);
        xoaXuongDong1(DangNhap.tenDangNhap);
        if (!ktTenDangNhap(DangNhap.tenDangNhap))
        {
            printf("+--------------------------------------------------------------------+");
            printf("\n|   Ten dang nhap chua chu cai, so, dau gach duoi, it nhat 10 ki tu  |");
            printf("\n+--------------------------------------------------------------------+\n");
        }
    } while (!ktTenDangNhap(DangNhap.tenDangNhap));

    do
    {
        printf("\nMAT KHAU: ");
        fflush(stdin);
        fgets(DangNhap.matKhau, sizeof(DangNhap.matKhau) - 1, stdin);
        xoaXuongDong1(DangNhap.matKhau);
        if (!ktMatKhau(DangNhap.matKhau))
        {
            printf("+--------------------------------------------------------------------+");
            printf("\n|                  Mat khau chi chua 8 so !!!                        |");
            printf("\n+--------------------------------------------------------------------+\n");
        }
    } while (!ktMatKhau(DangNhap.matKhau));
}

int dangNhapThanhCong()
{
    kiemTra();
    if (strcmp(DangNhap.tenDangNhap, "quan_li_thu_vien_utc2") == 0 && strcmp(DangNhap.matKhau, "11223344") == 0)
        return 1;
    return 0;
}
