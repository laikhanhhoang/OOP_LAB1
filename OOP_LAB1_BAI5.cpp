#include <bits/stdc++.h>
using namespace std;
vector<int> numberofday = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Ngay{
	private:
		int ngay, thang, nam;
	public:
		void Nhap(){
			cout << "Hay nhap ngay, thang, nam cua ngay ma ban muon tinh toan (moi so cach nhau mot dau cach)." << endl;
			cin >> ngay >> thang >> nam;
		}
		
		void Homtruoc(){
			if(this->ngay >= 2){
				cout << "Ngay truoc ngay nay la : ngay " << this->ngay - 1 << " thang " << this->thang << " nam " << this->nam << "." << endl;
				return;
			}
			
			set<int> s = {1,3,5,7,8,10,12};
			if(this->thang == 1){
				cout << "Ngay truoc ngay nay la : ngay " << 31 << " thang " << 12 << " nam " << this->nam - 1 << "." << endl;
				return;
			}
			if(this->thang == 3){
				if((this->nam % 4 == 0 && this->nam % 100 != 0) || (this->nam % 400 == 0)){
					cout << "Ngay truoc ngay nay la : ngay " << 29 << " thang " << 2 << " nam " << this->nam << "." << endl;
					return;
				}
					cout << "Ngay truoc ngay nay la : ngay " << 28 << " thang " << 2 << " nam " << this->nam << "." << endl;
					return;
			}
			if(s.count(this->thang - 1)){
				cout << "Ngay truoc ngay nay la : ngay " << 31 << " thang " << this->thang - 1 << " nam " << this->nam << "." << endl;
				return;
			}
			cout << "Ngay truoc ngay nay la : ngay " << 30 << " thang " << this->thang - 1 << " nam " << this->nam << "." << endl;
			return;
		}
		
		void Homsau() {
    		int dayofmonth;
    
    		if (((this->nam % 4 == 0 && this->nam % 100 != 0) || (this->nam % 400 == 0)) && this->thang == 2) 
        		dayofmonth = numberofday[this->thang] + 1;
    		else 
        		dayofmonth = numberofday[this->thang];

    		if (this->ngay < dayofmonth) {
        		cout << "Ngay sau ngay nay la: ngay " << this->ngay + 1 << " thang " << this->thang << " nam " << this->nam << "." << endl;
    		} else if (this->thang == 12) {
        		cout << "Ngay sau ngay nay la: ngay 1 thang 1 nam " << this->nam + 1 << "." << endl;
        		return;
    		} else {
        		cout << "Ngay sau ngay nay la: ngay 1 thang " << this->thang + 1 << " nam " << this->nam << "." << endl;
        		return;
    		}
		}
		
		void order(){
			int ans = 0;
			for(int i = 1; i < this->thang; i++){
				ans += numberofday[i];
				if(i == 2 && this->nam % 4 == 0) ans++;
			}
			ans += this->ngay;
			cout << "Ngay do la ngay thu " << ans << " trong nam." << endl;
		}

};


int main(){
		cout << "Bat dau vi du : " << endl;
		Ngay day;
		day.Nhap();
		day.Homtruoc();
		day.Homsau(); day.order();
		cout << "Ket thuc vi du." << endl;
		return 0;
}

