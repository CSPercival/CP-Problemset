#include <bits/stdc++.h>

using namespace std;

// bool pierwsza[10000005];
vector<bool> pierwsza;
vector<int> pier;

void sito(int limit){
    pierwsza.resize(limit + 10, 0);
    pierwsza[0]=1;
    pierwsza[1]=1;
    for(int i=2;i<=limit;i++){
        if(pierwsza[i]==0){
            pier.push_back(i);
            for(int j=i+i;j<=limit;j=j+i){
                pierwsza[j]=1;
            }
        }
    }
}

int main()
{
    int n = 2e7;
    int d = 1500;
    sito(n);
    int idx = 0;
    while(pier[idx] <= n / d){
        idx++;
    }
    cout << idx << " " << idx + d << " " << pier[idx] << "\n";

    int mini = 1e9;
    int miniidx = -1;
    for(int i = 50; i <= 5000; i++){
        int idx2 = 0;
        while(pier[idx2] <= n / i){
            idx2++;
        }
        if(mini >= idx2 + i){
            mini = idx2 + i;
            miniidx = i;
            cout << "    ";
        }
        cout << i << " " << idx2 << " " << idx2 + i << " " << pier[idx2] << " " << idx2 + idx2 + i << "\n";
    }
    cout << miniidx << " " << mini << "\n";

    // long long ans = 0, ctr = 0;
    // while(ans < n){
    //     ans += pier[ctr];
    //     ctr++;
    // }
    // cout << ans << " " << ctr << "\n";
    // scanf("%d",&n);

    // printf("%d",pier.size());
    return 0;
}
