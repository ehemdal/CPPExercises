/*
	Simple coroutine example, adapted from https://github.com/chaelim/Coroutine/blob/master/Examples/simple.cpp
*/
#include <coroutine>
#include <cstdio>

struct simple
{
	// The required promise object
	struct promise_type
	{
		// The new and delete operators are overloaded so we can make them visible with printf()
		static void* operator new(std::size_t s)
		{
			printf("\nnew operator size=%zd\n", s);
			return ::operator new(s);
		}

		static void operator delete(void* ptr, std::size_t s)
		{
			printf("\ndelete operator size=%zd\n", s);
			delete(ptr);
		}
		// data to be returned via return_value()
		int value = 0;

		// These member functions must be defined for a coroutine. Try commenting them out.
		simple get_return_object() noexcept { return simple(std::coroutine_handle<promise_type>::from_promise(*this)); }
		std::suspend_never initial_suspend() noexcept { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		void unhandled_exception() noexcept {}
		void return_value(int v) noexcept { value = v; }
		// If the coroutine doesn't return a value, define return_void() instead
	};

	simple(std::coroutine_handle<promise_type> coro) noexcept : m_coro(coro) {}
	simple(simple&& other) noexcept : m_coro(other.m_coro) { other.m_coro = nullptr; }
	~simple()
	{
		if (m_coro)
			m_coro.destroy();
	}

	int value() const noexcept { return m_coro.promise().value; }

	std::coroutine_handle<promise_type> m_coro;
};

simple Simple() noexcept
{
	printf("Coroutine is running\n");
	co_return 42;
}

int main()
{
	printf("Main function is starting\n");
	auto t = Simple();
	printf("Return value=%d\n", t.value());
}