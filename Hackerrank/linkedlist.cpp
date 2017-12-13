#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	node *next,
		 *prev;
};

node* first;

void init()
{
	first = new node;
	first->next= NULL;
	first->prev=NULL;
	first->data=-1;
	
}
void createNewNode(int data){
	if(first->data!=-1){
		node* temp = first;
		while(temp->next)
		{
			temp = temp->next;
		}
		node* newtemp = new node;
		newtemp->data = data;
		newtemp->next = NULL;
		newtemp->prev = NULL;
		temp->next = newtemp;
	}
	else{
		first->data = data;
	}
}

bool checkCycle(){
	map<int, bool> testcase;
	node* temp = first;
	while(true){
		if(testcase[first->data]) return true;
		else testcase[first->data] = true;
		
		if(!temp->next) return false;
		else temp = temp->next;
		
	}
}

void print(){
	node *temp = first;
	while(true){
		cout << temp->data << " ";
		if(temp->next) temp = temp->next;
		else break;
	}
}

int main(){
	init();	
	createNewNode(15);
	createNewNode(40);
	createNewNode(50);
	createNewNode(41);
	
//	node *temp = first;
//	while(true){
//		if(temp->next) temp = temp->next;
//		else break;
//	}
//	temp->next = first->next->next;
	if(checkCycle()){
		cout << "\nNo cycle detected\n";
	}
	else cout << "\nCycle detected\n";
	
}
