#include <bits/stdc++.h>
using namespace std;

class SoTietKiem {
public:
    string maSo;
    string loaiTietKiem;
    string hoTenKhachHang;
    string cmnd; // Chuyen doi thanh string
    string ngayMoSo; // Su dung dinh dang DD-MM-YYYY
    double laisuat = 0;
    double soTienGui;

    // Nhap thong tin so tiet kiem tu nguoi dung
    void nhapSoTietKiem();
    
    // Xuat thong tin so tiet kiem
    void xuatSoTietKiem();
    
    // Tinh lai suat dua tren lai suat nhap vao
    double tinhLaiSuat(double laiSuat);
    
    // Rut tien tu so tiet kiem
    void rutTien(double soTienRut);
    
    // Tinh lai suat hien tai cho so tiet kiem
    void Tinhlaisuat();
    
    // Rut tien (khong co tham so)
    void rutTien();
};

// Kiem tra dinh dang ma so (toi da 5 ky tu, chi chua chu cai va so)
bool kiemTraMaSo(const string& maSo) {
    return regex_match(maSo, regex("^[A-Za-z0-9]{1,5}$")) && maSo.length() <= 5;
}

// Kiem tra dinh dang loai tiet kiem (chi chua chu cai va dau cach, khong qua 10 ky tu)
bool kiemTraLoaiTietKiem(const string& loai) {
    if (!std::regex_match(loai, std::regex("^[a-zA-Z ]+$"))) return false; // Kiem tra chi chu cai va dau cach
    int countLetters = 0;

    for (char c : loai) {
        if (isalpha(c)) countLetters++; // Dem so chu cai
    }

    return countLetters <= 10; // Kiem tra so chu cai
}

// Kiem tra dinh dang ho ten (toi da 30 ky tu, chi chua chu cai va dau cach)
bool kiemTraHoTen(const string& hoTen) {
    return hoTen.length() <= 30 && regex_match(hoTen, regex("^[A-Za-z\\s]+$"));
}

// Kiem tra dinh dang CMND (9 hoac 12 ky tu)
bool kiemTraCMND(const string& cmnd) {
    return (cmnd.length() == 9 || cmnd.length() == 12);
}

// Kiem tra dinh dang ngay (DD-MM-YYYY)
bool kiemTraNgay(const string& ngay) {
    int d = stoi(ngay.substr(0, 2));
    int m = stoi(ngay.substr(3, 2));
    int y = stoi(ngay.substr(6, 4));

    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;

    if (m == 2) {
        bool namNhuan = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        return (namNhuan ? d <= 29 : d <= 28);
    }

    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return d <= 30;
    }

    return true;
}

// Kiem tra so tien gui (phai lon hon 0)
bool kiemTraSoTienGui(double soTien) {
    return soTien > 0;
}

void SoTietKiem::nhapSoTietKiem() {
    cout << "Nhap ma so: ";
    cin.ignore();
    getline(cin, maSo);
    while (!kiemTraMaSo(maSo)) {
        cout << "Ma so khong hop le, vui long nhap lai: ";
        getline(cin, maSo);
    }

    cout << "Nhap loai tiet kiem (ngan han, dai han, khong ky han): ";
    getline(cin, loaiTietKiem);
    while (!kiemTraLoaiTietKiem(loaiTietKiem)) {
        cout << "Loai tiet kiem khong hop le (khong qua 10 ky tu sau khi loai bo khoang trang), vui long nhap lai: ";
        getline(cin, loaiTietKiem);
    }

    cout << "Nhap ho ten khach hang: ";
    getline(cin, hoTenKhachHang);
    while (!kiemTraHoTen(hoTenKhachHang)) {
        cout << "Ho ten khach hang khong hop le, vui long nhap lai: ";
        getline(cin, hoTenKhachHang);
    }

    cout << "Nhap CMND: ";
    cin >> cmnd;
    while (!kiemTraCMND(cmnd)) {
        cout << "CMND khong hop le, vui long nhap lai: ";
        cin >> cmnd;
    }

    cout << "Nhap ngay mo so (DD-MM-YYYY): ";
    cin >> ngayMoSo;
    while (!kiemTraNgay(ngayMoSo)) {
        cout << "Ngay mo so khong hop le, vui long nhap lai: ";
        cin >> ngayMoSo;
    }

    cout << "Nhap so tien gui: ";
    cin >> soTienGui;
    while (!kiemTraSoTienGui(soTienGui)) {
        cout << "So tien gui phai la so duong, vui long nhap lai: ";
        cin >> soTienGui;
    }
}

