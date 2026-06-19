/*
10. 生成huffman树并求叶子结点的哈夫曼编码
最优二叉树，也称哈夫曼(Haffman)树，是指对于一组带有确定权值的叶结点，构造的具有最小带权路径长度的二叉树。输入叶子结点个数n，并依次输入各个叶子结点的值及其权重，生成哈夫曼树。随后根据输入的要查询的叶结点的值，依据生成的哈夫曼树输出相应的哈夫曼编码，对于查找不到的叶结点，输出false。

 

示例 1：

1733564044890.png

输入：叶子结点个数=[4],各结点的值与权重=[A 5  ,要查询的叶结点的值=[C]
                                      B 4
                                      C 1
                                      D 2]
输出：相应哈夫曼编码=[100]
示例 2：

输入：叶子结点个数=[4],各结点的值与权重=[A 5  ,要查询的叶结点的值=[E]
                                      B 4
                                      C 1
                                      D 2]
输出：相应哈夫曼编码=[false]
 

提示：

树中节点数目在范围 [0, 100] 内

-100 <= Node.val <= 100

输入层序之间没有空格，如A、B、C三个结点输入为ABC

输入结点的度之间有空格如示例一A、B、C、D、E五个结点的度输入应为：2 0 1 1 0

考生只需补充以下函数即可：void select()、void huff_tree()、void huf_code()


Auxiliary Code

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>  // 用于 strcpy 和 malloc

using namespace std;

// 定义哈夫曼树节点类型
struct NodeType {
    char data;      // 字符数据
    double weight;  // 权值
    int parent;     // 父节点索引
    int lch;        // 左孩子索引
    int rch;        // 右孩子索引
    NodeType() : data(0), weight(0), parent(0), lch(0), rch(0) {}
};

typedef vector<NodeType> HufTree; // 定义哈夫曼树类型
typedef char** HufCode;          // 定义哈夫曼编码表类型

// 在树中选择两个权值最小且父节点为空的节点
void select(HufTree* ht, int n, int* s1, int* s2) {
   
}

// 构造哈夫曼树
void huff_tree(const vector<int>* w, int n, HufTree* ht) {
    
}

// 构建哈夫曼编码表
void huf_code(HufCode* hcd, HufTree* ht, int n) {
   
}

class HuffmanTree {
private:
    HufTree tree;  // 哈夫曼树
    int n;         // 叶子节点数量
    HufCode huffmanCode;  // 哈夫曼编码表

public:
    // 构造函数，初始化树
    HuffmanTree(const vector<char>* data, const vector<int>* weights) {
        n = data->size();
        tree.resize(2 * n);

        // 初始化叶子节点
        for (int i = 1; i <= n; i++) {
            tree[i].data = (*data)[i - 1];
            tree[i].weight = (*weights)[i - 1];
        }

        // 构造哈夫曼树
        huff_tree(weights, n, &tree);

        // 生成哈夫曼编码
        huf_code(&huffmanCode, &tree, n);
    }

    // 输出指定节点的哈夫曼编码
    void printHuffmanCode(const char target) const {
        for (int i = 1; i <= n; i++) {
            if (tree[i].data == target) {
                cout << huffmanCode[i] << endl;
                return;
            }
        }
        cout << "false";
    }

    HuffmanTree() {
        // 释放编码表内存
        for (int i = 1; i <= n; i++) {
            free(huffmanCode[i]);
        }
        free(huffmanCode);
    }
};

int main() {
    int n;
    vector<char> data;
    vector<int> weights;

    // 输入叶子节点个数和字符及其权值
    cin >> n;

    data.resize(n);
    weights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i] >> weights[i];
    }

    // 构造哈夫曼树
    HuffmanTree huffman(&data, &weights);

    // 查询指定字符的哈夫曼编码
    char target;
    cin >> target;
    huffman.printHuffmanCode(target);

    return 0;
}
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct HufNode{
    char data;
    int weight;
    int parent,lch,rch;
}HufNode,*HufTree;

void Huff_Tree(HufTree ht,int *WeightElem,int num);
void Select(HufTree ht,int num,int *s1,int *s2);
char** huf_code(HufTree ht,int num);

int main()
{
    int num;
    scanf("%d",&num);
    char *DataElem=(char*)malloc((num+1)*sizeof(char));
    int *WeightElem=(int*)malloc((num+1)*sizeof(int));
    for(int i=1;i<num+1;i++){
        scanf(" %c",&DataElem[i]);
        scanf("%d",&WeightElem[i]);
        // printf("%c %d\n",DataElem[i],WeightElem[i]);
    }
    HufTree ht=(HufTree)malloc(2*num*sizeof(HufNode));
    Huff_Tree(ht,WeightElem,num);
    char** huffmanCode=huf_code(ht,num);

    char target;
    scanf(" %c",&target);
    // printf("%c\n",target);
    for(int i=1;i<=num;i++){
        if(target==DataElem[i]){
            printf("%s\n",huffmanCode[i]);
            return 0;
        }
    }

    printf("false\n");

    return 0;
}

void Huff_Tree(HufTree ht,int *WeightElem,int num){
    int i,s1,s2;
    for(i=1;i<2*num;i++){
        if(i>=1&&i<=num)ht[i].weight=WeightElem[i];
        else ht[i].weight=0;
        ht[i].parent=0;
        ht[i].lch=ht[i].rch=0;
    }
    for(i=num+1;i<2*num;i++){
        Select(ht,num,&s1,&s2);
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        if(ht[s1].weight==ht[s2].weight){
            if(s1<s2){
                int temp=s1;
                s1=s2;
                s2=temp;
            }
        }
        ht[i].lch=s1;ht[i].rch=s2;
        ht[s1].parent=ht[s2].parent=i;
    }
}

void Select(HufTree ht,int num,int *s1,int *s2){
    int i,min;
    for(min=50000,i=1;i<2*num;i++){
        if(ht[i].parent==0 && ht[i].weight!=0 && ht[i].weight<min){
            min=ht[i].weight;
            *s1=i;
        }
    }
    for(min=50000,i=1;i<2*num;i++){
        if(ht[i].parent==0 && ht[i].weight!=0 && i!=*s1 && ht[i].weight<min){
            min=ht[i].weight;
            *s2=i;
        }
    }
}

char** huf_code(HufTree ht,int num){
    char *cd,**hcd;
    int i,start,c,f;
    hcd=(char**)malloc((num+1)*sizeof(char*));
    cd=(char*)malloc(num*sizeof(char));
    for(i=1;i<=num;i++){
        cd[num-1]='\0';
        start=num-1;c=i;f=ht[c].parent;
        while(f){
            if(ht[f].lch==c)cd[--start]='0';
            else cd[--start]='1';
            c=f;f=ht[f].parent;
        }
        hcd[i]=(char*)malloc((num-start)*sizeof(char));
        strcpy(hcd[i],&cd[start]);
    }
    return hcd;
}