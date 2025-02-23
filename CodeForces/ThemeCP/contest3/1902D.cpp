//Rating 1900
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

int dx[250];
int dy[250];
map<pair<int,int>, vector<int>> pos;
vector<pair<int,int>> path;

void move(pair<int,int> *p, char d){
    (*p).st += dx[d]; 
    (*p).nd += dy[d]; 
}

void follow_path(string &s){
    pair<int, int> p = {0,0};
    int t = 0;
    pos[p].push_back(t);
    path.push_back(p);

    for(int i = 0, t = 1; i < s.size(); i++, t++){
        move(&p,s[i]);
        // cout << p.st << " - " << p.nd << "\n";
        pos[p].push_back(t);
        path.push_back(p);
    }
}

pair<int,int> conv(pair<int,int> x, pair<int,int> c1, pair<int,int> c2){
    pair<int,int> center = {(c1.st + c2.st) / 2, (c1.nd + c2.nd) / 2};
    pair<int,int> nx;
    nx.st = center.st * 2 - x.st;
    nx.nd = center.nd * 2 - x.nd;
    return nx;
}

bool check(pair<int, int> p, int t1, int t2){
    if(pos.find(p) == pos.end()) return false;
    auto it = lower_bound(all(pos[p]), t1);
    if(it != pos[p].end() && (*it) <= t2) return true;
    return false;
}

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    pos.clear();
    path.clear();

    follow_path(s);

    // for(auto i : pos){
    //     cout << i << "\n";
    // }

    int x, y, l, r;
    pair<int,int> p,np;
    while(q--){
        cin >> p.st >> p.nd >> l >> r;
        p.st *= 2;
        p.nd *= 2;
        np = conv(p, path[l - 1], path[r]);

        if(check(p, 0, l - 1) || check(p, r, n) || check(np, l, r - 1)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

 
int32_t main(){
    BOOST;
    dx['L'] = -2;
    dx['R'] = 2;

    dy['D'] = -2;
    dy['U'] = 2;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
