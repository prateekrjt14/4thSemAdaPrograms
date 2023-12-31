#include<stdio.h>
#include<stdlib.h>

int insertionSort(int[],int,int*);

int main()
{
   FILE*fp = fopen("inSortRes.txt","w");
   
   int n=10;
   while(n!=110)
   {
      int arr[n], b, w, avg, count = 0, *p, i;
      p = &count;
     
      for(i=0; i<n; i++)
         arr[i] = i+1;   // best case
         
      b = insertionSort(arr,n,p);
     
      *p=0;
      for(i=0; i<n; i++)
         arr[i] = n-i;   // worst case
         
      w = insertionSort(arr,n,p);
     
      *p=0;
      for(i=0; i<n; i++)
         arr[i] = rand()%100;   // average case
         
      avg = insertionSort(arr,n,p);
     
      fprintf(fp,"%d\t%d\t%d\t%d\n",n,b,w,avg);
      n+=10;  
   }
   fclose(fp);

   return 0;
}

int insertionSort(int arr[], int n, int*p)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            *p+=1;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
       
        if(j == i-1)  //bcz for best case it won't enter in the loop, but one comparision will be done
        *p+=1;        // ie. arr[j] < temp in the first case
       
        arr[j + 1] = key;
    }
   
    return *p;
}
