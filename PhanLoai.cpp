#include <iostream>
#include "PhanLoai.h"
#include <iomanip>

int PhanLoai::count_id = 0;
// Ham getter
string PhanLoai::getTenPL(){
    return this->tenPL;
}
int PhanLoai::getMaPL(){
    return this-> maPL;
}
int PhanLoai::getCheckDeleteSo(){
    return this-> check_delete;
}
string PhanLoai::getCheckDelete(){
    if (check_delete == 0) return "Ton tai";
    else return "Da Xoa";
}
// Ham setter
void PhanLoai::setTenPL(string tenPL){
    this->tenPL = tenPL;
}
void PhanLoai::setMaPL(int  maPL){
    this-> maPL =  maPL;
}
void PhanLoai::setCheckDelete(int check_delete){
    this->check_delete =  check_delete;
}
// Ham constructor
PhanLoai::PhanLoai(int  maPL, string tenPL, int check_delete){
    if (maPL != -1){
        this->maPL = maPL;
        if (count_id < maPL) count_id = maPL;
    }
    else this->maPL = ++count_id;
    this->tenPL = tenPL;
    this->check_delete = check_delete;
}
// Ham destructor
PhanLoai::~PhanLoai(){}

istream& operator>>(istream& in, PhanLoai& pl)
{
    in.ignore();
    cout << "\t\t\t\t\t\tNhap ten phan loai: ";  getline(in, pl.tenPL);
    return in;
}
ostream& operator<<(ostream& out, const PhanLoai& pl)
{
    out << "\n\t\t\t\t\t\t\t |" << setw(12) << pl.maPL << "|" << setw(14) << pl.tenPL <<  "|";
    return out;
}