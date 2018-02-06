#pragma once
#include "Listing2.2.h"

/* Listing 2.2 - Waiting for a thread to finish. */
namespace Listing2_2
{
	void do_something_in_current_thread() {
	}
	struct func
	{
		int i;
		func(int i_) : i{i_}{ }
		void operator() () {

		}
	};
	void exceptionSafeFunc()
	{
		int some_local_state{ 0 };
		func my_func{ some_local_state };
		std::thread t{ my_func };
		try
		{
			do_something_in_current_thread();
		}
		catch (std::exception ex)
		{
			t.join();
			throw;
		}
		t.join();
	}
}