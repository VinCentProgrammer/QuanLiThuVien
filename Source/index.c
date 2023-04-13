#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "Login/loginExecute.c"
#include "Module_User/main.c"

int mainMenu();

int main()
{
    bool kiemTraThoiGian = true;
    int ok = 1;

    do
    {
        for (int i = 3; i >= 1; i--)
        {
            printf("\n# CON LAI %d LAN\n", i);
            if (dangNhapThanhCong())
            {
                printf("\n+----------------------------------------------------------+");
                printf("\n|              DANG NHAP THANH CONG (X_X)                  |");
                printf("\n+----------------------------------------------------------+\n\n");
                kiemTraThoiGian = false;
                thoat();
                break;
            }
            else
            {
                ok = 0;
                printf("\n+----------------------------------------------------------+");
                printf("\n|              DANG NHAP KHONG THANH CONG (u_u)            |");
                printf("\n+----------------------------------------------------------+\n\n");
                thoat();
            }
        }

        if (ok == 0)
        {
            kiemTraThoiGian = false;

            printf("\nVUI LONG DANG NHAP LAI SAU 30' (-.-)\n");
            time_t start_time, current_time;
            double elapsed_time;
            time(&start_time);
            printf("\nBAT DAU DEM THOI GIAN KE TU BAY GIO, VUI LONG DOI......\n");
            do
            {
                time(&current_time);
                elapsed_time = difftime(current_time, start_time);
            } while (elapsed_time < 30 * 60);
            kiemTraThoiGian = true;
        }
    } while (kiemTraThoiGian == true);

    if (ok)
    {
        int choice;
    mainMenu:
        choice = mainMenu();
        if (choice == 0)
        {
            goto Exit;
        }
        else if (choice == 1)
        {

            while (1)
            {
                int chonModuleAdmin = functionMainAdmin();
                switch (chonModuleAdmin)
                {
                case 1:
                    goto mainMenu;
                    break;
                case -1:
                    goto Exit;
                default:
                    functionMainAdmin();
                }
            }
        }
        else if (choice == 2)
        {
            while (1)
            {
                int chonModuleUser = functionMainUser();
                switch (chonModuleUser)
                {
                case 1:
                    goto mainMenu;
                    break;
                case -1:
                    goto Exit;
                default:
                    functionMainUser();
                }
            }
        }
        else
        {
            printf("Lua chon khong hop le!!!\n");
            return 0;
        }
    Exit:
        return 0;
    }
}

int mainMenu()
{
    int luaChon;
    printf("\n+--------UCT2----------- MENU CHINH ----------IT_K63-------+");
    printf("\n|                                                          |");
    printf("\n| 1. QUAN LI SACH TRONG KHO   |  2. BAN DOC MUON SACH UTC2 |");
    printf("\n|                                                          |");
    printf("\n|                 NHAP PHIM 1 HOAC 2 DE CHON               |");
    printf("\n|                                                          |");
    printf("\n+----------------------------------------- 0. DANG XUAT ---+\n");
    scanf("%d", &luaChon);
    return luaChon;
}