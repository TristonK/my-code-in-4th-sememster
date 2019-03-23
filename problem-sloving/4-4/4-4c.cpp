#include <bits/stdc++.h>
using namespace std;

int n,k,a[1002],b[1002];
bool used[1002];
double ansa,ansb;

void init(){
    memset(a,0, sizeof(a));
    memset(b,0, sizeof(b));
    memset(used,0, sizeof(used));
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
}

void getans(){
    ansa=0.0,ansb=0.0;
    double ans=0.0;
    for(int i=0;i<k;i++){
        int use_index=0;
        for(int j=1;j<=n;j++){
            if(!used[j]){
                double tempans=(ansb+b[j])*1.0/(ansa+a[j]);
                if(use_index==0){
                    ans=tempans;
                    use_index=j;
                }
                else if(tempans-ans>1e-6){
                    ans=tempans;
                    use_index=j;
                }
            }
        }
        used[use_index]=true;
        ansa+=a[use_index];ansb+=b[use_index];
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    while(cin>>n>>k){
        if(!n&&!k)
            break;
        init();
        getans();
    }
    return 0;
}