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


bool check(vector<int> a,vector<int> b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

void solve(){
    int n, k; cin >> n >> k;
    ll pot = 1;
    for(int i = 1; i <= min(10,n); i++){
        pot *= i;
    }
    if(n == 1 && k == 1){
        cout << "YES\n1\n";
        return;
    }
    if(((ll)k * (ll)(n+1))%2 == 1 || k > pot || k == 1 || k+1 == pot){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> perm[3];
    perm[0].assign(n,0);
    perm[1].assign(n,0);
    perm[2].assign(n,0);
    
    int tmp = 0;
    if(k&1){
        for(int id = 0; id < 3; id++){
            for(int i = 1; i <= n; i++){
                perm[id][i-1] = i;
            }
        }   
        int x = n;
        int ii = 0;
        ll wyn = 3 * (n+1)/2;
        for(ii = 0; x >= 1; ii++, x-=2){
            perm[1][ii] = x;
            perm[2][ii] = wyn - ii - 1 - x;
        }
        x = n - 1;
        for(;x >= 2;ii++, x -= 2){
            perm[1][ii] = x;
            perm[2][ii] = wyn - ii - 1 - x;
        }
        for(int id = 0; id < 3; id++){
            for(int i : perm[id]){
                cout << i << " ";
            }
            cout << "\n";
        }
        // tmp = 3;
        k -= 3;
    }
    vector<int> p(n), po(n);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }
    // cout << k << endl;
    do {
        for(int i = 0; i < n; i++){
            po[i] = n + 1 - p[i];
        }
        // cout << "XD" << endl;
        // cout << p << "\n";
        // cout << po << "\n";
        if(check(p,perm[0]) || check(p,perm[1]) || check(p,perm[2]) || check(po,perm[0]) || check(po,perm[1]) || check(po,perm[2]) ) continue;
        for(int i : p){
            cout << i << " ";
        }
        cout << "\n";
        for(int i : po){
            cout << i << " ";
        }
        cout << "\n";
        k -= 2;
    } while (next_permutation(p.begin(),p.end()) && k > 0);
    // cout << k << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
