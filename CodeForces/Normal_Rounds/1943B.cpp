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

struct Hash{
    ll p, m;
    vector<ll> h;
    vector<ll> rh;
    vector<ll> pk;
    string s;
    int n;
    Hash(int in_p, int in_m, string &in_s){
        s = "#" + in_s + "#";
        n = in_s.size();
        h.resize(s.size(),0);
        rh.resize(s.size(),0);
        pk.resize(s.size(),0);
        p = in_p;
        m = in_m;
        for(int i = 1; i <= n; i++){
            h[i] = (h[i - 1] * p + s[i] - 'a' + 1) % m;
        }
        for(int i = n; i >= 1; i--){
            rh[i] = (rh[i + 1] * p + s[i] - 'a' + 1) % m;
        }
        pk[0] = (1 % m);
        for(int i = 1; i <= n + 1; i++){
            pk[i] = (pk[i - 1] * p) % m;
        }
    }

    ll get_hash(int l, int r){
        if(l > r) return -1;
        ll ans = (h[r] - h[l - 1] * pk[r - l + 1]) % m;
        if(ans < 0) ans += m;
        return ans; 
    }

    ll get_rev_hash(int l, int r){
        if(l > r) return -1;
        ll ans = (rh[l] - rh[r + 1] * pk[r - l + 1]) % m;
        if(ans < 0) ans += m;
        return ans; 
    }

    bool alter(int l, int r){
        if(r - l + 1 <= 3) return false;
        int tr = r;
        int tl = r - 3;
        while(l <= tl){
            if(get_hash(tl, (tl + tr) / 2) != get_hash((tl + tr + 1) / 2, tr)) return false;
            tl -= tr - tl + 1;
        }
        
        tl = l;
        tr = l + 3;
        while(tr <= r){
            if(get_hash(tl, (tl + tr) / 2) != get_hash((tl + tr + 1) / 2, tr)) return false;
            tr += tr - tl + 1;
        }
        if((r - l)&1){
            //even
            if(s[l] != s[r - 1] || s[l + 1] != s[r]) return false;
        } else {
            //odd
            if(s[l] != s[r] || s[l + 1] != s[r - 1]) return false;
        }
        return true;
    }
};

struct Letrack{
    vector<vector<int>> let;
    Letrack(string &s){
        let.assign(s.size() + 1, vector<int>(30,0));
        for(int i = 0; i < s.size(); i++){
            let[i + 1] = let[i];
            let[i + 1][s[i] - 'a']++;
        }
    }

    bool mono(int l, int r){
        int diff = 0;
        for(int i = 0; i <= 'z' - 'a'; i++){
            if(let[r][i] - let[l - 1][i] > 0) diff++;
        }
        if(diff > 1) return false;
        return true;
    }
};

void solve(){
    int n,q; 
    cin >> n >> q;
    string s; cin >> s;

    Hash h1(37, 1e9 + 9, s);
    Hash h2(57, 888173173, s);
    Letrack let(s);

    int l, r;
    ll d;
    ll ans;
    while(q--){
        cin >> l >> r;
        d = r - l + 1;
        ans = 0;
        if(!let.mono(l,r)){
            if(h1.alter(l,r) && h2.alter(l,r)){
                d /= 2;
                ans = d * (d + 1);
            } else {
                ans = d * (d + 1)/2 - 1;
                if(h1.get_hash(l,(l + r)/2) == h1.get_rev_hash((l + r + 1)/2, r) && 
                    h2.get_hash(l,(l + r)/2) == h2.get_rev_hash((l + r + 1)/2, r)){
                    ans -= d;
                }
            }
        }
        cout << ans << '\n';
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
