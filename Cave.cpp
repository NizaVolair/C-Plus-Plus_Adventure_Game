/****************************************************************************************
 **Program Filename: Cave.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Cave class is a subclass of room where you can talk to a troll
 **Input: strings, and integers
 **Output: Prints messages and returns integers to adjust fun level
****************************************************************************************/
#include "Cave.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;


/****************************************************************************************
**Function: swim
**Description: This method takes an object and returns an int 
**Parameters: string
**Pre-Conditions: string is passed
**Post-Conditions: if string is Broken Glass the return is pos, but otherwise neg
****************************************************************************************/
int Cave::troll(string stuff)
{  if(stuff == "Broken Glass")
   {  cout << "Troll smiles: Num num num thanks for the snack!" << endl;
      return 5;
   }
   else if(stuff == "Old Shoe")
   {  cout << "Troll yells: I can't eat a nasty old shoe!" << endl;
      cout << "The troll throws the show at you." << endl;
      return -10; 
   }
   else
   {  cout << "Troll inquires: Maybe I can eat your fingernails instead?\n" << endl;
      cout << "You run to escape the troll and hit your left knee." << endl;
      return -2;
   }
}
