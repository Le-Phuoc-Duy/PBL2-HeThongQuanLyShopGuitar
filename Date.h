#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Date{
    private:
        int ngay, thang, nam, gio, phut;      
    public:
    // Ham getter
        int getNgay();
        int getThang();
        int getNam();
        int getGio();
        int getPhut();
    // Ham setter
        void setNgay(int);      
        void setThang(int);       
        void setNam(int);   
        void setGio(int);   
        void setPhut(int);   
    //
    
    // Ham constructor

    Date();
    Date(int, int, int, int = 0, int = 0);
    // Date(int, int, int);

    // Ham destructor
    ~Date();
    // Ham da nang hoa
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
    void Input();
    // so sanh theo thang
    int operator== (Date);
    int operator!= (Date);
    int operator< (Date);
    int operator> (Date);
    friend bool HamThoiGian(const Date&);
};