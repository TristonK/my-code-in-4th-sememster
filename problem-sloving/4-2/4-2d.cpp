#include <bits/stdc++.h>
using namespace std;

int n,m;
int majo[1000005],dp[1000005][5][5];

void init(){
    cin >> n >>m;
    int majong;
    for(int i=0;i<n;i++) {
        cin >> majong;
        majo[majong]++;
    }
}

void majo_dp(){
    for(int i = 0;i <= m+1; ++i){
        for(int j = 0 ; j < 3 ;++j){
            for(int k = 0 ;k < 3 ; ++k){
                for(int l = 0;l < 3; ++l){
                    if( j + k + l > majo[i]) break;
                    dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+l+(majo[i]-j-k-l)/3);
                }
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    majo_dp();
    cout<<dp[m+1][0][0]<<endl;
    return 0;
}