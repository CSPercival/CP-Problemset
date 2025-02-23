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

int binsrch(int x, vector<int> &l){
    int p = 0, k = l.size() - 1, sr;
    while(k - p > 1){
        sr = (p + k) / 2;
        if(l[sr] <= x){
            p = sr;
        } else {
            k = sr;
        }
    }
    return p;
}

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> l(k + 1), r(k + 1);
    for(int i = 0; i < k; i++) {cin >> l[i]; l[i]--;}
    for(int i = 0; i < k; i++) {cin >> r[i]; r[i]--;}
    // cout << l << "\n";

    l[k] = n;


    int q; cin >> q;
    int idx;
    int a, b;
    vector<vector<pair<int,int>>> queries(k + 1, vector<pair<int,int>>());

    int xi;
    while(q--){
        cin >> xi;
        xi--;
        idx = binsrch(xi, l);
        a = min(xi, l[idx] + r[idx] - xi);
        b = max(xi, l[idx] + r[idx] - xi);
        queries[idx].push_back({a,b});
    }

    // cout << queries << "\n";

    int ctr1 = 0;
    char c1, c2;
    for(int i = 0; i < k; i++){
        sort(queries[i].begin(), queries[i].end());
        // cout << i << " " << queries[i] << "\n";
        ctr1 = 0;
        string s1, s2;
        int ctr2 = 0;
        for(int j = l[i]; j < (r[i] + l[i] + 1) / 2; j++){
            while(ctr2 < queries[i].size() && queries[i][ctr2].first <= j){
                ctr2++;
                ctr1++;
            }

            c1 = s[j];
            c2 = s[r[i] - (j - l[i])];
            if(ctr1 & 1){
                s1.push_back(c2);
                s2.push_back(c1);
            } else {
                s1.push_back(c1);
                s2.push_back(c2);
            }

        }
        if((r[i] - l[i] + 1) & 1){
            s1.push_back(s[(l[i] + r[i]) / 2]);
        }
        reverse(all(s2));
        cout << s1 << s2;
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
