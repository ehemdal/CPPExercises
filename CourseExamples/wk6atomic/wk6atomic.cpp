#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;
/*
	Example of an atomic variable.  Because accum is atomic, the compiler protects
	against races among the threads.  You might get thread 1 finishing after thread 2, but
	the final result will be correct.  Run this program a few times in succession.
*/

atomic<int> accum(0);

void square(int x) {
	accum += x * x;
	cout << "Inside thread, accum = " << accum << endl;
	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main() {
	cout << "In main, before threads, accum = " << accum << endl;
	thread th1(&square, 100);
	thread th2(&square, 200);
	cout << "In main, after threads, accum = " << accum << endl;

	th1.join();
	th2.join();
	cout << "In main, before exit, accum = " << accum << endl;
	return 0;
}
