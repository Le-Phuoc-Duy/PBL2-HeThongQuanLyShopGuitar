#include "QuanLyHang.h"
#include "QuanLyHD.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
// #include "Date.h"

/// ///// THAO TÁC VỚI KHO HANG

QuanLyHang::QuanLyHang()
{
    this->lengthK = 0;
    this->lengthPL = 0;
}
QuanLyHang::~QuanLyHang(){}

int QuanLyHang::getLengthK()
{
    return this->lengthK;
}

void QuanLyHang::setLengthK(int lengthK)
{
    this->lengthK = lengthK;
}


void QuanLyHang::Insert()
{
    Show(0);
    ShowPL(0);
    // kiem tra ma va ten hang hoa co trung khong
    string tenHH;
    cin.ignore();
    cout << "\t\t\t\t\t\tNhap ten hang hoa moi: ";  getline(cin, tenHH);
    HamChuanHoa(tenHH);
    int n = FindIndexTen(tenHH);
    if (n != -1 && databaseK[n]->getCheckDeleteSo() == 1){
        cout << "\t\t\t\t\t\tHang hoa da bi xoa. Hay cap nhat lai trang thai!" << endl;
        return;
    }
    if (n != -1)
    {
        cout << "\t\t\t\t\t\tHang hoa " << tenHH << " da ton tai" << endl;
        return;
    }
    // kiem tra ma hang hoa ton tai chua
    cout << "\t\t\t\t\t\tMa phan loai: ";     int maPL = Nhap_ma();
    if (FindIndexPL(maPL) == -1 ){
        int opt;
        cout << "\t\t\t\t\t\tMa phan loai chua ton tai! Ban muon them ma phan loai moi khong?";
        cout << "\n\t\t\t\t\t\t1. Co";
        cout << "\n\t\t\t\t\t\t0. Khong" << endl;
        opt = Lua_chon();

        if(opt == 0) return;
        else if (opt == 1){
        string tenPL ;  cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten phan loai: "; getline(cin, tenPL);
        HamChuanHoa(tenPL);

            while (FindIndexTenPL(tenPL) != -1){
                cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
                cout << "\n\t\t\t\t\t\tNhap ten phan loai: ";
                cin.ignore(); getline(cin, tenPL);
                HamChuanHoa(tenPL);
            }

        PhanLoai *pl = new PhanLoai(maPL, tenPL);
        databasePL.push_back(pl);
        int n = (this->lengthPL) + 1; this->setLengthPL(n);
        cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
        }
        else{
            cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat";
            return;
        }
    }
    Kho *kho = new Kho;
    kho->Input(*this, tenHH, maPL);
    databaseK.push_back(kho);
    this->lengthK++;
    cout << "\t\t\t\t\t\tThem hang hoa thanh cong!" << endl;
}

void QuanLyHang::Readf()
{
    ifstream filein;
    filein.open("Kho.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
        int maHH, so_luong, maPL;
        string tenHH;
        double gia_von, gia_ban;
        string check_delete_chuoi;  int check_delete;
    while (filein.eof() !=true)
    {
        filein >> maHH;
        filein.ignore();
        getline(filein, tenHH, ',');
        filein >> gia_von;
        filein.ignore();
        filein >> gia_ban;
        filein.ignore();
        filein >> so_luong;
        filein.ignore();
        filein >> maPL;
        filein.ignore();
        HamChuanHoa(tenHH);
        getline(filein, check_delete_chuoi);
        HamChuanHoa(check_delete_chuoi);
        // kiem tra bien check co hop le khong
        if (check_delete_chuoi == "Da Xoa") check_delete = 1;
        else if (check_delete_chuoi == "Ton Tai") check_delete = 0;
        else{
            cout << "\n\t\t\t\t\t\tTrang thai hang hoa " << maHH << " khong hop le!" << endl;    
            continue;
        }
        // Kiem tra ten hang hoa co trung khong 
        int n = FindIndex(maHH), m = FindIndexTen(tenHH);
        if (n != -1 && m != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << maHH << " va ten hang hoa " << tenHH << " da ton tai"<< endl;
            continue;
        }
        else if (n != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << maHH << " da ton tai" << endl;
            continue;
        }
        else if (m != -1)
        {
            cout << "\t\t\t\t\t\tTen hang hoa " << tenHH << " da ton tai" << endl;
            continue;
        }
        // Kiem tra ma phan loai da ton tai chua
        if (FindIndexPL(maPL) == -1 ){
            int opt;
            cout << "\n\t\t\t\t\t\tMa phan loai " << maPL << " chua ton tai. Ban muon them ma phan loai nay khong?";
            cout << "\n\t\t\t\t\t\t1. Co";
            cout << "\n\t\t\t\t\t\t0. Khong";
            opt = Lua_chon();

            if(opt != 1) continue;
            else{
                string tenPL ;  cin.ignore();
                cout << "\t\t\t\t\t\tNhap ten phan loai: "; getline(cin, tenPL);
                HamChuanHoa(tenPL);

                while (FindIndexTenPL(tenPL) != -1){
                    cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
                    cout << "\n\t\t\t\t\t\tNhap ten phan loai: ";
                    cin.ignore(); getline(cin, tenPL);
                    HamChuanHoa(tenPL);
                }
                
                PhanLoai *pl = new PhanLoai(maPL, tenPL);
                databasePL.push_back(pl);
                this->lengthPL ++;
                cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
            }
        }

        Kho *kho = new Kho(maHH, tenHH, gia_von, gia_ban, so_luong, maPL);
        databaseK.push_back(kho);
        (this->lengthK)++;
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}

// Tìm kiếm hang hoa theo mã nhân viên
int QuanLyHang::FindIndex(const int &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->getMaHH() == index) return i;
    }
    return -1;
}

