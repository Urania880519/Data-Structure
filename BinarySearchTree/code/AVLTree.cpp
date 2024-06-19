#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
struct TreeNode {
    int value, height;
    TreeNode* lchild, * rchild;
    TreeNode(int v) :value(v), height(1), lchild(NULL), rchild(NULL) {}
};

int getHeight(TreeNode* root) {
    // TODO
    if (root == NULL)
        return 0;
    return root->height;
}

int getbalanceFactor(TreeNode* root) {
    // TODO
    if (root == NULL)
        return 0;
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(TreeNode* root) {
    // TODO
    if (root == nullptr) {
        return;
    }
    int leftHeight = (root->lchild != nullptr) ? root->lchild->height : 0;
    int rightHeight = (root->rchild != nullptr) ? root->rchild->height : 0;
    root->height = 1 + max(leftHeight, rightHeight);
}

void L(TreeNode*& root) {
    // TODO
    TreeNode* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(TreeNode*& root) {
    // TODO
    TreeNode* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(TreeNode*& root, int v) {
    if (root == NULL) {
        root = new TreeNode(v);
        return;
    }
    
    if (v < root->value) {
        // TODO
        insert(root->lchild, v);
        
    }
    else {
        // TODO
        insert(root->rchild, v);
    }

    updateHeight(root);

    int balance = getbalanceFactor(root);

     

    // Left Left Case  
    if (balance > 1 && v < root->lchild->value) {
        R(root);
    }
        

    else if (balance < -1 && v > root->rchild->value) {
        L(root);
    }
        

    
    else if (balance > 1 && v > root->lchild->value)
    {
        L(root->lchild);
        R(root);
    }

    
    else if (balance < -1 && v < root->rchild->value)
    {
        R(root->rchild);
        L(root);
    }

}

int main() {
    int n, tmp;
    TreeNode* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        insert(root, tmp);
    }
    printf("%d\n", root->value);
    return 0;
}