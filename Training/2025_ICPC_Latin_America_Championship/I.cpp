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

struct LinkedList{
    
    struct Node{
        int val;
        int prev;
        int next;
        
        Node(){

        }

        Node(int in_val, int idx){
            val = in_val;
            prev = idx;
            next = idx;
        }

        Node(int in_val, int in_prev, int in_next){
            val = in_val;
            prev = in_prev;
            next = in_next;
        }
    };

    int n;
    // int start_idx = -1;
    vector<Node> i2v;
    vector<int> v2i;

    LinkedList(vector<int> &vals){
        n = vals.size();
        v2i.assign(1e6 + 10, -1);
        for(int i = 0; i < n; i++){
            Node tmp(vals[i], (i + n - 1) % n, (i + 1) % n);
            i2v.push_back(tmp);
            v2i[vals[i]] = i;            
        }
        // start_idx = 0;
    }

    void del(int val){
        int del_idx = v2i[val];
        n--;
        v2i[val] = -1;
        // if(del_idx == start_idx)
        //     start_idx = i2v[del_idx].next;
        // if(n == 0) return;
        i2v[i2v[del_idx].prev].next = i2v[del_idx].next;
        i2v[i2v[del_idx].next].prev = i2v[del_idx].prev;
        i2v[del_idx].prev = -1;
        i2v[del_idx].next = -1;
    }

    void add(int val, int bval){
        n++;
        int nidx = v2i[bval];
        int pidx = i2v[nidx].prev;
        int cidx = i2v.size();
        
        v2i[val] = cidx;

        Node tmp(val, pidx, nidx);
        i2v.push_back(tmp);
        i2v[nidx].prev = cidx;
        i2v[pidx].next = cidx;
    }

    int single_query(int start_idx, int k, vector<int> &a){
        int ctr = 0;
        int pidx = v2i[a[start_idx]];
        // if(pidx == -1) return 0;
        for(int i = start_idx; pidx != -1 && ctr <= k; i = (i + 1) % k){
            if(i2v[pidx].val != a[i]) break;
            pidx = i2v[pidx].next;
            ctr++;
        }
        return ctr;
    }

    int query(int k, vector<int> &a){
        int ans = 0;
        int ansik;
        for(int i = 0; i < k;){
            ansik = single_query(i, k, a);
            ans = max(ansik, ans);
            ansik = max(1, ansik);
            i += ansik;
        }
        return ans;
    }
};

int32_t main(){
    BOOST;
 
    int n; cin >> n;
    vector<int> p_val(n);
    for(int i = 0; i < n; i++){
        cin >> p_val[i];
    }
    
    int q; cin >> q;
    char mode;

    LinkedList p(p_val);

    int x,y,z;
    int k;
    vector<int> ai;
    while(q--){
        cin >> mode;
        if(mode == '-'){
            cin >> x;
            p.del(x);
        }
        if(mode == '+'){
            cin >> y >> z;
            p.add(y, z);
        }
        if(mode == '?'){
            cin >> k;
            ai.resize(k);
            for(int i = 0; i < k; i++){
                cin >> ai[i];
            }  
            int ans = p.query(k, ai);
            if(ans > k){
                cout << "*\n";
            } else {
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