// Tìm kiếm hang hoa theo ten
int QuanLyHang::FindIndexTen(const string &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->getTenHH() == index)
            return i;
    }
    return -1;
}


void QuanLyHang::Remove()
{
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Xoa theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Xoa theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    int luachon = Lua_chon();

    if (luachon == 1){
        int maHH;
        Show(0);
        cout << "\t\t\t\t\t\tMa can xoa: ";   maHH = Nhap_ma();
        int n = FindIndex(maHH);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }
        this->databaseK[n]->setCheckDelete(1);
        cout << "\t\t\t\t\t\tXoa hang hoa thanh cong!" << endl;
    } 
    if (luachon == 2){
        string tenHH;
        Show(0);
        cin.ignore(); 
        cout << "\t\t\t\t\t\tNhap ten hang hoa: ";  getline(cin,tenHH);
        int n = FindIndexTen(tenHH);
        HamChuanHoa(tenHH);
        if (n == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }
        this->databaseK[n]->setCheckDelete(1);
        cout << "\t\t\t\t\t\tXoa hang hoa thanh cong!" << endl;
    }
    else {
        cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat!" << endl;
        return;
    }
}
void QuanLyHang::Find(){
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Tim theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Tim theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    int luachon = Lua_chon();
    if (luachon == 1){
        cout << "\t\t\t\t\t\tMa can tim: ";    int maHH = Nhap_ma();
        int n = FindIndex(maHH);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }else{
                cout << "\n\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
                << "Gia Ban|" << setw(9) << "So luong|" << setw(10) << "Phan loai|" << setw(11) << "Trang thai|";
                cout << "\n\t\t\t---------------------------------------------------------------------------------------------------------";
                cout << *databaseK[n] << setw(10) << databaseK[n]->getCheckDelete() << "|";
                cout << "\n\t\t\t----------------------------------------------------------------------------------------------------------" << endl;
        }
    }else if (luachon == 2)
    {
        string tenHH;
        cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten: ";    getline(cin,tenHH);
        HamChuanHoa(tenHH);
        int n = FindIndexTen(tenHH);
        if (n == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
            << "Gia Ban|" << setw(9) << "So luong|" << setw(10) << "Phan loai|" << setw(11) << "Trang thai|";
            cout << "\n\t\t\t---------------------------------------------------------------------------------------------------------";
            if (databaseK[n]->getTenHH() == tenHH) cout << *databaseK[n] << setw(10) << databaseK[n]->getCheckDelete() << "|";    
            cout << "\n\t\t\t----------------------------------------------------------------------------------------------------------" << endl;
        }
    } else return;
}
void QuanLyHang::Update(){
    system("cls");
    Show(0);
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ten\t\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Cap nhat phan loai\t\t|";
    cout << "\n\t\t\t\t\t\t|\t3. Cap nhat gia von\t\t|";
    cout << "\n\t\t\t\t\t\t|\t4. Cap nhat gia ban\t\t|";
    cout << "\n\t\t\t\t\t\t|\t5. Cap nhat so luong\t\t|";
    cout << "\n\t\t\t\t\t\t|\t6. Khoi phuc trang thai\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t|";
    cout << "\n\t\t\t\t\t\t-----------------------------------------" << endl;
    int luachon = Lua_chon(); 

    if (luachon == 0){
        return;
    }else{
        if (luachon == 6) Show(1);
        int hh; cout << "\t\t\t\t\t\tMa so hang hoa can cap nhat: ";
        hh = Nhap_ma();
        int n = FindIndex(hh);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }
        switch (luachon){
            case 1:
            {
                string tenHH;
                cout << "\t\t\t\t\t\tNhap ten hang hoa moi: ";
                cin.ignore(); getline(cin, tenHH);
                HamChuanHoa(tenHH);
                databaseK[n]->setTenHH(tenHH);
                break;
            }
            case 2:
            {
                int maPL;
                ShowPL(0);
                cout << "\t\t\t\t\t\tNhap ma phan loai moi: ";
                cin >> maPL;
                if (FindIndexPL(maPL) == -1 ){
                    int opt;
                    cout << "\t\t\t\t\t\tMa phan loai chua ton tai! Ban muon them ma phan loai moi khong?";
                    cout << "\n\t\t\t\t\t\t1. Co";
                    cout << "\n\t\t\t\t\t\t0. Khong" << endl;
                    opt = Lua_chon();

                    if(opt == 0) return;
                    else if (opt == 1){
                        string tenPL ;  cin.ignore();
                        cout << "\t\t\t\t\t\tNhap ten phan loai: "; getline(cin, tenPL);
                        HamChuanHoa(tenPL);

                        while (FindIndexTenPL(tenPL) != -1){
                            cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
                            cout << "\n\t\t\t\t\t\tNhap ten phan loai: ";
                            cin.ignore(); getline(cin, tenPL);
                            HamChuanHoa(tenPL);
                        }
                
                        PhanLoai *pl = new PhanLoai(maPL, tenPL);
                        databasePL.push_back(pl);
                        int n = (this->lengthPL) + 1; this->setLengthPL(n);
                        cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
                    }
                    else{
                        cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat";
                        return;
                    }
                }
                databaseK[n]->setMaPL(maPL);
                break;
            }
            case 3:
            {
                double giavon;
                cout << "\t\t\t\t\t\tNhap gia von moi: "; giavon = In_double();
                databaseK[n]->setGiaVon(giavon);
                break;
            }
            case 4:
            {
                double giaban;
                cout << "\t\t\t\t\t\tNhap gia ban moi: "; giaban = In_double();
                databaseK[n]->setGiaBan(giaban);
                break;
            }
            case 5:
            {
                int soluong;
                cout << "\t\t\t\t\t\tNhap so luong moi: "; soluong = In_double();
                databaseK[n]->setSoLuong(soluong);
                break;
            }
            case 6:
            {
                databaseK[n]->setCheckDelete(0);
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
void QuanLyHang::Show(int trang_thai)
{   
    cout << "\n\t\t\t\t\t\t\tDANH SACH CAC MAT HANG";
    cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
    << "Gia Ban|" << setw(10) << "So luong|" << setw(10) << "Phan loai|";
    cout << "\n\t\t\t----------------------------------------------------------------------------------------------";
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->getCheckDeleteSo() == trang_thai) cout << *databaseK[i];
    }
    cout << "\n\t\t\t-----------------------------------------------------------------------------------------------" << endl;
}

void QuanLyHang::Writef(){
    ofstream fileout;
    fileout.open("Kho.txt");
    for (int i = 0; i < this->getLengthK(); i++)
    {
        if (i != 0) fileout << endl;
        fileout << databaseK[i]->getMaHH() << ", " <<  databaseK[i]->getTenHH() << ", " << setprecision(10) <<  databaseK[i]->getGiaVon() 
        << ", " << databaseK[i]->getGiaBan() << ", " << databaseK[i]->getSoLuong() << ", "<< databaseK[i]->getmaPL()<< ", " 
        << databaseK[i]->getCheckDelete();
    }
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}
bool up(double x, double y)
{
    return (x > y) ? true : false;
}
bool down(double x, double y)
{
    return (x < y) ? true : false;
}

void QuanLyHang::selectionsortGiaBan(bool (*cmp)(double,double)){
    for(int i = 0; i< this->lengthK-1;i++){
        for (int j = i + 1; j < this->lengthK; j++){
            if (cmp(databaseK[i]->getGiaBan(),databaseK[j]->getGiaBan())){
                swap(databaseK[i],databaseK[j]);
            }
        }
    }
}
void QuanLyHang::selectionsortGiaVon(bool (*cmp)(double,double)){
    for(int i = 0; i< this->lengthK-1;i++){
        for (int j = i + 1; j < this->lengthK; j++){
            if (cmp(databaseK[i]->getGiaVon(),databaseK[j]->getGiaVon())){
                swap(databaseK[i],databaseK[j]);
            }
        }
    }
}
void QuanLyHang::Sort(){
    system("cls");
    cout << "\n\t\t\t\t\t\t---------------------------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Sap xep theo chieu giam cua gia ban\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Sap xep theo chieu tang cua gia ban\t\t|";
    cout << "\n\t\t\t\t\t\t|\t3. Sap xep theo chieu giam cua gia von\t\t|";
    cout << "\n\t\t\t\t\t\t|\t4. Sap xep theo chieu tang cua gia von\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------------------------------" << endl;
    int luachon = Lua_chon();
    switch(luachon){
        case 0:
        {
            break;
        }
        case 1:
        {
            selectionsortGiaBan(down);
            Show(0);
            break;
        }
        case 2:
        {
            selectionsortGiaBan(up);
            Show(0);
            break;
        }
        case 3:
        {
            selectionsortGiaVon(down);
            Show(0);
            break;
        }
        case 4:
        {
            selectionsortGiaVon(up);
            Show(0);
            break;
        }
        default:
        {
            cout << "\t\t\t\t\t\tLua chon khong hop le!";
            break;

        }
    }
}
int QuanLyHang::FindIndexDM(const int &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->getmaPL() == index)
            return i;
    }
    return -1;
}
int QuanLyHang::FindIndexTenDM(const string &index)
{
    for (int i = 0; i < this->lengthK; i++)
    {
        if (databaseK[i]->getTenPL() == index)
            return i;
    }
    return -1;
}

