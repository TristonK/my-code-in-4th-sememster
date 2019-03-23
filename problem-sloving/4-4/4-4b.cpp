#include <bits/stdc++.h>
using namespace std;

int n,k,l,wood[100002];

void init(){
    memset(wood,0, sizeof(wood));
    cin >> n >> k >> l;
    for(int i=0;i<n*k;i++){
        cin >> wood[i];
    }
    sort(wood,wood+n*k);
}

void getans(){
    long long ans=0;
    if(wood[n-1]-wood[0]>l){
        cout<<"0"<<endl;
        return;
    }
    for(int i=n*k-1;i>=0;i--){
        if(wood[i]-wood[0]<=l&&i<=(n-1)*k){
            ans+=wood[i];
            n--;
        }
    }
    cout<< ans <<endl;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    getans();
    return 0;
}