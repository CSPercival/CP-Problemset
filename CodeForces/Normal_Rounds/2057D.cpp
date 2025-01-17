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

int minusinfi = 2e9 * -1;

struct SegTree{
    struct Node{
        int best;
        int prefmax, prefmin;
        int sufmax, sufmin;
        int siz;

        void print(){
            printf("    best: %lld\n", best);
            printf("    pref: %lld - %lld\n", prefmax, prefmin);
            printf("    suf: %lld - %lld\n", sufmax, sufmin);
            printf("    siz: %lld\n",siz);
        }
    };

    int n, shift = 1;
    vector<Node> t;

    SegTree(int in_n, vector<int> &ai){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.resize(2 * shift);

        for(int i = 0; i < n; i++){
            t[i + shift] = {-1, ai[i] - 1, ai[i] * -1 - 1, ai[i] - 1, ai[i] * -1 - 1, 1};
        }
        for(int i = n + shift; i < t.size(); i++){
            t[i] = {-1,minusinfi,minusinfi,minusinfi,minusinfi, 1};
        }
        for(int i = shift - 1; i > 0; i--){
            t[i] = merge(t[i << 1], t[(i << 1) + 1]);
        }
    }

    void update(int idx, int val){
        idx += shift;
        t[idx] = {-1, val - 1, val * -1 - 1, val - 1, val * -1 - 1, 1};
        for(idx >>= 1; idx > 0; idx >>= 1){
            t[idx] = merge(t[idx << 1], t[(idx << 1) + 1]);
        }
    }

    int query(){
        return t[1].best;
    }

    Node merge(Node a, Node b){
        Node ans;
        ans.best = max({a.best, b.best, a.sufmax + b.prefmin, a.sufmin + b.prefmax});
        ans.prefmax = max({a.prefmax, b.prefmax - a.siz});
        ans.prefmin = max({a.prefmin, b.prefmin - a.siz});
        ans.sufmax = max({b.sufmax, a.sufmax - b.siz});
        ans.sufmin = max({b.sufmin, a.sufmin - b.siz});
        ans.siz = a.siz + b.siz;
        return ans;
    }

    void print(){
        for(int i = 0; i <= n + shift; i++){
            printf("%lld: ", i);
            t[i].print();
        }
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }

    SegTree algo(n,ai);

    // algo.print();

    int p, x;
    cout << algo.query() + 1 << "\n";
    while(q--){
        cin >> p >> x;
        algo.update(p - 1,x);
        cout << algo.query() + 1<< "\n";
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
