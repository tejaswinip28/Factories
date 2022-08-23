#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,h,w,radius,sum;
    scanf("%d",&n);
    int r[n];
    for(int i=0;i<n;i++)
    scanf("%d",&r[i]);
    scanf("%d %d",&w,&h);
    int d[h][w],disc[h][w],z[h][w],k[h][w];
    for(int i=0;i<h;i++)
    {
        sum=0;
        for(int j=0;j<w;j++)
        {
            scanf("%d",&d[i][j]);
            z[i][j]=d[i][j];
            sum=sum+d[i][j];
            disc[i][j]=sum;
            k[i][j]=1;
        }
    }
    for(int i=1;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            disc[i][j]=disc[i][j]+disc[i-1][j];
        }
    }
    for(int p=0;p<n;p++)
    {
        radius=r[p];
        int a1=0,a2=0;
        int min=INT_MAX;
        for(int i=0;i<h;i++)
        {
          for(int j=0;j<w;j++)
          {
              sum=0;
              if(i+radius<h&&j+radius<w)
              sum=disc[i+radius][j+radius];
              if(i+radius>=h&&j+radius>=w)
              sum=disc[h-1][w-1];
              if(i+radius>=h&&j+radius<w)
              sum=disc[h-1][j+radius];
              if(i+radius<h&&j+radius>=w)
              sum=disc[i+radius][w-1];
              
              if(i>radius&&j>radius)
              sum=sum+disc[i-radius-1][j-radius-1];
              
              if(i>radius)
              {
                if(j+radius<w)
                sum=sum-disc[i-radius-1][j+radius];
                else if(j+radius>=w)
                sum=sum-disc[i-radius-1][w-1];
              }
              
              if(j>radius)
              {
                if(i+radius<h)
                sum=sum-disc[i+radius][j-radius-1];
                else if(i+radius>=h)
                sum=sum-disc[h-1][j-radius-1];
              }
              
              if(sum<min)
              {
                  min=sum;
                  a1=i;
                  a2=j;
              }
          }
        }
        printf("%d %d\n",a1,a2);
        for(int i=a1-radius;i<=a1+radius;i++)
        {
          if(i>0&&i<h)
          {
            for(int j=a2-radius;j<=a2+radius;j++)
            {
              if(j>0&&j<w)
              {
                  k[i][j]++;
                  int t=k[i][j];
                  d[i][j]=((t)*d[i][j])/(t-1);
              }
            }
          }
        }
        for(int i=0;i<h;i++)
        {
          sum=0;
          for(int j=0;j<w;j++)
          {
            sum=sum+d[i][j];
            disc[i][j]=sum;
          }
        }
        for(int i=0;i<h;i++)
        {
          if(i-1>=0)
          {
           for(int j=0;j<w;j++)
           {
            disc[i][j]=disc[i][j]+disc[i-1][j];
           }
          }
        }
    }
}
