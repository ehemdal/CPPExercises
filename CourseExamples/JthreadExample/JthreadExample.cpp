// JthreadExample.cpp : Joinable threads (and mutex to keep things organized)
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
mutex thread_lock;

static void func(int th, int x) {
	thread_lock.lock();
	cout << "Inside jthread " << th << " x is " << x << endl;
	cout << "Jthread " << th << " is waiting for 5 seconds" << endl;
	this_thread::sleep_for(chrono::seconds(5));
	thread_lock.unlock();
}

int main() {
	cout << "Main function is starting a thread" << endl;
	jthread th1(&func, 1, 100);
	jthread th2(&func, 2, 200);
	jthread th3(&func, 3, 300);
	cout << "Main function is waiting to rejoin the threads" << endl;
	cout << "Outside threads" << endl;
	// Jthreads are joined when they terminate, you can also call join() anyway.
	th3.join();
	return 0;
}
