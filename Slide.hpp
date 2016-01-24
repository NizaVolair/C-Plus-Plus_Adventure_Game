/****************************************************************************************
 **Program Filename: Slide.hpp
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Slide is a child of Room with two additional room pointers
 ***************************************************************************************/
#include "Room.hpp"
#ifndef SLIDE_HPP
#define SLIDE_HPP
#include "Room.hpp"
#include "Character.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Slide : public Room
{  
   private:
      Room * middle;
      Room * floor;
   public:
      Slide(string n, string i, string d, string h, vector<string> s) :
      Room( "Slide", n, i, d, h, s) 
      {	 ahead = behind = above = below = left = right = middle = floor = this;
      };
      void setMultiDoors(Room *, Room *, Room *, Room *, Room *, Room *, Room *, Room *);
      Room * getDoor(int);
};
#endif
