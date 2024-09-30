#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

// Tao mang LPS doi voi mang A
// Y nghia cua mang LPS nay la doi voi moi phan tu thu i cua bang A,
// phan tu thu i cua mang LPS luu lai gia tri dai nhat cua mang con vua la "tien to"
// vua la "hau to" cua mang duoc tao boi i+1 gia tri lien tiep cua mang A ke tu phan tu dau tien
// vi du doi voi mang {1,2,1} thi mang LPS la {0,0,1}
vector<int> computeLPS(const vector<int>& A) {
    int m = A.size();
    vector<int> lps(m);
    int length = 0;
    int i = 1;

    while (i < m) {
        if (A[i] == A[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Ta ap dung thuat toan KMP de kiem xem trong mang B xuat hien bao nhieu lan mang A
vector<int> KMPsearch(const vector<int>& B, const vector<int>& A) {
    int n = B.size();
    int m = A.size();
    vector<int> lps = computeLPS(A);
    vector<int> positions;
    int i = 0;
    int j = 0;

    while (i < n) {
        if (A[j] == B[i]) {
            i++;
            j++;
        }

        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && A[j] != B[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return positions;
}

int main() {
    int sizea, sizeb;
    cin >> sizea;
    cin >> sizeb;
    vector<int> A;
    vector<int> B;

    /*ifstream infile; 
    infile.open("x.txt"); (dung trong truong hop ban muon doc du lieu tu file x)*/
    int x;
    for (int i = 0; i < sizea; i++) {
    	cin >> x;
		// infile >> x; (dung trong truong hop ban muon doc du lieu tu file x)
        
        A.push_back(x);
    }
	for (int i = 0; i < sizeb; i++) {
    	cin >> x;
        // infile >> x; (dung trong truong hop ban muon doc du lieu tu file x)

        B.push_back(x);
    }

    vector<int> result = KMPsearch(B, A);

    if (!result.empty()) {
        cout << "Mang mau A duoc tim thay tai cac vi tri: ";
        for (int pos : result) {
            cout << pos << " ";
        }
        cout << endl;
    } else {
        cout << "Mang mau A khong duoc tim thay." << endl;
    }
    return 0;
}

