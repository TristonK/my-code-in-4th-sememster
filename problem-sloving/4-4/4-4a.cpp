#include <bits/stdc++.h>
using namespace std;

int n,m,ans,num[50002];

void init(){
    ans = 0;
    memset(num,0, sizeof(num));
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }

}

void getans(){
    sort(num,num+n);
    int left=0,right=n-1;
    while(left<=right){
        if(num[left]+num[right]<=m){
            left++;
            right--;
            ans++;
        }
        else{
            right--;
            ans++;
        }
    }
}


int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    getans();
    cout << ans << endl;
    return 0;
}