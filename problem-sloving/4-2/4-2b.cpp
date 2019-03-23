#include <bits/stdc++.h>
using namespace std;

int n,k,m,cnt=0;
int digit[40010],op[40010],dp[(1<<18)];
typedef pair<int,int> pp;
pp p[18];
int dis[19][40010];
queue<int>q;

void init(){
    memset(digit,0, sizeof(digit));
    memset(dis,0x3f, sizeof(dis));
    memset(dp,0x3f, sizeof(dp));
    cin >> n >> k >> m;
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        digit[x]=1;
    }
    for(int i=1;i<=m;i++){
        cin >> op[i];
    }
    for(int i=0;i<=n;i++){
        if(digit[i]^digit[i+1]){
            p[cnt]=pp(cnt,i);
            cnt++;
        }
    }
}

void bfs(pp x){
    q.push(x.second);
    dis[x.first][x.second]=0;
    int start=x.first;
    while (!q.empty()){
        int now2 = q.front();q.pop();
        for(int i=1;i<=m;i++){
            if(now2-op[i]>=0&&dis[start][now2-op[i]]>dis[start][now2]+1){
                dis[start][now2-op[i]]=dis[start][now2]+1;
                q.push(now2-op[i]);
            }
            if(now2+op[i]<=n&&dis[start][now2+op[i]]>dis[start][now2]+1){
                dis[start][now2+op[i]]=dis[start][now2]+1;
                q.push(now2+op[i]);
            }
        }
    }
}

int getans(int num){
    if(num == 0)
        return 0;
    if(dp[num]!=0x3f3f3f3f)
        return dp[num];
    int temp=0;
    while (!(num&(1<<temp)))
        temp++;
    for(int i=temp+1;i<2*k;i++){
        if(num&(1<<i))
            dp[num]=min(dp[num],getans(num^(1<<i)^(1<<temp))+dis[temp][p[i].second]);
    }
    return dp[num];
}


int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    for(int i=0;i<cnt;i++){
        bfs(p[i]);
    }
    cout<<getans((1<<cnt)-1)<<endl;
    //cout<<dp[(1<<cnt)-1]<<endl;
    return 0;
}