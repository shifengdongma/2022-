#include<iostream>
using namespace std;
int main()
{
    int m;
    cout<<"������m��";
    cin>>m;
    while(m%2==0)
        {
            cout<<"������������ȷ��m��";
            cin>>m;
        }
    int a[100][100];
    int i=1,j,k,x,y;
    for(x=0;x<100;x++)//�������� 
    {
        for(y=0;y<100;y++)
        a[x][y]=0;
    }
    while(i<=m*m)
    {
        if(i==1)//��һ��λ�ø�ֵ
        {
            j=0;
            k=m/2;
            a[j][k]=i;
            i++;
            //cout<<i;
        }
        else//����λ�ø�ֵ
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
            //�������Ԫ�� 
        }
    }
    for(x=0;x<m;x++)
    {
		for(y=0;y<m;y++)
			cout<<a[x][y]<<" ";
		cout<<endl;
	}
}
