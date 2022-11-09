#include <string>
#pragma once
using namespace std;
class PhanLoai{
    private:
        int static count_id;
        int maPL;
        string tenPL;
        int check_delete;
    public:
    // Ham getter
        string getTenPL();
        int getMaPL();
        int getCheckDeleteSo();
        string getCheckDelete();
    // Ham setter
        void setTenPL(string);
        void setMaPL(int);
        void setCheckDelete(int);
    // Ham constructor
        PhanLoai(int = -1, string = "", int = 0);
    // Ham desstructor
        ~PhanLoai();
        friend istream& operator>>(istream&, PhanLoai&);
        friend ostream& operator<<(ostream&, const PhanLoai&);
};