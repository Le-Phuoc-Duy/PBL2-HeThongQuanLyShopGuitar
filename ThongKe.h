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
        double luongNV, doanh_thu, loi_nhuan, von;
    public:
        int DemNgay(int, int);
        ThongKe();
        void ThongKeThang(QuanLyNV&, QuanLyHD&);
        void ThongKeNam(QuanLyNV&, QuanLyHD&);
        
};