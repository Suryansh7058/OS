#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[],char *en[])
{
    int i,j,mid,ele;
    int arr[argc];
    for(j=0;j<argc-1;j++)
    {
        int n=atoi(argv[j]);
        arr[j]=n;
    }
    ele=atoi(argv[j]);
    i = 0;
    j= argc - 1;
    mid = (i+j)/2;
    while (arr[mid]!=ele && i<=j)
    {
        if (ele>arr[mid])
            i = mid + 1;
        else
            j=mid-1;
        mid = (i+j)/2;
    }
    if(i<=j)
        printf("Element is present in the list");
    else
        printf("not found!" );
}
