#pragma once
#include <iostream>

class IExecutionEvent
{
public:
	virtual void OnFinishedExecution() = 0;
};

class ThreadHandler : public IExecutionEvent {
public:
	bool threadDone = false;

	void OnFinishedExecution() override {
		std::cout << "Thread is done" << std::endl;
		threadDone = true;
	}
};