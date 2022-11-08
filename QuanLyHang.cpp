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
    Show();
    ShowPL();
    // kiem tra ma va ten hang hoa co trung khong
    string tenHH;
    cin.ignore();
    cout << "\t\t\t\t\t\tNhap ten hang hoa moi: ";  getline(cin, tenHH);
    HamChuanHoa(tenHH);
    if (FindIndexTen(tenHH) != -1)
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
        // Kiem tra ten hang hoa co trung khong 
        if (FindIndex(maHH) != -1 && FindIndexTen(tenHH) != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << maHH << " va ten hang hoa " << tenHH << " da ton tai"<< endl;
            continue;
        }
        else if (FindIndex(maHH) != -1)
        {
            cout << "\t\t\t\t\t\tMa hang hoa " << maHH << " da ton tai" << endl;
            continue;
        }
        else if (FindIndexTen(tenHH) != -1)
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


void QuanLyHang::Remove(QuanLyHD& ql_hd)
{
    cout << "\n\t\t\t\t\t\t---------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Xoa theo ma\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Xoa theo ten\t\t|";
    cout << "\n\t\t\t\t\t\t---------------------------------";
    int luachon = Lua_chon();

    if (luachon == 1){
        int maHH;
        Show();
        cout << "\t\t\t\t\t\tMa can xoa: ";   maHH = Nhap_ma();
        int n = FindIndex(maHH);
        if (n == -1){
            cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
            return;
        }
        if (ql_hd.FindIndexHD(maHH) != -1){
        cout << "\t\t\t\t\t\tHang hoa da duoc dang ki boi hoa don. Khong the xoa!" << endl;
        return;
        }
        else{
            databaseK.erase(n);
            this->lengthK--;
            cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
        }
    } 
    if (luachon == 2){
        string tenHH;
        Show();
        cin.ignore(); 
        cout << "\t\t\t\t\t\tNhap ten hang hoa: ";  getline(cin,tenHH);
        int n = FindIndexTen(tenHH);
        HamChuanHoa(tenHH);
        if (n == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }
        // tim ma so cua hang hoa tren, neu ma duoc dang ki thi khong xoa duoc
        int maHH = databaseK[n]->getMaHH(); 
        if (ql_hd.FindIndexHH(maHH) != -1){
        cout << "\t\t\t\t\t\tHang hoa da duoc dang ki boi hoa don. Khong the xoa!" << endl;
        return;
        }
        else{
            databaseK.erase(FindIndexTen(tenHH));
            lengthK--;
            cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
        }
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
                cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
                << "Gia Ban|" << setw(9) << "So luong|" << setw(10) << "Phan loai|";
                cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
                cout << *databaseK[n];
                cout << "\t\t\t-----------------------------------------------------------------------------------------------" << endl;
        }
    }else if (luachon == 2)
    {
        string tenHH;
        cin.ignore();
        cout << "\t\t\t\t\t\tNhap ten: ";    getline(cin,tenHH);
        HamChuanHoa(tenHH);
        int n = FindIndexTen(tenHH);
        if ( n == -1){
            cout << "\t\t\t\t\t\tTen khong ton tai!" << endl;
            return;
        }else{
            cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
            << "Gia Ban|" << setw(9) << "So luong|" << setw(10) << "Phan loai|";
            cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
            cout << *databaseK[n];
            cout << "\t\t\t-----------------------------------------------------------------------------------------------" << endl;
        }
    } else return;
}
void QuanLyHang::Update(){
    system("cls");
    cout << "\n\t\t\t\t\t\t-----------------------------------------";
    cout << "\n\t\t\t\t\t\t|\t1. Cap nhat ten\t\t\t|";
    cout << "\n\t\t\t\t\t\t|\t2. Cap nhat phan loai\t\t|";
    cout << "\n\t\t\t\t\t\t|\t3. Cap nhat gia von\t\t|";
    cout << "\n\t\t\t\t\t\t|\t4. Cap nhat gia ban\t\t|";
    cout << "\n\t\t\t\t\t\t|\t5. Cap nhat so luong\t\t|";
    cout << "\n\t\t\t\t\t\t|\t0. Thoat\t\t\t|";
    cout << "\n\t\t\t\t\t\t-----------------------------------------" << endl;
    int luachon = Lua_chon(); 

    if (luachon == 0){
        return;
    }else{
        Show();
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
                ShowPL();
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
                cout << "\t\t\t\t\t\tNhap gia von moi: ";
                cin >> giavon;
                databaseK[n]->setGiaVon(giavon);
                break;
            }
            case 4:
            {
                double giaban;
                cout << "\t\t\t\t\t\tNhap gia ban moi: ";
                cin >> giaban;
                databaseK[n]->setGiaBan(giaban);
                break;
            }
            case 5:
            {
                int soluong;
                cout << "\t\t\t\t\t\tNhap so luong moi: ";
                cin >> soluong;
                databaseK[n]->setSoLuong(soluong);
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
void QuanLyHang::Show()
{   
    cout << "\n\t\t\t\t\t\t\tDANH SACH CAC MAT HANG";
    cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t" << setw(10) << "| Ma Hang|" << setw(20) <<  "Ten Hang|" << setw(15) << "Gia Von|" << setw(15) 
    << "Gia Ban|" << setw(10) << "So luong|" << setw(10) << "Phan loai|";
    cout << "\n\t\t\t----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < this->getLengthK(); i++)
    {
        cout << *databaseK[i];
    }
    cout << "\t\t\t-----------------------------------------------------------------------------------------------" << endl;
}

void QuanLyHang::Writef(){
    ofstream fileout;
    fileout.open("Kho.txt");
    for (int i = 0; i < this->getLengthK(); i++)
    {
        if (i != 0) fileout << endl;
        fileout << databaseK[i]->getMaHH() << ", " <<  databaseK[i]->getTenHH() << ", " << setprecision(10) <<  databaseK[i]->getGiaVon() 
        << ", " << databaseK[i]->getGiaBan() << ", " << databaseK[i]->getSoLuong() << ", "<< databaseK[i]->getmaPL();
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
            Show();
            break;
        }
        case 2:
        {
            selectionsortGiaBan(up);
            Show();
            break;
        }
        case 3:
        {
            selectionsortGiaVon(down);
            Show();
            break;
        }
        case 4:
        {
            selectionsortGiaVon(up);
            Show();
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

        filein >> maPL;
        filein.ignore();
        getline(filein, tenPL);
        HamChuanHoa(tenPL);
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
    ShowPL();
    PhanLoai *pl = new PhanLoai;
    cin >> *pl;

    if (FindIndexTenPL(pl->getTenPL()) != -1)
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
    ShowPL();
    cout << "\t\t\t\t\t\tMa phan loai: ";   maPL = Nhap_ma();
    if (FindIndexPL(maPL) == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    } else{
        if (FindIndexDM(maPL) != -1)
        {
            cout << "\t\t\t\t\t\tPhan loai da duoc dang ki boi hang hoa. Khong the xoa!" << endl;
            return;
        }
        databasePL.erase(FindIndexPL(maPL));
        this->lengthPL--;
        cout << "\t\t\t\t\t\tXoa thanh cong!" << endl;
    }
}

void QuanLyHang::WritefPL(){
    ofstream fileout;
    fileout.open("PhanLoai.txt");
    for (int i = 0; i < this->getLengthPL(); i++)
    {
        if (i != 0) fileout << endl;
        fileout << databasePL[i]->getMaPL() << ", " << databasePL[i]->getTenPL();
    }
    cout << "\t\t\t\t\t\tGhi vao file thanh cong!" << endl;
    fileout.close();
}

void QuanLyHang::ShowPL(){
    cout << "\n\t\t\t\t\t\t\t      DANH SACH CAC PHAN LOAI";
    cout << "\n\t\t\t\t\t\t\t -----------------------------";
    cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
    cout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
    for (int i = 0; i < this->getLengthPL(); i++)
    {
        cout << *databasePL[i];
    }
    cout << "\t\t\t\t\t\t\t -----------------------------" << endl;
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
            cout << "\n\t\t\t\t\t\t\t -----------------------------";
            cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
            cout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
            cout << *databasePL[n];
            cout << "\t\t\t\t\t\t\t -----------------------------" << endl;
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
            cout << "\n\t\t\t\t\t\t\t -----------------------------";
            cout << "\n\t\t\t\t\t\t\t" << setw(15) << "|Ma Phan Loai|" << setw(15) <<  "Ten Phan Loai|";
            cout << "\n\t\t\t\t\t\t\t -----------------------------" << endl;
            cout << *databasePL[n];
            cout << "\t\t\t\t\t\t\t -----------------------------" << endl;
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
    ShowPL();
    cout << "\t\t\t\t\t\tMa so phan loai can cap nhat: ";   maPL = Nhap_ma();
    if (FindIndexPL(maPL) == -1){
        cout << "\t\t\t\t\t\tMa khong ton tai!" << endl;
        return;
    }
    string tenPL;
    cout << "\t\t\t\t\t\tNhap ten phan loai moi: ";
    cin.ignore(); getline(cin, tenPL);
    HamChuanHoa(tenPL);
    while (FindIndexTen(tenPL) != -1){
        cout << "\t\t\t\t\t\tTen phan loai da ton tai. Nhap lai!";
        cout << "\n\t\t\t\t\t\tNhap ten hang hoa: ";
        cin.ignore(); getline(cin, tenPL);
        HamChuanHoa(tenPL);
    }
    databasePL[FindIndexPL(maPL)]->setTenPL(tenPL);
    cout << "\nCap nhat thanh cong!" << endl;
}