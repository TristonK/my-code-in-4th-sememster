#include <bits/stdc++.h>
using namespace std;

const int maxn=300;
const double eps=0.00000001,inf=1e15;

int n,m,id[maxn*2];
double a[maxn][maxn];//a[i][j]:i��ڼ���Լ�� j��ڼ���Ԫ��
double myabs(double x) {return x>0?x:-x;}
//a[0][i] -> ci Ŀ�꺯���е�i��Ԫ��ϵ��
//a[i][0] -> bi ��i��Լ���еĳ���
//a[i][j] -> Aij ��i��Լ���е�j��Ԫ�ص�ϵ��
//��� sigma(ci*xi),i��N
//Լ�� xj=bj-sigma(aji*xi) ,j��B

//ת��
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
//�������xe�ʷǻ�������(1~n)  �������xl�ʻ�������(n+1~n+m)
{
    int tt=id[n+l];
	id[n+l]=id[e];
	id[e]=tt;
    int i,j;
	double t=a[l][e];a[l][e]=1;
    for (j=0;j<=n;j++) a[l][j]/=t;
    //��д������ʽ��
    for (i=0;i<=m;i++)
     if (i!=l && myabs(a[i][e])>eps)
     {
        t=a[i][e];a[i][e]=0;
        for (j=0;j<=n;j++)
          a[i][j]-=a[l][j]*t;
     }
}
//���Ż�
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
        //���Ŀ�����ci��С��0 ��ô���Ž���Ƿǻ�������Ϊ0
        for (i=1;i<=m;i++)
         if (a[i][e]>eps && a[i][0]/a[i][e]<minn)
          minn=a[i][0]/a[i][e],l=i;
        //�����е�ʽ�����ҳ�������ǰѡ���ϵ����Ϊ0���������һ��
        if (!l) {printf("Unbounded\n");return 0;}
        //������е�a[i][e]��С��0��˵������ֵ������
        pivot(l,e);
    }return 1;
}
double LP()
{
    int t,i,j;
/*    scanf("%d%d%d",&n,&m,&t);
    //n������ m��Լ��
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
		memset(id,0,sizeof(id)); //�ǵó�ʼ��
		readin();
		double ans=LP();
		printf("%f\n",ans);
	}
	return 0;
}

