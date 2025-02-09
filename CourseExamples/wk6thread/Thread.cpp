// Thread.cpp: Example of threading and std::this_thread::sleep_for()
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

static void func(int x) {
	cout << "Inside thread " << x << endl;
	cout << "Thread is waiting for 5 seconds" << endl;
	// Add a wait to show that the parent process won't finish until the thread
	// returns
	this_thread::sleep_for(chrono::seconds(5));
}

int main() {
	cout << "Main function is starting a thread" << endl;
	thread th(&func, 100);
	cout << "Main function is waiting to rejoin the thread" << endl;
	th.join();
	cout << "Outside thread" << endl;
	return 0;
}
