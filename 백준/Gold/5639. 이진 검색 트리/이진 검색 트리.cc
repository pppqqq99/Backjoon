#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000000][3] = {0,};

int treeRight(int p, int n){
    arr[p][2] = n;
    arr[n][0] = p;
    return n;
}

int treeLeft(int p, int n){
    arr[p][1] = n;
    arr[n][0] = p;
    return n;
}

void makeTree(int root, int node){
    int parent = root, before, c=0;
    while(parent != 0){
        before = parent;
        if(parent > node) { parent = arr[parent][1]; c=1;}
        else { parent = arr[parent][2]; c=2;}
    }
    if(c==1) treeLeft(before, node);
    if(c==2) treeRight(before, node);
}

void postOrder(int root){
    if(root == 0){ return ;}
    int left = arr[root][1];
    int right = arr[root][2];
    postOrder(left);
    postOrder(right);
    printf("%d\n", root);
}

int main(){
    int parent, node, root;
    cin>>parent;
    root = parent;
    while(cin>>node){
        makeTree(root, node);
    }
    postOrder(root);
}