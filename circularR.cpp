//m.rizki alfarabi
#include <iostream>
using namespace std;

struct node{
	char data;
	node *prev;
	node *next;
};

node *head, *tail, *cur, *newNode, *del, *afterNode;

void createCircular(char data){
	head = new node();
	head->data = data;
	head->prev = head;
	head->next = head;
	tail = head;
}

void addFirst(char data){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
		newNode = new node();
	    newNode->data = data;
	    newNode->prev = tail;
	    newNode->next = head;
	    head->prev = newNode;
	    tail->next = newNode;
		head = newNode;
  }
}

void addLast(char data){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
	}else{
	    newNode = new node();
	    newNode->data = data;
	    newNode->prev = tail;
	    newNode->next = head;
	    tail->next = newNode;
	    head->prev = newNode;
	    tail = newNode;
	}
}

void addMiddle( char data, int posisi ){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{

    if (posisi == 1){
      cout << "Posisi bukan posisi tengah!" << endl;
    }else if (posisi < 1){
      cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	newNode = new node();
    	newNode->data = data;

    	cur = head;
    	int nomor = 1;
    	while( nomor <  posisi - 1){
    		cur = cur->next;
        	nomor++;
      	}

    	afterNode = cur->next;
    	newNode->prev = cur;
    	newNode->next = afterNode;
    	cur->next = newNode;
    	afterNode->prev = newNode;
    }
  }
}

void removeFirst(){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
		del = head;
    	head = head->next;
    	tail->next = head;
    	head->prev = tail;
    	delete del;
	}
}

void removeLast(){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
	}else{
    	del = tail;
    	tail = tail->prev;
    	tail->next = head;
    	head->prev = tail;
    	delete del;
	}
}

void removeMiddle(int posisi){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
  }else{
    if (posisi == 1){
    	cout << "Posisi bukan posisi tegah!" << endl;
    }else if (posisi < 1){
    	cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	//tranversing
    	int nomor = 1;
    	cur = head;
		while(nomor < posisi - 1){
        	cur = cur->next;
        	nomor++;
    	}
    	del = cur->next;
    	afterNode = del->next;
    	cur->next = afterNode;
    	afterNode->prev = cur;
    	delete del;
    }
  }
}

void printCircular()
{
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
    	cout << "INFO DATA" << endl;
    	cur = head;
    	while (cur->next != head){
    		// print
    		cout << "Data : " << cur->data << endl;
    		//step
    		cur = cur->next;
    	}
    //print Last Node
    cout << "Data : " << cur->data << endl;
  }
}

void searchNode(node **head, int id){
    int currentID = 1;
    node *cur = *head;
    while (cur->next != 0 && currentID != id){
        cur = cur->next;
        currentID++;
    }
    cout << cur->data << " ditemukan pada data ke " << currentID;
}

int main(){

  int newData = 'b';
  createCircular(newData);

  printCircular();

  int data2 = 'a';
  addFirst(data2);

  printCircular();

  int data3 = 'c';
  addLast(data3);

  printCircular();

  int data4 = 'j';
  addMiddle(data4, 'c');

  printCircular();

  removeMiddle('b');

  printCircular();
  
  searchNode(&head, 'b');
}
