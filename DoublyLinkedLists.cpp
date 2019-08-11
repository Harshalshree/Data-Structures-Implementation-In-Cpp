#include<bits/stdc++.h>
using namespace std;

//Declaring a Double Linked List
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

//Creating a Head Pointer
struct Node* head = NULL;

//Creating a Tail Pointer
struct Node* tail = NULL;

//Inserting a Node at the Start
void insertAtStart(int n){
	struct Node* newNode = new Node;
	struct Node* temp = head;
	if(head == NULL){
		newNode->prev = NULL;
		newNode->next = head;
		newNode->data = n;
		head = newNode;
	}
	else{
		temp->prev = newNode;
		newNode->prev = NULL;
		newNode->next = head;
		newNode->data = n;
		head = newNode;
	}
}

void displayRev(){
	struct Node* temp;
	struct Node* temp1 = head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp = temp1;
	if(temp == NULL){
		cout <<"LIST EMPTY" << endl;
	}
	else{
		while(temp != NULL){
			cout << temp->data << "->"; 
			temp = temp->prev;
		}
		cout << "NULL" << endl;
	}
}

void displayNormal(){
	struct Node* temp1 = head;
	if(temp1 == NULL){
		cout <<"LIST EMPTY" << endl;
	}
	else{
		while(temp1 != NULL){
			cout << temp1->data << "->"; 
			temp1 = temp1->next;
		}
		cout << "NULL" << endl;
	}
}



int main(){
	int i = -1;
	int elem;
	cout << "LINKED LIST:" << endl;
	while(i != 0){
		cout << "ENTER\n1.INSERT AT THE START\n2.DISPLAY ELEMENTS IN REVERSE ORDER\n3.DISPLAY IN NORMAL ORDER"<< endl;
		cin >> i;
		switch(i){
			case 1:
				cout << "Enter Element" <<endl;
				cin >> elem;
				insertAtStart(elem);
				break;
			case 2:
				displayRev();
				break;
			case 3:
				displayNormal();
				break;
		}
	}
	return 0;
}
