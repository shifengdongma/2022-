#include<iostream>
using namespace std;
int main()
{
    int m;
    cout<<"请输入m：";
    cin>>m;
    while(m%2==0)
        {
            cout<<"错误！请输入正确的m：";
            cin>>m;
        }
    int a[100][100];
    int i=1,j,k,x,y;
    for(x=0;x<100;x++)//构造数组 
    {
        for(y=0;y<100;y++)
        a[x][y]=0;
    }
    while(i<=m*m)
    {
        if(i==1)//第一个位置赋值
        {
            j=0;
            k=m/2;
            a[j][k]=i;
            i++;
            //cout<<i;
        }
        else//其他位置赋值
        {
            j=(j-1+m)%m;
            k=(k-1+m)%m;
            if(a[j][k]!=0)
            {
                j=(j+2)%m;
                k=(k+1)%m;
            }
            a[j][k]=i;
            i++;
            //输出所有元素 
        }
    }
    for(x=0;x<m;x++)
    {
		for(y=0;y<m;y++)
			cout<<a[x][y]<<" ";
		cout<<endl;
	}
}
