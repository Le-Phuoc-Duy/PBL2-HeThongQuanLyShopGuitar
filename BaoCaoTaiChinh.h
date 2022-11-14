#include "ThongKe.h"
class BaoCaoTaiChinh{
    private:
        List <ThongKe*> databaseBCTC;
        int lengthBCTC;
    public:
        BaoCaoTaiChinh();
        ~BaoCaoTaiChinh();
        int getLengthBCTC();
        void setLengthBCTC(int);
        void Readf();
        void Writef();
        
        void ThongKeThang(QuanLyNV&, QuanLyHD&);
        void ThongKeQuy(QuanLyNV&, QuanLyHD&);
        void ThongKeNam(QuanLyNV&, QuanLyHD&);
};