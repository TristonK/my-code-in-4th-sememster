#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int f[1005],nb[1005],num[1005];

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
    cin >> n >> m >> k;
    memset(num,0, sizeof(num));
    for(int i=0;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=k;i++){
        cin >> nb[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        unions(a,b);
    }

}

void getans(){
    for(int i=1;i<=n;i++){
        num[findp(i)]++;
    }
    int maxx=0,sum1=0,sum2=0;
    for(int i=1;i<=k;i++){
        num[nb[i]]=num[findp(nb[i])];
        maxx=max(maxx,num[nb[i]]);
        sum1+=num[nb[i]];
        sum2+=(num[nb[i]])*(num[nb[i]]-1)/2;
    }
    int ans=(n+maxx-sum1)*(n+maxx-1-sum1)/2+sum2-(maxx)*(maxx-1)/2-m;
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