#include "QuanLyNV.h"
#include "QuanLyHD.h"
#include <fstream>
#include <iomanip>

QuanLyNV::QuanLyNV(){
    this->lengthNV = 0;
}
QuanLyNV::~QuanLyNV(){}
// Getter Setter
void QuanLyNV::setLengthNV(int lengthNV)
{
    this->lengthNV = lengthNV;
}
int QuanLyNV::getLengthNV()
{
    return lengthNV;
}
void QuanLyNV::Readf()
{
    ifstream filein;
    filein.open("NhanVien.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
        int maNV;
        string ho_dem_NV;
        string tenNV;
        int gioi_tinh;
        Date ngay_sinh;
        string sdt;
        string dia_chi;
        double luongcoban;
        int chuc_vu;
        string gioi_tinh_chuoi;
        string chuc_vu_chuoi;
        double luong;
    while (filein.eof() != true)
    {
        filein >> maNV;
        filein.ignore();
        getline(filein, ho_dem_NV, ',');
        getline(filein, tenNV, ',');
        getline(filein, gioi_tinh_chuoi, ',');
        HamChuanHoa(gioi_tinh_chuoi);
        filein >> ngay_sinh;
        filein.ignore(2);
        getline(filein, sdt, ',');
        filein.ignore();
        getline(filein, dia_chi, ',');
        filein.ignore();
        getline(filein, chuc_vu_chuoi, ',');
        HamChuanHoa(chuc_vu_chuoi);
        filein >> luong;
        filein.ignore();

        // Kiem tra chuc vu hop le khong
        if (chuc_vu_chuoi == "Ban Hang") chuc_vu = 0;   
        else if (chuc_vu_chuoi == "Quan Kho") chuc_vu = 1;
        else{
            cout << "\n\t\t\t\t\t\tChuc vu khong hop le!" << endl;    
            continue;
        }
        ///// Kiem tra SDT hop le khong
        for (int i = 0; i < sdt.length(); i++){
            if (sdt[i] < 48 || sdt[i] > 57) sdt = "0";
            break;
        }
            // kiem tra sdt co du 10 so chua
        if (sdt.length() != 10){
            cout << "\n\t\t\t\t\t\tSo dien thoai cua nhan vien " << maNV << " khong hop le";
            continue;
        };
        // Kiem tra gioi tinh co hop le khong
        if (gioi_tinh_chuoi == "Nam") gioi_tinh = 1;  
        else if (gioi_tinh_chuoi == "Nu") gioi_tinh = 0;  
        else{
            cout << "\n\t\t\t\t\t\tGioi tinh cua nhan vien " << maNV << " khong hop le!" << endl;
            continue;
        }
        // Kiem tra ma nhan vien co trung khong 
        if (FindIndex(maNV) != -1)
        {
            cout << "\n\t\t\t\t\t\tMa nhan vien " << maNV << " da ton tai!" << endl;
            continue;
        }
        HamChuanHoa(ho_dem_NV); HamChuanHoa(tenNV);
        NhanVien *nv = new NhanVien(maNV, ho_dem_NV, tenNV, gioi_tinh, ngay_sinh, sdt, dia_chi, chuc_vu, luong);
        databaseNV.push_back(nv);
        (this->lengthNV)++;
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}
void QuanLyNV::Show()
{
    cout << "\n\t\t\t\t\t\t\tDANH SACH NHAN VIEN";
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t"<< "|Ma NV|" << setw(21) << "Ho ten nhan vien  |" << setw(9) << "Gioi tinh|" << setw(11) 
    << "Ngay sinh|"<< setw(14) << "SDT     |" <<  setw(20) << "Dia chi     |"<< setw(10) << "Chuc vu |" << setw(10)  << "Luong  |";
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->lengthNV; i++)
    {
        cout << *databaseNV[i];
    }
    cout << "\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
}
void QuanLyNV::Insert()
{
    NhanVien *nv = new NhanVien;
    cin >> *nv;
    string ho = nv->getHoDemNV();   HamChuanHoa(ho);    nv->setHoDemNV(ho);
    string ten = nv->getTenNV();    HamChuanHoa(ten);   nv->setTenNV(ten);
    
    databaseNV.push_back(nv);
    this->lengthNV++;
    cout << "\t\t\t\t\t\tThem hang hoa thanh cong!" << endl;
}

void QuanLyNV::Writef()
{
    ofstream fileout;
    fileout.open("NhanVien.txt");
    for (int i = 0; i < this->getLengthNV(); i++)
    {
        if (i != 0) fileout << endl;
        fileout << databaseNV[i]->getMaNV() << ", " <<  databaseNV[i]->getHoDemNV() << ", " <<  databaseNV[i]->getTenNV() << ", " 
        << databaseNV[i]->getGioiTinh() <<  ", " << databaseNV[i]->getNgaySinh() << ", " << databaseNV[i]->getSDT() << ", " 
        << databaseNV[i]->getDiaChi() << ", " << databaseNV[i]->getChucVu() << ", " << (size_t)databaseNV[i]->getLuong();
    }
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}
void QuanLyNV::Find()
{
    cout << "\t\t\t\t\t\tMa can tim:";      int maNV = Nhap_ma();
    int n = FindIndex(maNV);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }else{
            cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t"<< "|Ma NV|" << setw(21) << "Ho ten nhan vien  |" << setw(9) << "Gioi tinh|" << setw(11) 
            << "Ngay sinh|"<< setw(14) << "SDT     |" <<  setw(20) << "Dia chi     |"<< setw(10) << "Chuc vu |" << setw(10)  << "Luong  |";
            cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
            cout << *databaseNV[n];
            cout << "\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
        }
}
int QuanLyNV::FindIndex(const int& index){
    for (int i = 0; i < this->lengthNV; i++)
    {
        if (databaseNV[i]->getMaNV() == index) return i;
    }
    return -1;
}
bool up(string x, string y)
{
    return (x < y) ? true : false;
}
bool down(string x, string y)
{
    return (x > y) ? true : false;
}

