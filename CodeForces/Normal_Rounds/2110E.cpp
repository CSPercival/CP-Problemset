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


bool euler(int n, int m, vector<vector<pair<int,int>>> &g, vector<int> &ans){
    vector<int> alive(m + 1, 1);
    int currv = 0;
    int noodd = 0;
    for(int i = 0; i < n; i++){
        if(g[i].size() && currv == 0) currv = i;
        if(g[i].size()&1){
            currv = i;
            noodd++;
        }
    }
    if(noodd > 2) return false;
    vector<int> dead(m + 1, 0);
    vector<pair<int,int>> estack;
    while(true){
        while(g[currv].size() && dead[g[currv].back().nd])
            g[currv].pop_back();
        if(g[currv].size()){
            dead[g[currv].back().nd] = 1;
            estack.push_back({currv, g[currv].back().nd});
            currv = g[currv].back().st;
        } else {
            if(estack.empty()) break;
            currv = estack.back().st;
            ans.push_back(estack.back().nd);
            estack.pop_back();
        }
    }
    if(ans.size() != m) return false;
    return true;
}

void solve(){
    int n; 
    cin >> n;
    
    vector<vector<pair<int,int>>> g(5 * n);
    vector<pair<int,int>> snd(n);
    map<int,int> oth;
    vector<int> hto(2 * n);
    int si,ti,wi;
    for(int i = 0; i < n; i++){
        cin >> snd[i].st >> snd[i].nd;
        hto[2 * i] = snd[i].st;
        hto[2 * i + 1] = snd[i].nd;
    }
    sort(all(hto));
    hto.erase(unique(all(hto)), hto.end());
    for(int i = 0; i < hto.size(); i++){
        oth[hto[i]] = i;
    }

    int shift = hto.size();
    for(int i = 0; i < n; i++){
        g[oth[snd[i].st]].push_back({oth[snd[i].nd] + shift, i});
        g[oth[snd[i].nd] + shift].push_back({oth[snd[i].st], i});
    }

    vector<int> ans;
    if(euler(hto.size() + shift, n, g, ans)){
        cout << "YES\n";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
        return;
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
