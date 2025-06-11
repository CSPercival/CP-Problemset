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

void factor(int x, vector<int> &p){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            p.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1){
        p.push_back(x);
    }
}

int genmask(int x, vector<int> &p){
    int ans = 0;
    int mask = 1;
    for(int i : p){
        if(x % i == 0) ans |= mask;
        mask <<= 1;
    }
    return ans;
}

int findway(vector<int> &mask){
    if(mask[0] == 0) return 1;
    if(__builtin_popcount(mask[0]) == 1) return 2;
    for(int i = 0; i < mask.size(); i++){
        for(int j = 0; j < mask.size(); j++){
            if((mask[i] & mask[j]) == 0) return 2;
        }
    }
    for(int i = 0; i < mask.size(); i++){
        for(int j = 0; j < mask.size(); j++){
            if(i == j) continue;
            for(int i2 = 0; i2 < mask.size(); i2++){
                if(i == i2 || j == i2) continue;
                if((mask[i] & mask[j] & mask[i2]) == 0) return 3;
            }
        }
    }
    for(int i = 0; i < mask.size(); i++){
        for(int j = 0; j < mask.size(); j++){
            if(i == j) continue;
            for(int i2 = 0; i2 < mask.size(); i2++){
                if(i == i2 || j == i2) continue;
                for(int j2 = 0; j2 < mask.size(); j2++){
                    if((mask[i] & mask[j] & mask[i2] & mask[j2]) == 0) return 4;
                }
            }
        }
    }
    return 5;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << "0\n";
        return;
    }
    int nwd = a[0];
    for(int i = 1; i < n; i++){
        nwd = gcd(nwd, a[i]);
    }
    for(int i = 0; i < n; i++){
        a[i] /= nwd;
    }
    sort(all(a));
    int gen1 = 10;
    if(a[0] == 1) gen1 = 0;
    vector<int> primes;
    vector<int> masks;
    for(int i = 0; i < n && gen1 > 1; i++){
        primes.clear();
        factor(a[i], primes);
        masks.clear();
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            masks.push_back(genmask(a[j], primes));
        }
        sort(all(masks));
        masks.resize(distance(masks.begin(), unique(all(masks))));
        // cout << a[i] << " " << masks << "\n";
        gen1 = min(gen1, findway(masks));
    }
    // cout << gen1 << "\n";
    int ans = gen1;
    for(int i = 0; i < n; i++){
        if(a[i] != 1) ans++;
    }
    if(gen1 > 0) ans--;
    cout << ans << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
