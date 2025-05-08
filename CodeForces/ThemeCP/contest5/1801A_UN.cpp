//Rating 1600
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

int tab[210][210];

void solve(){
    int n, m; cin >> n >> m;

    // int base = 0;
    // for(int i = 0; i < n; i += 2){
    //     for(int j = 0; j < m; j += 2){
    //         tab[i][j] = base;
    //         tab[i][j + 1] = base + 1;
    //         tab[i + 1][j] = base + 2;
    //         tab[i + 1][j + 1] = base + 3;
    //         base += 8;
    //     }
    // }
    int tmp1 = 0, tmp2 = 0 ;
    for(int i = 0; i < n - 3 ; i++){
        for(int j = 0; j < m - 3; j++){
            cout << i << " " << j << "\n";
            tmp1 = 0;
            tmp2 = 0;
            cout << (tab[i + tmp1][j + tmp2] ^ tab[i + tmp1][j + 1 + tmp2] ^ tab[i + 1 + tmp1][j + tmp2] ^ tab[i + 1 + tmp1][j + 1 + tmp2]);
            cout << " == ";
            tmp1 = 2;
            tmp2 = 2;
            cout << (tab[i + tmp1][j + tmp2] ^ tab[i + tmp1][j + 1 + tmp2] ^ tab[i + 1 + tmp1][j + tmp2] ^ tab[i + 1 + tmp1][j + 1 + tmp2]);
            cout << "\n";

            tmp1 = 0;
            tmp2 = 2;
            cout << (tab[i + tmp1][j + tmp2] ^ tab[i + tmp1][j + 1 + tmp2] ^ tab[i + 1 + tmp1][j + tmp2] ^ tab[i + 1 + tmp1][j + 1 + tmp2]);
            cout << " == ";
            tmp1 = 2;
            tmp2 = 0;
            cout << (tab[i + tmp1][j + tmp2] ^ tab[i + tmp1][j + 1 + tmp2] ^ tab[i + 1 + tmp1][j + tmp2] ^ tab[i + 1 + tmp1][j + 1 + tmp2]);
            cout << "\n";
        }
    }


    cout << n  * m << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << tab[i][j] << " ";
        }
        cout << "\n";
    }
}

 
int32_t main(){
    BOOST;
    int n = 201, m = 201;
    int base = 0;
    int addition = 0;
    for(int i = 0; i < n; i += 2){
        int x = i, y = 0;
        addition = 0;
        while(x >= 0 && y < m){
            tab[x][y] = base + addition++;
            tab[x + 1][y] = base + addition++;
            tab[x][y + 1] = base + addition++;
            tab[x + 1][y + 1] = base + addition++;
            x -=2;
            y += 2;
        }
        base += 1024;
    }

    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
