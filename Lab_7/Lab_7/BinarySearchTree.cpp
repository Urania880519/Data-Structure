#include<iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* lchild, * rchild;
    TreeNode(int v) : value(v), lchild(NULL), rchild(NULL) {}
};

TreeNode* insert(TreeNode* node, int value) {
    //TO-DO
    TreeNode* new_node = new TreeNode(value);
    
    if (!node) {
        node = new_node;
        return node;
    }
    
        //while (curr) {
        //    if (value > curr->value) {
        //        curr = curr->lchild;
        //    }
        //    else if(value<curr->value)
        //    {
        //        curr = curr->rchild;
        //    }
        //}
        //curr = new_node;
        //return node;
        
    if (value < node->value) {
        node->lchild = insert(node->lchild, value);
    }
    else if (value > node->value) {
        node->rchild = insert(node->rchild, value);
    }
    return node;

}

void inOrder(TreeNode* node) {
    //TO-DO
    if (node == NULL)
        return;

    inOrder(node->lchild);
    cout << node->value << " ";
    inOrder(node->rchild);
    
}

void preOrder(TreeNode* node) {
    //TO-DO
    //TreeNode* curr = node;
    //if (curr == nullptr)
    //    return;

    //cout << node->value << " ";
    
    //if (curr->lchild || curr->rchild) {

    //    if (curr->lchild) {
    //       
    //        TreeNode* left_start = new TreeNode(NULL);
    //        left_start = curr->lchild;
    //        preOrder(left_start);
    //    }
    //    if (curr->rchild) {
            
    //        TreeNode* right_start = new TreeNode(NULL);
    //        right_start = curr->rchild;
    //        preOrder(right_start);
    //    }
    //}
    if (node == NULL)
        return;
    cout << node->value << " ";
    preOrder(node->lchild);
    preOrder(node->rchild);
    
}

void postOrder(TreeNode* node) {
    //TO-DO
    if (node == NULL)
        return;

    postOrder(node->lchild);
    postOrder(node->rchild);
    cout << node->value << " ";

}

int main() {
    int n;
    cin >> n;
    
    //TO-DO
    TreeNode* original = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        
        original= insert(original, val);
    }
    
    cout << "InOrder traversal: ";
    inOrder(original);
    cout << endl;
    cout << "PreOrder traversal: ";
    preOrder(original);
    cout << endl;
    cout << "PostOrder traversal: ";
    postOrder(original);
    cout << endl;


    return 0;
}