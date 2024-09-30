#include<bits/stdc++.h>
using namespace std;

class Phanso{
	private:
		int Tuso;
		int Mauso;
	public:
        // Nhap vao tu so va mau so cua phan so
		void Nhap(){
			cout << "Ban hay nhap tu so : "  << endl;
			cin >> Tuso;
			cout << "Ban hay nhap mau so : " << endl;
			cin >> Mauso;
		}
        
		void Rutgon(){ // Rut gon phan so
			if(Mauso){
				int d = __gcd(abs(Tuso), abs(Mauso));
				Tuso /= d;
				Mauso /= d;
				if(Mauso < 0){
					Tuso = -Tuso;
					Mauso = -Mauso;
				}
			}
		}
		
		void Xuat(){ // In phan so ra man hinh
			if (Mauso == 0) cout << "Mau so khong the bang 0." << endl; 
			else cout << "Phan so sau khi da rut gon la : " << Tuso << "/" << Mauso;
		}
};

int main(){
	Phanso ps;
	ps.Nhap();
	ps.Rutgon();
	ps.Xuat();
}
