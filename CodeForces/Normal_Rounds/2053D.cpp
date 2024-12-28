#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
#define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

ll mod = 998244353;

ll pot = 1;

ll fastpow(ll n, ll k){
    if(k == 0) return 1;
    ll tmp = fastpow(n, k/2);
    if(k&1) return (((tmp * tmp) % mod) * n) % mod;
    return (tmp * tmp) % mod;
}

ll modrev(ll x){
    return fastpow(x, mod - 2);
}

void add(int idx, vector<pair<ll,int>> &a, vector<pair<ll,int>> &b, ll *ans){
    (*ans) *= min(a[idx].st, b[idx].st);
    (*ans) %= mod;
}

void rem(int idx, vector<pair<ll,int>> &a, vector<pair<ll,int>> &b, ll *ans){
    (*ans) *= modrev(min(a[idx].st, b[idx].st));
    (*ans) %= mod;
}

void inc(int idx, vector<pair<ll,int>> &a, vector<ll> &conva, vector<pair<ll,int>> &b, vector<ll> &convb, ll*ans){
    int nidx = conva[idx - 1];
    // assert(a[nidx].nd == idx);
    int n = a.size();
    
    rem(nidx,a,b,ans);
    a[nidx].st++;
    if(nidx == n - 1 || a[nidx] <= a[nidx + 1]){
        // bez swap
        add(nidx,a,b,ans);
        return;
    }
    //swap
    int nidx2 = nidx;
    for(int i = pot; i > 0; i >>= 1){
        if(nidx2 + i < n && a[nidx2 + i].st < a[nidx].st){
            nidx2 += i;
        }
    }
    rem(nidx2, a, b, ans);
    swap(a[nidx], a[nidx2]);
    swap(conva[a[nidx].nd], conva[a[nidx2].nd]);
    add(nidx, a, b, ans);
    add(nidx2, a, b, ans);
}

void solve(){
    int n, q; cin >> n >> q;
    pot = 1;
    while(pot < n) pot <<= 1;
    vector<pair<ll,int>> ai(n),bi(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i].st;
        ai[i].nd = i;
    }
    for(int i = 0; i < n; i++){
        cin >> bi[i].st;
        bi[i].nd = i;
    }
    sort(all(ai));
    sort(all(bi));

    vector<ll> conva(n),convb(n);
    for(int i = 0; i < n; i++){
        conva[ai[i].nd] = i;
        convb[bi[i].nd] = i;
    }
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans *= min(ai[i].st, bi[i].st);
        ans %= mod;
    }
    cout << ans << " ";
    int o, x;
    int newx;
    // cout << ai << "\n";
    // cout << bi << "\n";
    // cout << conva << "\n";
    // cout << convb << "\n";
    while(q--){
        cin >> o >> x;
        if(o == 1){
            // inc a[x]
            inc(x, ai, conva, bi, convb, &ans);
        } else {
            // inc b[x]
            inc(x, bi, convb, ai, conva, &ans);
        }
        cout << ans << " ";
        // cout << ai << "\n";
        // cout << bi << "\n";
        // cout << conva << "\n";
        // cout << convb << "\n";
    }

    cout << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
