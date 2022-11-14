#pragma once
#include "QuanLy.h"
#include "List.h"
#include "HoaDon.h"
#include "QuanLyHang.h"
#include "QuanLyNV.h"
#include "QuanLyHD.h"
#include <ctime>
class ThongKe{
    private:
        struct TaiChinh
        {
            double luongNV, doanh_thu, loi_nhuan, von;
        };
        struct TaiChinh tc[12];
        int year;
    public:
        ThongKe(QuanLyNV&, QuanLyHD&);
        ~ThongKe();
        ThongKe(double, double, double, double, int);
        void setYear(int);
        int getYear();

        friend class BaoCaoTaiChinh;
};