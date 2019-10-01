#include "vector.h"

int main(void)
{
	container::vector < int > vector;
	while (vector.empty())
	{
		vector.push_back(rand() % 1500);
		std::cout << vector.pop_back() << std::endl;
	}
	return 0;
}
