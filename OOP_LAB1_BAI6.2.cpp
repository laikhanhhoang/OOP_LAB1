#include<bits/stdc++.h>
using namespace std;

//Ham checkten kiem tra xem ten nhap vao co thoa man dinh dang hay khong
bool checkten(string s){
	int n = s.size();
	int sodaucach = 0, chusaudaucach = 0;
	bool check = true;
	if(int(s[0]) < 65 || int(s[0]) > 90) check = false;
	for(int i = 1; i < n; i++){
		if(int(s[i-1]) == 32){
			if(int(s[i]) < 65 || int(s[i]) > 90){
				check = false;
			}
			else chusaudaucach = 1;
		}
		else if(int(s[i]) == 32){
			sodaucach = 1;
		}
		else if(s[i] < 97 || s[i] > 122) check = false;
	}
	if(int(s[n-1]) == 32) check = false;
	if(!sodaucach || !chusaudaucach) check = false;
	return check;
}

class hocsinh{
	private:
		
	public:
		string ten;
		double dtoan, dvan, danh;
		// Ham nay dung de nhap ten cua hoc sinh
		void Nhapten(){
			cout << "Hay nhap day du ho va ten cua hoc sinh : " << endl;
			
			string s; 
			cin.ignore();
			getline(cin, s);
			bool c = checkten(s);
			while(c == false){
				cout << "   Ten cua ban khong hop le, hay nhap lai." << endl;
				cout << "   ";
				getline(cin, s);
				cout << endl;
				c = checkten(s);
			}
			this->ten= s;
			return;
		}
		
		// Ham nay dung de nhap diem toan
		// Neu so nhap vao khong thoa man xuat ra thong bao va yeu cau nhap lai
		void Nhapdiemtoan(){
			cout << "Hay nhap diem toan cua hoc sinh : " << endl;
			int x; cin >> x;
			while(x < 0 || x > 10){
				cout << "   So diem cua ban khong hop le, hay nhap lai." << endl;
				cout << "   ";
				cin >> x;
				cout << endl;
			}
			this->dtoan= x;
			return;
		}
		
		// Ham nay dung de nhap diem van
		// Neu so nhap vao khong thoa man xuat ra thong bao va yeu cau nhap lai
		void Nhapdiemvan(){
			cout << "Hay nhap diem van cua hoc sinh : " << endl;
			int x; cin >> x;
			while(x < 0 || x > 10){
				cout << "   So diem cua ban khong hop le, hay nhap lai." << endl;
				cout << "   ";
				cin >> x;
				cout << endl;
			}
			this->dvan= x;
			return;
		}
		
		// Ham nay dung de nhap diem anh
		// Neu so nhap vao khong thoa man xuat ra thong bao va yeu cau nhap lai
		void Nhapdiemanh(){
			cout << "Hay nhap diem anh cua hoc sinh : " << endl;
			int x; cin >> x;
			while(x < 0 || x > 10){
				cout << "   So diem cua ban khong hop le, hay nhap lai." << endl;
				cout << "   ";
				cin >> x;
				cout << endl;
			}
			this->danh= x;
			return;
		}
		
		//Ham nay tra ve diem trung binh
		double Diemtb(){
			return (2*dtoan + dvan + danh)/4;
		}
		
		//Ham nay giup phan loai hoc sinh
		string Phanloai(){
			double x = this->Diemtb();
			if(x >= 9) return "Xuatsac";
			if(x >= 8 && x < 9) return "Gioi";
			if(x >= 6.5 && x < 8) return "Kha";
			if(x >= 5 && x < 6.5) return "Trung Binh";
			if(x < 5) return "Yeu";
		}
		
		string getten(){
			return this->ten;
		}
		
		void display(){
			cout << this->ten << " voi diem toan, van, anh van lan luot la : " << this->dtoan << " " << this->dvan << " " << this->danh << "." << endl; 
		}
};

// Ham nay dung de xuat ra hoc sinh co diem cao nhat trong so cac hoc sinh
void Hocsinhcodiemcaonhat(vector<hocsinh>& hs){
	int mxgrade = -1, n = hs.size();
	string besths = hs[0].getten();
	for(int i = 0; i < n; i++){
		if(mxgrade < hs[i].Diemtb()){
			besths = hs[i].getten();
			mxgrade = hs[i].Diemtb();
		}
	}
	cout << "Hoc sinh co diem trung binh cao nhat la : " << besths << " ." << endl;
	return;
}

// Ham nay dung de kiem kiem tra xem ten cua hoc sinh co thoa man voi tu khoa nhap vao hay khong
bool caseInsensitiveSearch(const string& studentName, const string& keyword) {
    string lowerStudentName = studentName;
    string lowerKeyword = keyword;

    transform(lowerStudentName.begin(), lowerStudentName.end(), lowerStudentName.begin(), ::tolower);
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);

    vector<string> keywords;
    istringstream iss(lowerKeyword);
    string temp;
    while (iss >> temp) {
        keywords.push_back(temp);
    }

    for (const string& word : keywords) {
        if (lowerStudentName.find(word) == string::npos) {
            return false; // N?u không tìm th?y t? nào
        }
    }

    return true; 
}

// Ham nay tra ve chi so cua cac hoc sinh thoa man voi ten nhap vao
vector<int> Cachocsinhthoaman(vector<hocsinh>& hs, string cantim){
	vector<int> ans;
	for(int i = 0; i < hs.size(); i++){
		if(caseInsensitiveSearch(hs[i].getten(), cantim)) ans.push_back(i);
	}
	return ans;
}

// Ham nay tra ve chi so cua cac hoc sinh co diem toan thap nhat
vector<int> Danhsachdtoanthapnhat(vector<hocsinh>& hs){
	vector<int> ans;
	double mindtoan = 100;
	for(int i = 0; i < hs.size(); i++){
		mindtoan = min(mindtoan, hs[i].dtoan);
	}
	for(int i = 0; i < hs.size(); i++){
		if(hs[i].dtoan == mindtoan) ans.push_back(i);
	}
	return ans;
}
int main(){
	int n = 1;
	cout << "Hay nhap so hoc sinh trong lop : " << endl;
	cin >> n;
	
	vector<hocsinh> hs(n);
	
	for(int i = 0; i < n; i++){
		hs[i].Nhapten();
		hs[i].Nhapdiemtoan();
		hs[i].Nhapdiemanh();
		hs[i].Nhapdiemvan();
	}
	
	Hocsinhcodiemcaonhat(hs);
	
	string cantim;
	cin.ignore();
	cout << "Nhap ten cua hoc sinh ma ban can tim : ";
	getline(cin, cantim);
	
	vector<int> satis = Cachocsinhthoaman(hs, cantim);
	if(satis.size() == 0) cout << "Khong co hoc sinh nao giong voi thong tin ban dua ra." << endl;
	else{
		cout << "Cac hoc sinh co the trung voi nguoi ban muon tim : " << endl;
		for(int i = 0; i < satis.size(); i++){
			hs[satis[i]].display();	
		}
	}
	
	
	vector<int> satis1 = Danhsachdtoanthapnhat(hs);
	cout << "Danh sach cac hoc sinh co diem toan thap nhat la : "<< endl;
	for(int i = 0; i < satis1.size(); i++){
		hs[satis1[i]].display();
	}
	
	return 0;
}

