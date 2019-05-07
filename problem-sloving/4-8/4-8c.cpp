#include <bits/stdc++.h>
using namespace std;

int n,m;
int g[104][104],clique[104][104];
int clique_size[10004];
int cli_cnt=0;
typedef pair<int,int> point;
queue<point> p;
int x_path[4]={0,0,-1,1};
int y_path[4]={1,-1,0,0};

void bfs(int x,int y){
    int length = 1;
    p.push(make_pair(x,y));
    clique[x][y]=cli_cnt;
    while(!p.empty()){
        point pp = p.front();
        p.pop();
        int a = pp.first,b=pp.second;
        for(int i=0;i<4;i++){
            int a_next = a + x_path[i];
            int b_next = b + y_path[i];
            if(a_next>0 && a_next<=n && b_next>0 && b_next<=n
               && !clique[a_next][b_next] && g[a][b]!=g[a_next][b_next]){
                clique[a_next][b_next]=cli_cnt;
                length++;
                p.push(make_pair(a_next,b_next));
            }
        }
    }
    clique_size[cli_cnt]=length;
}

void init(){
    memset(g,0, sizeof(g));
    memset(clique,0, sizeof(clique));
    memset(clique_size,0, sizeof(clique_size));
    while(!p.empty())
        p.pop();
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        char temp[105];
        cin >> temp;
        for(int j=0;j<n;j++)
            if(temp[j]=='1')
                g[i][j+1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!clique[i][j]){
                cli_cnt++;
                bfs(i,j);
            }
        }
    }
}



void getans(){
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cout << clique_size[clique[a][b]]<< endl;
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    getans();
    return 0;
}