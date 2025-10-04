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

struct SegTree{
    vector<int> t;
    vector<int> p;
    int shift = 1;
    int n;
    
    SegTree(int in_n){
        n = in_n;
        while(shift <= n) shift <<= 1;
        t.resize(2 * shift, 0);
        p.resize(2 * shift, 0);
    }

    void push(int idx){
        t[idx] += p[idx];
        if(idx < shift){
            p[2 * idx] += p[idx];
            p[2 * idx + 1] += p[idx];
        }
        p[idx] = 0;
    }

    void modify(int cl, int cr, int ql, int qr, int idx, int val, int mode){
        push(idx);
        if(cr <= ql || qr <= cl) return;
        if(ql <= cl && cr <= qr){
            if(mode){
                p[idx] = 0;
                t[idx] = 0;
            } else {
                p[idx] += val;
            }
            push(idx);
            return;
        }
        modify(cl, (cl + cr)/2, ql, qr, idx * 2, val, mode);
        modify((cl + cr)/2, cr, ql, qr, idx * 2 + 1, val, mode);
        t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
    }

    void add(int l, int r, int val){
        modify(0, shift, l, r, 1, val, 0);
    }

    void clear(int idx){
        modify(0, shift, idx, idx + 1, 1, 0, 1);
    }

    int maxi(){
        return t[1];
    }

    void print(){
        cout << "t: " << t << "\n";
        cout << "p: " << p << "\n";
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }   
    SegTree tree(n + 1);
    for(int i = 1; i <= n; i++){
        // cout << "i: " <<  i << "\n";
        // tree.print();
        tree.clear(a[i]);
        // tree.print();
        if(a[i] != 0)
            tree.add(0, a[i], 1);
        // tree.print();
        cout << tree.maxi() << " ";
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
