/*#include <iostream>
#include <thread>
#include<vector>
void TestThread(int id, int runTime) {
	for (int i = 0; i < 10; i++) {
		std::cout << id << "| run: " << i << "\n";
	}
}

int main() {
	const int count = 60;
	const int runTime = 14000;

	std::vector<std::thread> threadList;

	for (int i = 0; i < count; ++i) {
		threadList.emplace_back(TestThread, i, runTime);
	}
	
	for (int i = 0; i < count; ++i) {
		threadList[i].detach();
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(14000));
	std::cout << "done";
	
	return 0;
}*/