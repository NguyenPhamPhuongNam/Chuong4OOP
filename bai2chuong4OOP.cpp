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

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


class PhanSo {
private:
    int tu, mau;

public:
    PhanSo(int tu = 0, int mau = 1) : tu(tu), mau(mau) {
        if (mau == 0) {
            cout<<"Mau khong the bang 0.";
        }
        toigianphanso();
    }


    void toigianphanso() {
        int uoc = gcd(abs(tu), abs(mau));
        tu /= uoc;
        mau /= uoc;
        if (mau < 0) { 
            tu = -tu;
            mau = -mau;
        }
    }


    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0) {
            cout<<"Mau khong the bang 0.";
        }
        toigianphanso();
    }

  
    void xuat() const {
        cout << tu << "/" << mau;
    }


    double value() const {
        return (double)tu / mau; 
    }


    int getTu() const {
        return tu;
    }

  
    bool operator<(const PhanSo& other) const {
        return value() < other.value(); 
    }
};


class arrPhanSo {
private:
    vector<PhanSo> a;

public:

    void nhapPhanSo(int n) {
        for (int i = 0; i < n; ++i) {
            PhanSo ps;
            cout << "Nhap phan so thu " << i + 1 << ": " << '\n';
            ps.nhap();
            a.push_back(ps);
        }
    }

 
    void xuatPhanSo() const {
        for (size_t i = 0; i < size(a); ++i) {
            a[i].xuat();
            cout << " ";
        }
        cout << '\n';
    }


    void taoNgauNhien(int n) {
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            int tu = rand() % 1000000 - 999999; 
            int mau;
            do {
                mau = rand() % 1000000 + 1;  
            } while (mau == 0);
            a.push_back(PhanSo(tu, mau));
        }
    }

    PhanSo timMax() const {
        return *max_element(all(a));
    }


    int demTuNguyenTo() const {
        int count = 0;
        for (const auto& ps : a) {
            if (isPrime(ps.getTu())) {
                ++count;
            }
        }
        return count;
    }


    void sapXepTangDan() {
        sort(all(a));
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    arrPhanSo aPS;
    int n;

    cout << "Nhap so luong phan so: ";
    cin >> n;

    aPS.nhapPhanSo(n);

    cout << "Danh sach phan so: ";
    aPS.xuatPhanSo();


    cout << "\nTao 5 phan so ngau nhien: ";
    aPS.taoNgauNhien(5);
    aPS.xuatPhanSo();

    cout << "\nPhan so lon nhat: ";
    aPS.timMax().xuat();
    cout << '\n';


    cout << "\nSo phan so co tu la so nguyen to " << aPS.demTuNguyenTo() << '\n';


    cout << "\nSap xep phan so theo thu tu tang dan: ";
    aPS.sapXepTangDan();
    aPS.xuatPhanSo();

    
    exit(0);
}
    
   


