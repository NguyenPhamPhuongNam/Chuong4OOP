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

class cArray {
private:
    int a[nax]; 
    int size;      
public:
    cArray() : size(0) {}

    void inputArray(int n) {
        size = n;
        cout << "Nhap " << n << " so nguyen:\n";
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    }


    void outputArray() const {
        cout << "Cac phan tu trong mang: ";
        for (int i = 0; i < size; ++i) {
            cout <<a[i] << " ";
        }
        cout << "\n";
    }


    void generateRandomArray(int n) {
        size = n;
        srand(time(0)); 
        for (int i = 0; i < n; ++i) {
            a[i] = rand() % 1000000; 
        }
    }


    int countOccurrences(int x) const {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (a[i] == x) {
                count++;
            }
        }
        return count;
    }


    bool tangdan() const {
        for (int i = 1; i < size; ++i) {
            if (a[i] < a[i - 1]) {
                return false;
            }
        }
        return true;
    }


    int findSmallestOdd() const {
        int minOdd = -1; 
        for (int i = 0; i < size; ++i) {
            if (a[i] % 2 != 0) { 
                if (minOdd == -1 || a[i] < minOdd) {
                    minOdd = a[i];
                }
            }
        }
        return minOdd;
    }

    void sortArray() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    cArray a;
    int n, x;

    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    a.inputArray(n);

    a.outputArray();


    cout << "Tao mang ngau nhien:\n";
    a.generateRandomArray(n);
    a.outputArray();


    cout << "Nhap gia tri can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " la: " << a.countOccurrences(x) << "\n";


    if (a.tangdan()) {
        cout << "Mang tang dan.\n";
    } else {
        cout << "Mang khong tang dan.\n";
    }

    int smallestOdd = a.findSmallestOdd();
    if (smallestOdd != -1) {
        cout << "Phan tu le nho nhat la: " << smallestOdd << "\n";
    } else {
        cout << "Khong co phan tu le trong mang.\n";
    }


    cout << "Mang sau khi sap xep tang dan: \n";
    a.sortArray();
    a.outputArray();
    
    exit(0);
}