void QuanLyNV::selectionsortTen(bool (*cmp)(string,string)){
    for(int i = 0; i < this->lengthNV - 1; i++){
        for (int j = i + 1; j < this->lengthNV; j++){
            if ((*cmp)(databaseNV[i]->getTenNV(), databaseNV[j]->getTenNV())){
                swap(databaseNV[i], databaseNV[j]);
            }
            if (databaseNV[i]->getTenNV() == databaseNV[j]->getTenNV()){
                if ((*cmp)(databaseNV[i]->getHoDemNV(), databaseNV[j]->getHoDemNV())){
                swap(databaseNV[i], databaseNV[j]);
            }
            }
        }
    }
}

void QuanLyNV::Sort()
{
    system("cls");
    cout << "\n\t\t\t\t\t\t------------------------------------------";
    cout << "\n\t\t\t\t\t\t|1. Sap xep ten nhan vien theo chieu giam|";
    cout << "\n\t\t\t\t\t\t|2. Sap xep ten nhan vien theo chieu tang|";
    cout << "\n\t\t\t\t\t\t------------------------------------------";
    int luachon = Lua_chon();
    switch(luachon){
        case 1:
        {
            selectionsortTen(down);
            Show();
            break;
        }
        case 2:
        {
            selectionsortTen(up);
            Show();
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!" << endl;
            break;

        }
    }
}

void QuanLyNV::Update(){
    system("cls");
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ten\t\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Cap nhat gioi tinh\t\t|";
    cout << "\n\t\t\t\t\t\t|\t3. Cap nhat ngay sinh\t\t|";
    cout << "\n\t\t\t\t\t\t|\t4. Cap nhat so dien thoai\t|";
    cout << "\n\t\t\t\t\t\t|\t5. Cap nhat dia chi\t\t|";
    cout << "\n\t\t\t\t\t\t|\t6. Cap nhat chuc vu\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t|";
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    int luachon = Lua_chon(); 

    if (luachon == 0){
        return;
    }else{
        Show();
        int nv; cout << "\n\t\t\t\t\t\tMa so nhan vien can cap nhat: ";
        nv = Nhap_ma();
        int n = FindIndex(nv);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }
        switch (luachon){
            case 1:
            {
                string tenNV, hodem;
                cout << "\t\t\t\t\t\tNhap ho dem nhan vien: ";
                cin.ignore(); getline(cin, hodem);
                cout << "\t\t\t\t\t\tNhap ten nhan vien: ";
                getline(cin, tenNV);
                HamChuanHoa(tenNV); HamChuanHoa(hodem);
                databaseNV[n]->setTenNV(tenNV);
                databaseNV[n]->setHoDemNV(hodem);
                break;
            }
            case 2:
            {
                int gioitinh;
                do{
                    cout << "\t\t\t\t\t\tGioi tinh :    1.Nam       0. Nu" << endl;
                    gioitinh = Lua_chon();
                }while(gioitinh != 0 && gioitinh != 1);
                databaseNV[n]->setGioiTinh(gioitinh);
                break;
            }
            case 3:
            {
                Date ngaysinh;
                cout << "\t\t\t\t\t\tNhap ngay sinh nhan vien: ";
                cin >> ngaysinh;
                databaseNV[n]->setNgaySinh(ngaysinh);
                break;
            }
            case 4:
            {
                string sdt = KiemTraSDT();
                databaseNV[n]->setSDT(sdt);
                break;
            }
            case 5:
            {
                string diachi;
                cout << "\t\t\t\t\t\tNhap dia chi nhan vien: ";
                cin.ignore(); getline(cin,diachi);
                databaseNV[n]->setDiaChi(diachi);
                break;
            }
            case 6:
            {
                int chucvu;
                do{
                    cout << "\t\t\t\t\t\tChuc vu: ";
                    cout << "\n\t\t\t\t\t\t 0. Nhan vien ban hang "; 
                    cout << "\n\t\t\t\t\t\t 1. Nhan vien quan kho "; 
                    chucvu = Lua_chon();
                }while(chucvu != 0 && chucvu != 1);
                databaseNV[n]->setChucVu(chucvu);
                databaseNV[n]->setLuong();
                break;
            }
            default:
            {
                cout << "\t\t\t\t\t\tLua chon khong hop le!";
                cout << "\n\t\t\t\t\t\t"; system("pause");
                break;
            } 
        }
        cout << "\n\t\t\t\t\t\tCap nhat thanh cong!" << endl;
    }
}
void QuanLyNV::Remove(QuanLyHD& ql_hd)
{
    int manv;
    Show();
    cout << "\t\t\t\t\t\tMa can xoa: ";   manv = Nhap_ma();
    if (FindIndex(manv) == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    if (ql_hd.FindIndexNV(manv) != -1){
        cout << "\t\t\t\t\t\tNhan vien da duoc dang ki boi hoa don. Khong the xoa!" << endl;
        return;
    }
        databaseNV.erase(FindIndex(manv));
        this->lengthNV--;
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
}
