/****************************************************************************************
 **Program Filename: Bar.hpp
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Bar class is a subclass of room where you can get friends and drink
****************************************************************************************/
#ifndef BAR_HPP
#define BAR_HPP
#include "Room.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Bar : public Room
{  
   private:
      vector<string> people;
   public:
      Bar(string n, string i, string d, string h, vector<string> s, vector<string> p) :
      Room("Bar", n, i, d, h, s) { people = p;};
      void mingle();
      string makeFriends(int);
      void showDrinks();
      int getDrink(int);
};
#endif
