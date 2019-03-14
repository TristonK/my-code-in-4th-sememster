#include <bits/stdc++.h>
using namespace std;

int n,a,b,M,x[1001],y[1001];
int ans=0;

void init(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    cin >> a >> b >> M;
    ans = 0;
}

void getans(int l, int r){
    if(l==r){
        while(y[l]>=0){
            int temp = a*x[l]+b*y[l];
            ans = max(ans,temp%M);
            if(temp<M)
                break;
            y[l]--;
        }
        return;
    }
    if(r - l == 1){
        if(x[l] + 1 == x[r]){
            while(y[l]>=0){
                int temp = a*x[l]+b*y[l];
                ans = max(ans,temp%M);
                if(temp<M)
                    break;
                y[l]--;
            }
            while(y[r]>=0){
                int temp = a*x[r]+b*y[r];
                ans = max(ans,temp%M);
                if(temp<M)
                    break;
                y[r]--;
            }
        }
        else{
            double k_line;
            k_line = (y[r] - y[l])*1.0 / (x[l] - x[r]);
            int i=0;
            if(a<b){
                int tempx = x[l],tempy=y[l];
                while(tempx<=x[r]){
                    int temp = a*tempx+b*tempy;
                    ans = max(ans,temp%M);
                    if(temp<M)
                        break;
                    i++;
                    tempx+=i;tempy-=ceil(k_line*i);
                }
            }
            else{
                int tempx = x[r],tempy=y[r];
                while(tempx>=x[l]){
                    int temp = a*tempx+b*tempy;
                    ans = max(ans,temp%M);
                    if(temp<M)
                        break;
                    i++;
                    tempx-=i;tempy+=floor(k_line*i);
                }
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    getans(l,mid);
    getans(mid,r);
}

int main() {
    init();
    getans(0,n-1);
    cout << ans <<endl;
    return 0;
}
