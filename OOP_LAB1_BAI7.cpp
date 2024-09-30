#include <bits/stdc++.h>
using namespace std;

class Chuyenbay {
public:
    string Machuyenbay;
    string Ngaybay;
    string Giobay;
    string Noidi;
    string Noiden;

    void nhapChuyenBay();
    void xuatChuyenBay() {
        cout << "Ma chuyen bay: " << Machuyenbay << endl;
        cout << "Ngay bay: " << Ngaybay << endl;
        cout << "Gio bay: " << Giobay << endl;
        cout << "Noi di: " << Noidi << endl;
        cout << "Noi den: " << Noiden << endl;
    }
};

// Kiem tra ma chuyen bay dung dinh dang la chuoi ki tu dai toi da ky tu, khong duoc chua khoan trang hay ky tu dac biet
bool Kiemtramachuyenbay(const string& input) {
    return regex_match(input, std::regex("^[A-Za-z0-9]{1,5}$"));
}

bool Kiemtrangaybay(std::string &input) {
    // Kiem tra dinh dang
    std::regex pattern(R"(^([0-2][0-9]|(3[01]))-(0[1-9]|1[0-2])-(\d{4})$)");
    if (!std::regex_match(input, pattern)) {
        return false; // Dinh dang khong hop le
    }

    // Tach ngay, thang, nam
    int d = (input[0] - '0') * 10 + (input[1] - '0');
    int m = (input[3] - '0') * 10 + (input[4] - '0');
    int y = (input[6] - '0') * 1000 + (input[7] - '0') * 100 + (input[8] - '0') * 10 + (input[9] - '0');

    // Kiem tra tinh hop le cua ngay
    if (m == 2) { // Thang 2
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) { // Nam nhuan
            return d >= 1 && d <= 29;
        } else {
            return d >= 1 && d <= 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) { // Cac thang 30 ngay
        return d >= 1 && d <= 30;
    } else { // Cac thang con lai
        return d >= 1 && d <= 31;
    }
}

// Kiem tra gio bay duoc nhap vao dung dinh dang 24 gio
bool KiemtragioBay(const string& gioBay) {
    return regex_match(gioBay, regex("^(2[0-3]|[01][0-9]):([0-5][0-9])$"));
}

// Kiem tra noi di la chuoi ki tu dai toi da 20 ky tu, khong duoc chua so hoac ky tu dac biet
bool Kiemtranoidi(const std::string& noiDi) {
    return std::regex_match(noiDi, std::regex("^[a-zA-Z ]{1,20}$"));
}

// Kiem tra noi den la chuoi ki tu dai toi da 20 ky tu, khong duoc chua so hoac ky tu dac biet
bool Kiemtranoiden(const string& noiDen) {
    return std::regex_match(noiDen, std::regex("^[a-zA-Z ]{1,20}$"));
}

// Nhap thong tin cua chuyen bay
void Chuyenbay::nhapChuyenBay() {
    cout << "Hay nhap ma chuyen bay (1-5 ky tu, khong chua khoang trong va ky tu dac biet): ";
    cin >> Machuyenbay;
    while (!Kiemtramachuyenbay(Machuyenbay)) {
        cout << "Ban da nhap sai dinh dang, hay nhap lai : ";
        cin >> Machuyenbay;
    }

    cout << "Hay nhap ngay bay, theo dinh dang DD-MM-YYYY (vi du: 01-09-2024): ";
    cin >> Ngaybay;
    while (!Kiemtrangaybay(Ngaybay)) {
        cout << "Ngay bay khong hop le, hay nhap lai : ";
        cin >> Ngaybay;
    }

    cout << "Hay nhap gio bay theo dinh dang HH:MM (vi du: 23:08) : ";
    cin >> Giobay;
    while (!KiemtragioBay(Giobay)) {
        cout << "Gio bay khong hop le, hay nhap lai : ";
        cin >> Giobay;
    }

    cout << "Hay nhap noi di cua chuyen bay (ten dia danh, khong chua so hoac ky tu dac biet) : ";
    cin.ignore();
    getline(cin, Noidi);
    while (!Kiemtranoidi(Noidi)) {
        cout << "Noi di khong hop le, hay nhap lai : ";
        getline(cin, Noidi);
    }

    cout << "Hay nhap noi den cua chuyen bay (ten dia danh, khong chua so hoac ky tu dac biet) : ";
    getline(cin, Noiden);
    while (!Kiemtranoiden(Noiden)) {
        cout << "Noi den khong hop le, hay nhap lai : ";
        getline(cin, Noiden);
    }
}

