#include<bits/stdc++.h>
using namespace std;

struct BstNode{
	int data;
	struct BstNode* right;
	struct BstNode* left;
};

struct BstNode* getNewNode(int n){
	struct BstNode* newBstNode = new BstNode;
	newBstNode->data = n;
	newBstNode->left = NULL;
	newBstNode->right = NULL;
	return newBstNode;
}

struct BstNode* Insert(struct BstNode* root, int n){
	if(root == NULL){
		root = getNewNode(n);
	}
	else if(n <= root->data){
		root->left = Insert(root->left,n); 
	}
	else{
		root->right = Insert(root->right,n);
	}
	return root;
}

void inOrder(struct BstNode* Root){
	if(Root == NULL){
		return;
	}
	inOrder(Root->left);
	cout << Root->data << endl;
	inOrder(Root->right); 
}

struct BstNode* FindMin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct BstNode* Delete(struct BstNode *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			root = NULL;
			delete root;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct BstNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

int main(){
	struct BstNode* rootPtr = NULL;
	cout << "BINARY SEARCH TREE:" << endl;
	int i = -1;
	int elem;
		while(i != 0){
		cout << "ENTER\n1.INSERT\n2.DISPLAY INORDER\n3.DELETE\n0.QUIT PROGRAM" << endl;
		cin >> i;
		switch(i){
			case 1:
				cout << "Enter Element" <<endl;
				cin >> elem;
				rootPtr = Insert(rootPtr,elem);
				break;
			case 2:
				inOrder(rootPtr);
				break;
			case 3:
				cout << "Enter Element" << endl;
				cin >> elem;
				Delete(rootPtr,elem);
		}
		}
	return 0;
}



