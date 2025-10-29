#include "ThreadPool.h"

ThreadPool::ThreadPool(int _workerCount)
{
	workerCount = _workerCount;

	for (int i = 0; i < workerCount; i++) {
		this->InactiveThreads.push(new WorkerThread(i, this));
	}
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::StartScheduling()
{
	this->isRunning = true;
	this->start();
}

void ThreadPool::StopScheduling()
{
	this->isRunning = false;
}

void ThreadPool::ScheduleTask(IWorkerAction* _task)
{
	this->PendingTasks.push(_task);
}

void ThreadPool::run()
{
	while (this->isRunning) {
		//if pending task
		if (!this->PendingTasks.empty()) {
			//if there is available thread
			if (!this->InactiveThreads.empty()) {
				auto workerThread = this->InactiveThreads.front();
				this->InactiveThreads.pop();

				this->ActiveThreads[workerThread->getID()] = workerThread;

				auto task = this->PendingTasks.front();
				this->PendingTasks.pop();
				workerThread->AssignTask(task);

				workerThread->start();
			}
		}
	}
}

void ThreadPool::OnFinishedTask(int id)
{
	if (this->ActiveThreads[id] != nullptr) {
		delete this->ActiveThreads[id];
		this->ActiveThreads.erase(id);

		InactiveThreads.push(new WorkerThread(id, this));
	}
}
