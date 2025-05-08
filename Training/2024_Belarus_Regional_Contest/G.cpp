#include<bits/stdc++.h>

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(0);ios_base::sync_with_stdio(false)

typedef long long ll;
//#define int ll

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

vector<int> mi;

void Manacher(vector<int> &text, vector<int> &ans){
    int n = text.size();
    text.insert(text.begin(), 1e5);
    text.push_back(1e7);
    ans.resize(n + 2);
    ans[0] = 1;
    int l = 0, r = 1;
    

    auto triv = [&text](int cent, int start_idx) -> int {
        while(text[start_idx] == text[2 * cent - start_idx]) start_idx++;
        return start_idx;
    };

    int last_idx;
    for(int i = 1; i <= n; i++){
        if(i >= r){
            last_idx = triv(i, i + 1);
        } else {
            last_idx = min(r, ans[l + r - i] + i);
            if(last_idx == r){
                last_idx = triv(i, last_idx);
            }
        }
        ans[i] = last_idx - i;
        if(last_idx > r){
            r = last_idx;
            l = 2 * i - last_idx;
        }
    }
}

ll count_div(vector<int> &ai, int d){
    vector<int> bi((2 * ai.size()) + 1);
    int m1 = -1;
    int tmp;
    int hash = 1e6;
    for(int i = 0; i < ai.size(); i++){
        tmp = (ai[i] * m1) % d;
        if(tmp < 0) tmp += d;
        m1 *= -1;

        bi[i * 2] = hash;
        bi[i * 2 + 1] = tmp;
    }
    bi[2 * ai.size()] = hash;
    vector<int> pal;
    Manacher(bi, pal);
    // cout << pal << "\n";
    // cout << bi << "\n";

    ll ans = 0;
    for(int i = 1; i < bi.size(); i += 2){
        ans += pal[i] / 2;
    }
    return ans;
}

ll count_exactly(vector<ll> &div_by, int d){
    ll ans = 0;
    for(int i = 1; i <= 200/d; i++){
        ans += mi[i] * div_by[i * d];
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> ai(n);
    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }
    vector<ll> div_by(210, 0);
    for(int i = 1; i <= 200; i++){
        div_by[i] = count_div(ai, i);
    }

    ll ans = 0;
    for(int i = 1; i <= 200; i++){
        // cout << i << ": " << count_exactly(div_by, i) << "\n"; 
        ans += count_exactly(div_by, i) * i;
    }
    cout << ans << "\n";
}

void count_mi(int n){
    mi.resize(n + 1);
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        tmp = i;
        int ctr = 0;
        for(int div = 2; div <= tmp; div++){
            if(tmp % div == 0){
                if(tmp % (div * div) == 0){
                    mi[i] = 0;
                    ctr = -1;
                    break;
                } else {
                    ctr++;
                }
                while((tmp % div) == 0) tmp /= div;
            }
        }
        if(ctr == -1){ 
            mi[i] = 0;
        } else {
            if(ctr&1){
                mi[i] = -1;
            } else {
                mi[i] = 1;
            }
        }
    }
}

int main(){
    BOOST;

    count_mi(200);
    // cout << mi << "\n";
    int q = 1;
    while(q--){
        solve();
    }

    // vector<int> text = {1,2,3,2,3,2,1,2,3,4,5,4,3,1};
    // vector<int> pal;
    // Manacher(text, pal);
    return 0;
}
/*
[1, 1, 1, 2, 4, 2, 1, 3, 1, 1, 1, 3, 1, 1, 1, 0]


*/