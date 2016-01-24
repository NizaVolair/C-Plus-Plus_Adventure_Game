/****************************************************************************************
 **Program Filename: RegRoom.hpp
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: RegRoom class is a subclass of room
 ***************************************************************************************/
#ifndef REGROOM_HPP
#define REGROOM_HPP
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class RegRoom : public Room
{
   public:
      RegRoom(string n, string i, string d, string h, vector<string> s) :
      Room( "Plane", n, i, d, h, s) {};
};
#endif
