#include "QuanLyHD.h"
#include <fstream>
#include <iomanip>
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

void QuanLyHD::Readf()
{
    ifstream filein;
    filein.open("HoaDon.txt");
    if (!filein)
    {
        textcolor(12);cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;textcolor(7);
        return;
    }
    filein.seekg(0, ios::end);
    if (filein.tellg() == 0) return;
    filein.seekg(0, ios::beg);
        
        int maHD;
        Date ngay_lap; int gio; int phut;
        double thanh_tien;
        string sdt;
        int maNV;
        int lengthCTHD;
        int trang_thai; string trang_thai_chuoi;
        int maHH;
        double don_gia;
        int so_luong;
    while (filein.eof() !=true)
    {
        filein >> maHD;
        filein.ignore();
        filein >> gio; filein.ignore(); filein >> phut;
        filein >> ngay_lap;
        ngay_lap.setGio(gio); ngay_lap.setPhut(phut);
        filein.ignore();
        filein >> maNV;
        filein.ignore(2);
        getline(filein, sdt, ',');
        filein.ignore();
        getline(filein, trang_thai_chuoi, ',');
        if (trang_thai_chuoi == "Ban"){/// Neu la don ban thi doc sdt
            trang_thai = 2;
        } else if (trang_thai_chuoi == "Mua"){
            trang_thai = 1;
        }
        filein >> lengthCTHD;
        HoaDon *hd = new HoaDon(maHD, lengthCTHD, maNV, sdt, ngay_lap, thanh_tien, trang_thai);
        for (int i = 0; i < lengthCTHD; i++){
            filein.ignore();
            filein >> maHH;
            filein.ignore();
            filein >> so_luong;
            filein.ignore();
            filein >> don_gia;
            ChiTietHoaDon *cthd = new ChiTietHoaDon(maHH, so_luong, don_gia);
            hd->cthd.push_back(cthd);
        }
        filein.ignore();
        filein >> thanh_tien;
        hd->setThanhTien(thanh_tien);
        filein.ignore();
        this->databaseHD.push_back(hd);
        this->lengthHD++;
    }
    textcolor(6);cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;textcolor(7);
    filein.close();
}

