#include<stdio.h>
#include<stdlib.h>

int matchCount(char[],char[],int n, int m);

int main()
{
   FILE*fp = fopen("StrMtchRes.txt","w");
   int n = 10;
   
   while(n != 110)
   {
      int b, w ,avg, i;
      char txt[n],ptrn[3];
     
      for(i=0; i<n; i++)
         txt[i] = 'a';
         
      for(i=0; i<3; i++)
         ptrn[i] = 'a';   // "aaa" for best case
      b = matchCount(txt,ptrn,n,3);
     
      ptrn[2] = 'b'; // "aab" for worst case
      w = matchCount(txt,ptrn,n,3);
     
      ptrn[1] = 'b'; // "aba" for average case
      avg = matchCount(txt,ptrn,n,3);
     
      fprintf(fp,"%d\t%d\t%d\t%d\n",n,b,w,avg);
      n+= 10;    
   }
   
   fclose(fp);
   
   return 0;
}

int matchCount(char txt[],char ptrn[], int n, int m)
{
   int i, j, count = 0;
   for(i = 0; i <= n-m; i++)
   {
      j = 0;
      while(j<m && ptrn[j] == txt[i+j])
      {
         count++;
         j++;
      }
      if(j == m)
        break;

      count++;
   }
   
   return count;
}
