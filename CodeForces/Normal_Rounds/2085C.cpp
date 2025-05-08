#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

int find_01(ll x, ll y, ll k){
    int mask = 1;
    x += k;
    y += k;
    for(int i = 0; i < 63; i++, mask <<= 1){
        if((x & mask) != (y & mask)){
            return mask;
        }
    }
    return 0;
}

void print_bin(ll x){
    while(x > 0){
        cout << (x&1);
        x >>= 1;
    }
    cout << "\n";
}

void solve(){
    // int n; cin >> n;
    ll x, y, k = 0; cin >> x >> y;
    if(x == y){
        cout << "-1\n";
        return;
    }

    ll mask = 1;
    ll mask2 = 0;
    ll mask01 = find_01(x,y,k);
    int mode = 1;
    while(((x + k + y + k) != ((x + k) ^ (y + k))) && mask01){
        mask = 1;
        mode = 1;
        mask2 = 0;
        // cout << "k:     ";
        // print_bin(k);
        // cout << "x+k:   ";
        // print_bin(x + k);
        // cout << "y+k:   ";
        // print_bin(y + k);
        // cout << "mask:  ";
        // print_bin(mask01);
        

        for(int i = 0; i < 63; i++, mask <<= 1){
            if(((x + k) & mask) == ((y + k) & mask)){
                if(((y + k) & mask)){
                    if(mask2 == 0){
                        k += mask;
                        break;
                    } else {
                        // cout << "mask2: ";
                        // print_bin(mask2);
                        k += mask2;
                        break;
                    }
                }
            } else {
                mask2 = 0;
            }
            if(mask >= mask01){
                mask2 += mask;
            }
        }
        mask01 = find_01(x, y, k);
    }
    // for(int i = 0; i < 63; i++, mask <<= 1){
    //     if(((x + k) & mask) == ((y + k) & mask)){
    //         if(((y + k) & mask)){
    //             k += mask2;
    //         }
    //     } else {

    //     }
    // }
    assert(((x + k + y + k) == ((x + k) ^ (y + k))));
    // assert(k <= 1e18);
    if(k > 1e18){
        k = -1;
    }
    cout << k << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
// 00000000000100100100100100100100
// 00000000000010010010010010010100

// 00000000000100100100100101000000
// 00000000000010010010010010100000