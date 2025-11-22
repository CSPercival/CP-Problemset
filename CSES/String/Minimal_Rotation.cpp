#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Hash{
    string s;
    int n;
    int mod;
    int p;
    vector<ll> pk;
    vector<ll> h;
    Hash(string &ins, int inmod, int inp){
        s = ins; mod = inmod; p = inp;
        n = s.size();
        pk.resize(n);
        h.resize(n);
        pk[0] = 1;
        h[0] = 0;
        for(int i = 1; i < n; i++){
            pk[i] = (pk[i - 1] * p) % mod;
            h[i] = (h[i - 1] * p + s[i] - 'a' + 1) % mod;
        }
    }

    int get_hash(int l, int r){
        assert(l > 0);
        l--;
        int ans = (h[l] * pk[r - l] - h[r]) % mod;
        if(ans < 0) ans += mod;
        return ans;
    }

    bool cmp(int l1, int r1, int l2, int r2){
        int swapped = 0;
        if(r1 - l1 > r2 - l2){
            swapped = 1;
            swap(l1, l2);
            swap(r1, r2);
        }
        int shift = r1 - l1;
        if(get_hash(l1, l1 + shift) == get_hash(l2, l2 + shift)) return 1^swapped;
        int po = -1, ko = shift, sr;
        while(po + 1 < ko){
            sr = (po + ko) / 2;
            if(get_hash(l1, l1 + sr) == get_hash(l2, l2 + sr)){
                po = sr;
            } else {
                ko = sr;
            }
        }
        return (s[l1 + ko] < s[l2 + ko]) ^ swapped;
    }
};

struct CMP{
    Hash *h;
    int n;

    CMP(Hash *inh, int inn){
        h = inh;
        n = inn;
    }

    bool operator()(int idxa, int idxb){
        if(idxa == 0 || idxb == 0) return false;
        return h->cmp(idxa, idxa + n - 1, idxb, idxb + n - 1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string text; cin >> text;

    int n = text.size();
    text = "#" + text + text + "$";
    Hash hs(text, 1e9 + 7, 31);

    vector<int> rot(n);
    CMP cmp(&hs, n);
    iota(rot.begin(), rot.end(), 1);
    auto it = min_element(rot.begin(), rot.end(), cmp);
    for(int i = (*it); i < (*it) + n; i++){
        cout << text[i];
    }
    cout << "\n";
    return 0;
}
