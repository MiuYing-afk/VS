#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int n;
int graph[100][100];
int visited[100];
char vertex[100][10];
int first;  // 控制空格

int findIndex(char *v);
void bfs(int v);

int main()
{
    int m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%s",vertex[i]);
    }

    char u[10],v[10];
    for(int i=0;i<m;i++){
        scanf("%s %s",u,v);
        int a=findIndex(u);
        int b=findIndex(v);
        graph[a][b]=1; //有向图单向边
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    first = 1; //初始化标记

    char start[10];
    scanf("%s",start);
    int startIndex=findIndex(start);
    bfs(startIndex);

    return 0;
}

int findIndex(char *v){
    for(int i=0;i<n;i++){
        if(strcmp(vertex[i],v)==0){
            return i;
        }
    }
    return -1;
}

void bfs(int v){
    int queue[100];
    int front=0,rear=0;
    visited[v]=1;
    //输出处理
    if(first){
        printf("%s",vertex[v]);
        first=0;
    }else{
        printf(" %s",vertex[v]);
    }
    queue[rear++]=v;

    while(front<rear){
        int current=queue[front++];
        // 倒序循环 i从n-1到0  模拟头插邻接表顺序！关键
        for(int i = n-1; i >= 0; i--){
            if(graph[current][i]==1 && !visited[i]){
                visited[i]=1;
                printf(" %s",vertex[i]);
                queue[rear++]=i;
            }
        }
    }
}