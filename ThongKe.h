#pragma once
#include "QuanLy.h"
#include "List.h"
#include "HoaDon.h"
#include "QuanLyHang.h"
class QuanLyNV;
class QuanLyHD;
#include <ctime>
#include <Windows.h>
class ThongKe{
    private:
        double luongNV, doanh_thu, loi_nhuan, von;
    public:
        ThongKe();
        void ThongKeHomNay(QuanLyHD&);
        void ThongKeNgay(QuanLyNV&, QuanLyHD&);
        void ThongKeThang(QuanLyNV&, QuanLyHD&);
        void ThongKeNam(QuanLyNV&, QuanLyHD&);
};