#include "QuanLyKH.h"
#include "QuanLyHD.h"
#include <fstream>
#include <iostream>
#include <iomanip>

QuanLyKH::QuanLyKH()
{
    this->lengthKH = 0;
}

QuanLyKH::~QuanLyKH() {}

int QuanLyKH::getLengthKH()
{
    return this->lengthKH;
}
void QuanLyKH::setLengthKh(int length)
{
    this->lengthKH = length;
}
// Tìm kiếm khach hang theo mã KH
int QuanLyKH::FindIndex(const int &index)
{
    for (int i = 0; i < this->lengthKH; i++)
    {
        if (databaseKH[i]->getMaKH() == index)
            return i;
    }
    return -1;
}

// Tìm kiếm khach hang theo tên KH
int QuanLyKH::FindIndexTen(const string &index)
{
    for (int i = 0; i < this->lengthKH; i++)
    {
        if (databaseKH[i]->getTenKH() == index)
            return i;
    }
    return -1;
}
// Tìm kiếm khach hang theo sdt
int QuanLyKH::FindIndexSDT(const string &index)
{
    for (int i = 0; i < this->lengthKH; i++)
    {
        if (databaseKH[i]->getSDT() == index)
            return i;
    }
    return -1;
}
void QuanLyKH::Insert()
{
    KhachHang *khachhang = new KhachHang;
    cin >> *khachhang;
    // kiem tra so dien thoai khach hang co trung khong
    if (FindIndexSDT(khachhang->getSDT()) != -1)
    {
        cout << "\n\t\t\t\t\t\tSo dien thoai da ton tai" << endl;
        return;
    }
    string ten = khachhang->getTenKH();
    HamChuanHoa(ten);
    khachhang->setTenKH(ten);

    databaseKH.push_back(khachhang);
    this->lengthKH++;
    cout << "\t\t\t\t\t\tThem khach hang thanh cong!" << endl;
}

