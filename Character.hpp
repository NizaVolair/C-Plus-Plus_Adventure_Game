/****************************************************************************************
 **Program Filename: Character.hpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Character is a class to hold player info for an adventure game 
 ***************************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Room.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Room;
class Bar;

class Character
{  
   private:
      string name;
      int fun;
      vector<string> friends;
      vector<string> pack;
      Room * location;
   public:
      Character();
      Character(string, Room *);
      string getName();
      void changeFunLevel(int);
      int getFunLevel();
      void addFriend(string);
      void displayFriends();
      int getNumFriends();
      string getFriend(int);
      void addPack(string);
      void displayPack();
      string getPack(int);
      string findPack(string);
      void changeLocation(Room *);
      Room * getLocation();
};
#endif
