#include<stdio.h>
void main()
{
    int a[20],n,k,item,i;
    void insert(int a[],int n,int k,int item);
    printf("ARYAN THAKUR\n");
    printf("enter number of elements(<=20)=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter element [%d]=",i);
        scanf("%d",&a[i]);
    }
    printf("enter item to insert=:");
    scanf("%d",&item);
    printf("enter index position for new item=");
    scanf("%d",&k);
    printf("elements after insertion==\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}
void insert(int a[],int n,int k,int item)
{
    int i=n-1;
    while (i>=k)
    {
        a[i+1]=a[i];
        i=i-1;
    }
    a[k]=item;
    n=n+1;
}
