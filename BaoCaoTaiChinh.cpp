#include "BaoCaoTaiChinh.h"
#include <iomanip>
#include <fstream>
BaoCaoTaiChinh::BaoCaoTaiChinh()
{
    this->lengthBCTC = 1;
}
BaoCaoTaiChinh::~BaoCaoTaiChinh()
{
}
int BaoCaoTaiChinh::getLengthBCTC()
{
    return this->lengthBCTC;
}
void BaoCaoTaiChinh::setLengthBCTC(int lengthBCTC)
{
    this->lengthBCTC = lengthBCTC;
}
void BaoCaoTaiChinh::Readf()
{
    ifstream filein;
    filein.open("BaoCaoTaiChinh.txt");
    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
    double luongNV, doanh_thu, loi_nhuan, von;
    int year;
    while (filein.eof() != true)
    {
        filein >> year;
        filein >> luongNV;
        filein >> doanh_thu;
        filein >> loi_nhuan;
        filein >> von;
        ThongKe *tk = new ThongKe(luongNV, doanh_thu, loi_nhuan, von, year);
        databaseBCTC.push_back(tk);
        this->lengthBCTC++;
    }
    filein.close();
}

void BaoCaoTaiChinh::Writef()
{
    ofstream fileout;
    fileout.open("BaoCaoTaiChinh.txt");
    for (int i = 0; i < this->getLengthBCTC(); i++)
    {
        fileout << databaseBCTC[i]->getYear() << endl;
        fileout << setprecision(15) << databaseBCTC[i]->tc->luongNV << endl;
        fileout << databaseBCTC[i]->tc->doanh_thu << endl;
        fileout << databaseBCTC[i]->tc->loi_nhuan << endl;
        fileout << databaseBCTC[i]->tc->von << endl;
    }
    fileout.close();
}
void BaoCaoTaiChinh::ThongKeThang(QuanLyNV& nv, QuanLyHD& hd)
{
    int month, year;
    cout << "Nhap thang can thong ke: "; cin >> month; cin.ignore(); cin >> year;

    databaseBCTC.erase(this->lengthBCTC);
    ThongKe *tk = new ThongKe(nv,hd);
    databaseBCTC.push_back(tk);

    int cnt = 0;
    for(int i = 0; i< this->lengthBCTC; i++){
        if(databaseBCTC[i]->getYear() == year){
            cout << "Tong luong nhan vien: " << databaseBCTC[i]->tc[month-1].luongNV << endl;
            cout << "Doanh thu: " << databaseBCTC[i]->tc[month-1].doanh_thu << endl;
            cout << "Loi nhuan: " << databaseBCTC[i]->tc[month-1].loi_nhuan << endl;
        }
        else cnt++;
    }
    if (cnt == this->lengthBCTC) cout << "Khong co du lieu";
}

void BaoCaoTaiChinh::ThongKeQuy(QuanLyNV& nv, QuanLyHD& hd)
{
    int quy, year;
    cout << "Nhap quy can thong ke: "; cin >> quy;
    cout << "Nhap nam: "; cin >> year;

    databaseBCTC.erase(this->lengthBCTC);
    ThongKe *tk = new ThongKe(nv,hd);
    databaseBCTC.push_back(tk);

    int cnt = 0;
    double luongNV = 0, doanhthu = 0, loinhuan = 0;
    for(int i = 0; i< this->lengthBCTC; i++){
        if(databaseBCTC[i]->getYear() == year){
            for(int j = 0;j<3;j++){
                luongNV += databaseBCTC[i]->tc[quy*3-1 - j].luongNV;
                doanhthu += databaseBCTC[i]->tc[quy*3-1 - j].doanh_thu;
                loinhuan += databaseBCTC[i]->tc[quy*3-1 - j].loi_nhuan;
            }
        }
        else cnt++;
    }
    if (cnt == this->lengthBCTC) cout << "Khong co du lieu";
    else{
        cout << "Tong luong nhan vien: " << luongNV << endl;
        cout << "Doanh thu: " << doanhthu << endl;
        cout << "Loi nhuan: " << loinhuan << endl;
    }
    
}

void BaoCaoTaiChinh::ThongKeNam(QuanLyNV& nv, QuanLyHD& hd)
{
    int year;
    cout << "Nhap nam can thong ke: "; cin >> year;

    databaseBCTC.erase(this->lengthBCTC);
    ThongKe *tk = new ThongKe(nv,hd);
    databaseBCTC.push_back(tk);

    int cnt = 0;
    double luongNV = 0, doanhthu = 0, loinhuan = 0;
    for(int i = 0; i< this->lengthBCTC; i++){
        if(databaseBCTC[i]->getYear() == year){
            for(int j = 0;j<12;j++){
                luongNV += databaseBCTC[i]->tc[j].luongNV;
                doanhthu += databaseBCTC[i]->tc[j].doanh_thu;
                loinhuan += databaseBCTC[i]->tc[j].loi_nhuan;
            }
        }
        else cnt++;
    }
    if (cnt == this->lengthBCTC) cout << "Khong co du lieu";
    else{
        cout << "Tong luong nhan vien: " << luongNV << endl;
        cout << "Doanh thu: " << doanhthu << endl;
        cout << "Loi nhuan: " << loinhuan << endl;
    }
}