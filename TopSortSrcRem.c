// Topological sorting (Source Removal)
// graph implemented by adj matrix

#include<stdio.h>
#include<stdlib.h>

int n, acyclic=1, connected=1;
/////////  Graph Creation //////////
void printGraphMatrix(int (*a)[n]);
void createGraph(int (*a)[n], int[], int[]);

////////  Acyclicity check using DFS //////////
void DFS(int (*a)[n],int[],int[], int);
void checkDAG(int (*a)[n],int[]);

////////  Topological sort (src removal) ///////////
void topSrtSrcRem(int (*a)[n], int[], int[], int[]);

int main()
{
    printf("Enter the number of vertices in the graph:\t");
    scanf("%d", &n);

    int a[n][n];
    int v[n], vtxInDegree[n], vtxOutDegree[n], topSort[n];

    for (int m = 0; m < n; m++)
    {
        v[m] = vtxInDegree[m] = vtxOutDegree[m] = topSort[m] = 0;
    }

    createGraph(a, vtxInDegree, vtxOutDegree);
    printGraphMatrix(a);

    printf("\nIndegree ..\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", vtxInDegree[i]);

    printf("\nOutdegree ..\n");
    for (int i = 0; i < n; i++)
        printf("%d  ", vtxOutDegree[i]);

    checkDAG(a, vtxInDegree);

    if (acyclic)
    {
        topSrtSrcRem(a, vtxInDegree, vtxOutDegree, topSort);
        printf("\n\nTopological Sorting\n\n");
        for (int i = 0; i < n; i++)
            printf("%d\t", topSort[i]);
    }
    else
        printf("\nThe graph is not a DAG, hence topological sorting is not possible...\n");
    return 0;
}

void printGraphMatrix(int (*a)[n])
{
    printf("\nAdjacency Matrix....\n");
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        printf("%d  ",a[i][j]);
        printf("\n");
    }
}

void createGraph(int (*a)[n], int vtxInDegree[], int vtxOutDegree[])
{
    for(int i = 0; i<n; i++)     
       for(int j = 0; j<n; j++) 
           a[i][j] = 0;
    
    int i,j;
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
            vtxOutDegree[i]+=1;
            vtxInDegree[j]+=1;
        }
    }
}

void DFS(int (*a)[n],int v[], int recursionStack[], int k)
{
    if(!v[k])
    {
        v[k] = 1;
        recursionStack[k] = 1;
        for (int j = 0; j < n; j++)
        {
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
    
void checkDAG(int (*a)[n], int vtxInDegree[])
{
    int recursionStack[n], v[n], startIndex = 0;
    for(int i=0; i<n; i++)
       v[i] = recursionStack[i] = 0;
       
    for(int i = 0; i<n; i++)
       if(vtxInDegree[i] == 0)
       {  
           startIndex = i;
           break;
       }      
    
    DFS(a,v,recursionStack,startIndex);
    
    for(int i=0; i<n; i++)
        if(!v[i])
           connected = 0;
    
    if(!connected) // other disconnected component/s can be cyclic
    {
        for(int i=0; i<n; i++)
           if(!v[i])
           { 
               DFS(a,v,recursionStack,i);
           }
    }
}

void topSrtSrcRem(int (*a)[n], int vtxInDegree[], int vtxOutDegree[], int topSort[])
{
    int flag = 1;
    int index = 0;
    int removeableVtx; // to store the index of the efficient vertex whose indegree is zero

    while (flag)
    {
        removeableVtx = -1;
        int maxOutdegree = -1;

        for (int i = 0; i < n; i++)
        {
            if (vtxInDegree[i] == 0 && vtxOutDegree[i] > maxOutdegree)
            {
                removeableVtx = i;
                maxOutdegree = vtxOutDegree[i];
            }
        }

        if (removeableVtx != -1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[removeableVtx][i])
                    vtxInDegree[i] -= 1;
            }

            vtxInDegree[removeableVtx] = -1; // so that this source doesn't get selected again
            vtxOutDegree[removeableVtx] = -1; // update the outdegree as well
            topSort[index] = removeableVtx + 1;
            index++;
        }
        else
        {
            flag = 0; // exit the loop if no vertex with zero indegree is found
        }
    }
}
