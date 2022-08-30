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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>parent;
    root = parent;
    while(cin>>node){
        makeTree(root, node);
        // if(parent > node){
        //     parent = treeLeft(parent, node);
        // }else{
        //     int before = parent;
        //     int child = 2, temp;
        //     while((parent = arr[parent][0]) != 0 && parent < node) before = parent;
        //     while((temp = arr[before][child]) != 0){
        //         if(temp > node) child = 1;
        //         else child = 2;
        //         before = temp;
        //     }
        //     if(child == 1)
        //         parent = treeLeft(before, node);
        //     else
        //         parent = treeRight(before, node);
        // }
    }
    
    postOrder(root);

}