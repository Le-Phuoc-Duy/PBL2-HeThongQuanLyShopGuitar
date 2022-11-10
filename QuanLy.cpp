#include "QuanLy.h"
#include <iostream>
#include <math.h>

QuanLy::QuanLy(){}
QuanLy::~QuanLy(){}

void QuanLy::HamChuanHoa(string& a){
    // xoa cac ki tu thua ' ' dau va cuoi
    while(a[0] == ' ')
    {
        a.erase(a.begin() + 0);
    }
    while (a[a.length() - 1] == ' ')
    {
        a.erase(a.begin() + a.length() - 1 );
    }
    // xoa cac ki tu thua ' ' o giua
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ' && a[i+1] == ' '){
            a.erase(a.begin() + i);
            i--;
        }
    }
    // viet hoa ki tu dau tien
    if (a[0] >= 97 && a[0] <= 122)
    {
        a[0] -= 32;
    }
    // viet hoa cac ki tu dau va viet thuong cac ki tu giua
    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] == ' '){
            i++;
            if (a[i] >= 97 && a[i] <= 122)
            {
                a[i] -= 32;
            }
        }
        else{
                if (a[i] >= 65 && a[i] <= 90){
                    a[i] += 32;
                }
        }
    }
}

int& QuanLy::Lua_chon(){
    static int luachon;
    while(1)
    {
        try{
            string x;
            cin.ignore();
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
int QuanLy::Nhap_ma(){
    int luachon = 0;
    while(1)
    {
        try{
            string x;
            fflush(stdin);
            cout << "\n\t\t\t\t\t\tNhap ma: "; cin >> x;
            int n = x.length();
            // Dung chuoi de kiem tra lua chon co phai la 1 so nguyen lon hon khong ko
            for(int i = n - 1; i >= 0; --i){
                if (x[i] < 48 || x[i] > 57) throw "";
            }
            // Neu ket qua dung, thi tra ve lua 
            for(int i = n - 1; i >= 0; --i){
                luachon += (int)(x[i] - '0') * pow(10, n-i-1);
            }
            break;
        }
        catch(...) {
            cout << "\t\t\t\t\t\tMa so phai la so tu nhien!" << endl;
        }
    }
    return luachon;
}
string& QuanLy::KiemTraSDT()
{
    static string x;
    while(1)
    {
        try
        {
            cout << "\t\t\t\t\t\tNhap so dien thoai: ";     fflush(stdin); cin >> x;
            if (x.length() != 10) throw "";
            if (x[0] != '0') throw "";
            for (int i = 1; i < x.length(); i++){
                if (x[i] < 48 || x[i] > 57) throw "";
            }
            break;
        }
        catch(...)
        {
            cout << "\t\t\t\t\t\tSo dien thoai khong hop le. Nhap lai!" << endl;
        }
    }
    return x;
}
double& QuanLy::In_double()
{
    static double kq;
    string data;
    fflush(stdin); cin >> data;
    while(1)
    {
        try
        {
            int a = 0, b = 0;
            int count = 0, n = data.length(), i = n - 1, count_pow = 1;
            for(int j = n - 1; j >= 0; --j){
                if (data[j] == '.') count++;
            }
            if (count != 0 && count != 1) throw "";
            while (data[i] != '.' && i >= 0){
                if (data[i] < 48 || data[i] > 57) throw "";
                else a += (int)(data[i] - '0') * count_pow;
                count_pow *= 10;
                i--;
            }
            i--; count_pow = 1;
            while (i >= 0){
                if (data[i] < 48 || data[i] > 57) throw "";
                else b += (int)(data[i] - '0') * count_pow;
                count_pow *= 10;
                i--;
            }
            kq = b + a/10;
            break;
        }
        catch(...)
        {
            cout << "\t\t\t\t\t\tKieu du lieu nhap vao khong hop le. Nhap lai: "; fflush(stdin); cin >> data;
        }
        return kq;
    }
}