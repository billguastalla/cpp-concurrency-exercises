#pragma once
#include "Listing2.1.h"
#include <iostream>

/* Listing 2.1 - A function that returns while a thread still has access to local variables.. */
namespace Listing2_1
{
	void do_something(int & i)
	{
		std::cout << "Doing something with i, whose value is: " << i << std::endl;
	}
	struct func
	{
		int & i;
		func(int &i_) : i{ i_ } {}
		void operator() ()
		{
			for (unsigned j = 0; j < 1000000; ++j)
				do_something(i);
		}
	};
	void oops()
	{
		int some_local_state{ 0 };
		func my_func{ some_local_state };
		std::thread my_thread{ my_func };
		my_thread.detach();
	}
}