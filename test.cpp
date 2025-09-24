/*#include <iostream>
#include <thread>
#include<vector>
void TestThread(int id, int runTime) {
	for (int i = 0; i < 10; i++) {
		std::cout << id << "| run: " << i << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(runTime/10));
	}
}

int main() {
	const int count = 10;
	const int runTime = 14000;

	std::vector<std::thread> threadList;

	for (int i = 0; i < count; ++i) {
		threadList.emplace_back(TestThread, i, runTime);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	
	for (int i = 0; i < count; ++i) {
		threadList[i].join();
	}
	
	std::cout << "done";

	return 0;
}*/