void QuanLyKH::Readf()
{
    ifstream filein;
    filein.open("KhachHang.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
    filein.seekg(0, ios::end);
    if (filein.tellg() == 0) return;
    filein.seekg(0, ios::beg);
    int maKH, so_diem;
    string tenKH, hodem, sdt;
    char x;
    string check_delete_chuoi; int check_delete;
    while (filein.eof() != true)
    {
        filein >> maKH;
        filein.ignore(2);
        getline(filein, hodem, ',');
        filein.ignore();
        getline(filein, tenKH, ',');
        filein.ignore();
        getline(filein, sdt, ',');
        filein.ignore();
        filein >> so_diem;
        filein.ignore(2);
        getline(filein, check_delete_chuoi);
        if (check_delete_chuoi == "Da Xoa") check_delete = 1;
        else if (check_delete_chuoi == "Ton Tai") check_delete = 0;
        HamChuanHoa(tenKH); HamChuanHoa(hodem);
        KhachHang *khachhang = new KhachHang(maKH, hodem, tenKH, sdt, so_diem, check_delete);
        databaseKH.push_back(khachhang);
        (this->lengthKH)++;
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}

void QuanLyKH::Show(int trang_thai)
{
    cout << "\n\t\t\t\t\t\t\t\tDANH SACH KHACH HANG";
    cout << "\n\t\t\t\t\t\t--------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t" << setw(10) << "| Ma Khach Hang|" << setw(9) << "Ten Khach Hang|" << setw(11) << " SDT|" << setw(5)
         << "So Diem|" << endl;
    cout << "\t\t\t\t\t\t--------------------------------------------------";

    for (int i = 0; i < this->getLengthKH(); i++)
    {
        if (databaseKH[i]->getCheckDeleteSo() == trang_thai) cout << *databaseKH[i];
    }
    cout << "\n\t\t\t\t\t\t--------------------------------------------------" << endl;
}
void QuanLyKH::Find()
{
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Tim theo SDT\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Tim theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    int luachon = Lua_chon();
    if (luachon == 1){
        string sdt = KiemTraSDT();
        int n = FindIndexSDT(sdt);
        if (n == -1)
        {
            cout << "\t\t\t\t\t\tSDT khong ton tai!" << endl;
            return;
        }
        else
        {
            cout << "\n\t\t\t\t\t\t------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t" << setw(10) << "| Ma Khach Hang|" << setw(9) << "Ten Khach Hang|" << setw(10) << " SDT|" << setw(5)
            << "So Diem|" << setw(11) << "Trang thai|";
            cout << "\n\t\t\t\t\t\t------------------------------------------------------------";
            cout << *databaseKH[n] << setw(10) << databaseKH[n]->getCheckDelete() << "|";
            cout << "\n\t\t\t\t\t\t------------------------------------------------------------" << endl;
        }
    }else if (luachon == 2)
    {
        string tenKH;
        cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten: ";    getline(cin,tenKH);
        HamChuanHoa(tenKH);
        if (FindIndexTen(tenKH) == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t\t\t\t------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t" << setw(10) << "| Ma Khach Hang|" << setw(9) << "Ten Khach Hang|" << setw(10) << " SDT|" << setw(5)
            << "So Diem|" << setw(11) << "Trang thai|";
            cout << "\n\t\t\t\t\t\t------------------------------------------------------------";
            for (int i = 0; i < this->lengthKH; i++)
            {
                if (databaseKH[i]->getTenKH() == tenKH) cout << *databaseKH[i] << setw(10) << databaseKH[i]->getCheckDelete() << "|";      
            }
            cout << "\n\t\t\t\t\t\t------------------------------------------------------------" << endl;    
        }
    } else{
        cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat!" << endl;
        return;
    }
}
void QuanLyKH::Writef()
{
    ofstream fileout;
    fileout.open("KhachHang.txt");
    for (int i = 0; i < this->getLengthKH(); i++)
    {
        if (i != 0) fileout << endl;
        fileout << databaseKH[i]->getMaKH() << ", " <<  databaseKH[i]->getHoDemKH() << ", "<<  databaseKH[i]->getTenKH() 
        << ", " << databaseKH[i]->getSDT() << ", " <<  databaseKH[i]->getSoDiem() << ", " << databaseKH[i]->getCheckDelete();
    }
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}

void QuanLyKH::Remove()
{
    int ma;
    Show(0);
    cout << "\t\t\t\t\t\tMa khach hang can xoa: "; ma = Nhap_ma();
    int n = FindIndex(ma);
    if (n == -1)
    {
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    else{
        this->databaseKH[n]->setCheckDelete(1);
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
    }
}

void QuanLyKH::Update(QuanLyHD& ql_hd){
    system("cls");
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ten\t\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Cap nhat so dien thoai\t|";
    cout << "\n\t\t\t\t\t\t|\t3. Khoi phuc trang thai\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t|";
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    int luachon = Lua_chon(); 
    if (luachon == 0){
        return;
    }else if (luachon < 0 || luachon > 3){
        cout << "\t\t\t\t\t\tLua chon khong hop le!";
        return;
    }
    else{
        if (luachon == 3) Show(1);
        else Show(0);
        int ma; 
        cout << "\n\t\t\t\t\t\tMa so khach hang can cap nhat: ";        ma = Nhap_ma();
        int n = FindIndex(ma);
        if (luachon != 3){
            if (n == -1 || databaseKH[n]->getCheckDeleteSo() == 1){
                cout << "\t\t\t\t\t\tMa khong ton tai hoac da xoa!" << endl;
                return;
            }
        }
        else{
            if (n == -1 || databaseKH[n]->getCheckDeleteSo() == 0){
                cout << "\t\t\t\t\t\tKhong ton tai khach hang da xoa nhu tren!" << endl;
                return;
            }
        }
        switch (luachon){
            case 1:
            {
                string ten, hodem;
                cin.ignore();
                cout << "\t\t\t\t\t\tNhap ho dem khach hang: ";  getline(cin, hodem);
                cout << "\t\t\t\t\t\tNhap ten khach hang: ";  getline(cin, ten);
                HamChuanHoa(ten);   HamChuanHoa(hodem);
                databaseKH[n]->setTenKH(ten);
                databaseKH[n]->setHoDemKH(hodem);
                break;
            }
            case 2:
            {
                string sdt = KiemTraSDT();
                while (FindIndexSDT(sdt) != -1){
                    cout << "\t\t\t\t\t\tSDT da ton tai. Nhap lai!" << endl;
                    sdt = KiemTraSDT();
                }
                // bien SDT luu SDT cu
                string SDT = databaseKH[FindIndex(ma)]->getSDT();
                databaseKH[n]->setSDT(sdt);
                // cap nhat so dien thoai moi trong danh sach hoa don
                int m = ql_hd.FindIndex(SDT);
                while (m != -1){
                    ql_hd.databaseHD[n]->setSDT(sdt);
                    m = ql_hd.FindIndex(SDT);
                }
                break;
            }
            case 3:
            {
                databaseKH[n]->setCheckDelete(0);
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
bool increase(string x, string y)
{
    return (x < y) ? true : false;
}
bool descrease(string x, string y)
{
    return (x > y) ? true : false;
}

void QuanLyKH::selectionsortTen(bool (*cmp)(string,string)){
    for(int i = 0; i < this->lengthKH - 1; i++){
        for (int j = i + 1; j < this->lengthKH; j++){
            if ((*cmp)(databaseKH[i]->getTenKH(), databaseKH[j]->getTenKH())){
                swap(databaseKH[i], databaseKH[j]);
            }
            if (databaseKH[i]->getTenKH() == databaseKH[j]->getTenKH()){
                if ((*cmp)(databaseKH[i]->getHoDemKH(), databaseKH[j]->getHoDemKH())){
                swap(databaseKH[i], databaseKH[j]);
            }
            }
        }
    }
}
void QuanLyKH::Sort()
{
    system("cls");
    cout << "\n\t\t\t\t\t\t------------------------------------------";
    cout << "\n\t\t\t\t\t\t|1. Sap xep ten khach hang theo chieu giam|";
    cout << "\n\t\t\t\t\t\t|2. Sap xep ten khach hang theo chieu tang|";
    cout << "\n\t\t\t\t\t\t------------------------------------------";
    int luachon = Lua_chon();
    switch(luachon){
        case 1:
        {
            selectionsortTen(descrease);
            Show(0);
            break;
        }
        case 2:
        {
            selectionsortTen(increase);
            Show(0);
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat!" << endl;
            break;

        }
    }
}