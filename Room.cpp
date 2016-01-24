/****************************************************************************************
 **Program Filename: Room.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Room class is an abstract class where items can be collected, hints can
 **be given, information can be returned
 **Input: strings, Room pointer, and integers
 **Output: Prints messages and returns strings and pointers for items and room information
 ***************************************************************************************/
#include "Room.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


//Default Constructor
Room::Room()
{  type = " ";
   name = " ";
   intro = " ";
   description = " ";
   hint = " ";
   ahead = behind = above = below = left = right = this;
}


//Contructor sets the basic info for the room and sets all pointers to self
Room::Room(string t, string n, string i, string d, string h, vector<string> s)
{  type = t;
   name = n;
   intro = i;
   description = d;
   hint = h;
   stuff = s;
   ahead = behind = above = below = left = right = this;
}


/****************************************************************************************
**Function: setDoors
**Description: This method sets 6 door pointers
**Parameters: 6 foor pointers
**Pre-Conditions: pointer initialized and passed
**Post-Conditions: pointers set to corresponding room objects
****************************************************************************************/
void Room::setDoors(Room * ah, Room * bh, Room * a, Room * b, Room * l, Room * r)
{  ahead = ah;
   behind = bh;
   above = a;
   below = b;
   left = l;
   right = r;
}


/****************************************************************************************
**Function: shoeDoors
**Description: This method displays intros for the rooms at 6 door pointers
**Parameters: none
**Pre-Conditions: object initialized
**Post-Conditions: shows correct introductins and doesn't present info about this room
****************************************************************************************/
void Room::showDoors()
{  if(ahead != this)
   {  cout << "Ahead- " << ahead->getIntro() << endl;
   }
   if(behind != this)
   {  cout << "Behind- " << behind->getIntro() << endl;
   }
   if(above != this)
   {  cout << "Above- " << above->getIntro() << endl;
   }
   if(below != this)
   {  cout << "Below- " << below->getIntro() << endl;
   }
   if(left != this)
   {  cout << "Left- " << left->getIntro() << endl;
   }
   if(right != this)
   {  cout << "Right- " << right->getIntro() << endl;
   }
}


/****************************************************************************************
**Function: getDoors
**Description: This method return a door pointers depending on a string
**Parameters: a string
**Pre-Conditions: user enters the correct string they desire
**Post-Conditions: The corresponding room is returned
****************************************************************************************/
Room * Room::getDoor(string door)
{  if((door == "ahead" || door == "Ahead") && (ahead != this))
   {  return ahead;
   }
   else if((door == "behind" || door == "Behind") && (behind != this))
   {  return behind;
   }
   else if((door == "above" || door == "Above") && (above != this))
   {  return above;
   }
   else if((door == "below" || door == "Below") && (below) != this)
   {  return below;
   }
   else if((door == "left" || door == "Left") && (left) != this)
   {  return left;
   }
   else if((door == "right" || door == "Right") && (right) != this)
   {  return right;
   }
   else
   {  return this;
   }
}


//Get Methods for Room class return class variables
string Room::getType()
{  return type;
}
string Room::getName()
{  return name;
}
string Room::getIntro()
{  return intro;
}
string Room::getDescription()
{  return description;
}
string Room::getHint()
{  return hint;
}


/****************************************************************************************
**Function: showStuff
**Description: This method displays all strings in stuff vector
**Parameters: none
**Pre-Conditions: object initialized
**Post-Conditions: all stuff is displayed
****************************************************************************************/
void Room::showStuff()
{  cout << "~~~Stuff Discovered~~~" << endl;
   for(int i = 0; i < stuff.size(); i++)
   {  cout << (i + 1) << " " << stuff.at(i) << endl;
   }
   cout << endl;
}  


/****************************************************************************************
**Function: getStuff
**Description: This method returns a string depending upon number entered
**Parameters: number
**Pre-Conditions: user enters correct number from list
**Post-Conditions: string item is returned
****************************************************************************************/
string Room::getStuff(int i)
{  if((0 <= (i - 1)) && ((i - 1) <= stuff.size()))
   {  return stuff.at(i - 1);
   }
   else
   {  cout << "ERROR: Invalid Stuff" << endl;
      return "ERROR";
   }
}