///// THAO TAC VOI PHAN LOAI HANG
int QuanLyHang::getLengthPL() { return this->lengthPL;}
void QuanLyHang::setLengthPL(int lengthPL){ this->lengthPL = lengthPL;}

void QuanLyHang::ReadfPL(){
    ifstream filein;
    filein.open("PhanLoai.txt");

    if (!filein)
    {
        cout << "\n\t\t\t\t\t\tLoi: File khong mo duoc." << endl;
        return;
    }
    
    while (filein.eof() != true)
    {
        int maPL;
        string tenPL;
        string check_delete_chuoi;      int check_delete;
        filein >> maPL;
        filein.ignore();
        getline(filein, tenPL, ',');
        HamChuanHoa(tenPL);
        getline(filein, check_delete_chuoi);
        HamChuanHoa(check_delete_chuoi);
        // kiem tra bien check co hop le khong
        if (check_delete_chuoi == "Da Xoa") check_delete = 1;
        else if (check_delete_chuoi == "Ton Tai") check_delete = 0;
        else{
            cout << "\n\t\t\t\t\t\tTrang thai phan loai " << maPL << " khong hop le!" << endl;    
            continue;
        }
        if (FindIndexPL(maPL) != -1 && FindIndexTenPL(tenPL) != -1)
        {
            cout << "\t\t\t\t\t\tMa phan loai " << maPL << " va ten phan loai " << tenPL << " da ton tai" << endl;
            continue;
        }
        else if (FindIndexPL(maPL) != -1)
        {
            cout << "\t\t\t\t\t\tMa phan loai " << maPL << " da ton tai" << endl;
            continue;
        }
        else if (FindIndexTenPL(tenPL) != -1)
        {
            cout << "\t\t\t\t\t\tTen phan loai " << tenPL << " da ton tai" << endl;
            continue;
        }

        PhanLoai *phan_loai = new PhanLoai(maPL, tenPL);
        databasePL.push_back(phan_loai);
        this->lengthPL++;
    }
    cout << "\n\t\t\t\t\t\tDoc file thanh cong!" << endl;
    filein.close();
}

