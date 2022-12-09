#pragma once
#include <string>
#include <windows.h>
using namespace std;

class QuanLy
{
protected:
public:
    QuanLy();
    virtual ~QuanLy();
    virtual void Readf() = 0;
    virtual void Insert();
    virtual void Show();
    virtual void Update();
    virtual void Delete();
    virtual void Writef() = 0;

    void HamChuanHoa(string&);
    string& KiemTraSDT();
    int So_nguyen();
    int Nhap_ma();
    double In_double();
    void textcolor(int);
};

