#include <iostream>
using namespace std;


struct Node { 
   int age;
   string name; 
   struct Node *next; 
};
 
struct Node* head = NULL;
 
void insert(int n, string s) { 
   struct Node* newnode = new Node; 
   struct Node *ptr = head;  
   newnode->age = n; 
   newnode->name = s;
   newnode->next = head; 
   if (head!= NULL) { 
      while (ptr->next != head) 
         ptr = ptr->next; 
      ptr->next = newnode; 
   } else
      newnode->next = newnode;   
  head = newnode; 
}  
void display() { 
   struct Node* temp;
   temp = head;
   cout << "Names:" << endl;
   do { 
      cout<<temp->name <<" "; 
      temp = temp->next; 
   } while(temp != head);
   temp = head;
   cout << endl;
   cout << "Ages:" << endl;
   do { 
      cout<<temp->age <<" "; 
      temp = temp->next; 
   } while(temp != head);
}

int main(){
	int i = -1;
	string s;
	int age;
	while(i != 0){
		cout << "ENTER\n1.INSERT AT THE START\n2.DISPLAY ALL ELEMENTS\n0.QUIT PROGRAM" << endl;
		cin >> i;
		switch(i){
			case 1:
				cout << "Enter Name And Age" <<endl;
            cin >> s;
				cin >> age;
				insert(age,s);
				break;
			case 2:
				display();
				break;
		}
	}
	return 0;
}
