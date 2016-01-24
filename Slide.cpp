/****************************************************************************************
 **Program Filename: Slide.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Slide is a child of Room with two additional room pointers
 **Input: Room pointers and ints
 **Output: Room pointer
 ***************************************************************************************/
#include "Room.hpp"
#include "Slide.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;


/****************************************************************************************
**Function: setMultiDoors
**Description: This method sets 8 room pointers 
**Parameters: 8 room pointers
**Pre-Conditions: object initialized and poitners passes
**Post-Conditions: all 8 links work correctly
****************************************************************************************/
void Slide::setMultiDoors(Room * ah, Room * bh, Room * a, Room * b, Room * l, Room * r, Room * m, Room * f)
{  ahead = ah;
   behind = bh;
   above = a;
   below = b;
   left = l;
   right = r;
   middle = m;
   floor = f;
}


/****************************************************************************************
**Function: getDoors
**Description: This method returns one of the 8 doors base on the 8 modulus of any number  
**Parameters: integer
**Pre-Conditions: object initialized
**Post-Conditions: returns a link to a room object
****************************************************************************************/
Room * Slide::getDoor(int door)
{  int num = ((door % 8) + 1);
   if(num == 1)
   {  return ahead;
   }
   else if(num == 2)
   {  return behind;
   }
   else if(num == 3)
   {  return above;
   }
   else if(num == 4)
   {  return below;
   }
   else if(num == 5)
   {  return left;
   }
   else if(num == 6)
   {  return right;
   }
   else if(num == 7)
   {  return middle;
   }
   else if(num == 8)
   {  return floor;
   }
}