// Ham so sanh thoi gian khoi hanh cua hai chuyen bay
bool Sosanh(const Chuyenbay& cb1, const Chuyenbay& cb2) {
    int d1 = stoi(cb1.Ngaybay.substr(0, 2));
    int m1 = stoi(cb1.Ngaybay.substr(3, 2));
    int y1 = stoi(cb1.Ngaybay.substr(6, 4));
    
    int h1 = stoi(cb1.Giobay.substr(0, 2));
    int min1 = stoi(cb1.Giobay.substr(3, 2));
    
    int d2 = stoi(cb2.Ngaybay.substr(0, 2));
    int m2 = stoi(cb2.Ngaybay.substr(3, 2));
    int y2 = stoi(cb2.Ngaybay.substr(6, 4));
    
    int h2 = stoi(cb2.Giobay.substr(0, 2));
    int min2 = stoi(cb2.Giobay.substr(3, 2));
    
    if (y1 != y2) return y1 < y2;
    if (m1 != m2) return m1 < m2;
    if (d1 != d2) return d1 < d2;
    if (h1 != h2) return h1 < h2;
    return min1 < min2;
}

// Ham sap xep chuyen bay theo gio khoi hanh
void Sapxepchuyenbay(vector<Chuyenbay>& dsChuyenBay) {
    sort(dsChuyenBay.begin(), dsChuyenBay.end(), Sosanh);
}

// Ham xuat ra thong tin cua cac chuyen bay khoi hanh tu mot noi cu the trong ngay duoc chi dinh
void Caccbthoamannoidivangaybay(vector<Chuyenbay>& dsChuyenBay, const string& noiDi, const string& ngayBay) {
    int z = 0;
	for (auto& cb : dsChuyenBay) {
        if (cb.Noidi == noiDi && cb.Ngaybay == ngayBay) {
        	z++;
        	if(z == 1) cout << "Cac chuyen bay tu " << noiDi << " vao ngay " << ngayBay << ":\n";
            cb.xuatChuyenBay();
        }
    }
    if(z == 0) cout << "Khong co chuyen bay nao thoa man." << endl;
}


// Ham dem so luong chuyen bay tu mot noi di den noi den nhat dinh
int Demcbthoanoidivanoiden(vector<Chuyenbay>& dsChuyenBay, const string& noiDi, const string& noiDen) {
    int count = 0;
    for (const auto& cb : dsChuyenBay) {
        if (cb.Noidi == noiDi && cb.Noiden == noiDen) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<Chuyenbay> dsChuyenBay;
    int n = 1;

    cout << "Nhap so chuyen bay: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cout << endl << "Hay nhap thong tin ve chuyen bay thu " << i+1 <<". \n";
        Chuyenbay cb;
        cb.nhapChuyenBay();
        dsChuyenBay.push_back(cb);
    }

    cout << "\nDanh sach chuyen bay:\n";
    for (auto& cb : dsChuyenBay) {
        cb.xuatChuyenBay();
        cout << endl;
    }

    Sapxepchuyenbay(dsChuyenBay);
    cout << "Danh sach chuyen bay sau khi sap xep:\n";
    for (auto& cb : dsChuyenBay) {
        cb.xuatChuyenBay();
        cout << endl;
    }

    string noiDi, ngayBay;
    cout << "Nhap noi di va ngay bay de tim kiem:\n";
    cout << "Noi di: ";
    cin.clear();
    getline(cin, noiDi);
    cout << "Ngay bay (DD-MM-YYYY): ";
    cin >> ngayBay;

    
    Caccbthoamannoidivangaybay(dsChuyenBay, noiDi, ngayBay);
	
	
	cout << "Nhap noi di de dem so chuyen bay : \n";
	cin.ignore();
	getline(cin, noiDi);
    string noiDen;
    cout << "Nhap noi den de dem so chuyen bay:\n";
    getline(cin, noiDen);
    int count = Demcbthoanoidivanoiden(dsChuyenBay, noiDi, noiDen);
    cout << "So chuyen bay tu " << noiDi << " den " << noiDen << " la: " << count << endl;

    return 0;
}
