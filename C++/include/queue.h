#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
	int data;
	Node* next;
	Node(int data) {
		this -> data = data;
		next = NULL;
	}
} Node;

typedef struct Queue {
	Node *front, *rear;
	int size;

	Queue() {front = rear = NULL;}
	
	/* Insert a new Node to the rear of the Queue, O(1) */
	void enqueue(int data) {
		Node* temp = new Node(data);
		/* If Queue is empty */
		if(rear == NULL) {
			front = rear = temp;
			return;
		}
		rear -> next = temp;
		rear = temp;
		size++;
	}
	
	/* Removes and returns the Node at the front of the Queue, O(1) */
	int dequeue() {
		/* If Queue is empty */
		if(front == NULL) return 0;
		Node* temp = front;
		int data = temp -> data;
		front = front -> next;
		--size;
		/* If front becomes NULL, make rear also NULL */
		if(front == NULL) rear = NULL;
		delete(temp);
		return data;
	}
} Queue;

#endif
