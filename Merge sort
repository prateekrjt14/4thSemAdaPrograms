#include<stdio.h>
#include<stdlib.h>

void mergeSort(int[],int,int,int*);
void merge(int[],int,int,int,int*);

int join(int arr1[], int left1[], int right1[], int l1, int m1, int r1)
{
   int i; // So used in second loop
   for (i = 0; i <= m1 - l1; i++)
      arr1[i] = left1[i];
   for (int j = 0; j < r1 - m1; j++)
      arr1[i + j] = right1[j];
}

int split(int arr1[], int left1[], int right1[], int l1, int m1, int r1){
   for (int i = 0; i <= m1 - l1; i++)
      left1[i] = arr1[i * 2];
   for (int i = 0; i < r1 - m1; i++)
      right1[i] = arr1[i * 2 + 1];
}

int generateWorstCase(int arr1[], int l1, int r1){
   if (l1 < r1){
      int m1 = l1 + (r1 - l1) / 2;
      // creating two auxillary arrays
      int left1[m1 - l1 + 1];
      int right1[r1 - m1];
      // Storing alternate array elements in left
      // and right subarray
      split(arr1, left1, right1, l1, m1, r1);
      // Recursing first and second halves
      generateWorstCase(left1, l1, m1);
      generateWorstCase(right1, m1 + 1, r1);
      // joining left and right subarray
      join(arr1, left1, right1, l1, m1, r1);
   }
}

int main()
{  
   FILE*fp = fopen("mrgeSrtRes.txt","w");
   
   int n = 4;
   
   while(n!=128)
   {
      int arr[n], i, count=0, *p=&count;
      for(i=0; i<n; i++)
         arr[i] = i+1;   // keeping both the sub arrays in ascending order
         
      mergeSort(arr,0,n-1,p);
      fprintf(fp,"%d\t%d\t",n,*p); // best case
     
      *p=0;
      generateWorstCase(arr,0,n-1);
      mergeSort(arr,0,n-1,p);
      fprintf(fp,"%d\t",*p);   //worst case
     
      for(i=0; i<n; i++)
         arr[i] = rand()%n;
      *p=0;
      mergeSort(arr,0,n-1,p);
      fprintf(fp,"%d\n",*p);    //average case
     
     
      n*=2;      
   }
   
   fclose(fp);
   
   return 0;
}

void merge(int arr[],int low, int high, int mid,int* count)
{
   int i = low, j = mid+1, k = low; int b[110];
   
   
   while(i<=mid && j<=high)
   {
      *count+=1;
      if(arr[i] < arr[j])
      {
         b[k] = arr[i];
         i++;
      }
     
      else
      {
         b[k] = arr[j];
         j++;
      }
     
      k++;

   }
   
   while(i<=mid)
   {
      b[k] = arr[i];
      i++;
      k++;
   }
   
   while(j<=high)
   {
      b[k] = arr[j];
      j++;
      k++;    
   }
   
   int m;
   for(m=low; m<=high; m++)
      arr[m] = b[m];
}

void mergeSort(int arr[], int low, int high, int*count)
{
   if(low == high)
     return;
   int mid = (high+low)/2;
   mergeSort(arr,low,mid,count);
   mergeSort(arr,mid+1,high,count);
   
   merge(arr,low,high,mid,count);
}

