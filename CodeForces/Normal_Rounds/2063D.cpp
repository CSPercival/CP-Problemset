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


void solve(){
    int n; cin >> n;
    int m; cin >> m;
    vector<int> ai(n);
    vector<int> bi(m);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }
    for(int i = 0; i < m; i++){
        cin >> bi[i];
    }
    if(n < m){
        swap(n, m);
        swap(ai, bi);
    }
    // for(int i = 0; i < n; i++){
    //     cout << ai[i] << " ";
    // }
    // cout << "\n";
    sort(all(ai));
    sort(all(bi));

    int fmax = 0;
    if(n - m <= m){
        fmax = n - m;
        fmax += ((m - (n - m)) * 2) / 3;
    } else {
        fmax = m;
    }
    vector<int> rasa(n/2 + 1, 0);
    vector<int> rasb(m/2 + 1, 0);

    for(int i = 0; i < n/2; i++){
        rasa[i] = ai[n - 1 - i] - ai[i];
    }
    for(int i = 0; i < m/2; i++){
        rasb[i] = bi[m - 1 - i] - bi[i];
    }
    
    cout << fmax << "\n";
    int idx1 = 0, idx2 = 0;
    int zap2 = m, zap1 = n;
    ll ans = 0;
    for(int i = 1; i <= fmax; i++){
        if(zap2 >= 2){
            if(zap1 >= 2){
                if(rasa[idx1] > rasb[idx2]){
                    ans += rasa[idx1];
                    idx1++;
                    zap2--;
                    zap1 -= 2;
                } else {
                    ans += rasb[idx2];
                    idx2++;
                    zap1--;
                    zap2 -= 2;
                }
            } else {
                if(zap1 == 1){
                    ans += rasb[idx2];
                    idx2++;
                    zap2 -= 2;
                    zap1 -= 1;
                } else {
                    idx1--;
                    ans -= rasa[idx1];
                    zap2 += 1;
                    zap1 += 2;
                    ans += rasb[idx2];
                    zap2 -= 2;
                    zap1 --;
                    idx2++;
                    ans += rasb[idx2];
                    zap2 -= 2;
                    zap1 --;
                    idx2++;
                }
            }
        } else {
            if(zap2 == 1){
                ans += rasa[idx1];
                idx1++;
                zap2--;
                zap1 -= 2;
            } else {
                idx2--;
                ans -= rasb[idx2];
                zap1 += 1;
                zap2 += 2;
                ans += rasa[idx1];
                zap1 -= 2;
                zap2 --;
                idx1++;
                ans += rasa[idx1];
                zap1 -= 2;
                zap2 --;
                idx1++;
            }
        }
        cout << ans << " ";
    }
    if(fmax != 0)
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
