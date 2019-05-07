#include <bits/stdc++.h>
using namespace std;

int H,W;
int g[505][505];
int d[505][505];
int special[505][505];
int path[504][504];
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
bool vis[504][504];
typedef pair<int,int> P;
queue <P> q;
void init(){
    scanf("%d%d",&H,&W);
    int temp=getchar();
    memset(special,0, sizeof(special));
    memset(path,0, sizeof(path));
    memset(vis,0, sizeof(vis));
    for(int i=1;i<=H;i++){
        bool flagg = true;
        for(int j=1;j<=W;j++){
            temp = getchar();
            if(temp=='#')
                g[i][j]=-1;
            else if(temp-'0'>0){
                special[i][j]=g[i][j]=(temp-'0');
            }
            else if(temp==10){
                flagg = false;
                for(;j<=W;j++)
                    g[i][j]=0;
            }
            else
                g[i][j]=0;
        }
        if(flagg)
            temp=getchar();
    }
    memset(d,0,sizeof(d));
   /* for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++)
            printf("%d ",g[i][j]);
        printf("\n");
    }*/
}

void getans(){
    q.push(P(1,1));
    d[1][1]=0;
    path[1][1]=1;
    while(q.size()){
        P p = q.front();
        q.pop();
        if(p.first==H&&p.second==W)
            break;
        if(special[p.first][p.second]>0){
            special[p.first][p.second]--;
            q.push(p);
        } else{
            for(int i=0;i<8;i++){
                int nx=p.second+dx[i],ny=p.first+dy[i];
                if(nx>0&&nx<=W&&ny>0&&ny<=H&&g[ny][nx]!=-1){
                    if(!vis[ny][nx]){
                        vis[ny][nx]= true;
                        path[ny][nx]+=path[p.first][p.second];
                        d[ny][nx]=d[p.first][p.second]+1+g[ny][nx];
                        q.push(P(ny,nx));
                    } else if (d[ny][nx]==d[p.first][p.second]+1+g[ny][nx]){
                        path[ny][nx]+=path[p.first][p.second];
                    }
                }
            }
        }
    }
}


int main(){
   /* cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);*/
    init();
    getans();
    if(path[H][W])
        cout << d[H][W] <<" "<<path[H][W]<<endl;
    else
        cout<<"endless nightmare..."<<endl;
    return 0;
}