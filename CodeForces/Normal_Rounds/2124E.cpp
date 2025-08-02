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

int check(int diff, int l, int r, int sr, vector<ll> &pre){
    if((pre[sr - 1] - pre[l - 1]) < pre[r] - pre[sr]){
        if(pre[sr] - pre[l - 1] - (pre[r] - pre[sr]) <= diff){
            return sr;
        } else {
            return -1;
        }
    } else {
        if(pre[r] - pre[sr - 1] - (pre[sr - 1] - pre[l - 1]) <= diff){
            return sr - 1;
        } else {
            return -1;
        }
    }
}

void solve(){
    int n; 
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> pre(n + 1);
    ll sum = 0;
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    if(sum & 1){
        cout << "-1\n";
        return;
    }
    ll tsum = 0;
    for(int i = 0; i <= n; i++){
        if(pre[i] == pre[n] - pre[i]){
            cout << "1\n";
            for(int j = 1; j <= n; j++){
                cout << a[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    
    int rptr = 0;
    int lptr = 0;
    int l, sr = -1, r;
    ll bigdiff = -1;
    for(int i = 0; i <= n; i++){
        if(pre[i] < pre[n] - pre[i]){
            while(pre[rptr] - pre[i] < pre[n] - pre[rptr]) rptr++;
            sr = check(pre[i], i + 1, n, rptr, pre);
            if(sr != -1){
                bigdiff = pre[i];
                l = i + 1;
                r = n;
                break;
            }
        } else {
            while(pre[lptr] < pre[i] - pre[lptr]) lptr++;
            sr = check(pre[n] - pre[i], 1, i, lptr, pre);
            if(sr != -1){
                bigdiff = pre[n] - pre[i];
                l = 1;
                r = i;
                break;
            }
        }
    }
    if(sr == -1){
        cout << "-1\n";
        return;
    }

    cout << "2\n";
    vector<int> tans(n + 1, 0);
    ll smalldiff;
    ll tmp;
    int righti, lefti;
    for(int i = 1; i < l; i++){
        tans[i] = a[i];
    }
    for(int i = r + 1; i <= n; i++){
        tans[i] = a[i];
    }
    smalldiff = abs(pre[sr] - pre[l - 1] - (pre[r] - pre[sr])); 
    lefti = sr;
    righti = sr + 1;
    if(pre[sr] - pre[l - 1] < pre[r] - pre[sr]){
        while(smalldiff > 0){
            tmp = min(smalldiff, a[righti] - tans[righti]);
            smalldiff -= tmp;
            bigdiff -= tmp;
            tans[righti] += tmp;
            if(tans[righti] == a[righti]) righti++;
        }
    } else {
        while(smalldiff > 0){
            tmp = min(smalldiff, a[lefti] - tans[lefti]);
            smalldiff -= tmp;
            bigdiff -= tmp;
            tans[lefti] += tmp;
            if(tans[lefti] == a[lefti]) lefti--;
        }
    }
    assert((bigdiff&1) == 0);
    while(bigdiff > 0){
        tmp = min({bigdiff/2, a[lefti] - tans[lefti], a[righti] - tans[righti]});
        bigdiff -= tmp * 2;
        tans[lefti] += tmp;
        tans[righti] += tmp;
        if(tans[lefti] == a[lefti]) lefti--;
        if(tans[righti] == a[righti]) righti++;
    }
    for(int i = 1; i <= n; i++){
        cout << tans[i] << " ";
        a[i] -= tans[i];
    }
    cout << "\n";
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
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