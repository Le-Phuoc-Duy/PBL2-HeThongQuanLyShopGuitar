#include<iostream>
#include <iomanip>
#include "NhanVien.h"

int NhanVien::count_id = 0;
//Ham dung
NhanVien::NhanVien(int maNV, string hodem, string tenNV, int gioi_tinh, Date ngay_sinh, string sdt, string dia_chi, int chuc_vu, double luong, int check_delete, Date ngay_vao, Date ngay_nghi)
{
    if (maNV != -1){
        this->maNV = maNV;
        if (count_id < maNV) count_id = maNV;
    }
    else this->maNV = ++count_id;
    this->gioi_tinh = gioi_tinh;
    this->ho_dem_NV = hodem;
    this->tenNV = tenNV;
    this->ngay_sinh = ngay_sinh;
    this->sdt = sdt;
    this->dia_chi = dia_chi;
    this->chuc_vu = chuc_vu;
    this->luong = luong;
    this->check_delete = check_delete;
    this->ngay_vao = ngay_vao;
    this->ngay_nghi = ngay_nghi;
}
NhanVien::~NhanVien(){}
// Ham Setter
void NhanVien::setCountID(int count)
{
    this->count_id = count;
}
void NhanVien::setMaNV(int maNV)
{
    this->maNV = maNV;
}
void NhanVien::setGioiTinh(int gioi_tinh)
{
    this->gioi_tinh = gioi_tinh;
}
void NhanVien::setTenNV(string tenNV)
{
    this->tenNV = tenNV;
}
void NhanVien::setHoDemNV(string hodem)
{
    this->ho_dem_NV = hodem;
}
void NhanVien::setNgaySinh(Date ngay_sinh)
{
    this->ngay_sinh = ngay_sinh;
}
void NhanVien::setSDT(string sdt)
{
    this->sdt = sdt;
}
void NhanVien::setDiaChi(string dia_chi)
{
    this->dia_chi = dia_chi;
}
void NhanVien::setLuong()
{
    if (chuc_vu == 0) luong = 7000000;
    else luong = 5500000;
}
void NhanVien::setChucVu(int chuc_vu)
{
    this->chuc_vu = chuc_vu;
}
void NhanVien::setCheckDelete(int check)
{
    this->check_delete = check;
}
void NhanVien::setNgayVao(){
    Date ngayvao;
    ngayvao.setGio(0);
    ngayvao.setPhut(0);
    this->ngay_vao = ngayvao;
}
void NhanVien::setNgayNghi(){
    Date ngaynghi;
    ngaynghi.setGio(0);
    ngaynghi.setPhut(0);
    this->ngay_nghi = ngaynghi;
}
//Ham Getter
int NhanVien::getCountID()
{
    return count_id;
}
int NhanVien::getMaNV()
{
    return maNV;
}
string NhanVien::getTenNV()
{
    return tenNV;
}
string NhanVien::getHoDemNV()
{
    return ho_dem_NV;
}
string NhanVien::getHoTenNV()
{
    return ho_dem_NV + tenNV;
}
string NhanVien::getGioiTinh()
{
    if (gioi_tinh == 1) return "Nam";
    else return "Nu";
}
Date NhanVien::getNgaySinh()
{
    return ngay_sinh;
}
string NhanVien::getSDT()
{
    return sdt;
}
string NhanVien::getDiaChi()
{
    return dia_chi;
}
double NhanVien::getLuong()
{
    return luong;
}
string NhanVien::getChucVu()
{
    if (chuc_vu == 0) return "Quan ly";
    else return "Nhan vien";
}
string NhanVien::getCheckDelete()
{
    if (check_delete == 0) return "Ton Tai";
    else return "Da Xoa";
}
int NhanVien::getCheckDeleteSo(){
    return check_delete;
}
Date NhanVien::getNgayVao(){
    return this->ngay_vao;
}
Date NhanVien::getNgayNghi(){
    return this->ngay_nghi;
}
/// Da nang hoa toan tu
ostream& operator<<(ostream& out, NhanVien& nv)
{
    out << "\n\t\t\t" << "|" << setw(5) << nv.maNV << "|" << setw(15) << nv.ho_dem_NV + " " << setw(5) << nv.tenNV << "|" << setw(9) << nv.getGioiTinh() 
    <<  "|" << setw(2) << nv.ngay_sinh << "|" << setw(13) << nv.getSDT() << "|" <<  setw(19) << nv.dia_chi << "|" << setw(9) << nv.getChucVu() << "|" 
    <<setw(9) << (size_t)nv.luong << "|" << setw(13) << nv.ngay_vao << "|";
    if (nv.getCheckDeleteSo() == 1) out << setw(13) << nv.ngay_nghi << "|";
    return out;
}
istream& operator>>(istream& in, NhanVien& nv)
{
    string x;
    cin.ignore();
    cout << "\t\t\t\t\t\tNhap ho dem nhan vien: ";  getline(in, nv.ho_dem_NV);
    cout << "\t\t\t\t\t\tNhap ten nhan vien: ";  getline(in, nv.tenNV);
    cout << "\t\t\t\t\t\tGioi tinh :    1.Nam       0. Nu" << endl;
    do{
        cout << "\t\t\t\t\t\tNhap gioi tinh : "; fflush(stdin); in >> x;
    }while(x != "0" && x!= "1");
    nv.gioi_tinh = (int)(x[0] - '0');
    cout << "\t\t\t\t\t\tNhap ngay sinh: ";     nv.ngay_sinh.Input();
    while(1)
    {
        try
        {   fflush(stdin);
            cout << "\t\t\t\t\t\tNhap so dien thoai: "; in >> nv.sdt;
            if (nv.sdt.length() != 10) throw "";
            if (nv.sdt[0] != '0') throw "";
            for (int i = 1; i < nv.sdt.length(); i++){
                if (nv.sdt[i] < 48 || nv.sdt[i] > 57) throw "";
            }
            break;
        }
        catch(...)
        {
            cout << "\t\t\t\t\t\tSo dien thoai khong hop le. Nhap lai!" << endl;
        }
    }
    cout << "\t\t\t\t\t\tNhap dia chi: ";    in.ignore(); getline(in, nv.dia_chi);
    string y;
    cout << "\t\t\t\t\t\tChuc vu:     0. Quan Ly              1. Nhan vien"; 
    do{
        cout << "\n\t\t\t\t\t\tNhap chuc vu : ";   fflush(stdin); in >> y;
    }while(y != "0" && y != "1");
    fflush(stdin);
    nv.chuc_vu = (int)(y[0] - '0');
    nv.setLuong();
    nv.setNgayVao();
    return in;
}