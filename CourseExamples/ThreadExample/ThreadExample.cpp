// ThreadExample.cpp: (Ugly) Example of threading and std::this_thread::sleep_for()
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

static void func(int th, int x) {
	cout << "Inside thread " << th << " x is " << x << endl;
	cout << "Thread " << th << " is waiting for 5 seconds" << endl;
	this_thread::sleep_for(chrono::seconds(5));
}

int main() {
	cout << "Main function is starting a thread" << endl;
	thread th1(&func, 1, 100);
	thread th2(&func, 2, 200);
	thread th3(&func, 3, 300);
	cout << "Main function is waiting to rejoin the threads" << endl;
	th1.join();
	th2.join();
	th3.join();
	cout << "Outside thread" << endl;
	return 0;
}
