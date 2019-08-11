#include<bits/stdc++.h>
using namespace std;

//Declaring a Linked List
struct Node{
	int data;
	struct Node* next;
};

//Creating a Head Pointer
struct Node* head = NULL;

//Inserting a Node at the Start
void insertAtStart(int n){
	struct Node* newNode = new Node;
	newNode->data = n;
	newNode->next = head;
	head = newNode;
}

//Inserting a Node at the End
void insertAtEnd(int n){
	struct Node* newNode = new Node;
	struct Node* temp = head;
	if(head == NULL){
		head = newNode;
		newNode->data = n;
		newNode->next = NULL;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->data = n;
		newNode->next = NULL;
	}
	delete temp;
}

//Displaying All Items in the Linked List
void display(){
	struct Node* temp = head;
	if(head == NULL){
		cout << "List is empty." << endl;
	}
	else{
		while(temp != NULL){
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
	delete temp;
}

//Deleting the First Element
void deleteFirst(){
	struct Node* temp = head;
	if(head == NULL){
		cout << "List is empty." << endl;
	}
	else{
	head = head->next;
	}
	delete temp;
}
//Deleting the Last Element
void deleteLast(){
	if(head == NULL){
		cout << "List is empty." << endl;
	}
	else if(head->next == NULL){
		delete head;
	}
	else{
		struct Node* second_last = head; 
    	while (second_last->next->next != NULL) 
        	second_last = second_last->next;  
    	delete (second_last->next); 
    	second_last->next = NULL; 
    }
}

int main(){
	int i = -1;
	int elem;
	cout << "LINKED LIST:" << endl;
	while(i != 0){
		cout << "ENTER\n1.INSERT AT THE START\n2.INSERT AT THE BACK\n3.DISPLAY ALL ELEMENTS\n4.DELETE FIRST ELEMENT\n5.DELETE LAST ELEMENT\n0.QUIT PROGRAM" << endl;
		cin >> i;
		switch(i){
			case 1:
				cout << "Enter Element" <<endl;
				cin >> elem;
				insertAtStart(elem);
				break;
			case 2:
				cout << "Enter Element" <<endl;
				cin >> elem;
				insertAtEnd(elem);
				break;
			case 3:
				display();
				break;
			case 4:
				deleteFirst();
				break;
			case 5:
				deleteLast();
				break;
		}
	}
	return 0;
}
