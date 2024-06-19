#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;

	// Constructor
	Node(int d) : data(d), left(nullptr), right(nullptr) {}

	// Copy Constructor for deep copy
	Node(const Node& other) {
		// TODO
		data = other.data;
		left = other.left;
		right = other.right;

	}

	// Destructor
	~Node() {
		delete left;
		delete right;
	}
};

class BinaryTree {
public:
	Node* root;

	// Constructor
	BinaryTree() : root(nullptr) {}

	// Copy Constructor for deep copy
	BinaryTree(const BinaryTree& other) {
		if (other.root == nullptr) {
			root = nullptr;
			return;
		}

		queue<Node*> q;
		q.push(other.root);
		
		root = new Node(other.root->data);

		queue<Node*> copiedQ;
		copiedQ.push(root);

		while (!q.empty()) {
			Node* currOrig = q.front();
			Node* currCopy = copiedQ.front();

			q.pop();
			copiedQ.pop();
			if (currOrig->left) {
				currCopy->left = new Node(currOrig->left->data);
				q.push(currOrig->left);
				copiedQ.push(currCopy->left);
			}

			if (currOrig->right) {
				currCopy->right = new Node(currOrig->right->data);
				q.push(currOrig->right);
				copiedQ.push(currCopy->right);
			}
		}
	}

	// Destructor
	~BinaryTree() {
		delete root;
	}

	
	void insert(int data) {
		// TODO
		Node* newNode = new Node(data);


		if (!root) {
			root = newNode;
			return;
		}


		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			Node* current = q.front();
			q.pop();

			if (!current->left) {
				current->left = newNode;
				return;
			}
			else {
				q.push(current->left);
			}


			if (!current->right) {
				current->right = newNode;
				return;
			}
			else {
				q.push(current->right);
			}
		}

	}

	void printInPreOrder() {
		if (root == nullptr)
			return;

		cout << root->data;
		Node* curr = root;
		
		
		if (root->left || root->right) {
			
			if (root->left) {
				cout << ",";
				BinaryTree* left_tree = new BinaryTree();
				left_tree->root = curr->left;
				left_tree->printInPreOrder();
			}
			if (root->right) {
				cout << ",";
				BinaryTree* right_tree = new BinaryTree();
				right_tree->root = curr->right;
				right_tree->printInPreOrder();
			}
		}
		
	}

	void reverse() {
		// TODO
		if (root == NULL)
		return;
		Node* curr = root;
		if (curr) {
			if (curr->left && curr->right) {
				Node* temp = curr->left;
				curr->left = curr->right;
				curr->right = temp;
			}
			else if (curr->left) {
				curr->right = curr->left;
				curr->left = nullptr;
			}
		}
		

		
		BinaryTree* left_tree = new BinaryTree();
		left_tree->root = curr->left;
		left_tree->reverse();


		BinaryTree* right_tree = new BinaryTree();
		right_tree->root = curr->right;
		right_tree->reverse();


	}


};

//		1
//	   / \
//	  2   3
//	 / \
//	4   5
int main(void) {
	BinaryTree bt;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int data;
		std::cin >> data;
		bt.insert(data);
	}



	bt.printInPreOrder();
	cout << endl;
	bt.reverse();
	bt.printInPreOrder();
	cout << endl;

	BinaryTree bt2 = bt;
	bt2.printInPreOrder();
	
}