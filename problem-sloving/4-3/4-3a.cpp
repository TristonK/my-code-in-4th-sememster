#include <bits/stdc++.h>
using namespace std;

int n,num[504],dp[504][504];

void init(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    memset(dp,0, sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> num[i];
    }
    num[0]=1;num[n+1]=1;
}

void get_ans(){
    for(int i=1;i<=n;++i){//length
        for(int left=1;left<=n-i+1;++left){
            int right=left+i-1;
            for(int j=left;j<=right;++j){
                dp[left][right]=max(dp[left][right], num[left-1]*num[j]*num[right+1] + dp[left][j-1] + dp[j+1][right]);
            }
        }
    }
}

int main(){
    init();
    get_ans();
    cout << dp[1][n] <<endl;
    return 0;
}