void QuanLyHang::InsertPL(){
    ShowPL(0);
    PhanLoai *pl = new PhanLoai;
    cin >> *pl;
    int n = FindIndexTenPL(pl->getTenPL());
    if (n != -1 && databaseK[n]->getCheckDeleteSo() == 1){
        cout << "\t\t\t\t\t\tPhan loai da bi xoa. Hay cap nhat lai trang thai!" << endl;
        return;
    }
    if (n != -1)
    {
        cout << "\t\t\t\t\t\tTen phan loai " << pl->getTenPL() << " da ton tai" << endl;
        delete pl;
        return;
    }
    string ten = pl->getTenPL();
    HamChuanHoa(ten)    ; pl->setTenPL(ten);
    databasePL.push_back(pl);
    this->lengthPL++;
    cout << "\t\t\t\t\t\tThem phan loai thanh cong!" << endl;
}
void QuanLyHang::RemovePL(){
    int maPL;
    ShowPL(0);
    cout << "\t\t\t\t\t\tMa phan loai: ";   maPL = Nhap_ma();
    int n = FindIndexPL(maPL);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    } else{
        this->databasePL[n]->setCheckDelete(1);
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
    }
}

void QuanLyHang::WritefPL(){
    ofstream fileout;
    fileout.open("PhanLoai.txt");
    for (int i = 0; i < this->getLengthPL(); i++)
    {
        if (i != 0) fileout << endl;
        fileout << databasePL[i]->getMaPL() << ", " << databasePL[i]->getTenPL() << ", " << databasePL[i]->getCheckDelete();
    }
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}

