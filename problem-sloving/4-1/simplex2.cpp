#include <bits/stdc++.h>
using namespace std;

const int maxn=300;
const double eps=0.00000001,inf=1e15;

int n,m,id[maxn*2];
double a[maxn][maxn];//a[i][j]:i表第几条约束 j表第几个元素
double myabs(double x) {return x>0?x:-x;}
//a[0][i] -> ci 目标函数中第i个元素系数
//a[i][0] -> bi 第i条约束中的常数
//a[i][j] -> Aij 第i条约束中第j个元素的系数
//最大化 sigma(ci*xi),i∈N
//约束 xj=bj-sigma(aji*xi) ,j∈B

//转轴
void print()
{
	printf("%d,%d\n",n,m);
	for(int i=0;i<=n+m;i++)
		printf("%d ",id[i]);
	printf("\n");
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			printf("%.0f%c",a[i][j],j==m?'\n':' ');
	printf("\n");
}
void pivot(int l,int e)
//替入变量xe∈非基本变量(1~n)  替出变量xl∈基本变量(n+1~n+m)
{
    int tt=id[n+l];
	id[n+l]=id[e];
	id[e]=tt;
    int i,j;
	double t=a[l][e];a[l][e]=1;
    for (j=0;j<=n;j++) a[l][j]/=t;
    //重写其它等式：
    for (i=0;i<=m;i++)
     if (i!=l && myabs(a[i][e])>eps)
     {
        t=a[i][e];a[i][e]=0;
        for (j=0;j<=n;j++)
          a[i][j]-=a[l][j]*t;
     }
}
//最优化
bool simplex()
{
    int i,j;
    while (1)
    {
        int l=0,e=0;
		double minn=inf;
        for (j=1;j<=n;j++)
         if (a[0][j]>eps) {e=j;break;}
        if (!e) break;
        //如果目标变量ci都小于0 那么最优解就是非基变量都为0
        for (i=1;i<=m;i++)
         if (a[i][e]>eps && a[i][0]/a[i][e]<minn)
          minn=a[i][0]/a[i][e],l=i;
        //在所有的式子中找出包含当前选中项（系数不为0）且最紧的一项
        if (!l) {printf("Unbounded\n");return 0;}
        //如果所有的a[i][e]都小于0，说明最优值正无穷
        pivot(l,e);
    }return 1;
}
double LP()
{
    int t,i,j;
/*    scanf("%d%d%d",&n,&m,&t);
    //n个变量 m条约束
    for (i=1;i<=n;i++) scanf("%lf",&a[0][i]);
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
          scanf("%lf",&a[i][j]);
        scanf("%lf",&a[i][0]);
    } */
    for (i=1;i<=n+m;i++) id[i]=i;
    simplex();
    return -a[0][0];
}
void readin()
{
	return ;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(id,0,sizeof(id)); //记得初始化
		readin();
		double ans=LP();
		printf("%f\n",ans);
	}
	return 0;
}