void QuanLyHD::Insert(QuanLyNV& nv, QuanLyKH& kh, QuanLyHang& hh){
    nv.Show(0);
    cout << "\t\t\t\t\t\tMa nhan vien nhap: ";  int maNV = Nhap_ma();
    int n = nv.FindIndex(maNV);
    while (n == -1 || nv.databaseNV[n]->getCheckDeleteSo() == 1){
        textcolor(12);cout << "\t\t\t\t\t\tMa nhan vien chua ton tai hoac da xoa!" << endl;textcolor(7);
        int luachon;
        do{
            cout << "\t\t\t\t\t\tBan muon?    1. Nhap lai       0. Thoat"; luachon = Lua_chon();
            if (luachon == 0) return;
        }while(luachon != 1);
        maNV = Nhap_ma(); // Nhap lai ma
        n = nv.FindIndex(maNV);
    }
    int trang_thai; string sdt;
    do{
        cout << "\t\t\t\t\t\tTrang thai hoa don?    1. Mua       2. Ban";
        trang_thai = Lua_chon();
        // Neu hoa don ban thi yeu cau nhap sdt khach hang
        if (trang_thai == 2){
            cout << "\t\t\t\t\t\tSDT khach hang: " << endl; sdt = KiemTraSDT();
            int m = kh.FindIndexSDT(sdt);
            if (m == -1 || (m != -1 && kh.databaseKH[m]->getCheckDeleteSo() == 1)){
                textcolor(12);cout << "\t\t\t\t\t\tKhach hang chua ton tai hoac da xoa!" << endl;textcolor(7);
                return;
            }
        }else if (trang_thai == 1) sdt = "NULL";
    } while(trang_thai != 1 && trang_thai != 2);
    HoaDon *hd = new HoaDon;
    hd->setTrangThai(trang_thai);
    hd->setMaNV(maNV);
    hd->setSDT(sdt);
    hd->Input(kh, nv, hh); // Cap nhat thong tin hoa don
    databaseHD.push_back(hd);
    this->lengthHD++;
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


void QuanLyHD::Find(QuanLyNV& nv, QuanLyHang& hh)
{
    cout << setw(55) << " "; for (int i = 1; i <= 50; i++) cout << "-";
    cout << "\n\n";
    cout << setw(61) << " " << "1. Tim theo ma" << endl;
    cout << setw(61) << " " << "2. Tim danh sach hoa don theo nhan vien" << endl;
    cout << setw(61) << " " << "0. Thoat" << endl;
    cout << "\n" << setw(55) << " "; for (int i = 1; i <= 50; i++) cout << "-";
    int luachon = Lua_chon();
    if (luachon == 1){
        int maHD;
        cout << "\t\t\t\t\t\tNhap ma hoa don can tim: ";    maHD = Nhap_ma();
        int n = FindIndexHD(maHD);
        if (n == -1){
            textcolor(12);cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;textcolor(7);
            return;
        }else{
                databaseHD[n]->Output(hh);
        }
    }else if(luachon == 2){
        int maNV;
        nv.Show(0); nv.Show(1);
        cout << "\t\t\t\t\t\tNhap ma nhan vien: ";    maNV = Nhap_ma();
        int count = 1;
        for (int i = 0; i < this->lengthHD; i++)
        {
            cout << "\t\t\t\t\t\tHoa don thu " << count;
            if (databaseHD[i]->getMaNV() == maNV){
                databaseHD[i]->Output(hh);
                count++;
            }
        }
    }else if(luachon == 0){
        return;
    }
    else {
        textcolor(12);cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat!" << endl;textcolor(7);
        return;
    }
}
void QuanLyHD::Remove()
{
    int maHD;
    int luachon1;
    do{
        cout << "\t\t\t\t\t\tBan muon xoa hoa don?    1. Mua       2. Ban";
        luachon1 = Lua_chon();
        if (luachon1 == 2){
            ShowGeneral(2);
            cout << "\t\t\t\t\t\tNhap ma hoa don: "; maHD = Nhap_ma();
            int n = FindIndexHD(maHD);
            if (n == -1 || databaseHD[n]->getTrangThaiSo() != 2)
            {
                textcolor(12);cout << "\t\t\t\t\t\tHoa don ban khong ton tai!" << endl;textcolor(7);
                return;
            }
        }else if (luachon1 == 1){
            ShowGeneral(1);
            cout << "\t\t\t\t\t\tNhap ma hoa don: "; maHD = Nhap_ma();
            int n = FindIndexHD(maHD);
            if (n == -1 || databaseHD[n]->getTrangThaiSo() != 1)
            {
                textcolor(12);cout << "\t\t\t\t\t\tHoa don mua khong ton tai!" << endl;textcolor(7);
                return;
            }
        }
    }while(luachon1 != 1 && luachon1 != 2);
        int luachon;
        do{
            cout << "\t\t\t\t\t\tXac nhan?      1. Co           0. Khong";
            luachon = Lua_chon();
            if (luachon == 1)
            {
                databaseHD.erase(FindIndexHD(maHD));
                this->lengthHD--;
                textcolor(6);cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;textcolor(7);
            }
            else if (luachon == 0)
            {
                break;
            }
        }while (luachon != 0 && luachon != 1);
}
void QuanLyHD::Show(QuanLyHang& hh){
    int luachon1;
    do{
        cout << "\t\t\t\t\t\tBan muon in danh sach hoa don?    1. Mua       2. Ban";
        luachon1 = Lua_chon();
        if (luachon1 == 2){
            textcolor(6);cout << "\n" << setw(60) << " " <<"DANH SACH HOA DON BAN" << endl;textcolor(7);
            int count = 0;
            for (int i = 0; i < this->lengthHD; i++){
                if (databaseHD[i]->getTrangThaiSo() == 2){
                    textcolor(3);cout << "\t\t\t\t\t\t\t\tChi tiet hoa don thu " << count + 1;textcolor(7);
                    databaseHD[i]->Output(hh);
                    cout << "\n\n";
                    count ++;
                }
            }
        }else if (luachon1 == 1){
            textcolor(6);cout << "\n" << setw(60) << " " <<"DANH SACH HOA DON MUA" << endl;textcolor(7);
            int count = 0;
            for (int i = 0; i < this->lengthHD; i++){
                if (databaseHD[i]->getTrangThaiSo() == 1){
                    textcolor(3);cout << "\t\t\t\t\t\t\t\tChi tiet hoa don thu " << count + 1;textcolor(7);
                    databaseHD[i]->Output(hh);
                    cout << "\n\n";
                    count ++;
                }
            }
        }
    }while(luachon1 != 1 && luachon1 != 2);
}
void QuanLyHD::Writef(){
    ofstream fileout;
    fileout.open("HoaDon.txt");
    for (int i = 0; i < this->getLengthHD(); i++)
    {
        if (i != 0) fileout << endl;
        fileout << databaseHD[i]->getMaHD() << ", ";
        fileout << databaseHD[i]->getNgayLap();
        fileout << ", " <<  databaseHD[i]->getMaNV() << ", " 
        << databaseHD[i]->getSDT() << ", " << databaseHD[i]->getTrangThai() << ", " << databaseHD[i]->getLengthCTHD() << ", ";
        for (int j = 0; j < databaseHD[i]->lengthCTHD; j++){
            fileout << databaseHD[i]->cthd[j]->getMaHH() << ", "<< databaseHD[i]->cthd[j]->getSoLuong() << ", " 
            << setprecision(15) <<databaseHD[i]->cthd[j]->getDonGia() << ", ";
        }
        fileout << databaseHD[i]->getThanhTien();
    }
    textcolor(6);cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;textcolor(7);
    fileout.close();
}
void QuanLyHD::ShowGeneral(int trang_thai){
    if (trang_thai == 1) {textcolor(6);cout << "\n" << setw(70) << " " <<"DANH SACH HOA DON MUA" << endl;textcolor(7);}
    else {textcolor(6);cout << "\n" << setw(70) << " " <<"DANH SACH HOA DON BAN" << endl;textcolor(7);}

    cout << setw(53) << " "; for (int i = 1; i<=55; i++) cout << "-"; cout << endl;
    cout << setw(53) << " " << "| Ma HD |" << " Ma NV |" << "    SDT    |" << " Thanh Tien |"<< " Trang Thai |" << endl;
    cout << setw(53) << " "; for (int i = 1; i<=55; i++) cout << "-";
    for (int i = 0; i < this->lengthHD; i++){
        if (databaseHD[i]->getTrangThaiSo() == trang_thai) cout << *databaseHD[i];
    }
    cout << "\n" << setw(53) << " "; for (int i = 1; i<=55; i++) cout << "-"; cout << endl;
}