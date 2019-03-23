#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[604],dp[604][604];

void init(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    memset(dp,0, sizeof(dp));
    for(int i=1;i<=n;i++){
        cin >> num[i];
     //   cout<<"hi"<<endl;
    }
}
#define inf 0x3f3f3f3f
void getans(){
   // cout << "here"<<endl;
    for(int i=1;i<=n;i++)
        dp[i][i]=1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <=n-i+1; j ++) {
            int l=j,r=j+i-1;
            dp[l][r]=min(dp[l][r-1]+1,dp[l+1][r]+1);
            for (int k = l; k <= r; k ++)
                if(num[l]==num[k])
                    dp[l][r]=min(dp[l][r],dp[l+1][k-1]+dp[k][r]);
        }
}

int main(){
    init();
    getans();
    cout << dp[1][n]<<endl;
    return 0;
}