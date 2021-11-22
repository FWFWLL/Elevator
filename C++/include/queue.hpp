#ifndef QUEUE_HPP
#define QUEUE_HPP

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

	/* Initialize front and rear as NULL */
	Queue() {
		front = rear = NULL;
		size = 0;
	}
	
	/* Check if Queue contains given parameter, O(n) */
	bool contains(int data) {
		Node* temp = front;
		while(temp != NULL) if(temp -> data == data) return true;
		return false;
	}

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
		if(front == NULL) return -1;
		Node* temp = front;
		int data = temp -> data;
		front = front -> next;
		/* If front becomes NULL, make rear also NULL */
		if(front == NULL) rear = NULL;
		delete(temp);
		--size;
		return data;
	}
	
	/* Prints the queue, O(n)*/
	void print() {
		Node* temp = front;
		std::cout << "[";
		while(temp != NULL) {
			std::cout << temp -> data;
			if(temp != rear) std::cout << " <- ";
			temp = temp -> next;
		}
		std::cout << "]";
	}
} Queue;

#endif
