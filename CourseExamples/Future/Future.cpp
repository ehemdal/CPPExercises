// Future.cpp: using task support in class std::future
// See also:https://www.geeksforgeeks.org/std-future-in-cpp/
//			https://stackoverflow.com/questions/70509208/stdfuture-in-simple-words
// This calls a task which deliberately waits to demonstrate that the
// calling program is going to wait for the task to finish

#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int square(int x) {
	cout << "Task is running. . ." << endl;
	this_thread::sleep_for(chrono::seconds(5));
	return x * x;
}

int main() {
	cout << "Starting an asynchronous task." << endl;
	auto a = async(&square, 10);
	cout << "Calling get() on the task to wait for results." << endl;
	int v = a.get();

	cout << "After task comes back, result is " << v << endl;
	return 0;
}