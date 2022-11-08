#include <string>
#pragma once
using namespace std;
class PhanLoai{
    private:
        int static count_id;
        int maPL;
        string tenPL;
    public:
    // Ham getter
        string getTenPL();
        int getMaPL();
    // Ham setter
        void setTenPL(string);
        void setMaPL(int);
    // Ham constructor
        PhanLoai(int = -1, string = "");
    // Ham desstructor
        ~PhanLoai();
        friend istream& operator>>(istream&, PhanLoai&);
        friend ostream& operator<<(ostream&, const PhanLoai&);
};