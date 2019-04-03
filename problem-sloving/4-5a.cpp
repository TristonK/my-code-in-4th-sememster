#include <bits/stdc++.h>
using namespace std;

int f[1002],child[1002];
int n,m,ans;

int findp(int a){
    int b=a;
    while(f[b]!=b){
        b=f[b];
    }
    int c,d=a;
    while(d!=b){
        c=f[d];
        f[d]=b;
        d=c;
    }
    return b;
}
void unions(int a,int b){
    a=findp(a);
    b=findp(b);
    if(a<b){
        int temp=b;
        b=a;
        a=temp;
    }
    f[b]=a;
}
void init(){
    cin >> n >> m;
    memset(child,0, sizeof(child));
    for(int i=0;i<=n;i++){
        f[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >>b;
        unions(a,b);
    }
}

void getans(){
    ans=0;
    for(int i=1; i<=n;i++){
        int temp=findp(i);
        child[temp]++;
    }
    for(int i=1;i<=n;i++){
        if(child[i])
            child[i]--;
        ans+=child[i];
    }
    cout<<ans<<endl;
}
int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    getans();
    return 0;
}