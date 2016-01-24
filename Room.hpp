/****************************************************************************************
 **Program Filename: Room.hpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Room class is an abstract class where items can be collected, hints can
 ***************************************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include "Character.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;


class Character;

class Room
{  
   protected:
      string type;
      string name;
      string intro;
      string description;
      string hint;
      vector<string> stuff;
      Room * ahead;
      Room * behind;
      Room * above;
      Room * below;
      Room * left;
      Room * right;
   public:
      Room();
      Room(string, string, string, string, string, vector<string>);
      void setDoors(Room *, Room *, Room *, Room *, Room *, Room *);
      void showDoors();
      Room * getDoor(string);
      string getType();
      string getName();
      string getIntro();
      string getDescription();
      string getHint();
      void showStuff();
      string getStuff(int); 
      virtual void mingle() {};
      virtual string makeFriends(int) {};
      virtual void showDrinks() {};
      virtual int getDrink(int) {};
      virtual int troll(string) {};
      virtual int swim(string) {};
      virtual bool mantis(Character *) {};
      virtual void setMultiDoors(Room *, Room *, Room *, Room *, Room *, Room *, Room *, Room *) {};
      virtual Room * getDoor(int) {};
};
#endif
