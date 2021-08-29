#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
 
void quick_sort(int[],int,int);
int partition(int[],int,int);
void insertion_sort(int[],int);
 
void main(void)
{
double quick_time = 0.0, insert_time = 0.0;
int i, n=100000;
int a[n];
srand(time(0));
for(i=0;i<n;i++)
	a[i] = (rand()%(100-0)+1);
printf("Array of 100000 random numbers is initialized\n\n");
clock_t begin = clock();
quick_sort(a,0,n-1);
clock_t end = clock();
quick_time += (double)(end - begin) / CLOCKS_PER_SEC;
printf("The array is sorted using quick sort in %f seconds\n", quick_time);
for(i=0;i<n;i++)
	a[i] = (rand()%(100-0)+1);
clock_t start = clock();
insertion_sort(a, n);
clock_t finish = clock();
insert_time += (double)(finish - start) / CLOCKS_PER_SEC;
printf("The array is sorted using insertion sort in %f seconds\n", insert_time);
}
 
void quick_sort(int a[],int l,int u)
{
int j;
if(l<u)
{
j=partition(a,l,u);
quick_sort(a,l,j-1);
quick_sort(a,j+1,u);
}
}
 
int partition(int a[],int l,int u)
{
int v,i,j,temp;
v=a[l];
i=l;
j=u+1;
do
{
do
i++;
while(a[i]<v&&i<=u);
do
j--;
while(v<a[j]);
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
a[l]=a[j];
a[j]=v;
return(j);
}

void insertion_sort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
 
        
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
