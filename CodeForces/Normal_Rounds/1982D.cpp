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
 
int val[510][510];
string snow[510];
int bil[510][510]; // balans ile0 - ile1
ll sum[2];
 
void count(int x, int y, int k){
    int ile0 = 0, ile1 = 0;
    for(int i = x; i < x + k; i++){
        for(int j = y; j < y + k; j++){
            if(snow[i][j] == '1'){
                ile1++;
            } else {
                ile0++;
            }
        }
    }
    bil[x][y] = ile0 - ile1;
}
 
void update_down(int x, int y, int k){
    bil[x][y] = bil[x - 1][y];
    for(int j = y; j < y + k; j++){
        if(snow[x - 1][j] == '1'){
            bil[x][y] += 1;
        } else {
            bil[x][y] -= 1;
        }
        if(snow[x - 1 + k][j] == '1'){
            bil[x][y] -= 1;
        } else {
            bil[x][y] += 1;
        }
    }
}
 
void update_right(int x, int y, int k){
    bil[x][y] = bil[x][y - 1];
    for(int i = x; i < x + k; i++){
        if(snow[i][y - 1] == '1'){
            bil[x][y] += 1;
        } else {
            bil[x][y] -= 1;
        }
        if(snow[i][y - 1 + k] == '1'){
            bil[x][y] -= 1;
        } else {
            bil[x][y] += 1;
        }
    }
}
 
void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> val[i][j];
        }
    }
 
    sum[0] = 0;
    sum[1] = 0;
 
    for(int i = 0; i < n; i++){
        cin >> snow[i];
        for(int j = 0; j < m; j++){
            // cin >> snow[i][j];
            sum[snow[i][j] - '0'] += val[i][j];
        }
    }
    if(sum[0] == sum[1]){
        cout << "YES\n";
        return;
    }
 
    // for(int i = 0; i <= n + 1; i++){
    //     snow[i][0] = -1;
    //     snow[i][m + 1] = -1;
    // }
    // for(int j = 0; j <= m + 1; j++){
    //     snow[0][j] = -1;
    //     snow[n + 1][j] = -1;
    // }
 
    vector<int> poss_mov;
 
    count(0,0,k);
 
    for(int i = 1; i < n - k + 1; i++){
        update_down(i,0,k);
    }
    for(int i = 0; i < n - k + 1; i++){
        for(int j = 1; j < m - k + 1; j++){
            update_right(i,j,k);
        }
    }
    for(int i = 0; i < n - k + 1; i++){
        for(int j = 0; j < m - k + 1; j++){
        //    cout << bil[i][j] << " ";
            if(bil[i][j] == 0) continue;
            poss_mov.push_back(abs(bil[i][j]));
        }
        //cout << "\n";
    }
    
 
    if(poss_mov.size() == 0){
        cout << "NO\n";
        return;
    }
 
    int small = poss_mov[0];
    for(int i = 1; i < poss_mov.size(); i++){
        small = __gcd(small,poss_mov[i]);
    }
 
    if(abs(sum[0] - sum[1]) % small == 0){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
 
 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}