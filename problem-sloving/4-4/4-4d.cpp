#include <bits/stdc++.h>
using namespace std;

int n,m;
int p[505];

void init(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
}

void getans(){
    double ans=0.0;
    for(int i=0;i<m;i++){
        int u,v,m;
        cin >> u >> v >> m;
        double tempans=(p[u]+p[v])*1.0/m;
        if(tempans-ans>1e-6)
            ans=tempans;
    }
    cout<<setiosflags(ios::fixed)<<setprecision(6)<<ans<<endl;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    getans();
    return 0;
}