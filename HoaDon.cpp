#include <iostream>
#include "HoaDon.h"
#include "QuanLyHang.h"
using namespace std;

int HoaDon::count_id = 0;
// Ham dung va ham huy
HoaDon::HoaDon(int maHD, int lengthCTHD, int maNV, string sdt,  Date ngay_lap, double thanh_tien){
    if (maHD != -1){
        this->maHD = maHD;
        if (count_id < maHD) count_id = maHD;
    }
    else this->maHD = ++count_id;
    this->maNV = maNV;
    this->sdt = sdt;
    this->ngay_lap = ngay_lap;
    this->thanh_tien = thanh_tien;
    this->lengthCTHD = lengthCTHD;
    this->thanh_tien = thanh_tien;
}
HoaDon::~HoaDon(){}

// Ham Setter
void HoaDon::setMaHD(int maHD)
{
    this->maHD = maHD;
}

void HoaDon::setSDT(string sdt)
{
   this->sdt = sdt;
}

void HoaDon::setLengthCTHD(int lengthcthd)
{
    this->lengthCTHD = lengthCTHD;
}

void HoaDon::setNgayLap(Date ngay_lap)
{
    this->ngay_lap = ngay_lap;
}
void HoaDon::setThanhTien(double thanh_tien)
{
    this->ngay_lap = ngay_lap;
}
void HoaDon::setMaNV(int maNV)
{
    this->maNV = maNV;
}
// Ham Getter
int HoaDon::getMaHD()
{
    return this->maHD;
}

string HoaDon::getSDT()
{
   return this->sdt;
}

int HoaDon::getLengthCTHD()
{
    return this->lengthCTHD;
}

Date HoaDon::getNgayLap()
{
    return this->ngay_lap;
}
double HoaDon::getThanhTien()
{
    return this->thanh_tien;
}
int HoaDon::getMaNV()
{
    return this->maNV;
}
//
void HoaDon::Input(QuanLyKH& kh, QuanLyNV& nv, QuanLyHang& hh, int maNV, string sdt){
    this->sdt = sdt; this->maNV = maNV;
    Date ngay_lap;
    setNgayLap(ngay_lap);
    cout << "\t\t\t\t\t\tNhap so luong loai hang: "; cin >> this->lengthCTHD;
    for (int i = 0; i < this->lengthCTHD; i++){
        hh.Show(0);
        cout << "\n\t\t\t\t\t\tNhap thong tin chi tiet loai " << i + 1;       
        ChiTietHoaDon *p = new ChiTietHoaDon;
        p->Input(hh);
        this->cthd.push_back(p);
        this->thanh_tien = this->thanh_tien + this->cthd[i]->getDonGia();
    }
    int n = kh.FindIndexSDT(sdt);
    double sd_ct = (this->thanh_tien) / 100000; // so diem duoc cong them khi mua: 100k tich 1 diem
    double sd_bd = kh.databaseKH[n]->getSoDiem(); // so diem ban dau
    kh.databaseKH[n]->setSoDiem(sd_bd + sd_ct);
    // neu tren 100 diem thi duoc giam gia (100d = 100k)
    if (sd_bd >= 100)
    {
        int tien = 0;
        cout << "\n\t\t\t\t\t\tKhach hang duoc giam " << sd_bd * 1000 << endl;
        if (sd_bd*1000 <= this->thanh_tien) this->thanh_tien -= sd_bd * 1000; // tien tich duoc <= thanh tien
        else{// tien tu diem tich duoc > thanh tien
            this->thanh_tien = 0;
            tien = (sd_bd * 1000 - thanh_tien)/1000;
        }
        kh.databaseKH[n]->setSoDiem(tien);
    }
    cout << "\n\t\t\t\t\t\tTHANH TIEN: " << (size_t)thanh_tien << endl;
}
ostream& operator<<(ostream& out, HoaDon& nv)
{
    out << "\t\t\t\t" << "|" << setw(5) << nv.getMaHD() << "|" << setw(5) << nv.getMaNV() << "|" << setw(5) << nv.getSDT() 
    << "|" << setw(14) << setprecision(13) << nv.getThanhTien() << "|" << endl;
    return out;
}
void HoaDon::Output(QuanLyHang& hh)
{
    cout << "\n\t\t\t\t\t\t1. Ma hoa don: " << maHD ;
    cout << "\n\t\t\t\t\t\t1. Ma nhan vien nhap: " << maNV ;
    cout << "\n\t\t\t\t\t\t2. SDT khach hang: " << sdt;
    cout << "\n\t\t\t\t\t\t3. Ngay lap: ";
    ngay_lap.Output(); 
    cout << endl;
    cout << "\t\t\t\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t\t" << setw(28) << "|      Ten hang hoa|" << setw(9) << "So luong|" << setw(15) << "Don gia|" << endl;
    cout << "\t\t\t\t\t\t--------------------------------------------" ;
    for (int i = 0; i < lengthCTHD; i++)
    {
        cthd[i]->Output(hh);
    }
    cout << "\n\t\t\t\t\t\t--------------------------------------------" ;
    cout << "\n\n\n\t\t\t\t\t\tTHANH TIEN: " << setprecision(15) << thanh_tien << endl;
}