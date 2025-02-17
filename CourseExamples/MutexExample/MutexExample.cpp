// MutexExample.cpp 
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/*
	Example of using a mutex to synchronize threads, adapted from
	https://www.geeksforgeeks.org/std-mutex-in-cpp/
	Run this several times and compare the lock and nolock results.
*/

int accum_nolock = 0;
int accum_lock = 0;
mutex accum_mutex;

static void count_nolock() {
	for (int i = 0; i < 1000000; i++)
	{
		accum_nolock++;
	}
}
static void count_lock() {
	accum_mutex.lock();
	for (int i = 0; i < 1000000; i++)
	{
		accum_lock++;
	}
	accum_mutex.unlock();
}

int main() {
	thread th1(&count_nolock);
	thread th2(&count_nolock);
	thread th3(&count_lock);
	thread th4(&count_lock);

	th1.join();
	th2.join();
	th3.join();
	th4.join();
	cout << "In main, accum_nolock = " << accum_nolock << endl;
	cout << "in main, accum_lock = " << accum_lock << endl;

	return 0;
}