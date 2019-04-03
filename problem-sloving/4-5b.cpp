#include <bits/stdc++.h>
using namespace std;

int T,n,t,d;
long long h,r;
int f[1005],top[1005],down[1005];
long long x[1005],y[1005],z[1005];

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
double dis(long long x1,long long x2,long long y1,long long y2,long long z1,long long z2){
    return sqrt((x2-x1)*(x2-x1)*1.0+(y2-y1)*(y2-y1)*1.0+(z2-z1)*(z2-z1)*1.0);
}

void init(){
    cin>>n>>h>>r;
    t=0;d=0;
    for(int i=1;i<=n;i++){
        f[i]=i;
        cin >> x[i] >> y[i] >> z[i];
        if(z[i]+r>=h){
            top[t]=i;
            t++;
        }
        if(z[i]-r<=0){
            down[d]=i;
            d++;
        }
    }
}

void getans(){
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(dis(x[i],x[j],y[i],y[j],z[i],z[j])<=2*r)
                unions(i,j);
        }
    }
    bool flag= false;
    for(int i=0;i<t;i++){
        for(int j=0;j<d;j++){
            if(findp(top[i])==findp(down[j])){
                flag= true;
                break;
            }
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> T;
    while (T--){
        init();
        getans();
    }
    return 0;
}