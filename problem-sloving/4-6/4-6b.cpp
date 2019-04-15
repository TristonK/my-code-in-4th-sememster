#include <bits/stdc++.h>
using namespace std;

int H,W,T,h,w,cnt;
char input_temp[1002];
long long str[1002][1002];
long long pattern[52];

void init(){
    cnt=0;
    memset(str,0LL, sizeof(str));
    cin>>H>>W>>T>>h>>w;
    for(int i=0;i<H;i++){
        cin >> input_temp;
        for(int j=0;j+w-1<W;j++){
            for(int k=j;k<j+w;k++){
                if(input_temp[k]=='1'){
                    str[i][j]|=(1LL<<(w-1-k+j));
                }
            }
        }
    }
}


bool issame(){
    /*cout << "test begin"<<endl;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++)
            cout<<str[i][j]<<" ";
        cout<<endl;
    }
    cout<< "pattern is \n";
    for(int i=0;i<h;i++)
        cout<<"  "<<pattern[i]<<endl;*/
    for(int i=0;i+h-1<H;i++){
        for(int j=0;j+w-1<W;j++){
            bool flag= true;
            for(int k=0;k<h;k++){
                if(str[i+k][j]!=pattern[k]){
                    flag= false;
                    break;
                }
            }
            if(flag)
                return true;
        }
    }
    return false;
}


void getans(){
    while (T--){
        memset(pattern,0LL, sizeof(pattern));
        for(int i=0;i<h;i++){
            cin >> input_temp;
            for(int j=0;j<w;j++){
                if(input_temp[j]=='1')
                    pattern[i]|=(1LL<<(w-1-j));
            }
        }
        if(issame())
            cnt++;
    }
    cout<<cnt<<endl;
}


int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    init();
    getans();
    return 0;
}