#include<stdio.h>

int i,j,k,t,sum,num;
int a[1000];
bool f[500000];
int main()
{
    while(1){sum=num=0;
        for(i=1;i<=6;i++){
            scanf("%d",&k);
            sum+=k*i;
            j=1;
            while(k>=j)a[++num]=j*i,k-=j,j*=2;
            if(k)a[++num]=k*i;
        }if(!sum)break;
        printf("Collection #%d:\n",++t);
        if(sum%2==1){printf("Can't be divided.\n\n");continue;}
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=1;i<=num;i++)
            for(j=sum;j>=a[i];j--)
                if(f[j-a[i]])f[j]=1;
        if(f[sum/2])printf("Can be divided.\n\n");
            else printf("Can't be divided.\n\n");
    }return 0;
}
