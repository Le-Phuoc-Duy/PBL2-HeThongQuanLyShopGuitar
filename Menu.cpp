//chinh ma KH
#include "QuanLyHang.h"
#include "QuanLyNV.h"
#include "QuanLyKH.h"
#include "QuanLyHD.h"
#include "ThongKe.h"
#include <fstream>
#include <conio.h>
string PASS;
int& Lua_chon_hop_le(){
    static int luachon;
    while(1)
    {
        try{
            string x;
            cout << "\n\t\t\t\t\t\tNhap lua chon: "; cin >> x;
            // Dung chuoi de kiem tra lua chon co phai la 1 so nguyen tu 0 -> 9 khong
            if (x.length() != 1) throw "";
            if (x[0] < 48 || x[0] > 57) throw int(1);
            // Neu ket qua dung, thi tra ve lua chon
            luachon = (int)(x[0] - '0');
            break;
        }
        catch(...) {
            cout << "\t\t\t\t\t\tLua chon phai la kieu so nguyen tu 0-9!" << endl;
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
        cout << "\n\t\t\t\t\t\t=================================================";
        cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY KHO HANG\t\t|";
        cout << "\n\t\t\t\t\t\t|\t1. Thao tac voi hang hoa\t\t|";
        cout << "\n\t\t\t\t\t\t|\t2. Thao tac voi phan loai hang\t\t|";
        cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t======================END========================";
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
                cout << "\n\t\t\t\t\t\t-------------------------------------------------";
                cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY MAT HANG\t\t|";
                cout << "\n\t\t\t\t\t\t|\t1. Them hang hoa\t\t\t|";
                cout << "\n\t\t\t\t\t\t|\t2. Xoa mot mat hang\t\t\t|";
                cout << "\n\t\t\t\t\t\t|\t3. Tim thong tin hang hoa\t\t|";
                cout << "\n\t\t\t\t\t\t|\t4. Thay doi thong tin hang hoa\t\t|";
                cout << "\n\t\t\t\t\t\t|\t5. Sap xep cac hang hoa\t\t\t|";
                cout << "\n\t\t\t\t\t\t|\t6. In ra danh sach hang hoa\t\t|";
                cout << "\n\t\t\t\t\t\t|\t7. Xuat file danh sach hang hoa\t\t|";
                cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
                cout << "\n\t\t\t\t\t\t-------------------------------------------------";
                luachon2 = Lua_chon_hop_le();

                switch (luachon2)
                {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    ql_hang.Insert();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 2:
                {
                    ql_hang.Remove();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 3:
                {
                    ql_hang.Find();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 4:
                {
                    ql_hang.Update();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 5:
                {
                    ql_hang.Sort();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 6:
                {
                    system("cls");
                    ql_hang.Show(0);
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 7:
                {
                    ql_hang.Writef();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                default:
                {
                    cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
                    cout << "\t\t\t\t\t\t";         system("pause");
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
                cout << "\n\t\t\t\t\t\t-------------------------------------------------";
                cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY PHAN LOAI\t\t|";
                cout << "\n\t\t\t\t\t\t|\t1. Them phan loai\t\t\t|";
                cout << "\n\t\t\t\t\t\t|\t2. Xoa mot phan loai\t\t\t|";
                cout << "\n\t\t\t\t\t\t|\t3. Tim thong tin phan loai\t\t|";
                cout << "\n\t\t\t\t\t\t|\t4. Thay doi thong tin phan loai\t\t|";
                cout << "\n\t\t\t\t\t\t|\t5. In ra danh sach phan loai\t\t|";
                cout << "\n\t\t\t\t\t\t|\t6. Xuat file danh sach phan loai\t|";
                cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
                cout << "\n\t\t\t\t\t\t-------------------------------------------------";
                luachon2 = Lua_chon_hop_le();

                switch (luachon2)
                {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    ql_hang.InsertPL();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 2:
                {
                    ql_hang.RemovePL();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 3:
                {
                    ql_hang.FindPL();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 4:
                {
                    ql_hang.UpdatePL();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 5:
                {
                    ql_hang.ShowPL(0);
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                case 6:
                {
                    ql_hang.WritefPL();
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                default:
                {
                    cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
                    cout << "\t\t\t\t\t\t";         system("pause");
                    break;
                }
                }
            } while (luachon2);
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         system("pause");
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
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY NHAN VIEN\t\t|";
        cout << "\n\t\t\t\t\t\t|\t1. Them nhan vien\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t2. Xoa mot nhan vien\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t3. Tim thong tin nhan vien\t\t|";
        cout << "\n\t\t\t\t\t\t|\t4. Cap nhat thong tin nhan vien\t\t|";
        cout << "\n\t\t\t\t\t\t|\t5. Sap xep nhan vien theo ten\t\t|";
        cout << "\n\t\t\t\t\t\t|\t6. In ra danh sach nhan vien\t\t|";
        cout << "\n\t\t\t\t\t\t|\t7. Xuat file danh sach nhan vien\t|";
        cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        luachon1 = Lua_chon_hop_le();

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            ql_nv.Insert();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 2:
        {
            ql_nv.Remove();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 3:
        {
            ql_nv.Find();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 4:
        {
            ql_nv.Update();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 5:
        {
            ql_nv.Sort();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            ql_nv.Show(0);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 7:
        {
            ql_nv.Writef();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         system("pause");
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
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY KHACH HANG\t\t|";
        cout << "\n\t\t\t\t\t\t|\t1. Them khach hang\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t2. Xoa mot khach hang\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t3. Tim thong tin khach hang\t\t|";
        cout << "\n\t\t\t\t\t\t|\t4. Thay doi thong tin khach hang\t|";
        cout << "\n\t\t\t\t\t\t|\t5. Sap xep khach hang theo ten\t\t|";
        cout << "\n\t\t\t\t\t\t|\t6. In ra danh sach khach hang\t\t|";
        cout << "\n\t\t\t\t\t\t|\t7. Xuat file danh sach khach hang\t|";
        cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        luachon1 = Lua_chon_hop_le();;

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            ql_kh.Insert();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 2:
        {
            ql_kh.Remove();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 3:
        {
            ql_kh.Find();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 4:
        {
            ql_kh.Update(ql_hd);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            ql_kh.Sort();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            ql_kh.Show(0);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 7:
        {
            ql_kh.Writef();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         system("pause");
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
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY HOA DON\t\t|";
        cout << "\n\t\t\t\t\t\t|\t1. Them hoa don\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t2. Tim thong tin hoa don\t\t|";
        cout << "\n\t\t\t\t\t\t|\t3. Xoa hoa don\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t4. Tim danh sach hoa don\t\t|";
        cout << "\n\t\t\t\t\t\t|\t5. In ra danh sach hoa don\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t6. Xuat file danh sach hoa don\t|";
        cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        luachon1 = Lua_chon_hop_le();

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            ql_hd.Insert(ql_nv, ql_kh, ql_hh);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 2:
        {
            ql_hd.Find(ql_nv, ql_hh);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 3:
        {
            ql_hd.Remove();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 4:
        {
            ql_hd.Find(ql_nv, ql_hh);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 5:
        {
            ql_hd.Show(ql_hh);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 6:
        {
            ql_hd.Writef();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         system("pause");
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
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY HOA DON\t\t|";
        cout << "\n\t\t\t\t\t\t|\t1. Bao cao doanh thu hom nay\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t2. Bao cao theo thang\t\t|";
        cout << "\n\t\t\t\t\t\t|\t3. Bao cao theo nam\t\t|";
        cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t-------------------------------------------------";
        luachon1 = Lua_chon_hop_le();

        switch (luachon1)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            ql_hd.ThongKeHomNay();
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 2:
        {
            bctc.ThongKeThang(ql_nv,ql_hd);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        case 3:
        {
            bctc.ThongKeNam(ql_nv,ql_hd);
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         system("pause");
            break;
        }
        }
    } while (luachon1);
}
// Ham dang nhap
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
    cout << prompt;
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
            cout << "*";
        }
    }
    return pass;
}

//
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
    // bctc.Readf();
    // Menu dang nhap
    int luachon1;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t*************************************************";
        cout << "\n\t\t\t\t\t\t|\t\tPHAN MEM QUAN LY DAN GUITAR\t|";
        cout << "\n\t\t\t\t\t\t|\t1. Dang nhap bang admin\t\t\t|";
        cout << "\n\t\t\t\t\t\t|\t2. Dang nhap bang nhan vien\t\t|";
        cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
        cout << "\n\t\t\t\t\t\t***********************END***********************";
        luachon1 = Lua_chon_hop_le();
        if (luachon1 == 1)
        {
            string input;
            int check = 1;
            input = getPass("\t\t\t\t\t\tNhap mat khau: ");
            setPass();
            while (input != PASS)
            {
                cout << "\n\t\t\t\t\t\tSai mat khau. Nhap lai!" << endl;
                cout << "\n\t\t\t\t\t\tBan co muon tiep tuc (c/k): ";
                char x;
                cin >> x;
                if (x == 'c')
                    input = getPass("\t\t\t\t\t\tNhap mat khau: ");
                else
                {
                    check = 0;
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
                    cout << "\n\t\t\t\t\t\t*************************************************";
                    cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY CHINH\t\t|";
                    cout << "\n\t\t\t\t\t\t|\t1. Thao tac voi nhan vien\t\t|";
                    cout << "\n\t\t\t\t\t\t|\t2. Thao tac voi kho hang\t\t|";
                    cout << "\n\t\t\t\t\t\t|\t3. Thao tac voi khach hang\t\t|";
                    cout << "\n\t\t\t\t\t\t|\t4. Thao tac voi hoa don\t\t\t|";
                    cout << "\n\t\t\t\t\t\t|\t5. Bao cao tai chinh\t\t\t|";
                    cout << "\n\t\t\t\t\t\t|\t6. Doi mat khau admin\t\t\t|";
                    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
                    cout << "\n\t\t\t\t\t\t***********************END***********************";
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
                        cout << "\n\t\t\t\t\t\tNhap mat khau moi: ";
                        cin.ignore();
                        getline(cin, PASS);
                        savePass();
                        cout << "\n\t\t\t\t\t\tDoi mat khau thanh cong!" << endl;
                        break;
                    }
                    default:
                    {
                        cout << "\n\t\t\t\t\t\tLua chon khong hop le!" << endl;
                        cout << "\t\t\t\t\t\t";
                        system("pause");
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
                cout << "\n\t\t\t\t\t\t*************************************************";
                cout << "\n\t\t\t\t\t\t|\t\tMENU QUAN LY CHINH\t\t|";
                cout << "\n\t\t\t\t\t\t|\t1. Thao tac voi khach hang\t\t|";
                cout << "\n\t\t\t\t\t\t|\t2. Thao tac voi kho hang\t\t|";
                cout << "\n\t\t\t\t\t\t|\t3. Thao tac voi hoa don\t\t\t|";
                cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t|";
                cout << "\n\t\t\t\t\t\t***********************END***********************";
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
                    cout << "\n\t\t\t\t\t\tLua chon khong hop le!" << endl;
                    cout << "\t\t\t\t\t\t";     system("pause");
                    break;
                }
                }
            } while (luachon2 != 0);
        }
        else if (luachon1 != 0){
            cout << "\n\t\t\t\t\t\tLua chon khong hop le!" << endl;
            cout << "\t\t\t\t\t\t";         system("pause");
        }
    } while (luachon1 != 0);
    ql_nv.Writef();
    ql_kh.Writef();
    ql_hang.Writef();
    ql_hang.WritefPL();
    ql_hd.Writef();
    // bctc.Writef();
}
