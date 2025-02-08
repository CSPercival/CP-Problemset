#include<bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0)
#define st first
#define nd second
using namespace std;
typedef long long ll;

int mod;

struct Matrix{
    int v[2][2]={{1,0},{0,1}};
    
    void print(){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

struct SegmentTreePURQ{
    int n, shift = 1;
    vector<Matrix> t;
    SegmentTreePURQ(vector<Matrix> &in_mtx, int in_n){
        n = in_n;
        while(shift < n) shift <<= 1;
        t.resize(2 * shift);
        for(int i = 0; i < n; i++){
            t[i + shift] = in_mtx[i];
        }
        for(int i = shift - 1; i >= 1; i--){
            t[i] = merge(t[i << 1], t[(i << 1) + 1]);
        }
    }

    Matrix query(int l, int r){
        Matrix ansl, ansr;
        for(l += shift, r += shift; l < r; l >>= 1, r >>= 1){
            if(l & 1) ansl = merge(ansl, t[l++]);
            if(r & 1) ansr = merge(t[--r], ansr);
        }
        return merge(ansl, ansr);
    }

    Matrix merge(Matrix a, Matrix b){
        Matrix ans;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                ans.v[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    ans.v[i][j] += a.v[i][k] * b.v[k][j]; 
                }
                ans.v[i][j] %= mod;
            }
        }
        return ans;
    }

    void print(){
        for(int i = 1; i <= n + shift; i++){
            cout << i << ": \n";
            t[i].print();
            cout << "\n";
        }
    }
};

int32_t main(){
    BOOST;
    int n, m;
    cin >> mod >> n >> m;

    vector<Matrix> matrices(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                cin >> matrices[i].v[j][k];
            }
        }
    }

    SegmentTreePURQ algo(matrices, n);
    // algo.print();

    int l, r;
    Matrix ans;
    while(m--){
        cin >> l >> r;
        // r++;
        l--;
        ans = algo.query(l, r);
        ans.print();
        cout << "\n";
    }

}