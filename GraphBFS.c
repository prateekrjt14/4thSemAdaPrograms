// BFS, cyclicity & connectivity using BFS
// graph implemented by adj matrix

// while taking inputs, vertices start index is '1', i.e. in program if vtx is from 0->2, then while entering input, enter 1->3 

#include<stdio.h>

int n,i,j,k, count = 0;
/////////  Graph Creation & Display//////////
void printGraphMatrix(int (*a)[n]);
void createGraph(int (*a)[n], int[]);

///////// BFS utility for Connectivity & Acyclicity  //////////
int checkAcyclicity(int (*a)[n]);
int bfsAcyclicity(int (*a)[n], int[], int);

//////// Connectivity  /////////
void checkConnectivity(int (*a)[n], int[]);
void bfsConnectivity(int (*a)[n], int[], int);

int main()
{
    
    printf("Enter the number of vertices in the graph:\t");
    scanf("%d",&n);
    
    int a[n][n], vtxIndegree[n], acyclic; // we'll be starting the bfs from that vertex whose indegree is zero

    for(int i = 0; i<n; i++)
       vtxIndegree[i] = 0;
       
    createGraph(a, vtxIndegree);
    printGraphMatrix(a);
    
    checkConnectivity(a, vtxIndegree);
    acyclic = checkAcyclicity(a);
    
    if(acyclic)
      printf("\nAcyclic\n");
      
    else
      printf("\nCyclic\n");
    
    return 0;
}

void printGraphMatrix(int (*a)[n])
{
    printf("\nAdjacency Matrix....\n");
    for(i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
           printf("%d  ",a[i][j]);
        printf("\n");
    }
}

void createGraph(int (*a)[n], int vtxIndegree[])
{
    for(int i = 0; i<n; i++)     
    {
        for(int j = 0; j<n; j++)   // initializing each value to of graph zero
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
            vtxIndegree[j]+=1;
        }
    }
}

void checkConnectivity(int (*a)[n], int vtxIndegree[])
{
    FILE*fp = fopen("results.txt","a");
    int v[n], startIndex = 0, connected = 1;
    for(int i = 0; i<n; i++)
       v[i] =  0;
    
    for(int i = 0; i<n; i++)
       if(vtxIndegree[i] == 0)
       {  
           startIndex = i;
           break;
       }   
     printf("\nChecking connectivity from vertex %d\n",startIndex+1);      
    
    bfsConnectivity(a,v,startIndex);
    fprintf(fp,"%d\t%d\n",n,count);
    fclose(fp);
    
    for(int i = 0; i<n; i++)
       if(!v[i])
          connected = 0;
    
    if(connected == 1)
      printf("\nConnected\n");
      
    else
    {
        printf("\nNot connected, component 1 displayed above...\n");
        int component = 2;
            
        for(int i = 0; i<n; i++)
        {
            if(!v[i])
            {
               printf("\n\nComponent %d\n",component++);
               bfsConnectivity(a,v,i);  
            }
        }
    }
}

void bfsConnectivity(int (*a)[n], int v[], int k)
{
    v[k] =  1;
    
    printf("\n\t\tVertex %d visited\n", k + 1);
    int queue[n], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        queue[i] = 0;

    queue[rear] = k;
    while (front <= rear)
    {
        int currentNode = queue[front];
        printf("\nCurrent Node is : %d\n",currentNode+1);
        for (int i = 0; i < n; i++)
        {
            count++;
            if (a[currentNode][i])  // an edge from 'currentNode+1' -> 'i+1' exists
            {
                if (!v[i]) // vertex 'i+1' has not been visited yet
                {
                    rear += 1;
                    queue[rear] = i;
                    printf("\n\t\tVertex %d visited\n", i + 1);
                    v[i] = 1;
                }
            }
        }
        front += 1;
    }
}

int checkAcyclicity(int (*a)[n])
{
    int v[n], result; // result = 0 ----> Cyclic
       
    for(i = 0; i<n; i++)
    {
        for(int j = 0; j < n; j++)
           v[j] = 0;
        
        result = bfsAcyclicity(a,v,i);
        if(!result)
           break;
    }
    return result;
}

int bfsAcyclicity(int (*a)[n], int v[], int k) // from each vertex 'k+1', we are checking ther cyclicity through BFS
{
    v[k] =  1;
    int queue[n], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        queue[i] = 0;

    queue[rear] = k;
    while (front <= rear)
    {
        int currentNode = queue[front];
        for (int i = 0; i < n; i++)
        {
            count++;
            if (a[currentNode][i])  // an edge from 'currentNode+1' -> 'i+1' exists
            {
                if (!v[i]) // vertex 'i+1' has not been visited yet
                {
                    rear += 1;
                    queue[rear] = i;
                    v[i] = 1;
                }
                
                else if(i == k)
                   return 0;   // Cyclicity found from vertex 'k+1'
            }
        }
        front += 1;
    }
    return 1; // No cyclicity found from vertex 'k+1' 
}
