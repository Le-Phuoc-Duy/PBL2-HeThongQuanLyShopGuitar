#include "QuanLyHD.h"

QuanLyHD::QuanLyHD(){
    this->lengthHD = 0;
}
QuanLyHD::~QuanLyHD(){};
int QuanLyHD::getLengthHD(){
    return this->lengthHD;
}
void QuanLyHD::setLengthHD(int lengthHD){
    this->lengthHD = lengthHD;
}

void QuanLyHD::Insert(QuanLyNV& nv, QuanLyKH& kh, QuanLyHang& hh){
    nv.Show(0);
    cout << "\t\t\t\t\t\tMa nhap vien nhap: ";  int maNV = Nhap_ma();
    int n = nv.FindIndex(maNV);
    while (n == -1 || nv.databaseNV[n]->getCheckDeleteSo() == 1){
        cout << "\t\t\t\t\t\tMa nhan vien chua ton tai hoac da xoa!" << endl;
        int luachon;
        do{
            cout << "\t\t\t\t\t\tBan muon?    1. Nhap lai       0. Thoat"; luachon = Lua_chon();
            if (luachon == 0) return;
        }while(luachon != 1);
        maNV = Nhap_ma();
    }
    HoaDon *hd = new HoaDon;
    int luachon1; string sdt;
    do{
        cout << "\t\t\t\t\t\tTrang thai hoa don?    1. Mua       2. Ban";
        luachon1 = Lua_chon();
        if (luachon1 == 2){
            cout << "\t\t\t\t\t\tSDT khach hang: " << endl; sdt = KiemTraSDT();
            int m = kh.FindIndexSDT(sdt);
            if (m == -1 || kh.databaseKH[n]->getCheckDeleteSo() == 1){
                cout << "\t\t\t\t\t\tSDT chua ton tai hoac da xoa!" << endl;
                delete hd;
                return;
            }
        }
    }while(luachon1 != 1 || luachon1 != 2);
    hd->setSDT(sdt);
    hd->Input(kh, nv, hh, maNV);
    databaseHD.push_back(hd);
    lengthHD++;
}
int QuanLyHD::FindIndexHD(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getMaHD() == index)
            return i;
    }
    return -1;
}
int QuanLyHD::FindIndexNV(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getMaNV() == index)
            return i;
    }
    return -1;
}
int QuanLyHD::FindIndex(const string& a)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        if (databaseHD[i]->getSDT() == a)
            return i;
    }
    return -1;
}

int QuanLyHD::FindIndexHH(const int &index)
{
    for (int i = 0; i < this->lengthHD; i++)
    {
        int n = this->databaseHD[i]->getLengthCTHD();
        for (int j = 0; j < n; j++) 
            if(this->databaseHD[i]->cthd[j]->getMaHH()) return j;
    }
    return -1;
}


void QuanLyHD::Find(QuanLyHang& hh)
{
    int maHD;
    cout << "\t\t\t\t\t\tNhap ma hoa don can tim: ";    maHD = Nhap_ma();
    int n = FindIndexHD(maHD);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }else{
            databaseHD[n]->Output(hh);
    }
}
void QuanLyHD::Remove()
{
    int maHD;
    ShowGeneral();
    cout << "\t\t\t\t\t\tNhap ma hoa don: "; maHD = Nhap_ma();
    if (FindIndexHD(maHD) == -1)
    {
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    else
    {
        int luachon;
        do{
            cout << "\t\t\t\t\t\tXac nhan?";
            cout << "\n\t\t\t\t\t\t1. Co";
            cout << "\n\t\t\t\t\t\t0. Khong?";
            luachon = Lua_chon();
            if (luachon == 1)
            {
                databaseHD.erase(FindIndexHD(maHD));
                this->lengthHD--;
                cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
            }
            else if (luachon == 0)
            {
                break;
            }
        }while (luachon != 0 || luachon != 1);
    }
}
void QuanLyHD::Show(QuanLyHang& hh){
    cout << "\n\t\t\t\t\t\t\t\tDANH SACH CAC HOA DON" << endl;
    for (int i = 0; i<this->lengthHD; i++){
        cout << "\t\t\t\t\t\tChi tiet hoa don thu " << i + 1;
        databaseHD[i]->Output(hh);
        cout << "\n\n";
    }
}
void QuanLyHD::ShowGeneral(){
    cout << "\n\t\t\t\t\t\tDANH SACH CAC HOA DON" << endl;
    cout << "\n\t\t\t\t--------------------------------------------------" << endl;
    cout << "\t\t\t\t" << "|" << setw(5) << "Ma HD" << "|" << setw(5) << "MaNV" << "|" << setw(5) << "SDT" 
    << "|" << setw(14) << "Thanh tien" << "|" << endl;
    cout << "\t\t\t\t--------------------------------------------------" << endl;
    for (int i = 0; i < this->lengthHD; i++){
        cout << *databaseHD[i];
    }
    cout << "\t\t\t\t--------------------------------------------------" << endl;
}
