/*
 * Following code converts Binary Search Tree to Double Linked List data structure
*/

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
	
	Node(int data) {
		this->data =  data;
		this->prev = NULL;
		this->next = NULL;
	}
};

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int data;
	
	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
// 1. inorder traversal
// using head double pointer to prevent copying pointer
void convertInorder(TreeNode* root,TreeNode** head) {
	if(root == NULL) return;
	
	static TreeNode* prev = NULL;
	
	convertInorder(root->left, head);
	
	// save point of double linked list head
	if(prev == NULL) {
		*head = root;
	}
	
	else {
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	convertInorder(root->right,head);
}

// 2. preorder traversal

void convertPreOrder(TreeNode* root,TreeNode** head) {
	if(root == NULL) return;
	
	static TreeNode* prev = NULL;
	
	convertPreOrder(root->left, head);
	
	// save point of double linked list head
	if(prev == NULL) {
		*head = root;
	}
	
	else {
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	convertPreOrder(root->right,head);
}

// 3. postorder traversal


void convertPostOrder(TreeNode* root,TreeNode** head) {
	if(root == NULL) return;
	
	static TreeNode* prev = NULL;
	
	convertPostOrder(root->left, head);
	
	// save point of double linked list head
	if(prev == NULL) {
		*head = root;
		prev = root;
		return;
	}
	
	
	convertPostOrder(root->right, head);
	
	
	root->left = prev;
	prev->right = root;
	
	prev = root;
	return;
}

void printList(TreeNode* head) {
	while(head != NULL) {
		cout<<(head->data)<<" ";
		head = head->right;
	}
}

int main() {
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(12);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(25);
	root->left->right = new TreeNode(30);
	root->right->left = new TreeNode(36);
	
	TreeNode *head = NULL;
	convertInorder(root,&head);
	printList(head);
}
