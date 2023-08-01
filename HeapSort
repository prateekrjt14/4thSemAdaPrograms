//HeapSort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[], int n, int i){
    int parent=i;
    int lchild=2*i;
    int rchild=2*i+1;

    count++;
    if(lchild<=n && a[parent]<a[lchild])
    parent=lchild;

    if(rchild<=n && a[parent]<a[rchild])
    parent=rchild;
   
    if(parent!=i){
        swap(a+i,a+parent);
        heapify(a,n,parent);
    }
}

void heap(int a[],int n){
    int i;
    for(i=n/2;i>=1;i--)/////////
    heapify(a,n,i);

    for(i=n;i>1;i--){
        swap(a+1,a+i);
        heapify(a,i-1,1);//
    }
}

void main(){
    FILE *fp=fopen("heap.txt","w");
    srand(time(0));////
    for(int n=10;n<110;n+=10){
       
        int *a=(int*)malloc(sizeof(int)*(n+1));/////
        //best case- decreasing order
        count=0;
        a[n]=rand()%100;
        for(int i=n;i>1;i--)//*** imp!!! indexing starts from 1
        a[i-1]=a[i]+rand()%100;////////same no.
        heap(a,n);
        fprintf(fp,"%d\t%d\t",n,count);

        //avg case
        count=0;
        for(int i=1;i<=n;i++)
        a[i]=rand()%100;
        heap(a,n);
        fprintf(fp,"%d\t",count);

        //worst case-ascending order
        count=0;
        for(int i=1;i<=n;i++)
        a[i]=i;
        heap(a,n);
        fprintf(fp,"%d\n",count);
    }
    fclose(fp);
}
