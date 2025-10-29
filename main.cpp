#include <iostream>
#include "BaseRunner.h"
#include "IExecutionEvent.h"
#include "IETThread.h"
#include <semaphore>
/*
int main() {
	BaseRunner runner;
	runner.run();
}*/

float dat = 0.f;
int turn = 0;
bool p_flag[2] = { false,false };

std::counting_semaphore<1> skibidi(1);
std::counting_semaphore<1> skibidi2(0);
std::counting_semaphore<1> skibidi3(0);

class ThreadA : public IETThread {
private:
	void run() override {
		while (true) {
			skibidi.acquire();

			IETThread::sleep(500);
			dat = dat + 100;
			std::cout << dat << std::endl;
			skibidi2.release();
		}
	}
};

class ThreadB : public IETThread {
private:
	void run() override {
		while (true) {
			skibidi2.acquire();

			IETThread::sleep(500);
			dat = dat - 100;
			std::cout << dat << std::endl;
			skibidi3.release();
		}
	}
};

class ThreadB : public IETThread {
private:
	void run() override {
		while (true) {
			skibidi3.acquire();

			IETThread::sleep(500);
			std::cout << "peanits" << std::endl;
			skibidi.release();
		}
	}
};

// max then initial
std::counting_semaphore<5> my_semaphore(1);

class SemaphoreThread1 : public IETThread {
private:
	void run() override {
		std::cout << "1: Trying to acquire Semaphore\n";
		my_semaphore.acquire();
		std::cout << "1: Crit sec\n";
		IETThread::sleep(4000);
		my_semaphore.release();
		std::cout << "1: Released\n";
	}
};

class SemaphoreThread2 : public IETThread {
private:
	void run() override {
		IETThread::sleep(100);
		std::cout << "2: Trying to acquire Semaphore\n";
		my_semaphore.acquire();
		std::cout << "2: Crit sec\n";
		my_semaphore.release();
		std::cout << "2: Released\n";
	}
};

int main() {
	ThreadA a;
	ThreadB b;

	a.start();
	b.start();

	IETThread::sleep(10000);

	return 0;
}