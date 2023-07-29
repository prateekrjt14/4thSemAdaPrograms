// Topological sorting using DFS
// graph implemented by adj matrix
// while taking inputs, vertices start index is '1', i.e. in program if vtx is from 0->2, then while entering input, enter 1->3 

#include<stdio.h>

int n,i,j, u = -1, acyclic = 1, connected = 1, count = 0;
/////////  Graph Creation //////////
void printGraphMatrix(int (*a)[n]);

void createGraph(int (*a)[n],int []);

////////  DFS Traversal & Connectivity //////////
void DFS(int (*a)[n],int [], int[], int, int[]);
void checkDAG(int (*a)[n], int[], int[]);

int main()
{
    printf("Enter the number of vertices in the graph:\t");
    scanf("%d",&n);
    
    int a[n][n]; 
    int vtxInDegree[n], topSorted[n];

    for(int m=0; m<n; m++)
       vtxInDegree[m] = topSorted[m] = 0;
    
    createGraph(a,vtxInDegree);
    printGraphMatrix(a);
    
    checkDAG(a, vtxInDegree, topSorted);
    
    if(acyclic)
    {
       printf("\nTopological Sort for the above graph is...%d\n",u);
       for(int i = u; i >= 0; i--)
          printf("%d\t",topSorted[i]);
       printf("\n");     
    }  
      
    else
      printf("\nAbove graph is not a DAG, hence it's topological sorting is not possible...\n");
      
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

void DFS(int (*a)[n],int v[], int recursionStack[], int k, int topSorted[])
{
    if(!v[k])
    {
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
                   DFS(a,v,recursionStack,j, topSorted);
            }
        }
        recursionStack[k] = 0;
        topSorted[++u] = k+1;
    }
}    
    
void checkDAG(int (*a)[n], int vtxIndegree[], int topSorted[])
{
    int recursionStack[n], v[n], startIndex = 0;
    for(int i=0; i<n; i++)
       recursionStack[i] = v[i] = 0;    
       
    for(int i = 0; i<n; i++)
       if(vtxIndegree[i] == 0)
       {  
           startIndex = i;
           break;
       }   
       
    DFS(a,v,recursionStack,startIndex,topSorted);
    
    for(i=0; i<n; i++)
        if(!v[i])
           connected = 0;
    
    if(!connected)
    {
        for(i=0; i<n; i++)
           if(!v[i])
             DFS(a,v,recursionStack,i,topSorted);
    }
}
