#include <bits/stdc++.h>
using namespace std;

int n,m,N,M,T;
#define MAXN 1200
#define MAXM 1200
#define A1 N+1
#define B1 N+2
//#define flow2(x) M+2+x
int flow2(int x){
    return M+2+x;
}
//aunt's template
const double EPS = 1e-8;

int id[MAXN+MAXM] = {};
double v[MAXN] = {};
double a[MAXM][MAXN] = {};
//end
int line[100][100];
void init(){
    cin.sync_with_stdio(false);
    memset(a,0, sizeof(a));
    memset(line,0, sizeof(line));
    memset(v,0,sizeof(v));
    memset(id,0, sizeof(id));
    cin >> N >> M;
    n = (M+2)*2; m = M+2+2*(N+2);
    int u,vv;
    for (int i = 1; i <=M ;++i){
        cin >> u >> vv;
        if(!line[u+1][vv+1]){
            line[u+1][vv+1]=i;
            a[i][i]=a[i][flow2(i)]=a[i][0]=1;
        }
    }
    int A,B,C;
    cin >> A >> B >>C;
    A++;B++;C++;
    line[A1][A]=M+1;line[B1][B]=M+2;
    a[M+1][M+1]=a[M+1][flow2(M+1)]=a[M+1][0]=1;
    a[M+2][M+2]=a[M+2][flow2(M+2)]=a[M+2][0]=1;
    a[0][M+1]=1;a[0][flow2(M+2)]=1;
    for(int i=1; i<=N+2;i++){
        for(int j=1;j<=N+2;j++){
            if(i!=j && line[i][j]){
               if(i!=A1 && i!=B) a[M+2+i][line[i][j]]=-1;
               if(j!=A1 && j!=B) a[M+2+j][line[i][j]]=1;
               if(i!=B1 && i!=C) a[M+N+4+i][flow2(line[i][j])]=-1;
               if(j!=B1 && j!=C) a[M+N+4+j][flow2(line[i][j])]=1;
            }
        }
    }
}

/**
 * using aunt's template
 * */

int sgn(double x) {
    if (x < -EPS) return -1;
    return x > EPS ? 1 : 0;
}

void pivot(int r, int c) {
    swap(id[n + r], id[c]);
    double x = -a[r][c];
    a[r][c] = -1;
    for (int i = 0; i <= n; ++i) a[r][i] /= x;
    for (int i = 0; i <= m; ++i) {
        if (sgn(a[i][c]) && i != r) {
            x = a[i][c];
            a[i][c] = 0;
            for (int j = 0; j <= n; ++j) a[i][j] += x * a[r][j];
        }
    }
}

int simplex() {
    /* important: revert symbols of conditions */
    /* bug fixed thanks to TuoMianZiGan */
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] *= -1;
        }
    }
    for (int i = 1; i <= n; ++i) id[i] = i;
    /* initial-simplex */
    while (true) {
        int x = 0, y = 0;
        for (int i = 1; i <= m; ++i) {
            if (sgn(a[i][0]) < 0) { x = i; break; }
        }
        if (!x) break;
        for (int i = 1; i <= n; ++i) {
            if (sgn(a[x][i]) > 0) { y = i; break; }
        }
        if (!y) return -1; // infeasible
        pivot(x, y);
    }
    /* solve-simplex */
    while (true) {
        int x = 0, y = 0;
        for (int i = 1; i <= n; ++i) {
            if (sgn(a[0][i]) > 0) { x = i; break; }
        }
        if (!x) break; // finished
        double w = 0, t = 0; bool f = true;
        for (int i = 1; i <= m; ++i) {
            if (sgn(a[i][x]) < 0) {
                t = -a[i][0] / a[i][x];
                if (f || t < w) {
                    w = t, y = i, f = false;
                }
            }
        }
        if (!y) { return 1; } // unbounded
        pivot(y, x);
    }
    for (int i = 1; i <= n; ++i) v[i] = 0;
    for (int i = n + 1; i <= n + m; ++i) v[id[i]] = a[i - n][0];
    return 0;
}

int main() {
    cin >> T;
    while (T--){
        init();
        simplex();
        //cout << a[0][0]<<endl;
        if((int)a[0][0]==2)
            cout << "yes" <<endl;
        else
            cout << "no" <<endl;
    }
    return 0;
}