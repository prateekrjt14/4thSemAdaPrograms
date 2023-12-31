#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSrch(int[],int,int);

int main()
{
  int w, b, a, n = 10, i;
  FILE*fp = NULL;
 
  fp = fopen("linSrchRes.txt","w");
 
  if(fp == NULL)
  {
     printf("error...");
     exit(1);
  }
  srand(time(NULL));
  while(n!=110)
  {
   int arr[n];
   for (i = 0; i < n; i++)
   arr[i] = rand()%100;
   
   i = n/2;
   b = linearSrch(arr,n,arr[0]);
   w = linearSrch(arr,n,9999);
   a = linearSrch(arr,n,arr[i]);  
   fprintf(fp,"%d\t%d\t%d\t%d\n",n,b,w,a);  
 
   n+= 10;
  }  
  fclose(fp);

  return 0;
}

int linearSrch(int arr[],int n, int x)
{
   int i;
   for (i = 0; i < n; i++)
   {
    if (arr[i] == x)  
    {
      break;
    }
   }
   if (i == n)
   {
     i--;
   }  
   i++;  
   
   return i;
}
