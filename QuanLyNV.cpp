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
    filein.seekg(0, ios::end);
    if (filein.tellg() == 0) return;
    filein.seekg(0, ios::beg);
        int maNV;
        string ho_dem_NV;
        string tenNV;
        int gioi_tinh;
        Date ngay_sinh(0,0,0),ngay_vao(0,0,0),ngay_nghi(0,0,0);
        string sdt;
        string dia_chi;
        double luongcoban;
        int chuc_vu;
        string gioi_tinh_chuoi;
        string chuc_vu_chuoi;
        double luong;
        string check_delete_chuoi;
        int check_delete;
    while (filein.eof() != true)
    {
        filein >> maNV;
        filein.ignore(2);
        getline(filein, ho_dem_NV, ',');
        filein.ignore();
        getline(filein, tenNV, ',');
        filein.ignore();
        getline(filein, gioi_tinh_chuoi, ',');
        filein.ignore();
        filein >> ngay_sinh;
        filein.ignore(2);
        getline(filein, sdt, ',');
        filein.ignore();
        getline(filein, dia_chi, ',');
        filein.ignore();
        getline(filein, chuc_vu_chuoi, ',');
        // HamChuanHoa(chuc_vu_chuoi);
        filein >> luong;
        filein.ignore(2);
        getline(filein, check_delete_chuoi, ',');
        filein.ignore();
        filein >> ngay_vao;
        
        // HamChuanHoa(check_delete_chuoi);
        // kiem tra bien check co hop le khong
        if (check_delete_chuoi == "Da Xoa"){
            filein.ignore();
            filein >> ngay_nghi;
            check_delete = 1;
        } 
        else if (check_delete_chuoi == "Ton Tai") check_delete = 0;
        
        if (gioi_tinh_chuoi == "Nam") gioi_tinh = 1;  
        else if (gioi_tinh_chuoi == "Nu") gioi_tinh = 0;  
        
        HamChuanHoa(ho_dem_NV); HamChuanHoa(tenNV);
        NhanVien *nv = new NhanVien(maNV, ho_dem_NV, tenNV, gioi_tinh, ngay_sinh, sdt, dia_chi, chuc_vu, luong, check_delete, ngay_vao, ngay_nghi);
        databaseNV.push_back(nv);
        (this->lengthNV)++;
    }
    filein.close();
}
void QuanLyNV::Show(int trang_thai)
{
    if (trang_thai == 0) cout << "\n\t\t\t\t\t\t\tDANH SACH NHAN VIEN HIEN CO";
    else cout << "\n\t\t\t\t\t\t\tDANH SACH NHAN VIEN DA XOA";
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t"<< "|Ma NV|" << setw(21) << "Ho ten nhan vien  |" << setw(9) << "Gioi tinh|" << setw(11) 
    << "Ngay sinh|"<< setw(14) << "SDT     |" <<  setw(20) << "Dia chi     |"<< setw(10) << "Chuc vu |" << setw(10)  << "Luong  |" 
    << setw(10)  << "Ngay vao  |";
    if (trang_thai == 1) cout << setw(10)  << "Ngay ra  |";
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------";
    for (int i = 0; i < this->lengthNV; i++)
    {
        if (databaseNV[i]->getCheckDeleteSo() == trang_thai) cout << *databaseNV[i];
    }
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
}
void QuanLyNV::Insert()
{
    NhanVien *nv = new NhanVien;
    cin >> *nv;
    string ho = nv->getHoDemNV();   HamChuanHoa(ho);    nv->setHoDemNV(ho);
    string ten = nv->getTenNV();    HamChuanHoa(ten);   nv->setTenNV(ten);
    databaseNV.push_back(nv);
    this->lengthNV++;
    cout << "\t\t\t\t\t\tThem nhan vien thanh cong!" << endl;
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
        << databaseNV[i]->getDiaChi() << ", " << databaseNV[i]->getChucVu() << ", " << (size_t)databaseNV[i]->getLuong() 
        << ", " << databaseNV[i]->getCheckDelete() << ", " << databaseNV[i]->getNgayVao();
        if (databaseNV[i]->getCheckDelete() == "Da Xoa") fileout << ", " << databaseNV[i]->getNgayNghi();  
    }
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}
void QuanLyNV::Find()
{
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Tim theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Tim theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    int luachon = Lua_chon();
    if (luachon == 1){
        cout << "\t\t\t\t\t\tMa can tim:";      int maNV = Nhap_ma();
        int n = FindIndex(maNV);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t"<< "|Ma NV|" << setw(21) << "Ho ten nhan vien  |" << setw(9) << "Gioi tinh|" << setw(11) 
            << "Ngay sinh|"<< setw(14) << "SDT     |" <<  setw(20) << "Dia chi     |"<< setw(10) << "Chuc vu |" << setw(10)  << "Luong  |" 
            << setw(10)  << "Ngay vao  |" << setw(11) << "Trang thai|";
            cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------";
            cout << *databaseNV[n] << setw(10) << databaseNV[n]->getCheckDelete() << "|";
            cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
        }
    }else if (luachon == 2)
    {
        string tenNV;
        cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten: ";    getline(cin,tenNV);
        HamChuanHoa(tenNV);
        if (FindIndexTen(tenNV) == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t"<< "|Ma NV|" << setw(21) << "Ho ten nhan vien  |" << setw(9) << "Gioi tinh|" << setw(11) << "Ngay sinh|" << setw(14) 
            << "SDT     |" <<  setw(20) << "Dia chi     |"<< setw(10) << "Chuc vu |" << setw(10)  << "Luong  |" << setw(10)  << "Ngay vao  |" 
            << setw(11) << "Trang thai|";
            cout << "\n\t\t\t------------------------------------------------------------------------------------------------------------------";
            for (int i = 0; i < this->lengthNV; i++)
            {
                if (databaseNV[i]->getTenNV() == tenNV) cout << *databaseNV[i] << setw(10) << databaseNV[i]->getCheckDelete() << "|";      
            }
            cout << "\n\t\t\t------------------------------------------------------------------------------------------------------------------" << endl;
        }
    } else{
        cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat!" << endl;
        return;
    }
}
int QuanLyNV::FindIndex(const int& index){
    for (int i = 0; i < this->lengthNV; i++)
    {
        if (databaseNV[i]->getMaNV() == index) return i;
    }
    return -1;
}
int QuanLyNV::FindIndexTen(const string& index){
    for (int i = 0; i < this->lengthNV; i++)
    {
        if (databaseNV[i]->getTenNV() == index) return i;
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
            Show(0);
            break;
        }
        case 2:
        {
            selectionsortTen(up);
            Show(0);
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
    cout << "\n\t\t\t\t\t\t|\t7. Khoi phuc trang thai\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t|";
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    int luachon = Lua_chon(); 

    if (luachon == 0){
        return;
    } else if (luachon < 0 || luachon > 7){
        cout << "\t\t\t\t\t\tLua chon khong hop le!";
        return;
    }
    else{
        if (luachon != 7) Show(0);
        else Show(1);
        int nv; cout << "\n\t\t\t\t\t\tMa so nhan vien can cap nhat: ";
        nv = Nhap_ma();
        int n = FindIndex(nv);
        // Kiem tra xem ma co ton tai khong (neu chon khoi phuc ma thi xem ban dau ma da xoa chua)
        if (luachon != 7){
            if (n == -1 || databaseNV[n]->getCheckDeleteSo() == 1){
                cout << "\t\t\t\t\t\tMa khong ton tai hoac da xoa!" << endl;
                return;
            }
        }else{
            if (n == -1 || databaseNV[n]->getCheckDeleteSo() == 0){
                cout << "\t\t\t\t\t\tKhong ton tai nhan vien da xoa nhu tren!" << endl;
                return;
            }
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
                Date ngaysinh(0, 0, 0);
                cout << "\t\t\t\t\t\tNhap ngay sinh nhan vien: ";   ngaysinh.Input();
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
                    cout << "\n\t\t\t\t\t\t 0. Quan ly"; 
                    cout << "\n\t\t\t\t\t\t 1. Nhan vien"; 
                    chucvu = Lua_chon();
                }while(chucvu != 0 && chucvu != 1);
                databaseNV[n]->setChucVu(chucvu);
                databaseNV[n]->setLuong();
                break;
            }
            case 7:
            {
                databaseNV[n]->setCheckDelete(0);
                break;
            }
            default:
            {
                break;
            } 
        }
        cout << "\n\t\t\t\t\t\tCap nhat thanh cong!" << endl;
    }
}
void QuanLyNV::Remove()
{
    int manv;
    Show(0);
    cout << "\t\t\t\t\t\tMa can xoa: ";   manv = Nhap_ma();
    int n = FindIndex(manv);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    else{
        this->databaseNV[n]->setNgayNghi();
        this->databaseNV[n]->setCheckDelete(1);
        cout << "\t\t\t\t\t\tXoa nhan vien thanh cong!" << endl;
    }
}
