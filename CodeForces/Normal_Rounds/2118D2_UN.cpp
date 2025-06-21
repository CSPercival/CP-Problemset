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

vector<int> pred[200010];
bool on_cycle[200010];
ll k;

bool check(ll del1, ll del2, ll dist){
    if((del1 + dist) % k == del2) return true;
    return false;
}

void find_cycle(int idx){
    on_cycle[idx] = 0;
    //deb   cout << idx << " findcycle" << endl;
    for(int i : pred[idx]){
        find_cycle(i);
    }
}

ll vmod(ll x){
    x %= k;
    if(x < 0) return x + k;
    return x;
}

int bin_srch(vector<ll> &idxs, vector<pair<ll,ll>> &traf, ll pos){
    //deb   cout << idxs << "\n";
    //deb   cout << traf << "\n";
    //deb   cout << pos << endl;
    // reverse(all(idxs));
    //deb  cout << "bs0" << endl;

    if(traf[idxs[0]].st < pos) return -1;
    //deb  cout << "bs1" << endl;
    if(pos <= traf[idxs.back()].st) return 0;
    //deb  cout << "bs2" << endl;
    int po = idxs.size() - 1, ko = 0, sr;
    while(po < ko){
        sr = (po + ko)/2;
        if(traf[idxs[sr]].st < pos){
            po = sr - 1;
        } else {
            ko = sr;
        }
    }
    //deb cout << "ko " << idxs[ko] << endl;
    return idxs[ko];
}

void solve(){
    ll n, q; cin >> n >> k;
    vector<pair<ll,ll>> traf(n);    //pos,delay
    for(int i = 0; i < n; i++) cin >> traf[i].st;
    for(int i = 0; i < n; i++) cin >> traf[i].nd;

    vector<int> succ(2 * n, -1);    // nastepny w lewo i prawo(i + n)
    // vector<bool> on_cycle(2 * n, 1);

    map<ll, vector<int>> mt;

    for(int i = 0; i < 2 * n; i++){
        pred[i].clear();
        on_cycle[i] = true;
    }

    int vkey;
    for(int i = 0; i < n; i++){
        vkey = vmod(traf[i].nd + traf[i].st);
        //deb cout << i << ": " << traf[i] << " " << vkey << "\n";
        if(mt.count(vkey)){
            succ[i] = mt[vkey].back();
            pred[succ[i]].push_back(i);
        }
        mt[vkey].push_back(i + n);
    }

    //deb   cout << "git1" << endl;

    mt.clear();

    for(int i = n - 1; i >= 0; i--){
        vkey = vmod(traf[i].nd - traf[i].st);
        if(mt.count(vkey)){
            succ[i + n] = mt[vkey].back();
            pred[succ[i + n]].push_back(i + n);
        }
        mt[vkey].push_back(i);
    }
    //deb   cout << "git2" << endl;

    //deb  cout << "mt\n";
    // for(auto it : mt){
    //     reverse(all(it.nd));
    //     //  cout << it.st << ":  " << it.nd << "\n";
    // }
    //deb for(auto it : mt){
        // reverse(all(it.nd));
        //deb  cout << it.st << ":  " << it.nd << "\n";
    //deb }
    // mt.clear();
    //deb   cout << "git3" << endl;


    // for(int i = 0; i < n; i++){
    //     for(int j = i - 1; j >= 0; j--){
    //         if(check(traf[i].nd, traf[j].nd, traf[i].st - traf[j].st)){
    //             succ[i] = j + n;
    //             pred[j + n].push_back(i);
    //             break;
    //         }
    //     }
    //     for(int j = i + 1; j < n; j++){
    //         if(check(traf[i].nd, traf[j].nd, traf[j].st - traf[i].st)){
    //             succ[i + n] = j;
    //             pred[j].push_back(i + n);
    //             break;
    //         }
    //     }
    // }

    //deb   cout << succ;
    //deb   cout << endl;
    //deb  for(int i = 0; i < 2 * n; i++){
        //deb   cout << i << ":  " << pred[i] << "\n";
    //deb  }
    //deb  cout << endl;
    for(int i = 0; i < 2 * n; i++){
        if(succ[i] == -1){
            find_cycle(i);
        }
    }
    //deb for(int i = 0; i < 2 * n; i++){
    //deb     cout << i << " " << on_cycle[i] << "\n";
    //deb }

    ll spos;
    cin >> q;
    //deb cout << traf << "\n";
    //deb cout << endl;

    

    while(q--){
        cin >> spos;
        int gidx = -1;
        //deb  cout << "analize " << -spos << endl;
        
        //deb  cout << vmod(-spos) << "\n";
        if(mt.count(vmod(-spos))){
            //deb  cout << "szukanko " << endl;
            gidx = bin_srch(mt[vmod(-spos)], traf, spos);
        }

        //deb cout << gidx << " gidx\n";
        if(gidx == -1 || !on_cycle[gidx]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
        //deb  cout << "\n";
    }
    return 0;
}
