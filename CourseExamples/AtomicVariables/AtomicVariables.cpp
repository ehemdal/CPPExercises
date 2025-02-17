// AtomicVariables.cpp : Using an atomic variable to avoid races among threads
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;
/*
	Example of an atomic variable.  Because accum is atomic, the compiler protects
	against races among the threads.  You might get thread 1 finishing after thread 2,
	but	the final result will be correct.  Run this program a few times in a row.
*/
// notice the Modern C++ declaration and initialization
atomic<int> accum(0);

void square(int i, int x) {
	cout << "Before start of thread " << i << ", accum = " << accum << endl;
	accum += x * x;
	cout << "Inside thread " << i << ", accum = " << accum << endl;
	// small delay to make execution easier to observe
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
	cout << "In main, before starting threads, accum = " << accum << endl;
	thread th1(&square, 1, 100);
	thread th2(&square, 2, 200);
	cout << "In main, after starting threads, accum = " << accum << endl;
	th1.join();
	th2.join();
	cout << "In main, before exit, accum = " << accum << endl;
	return 0;
}
