#include<bits/stdc++.h>
using namespace std;

class Phanso {
	public:
		int Tuso;
		int Mauso;
		
		void Nhap(){ // Nhap tu so va mau so cua phan so
			cout << "Ban hay nhap tu so : "  << endl;
			cin >> Tuso;
			cout << "Ban hay nhap mau so : " << endl;
			cin >> Mauso;
		}
		// Ham nay viet lai phan so co mau > 0
		void chuanhoa(){
			if(Mauso < 0){
				Tuso = -Tuso;
				Mauso = -Mauso;
			}
		}
		// Ham so sanh hai phan so
		bool lonhon(const Phanso& ps) const{
			return (this->Tuso * ps.Mauso) > (this->Mauso * ps.Tuso);
		}
		// Ham tra ve true neu 2 phan so bang nhau
		bool bangnhau(const Phanso& ps) const{
			return (this->Tuso * ps.Mauso) == (this->Mauso * ps.Tuso);
		}
		
		void Xuat(){ // In phan so ra man hinh
			cout << Tuso << "/" << Mauso << endl;
		}
};

int main(){
	Phanso ps1, ps2;
	cout << "Hay nhap phan so thu nhat : " << endl; 
	ps1.Nhap(); 
	cout << "Hay nhap phan so thu hai : " << endl; 
	ps2.Nhap();
	Phanso org1 = ps1, org2 = ps2;
	
	if(!ps1.Mauso || !ps2.Mauso){
		cout << "Khong the so sanh vi phan so khong the co mau bang 0." << endl;
		return 0;
	}
	
	
	
	ps1.chuanhoa();
	ps2.chuanhoa();
	
	if(ps1.bangnhau(ps2)){
		cout << "Hai phan so bang nhau." << endl;
		return 0;
	}
	
	cout << "Phan so lon hon la : ";
	if(ps1.lonhon(ps2)){
		org1.Xuat();
	} else org2.Xuat();
	
	return 0;
}

