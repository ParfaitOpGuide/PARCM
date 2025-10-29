#include <iostream>
#include "BaseRunner.h"
#include "IExecutionEvent.h"
#include "IETThread.h"
#include <semaphore>

int main() {
	BaseRunner runner;
	runner.run();
}