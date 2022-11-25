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
    cout << "\t\t\t\t\t\tNhap thang, nam can thong ke: ";
    while(1){
        try{
            string x;
            fflush(stdin); getline(cin, x);
            int n = x.length();
            month = year = 0;
            int count = 0, count_pow = 1; int i = n - 1;
            for(int j = n - 1; j >= 0; --j){
                if (x[j] == '/') count++;
            }
            if (count != 1 || x[0] == '/') throw "";
            while (x[i] != '/' && i >= 0){
                if (x[i] < 48 || x[i] > 57) throw "";
                else year += (int)(x[i] - '0') * count_pow;
                count_pow *= 10;
                i--;
            }
            i--; count_pow = 1;
            while (i >= 0){
                if (x[i] < 48 || x[i] > 57) throw "";
                else month += (int)(x[i] - '0') * count_pow;
                count_pow *= 10;
                i--;
            }
            break;
        }
        catch(...) {
            cout << "\t\t\t\t\t\tThang nam phai nhap theo dinh dang mm/yyyy. Nhap lai: ";
        }
    }
    Date a(1,month,year);   //thoi gian nhap vao
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int yy = 1900 + ltm->tm_year;
    int mm = 1+ltm->tm_mon;
    Date b(1,mm,yy);    //thoi gian hien tai
    if (b < a){
        cout << "\t\t\t\t\t\tKhong co du lieu" << endl;
        return;
    }
    Date hientai(1,month,year);
    for(int j = 0; j < nv.getLengthNV();j++){
        
        int luong_theo_ngay = nv.databaseNV[j]->getLuong()/DemNgay(month,year);
        int ngayvao = nv.databaseNV[j]->getNgayVao().getNgay();
        int ngaynghi = nv.databaseNV[j]->getNgayNghi().getNgay();

        if (nv.databaseNV[j]->getNgayVao().getNgay() == 1
        &&nv.databaseNV[j]->getNgayVao() == hientai
        && nv.databaseNV[j]->getNgayNghi() != hientai){
            this->luongNV += nv.databaseNV[j]->getLuong();
        }
        else if (nv.databaseNV[j]->getNgayVao() == hientai 
        && nv.databaseNV[j]->getNgayNghi() != hientai){
            this->luongNV += luong_theo_ngay * (DemNgay(month,year) - ngayvao + 1);
        }else if(nv.databaseNV[j]->getNgayVao() == hientai 
        && nv.databaseNV[j]->getNgayNghi() == hientai){
            this->luongNV += luong_theo_ngay * (ngaynghi - ngayvao + 1);
        }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
        && nv.databaseNV[j]->getNgayNghi() == hientai){
            this->luongNV += luong_theo_ngay * ngaynghi;
        }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
        &&  hientai < nv.databaseNV[j]->getNgayNghi()
        && nv.databaseNV[j]->getNgayVao() < hientai){
            this->luongNV += nv.databaseNV[j]->getLuong();
        }else if(nv.databaseNV[j]->getCheckDeleteSo() == 0
        && nv.databaseNV[j]->getNgayVao() < hientai){
            this->luongNV += nv.databaseNV[j]->getLuong();
        }
    }
    for (int j = 0; j < hd.getLengthHD(); j++)
    {
        
        if (hd.databaseHD[j]->getTrangThaiSo() == 2 
        && hd.databaseHD[j]->getNgayLap() == hientai){
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

    cout << "\n" << setw(73) << " " << "BAO CAO THANG " << month << endl;
    cout << setw(47) << " ";for(int i = 1; i<=67;i++) cout << "-"; cout << endl;
    cout << setw(47) << " " << "|  Tong luong nhan vien (nghin)  |"<< setw(13) << " "<< left << setw(19) << round((this->luongNV / 1000)*10)/10 << "|" <<endl;
    cout << setw(47) << " ";for(int i = 1; i<=67;i++) cout << "-"; cout << endl;
    cout << setw(47) << " " << "|          Von (nghin)           |"<< setw(13) << " "<< left << setw(19) << round((this->von / 1000)*10)/10 << "|" <<endl;
    cout << setw(47) << " ";for(int i = 1; i<=67;i++) cout << "-"; cout << endl;
    cout << setw(47) << " " << "|       Doanh thu (nghin)        |"<< setw(13) << " "<< left << setw(19) << round((this->doanh_thu / 1000)*10)/10  << "|" <<endl;
    cout << setw(47) << " ";for(int i = 1; i<=67;i++) cout << "-"; cout << endl;
    cout << setw(47) << " " << "|       Loi nhuan (nghin)        |"<< setw(13) << " "<< left << setw(19) << round((this->loi_nhuan / 1000)*10)/10 << "|" <<endl;
    cout << setw(47) << " ";for(int i = 1; i<=67;i++) cout << "-"; cout << endl;  
}


/////////////////////////////////////////////////////////////////////////////////
void ThongKe::ThongKeNam(QuanLyNV& nv, QuanLyHD& hd){
    this->doanh_thu = 0;
    this->von = 0;
    this->loi_nhuan = 0;
    this->luongNV = 0;

    int year;
    cout << "\t\t\t\t\t\tNhap nam can thong ke: "; year = hd.In_double();
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int yy = 1900 + ltm->tm_year;   //nam hien tai
    if (year > yy){
        cout << "\t\t\t\t\t\tKhong co du lieu" << endl;
        return;
    }

    cout << "\n" << setw(72) << " " << "BAO CAO NAM " << year << endl;
    cout << setw(30) << " "; for(int i = 1; i<=99;i++) cout << "-"; cout << endl;
    cout << setw(30) << " " << "|          |" << " Tong luong nhan vien (nghin) |" <<"  Von (nghin)  |"<<" Doanh thu (nghin) |" <<" Loi nhuan (nghin) |" << endl;
    cout << setw(30) << " "; for(int i = 1; i<=99;i++) cout << "-"; cout << endl;

    int month;
    for (month = 1; month <= 12; month++){
        Date hientai(1,month,year);
        for(int j = 0; j < nv.getLengthNV();j++){
            
            int luong_theo_ngay = nv.databaseNV[j]->getLuong()/DemNgay(month,year);
            int ngayvao = nv.databaseNV[j]->getNgayVao().getNgay();
            int ngaynghi = nv.databaseNV[j]->getNgayNghi().getNgay();

            if (nv.databaseNV[j]->getNgayVao().getNgay() == 1
            &&nv.databaseNV[j]->getNgayVao() == hientai
            && nv.databaseNV[j]->getNgayNghi() != hientai){
                this->luongNV += nv.databaseNV[j]->getLuong();
            }
            else if (nv.databaseNV[j]->getNgayVao() == hientai 
            && nv.databaseNV[j]->getNgayNghi() != hientai){
                this->luongNV += luong_theo_ngay * (DemNgay(month,year) - ngayvao + 1);
            }else if(nv.databaseNV[j]->getNgayVao() == hientai 
            && nv.databaseNV[j]->getNgayNghi() == hientai){
                this->luongNV += luong_theo_ngay * (ngaynghi - ngayvao + 1);
            }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
            && nv.databaseNV[j]->getNgayNghi() == hientai){
                this->luongNV += luong_theo_ngay * ngaynghi;
            }else if(nv.databaseNV[j]->getCheckDeleteSo() == 1
            &&  hientai < nv.databaseNV[j]->getNgayNghi()
            && nv.databaseNV[j]->getNgayVao() < hientai){
                this->luongNV += nv.databaseNV[j]->getLuong();
            }else if(nv.databaseNV[j]->getCheckDeleteSo() == 0
            && nv.databaseNV[j]->getNgayVao() < hientai){
                this->luongNV += nv.databaseNV[j]->getLuong();
            }
        }
        for (int j = 0; j < hd.getLengthHD(); j++)
        {
            
            if (hd.databaseHD[j]->getTrangThaiSo() == 2 
            && hd.databaseHD[j]->getNgayLap() == hientai){
                this->doanh_thu = this->doanh_thu + hd.databaseHD[j]->getThanhTien();
            }
                
        }
        for (int j = 0; j < hd.getLengthHD(); j++)
        {
            if (hd.databaseHD[j]->getTrangThaiSo() == 1 
            && hd.databaseHD[j]->getNgayLap() == hientai)
                this->von = this->von + hd.databaseHD[j]->getThanhTien();
        }
        this->loi_nhuan = this->doanh_thu - this->von - this->luongNV;
        cout << setw(30) << " " <<"| Thang " << left << setw(3) << month <<"|"<< setw(12) << " "<< left << setw(18) << round((this->luongNV / 1000)*10)/10 << "|"
        << setw(5) << " "<< left << setw(10) << round((this->von / 1000)*10)/10 << "|"
        << setw(7) << " "<< left << setw(12) << round((this->doanh_thu / 1000)*10)/10 << "|"
        << setw(7) << " "<< left << setw(12) << round((this->loi_nhuan / 1000)*10)/10 << "|";
        cout << "\n" << setw(30) << " "; for(int i = 1; i<=99;i++) cout << "-"; cout << endl;
    }
}