#include "ThongKe.h"
ThongKe::ThongKe(QuanLyNV &nv, QuanLyHD &hd)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    this->year = 1900 + ltm->tm_year;

    for(int i = 0; i<12;i++){
        tc[i].luongNV = 0;
        tc[i].doanh_thu = 0;
        tc[i].von = 0;
        tc[i].loi_nhuan = 0;
    }
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < nv.getLengthNV(); j++)
        {
            tc[i].luongNV += nv.databaseNV[j]->getLuong();
        }
        for (int j = 0; j < hd.getLengthHD(); j++)
        {
            if (hd.databaseHD[j]->getTrangThaiSo() == 2 
            && hd.databaseHD[j]->getNgayLap().getThang() == i + 1
            && hd.databaseHD[j]->getNgayLap().getNam() == this->year)
                tc[i].doanh_thu = tc[i].doanh_thu + hd.databaseHD[j]->getThanhTien();
        }
        for (int j = 0; j < hd.getLengthHD(); j++)
        {
            if (hd.databaseHD[j]->getTrangThaiSo() == 1 
            && hd.databaseHD[j]->getNgayLap().getThang() == i + 1
            && hd.databaseHD[j]->getNgayLap().getNam() == this->year)
                tc[i].von = tc[i].von + hd.databaseHD[j]->getThanhTien();
        }
        tc[i].loi_nhuan = tc[i].doanh_thu - tc[i].luongNV - tc[i].von;
    }
}
ThongKe::ThongKe(double luongNV, double loi_nhuan, double doanh_thu, double von,int year){
    this->tc->luongNV = luongNV;
    this->tc->loi_nhuan = loi_nhuan;
    this->tc->doanh_thu = doanh_thu;
    this->tc->von = von;
    this->year = year;
}

void ThongKe::setYear(int year){
    this->year = year;
}
int ThongKe::getYear(){
    return this->year;
}