#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int inf = 1e9;

struct suffix_tree{
    struct node{
        map<int, int> g;
        int link;
        int l;
        int r;
        int p;
    };
    vector<node> t;
    int x, edge;
    
    vector<int> suf;
    vector<int> deep;
    vector<int> real;
    vector<int> word;
    suffix_tree(){
        t = vector<node>(2, {{}});
        for(int i=-1; i<=150; i++) t[0].g[i] = 1;
        t[1].l = -1;
        x = 1, edge = 0;
    }

    void modify(int c){
        word.pb(c);
        while(true){
            if(t[x].r <= edge){
                if(t[x].g.count(c)){
                    x = t[x].g[c];
                    edge = t[x].l;
                }
                else{
                    t[x].g[c] = t.size();
                    suf.pb(t.size());
                    t.pb({{}, 0, (int)word.size()-1, inf, x});
                    x = t[x].link;
                    edge = t[x].r;
                    continue;
                }
            }
            if(edge == -1 || word[edge] == c){edge++; return;}

            int last = t.size();
            suf.pb(last+1);
            t.pb({{}, 0, t[x].l, edge, t[x].p});
            t.pb({{}, 0, (int)word.size()-1, inf, last});
            t[last].g[word[edge]] = x;
            t[last].g[c] = last+1;
            t[t[last].p].g[word[t[last].l]] = last;
            t[x].l = edge;
            t[x].p = last;

            x = t[t[last].p].link;
            edge = t[last].l;
            while(edge < t[last].r) x = t[x].g[word[edge]], edge += t[x].r - t[x].l;
            t[last].link = edge == t[last].r ? x : (int)t.size();
            edge = t[x].r - (edge - t[last].r);
        }
    }

    void dfs(int x){
        deep[x] = deep[t[x].p] + 1;
        real[x] = real[t[x].p] + t[x].r - t[x].l;
        real[x] = min(real[x], (int)word.size());
        for(auto it : t[x].g) dfs(it.nd);
    }

    void treez(){
        int n = t.size();
        deep = vector<int>(n);
        real = vector<int>(n);
        dfs(1);
    }
};

void solve() {
    suffix_tree ts;
    string s;
    cin >> s;
    int n = s.size();
    assert(n > 1);
    for(auto it : s) ts.modify(it);
    ts.modify('$');
    ts.treez();

    auto leaf = [&](int x){
        if(ts.t[x].g.empty()) return true;
        return false;
    };

    // printf("deep[%d]= %d\n", ts.suf[2], ts.deep[ts.suf[2]]);
    // exit(0);

    int ans = 2;
    for(int i=0; i<n-1; i++){
        int x = ts.t[ts.suf[i]].p;
        if(x <= 1) continue;
        int y = ts.t[x].link;
        if(y <= 1) continue;
        
        if(i == 0){
            x = ts.suf[i];
            printf("x = {%d, %d}\n", ts.t[x].l, ts.t[x].r);
            printf("y = {%d, %d}\n", ts.t[y].l, ts.t[y].r);

            printf("y = %d\n", y);
            exit(0);
        }

        for(auto [c, xnxt] : ts.t[x].g){
            if(!ts.t[y].g.count(c)) continue;
            auto ynxt = ts.t[y].g[c];
            if(leaf(xnxt) && !leaf(ynxt)){
                int d = ts.deep[x]+1;
                // if(d == 3){
                    // printf("x = {%d, %d}\n", ts.t[x].l, ts.t[x].r);
                    // printf("y = {%d, %d}\n", ts.t[y].l, ts.t[y].r);

                    // cout << i << "\n";
                    // return;
                // }
                ans = max(ans, d);
            }
        }
    }
    cout << ans << "\n";
    // ts.modify('$');
    // ts.treez();

    // for(int i=1; i<=13; i++){
    //     printf("link[%d] = %d\n", i, ts.t[i].link);
    // }
    // for(int i=0; i<=n; i++){
        // printf("suf[%d] = %d, deep[%d] = %d, ", i, ts.suf[i], ts.suf[i], ts.deep[ts.suf[i]]);
        // printf("real[%d] = %d, link[%d] = %d\n", ts.suf[i], ts.real[ts.suf[i]], ts.suf[i], ts.t[ts.suf[i]].link);
        // for(int j=1; j<ts.t.size(); j++){
        //     cout << j << " " << ts.t[j].p << "\n";
        // }
    // }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    
}