#include <iostream>
#include "Function.h"

//Note du d�veloppeur : l'utilisation des parenth�ses ne marche pas encore, ce sera peut �tre rajout� par la suite

int main()
{
	std::vector<std::string> strText{};
	std::string text;
	bool isGood;

	do 
	{
		isGood = true;
		std::getline(std::cin, text);

		removeSpaces(text);

		if (verifyChar(text))
		{
			strSplit(text, strText);

			if (verifyOrder(strText))
			{
				std::cout << calc(strText) << std::endl;
			}
			else
			{
				isGood = false;
				warningMessage();
			}
		}
		else
		{
			isGood = false;
			warningMessage();
		}

		[text, strText]() mutable -> void
		{
			text.clear();
			strText.clear();
		};

	} while (!isGood);

	std::cin.ignore();

	return 0;
}