#include "My_List.h"
#include <Windows.h>

void task(DLIST& DL, std::string searchname,int targetyear)
{
	ptrNODE ptr = DL.get_begin();
	bool stop = true;
	std::cout << "\n\nSearch results : \n\n";
	std::cout << "~~~~~~~~~~~~~~~~~~\n";
	while (stop && ptr) {
		if ((ptr->info.getyear() > targetyear || ptr->info.getyear() == targetyear) && ptr->info.search(searchname, ptr->info.getname())) {
			ptr->info.print();
		}
		else { stop = false; }
		ptr = ptr->next;
	}
}

int main()
{
	setlocale(0, "");
	std::ifstream file("xdd.txt");
	if (file)
	{
		DLIST DL("xdd.txt");
		DL.print();
		std::string searchname;
		int targetyear;
		std::cout << "\n\nEnter name of the book: ";
		std::cin >> searchname;
		std::cout << "Enter the year of publishing: ";
		std::cin >> targetyear;
		task(DL, searchname, targetyear);
	}
	else { std::cout << "Input file not found" << std::endl; }
	std::cin.get();
}
