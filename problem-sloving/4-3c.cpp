#include <bits/stdc++.h>

using namespace std;

int n, m, wei[202], bin[202], v[202], s[202];
int dp[21][802], path[21][802];

void init() {
    //cin.sync_with_stdio(false);
    //cin.tie(NULL);
    //cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof(dp));
    memset(path, 0, sizeof(path));
    cin >> n >> m;
    memset(wei,0,sizeof(wei));
    memset(bin,0,sizeof(bin));
    for (int i = 1; i <= n; i++) {
        cin >> wei[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> bin[i];
        v[i] = wei[i] - bin[i];
        s[i] = wei[i] + bin[i];
    }
}

bool used(int num, int sum, int index) {
    bool is_used = false;
    while (num >= 0) {
        if (path[num][sum] == index) {
            is_used = true;
            break;
        } else {
            sum -= v[path[num][sum]];
            num--;
        }
    }
    return is_used;
}


void getans() {
    int base = 20 * m;
    dp[0][base] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = m-1 ; i >= 0; i--) {
            for (int j = 0; j < 2 * base; j++) {
                if (~dp[i][j]) {
                    if (dp[i + 1][j + v[k]] < dp[i][j] + s[k]) {
                        //int a=i,b=j;
                        //if (!used(a, b, k)) {
                            dp[i + 1][j + v[k]] = dp[i][j] + s[k];
                           // path[i + 1][j + v[k]] = path[i][j];
                       // }
                    }

                }
            }
        }
    }
    int find_min = 0;
    while (dp[m][base + find_min] ==-1 && dp[m][base - find_min] ==-1) {
        find_min++;
    }
    int find_max = base + find_min;
    if (dp[m][base + find_min] < dp[m][base - find_min])
        find_max = base - find_min;
    cout << (dp[m][find_max] + find_max - base) / 2 << " " << (dp[m][find_max] - find_max + base) / 2 << endl;
}

int main() {
    init();
    getans();
    return 0;
}