void SoTietKiem::xuatSoTietKiem() {
    cout << "Ma so: " << maSo << endl;
    cout << "Loai tiet kiem: " << loaiTietKiem << endl;
    cout << "Ho ten khach hang: " << hoTenKhachHang << endl;
    cout << "CMND: " << cmnd << endl;
    cout << "Ngay mo so: " << ngayMoSo << endl;
    cout << "So tien gui: " << soTienGui << endl;
}

// Tim kiem so tiet kiem theo ma so hoac CMND
void timKiemSoTietKiem(vector<SoTietKiem>& ds, const string& MS, const string& CM) {
    bool found = false; // Danh dau neu tim thay
    for (size_t i = 0; i < ds.size(); ++i) {
        if ((CM == "?" && ds[i].maSo == MS) || (MS == "?" && ds[i].cmnd == CM)) {
            found = true;
            cout << "So tiet kiem thu " << i + 1 << " thoa man. Mot so thong tin:\n";
            ds[i].xuatSoTietKiem();
        }
    }
    if (!found) {
        cout << "Khong co so tiet kiem nao thoa man." << endl;
    }
}

// So sanh hai ngay duoi dang chuoi
bool soSanhNgay(const string& ngay1, const string& ngay2) {
    int d1 = stoi(ngay1.substr(0, 2));
    int m1 = stoi(ngay1.substr(3, 2));
    int y1 = stoi(ngay1.substr(6, 4));

    int d2 = stoi(ngay2.substr(0, 2));
    int m2 = stoi(ngay2.substr(3, 2));
    int y2 = stoi(ngay2.substr(6, 4));

    // So sanh nam
    if (y1 != y2) return y1 < y2;
    // So sanh thang
    if (m1 != m2) return m1 < m2;
    // So sanh ngay
    return d1 < d2;
}

// Liet ke so tiet kiem theo khoang thoi gian
void lietKeSoTietKiemTheoThoiGian(vector<SoTietKiem>& ds, const string& ngayBatDau, const string& ngayKetThuc) {
    bool found = false; // Danh dau neu tim thay
    for (size_t i = 0; i < ds.size(); ++i) {
        if (soSanhNgay(ngayBatDau, ds[i].ngayMoSo) && soSanhNgay(ds[i].ngayMoSo, ngayKetThuc) || ds[i].ngayMoSo == ngayBatDau || ds[i].ngayMoSo == ngayKetThuc) {
            found = true;
            cout << "So tiet kiem mo ngay: " << ds[i].ngayMoSo << endl;
            ds[i].xuatSoTietKiem();
            cout << endl;
        }
    }
    
    if (!found) {
        cout << "Khong co so tiet kiem nao mo trong khoang thoi gian da cho." << endl;
    }
}

// So sanh so tiet kiem theo so tien gui (giam dan)
bool compareBySoTienGui(const SoTietKiem& a, const SoTietKiem& b) {
    return a.soTienGui > b.soTienGui;
}

// So sanh so tiet kiem theo ngay mo so (tang dan)
bool compareByNgayMoSo(const SoTietKiem& a, const SoTietKiem& b){
    // Tach ngay, thang, nam
    int d1 = stoi(a.ngayMoSo.substr(0, 2));
    int m1 = stoi(a.ngayMoSo.substr(3, 2));
    int y1 = stoi(a.ngayMoSo.substr(6, 4));
    
    int d2 = stoi(b.ngayMoSo.substr(0, 2));
    int m2 = stoi(b.ngayMoSo.substr(3, 2));
    int y2 = stoi(b.ngayMoSo.substr(6, 4));

    // So sanh nam truoc
    if (y1 != y2) return y1 < y2;
    // Neu nam bang nhau, so sanh thang
    if (m1 != m2) return m1 < m2;
    // Neu thang cung bang nhau, so sanh ngay
    return d1 < d2;
}

