#include <iostream>
#include <thread>

/* 2.1.1 */
void do_something(int i = 0) { std::cout << "Doing something\n"; std::cout << "\ti : " << i << std::endl; };
void do_something_else() { std::cout << "Doing something else\n"; };
class background_task
{
public:
	void operator() () const
	{
		do_something();
		do_something_else();
	}
};

/* Listing 2.1 */

struct func
{
	int & i;
	func(int& i_) :i{ i_ } {}

	void operator() ()
	{
		for (unsigned j = 0; j < 1000000; ++j)
		{
			do_something(i);
		}
	}
};
void oops()
{
	int some_local_state = 0;
	func my_func{ some_local_state };
	std::thread my_thread{ my_func };
	my_thread.detach();
}

int main()
{

	background_task f;
	std::thread my_thread{ f };
	std::thread my_other_thread{ background_task{} };
	std::thread my_lambda_thread{ []() {do_something(); do_something_else();} };
	my_thread.join();
	my_other_thread.join();
	my_lambda_thread.join();

	oops();

}


