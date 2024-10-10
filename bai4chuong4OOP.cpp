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

class DaThuc {
private:
    int bac; 
    vector<double> heSo; 

public:
   
    DaThuc(int n = 0) : bac(n), heSo(n + 1, 0.0) {} 


    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        heSo.resize(bac + 1);
        for(int i = 0; i <= bac; ++i) {
            cout << "Nhap he so a" << i + 1 << " cho x^" << bac - i << ": ";
            cin >> heSo[i];
        }
    }


    void xuat() const {
        bool check = true;
        for(int i = 0; i <= bac; ++i) {
            double HESO = heSo[i];
            int BAC = bac - i;
            if(HESO == 0) continue; 
            
            if(HESO > 0 && !check) cout << " + ";
            else if(HESO < 0 && !check) cout << " - ";
            else if(HESO < 0 && check) cout << "-";

            
            if(abs(HESO) != 1 || BAC == 0)
                cout << fixed << setprecision(2) << abs(HESO);
            else if(HESO == -1 && BAC != 0)
                ;
           
            if(BAC > 0) cout << "x";
            if(BAC > 1) cout << "^" << BAC;

            check = false;
        }
        if(check) cout << "0"; 
    }

   
    double giaTri(double x) const {
        double result = 0.0;
        for(int i = 0; i <= bac; ++i) {
            result += heSo[i] * pow(x, bac - i);
        }
        return result;
    }

    DaThuc operator+(const DaThuc& other) const {
        int maxBac = max(bac, other.bac);
        DaThuc tong(maxBac);

        for(int i = 0; i <= maxBac; ++i) {
            double HESO1 = (i <= bac) ? heSo[i] : 0.0;
            double HESO2 = (i <= other.bac) ? other.heSo[i] : 0.0;
            tong.heSo[i] = HESO1 + HESO2;
        }
        
        while(tong.bac > 0 && tong.heSo[0] == 0) {
            tong.heSo.erase(tong.heSo.begin());
            tong.bac--;
        }
        return tong;
    }

    DaThuc operator-(const DaThuc& other) const {
        int maxBac = max(bac, other.bac);
        DaThuc hieu(maxBac);
        for(int i = 0; i <= maxBac; ++i) {
            double HESO1 = (i <= bac) ? heSo[i] : 0.0;
            double HESO2 = (i <= other.bac) ? other.heSo[i] : 0.0;
            hieu.heSo[i] = HESO1 - HESO2;
        }

        while(hieu.bac > 0 && hieu.heSo[0] == 0) {
            hieu.heSo.erase(hieu.heSo.begin());
            hieu.bac--;
        }
        return hieu;
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
   cout << "Nhap thong tin da thuc thu nhat:\n";
    DaThuc P1;
    P1.nhap();

    cout << "\nNhap thong tin da thuc thu hai:\n";
    DaThuc P2;
    P2.nhap();

    cout << "\nDa thuc thu nhat: ";
    P1.xuat();
    cout << "\nDa thuc thu hai: ";
    P2.xuat();


    DaThuc Tong = P1 + P2;
    cout << "\n\nTong hai da thuc: ";
    Tong.xuat();


    DaThuc Hieu = P1 - P2;
    cout << "\nHieu hai da thuc: ";
    Hieu.xuat();


    double x;
    cout << "\n\nNhap gia tri x de tinh da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << fixed << setprecision(2) << P1.giaTri(x) << '\n';

    cout << "\n\nNhap gia tri x de tinh da thuc thu hai: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu hai tai x = " << x << " la: " << fixed << setprecision(2) << P2.giaTri(x) << '\n';
    
    exit(0);
}
    
   


