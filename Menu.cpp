//chinh ma KH
#include "QuanLyHang.h"
#include "QuanLyNV.h"
#include "QuanLyKH.h"
#include "QuanLyHD.h"
#include "ThongKe.h"
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
CONST INT MIDDLE = 48;
string PASS;
//// Ham tao bang
void textColor(int x)
{
    HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, x);
}
void Table(string str, string str1 = "NULL", string str2 = "NULL", string str3 = "NULL", string str4 = "NULL", string str5 = "NULL", string str6 = "NULL", string str7 = "NULL", string str8 = "NULL")
{
    textColor(14);
    cout << setw(MIDDLE) << " ";
    for (int i = 1; i <= (65 - str.length()) / 2; i++)
        cout << "=";
    cout << str;
    for (int i = 1; i <= 65 - str.length() - (65 - str.length()) / 2; i++)
        cout << "=";
    cout << "\n\n";

    textColor(11);
    if (str1 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str1 << endl;
    }
    if (str2 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str2 << endl;
    }
    if (str3 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str3 << endl;
    }
    if (str4 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str4 << endl;
    }
    if (str5 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str5 << endl;
    }
    if (str6 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str6 << endl;
    }
    if (str7 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str7 << endl;
    }
    if (str8 != "NULL")
    {
        for (int i = 1; i <= MIDDLE + 3 * (65 - str.length()) / 8; i++)
            cout << " ";
        cout << str8 << endl;
    }

    cout << "\n";
    textColor(14);
    for (int i = 1; i <= MIDDLE; i++)
        cout << " ";
    for (int i = 1; i <= 30; i++)
        cout << "=";
    cout << " END ";
    for (int i = 1; i <= 30; i++)
        cout << "=";
}
//// Giao dien khoi dong
void gotoxy(int x, int y)
{
    COORD d;
    d.X = x - 1;
    d.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),d);
}
void load()
{
    textColor(14);
    char a = 219;
    gotoxy(73,34);
    cout << ("Loading...\n");
    gotoxy(55,36);
    for (int r = 1; r<=46; r++)
    {
        for (int q = 0; q <= 100000000; q++);
        cout << a;
    }

}
void Start()
{
    textColor(11);
    cout << "   .d88888b.                                 888                   .d8888b.  888                             .d8888b.           d8b 888                    " << endl;
    cout << "  d88P* *Y88b                                888                  d88P  Y88b 888                            d88P  Y88b          Y8P 888                    " << endl;
    cout << "  888     888                                888                  Y88b.      888                            888    888              888                    " << endl;
    cout << "  888     888 888  888  8888b.  88888b.      888     888  888      *Y888b.   88888b.   .d88b.  88888b.      888        888  888 888 888888  8888b.  888d888" << endl;
    cout << "  888     888 888  888     *88b 888 *88b     888     888  888         *Y88b. 888 *88b d88**88b 888 *88b     888  88888 888  888 888 888        *88b 888P*  " << endl;
    cout << "  888 Y8b 888 888  888 .d888888 888  888     888     888  888           *888 888  888 888  888 888  888     888    888 888  888 888 888    .d888888 888    " << endl;
    cout << "  Y88b.Y8b88P Y88b 888 888  888 888  888     888     Y88b 888     Y88b  d88P 888  888 Y88..88P 888 d88P     Y88b  d88P Y88b 888 888 Y88b.  888  888 888    " << endl;
    cout << "   *Y888888*   *Y88888 *Y888888 888  888     88888888 *Y88888      *Y8888P*  888  888  *Y88P*  88888P*       *Y8888P88  *Y88888 888  *Y888 *Y888888 888    " << endl;
    cout << "         Y8b                                              888                                  888                                                          ";
    cout << "                                                     Y8b d88P                                  888                                                          ";
    cout << "                                                      YY88PP                                   888                                                          " << endl;

    Sleep(350);

    int x= 80;
    cout << "                                                                                                     @ @@@@@ "<< endl;
    Sleep(x); cout << "                                                                                                     @@@@@@@*"<< endl;
    Sleep(x); cout << "                                                                                                    @@@@@@   "<< endl;
    Sleep(x); cout << "                                                                                                 @@@@        "<< endl;
    Sleep(x); cout << "                                                                                               @@@@          "<< endl;
    Sleep(x); cout << "                                                                                            @@@@             "<< endl;
    Sleep(x); cout << "                                                                                         @@@@@               "<< endl;
    Sleep(x); cout << "                                                                                       @@@@                  "<< endl;
    Sleep(x); cout << "                                                                           @@@@@@.  @@@@@                    "<< endl;
    Sleep(x); cout << "                                                                          @@@#(@@@@@@@                       "<< endl;
    Sleep(x); cout << "                                                                        @@@@@@@@@@@@                         "<< endl;
    Sleep(x); cout << "                                                               @@@@@@@@@@@@@@//(@@@                          "<< endl;
    Sleep(x); cout << "                                                             @@@@@@@@@@@@@@@@@@@@@@@@@@                      "<< endl;
    Sleep(x); cout << "                                                            @@@@@@@@@@@*%(@@@@@@@@&                          "<< endl;
    Sleep(x); cout << "                                                            @@@@@@@@@@@@@@@@@@@@@                            "<< endl;
    Sleep(x); cout << "                                                            @@@@@@@@@@@@@@@@@@@@                             "<< endl;
    Sleep(x); cout << "                                                             @@@@@@@@@@@@@@@@@@@                             "<< endl;
    Sleep(x); cout << "                                                               %@@@@@@@@@@@@@@#                              "<< endl;
    Sleep(x); cout << "                                                                   @@@@@@@@@                                 "<< endl;

    load();
    cout << "\n\n\n";textColor(7);system("pause");
}
////Ham thao tac
int& Lua_chon_hop_le(){
    static int luachon;
    cout << endl;
    while(1)
    {
        try{
            string x;
            textColor(7);cout << "\n\t\t\t\t\t\tNhap lua chon: "; cin >> x;
            // Dung chuoi de kiem tra lua chon co phai la 1 so nguyen tu 0 -> 9 khong
            if (x.length() != 1) throw "";
            if (x[0] < 48 || x[0] > 57) throw int(1);
            // Neu ket qua dung, thi tra ve lua chon
            luachon = (int)(x[0] - '0');
            break;
        }
        catch(...) {
            textColor(12);cout << "\t\t\t\t\t\tLua chon phai la kieu so nguyen tu 0-9!" << endl;
        }
    }
    return luachon;
}
void Thao_tac_hang_hoa(QuanLyHang &ql_hang, QuanLyHD& ql_hd)
{
    int luachon1;
    do
    {
        system("cls");
        Table(" MENU QUAN LY KHO HANG",
        ">> 1. Thao tac voi hang hoa",
        ">> 2. Thao tac voi phan loai hang",
        ">> 0. Thoat");
        luachon1 = Lua_chon_hop_le();

        switch (luachon1)
        {
        case 0:
            break;
        case 1:
        {
            int luachon2;
            do
            {
                system("cls");
                Table(" MENU QUAN LY MAT HANG ",
                ">> 1. Them hang hoa",
                ">> 2. Xoa mot mat hang",
                ">> 3. Tim thong tin hang hoa",
                ">> 4. Thay doi thong tin hang hoa",
                ">> 5. Sap xep cac hang hoa",
                ">> 6. In ra danh sach hang hoa",
                ">> 7. Xuat file danh sach hang hoa",
                ">> 0. Thoat");
                luachon2 = Lua_chon_hop_le();

                switch (luachon2)
                {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    cout << endl;
                    try{
                        ql_hang.Insert();
                    }catch(int e){
                    }
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 2:
                {
                    cout << endl; ql_hang.Remove();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 3:
                {
                    cout << endl; ql_hang.Find();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 4:
                {
                    cout << endl; ql_hang.Update();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 5:
                {
                    cout << endl; ql_hang.Sort();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 6:
                {
                    cout << endl; ql_hang.Show(0);
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 7:
                {
                    ql_hang.Writef();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                default:
                {
                    textColor(12);cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                }
            } while (luachon2);
            break;
        }
        case 2:
        {
            int luachon2;
            do
            {
                system("cls");
                Table(" MENU QUAN LY PHAN LOAI ",
                ">> 1. Them phan loai",
                ">> 2. Xoa mot phan loai",
                ">> 3. Tim thong tin phan loai",
                ">> 4. Thay doi thong tin phan loai",
                ">> 5. In ra danh sach phan loai",
                ">> 6. Xuat file danh sach phan loai",
                ">> 0. Thoat");
                luachon2 = Lua_chon_hop_le();

                switch (luachon2)
                {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    cout << endl; 
                    try
                    {
                        ql_hang.InsertPL();
                    }
                    catch(int e){}
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 2:
                {
                    cout << endl; ql_hang.RemovePL();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 3:
                {
                    cout << endl; ql_hang.FindPL();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 4:
                {
                    cout << endl; ql_hang.UpdatePL();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 5:
                {
                    cout << endl; ql_hang.ShowPL(0);
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                case 6:
                {
                    cout << endl; ql_hang.WritefPL();
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                default:
                {
                    textColor(12);cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
                    cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
                    break;
                }
                }
            } while (luachon2);
            break;
        }
        default:
        {
            textColor(12);cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        }
    } while (luachon1 != 0);
}

void Thao_tac_nhan_vien(QuanLyNV &ql_nv, QuanLyHD &ql_hd)
{
    int luachon1;
    do
    {
        system("cls");

        Table(" MENU QUAN LY NHAN VIEN ",
        ">> 1. Them nhan vien",
        ">> 2. Xoa mot nhan vien",
        ">> 3. Tim thong tin nhan vien",
        ">> 4. Cap nhat thong tin nhan vien",
        ">> 5. Sap xep nhan vien theo ten",
        ">> 6. In ra danh sach nhan vien",
        ">> 7. Xuat file danh sach nhan vien",
        ">> 0. Thoat");
        luachon1 = Lua_chon_hop_le();

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << endl; ql_nv.Insert();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 2:
        {
            cout << endl; ql_nv.Remove();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 3:
        {
            cout << endl; ql_nv.Find();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 4:
        {
            cout << endl; ql_nv.Update();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 5:
        {
            cout << endl; ql_nv.Sort();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 6:
        {
            cout << endl; ql_nv.Show(0);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 7:
        {
            ql_nv.Writef();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        default:
        {
            textColor(12);cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        }
    } while (luachon1);
}

void Thao_tac_khach_hang(QuanLyKH &ql_kh, QuanLyHD &ql_hd)
{
    int luachon1;
    do
    {
        system("cls");
        Table(" MENU QUAN LY KHACH HANG ",
        ">> 1. Them khach hang",
        ">> 2. Xoa mot khach hang",
        ">> 3. Tim thong tin khach hang",
        ">> 4. Thay doi thong tin khach hang",
        ">> 5. Sap xep khach hang theo ten",
        ">> 6. In ra danh sach khach hang",
        ">> 7. Xuat file danh sach khach hang",
        ">> 0. Thoat");
        luachon1 = Lua_chon_hop_le();;

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << endl; ql_kh.Insert();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 2:
        {
            cout << endl; ql_kh.Remove();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 3:
        {
            cout << endl; ql_kh.Find();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 4:
        {
            cout << endl; ql_kh.Update(ql_hd);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 5:
        {
            cout << endl; ql_kh.Sort();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 6:
        {
            cout << endl; ql_kh.Show(0);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 7:
        {
            ql_kh.Writef();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        default:
        {
            textColor(12);cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        }
    } while (luachon1);
}

void Thao_tac_hoa_don(QuanLyHD &ql_hd, QuanLyNV &ql_nv, QuanLyKH &ql_kh, QuanLyHang &ql_hh)
{
    int luachon1;
    do
    {
        system("cls");
        Table(" MENU QUAN LY HOA DON ",
        ">> 1. Them hoa don",
        ">> 2. Tim thong tin hoa don",
        ">> 3. Xoa hoa don",
        ">> 4. Tim danh sach hoa don",
        ">> 5. In ra danh sach hoa don",
        ">> 6. Xuat file danh sach hoa don",
        ">> 0. Thoat");
        luachon1 = Lua_chon_hop_le();

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << endl; ql_hd.Insert(ql_nv, ql_kh, ql_hh);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 2:
        {
            cout << endl; ql_hd.Find(ql_nv, ql_hh);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 3:
        {
            cout << endl; ql_hd.Remove();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 4:
        {
            cout << endl; ql_hd.Find(ql_nv, ql_hh);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 5:
        {
            cout << endl; ql_hd.Show(ql_hh);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 6:
        {
            ql_hd.Writef();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        default:
        {
            textColor(12);cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        }
    } while (luachon1);
}

void Bao_cao_tai_chinh(QuanLyHD &ql_hd, QuanLyNV &ql_nv, ThongKe &bctc){
    int luachon1;
    do
    {
        system("cls");
        Table(" MENU QUAN LY HOA DON ",
        ">> 1. Bao cao doanh thu hom nay",
        ">> 2. Bao cao theo thang",
        ">> 3. Bao cao theo nam",
        ">> 0. Thoat");
        luachon1 = Lua_chon_hop_le();

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << endl; ql_hd.ThongKeHomNay();
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 2:
        {
            cout << endl; bctc.ThongKeThang(ql_nv,ql_hd);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        case 3:
        {
            cout << endl; bctc.ThongKeNam(ql_nv,ql_hd);
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        default:
        {
            textColor(12);cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
            break;
        }
        }
    } while (luachon1);
}

//// Quan ly dang nhap co mat khau
void savePass(){
    //Luu pass vao file password
    ofstream ofs("Password.txt", std::ofstream::out);
    ofs.close();
    ofstream fileout("Password.txt", std::ofstream::out);
    fileout << PASS;
    //
}
void setPass(){
    ifstream filein;
    filein.open("Password.txt");
    getline(filein,PASS);
    filein.close();
}
string getPass(string prompt)
{
    textColor(7);cout << prompt;
    string pass;
    char ch;
    while ((ch = _getch()) != 13)
    {
        if ((ch == 8))
        {
            if (pass.length() > 0)
            {
                cout << "\b \b";
                pass.resize(pass.length() - 1);
            }
        }
        else
        {
            pass += ch;
            textColor(7);cout << "*";
        }
    }
    return pass;
}
int main()
{
    QuanLyHang ql_hang;
    QuanLyNV ql_nv;
    QuanLyKH ql_kh;
    QuanLyHD ql_hd;
    ThongKe bctc;
    //doc file .txt
    ql_nv.Readf();
    ql_kh.Readf();
    ql_hang.ReadfPL();
    ql_hang.Readf();
    ql_hd.Readf();
    system("cls");
    //Khoi dong
    Start();
    // Menu dang nhap
    int luachon1;
    do
    {
        system("cls");
        Table(" PHAN MEM QUAN LY DAN GUITAR ",
        ">> 1. Dang nhap bang admin",
        ">> 2. Dang nhap bang nhan vien",
        ">> 0. Thoat");
        luachon1 = Lua_chon_hop_le();
        if (luachon1 == 1)
        {
            string input;
            int check = 1;
            input = getPass("\n\t\t\t\t\t\tNhap mat khau: ");
            setPass();
            int count = 0;
            while (input != PASS)
            {
                textColor(12); cout << "\n\t\t\t\t\t\tSai mat khau. Nhap lai!" << endl;
                textColor(7); cout << "\t\t\t\t\t\tBan co muon tiep tuc (c/k): ";
                char x;
                cin >> x;
                if (x == 'c'){
                    count++;
                    input = getPass("\n\t\t\t\t\t\tNhap mat khau: ");
                }
                else
                {
                    check = 0;
                    break;
                }
                /// Neu mat khau sai 3 lan thi se thoat
                if (count == 2 && input != PASS){
                    textColor(12);cout << "\n\n\t\t\t\t\t\tBan da sai mat khau 3 lan. Thoat!" << endl;
                    check = 0;
                    textColor(7);cout << "\t\t\t\t\t\t"; textColor(7);system("pause");
                    break;
                }
            }
            if (check == 1)
            {
                // Menu dang nhap
                int luachon2;
                do
                {
                    system("cls");
                    Table(" MENU QUAN LY CHINH",
                    ">> 1. Thao tac voi nhan vien",
                    ">> 2. Thao tac voi kho hang",
                    ">> 3. Thao tac voi khach hang",
                    ">> 4. Thao tac voi hoa don",
                    ">> 5. Bao cao tai chinh",
                    ">> 6. Doi mat khau admin",
                    ">> 0. Thoat");
                    luachon2 = Lua_chon_hop_le();

                    switch (luachon2)
                    {
                    case 0:
                    {
                        break;
                    }
                    case 1:
                    {
                        Thao_tac_nhan_vien(ql_nv, ql_hd);
                        break;
                    }
                    case 2:
                    {
                        Thao_tac_hang_hoa(ql_hang, ql_hd);
                        break;
                    }
                    case 3:
                    {
                        Thao_tac_khach_hang(ql_kh, ql_hd);
                        break;
                    }
                    case 4:
                    {
                        Thao_tac_hoa_don(ql_hd, ql_nv, ql_kh, ql_hang);

                        break;
                    }
                    case 5:
                    {
                        Bao_cao_tai_chinh(ql_hd,ql_nv,bctc);
                        break;
                    }
                    case 6:
                    {
                        string newpass;
                        textColor(7);cout << "\n\t\t\t\t\t\tNhap mat khau moi: ";
                        cin.ignore();
                        getline(cin, PASS);
                        savePass();
                        textColor(6);cout << "\t\t\t\t\t\tDoi mat khau thanh cong!" << endl;
                        cout << "\t\t\t\t\t\t"; textColor(7);system("pause");
                        break;
                    }
                    default:
                    {
                        textColor(12);cout << "\n\t\t\t\t\t\tLua chon khong hop le!" << endl;
                        cout << "\t\t\t\t\t\t";
                        textColor(7);system("pause");
                        break;
                    }
                    }
                } while (luachon2 != 0);
            }
            else
                luachon1 = 1;
        }
        else if (luachon1 == 2)
        {
            int luachon2;
            do
            {
                system("cls");
                Table(" MENU QUAN LY CHINH ",
                ">> 1. Thao tac voi khach hang",
                ">> 2. Thao tac voi kho hang",
                ">> 3. Thao tac voi hoa don",
                ">> 0. Thoat");
                
                luachon2 = Lua_chon_hop_le();

                switch (luachon2)
                {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    Thao_tac_khach_hang(ql_kh, ql_hd);
                    break;
                }
                case 2:
                {
                    Thao_tac_hang_hoa(ql_hang, ql_hd);
                    break;
                }
                case 3:
                {
                    Thao_tac_hoa_don(ql_hd, ql_nv, ql_kh, ql_hang);
                    break;
                }
                default:
                {
                    textColor(12);cout << "\n\t\t\t\t\t\tLua chon khong hop le!" << endl;
                    cout << "\t\t\t\t\t\t";     textColor(7);system("pause");
                    break;
                }
                }
            } while (luachon2 != 0);
        }
        else if (luachon1 != 0){
            textColor(12);cout << "\n\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         textColor(7);system("pause");
        }
    } while (luachon1 != 0);
    ql_nv.Writef();
    ql_kh.Writef();
    ql_hang.Writef();
    ql_hang.WritefPL();
    ql_hd.Writef();
    // bctc.Writef();
}
