// Future.cpp: using concurrency support in class std::future
// See also:https://www.geeksforgeeks.org/std-future-in-cpp/
//			https://stackoverflow.com/questions/70509208/stdfuture-in-simple-words
#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int square(int x) {
	return x * x;
}

int main() {
	auto a = async(&square, 10);
	int v = a.get();

	cout << "After task " << v << endl;
	return 0;
}