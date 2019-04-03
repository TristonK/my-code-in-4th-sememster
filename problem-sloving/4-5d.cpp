#include <bits/stdc++.h>
using namespace std;

int n,m,f[5005*4];
int ans=0;
map <int,int> D;//discrete
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
void unions(int a,int b) {
    a = findp(a);
    b = findp(b);
    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }
    f[b] = a;
}
void getans(){
    D.clear();
    int cnt=1;
    bool getit = false;
    cin >> n >> m;
    for(int i=0;i<=4*m;i++)
        f[i]=i;
    for(int i=1;i<=m;i++){
        int a,b;
        char op[8];
        cin >> a >> b >>op;
        if(getit)
            continue;
        else
            ans++;
        if(!D[a-1]){
            D[a-1]=cnt;cnt++;
        }
        if(!D[b]){
            D[b]=cnt;cnt++;
        }
        if(op[0]=='e'){
            unions(D[a-1],D[b]);unions(D[a-1]+2*m,D[b]+2*m);
        }
        else{
            unions(D[a-1]+2*m,D[b]);unions(D[a-1],D[b]+2*m);
        }
        if(findp(D[a-1])==findp(D[a-1]+2*m)||findp(D[b])==findp(D[b]+2*m)){
            ans--;
            getit= true;
        }
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    getans();
    cout << ans << endl;
    return 0;
}