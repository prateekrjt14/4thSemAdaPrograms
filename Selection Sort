#include<stdio.h>
#include<stdlib.h>

int selectSort(int[],int);

int main()
{
   int n = 10;
   FILE*fp = fopen("selectSortRes.txt","w");
   
   if(fp == NULL)
   {
      printf("Error...\n");
      exit(1);
   }
   
   while(n != 110)
   {
      int arr[n], res, i;
     
      for(i = 0; i<n; i++)
         arr[i] = rand()%200;
         
      res = selectSort(arr,n);
     
      fprintf(fp,"%d\t%d\n",n,res);
      n+= 10;  
   }
   
   fclose(fp);
   return 0;
}

int selectSort(int a[], int n)
{
   int i, j, temp, count = 0;
   
   for(i = 0; i<n-1; i++)
   {
      int min = i;
      for(j = i+1; j<n; j++)
      {
         count++;
         if(a[j] < a[min])
         {
            min = j;
         }
      }
      if(min != i)
      {
         temp = a[min];
         a[min] = a[i];
         a[i] = temp;
      }
   }
     
   return count;
}
