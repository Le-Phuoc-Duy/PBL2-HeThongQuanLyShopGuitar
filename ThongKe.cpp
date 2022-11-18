#include "ThongKe.h"
int ThongKe::DemNgay(int month, int year){
    if (month == 2)
    {
        if ((year  % 400 == 0) || ( year % 4 == 0 && year % 100 != 0)) return 29;
        else return 28;
    }
    else{
        if (month == 1 || month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 ||month == 12 ) 
            return 31;
        else return 30;
    }
}
ThongKe::ThongKe(){
    this->doanh_thu = 0;
    this->von = 0;
    this->loi_nhuan = 0;
    this->luongNV = 0;
}

void ThongKe::ThongKeThang(QuanLyNV& nv, QuanLyHD& hd){
    this->doanh_thu = 0;
    this->von = 0;
    this->loi_nhuan = 0;
    this->luongNV = 0;

    int month, year;
    cout << "Nhap thang, nam can thong ke: "; cin >> month; cin.ignore(); cin >> year;
    Date a(1,month,year);   //thoi gian nhap vao
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int yy = 1900 + ltm->tm_year;
    int mm = 1+ltm->tm_mon;
    Date b(1,mm,yy);    //thoi gian hien tai
    if (b < a){
        cout << "Khong co du lieu";
        return;
    }
    Date hientai(1,month,year);
    cout << "Luong (ma, ten, luong): " << endl;
    for(int j = 0; j < nv.getLengthNV();j++){
        
        int luong_theo_ngay = nv.databaseNV[j]->getLuong()/DemNgay(month,year);
        int ngayvao = nv.databaseNV[j]->getNgayVao().getNgay();
        int ngaynghi = nv.databaseNV[j]->getNgayNghi().getNgay();

        if (nv.databaseNV[j]->getNgayVao().getNgay() == 1
        &&nv.databaseNV[j]->getNgayVao() == hientai
        && nv.databaseNV[j]->getNgayNghi() != hientai){
            cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << nv.databaseNV[j]->getLuong() << endl;
            this->luongNV += nv.databaseNV[j]->getLuong();
        }
        else if (nv.databaseNV[j]->getNgayVao() == hientai 
        && nv.databaseNV[j]->getNgayNghi() != hientai){
            cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << luong_theo_ngay * (DemNgay(month,year) - ngayvao + 1)<< endl;
            this->luongNV += luong_theo_ngay * (DemNgay(month,year) - ngayvao + 1);
        }else if(nv.databaseNV[j]->getNgayVao() == hientai 
        && nv.databaseNV[j]->getNgayNghi() == hientai){
            cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << luong_theo_ngay * (ngaynghi - ngayvao + 1)<< endl;
            this->luongNV += luong_theo_ngay * (ngaynghi - ngayvao + 1);
        }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
        && nv.databaseNV[j]->getNgayNghi() == hientai){
            cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << luong_theo_ngay * ngaynghi<< endl;
            this->luongNV += luong_theo_ngay * ngaynghi;
        }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
        &&  hientai < nv.databaseNV[j]->getNgayNghi()
        && nv.databaseNV[j]->getNgayVao() < hientai){
            cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << nv.databaseNV[j]->getLuong()<< endl;
            this->luongNV += nv.databaseNV[j]->getLuong();
        }else if(nv.databaseNV[j]->getCheckDeleteSo() == 0
        && nv.databaseNV[j]->getNgayVao() < hientai){
            cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << nv.databaseNV[j]->getLuong()<< endl;
            this->luongNV += nv.databaseNV[j]->getLuong();
        }
    }
    cout << "Hoa don ban(ma, thanh tien): " << endl;
    for (int j = 0; j < hd.getLengthHD(); j++)
    {
        
        if (hd.databaseHD[j]->getTrangThaiSo() == 2 
        && hd.databaseHD[j]->getNgayLap() == hientai){
            cout<< hd.databaseHD[j]->getMaHD() << " " << hd.databaseHD[j]->getThanhTien()<< endl;
            this->doanh_thu = this->doanh_thu + hd.databaseHD[j]->getThanhTien();
        }
            
    }
    for (int j = 0; j < hd.getLengthHD(); j++)
    {
        if (hd.databaseHD[j]->getTrangThaiSo() == 1 
        && hd.databaseHD[j]->getNgayLap() == hientai)
            this->von = this->von + hd.databaseHD[j]->getThanhTien();
    }
    this->loi_nhuan = this->doanh_thu - this->luongNV - this->von;
    cout << "Tong luong nhan vien: "<< setprecision(20)<< this->luongNV<<endl;
    cout << "Doanh thu: " << this->doanh_thu<<endl;
    cout << "Loi nhuan: " << this->loi_nhuan<< endl;    
}


