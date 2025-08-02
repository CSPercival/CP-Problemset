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

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.nd.st != b.nd.st) return a.nd.st < b.nd.st;
    if(a.nd.nd != b.nd.nd) return a.nd.nd < b.nd.nd;
    return a.st < b.st;
}
bool cmp2(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.nd.nd != b.nd.nd) return a.nd.nd < b.nd.nd;
    if(a.nd.st != b.nd.st) return a.nd.st < b.nd.st;
    return a.st < b.st;
}

void solve(){
    int n; 
    cin >> n;
    int x, y;
    vector<pair<int,int>> p(n);
    vector<pair<int,pair<int,int>>> sp(n);
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        p[i] = {x,y};
        sp[i] = {i,{x,y}};
    }
    vector<pair<int,pair<int,int>>> q[4];
    sort(all(sp), cmp);
    for(int i = 0; i < n/2; i++){
        q[2].push_back(sp[i]);
    }
    for(int i = n/2; i < n; i++){
        q[1].push_back(sp[i]);
    }
    sort(all(q[1]), cmp2);
    sort(all(q[2]), cmp2);
    while(q[0].size() + q[3].size() < n/2){
        if(q[1].empty()){
            q[3].push_back(q[2].back());
            q[2].pop_back();
            continue;
        }
        if(q[2].empty()){
            q[0].push_back(q[1].back());
            q[1].pop_back();
            continue;
        }
        if(q[1].back().nd.nd > q[2].back().nd.nd){
            q[0].push_back(q[1].back());
            q[1].pop_back();
            continue;
        } else {
            q[3].push_back(q[2].back());
            q[2].pop_back();
            continue;
        }
    }
    // cout << q[0] << "\n";
    // cout << q[1] << "\n";
    // cout << q[2] << "\n";
    // cout << q[3] << "\n";
    for(int i = 0; i < q[0].size(); i++){
        cout << q[0][i].st + 1 << " " << q[2][i].st + 1 << "\n";
    }
    for(int i = 0; i < q[1].size(); i++){
        cout << q[1][i].st + 1 << " " << q[3][i].st + 1 << "\n";
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
