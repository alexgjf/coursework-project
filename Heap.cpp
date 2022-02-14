#include "Heap.h"
#include <iostream>

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob* job1) {
    if (numItems < MAX_HEAP_SIZE) {
    	arr[numItems] = job1;
    	int temp = numItems;
        while (temp >= 1 && arr[(temp - 2) / 2]->getPriority() < arr[temp]->getPriority()) {
            swap(arr[temp], arr[(temp - 1) / 2]);
            temp = (temp - 1) / 2;
        }
        numItems++;
    }
}

void Heap::dequeue() {
    if(numItems == 1) {
		arr[0] = 0;
		numItems--;
		return;
	}
	if(numItems > 1) {
		arr[0] = arr[numItems-1];
		arr[numItems-1] = 0;
		numItems--;
		trickleDown(0);
	}
}

PrintJob* Heap::highest() {
    if(numItems==0)
    {
    	return 0;
	}
	return arr[0];
}

void Heap::print() {
    cout << "Priority: " << arr[0]->getPriority() << ", Job Number: " << arr[0]->getJobNumber() << ", Number of Pages: " << arr[0]->getPages() << endl;
}

void Heap::trickleDown(int num) {
    for(int i = 0; i < numItems; i++) {
		if(arr[num]->getPriority() < arr[i]->getPriority())
        {
            PrintJob* temp = arr[num];
            arr[num] = arr[i];
            arr[i] = temp;
        }
	}
}
