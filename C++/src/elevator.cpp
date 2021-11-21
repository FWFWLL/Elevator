#include <cstddef>
#include <iostream>
#include "queue.h"

int main() {
	Queue q;
	q.enqueue(20);
	q.enqueue(5);
	q.enqueue(7);
	q.enqueue(9);
	std::cout << "Queue front: " << q.dequeue() << std::endl;
	std::cout << "Queue front after dequeue: " << (q.front) -> data << std::endl;
	std::cout << "Queue rear: " << (q.rear) -> data << std::endl;
	return 0;
}
