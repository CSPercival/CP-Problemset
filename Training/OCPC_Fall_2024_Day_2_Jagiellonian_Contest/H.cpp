#include<bits/stdc++.h>

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(0);ios_base::sync_with_stdio(false)

typedef long long ll;
typedef long double ld;
//#define int ll

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

struct Node{
    int id;
    int ans;
    int tid;
    int tl, tr;
    int degin;
    vector<int> oute;
    vector<int> bie;
};

struct Tree{
    int n;
    int shift;
    vector<int> t;
    vector<int> p;

    void build(int in_n, vector<int> &a){
        n = in_n;
        shift = 1;
        while(shift < n) shift <<= 1;
        t.assign(2 * shift, 0);
        p.assign(2 * shift, 0);
        for(int i = 0; i < n; i++){
            t[i + shift] = a[i];
        }
        for(int i = shift - 1; i > 0; i--){
            t[i] = max(t[i << 1], t[(i << 1) + 1]);
        }
    }
    
    int query(){
        return t[1];
    }

    void push(int idx){
        if(idx >= shift){
            p[idx] = 0;
            return;
        }
        t[(idx << 1)] += p[idx];
        t[(idx << 1) + 1] += p[idx];
        p[idx] = 0;
    }

    void Update(int l, int r, int val){
        update(1, 0, shift, l, r + 1, val);
    }

    void update(int idx, int trl, int trr, int l, int r, int val){
        push(idx);
        if(trr <= l || r <= trl) return;
        if(l <= trl && trr <= r){
            p[idx] += val;
            t[idx] += val;
            return;
        }
        update(idx << 1, trl, (trr + trl)/2, l, r, val);
        update((idx << 1) + 1, (trr + trl)/2, trr, l, r, val);
        t[idx] = max(t[idx << 1], t[(idx << 1) + 1]);
    }
};

struct NodeT{
    int stv;
    int n;
    int unl = 0;
    Tree t;
};

Node g[500010];
NodeT trees[500010];

int pptime;
void dfs(int idx, int par, int tid){
    pptime++;
    g[idx].tid = tid;
    g[idx].tl = pptime;
    g[idx].ans = 0;
    for(int v : g[idx].bie){
        if(v == par) continue;
        dfs(v, idx, tid);
    }
    pptime++;
    g[idx].tr = pptime;
}

void dfs2(int idx, int par, int dist, vector<int> &vals, vector<int> &v){
    v.push_back(idx);
    vals[g[idx].tl] = dist + g[idx].ans;
    vals[g[idx].tr] = dist + g[idx].ans;
    for(int i : g[idx].bie){
        if(i == par) continue;
        dfs2(i, idx, dist + 1, vals, v);
    }
}

void dfs3(int idx, int par, int tid){
    // cout << "o" << idx << endl;
    g[idx].ans = trees[tid].t.query();
    // cout << g[idx].ans << endl;
    for(int i : g[idx].bie){
        if(i == par) continue;
        // cerr << "ok1" << endl;
        trees[tid].t.Update(0, trees[tid].n - 1, 1);
        // cerr << "ok2" << endl;
        // cout << g[i].tl << " " << g[i].tr << endl;
        trees[tid].t.Update(g[i].tl, g[i].tr, -2);
        // cerr << "ok3" << endl;
        dfs3(i, idx, tid);

        trees[tid].t.Update(g[i].tl, g[i].tr, 2);
        trees[tid].t.Update(0, trees[tid].n - 1, -1);
    }
}

void process_tree(int tid, vector<int> &v){
    // cout << trees[tid].n << endl;
    vector<int> vals(trees[tid].n);
    dfs2(trees[tid].stv, 0, 0, vals, v);
    // for(int i : vals){
    //     cout << i << " "; 
    // }
    // cout << endl;
    trees[tid].t.build(trees[tid].n, vals);
    // cout << "git" << endl;

    dfs3(trees[tid].stv, 0, tid);
}

void solve(){
    int n, m; cin >> n >> m;
    int a, b; string s;

    for(int i = 1; i <= n; i++){
        g[i].id = i;
        g[i].tid = -1;
        g[i].degin = 0;
        g[i].oute.clear();
        g[i].bie.clear();
    }

    for(int i = 0; i < m; i++){
        cin >> a >> s >> b;
        if(s == "->"){
            g[a].oute.push_back(b);
            g[b].degin++;
        } else {
            g[a].bie.push_back(b);
            g[b].bie.push_back(a);
        }
    }
    queue<int> que;
    queue<int> tque;

    int tree_ctr = 0;
    for(int i = 1; i <= n; i++){
        if(g[i].tid == -1){
            pptime = -1;
            dfs(i, 0, tree_ctr);
            trees[tree_ctr].stv = i;
            trees[tree_ctr].n = pptime + 1;
            trees[tree_ctr].unl = pptime + 1;
            tree_ctr++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(g[i].degin == 0){
            if(g[i].bie.empty()){
                que.push(i);
            } else {
                trees[g[i].tid].unl -= 2;
                if(trees[g[i].tid].unl == 0){
                    tque.push(g[i].tid);
                }
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     printf("tid %d = %d\n",i, g[i].tid);
    // }

    int answer = 0;
    int idx = 0;
    vector<int> tmpv;
    while((!que.empty()) || (!tque.empty())){
        if(!tque.empty()){
            // cout << tque.front() << "\n";
            process_tree(tque.front(), tmpv);
            tque.pop();
            for(int i : tmpv){
                que.push(i);
            }
            tmpv.clear();
            continue;
        }
        idx = que.front();
        // cout << idx << endl;
        que.pop();
        for(int v : g[idx].oute){
            g[v].ans = max(g[v].ans, g[idx].ans + 1);
            g[v].degin--;
            if(g[v].degin == 0){
                if(g[v].bie.empty()){
                    que.push(v);
                } else {
                    trees[g[v].tid].unl -= 2;
                    if(trees[g[v].tid].unl == 0){
                        tque.push(g[v].tid);
                    }
                }
            }
        }
        answer = max(answer, g[idx].ans);
    }
    cout << answer << "\n";
}


int main(){
    BOOST;
    int q = 1; 
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}