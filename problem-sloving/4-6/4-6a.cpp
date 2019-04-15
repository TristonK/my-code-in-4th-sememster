#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

char a[MAXN],b[MAXN];
int nextv[MAXN];

void init(){
    cin>>a>>b;
}

int KMP(char s1[],char s2[],int s_length,int p_length){
    bool flag = false;
    //caculate the next array
    int j=0,k=-1;
    nextv[0]=-1;
    while (j<p_length){
        if(k==-1||s2[j]==s2[k]){
            j++;k++;
            nextv[j]=k;
        } else{
            k=nextv[k];
        }
    }
    //do kmp
    int i=0;j=0;
    while(i<s_length){
        if(j==-1||s1[i]==s2[j]){
            i++;
            j++;
        } else{
            j=nextv[j];
        }
        if(j==p_length){
            //return i-p_length+1;
            flag = true;
            cout<<i-p_length+1<<endl;
            j=nextv[j];
        }
    }
    if(flag)
        return 0;
    else
        return -1;

}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    if(KMP(a,b,strlen(a),strlen(b))==-1){
        cout << "nmdwsm" <<endl;
    }
    return 0;
}