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

class DonThuc {
private:
    double a; 
    int b;    

public:
    DonThuc(double heso = 0, int degree = 0) : a(heso), b(degree) {}


    void nhap() {
        cout << "Nhap he so a: ";
        cin >> a;
        cout << "Nhap bac b: ";
        cin >> b;
    }

    void setA(double coeff) { a = coeff; }
    void setB(int degree) { b = degree; }


    void xuat() const {
        if (b == 0) {
            cout << a;
        } else if (b == 1) {
            cout << a << "x";
        } else {
            cout << a << "x^" << b;
        }
    }

    double giaTri(double x) const {
        return a * pow(x, b);
    }


    DonThuc daoHam() const {
        if (b == 0) {
            return DonThuc(0, 0); 
        }
        return DonThuc(a * b, b - 1);
    }


    DonThuc operator+(const DonThuc& other) const {
        if (b == other.b) {
            return DonThuc(a + other.a, b);
        } else {
            cout << "Khong the cong hai don thuc khac bac!\n";
            return DonThuc(); 
        }
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    DonThuc dt1, dt2;
    cout << "Nhap thong tin don thuc thu nhat:\n";
    dt1.nhap();
    
    cout << "Nhap thong tin don thuc thu hai:\n";
    dt2.nhap();

    cout << "\nDon thuc thu nhat: ";
    dt1.xuat();
    cout << "\nDon thuc thu hai: ";
    dt2.xuat();


    DonThuc tong = dt1 + dt2;
    cout << "\nTong hai don thuc: ";
    tong.xuat();

    DonThuc daoHam1 = dt1.daoHam();
    cout << "\nDao ham don thuc thu nhat: ";
    daoHam1.xuat();
    DonThuc daoHam2 = dt2.daoHam();
    cout << "\nDao ham don thuc thu hai: ";
    daoHam2.xuat();


    double x;
    cout << "\n\nNhap gia tri cua x de tinh don thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua don thuc thu nhat tai x = " << x << " la: " << dt1.giaTri(x) <<'\n';
    
    cout << "\n\nNhap gia tri cua x de tinh don thuc thu hai: ";
    cin >> x;
    cout << "Gia tri cua don thuc thu hai tai x = " << x << " la: " << dt2.giaTri(x) << '\n';


    
    exit(0);
}
    
   


