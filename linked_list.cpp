//linked-list program to insert a new node, delete a node, reverse the linked-list
#include <iostream>
using namespace std;
class Node{
	public:
		int info;
		Node *next;
	};
void push(Node **h, int data){
	Node *n = new Node();
	n->info = data;
	n->next = *h;
	*h = n;
}
void insertAfter(Node *pn, int data){
	if(pn==NULL){
		cout<<"Previous node can't be null!";
		return;
	}
	Node *n = new Node();
	n->info = data;
	n->next = pn->next;
	pn->next = n;
}
void append(Node **h, int data){
	Node *temp = *h; 
	Node *n = new Node();
	n->info = data;
	n->next = NULL;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = n;
}
void del(Node **h,int d){
	Node *prev = NULL,*temp = *h;
	if(temp!=NULL && temp->info==d){
		*h = temp->next;
		delete temp;
		return;
	}
	while(temp->info!=d && temp!=NULL){
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL){
		cout<<"Value not found!";
		return;
	}
	prev->next = temp->next;
	delete temp;
}
void delIndex(Node **h, int d){
	Node *prev=NULL,*temp=*h;
	for(int i=0; i<d; i++){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	delete temp;
}
Node * reverse(Node *h){
	Node *nxt, *prev = NULL, *curr = h;
	if(h==NULL){
		cout<<"Linked-list is empty."<<endl;
		return h;
	}
	while(curr!=NULL){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	h = prev;
	return h;
}
void printList(Node *n){
	cout<<"Created linked-list is: ";
	if(n==NULL){
		cout<<"Empty!";
		return;
	}
	while(n!=NULL){
		cout<<n->info<<" ";
		n = n->next;
	}
	cout<<endl;
}
int main(){
	Node *head = NULL;
	cout<<"Enter '1' to start and also after every operation to continue."<<endl;
	int c;
	while(cin>>c){
		cout<<"Enter your choice: "<<endl;
		cout<<"1. Insert a node at front."<<endl;
		cout<<"2. Insert a node after a previous node."<<endl;
		cout<<"3. Insert a node before a node."<<endl;
		cout<<"4. Insert a node at end."<<endl;
		cout<<"5. Delete a node."<<endl;
		cout<<"6. Delete a node by using its index."<<endl;
		cout<<"7. Reverse the linked-list."<<endl;
		cout<<"8. End."<<endl;
		int choice, d, i;
		Node *t;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the data: ";
				cin>>d;
				push(&head,d);
				break;
			case 2:
				cout<<"Enter the data: ";
				cin>>d;
				cout<<"Enter the previous node index: ";
				cin>>i;
				for(int j=0; j<i; j++){
					head = head->next;
				}
				insertAfter(head,d);
				break;
			case 3:
				cout<<"Enter the data: ";
				cin>>d;
				cout<<"Enter the next node index: ";
				cin>>i;
				if(i==0){
					push(&head,d);
				}
				else{
					for(int j=0; j<i-1; j++){
					head = head->next;
				}insertAfter(head,d);
				}
				break;
			case 4:
				cout<<"Enter the data: ";
				cin>>d;
				append(&head,d);
				break;
			case 5:
				cout<<"Enter the value to be deleted: ";
				cin>>d;
				del(&head,d);
				break;
			case 6:
				cout<<"Enter the index of which value is to be deleted: ";
				cin>>d;
				delIndex(&head,d);
				break;
			case 7:
				t = reverse(head);
				printList(t);
				break;
			case 8:
				printList(head);
				break;
		}
		cout<<"Enter 1 to continue operations on linked-list or you may press any character other than integer to stop the execution.";
	}
}
