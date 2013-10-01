#pragma once

#include <mutex>
#include <condition_variable>

namespace sj
{
	class synchronizer
	{
	public:
		synchronizer()
		{
			condition = false;
		}
		void wait()
		{
			condition = false;
			std::unique_lock<std::mutex> lk(m);
			cv.wait(lk, [&]{ return condition; });
		}
		void signal()
		{
			condition = true;
			cv.notify_all();
		}
	private:
		std::mutex m;
		std::condition_variable cv;
		bool condition;
	};

	//template <typename T>
	//class synchronizer_par
	//{
	//public:
	//	synchronizer_par()
	//	{
	//		condition = false;
	//	}
	//	T wait()
	//	{
	//		condition = false;
	//		std::unique_lock<std::mutex> lk(m);
	//		cv.wait(lk, [&]{ return condition; });
	//	}
	//	void signal(const &T)
	//	{
	//		condition = true;
	//		cv.notify_all();
	//	}
	//private:
	//	std::mutex m;
	//	std::condition_variable cv;
	//	bool condition;
	//};
}