/////////////////////////////////////////////////////////////////////////////////
void ThongKe::ThongKeNam(QuanLyNV& nv, QuanLyHD& hd){
    this->doanh_thu = 0;
    this->von = 0;
    this->loi_nhuan = 0;
    this->luongNV = 0;

    int year;
    cout << "Nhap nam can thong ke: "; cin >> year;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int yy = 1900 + ltm->tm_year;   //nam hien tai
    if (year > yy){
        cout << "Khong co du lieu";
        return;
    }

    int month;
    for (month = 1; month <= 12; month++){
        cout << "----------------------------------------"<< endl;
        Date hientai(1,month,year);
        cout << "Luong (ma, ten, luong) cua thang " << month << ": "<< endl;
        for(int j = 0; j < nv.getLengthNV();j++){
            
            int luong_theo_ngay = nv.databaseNV[j]->getLuong()/DemNgay(month,year);
            int ngayvao = nv.databaseNV[j]->getNgayVao().getNgay();
            int ngaynghi = nv.databaseNV[j]->getNgayNghi().getNgay();

            if (nv.databaseNV[j]->getNgayVao().getNgay() == 1
            &&nv.databaseNV[j]->getNgayVao() == hientai
            && nv.databaseNV[j]->getNgayNghi() != hientai){
                cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << nv.databaseNV[j]->getLuong() << endl;
                this->luongNV += nv.databaseNV[j]->getLuong();
            }
            else if (nv.databaseNV[j]->getNgayVao() == hientai 
            && nv.databaseNV[j]->getNgayNghi() != hientai){
                cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << luong_theo_ngay * (DemNgay(month,year) - ngayvao + 1)<< endl;
                this->luongNV += luong_theo_ngay * (DemNgay(month,year) - ngayvao + 1);
            }else if(nv.databaseNV[j]->getNgayVao() == hientai 
            && nv.databaseNV[j]->getNgayNghi() == hientai){
                cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << luong_theo_ngay * (ngaynghi - ngayvao + 1)<< endl;
                this->luongNV += luong_theo_ngay * (ngaynghi - ngayvao + 1);
            }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
            && nv.databaseNV[j]->getNgayNghi() == hientai){
                cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << luong_theo_ngay * ngaynghi<< endl;
                this->luongNV += luong_theo_ngay * ngaynghi;
            }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
            &&  hientai < nv.databaseNV[j]->getNgayNghi()
            && nv.databaseNV[j]->getNgayVao() < hientai){
                cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << nv.databaseNV[j]->getLuong()<< endl;
                this->luongNV += nv.databaseNV[j]->getLuong();
            }else if(nv.databaseNV[j]->getCheckDeleteSo() == 0
            && nv.databaseNV[j]->getNgayVao() < hientai){
                cout << nv.databaseNV[j]->getMaNV() << " " << nv.databaseNV[j]->getHoTenNV()<< " " << nv.databaseNV[j]->getLuong()<< endl;
                this->luongNV += nv.databaseNV[j]->getLuong();
            }
        }
        cout << "Hoa don ban(ma, thanh tien)cua thang " << month << ": "<< endl;
        for (int j = 0; j < hd.getLengthHD(); j++)
        {
            
            if (hd.databaseHD[j]->getTrangThaiSo() == 2 
            && hd.databaseHD[j]->getNgayLap() == hientai){
                cout<< hd.databaseHD[j]->getMaHD() << " " << hd.databaseHD[j]->getThanhTien()<< endl;
                this->doanh_thu = this->doanh_thu + hd.databaseHD[j]->getThanhTien();
            }
                
        }
        for (int j = 0; j < hd.getLengthHD(); j++)
        {
            if (hd.databaseHD[j]->getTrangThaiSo() == 1 
            && hd.databaseHD[j]->getNgayLap() == hientai)
                this->von = this->von + hd.databaseHD[j]->getThanhTien();
        }
    }
    this->loi_nhuan = this->doanh_thu - this->luongNV - this->von;
    cout << "--------------------------------------------" << endl;
    cout << "Tong luong nhan vien: "<< setprecision(20)<< this->luongNV<<endl;
    cout << "Doanh thu: " << this->doanh_thu<<endl;
    cout << "Loi nhuan: " << this->loi_nhuan<< endl;    
}