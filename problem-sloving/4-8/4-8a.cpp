#include <bits/stdc++.h>
using namespace std;

int f[204],g[202][202];
int n,m;
int cnt=0;

int degree[204];
int conne[204];

void init(){
    cin >> m;
    cnt++;
    memset(g,0, sizeof(g));
    memset(degree,0, sizeof(degree));
    memset(conne,0, sizeof(conne));
    for(int i=0;i<=200;i++)
        f[i]=i;
    for(int i=0;i<m;i++){
        int x,y;cin>>x >> y;
        g[x][y]=g[y][x]=1;
        degree[x]++;degree[y]++;
        conne[x]=y;conne[y]=x;
    }
}

void getans(){
    if(m!=n-1){
        cout << "Case "<<cnt<<": 955" <<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!degree[i]){
            //cout<<"hi";
            cout << "Case "<<cnt<<": 955" <<endl;
            return;
        }
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==1 && conne[i]){
            degree[conne[i]]--;
            degree[i]--;
            conne[conne[i]]=0;
        }
    }
    int de_2=0;
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(degree[i]!=1 && degree[i]!=2&&degree[i]){
            flag= false;
            break;
        }
        if(degree[i]==1){
            de_2++;
            if(de_2>2){
                flag= false;
                break;
            }
        }
    }
    if(de_2!=2)
        flag= false;
    if(flag)
        cout << "Case "<<cnt<<": 996" <<endl;
    else
        cout << "Case "<<cnt<<": 955" <<endl;
}


int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    while (cin >> n && n){
        init();
        getans();
    }
    return 0;
}