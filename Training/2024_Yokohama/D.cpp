#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(0);ios_base::sync_with_stdio(false)

typedef long long ll;
#define int ll

template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

template<typename T>
using vc = vector<T>;

ll mod = 998244353;

struct Tree{
    string code;

    int nleaf;
    int nall;
    int logc = 20;
    int root = 1;
    vector<vector<int>> g;
    vector<int> p;
    vector<vector<int>> jumps;
    vector<pair<int,int>> lims;
    vector<int> nums;
    vector<int> dep;
    
    Tree(string incode){
        code = incode;
        nleaf = code.size() + 5;
        nall = code.size() + 5;
        // nall = incode.size();
        // exit(0);
        g.resize(nall + 1);
        p.resize(nall + 1);
        lims.assign(nall + 1, {1e9, -1});
        nums.resize(nleaf+1);
        dep.resize(nall + 1);
        jumps.resize(nall + 1, vector<int>(logc, 0));
        parse_();
        // for(int i = 0; i <= nall; i++){
        //     cout << i << " " << lims[i].st << " " << lims[i].nd << "\n";
        // }
        // cout << g << "\n";
        get_lims(1, 0);
        binary_lift();
        // for(int i = 0; i <= nall; i++){
        //     cout << i << " " << lims[i].st << " " << lims[i].nd << "\n";
        // }
        // cout << lims << "\n";
    }

    void parse_(){
        int node = 0, cnt = 0, leaf = 1;
        for (char c: code) {
            if (c == '(') {
                cnt++;
                int child = cnt;
                g[node].push_back(child);
                g[child].push_back(node);
                p[child] = node;
                node = child;
            }
            else if (c == '1') {
                cnt++;
                int child = cnt;
                g[node].push_back(child);
                g[child].push_back(node);
                p[child] = node;
                // node = child;
                lims[child] = {leaf, leaf};
                nums[leaf] = child;
                leaf++;
            }
            else {
                node = p[node];
            }
        }
    }

    pair<int,int> get_lims(int idx, int par){
        dep[idx] = dep[par] + 1;
        pair<int, int> alims = lims[idx];
        pair<int, int> tlims = lims[idx];
        for(int i : g[idx]){
            if(i == par) continue;
            tlims = get_lims(i, idx);
            alims.st = min(tlims.st, alims.st);
            alims.nd = max(tlims.nd, alims.nd);
        }
        lims[idx] = alims;
        return alims;
    }

    void binary_lift(){
        for(int i = 1; i <= nall; i++){
            jumps[i][0] = p[i];
        }
        for(int i = 1; i <= nall; i++){
            for(int j = 1; j < logc; j++){
                jumps[i][j] = jumps[jumps[i][j - 1]][j - 1];
            }
        }
    }

    int lca(int x, int y){
        x = nums[x];
        y = nums[y];
        if(dep[x] < dep[y]) swap(x,y);
        for(int i = logc - 1; i >= 0; i--){
            if(dep[jumps[x][i]] >= dep[y]){
                x = jumps[x][i];
            }
        }
        if(x == y){
            return x;
        }
        for(int i = logc - 1; i >= 0; i--){
            if(jumps[x][i] != jumps[y][i]){
                x = jumps[x][i];
                y = jumps[y][i];
            }
        }
        return p[x];
    }

    pair<int,int> find_lim(int x, int y){
        return lims[lca(x, y)];
    }
};

void solve_(){

    string codet1, codet2;
    cin >> codet1 >> codet2;
    int n = (codet1.size() + 2) / 3;
    // cout << n << "\n";
    Tree t1(codet1);
    Tree t2(codet2);
    ll ans = 1;
    int mini, maxi;
    pair<int,int> lim1, lim2;
    for(int i = 1; i < n; i++){
        // mini = min(t1.find_min(i, i + 1), t2.find_min(i, i + 1));
        lim1 = t1.find_lim(i, i + 1);
        lim2 = t2.find_lim(i, i + 1);
        mini = max(lim1.st, lim2.st);
        maxi = min(lim1.nd, lim2.nd);
        // cout << mini << " " << maxi << "\n";
        ans *= ((i - mini + 1) * (maxi - (i + 1) + 1)) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}

void preprocessing_(){

}

int32_t main(){
    BOOST;
    preprocessing_();
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve_();
    }
    return 0;
}
