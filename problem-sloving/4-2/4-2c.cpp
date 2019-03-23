#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
//拓扑排序
//错误原因：可能没开long long

int T,n,m,cnt;
int in[100005],out[100005],head[200005];
long long dp[100005];
struct eatline{
    int v,next;
}e[200005];
queue <int> q;
void init(){
    cnt = 0;
    memset(in,0, sizeof(in));
    memset(out,0,sizeof(out));
    memset(head,-1, sizeof(head));
    memset(dp,0, sizeof(dp));
    while(!q.empty())
        q.pop();
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int u,v;
        cin >> u >> v;
        out[u]++;in[v]++;
        e[cnt].next=head[u];e[cnt].v=v;
        head[u]=cnt++;
    }
}

void topological(){
    for(int i = 1;i <= n;++i) {
        if(!in[i]){
            dp[i]=1;
            q.push(i);
        }
    }
    int temp;
    while(!q.empty()) {
        temp=q.front();
        q.pop();
        for(int i = head[temp] ; ~i; i=e[i].next) {
            int v=e[i].v;
            dp[v]+=dp[temp];
            in[v]--;
            if(!in[v])
                q.push(v);
        }
    }
};

long long getans(){
    long long ans=0;
    for(int i=0;i<=n;++i){
        if(!out[i]){
            dp[i]%=1000000007;
            ans=(ans+dp[i])%1000000007;
        }
    }
    return ans;
}


int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> T;
    while(T--){
        init();
        topological();
        cout << getans() <<endl;
    }
    return 0;
}