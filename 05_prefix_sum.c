#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Compute prefix sum of vector a */

void psum1(float a[], float p[], long n)
{
    int cpe_count=0;
    long i;
    p[0]=a[0];
    for (i=1; i<n; i++){
        p[i]=p[i-1]+a[i];
        cpe_count++;
    }
    printf("psum1 cpe_count=%d\n", cpe_count);
}

void psum2(float a[], float p[], long n)
{
    int cpe_count=0;
    long i;
    p[0]=a[0];
    for (i=1; i<n-1; i+=2){
        float mid_val=p[i-1]+a[i];
        p[i]=mid_val;
        p[i+1]=mid_val+a[i+1];
        cpe_count++;
    }
    /* for even n, finish remaining element */
    if (i<n){
        p[i]=p[i-1]+a[i];
        cpe_count++;
    }
    printf("psum2 cpe_count=%.d\n", cpe_count);
}

void main(){
    int n=100;
    float a[n];
    float p[n];
    int i;
    for (i=0;i<n;i++){
        a[i]=i;
        p[i]=0;
    }
    psum1(a,p,n);
/*    for (i=0;i<n;i++){
        printf("%f ", p[i]);
    } 
    printf("\n"); */
    psum2(a,p,n);
/*    for (i=0;i<n;i++){
        printf("%f ", p[i]);
    } */
}