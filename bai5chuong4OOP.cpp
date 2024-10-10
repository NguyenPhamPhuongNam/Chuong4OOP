#include<bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
const int INF = numeric_limits<int>::max();
const int nax = (int)(1e6);
const int MAXN= (int)(1e6+5);
const int mod =1e9+2277;
const int BASE = (int)(301);
#define all(x) (x).begin(), (x).end()
#define size(x) ((int)x.size())
#define double long double
#define pii pair<int, int>
#define tup tuple<int, int, int>
#define iii pair<pii, int>
#define unsetbit(mask, x) ((mask)&=(~(1 << x)))
#define setbit(mask, x) ((mask)|=(1 << x))
#define reversebit(mask, x) ((mask) ^=(1 << n))
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int d8x[8] = { -1, 1, 0, 0, -1, 1, 1, -1};
const int d8y[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int Trie_sz = 1e6;
#define get_bit(mask, x) ((mask)>>(x)&1)
const int LOG=19;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
 
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

class cBook {
private:
    string maSach;
    string tenSach;
    int namXuatBan;
    int tongSoTrang;

public:
    cBook(string ma = "", string ten = "", int nam = 0, int trang = 0)
        : maSach(ma), tenSach(ten), namXuatBan(nam), tongSoTrang(trang) {}

    void NhapThongTin() {
        cout << "Nhap ma sach: ";
        getline(cin, maSach);
        cout << "Nhap ten sach: ";
        getline(cin, tenSach);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
        cout << "Nhap tong so trang: ";
        cin >> tongSoTrang;
        cin.ignore(); 
    }


    void XuatThongTin() const {
        cout << "Ma sach: " << maSach << '\n';
        cout << "Ten sach: " << tenSach << '\n';
        cout << "Nam xuat ban: " << namXuatBan << '\n';
        cout << "Tong so trang: " << tongSoTrang << '\n';
    }

    
    int getNamXuatBan() const { return namXuatBan; }

    
    void capNhatThongTin() {
        cout << "Cap nhat thong tin sach:\n";
        NhapThongTin();
    }
};


class cListBook {
private:
    vector<cBook> danhsach;

public:
    void nhapDanhSach() {
        int soLuong;
        cout << "Nhap so luong sach: ";
        cin >> soLuong;
        cin.ignore();

        for (int i = 0; i < soLuong; ++i) {
            cout << "\nNhap thong tin sach thu " << i + 1 << ":\n";
            cBook sach;
            sach.NhapThongTin();
            danhsach.push_back(sach);
        }
    }

    void xuatDanhSach() const {
        for (int i = 0; i < size(danhsach); ++i) {
            cout << "\nThong tin sach thu " << i + 1 << ":\n";
            danhsach[i].XuatThongTin();
        }
    }

    void timSachMoiNhat() const {
        if (danhsach.empty()) {
            cout << "Danh sach sach trong.\n";
            return;
        }

        int ViTriMoiNhat = 0;
        for (int i = 1; i < size(danhsach); ++i) {
            if (danhsach[i].getNamXuatBan() > danhsach[ViTriMoiNhat].getNamXuatBan()) {
                ViTriMoiNhat = i;
            }
        }

        cout << "\nSach xuat ban gan day nhat:\n";
        danhsach[ViTriMoiNhat].XuatThongTin();
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    cListBook danhsachSach;

    danhsachSach.nhapDanhSach();


    cout << "\nDanh sách các sách:\n";
    danhsachSach.xuatDanhSach();

    danhsachSach.timSachMoiNhat();
  
    
    exit(0);
}
    
   


