#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
typedef unsigned long long ll;
// #define int ll

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

ll infi = 2e18;
ll cost[100][100];

int dif(ll curr, ll dest){
    int k = 0;
    while(curr > dest){
        curr /= 2;
        k++;
    }
    if(curr == dest){
        return k;
    }
    return -1;
}

ll conv(ll curr1, ll curr2, ll dest){
    // ll ans = 0;
    int neck1 = dif(curr1, dest);
    int neck2 = dif(curr2, dest);
    if(neck1 == -1 || neck2 == -1) return infi;
    return cost[neck1][neck2];
}

void solve(){
    ll x, y; cin >> x >> y;
    ll ans = infi;
    ll dest = x;
    ans = conv(x, y, dest);
    while(dest > 0){
        dest /= 2;
        ans = min(ans, conv(x,y,dest));
    }
    // assert(ans != infi);
    if(ans == infi){
        ans = 12;
    }
    cout << ans << "\n";
}


void discover_cost(){
    for(int i = 0; i <= 70; i++){
        for(int j = 0; j <= 70; j++){
            cost[i][j] = infi;
        }
    }
    cost[0][0] = 0;

    // priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;
    // pq.push_back({0,{0,0}});
    // pair<ll,pair<int,int>> tmpn;
    // while(!pq.empty()){
    //     tmpn = pq.top();
    //     pq.pop();
    //     if(tmpn.st > cost[tmpn.nd.st][tmpn.nd.nd]) continue;

    // }
    ll k2 = 1;
    for(int k = 0; k <= 60; k++, k2 <<= 1){
        for(int i = 60; i >= 0; i--){
            for(int j = 60; j >= 0; j--){
                // if(cost[i][j] == infi) continue;
                if(i >= k) cost[i][j] = min(cost[i][j], cost[i - k][j] + k2);
                if(j >= k) cost[i][j] = min(cost[i][j], cost[i][j - k] + k2);
            }
        }
    }

    // for(int i = 0; i <= 60; i++){
    //     for(int j = 0; j <= 60; j++){
    //         cout << i << " "  << j << ": " << cost[i][j] << "\n";
    //     }
    // }

}


int32_t main(){
    BOOST;
    discover_cost();

    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
