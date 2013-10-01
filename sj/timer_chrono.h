#pragma once

#include <chrono>


namespace sj
{

class timer_chrono
{
	typedef std::chrono::steady_clock myclock;
	typedef std::chrono::duration<myclock::rep, 
		myclock::period> mydur;
	typedef std::chrono::nanoseconds nanoseconds;
	typedef std::chrono::microseconds microseconds;
	typedef std::chrono::milliseconds milliseconds;
	typedef std::chrono::seconds seconds;

public:
	timer_chrono()
	{ 
		this->s_time = myclock::time_point::min();
		this->accumulated = std::chrono::seconds(0);
	}
	void start()
	{
		this->s_time = myclock::now();
	}
	void stop()
	{
		auto now = myclock::now();

		if (!running())
			return;

		this->accumulated += now - this->s_time;
		this->s_time = myclock::time_point::min();
	}
	void restart()
	{
		this->s_time = myclock::now();
		this->accumulated = std::chrono::seconds(0);
	}
	bool running()
	{
		return this->s_time != myclock::time_point::min();
	}
	mydur elapsed()
	{
		auto now = myclock::now();

		if (!running())
			return this->accumulated;

		return this->accumulated + now - this->s_time;
	}
	int64_t elapsed_ns()
	{
		return std::chrono::duration_cast<nanoseconds>(elapsed()).count();
	}
	int64_t elapsed_us()
	{
		return std::chrono::duration_cast<microseconds>(elapsed()).count();
	}
	int64_t elapsed_ms()
	{
		return std::chrono::duration_cast<milliseconds>(elapsed()).count();
	}
	int64_t elapsed_s()
	{
		return std::chrono::duration_cast<seconds>(elapsed()).count();
	}
private:
	myclock::time_point s_time;
	mydur accumulated;
};


} // namespace sj
