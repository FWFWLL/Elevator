#include <cstddef>
#include <iostream>
#include <ios>
#include <limits>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include "queue.hpp"
#include "elevator.hpp"

class Elevator {
	private:
		int iCurrFloor;
		int iDestFloor;
	public:
		Queue floorQueue;
		
		Elevator() {
			iCurrFloor = 1;
			iDestFloor = -1;
		}
		
		/* When the elevator is moving to the destination floor we want */
		/* The elevator moves past each floor, we want to see this */
		void moveToFloor(int floor) {
			iDestFloor = floor;
			while(iCurrFloor != iDestFloor && iDestFloor != -1) {
				sleep(2);
				if(iCurrFloor < iDestFloor) iCurrFloor++;
				else iCurrFloor--;
				display();	
			}
		}

		/* When we press a floor button we add the floor to the queue */
		void pressButton(int floor) {
			floorQueue.enqueue(floor);
		}
		
		/* Display information about our elevator */
		void display() {
			system("clear");
			if(iDestFloor != -1) std::cout << "Moving to floor: " << iDestFloor << std::endl;
			std::cout << "Current floor: " << iCurrFloor << std::endl;
			std::cout << "Internal elevator queue: ";
			floorQueue.print();
			std::cout << std::endl;
		}
		
		/* Thread function */
		void run(int i) {
			while(true) {
				sleep(2);
				moveToFloor(floorQueue.dequeue());
			}
		}
};

int main() {
	Elevator elevator;
	int input;
	std::thread thread(&Elevator::run, &elevator, NULL);	
	while(true) {
		elevator.display();
		std::cin >> input;
		if(input == 0) {
			std::terminate();
			break;
		}
		if(input < 13 && input > 0) {
			elevator.pressButton(input);
		}
	}
	return 0;
}

