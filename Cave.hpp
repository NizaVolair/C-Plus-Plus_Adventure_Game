/****************************************************************************************
 **Program Filename: Cave.hpp
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Cave class is a subclass of room where you can talk to a troll
****************************************************************************************/
#ifndef CAVE_HPP
#define CAVE_HPP
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Cave : public Room
{ 
   public:
      Cave(string n, string i, string d, string h, vector<string> s) :
      Room( "Cave", n, i, d, h, s) {};
      int troll(string);
};
#endif
