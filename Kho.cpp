#include "Kho.h"
#include "QuanLyHang.h"
#include <iomanip>
#include <iostream>
using namespace std;

int Kho::count_id = 0;
// Ham getter
int Kho::getMaHH() {
    return this->maHH;
}
string Kho::getTenHH() {
    return this->tenHH;
}
int Kho::getmaPL() {
    return this->phan_loai.getMaPL();
}
string Kho::getTenPL() { return this->phan_loai.getTenPL();}
double Kho::getGiaVon() {
    return this->gia_von;
}
double Kho::getGiaBan() {
    return this->gia_ban;
}
int Kho::getSoLuong() {
    return this->so_luong;
}
int Kho::getCheckDeleteSo() {
    return this->check_delete;
}
string Kho::getCheckDelete()
{
    if (check_delete == 0) return "Ton Tai";
    else return "Da Xoa";
}
int Kho::getCountID() {
    return this->count_id;
}
// Ham setter
void Kho::setMaHH(int maHH){
    this->maHH = maHH;
}
void Kho::setTenHH(string tenHH){
    this->tenHH = tenHH;
} 

void Kho::setGiaVon(double gia_von){
   this->gia_von = gia_von; 
}
void Kho::setGiaBan(double gia_ban){
    this->gia_ban = gia_ban;
}
void Kho::setSoLuong(int so_luong){
    this->so_luong = so_luong;
}
void Kho::setCheckDelete(int check_delete){
    this->check_delete = check_delete;
}
void Kho::setMaPL(int maPL)
{
    this->phan_loai.setMaPL(maPL);
}
void Kho::setTenPL(string tenPL)
{
    this->phan_loai.setTenPL(tenPL);
}
// Ham constructor
Kho::Kho(int maHH, string tenHH, double gia_von, double gia_ban, int so_luong, int maPL, int check_delete){
    if (maHH != -1){
        this->maHH = maHH;
        if (count_id < maHH) count_id = maHH;
    }
    else this->maHH = ++count_id;
    this->tenHH = tenHH;
    this->gia_von = gia_von; 
    this->gia_ban = gia_ban;
    this->so_luong = so_luong;
    this->phan_loai.setMaPL(maPL);
    this->check_delete = check_delete;
}
// Ham destructor
Kho::~Kho(){}
// Da nang hoa toan tu
ostream& operator<<(ostream& out, Kho& kho)
{
    out << "\n\t\t\t" << "|" << setw(8) << kho.maHH << "|" << setw(19) <<  kho.tenHH << "|" << setw(14) << setprecision(10) << kho.gia_von 
    << "|" << setw(14) << kho.gia_ban << "|" << setw(9) << kho.so_luong << "|" << setw(9) << kho.phan_loai.getMaPL() << "|";
    return out;
}
void Kho::Input(QuanLyHang& ql_hh, string tenHH, int maPL)
{
    this->tenHH = tenHH; this->setMaPL(maPL);
    
    cout << "\t\t\t\t\t\tNhap gia nhap vao: ";     this->gia_von = ql_hh.In_double();
    cout << "\t\t\t\t\t\tNhap gia ban ra: ";     this->gia_ban = ql_hh.In_double();
}