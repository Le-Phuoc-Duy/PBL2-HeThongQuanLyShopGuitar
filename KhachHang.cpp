#include "KhachHang.h"

int KhachHang::count_id = 0;
// Ham constructor & destructor
KhachHang::KhachHang(int maKH, string hodem, string tenKH, string sdt, int so_diem, int check_delete){
    if (maKH != -1){
        this->maKH = maKH;
        if (count_id < maKH) count_id = maKH;
    }
    else this->maKH = ++count_id;
    this->hodem = hodem;
    this->sdt = sdt;
    this->tenKH = tenKH;
    this->so_diem = so_diem;
    this->check_delete = check_delete;
}
KhachHang::~KhachHang(){}
// Ham getter
int KhachHang::getMaKH(){
    return this->maKH;
}
string KhachHang::getHoDemKH(){
    return this->hodem;
}
string KhachHang::getTenKH(){
    return this->tenKH;
}
string KhachHang::getSDT(){
    return this->sdt;
}
int KhachHang::getSoDiem(){
    return this->so_diem;
}
string KhachHang::getCheckDelete()
{
    if (check_delete == 0) return "Ton Tai";
    else return "Da Xoa";
}
int KhachHang::getCheckDeleteSo(){
    return check_delete;
}
// Ham setter
void KhachHang::setMaKH(int maKH){
    this->maKH = maKH;
}
void KhachHang::setHoDemKH(string hodem){
    this->hodem = hodem;
}
void KhachHang::setTenKH(string tenKH){
    this->tenKH = tenKH;
}
void KhachHang::setSDT(string sdt){
    this->sdt = sdt;
}
void KhachHang::setSoDiem(int so_diem){
    this->so_diem = so_diem;
}
void KhachHang::setCheckDelete(int check)
{
    this->check_delete = check;
}

istream& operator>>(istream& in, KhachHang& khachhang){
    /// Kiem tra ten va ho co rong khong?
    do{
        try{
            fflush(stdin);
            cout << "\t\t\t\t\t\tNhap ho dem khach hang: ";  getline(in, khachhang.hodem);
            while(khachhang.hodem[0] == ' ') khachhang.hodem.erase(khachhang.hodem.begin() + 0);
            if (khachhang.hodem.empty() == 1) throw "\t\t\t\t\t\tNhap lai!";
             /// Kiem tra ho co ki tu dac biet khong?
            for (int i = 0; i < khachhang.hodem.length(); i++){
                if (!(khachhang.hodem[0] >= 97 && khachhang.hodem[0] <= 122) && !(khachhang.hodem[i] >= 65 && khachhang.hodem[i] <= 90)) throw "Nhap lai!";
            }
            break;
        }
        catch(const char* e){
            cout << e << endl;
        }
    }while(1);

    do{
        try{
            fflush(stdin);
            cout << "\t\t\t\t\t\tNhap ten khach hang: ";  getline(in, khachhang.tenKH);
            while(khachhang.tenKH[0] == ' ') khachhang.tenKH.erase(khachhang.tenKH.begin() + 0);
            if (khachhang.tenKH.empty() == 1) throw "\t\t\t\t\t\tNhap lai!";
             /// Kiem tra ten co ki tu dac biet khong?
            for (int i = 0; i < khachhang.tenKH.length(); i++){
                if (!(khachhang.tenKH[0] >= 97 && khachhang.tenKH[0] <= 122) && !(khachhang.tenKH[i] >= 65 && khachhang.tenKH[i] <= 90)) throw "Nhap lai!";
            }
            break;
        }
        catch(const char* e){
            cout << e << endl;
        }
    }while(1);
    ///

    /// Kiem tra so dien thoai co hop le khong
    while(1)
    {
        try
        {
            cout << "\t\t\t\t\t\tNhap so dien thoai: "; in >> khachhang.sdt;
            if (khachhang.sdt.length() != 10) throw "";
            if (khachhang.sdt[0] != '0') throw "";
            for (int i = 1; i < khachhang.sdt.length(); i++){
                if (khachhang.sdt[i] < 48 || khachhang.sdt[i] > 57) throw "";
            }
            break;
        }
        catch(...)
        {
            cout << "\t\t\t\t\t\tSo dien thoai khong hop le. Nhap lai!" << endl;
        }
    }
    khachhang.so_diem = 0;
    return in;
}

ostream& operator<<(ostream& out, KhachHang& khachhang)
{
    out << "\n" << setw(52) << " " << "|" << left << setw(7) << khachhang.maKH << "|" << left << setw(17) << khachhang.hodem + " " << left << setw(5) << khachhang.tenKH 
    << "|" << left << setw(13) << khachhang.sdt << "|" << setw(11) << khachhang.so_diem << "|";
    return out;
}