#include "Listings.h"
#include <iostream>

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

	}
}