/****************************************************************************************
 **Program Filename: Aqua.hpp
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Aqua class is a subclass of room where you can get friends and swim
 ***************************************************************************************/
#ifndef AQUA_HPP
#define AQUA_HPP
#include "Room.hpp"
#include "Character.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Aqua : public Room
{  
   private:
      vector<string> people;
   public:
      Aqua(string n, string i, string d, string h, vector<string> s, vector<string> p) :
      Room( "Aqua", n, i, d, h, s) {people = p;};
      virtual void mingle();
      virtual string makeFriends(int);
      int swim(string);
};
#endif
