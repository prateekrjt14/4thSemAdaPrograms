// DFS, cyclicity & connectivity using DFS
// graph implemented by adj matrix
// while taking inputs, vertices start index is '1', i.e. in program if vtx is from 0->2, then while entering input, enter 1->3 

#include<stdio.h>

int n,i,j,k, acyclic = 1, connected = 1, count = 0;
/////////  Graph Creation //////////
void printGraphMatrix(int (*a)[n]);

void createGraph(int (*a)[n],int []);

////////  DFS Traversal & Connectivity //////////
void DFS(int (*a)[n],int [], int[], int);
void checkConnectivity(int (*a)[n], int[]);

int main()
{
    printf("Enter the number of vertices in the graph:\t");
    scanf("%d",&n);
    
    int a[n][n]; 
    int vtxInDegree[n];

    for(int m=0; m<n; m++)
       vtxInDegree[m] = 0;
    
    createGraph(a,vtxInDegree);
    printGraphMatrix(a);
    
    checkConnectivity(a, vtxInDegree);
    
    if(acyclic)
      printf("\nThe graph is acyclic...\n");
      
    else
      printf("\nThe graph is cyclic...\n");
      
    return 0;
}

void printGraphMatrix(int (*a)[n])
{
    printf("\nAdjacency Matrix....\n");
    for(i = 0; i<n; i++)
    {
        for(j=0; j<n; j++)
        printf("%d  ",a[i][j]);
        printf("\n");
    }
}

void createGraph(int (*a)[n], int vtxInDegree[])
{
    for(i = 0; i<n; i++)     
    {
        for(j = 0; j<n; j++) 
        a[i][j] = 0;
    }
    
    while(i != -1 || j != -1)
    {
        printf("\nEnter '-1' to stop !!\n");
        printf("An edge exists from: "); scanf("%d",&i);
        if(i == -1) break;
        printf("                 to: "); scanf("%d",&j);
        
        i--;
        j--;
        if(i >= n || j >= n)
        {
            printf("\nEnter valid vertices !!\n");
        }
        else
        {
            a[i][j] = 1;
            vtxInDegree[j]+=1;
        }
    }
}

void DFS(int (*a)[n],int v[], int recursionStack[], int k)
{
    if(!v[k])
    {
        printf("\nVertex %d visited.\n", k+1);
        v[k] = 1;
        recursionStack[k] = 1;
        for (int j = 0; j < n; j++)
        {
            count++;
            if(a[k][j])
            {
                if(v[j] && recursionStack[j])
                   acyclic=0;
                   
                else
                   DFS(a,v,recursionStack,j);
            }
        }
        recursionStack[k] = 0;
    }
}    
    
void checkConnectivity(int (*a)[n], int vtxIndegree[])
{
    FILE*fp = fopen("results.txt","a");
    int recursionStack[n], v[n], startIndex = 0;
    for(int i=0; i<n; i++)
       recursionStack[i] = v[i] = 0;    
       
    for(int i = 0; i<n; i++)
       if(vtxIndegree[i] == 0)
       {  
           startIndex = i;
           break;
       }   
     printf("\nChecking connectivity from vertex %d\n",startIndex+1);         
    
    DFS(a,v,recursionStack,startIndex);
    fprintf(fp,"%d\t%d\n",n,count);
    fclose(fp);
    
    for(i=0; i<n; i++)
        if(!v[i])
           connected = 0;
    
    if(!connected)
    {
        int component = 2;
        printf("\nThe graph is not connected!!\nComponent 1 displayed above\n");
        
        for(i=0; i<n; i++)
           if(!v[i])
           { 
               printf("\n\nComponent %d\n",component++); 
               DFS(a,v,recursionStack,i);
           }
    }
    
    else
       printf("\nThe graph is connected...\n");
}
