#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> g[10001];
int max_p[10001];

void dfs(int point, int m_p){
    if(max_p[point])
        return;
    max_p[point]=m_p;
    for(int i=0;i<g[point].size();i++){
        dfs(g[point][i],m_p);
    }
}

void init(){
    memset(max_p,0, sizeof(max_p));
    cin >> n >>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        g[b].push_back(a);
    }
}

void getans(){
    for(int i=n;i>0;i--){
       // cout<<i<<endl;
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        cout << max_p[i]<< " ";
    }
    cout<<endl;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    getans();
    return 0;
}