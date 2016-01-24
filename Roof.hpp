/****************************************************************************************
 **Program Filename: Roof.hpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Roof class is a child class of Room with a end game mantis fight funtion
 ***************************************************************************************/
#ifndef ROOF_HPP
#define ROOF_HPP
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Roof : public Room
{  
   public:
      Roof(string n, string i, string d, string h, vector<string> s) :
      Room("Roof", n, i, d, h, s) {};
      bool mantis(Character *);




};
#endif
