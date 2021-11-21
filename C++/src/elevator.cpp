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
		int currentFloor;
		Queue floorQueue;
	public:
		Elevator() {
			currentFloor = 1;
		}
		
		/* When the elevator is moving to the destination floor we want */
		/* The elevator moves past each floor, we want to see this */
		void moveToFloor(int floor) {
			while(currentFloor != floor && floor != -1) {
				system("clear");
				display();
				sleep(1);
				if(currentFloor < floor) currentFloor++;
				else currentFloor--;
			}
		}

		/* When we press a floor button we add the floor to the queue */
		void pressButton(int floor) {
			floorQueue.enqueue(floor);
		}
		
		/* Get the current floor we are on */
		int getCurrentFloor() {
			return currentFloor;
		}
		
		/* Display information about our elevator */
		void display() {
			std::cout << "Current floor: " << getCurrentFloor() << std::endl;
			std::cout << "Internal elevator queue: ";
			floorQueue.print();
			std::cout << std::endl;
		}
};

int main() {
	Elevator elevator;
	int input = 1;
	while(true) {
		std::cin >> input;
		if(input == 0) break;
		if(input < 13 && input > 0) {
			elevator.pressButton(input);
			std::thread thread(&Elevator::moveToFloor, Elevator());	
		}
		input = -1;
	}
	return 0;
}

