#include <bits/stdc++.h>
using namespace std;

int n,m,s1[4097],ini[13];
long long dp[13][4096];
int c1_cnt=0;
long long ans=0;

#define s0(x,y) (!(ini[x]&s1[y])) //s0条件保证在第x行上不会有在贫瘠土地上种植
#define s2(x,y) (!(s1[x]&s1[y])) //s2条件保证相邻两行没有相同

void init(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    memset(s1, 0,sizeof(s1));
    memset(ini,0, sizeof(ini));
    memset(dp,0, sizeof(dp));
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int temp;
            cin>>temp;
            if(!temp)
                ini[i]+=(1<<(n-j));
        }
    }
}
void find_s1(){//s1条件保证一行之中任意两个相邻的点不同时为1
    int biggest=1<<n;
    for(int i=0;i<biggest;++i){
        if(!(i&(i<<1))){
            s1[c1_cnt]=i;
            c1_cnt++;
        }
    }
}

void get_ans(){
    for(int i=0;i<c1_cnt;i++)
        if(s0(1,i)){
            dp[1][i]=1;
        }
    for(int i=2;i<=m;i++) {
        for (int j = 0; j <= c1_cnt; j++) {
            if (!s0(i, j))
                continue;
            for (int k = 0; k < c1_cnt; ++k) {
                if (!s0(i - 1, k))
                    continue;
                if (!s2(j, k))
                    continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % (100000000);
            }
        }
    }
    for(int i=0;i<c1_cnt;i++){
        ans=(ans+dp[m][i])%(100000000);
    }
}

int main(){
    init();
    find_s1();
    get_ans();
    cout<<ans<<endl;
    return 0;
}