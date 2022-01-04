#ifndef SEMER_H_
#define SEMER_H_
#include "tools.h"
#if _WIN32 != 1 || _MSC_VER >= 1600
	#include <mutex>
	#include <atomic> 
	#include <condition_variable>

	#define SBind std::bind
	#define SAtomic    std::atomic
	#define SLockGuard std::lock_guard
	#define SUniqueLock std::unique_lock
	#define SMutex std::mutex
	#define SConditionVariable std::condition_variable
#else
	#include "boost/thread/mutex.hpp"
	#include "boost/thread/lock_guard.hpp"
	#include "boost/thread/condition_variable.hpp"

	#define SLockGuard boost::lock_guard
	#define SUniqueLock boost::unique_lock
	#define SMutex boost::mutex
	#define SConditionVariable boost::condition_variable
#endif
	//C++11 版本信号量实现
	class MySemer {
	public:
		MySemer(int32 value = 0) :count(value),wakeups(0){}
		inline int wait() {
			SUniqueLock<SMutex> lock(mutex);
			if (--count < 0) // count is not enough
			{
				condition.wait(lock, [&]()->bool {return wakeups > 0;}); // suspend and wait...
				--wakeups; //ok,me wake up
			}
			return 1;
		}
		inline int post(){
			SLockGuard<SMutex> lock(mutex);
			if (++count <= 0) // have some thread suspended
			{
				++wakeups;
				condition.notify_one(); // notify one !
			}
			return 0;
		}
		inline  int  prewait() {
			return 0;
		}
	private:
		int32 count;   // mutex count
		int32 wakeups; // wake up threads count
		SMutex mutex;
		SConditionVariable condition;
	};
#endif
