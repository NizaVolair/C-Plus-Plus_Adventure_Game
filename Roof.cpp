/****************************************************************************************
 **Program Filename: Roof.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Roof class is a child class of Room with a end game mantis fight funtion
 **Input: Character pointer 
 **Output: Displays messages about win/lose status and returns win/lose bool
 ***************************************************************************************/
#include "Room.hpp"
#include "Roof.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;


/****************************************************************************************
**Function: mantis
**Description: This method takes a character pointer checks for criteria and determines
**if the game has been won or lost
**Parameters: Character pointer
**Pre-Conditions: objects initialized
**Post-Conditions: bool returns true if one of 3 criteria is met
****************************************************************************************/
bool Roof::mantis(Character * you)
{  int check = 1;
   bool win = false;
   string temp;
   //Check if the player is popular
   if(you->getNumFriends() > 5)
   {  win = true;
      cout << "Your friends rally around you brandishing glowsticks and broken bottles!\n";
      cout << "The manitis takes a step back, caught off gaurd by this display of love.\n";
      cout << "Slowly and cautiously, the mantis gives you a high-five!\n" << endl;
   }
   //Check if the player has fun
   if(you->getFunLevel() > 10)
   {  win = true;
      cout << "The mantis blinks at you once, twice... a shy smile forms on its jagged\n";
      cout << "mouth. Music cues in the background and the mantis begins to dance!\n";
      cout << "Even vicious creatures of the night can't resist your fun-loving charms!!\n" << endl;
   }
   //Check if the player is well dressed
   if((you->findPack("Mermaid Scale Dress") != "ERROR") 
   || (you->findPack("Mermaid Scale Sneakers") != "ERROR")) 
   {  win = true;
      cout << "You slip into your mermaid scale attire. Dang you look good! The mantis\n";
      cout << "offers you a claw, and you accept. You jump on its back and fly off into\n";
      cout << "the night as fireworks blaze across the velvet sky.\n";
   }
   //If the player hasn't won yet, they lose :(
   if(!win)
   {  cout << "The mantis lashes out knocking " << you->getName() << " backwards off\n";
      cout << "the egde of the roof! " << you->getName() << " is not having fun!!\n" << endl;
      you->changeFunLevel(-100);
      cout <<  endl << you->getName() << " is dead.\n" << endl;
    
   }
   return win;
}

