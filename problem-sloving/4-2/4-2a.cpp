#include <bits/stdc++.h>
using namespace std;

long long dp[20][165][1460];
int digits[20];
bool is_prime[1460];
int len;

void get_prime(){
    memset(is_prime,1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= 1458;i++){
        if(is_prime[i]){
            for(int j = i*i; j <= 1458; j+=i){
                is_prime[j]= false;
            }
        }
    }
}

long long dpp(int pos, int s1, int s2, int flag){
    if(pos == -1){
        return (is_prime[s1]&&is_prime[s2]);
    }
    if(!flag && ~dp[pos][s1][s2]){
        return dp[pos][s1][s2];
    }
    long long ans=0;
    if(flag){
        for(int i = 0; i<= digits[pos]; ++i){
            ans += dpp(pos-1, s1+i, s2+i*i, (i==digits[pos]));
        }
    }
    else{
        for(int i = 0; i<=9 ;++i){
            ans += dpp(pos-1, s1+i, s2+i*i, 0);
        }
    }
    if(!flag){
        dp[pos][s1][s2] = ans;
    }
    return ans;
}

long long getans(long long num){
    len = 0;
    if(num == 0)
        return 0;
    while(num){
        digits[len] = num % 10;
        num/=10;
        len++;
    }
    return dpp(len-1,0,0,1);
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    int T;
    get_prime();
    memset(dp,-1,sizeof(dp));
    cin >> T;
    while(T--) {
        long long a, b;
        cin >> a >> b;
        cout << getans(b) - getans(a-1) <<endl;
    }
    return 0;
}