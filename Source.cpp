#include <iostream>
#include "Que.h"

int main()
{
	bool flag = false;
	short int num{};
	que mainQue;

	//SEND MESSAGE TO QUE || PARAMETERS (enum message, int weight) ||
	mainQue.sendMessage(mainQue.START, 20);
	mainQue.sendMessage(mainQue.TEST, 5);
	mainQue.sendMessage(mainQue.START, 1);
	mainQue.sendMessage(mainQue.START, 7);
	mainQue.sendMessage(mainQue.TEST, 9);

	while (true)
	{
		flag = false;

		//OVERLOAD FUNCTION || PASS MESSAGE INTO SWITCH
		mainQue.sendMessage(mainQue.fetchPost());

		//TESTING CODE, SLOWS PROGRAM TO SHOW QUEING PROCESS
		while (flag == false)
		{
			while (std::cout << "|please enter 1 to continue process|\n" && !(std::cin >> num))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "|Incorrect data input|\n";
			}
			if (num == 1)
			{
				flag = true;
			}
		}
	}

}