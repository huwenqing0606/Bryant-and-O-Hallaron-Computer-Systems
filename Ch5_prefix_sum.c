#include <stdio.h>
#include <stdlib.h>

/* Compute prefix sum of vector a */

void psum1(float a[], float p[], long n)
{
    long i;
    p[0]=a[0];
    for (i=1; i<n; i++){
        p[i]=p[i-1]+a[i];
    }
}

void psum2(float a[], float p[], long n)
{
    long i;
    p[0]=a[0];
    for (i=1; i<n-1; i+=2){
        float mid_val=p[i-1]+a[i];
        p[i]=mid_val;
        p[i+1]=mid_val+a[i+1];
    }
    /* for even n, finish remaining element */
    if (i<n){
        p[i]=p[i-1]+a[i];
    }
}

void main(){
    float a[5]={1,2,3,4,5};
    float p[5]={0,0,0,0,0};
    int n=5;
    int i;
    psum1(a,p,n);
    for (i=0;i<n;i++){
        printf("%9.6f ", p[i]);
    }
    printf("\n");
    psum2(a,p,n);
    for (i=0;i<n;i++){
        printf("%9.6f ", p[i]);
    }
}