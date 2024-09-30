#include<bits/stdc++.h>
using namespace std;

class Phanso {
	public:
		long long Tuso;
		long long Mauso;
		
		void Nhap(){ // Ham nhap vao tu va mau cua phan so
			cout << "Ban hay nhap tu so : "  << endl;
			cin >> Tuso;
			cout << "Ban hay nhap mau so : " << endl;
			cin >> Mauso;
		}
		
		void chuanhoa(){ // Viet lai phan so duoi dang phan so toi gian
			int d = __gcd(abs(Tuso), abs(Mauso));
			Tuso /= d;
			Mauso /= d;
			if(Mauso < 0){
				Tuso = -Tuso;
				Mauso = -Mauso;
			}
		}
		
		Phanso tong(const Phanso& ps) const{ // Ham tinh tong hai phan so
			Phanso ketqua;
			ketqua.Tuso = this->Tuso*ps.Mauso + ps.Tuso*this->Mauso;
			ketqua.Mauso = this->Mauso * ps.Mauso;
			ketqua.chuanhoa();
			return ketqua;
		}
		
		Phanso hieu(const Phanso& ps) const{ // Ham tinh hieu hai phan so
			Phanso ketqua;
			ketqua.Tuso = this->Tuso*ps.Mauso - ps.Tuso*this->Mauso;
			ketqua.Mauso = this->Mauso * ps.Mauso;
			ketqua.chuanhoa();
			return ketqua;
		}
		
		Phanso tich(const Phanso& ps) const{// Ham tinh tich hai phan so
			Phanso ketqua;
			ketqua.Tuso = this->Tuso * ps.Tuso;
			ketqua.Mauso = this->Mauso * ps.Mauso;
			ketqua.chuanhoa();
			return ketqua;
		}
		
		Phanso thuong(const Phanso& ps) const{// Ham tinh thuong hai phan so
			Phanso ketqua;
			ketqua.Tuso = this->Tuso * ps.Mauso;
			ketqua.Mauso = this->Mauso * ps.Tuso;
			ketqua.chuanhoa();
			return ketqua;
		}
		
		void Xuat(){
			cout << Tuso << "/" << Mauso << endl;
		}
		
};

int main(){
	Phanso ps1, ps2;
	cout << "Hay nhap phan so thu nhat : " << endl; 
	ps1.Nhap(); 
	cout << "Hay nhap phan so thu hai : " << endl; 
	ps2.Nhap();
	
	if(!ps1.Mauso || !ps2.Mauso){
		cout << "Khong the thuc hien cac phep tinh vi phan so khong the co mau bang 0." << endl;
		return 0;
	}
	
	
	
	ps1.chuanhoa();
	ps2.chuanhoa();
	
	Phanso cong = ps1.tong(ps2);
	Phanso tru = ps1.hieu(ps2);
	Phanso nhan = ps1.tich(ps2);
	
	
	cout << "Tong hai phan so: ";
    cong.Xuat();
    
    cout << "Hieu hai phan so: ";
    tru.Xuat();

    cout << "Tich hai phan so: ";
    nhan.Xuat();

    if(ps2.Tuso == 0) cout << "Khong the thuc hien phep chia khi phan so thu hai co tu so la 0." << endl;
	else{
		Phanso chia = ps1.thuong(ps2);
		cout << "Thuong hai phan so: ";
    	chia.Xuat();
	}

}