// Tinh lai suat so voi ngay hien tai tren he thong may tinh
void SoTietKiem::Tinhlaisuat(){
	cout << "Hay nhap lai suat cua ngan hang (tinh theo %/nam)) : ";
	cin >> laisuat;
	int d = stoi(ngayMoSo.substr(0, 2));
    int m = stoi(ngayMoSo.substr(3, 2));
    int y = stoi(ngayMoSo.substr(6, 4));

    time_t now = time(0);
    tm* ltm = localtime(&now);
    int dHienTai = ltm->tm_mday;
    int mHienTai = ltm->tm_mon + 1;
    int yHienTai = ltm->tm_year + 1900;

    tm moSo = {0};
    moSo.tm_mday = d;
    moSo.tm_mon = m - 1; 
    moSo.tm_year = y - 1900;

    tm hienTai = {0};
    hienTai.tm_mday = dHienTai;
    hienTai.tm_mon = mHienTai - 1;
    hienTai.tm_year = yHienTai - 1900;

    double soGiay = difftime(mktime(&hienTai), mktime(&moSo));
    int ndays = static_cast<int>(soGiay / (60 * 60 * 24)); 
    double p = 0.5;
    if(loaiTietKiem != "khong ky han") p = laisuat;
    
    cout << "So tien lai cho den ngay hien tai ma ban nhan duoc la : " << (soTienGui * p / 100) * (ndays / 360.0) << " dong." << endl;
}

void SoTietKiem::rutTien() {
    double x; // So tien muon rut
    cout << "Nhap so tien muon rut: ";
    cin >> x;

    // Kiem tra so tien rut khong vuot qua so tien gui
    while (x <= 0 || x > soTienGui) {
        cout << "So tien rut khong hop le. Vui long nhap lai: ";
        cin >> x;
    }

    // Hoi thoi gian da ky hop dong va thoi gian ky gui
    int use, sign = INT_MAX;
    cout << "Ban da ky hop dong tiet kiem duoc bao nhieu ngay? ";
    cin >> use;
    if(loaiTietKiem != "khong ky han"){
		cout << "Thoi gian ky gui tien trong hop dong tiet kiem la bao nhieu ngay? ";
    	cin >> sign;
	}	

    double p, t;

    if (use < sign) {
        p = 0.5; // Lai suat tam thoi
        t = static_cast<double>(use) / 360.0;
    } else {
        p = laisuat;
        t = static_cast<double>(sign) / 360.0;
    }

    // Tinh tien lai
    double lai = x * (p / 100) * t;

    // In ket qua
    cout << "Ban rut ra " << x << " dong." << endl;
    cout << "Ban nhan lai " << lai << " dong." << endl;
    cout << "Ban con lai " << (soTienGui - x) << " trong tai khoan." << endl;

    // Cap nhat so tien gui moi
    soTienGui -= x;
}


int main() {
    vector<SoTietKiem> dsSoTietKiem;
    int n;

    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        SoTietKiem stk;
        stk.nhapSoTietKiem();
        dsSoTietKiem.push_back(stk);
    }

    cout << "\nDanh sach so tiet kiem:\n";
    for (size_t i = 0; i < dsSoTietKiem.size(); ++i) {
        dsSoTietKiem[i].xuatSoTietKiem();
        cout << endl;
    }
	
	for (size_t i = 0; i < dsSoTietKiem.size(); ++i) {
		cout << "Doi voi khach hang thu " << i+1 << " : " << endl;
        dsSoTietKiem[i].Tinhlaisuat();
		dsSoTietKiem[i].rutTien();
    }
    string key;
    char loaiTimKiem;
    cout << "Tim kiem theo ma so (m) hay CMND (c)? ";
    cin >> loaiTimKiem;
    
    while(true){
    	cout << "Tim kiem theo ma so (m) hay CMND (c)? ";
    	cin >> loaiTimKiem;
		if (loaiTimKiem == 'm') {
			string MS;
			cout << "Nhap ma so cua so tiet kiem : " ;
			cin >> MS;
        	timKiemSoTietKiem(dsSoTietKiem, MS, "?");
        	break;
    	} else if (loaiTimKiem == 'c') {
    		cout << "Nhap so CMND cua chu so : " << endl;
			string CM; cin >> CM; 
			string t = "?";
        	timKiemSoTietKiem(dsSoTietKiem, t, CM);
        	break;
    	} else {
        	cout << "Lua chon khong hop le. Hay nhap lai.\n";
		}
    }
	
	cout << "\nDanh sach so tiet kiem sap xep theo so tien gui giam dan:\n";
    sort(dsSoTietKiem.begin(), dsSoTietKiem.end(), compareBySoTienGui);
    for (size_t i = 0; i < dsSoTietKiem.size(); ++i) {
        dsSoTietKiem[i].xuatSoTietKiem();
        cout << endl;
    }

    cout << "\nDanh sach so tiet kiem sap xep theo ngay mo so tang dan:\n";
    sort(dsSoTietKiem.begin(), dsSoTietKiem.end(), compareByNgayMoSo);
    for (size_t i = 0; i < dsSoTietKiem.size(); ++i) {
        dsSoTietKiem[i].xuatSoTietKiem();
        cout << endl;
    }
    return 0;
}

