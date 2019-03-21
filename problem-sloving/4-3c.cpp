#include <bits/stdc++.h>
using namespace std;

int n,m,wei[22],bin[22],v[22],s[22];

void init(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin >> wei[i];
    }
    for(int i=1;i<=n;i++){
        cin>>bin[i];
        v[i]=wei[i]-bin[i];
        s[i]=wei[i]+bin[i];
    }
}



int main(){
    init();

    return 0;
}