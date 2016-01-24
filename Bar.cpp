/****************************************************************************************
 **Program Filename: Bar.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Bar class is a subclass of room where you can get friends and drink
 **Input: strings, and integers
 **Output: Prints messages and returns integers to adjust fun level
****************************************************************************************/
#include "Bar.hpp"
#include "Room.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;


/****************************************************************************************
**Function: mingle 
**Description: This method displays all people in the vector
**Parameters: none
**Pre-Conditions: object initialized
**Post-Conditions: all people strings are displayed
****************************************************************************************/
void Bar::mingle()
{  cout << "~~~People in Bar~~~" << endl;
   for(int i = 0; i < people.size(); i++)
   {  cout << (i + 1) << " " << people.at(i) << endl;
   }
   cout << endl;
}


/****************************************************************************************
**Function: makeFriends
**Description: This method returns a person string corresponding to an int
**Parameters: int
**Pre-Conditions: correct int is passes
**Post-Conditions: correct person is returned
****************************************************************************************/
string Bar::makeFriends(int i)
{  if((0 <= (i - 1)) && ((i - 1) <= people.size()))
   {  return people.at(i - 1);
   }
   else
   {  cout << "ERROR: Invalid Person Number" << endl;
      return "ERROR";
   }
}


/****************************************************************************************
**Function: showDrinks
**Description: This method displays all drinks options
**Parameters: none
**Pre-Conditions: object initialized
**Post-Conditions: all drinks strings are displayed
****************************************************************************************/
void Bar::showDrinks()
{  cout << "~~~Drink Menu~~~" << endl;
   cout << "1) Budweiser" << endl;
   cout << "2) Tequila" << endl;
   cout << "3) Milkshake" << endl;
   cout << "4) Lemonade" << endl;
   cout << "5) Whiskey" << endl;
   cout << "6) Red Wine" << endl;
}


/****************************************************************************************
**Function: getDrink 
**Description: returns an integer corresponding to a drink, and if drink isn't available
**subtracts returns negative
**Parameters: integer for drink
**Pre-Conditions: integer is passed
**Post-Conditions: correct number returned
****************************************************************************************/
int Bar::getDrink(int num)
{  if((0 < num) && (num < 7))
   {  return num;
   }
   else
   {  cout << "ERROR: Invalid Drink\n";
      cout << "Bartendar shames you\n" << endl;
      return (-5);
   }
}      
