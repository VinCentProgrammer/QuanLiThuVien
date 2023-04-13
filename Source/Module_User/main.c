// File xử lí chính - User
#include <stdio.h>
#include <conio.h>
#include "lib.h"

// functionMainUser() ~ main()
int functionMainUser()
{
    while (1)
    {
        int chon = MenuSv();
        switch (chon)
        {
        case 1:
            danhSachSinhVien[++slsv] = nhapThongTinSinhVien();
            thoat();
            break;
        case 2:
            hienThiSV(danhSachSinhVien, slsv);
            thoat();
            break;
        case 3:
            sapXepTheoTenSvGiamDan(danhSachSinhVien, slsv);
            thoat();
            break;
        case 4:
            sapXepTheoTenSvTangDan(danhSachSinhVien, slsv);
            thoat();
            break;
        case 5:
            timKiemSvTheoMssv(danhSachSinhVien, slsv);
            thoat();
            break;
        case 6:
            timKiemSvTheoTen(danhSachSinhVien, slsv);
            thoat();
            break;
        case 7:
            xoaSvTheoMssv(danhSachSinhVien, &slsv);
            thoat();
            break;
        case 8:
            ghiSvVaoFile(danhSachSinhVien, slsv);
            thoat();
            break;
        case 9:
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