void QuanLyHang::ShowPL(int trang_thai){
    cout << "\n\t\t\t\t\t\t\t      DANH SACH CAC PHAN LOAI";
    cout << "\n\t\t\t\t\t\t\t -----------------------------";
    cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
    cout << "\n\t\t\t\t\t\t\t -----------------------------";
    for (int i = 0; i < this->lengthPL; i++)
    {
        if (databasePL[i]->getCheckDeleteSo() == trang_thai) cout << *databasePL[i];
    }
    cout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
}
void QuanLyHang::FindPL(){
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Tim theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Tim theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    int luachon = Lua_chon();

    if (luachon == 1){
        cout << "\t\t\t\t\t\tMa can tim:";
        int maPL = Nhap_ma();
        int n = FindIndexPL(maPL);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t\t\t\t\t ----------------------------------------";
            cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|" << setw(11) << "Trang thai|";
            cout << "\n\t\t\t\t\t\t\t ----------------------------------------";
            cout << *databasePL[n] << setw(10) << databasePL[n]->getCheckDelete() << "|";
            cout << "\n\t\t\t\t\t\t\t ----------------------------------------" << endl;
        }
    } else if (luachon ==  2)
    {
        string tenPL;
        cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten: ";    getline(cin,tenPL);
        HamChuanHoa(tenPL);
        int n = FindIndexTenPL(tenPL);
        if ( n == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t\t\t\t\t ---------------------------------------";
            cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|" << setw(11) << "Trang thai|";
            cout << "\n\t\t\t\t\t\t\t ---------------------------------------";
            cout << *databasePL[n] << setw(10) << databasePL[n]->getCheckDelete() << "|";
            cout << "\n\t\t\t\t\t\t\t ---------------------------------------" << endl;
        }
    }else{
        cout << "\t\t\t\t\t\tLua chon khong hop le. Thoat!" << endl; 
        return;
    }
    
}

int QuanLyHang::FindIndexPL(const int &index)
{
    for (int i = 0; i < this->lengthPL; i++)
    {
        if (databasePL[i]->getMaPL() == index)
            return i;
    }
    return -1;
}
int QuanLyHang::FindIndexTenPL(const string &index)
{
    for (int i = 0; i < this->lengthPL; i++)
    {
        if (databasePL[i]->getTenPL() == index)
            return i;
    }
    return -1;
}
void QuanLyHang::UpdatePL(){
    int maPL; 
    ShowPL(0);
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ten\t\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Khoi phuc trang thai\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t|";
    cout << "\n\t\t\t\t\t\t-----------------------------------------" << endl;
    int luachon = Lua_chon();
    if (luachon == 0) return;
    if (luachon == 2) ShowPL(1);
    cout << "\t\t\t\t\t\tMa so phan loai can cap nhat: ";   maPL = Nhap_ma();
    int n = FindIndexPL(maPL);
    if (n == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    switch (luachon)
    {
    case 1:
    {
        string tenPL;
        cout << "\t\t\t\t\t\tNhap ten phan loai moi: ";
        cin.ignore(); getline(cin, tenPL);
        HamChuanHoa(tenPL);
        if (FindIndexTen(tenPL) != -1){
        cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
        cout << "\n\t\t\t\t\t\tNhap ten hang hoa: ";
        cin.ignore(); getline(cin, tenPL);
        HamChuanHoa(tenPL);
        }
        databasePL[FindIndexPL(maPL)]->setTenPL(tenPL);
        break;
    }
    case 2:
    {
        databasePL[n]->setCheckDelete(0);
        break;
    }
    default:
        break;
    }
    cout << "\nCap nhat thanh cong!" << endl;
}