#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define inf 0x7f7f7f7f
#define maxn 420
double x[maxn],y[maxn];//存储机场坐标和高速公路费用
double dis[maxn][maxn];//用邻接矩阵来存储图
int p[maxn][maxn];//记录对应点的最小路径的前驱点
int n, t, A, B, T[110];  //直接定义全局变量，之后调用函数就不用传参了
double distant(double x1,double y1,double x2,double y2)
//求两点间距离
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double ds(double x1, double y1, double x2, double y2) 
//求两点距离的平方，下面求第四个机场坐标会用到
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void build_graph() {
    int d1,d2,d3;//分别表示每个城市给出的三个机场之间距离的平方
    for(int i=1;i<=n;i++)
    {
        cin >> x[(i - 1) * 4 + 1] >> y[(i - 1) * 4 + 1] >> x[(i - 1) * 4 + 2] >>
            y[(i - 1) * 4 + 2] >> x[(i - 1) * 4 + 3] >> y[(i - 1) * 4 + 3]>>T[i];
        //下面求出第四个点的坐标,原理是平行四边形对角线平分
        d1 = ds(x[(i - 1) * 4 + 1], y[(i - 1) * 4 + 1], x[(i - 1) * 4 + 2], y[(i - 1) * 4 + 2]);
        d2 = ds(x[(i - 1) * 4 + 1], y[(i - 1) * 4 + 1], x[(i - 1) * 4 + 3], y[(i - 1) * 4 + 3]);
        d3 = ds(x[(i - 1) * 4 + 2], y[(i - 1) * 4 + 2], x[(i - 1) * 4 + 3], y[(i - 1) * 4 + 3]);
        if(d1+d2==d3)
        {
            x[(i - 1) * 4 + 4] =x[(i - 1) * 4 + 2] + x[(i - 1) * 4 + 3] - x[(i - 1) * 4 + 1];
            y[(i - 1) * 4 + 4] =y[(i - 1) * 4 + 2] + y[(i - 1) * 4 + 3] - y[(i - 1) * 4 + 1];
        }
        if (d1 + d3 == d2) {
            x[(i - 1) * 4 + 4] = x[(i - 1) * 4 + 1] + x[(i - 1) * 4 + 3] - x[(i - 1) * 4 + 2];
            y[(i - 1) * 4 + 4] = y[(i - 1) * 4 + 1] + y[(i - 1) * 4 + 3] - y[(i - 1) * 4 + 2];
        }
        if (d2 + d3 == d1) {
            x[(i - 1) * 4 + 4] = x[(i - 1) * 4 + 1] + x[(i - 1) * 4 + 2] - x[(i - 1) * 4 + 3];
            y[(i - 1) * 4 + 4] = y[(i - 1) * 4 + 1] + y[(i - 1) * 4 + 2] - y[(i - 1) * 4 + 3];
        }
    }
}
int main(){
    double minfee=inf;//存储最小费用
    cin>>n>>t>>A>>B;
    build_graph();
    //下面是Floyd算法
    for(int i=1;i<=4*n;i++)
    {
        for(int j=1;j<=4*n;j++)
        {
            if((i-1)/4==(j-1)/4)//两个机场在同一个城市
                dis[i][j]=T[(i-1)/4+1]*distant(x[i],y[i],x[j],y[j]);
            else//两个机场在不同的城市
                dis[i][j]=t*distant(x[i],y[i],x[j],y[j]);
            p[i][j]=j;//初始路径都是直达的
        }
    }
    for(int k=1;k<=4*n;k++)
        for(int i=1;i<=4*n;i++)
            for(int j=1;j<=4*n;j++)
            //不断更新两点间的最短“距离”
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    p[i][j]=p[i][k];//更新最小路径的中间点
                }
            }
    
    //下面看从A的哪个机场到B的哪个机场费用最小
    int minA,minB;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
           { 
               if(minfee>dis[(A-1)*4+i][(B-1)*4+j])
               {minA=(A-1)*4+i; minB=(B-1)*4+j;
                   minfee = dis[(A - 1) * 4 + i][(B - 1) * 4 + j];}
        }  //求最小费用，以及得到起点和终点机场的编号
            printf("%.2f\n", minfee);//打印最小费用
            int k=p[minA][minB];
            printf("%d(%d)",A,minA-4*(A-1));//打印起点
            while(k!=minB)
            {
                printf("->%d(%d)",(k-1)/4+1,k-4*((k-1)/4));
                k=p[k][minB];
            }
            printf("->%d(%d)",B,minB-4*(B-1));
            //打印路径，这里要注意机场编号和所在城市编号的转换关系
            return 0;
}