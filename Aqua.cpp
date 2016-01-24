/****************************************************************************************
 **Program Filename: Aqua.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Aqua class is a subclass of room where you can get friends and swim
 **Input: strings, and integers
 **Output: Prints messages and returns integers to adjust fun level
 ***************************************************************************************/
#include "Aqua.hpp"
#include "Room.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


/****************************************************************************************
**Function: swim
**Description: This method takes a person strign and returns an int 
**Parameters: string
**Pre-Conditions: string is passed
**Post-Conditions: if string is Katie or Sara the return is pos, but otherwise neg
****************************************************************************************/
int Aqua::swim(string coach)
{  if(coach == "Katie")
   {  cout << "Piranha Attack! Luckily Lifeguard Katie to the rescue!" << endl;
      return 6;
   }
   if(coach == "Sara")
   {  cout << "Sara turns into a Selkie!!! Awesomeness ahoy!!!" << endl;
      return 10;
   }
   else if (coach == "none")
   {  cout << "You try to befriend a mermaid. You get slapped by a mermaid!" << endl;
      return -4;
   }
   else 
   {  cout << "You almost get eaten by a shark!" << endl;
      return -3;
   }
}
/****************************************************************************************
**Function: mingle
**Description: This method displays all people in the vector
**Parameters: none
**Pre-Conditions: object initialized
**Post-Conditions: all people strings are displayed
****************************************************************************************/
void Aqua::mingle()
{  cout << "~~~Creatures in Water~~~" << endl;
   for(int i = 0; i < people.size(); i++)
   {  cout << (i + 1) << " " << people.at(i) << endl;
   }
   cout << endl;
}


/****************************************************************************************
**Function: makeFriends 
**Description: This method returns a people string corresponding to an int
**Parameters: int
**Pre-Conditions: correct int is passed
**Post-Conditions: correct people string is returned
****************************************************************************************/
string Aqua::makeFriends(int i)
{  if((0 <= (i - 1)) && ((i - 1) <= people.size()))
   {  return people.at(i - 1);
   }
   else
   {  cout << "ERROR: Invalid Creature Number" << endl;
      return "ERROR";
   }
}
