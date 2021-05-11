#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int accum = 0;
mutex accum_mutex;

void square(int x) {
	int temp = x * x;
	accum_mutex.lock();
	accum += temp;
	accum_mutex.unlock();
}

int main() {
	thread th(&square, 100);
	th.join();
	cout << "Outside thread" << endl;
	return 0;
}