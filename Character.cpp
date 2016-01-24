/****************************************************************************************
 **Program Filename: Character.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Character is a class to hold player info for an adventure game 
 **Input: strings and ints for player info
 **Output: ints and strings to set get and request info
 ***************************************************************************************/
#include "Character.hpp"
#include "Room.hpp"
#include "Bar.hpp"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;


//Default Constructor
Character::Character()
{  name = " ";
   location = NULL;
   fun = 0;
}


//Constructor sets the name location and fun
Character::Character(string n, Room * l)
{  name = n;
   location = l;
   fun = 0;
}


//Get method returns name
string Character::getName()
{  return name;
}


/****************************************************************************************
**Function: changeFunLevel
**Description: This method adjusts the fun level according to an int 
**Parameters: integer
**Pre-Conditions: object intialized and int passed
**Post-Conditions: fun properly adjusted
****************************************************************************************/
void Character::changeFunLevel(int f)
{  fun += f;
   if(f < 0)
   {  cout << "Fun Level Decreased to " << fun << endl;
   }
   else if(f > 0)
   {  cout << "Fun Level Increased to " << fun << endl;
   }
}


//Get method returns fun level
int Character::getFunLevel()
{  return fun;
}


/****************************************************************************************
**Function: addFriend
**Description: This method adds a friend to the vector 
**Parameters: string for friend name
**Pre-Conditions: object intialized and string passed
**Post-Conditions: string in vector
****************************************************************************************/
void Character::addFriend(string f)
{  friends.push_back(f);  
   cout << "Friend " << f << " Joins Party" << endl;
}  


/****************************************************************************************
**Function: displayFriends
**Description: This method displays friends strings in the vector 
**Parameters: none
**Pre-Conditions: object intialized
**Post-Conditions: list displays
****************************************************************************************/
void Character::displayFriends()
{  cout << "~~~Friends List~~~" << endl;
   for(int i = 0; i < friends.size(); i++)
   {   cout << ( i + 1) << " " << friends.at(i) << endl;
   }
   cout << endl;
}



//Get method returns the size of the friend vector
int Character::getNumFriends()
{  return (friends.size());
}


/****************************************************************************************
**Function: getFriends
**Description: This method returns a friend strings if in the vector 
**Parameters: friend string
**Pre-Conditions: object intialized
**Post-Conditions: returns the same string if in the vector and error is not
****************************************************************************************/
string Character::getFriend(int num)
{  if((0 < num) && ((num - 1) <= friends.size()) && (friends.size() != 0))
   {  return friends.at(num - 1);
   }
   else
   {  cout << "ERROR: Invalid Friend\n";
      return "ERROR";
   }
}


/****************************************************************************************
**Function: addPack
**Description: This method adds stuff to the vector 
**Parameters: string for stuff's name
**Pre-Conditions: object intialized and string passed
**Post-Conditions: string in vector
****************************************************************************************/
void Character::addPack(string s)
{  if(pack.size() < 10)
   {  pack.push_back(s);
      cout << s << " Added to Fanny Pack" << endl;
   }
   else
   {  cout << "ERROR: Fanny Pack is Full" << endl;
   }
}


/****************************************************************************************
**Function: displayPack
**Description: This method displays stuff strings in the vector 
**Parameters: none
**Pre-Conditions: object intialized
**Post-Conditions: list displays
****************************************************************************************/
void Character::displayPack()
{  cout << "~~~Fanny Pack Items List~~~" << endl;
   for(int i = 0; i < pack.size(); i++)
   {   cout << ( i + 1) << " " << pack.at(i) << endl;
   }
   cout << endl;
}


/****************************************************************************************
**Function: getPack
**Description: This method returns a stuff strings corresponding to an int 
**Parameters: int
**Pre-Conditions: object intialized and int passed
**Post-Conditions: returns the correct string if in the vector and error is not
****************************************************************************************/
string Character::getPack(int num)
{  if((0 < num) && ((num - 1) <= pack.size()) && (pack.size() != 0))
   {  string temp = pack.at(num - 1);
      pack.erase(pack.begin()+ num -1);
      return temp;
   }
   else
   {  cout << "ERROR: Invalid Stuff\n";
      return "ERROR";
   }
}


/****************************************************************************************
**Function: findPack
**Description: This method returns a stuff strings if in the vector 
**Parameters: stuff string
**Pre-Conditions: object intialized
**Post-Conditions: returns the same string if in the vector and error is not
****************************************************************************************/
string Character::findPack(string find)
{  string temp = "ERROR";
   for(int i = 0; i < pack.size(); i++)
   {  if(pack.at(i) == find)
      temp = find;
   }
   return temp;
}


/****************************************************************************************
**Function: changeLocation 
**Description: This method changes location to a room pointer 
**Parameters: room pointer
**Pre-Conditions: object intialized Room pointer passed
**Post-Conditions: location changed to new room pointer
****************************************************************************************/
void Character::changeLocation(Room * l)
{  location = l;
}

//Get method returns current location
Room * Character::getLocation()
{  return location;
}
