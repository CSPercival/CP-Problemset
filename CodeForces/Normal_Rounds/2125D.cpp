#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
#define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

int mod = 998244353;

int mpow(int a, int k){
    if(k == 1) return a;
    int tmp = mpow(a,k/2);
    tmp = (tmp * tmp) % mod; 
    if(k&1){
        return (tmp * a) % mod;
    } else {
        return tmp;
    }
}

int rmod(int x){
    return mpow(x, mod - 2);
}

struct seg{
    int l,r,p,q;
};

bool cmp(seg &a, seg &b){
    if(a.l != b.l) return a.l < b.l;
    if(a.r != b.r) return a.r < b.r;
    if(a.p != b.p) return a.p < b.p;
    return a.q < b.q;
}

int get_nlu(int l, int r, vector<int> &nlu){
    return (nlu[r] * rmod(nlu[l - 1])) % mod;
}

int f3(int lim, vector<seg> &s){
    int po = 0, ko = s.size() - 1, sr;
    if(s.back().l <= lim) return s.size() - 1;
    while(po + 1 < ko){
        sr = (po + ko)/2;
        if(s[sr].l <= lim){
            po = sr;
        } else {
            ko = sr;
        }
    }
    return po;
}

int onlu(seg &s){
    return ((s.q - s.p) * rmod(s.q)) % mod;
}
int olu(seg &s){
    return (s.p * rmod(s.q)) % mod;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<seg> s(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> s[i].l >> s[i].r >> s[i].p >> s[i].q;
    }
    sort(all(s),cmp);
    vector<int> nlu(n + 1);
    nlu[0] = 1;
    for(int i = 1; i <= n; i++){
        // nlu[i] = (((nlu[i - 1] * (s[i].q - s[i].p)) % mod) * rmod(s[i].q)) % mod;
        nlu[i] = (nlu[i - 1] * onlu(s[i])) % mod;
    }

    vector<int> dp(m + 1);
    dp[0] = 1;
    int ptrl = 1, ptrr = 1;
    int cnlu = 1;
    int canlu = 1;
    int lasta;
    // while(ptrr <= n && s[ptrr].l == s[0].l){
    //     // cnlu = (((nlu[i - 1] * (s[i].q - s[i].p)) % mod) * rmod(s[i].q)) % mod;
    //     ptrr++;
    // }
    for(int i = 1; i <= m && ptrl <= n; i++){
        // cout << ptrl << " - " << ptrr << "\n";
        if(i < s[ptrl].l) continue;
        while(ptrr <= n && s[ptrr].l == s[ptrl].l){
            ptrr++;
        }   
        cnlu = get_nlu(ptrl, ptrr - 1, nlu);
        for(int j = ptrl; j < ptrr; j++){
            lasta = f3(s[j].r, s);
            canlu = (((cnlu * rmod(onlu(s[j]))) % mod) * olu(s[j])) % mod;
            if(ptrr <= n){
                canlu = (canlu * get_nlu(ptrr, lasta, nlu)) % mod;
            }
            dp[s[j].r] = (dp[s[j].r] + dp[s[j].l - 1] * canlu) % mod; 
        }
        ptrl = ptrr;
    }
    // cout << dp << "\n";
    cout << dp[m] << "\n";
}

 
int32_t main(){
    BOOST;
    
    // cout << (1 * rmod(2)) % mod << "\n";
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
