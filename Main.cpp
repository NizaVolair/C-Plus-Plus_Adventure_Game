/****************************************************************************************
 **Program Filename: Main.cpp 
 **Author: Niza Volair
 **Date: 06-09-15
 **Description: Main for Adventure Game Program 
 **Input: Chars and Ints for Choices and One string for a name 
 **Output: Prints messages to screen to prompt for choices and calls funtions from Room
 ***************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "Character.hpp"
#include "Room.hpp"
#include "Aqua.hpp"
#include "Bar.hpp"
#include "Cave.hpp"
#include "RegRoom.hpp"
#include "Roof.hpp"
#include "Slide.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int main()
{  //Create bools for checks for a finished game, a winning result, a decision to move,
   //a decision to add, and the time running out; ints for choices and time checks; a char
   //for yes/no answer, strings for object variables, a room pointer, and vectors for people/stuff
   bool finish = false;
   bool win = false; 
   bool move = false;
   bool add = false;
   bool overTime = false;
   int choice, num, timeNow = 0;
   char yesno;
   string name, intro, description, stuff, destination, hint, person;
   Room * roomPtr;
   vector<string>peopleVec;
   vector<string>stuffVec;

   //Create variables for all 10 of the classes and then create the room objects
   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fire Pit Pub ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a weathered door";
   description = "You walk into a lively dive bar. A warm fire blazes in a pit that\n";
   description += "dominates the center of the floor. Several people are drinking drinks\n";
   description += "and toasting marshmellows around the fire. The barkeep gives you a wide\n";
   description += "smile revealing a single gold tooth.";
   hint = "Make Friends with Everyone, Drink, & Collect Broken Glass...";
   peopleVec.push_back("Sara");
   peopleVec.push_back("Katie");
   peopleVec.push_back("Anastasia");
   peopleVec.push_back("Holly");
   peopleVec.push_back("Choco");
   stuffVec.push_back("Ripped Napkin");
   stuffVec.push_back("Broken Glass");
   stuffVec.push_back("Soggy Coaster");
   Bar firePitPub(name, intro, description, hint, stuffVec, peopleVec);
   Bar * firePitPubPtr = &firePitPub;
  
   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Concrete Cave ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a large hole in the concrete wall leading into darkness";
   description = "You hunker down and bend your head as you enter into the hole. The walls\n";
   description += "become rougher and narrower and they scrape your elbows as you find\n";
   description += "yourself walking up a slight incline. You hear eerie laughter echoing\n";
   description += "though the twisting tunnels that surround you. Lounging in a small\n";
   description += "niche carved into one wall is a medium sized cave troll clasping a\n";
   description += "bottle of wine. The troll smiles revealing many gold teeth.";
   hint = "Trolls Enjoy a Bit of Broken Glass...";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Glow Stick");
   stuffVec.push_back("Gold Tooth");
   stuffVec.push_back("Old Shoe");
   Cave concreteCave(name, intro, description, hint, stuffVec);
   Cave * concreteCavePtr = &concreteCave;

   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Concrete Caverns ~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a jagged hole cut high into the concrete wall leading into darkness";
   description = "You jump up and scramble into the jagged opening. You can see bright\n";
   description += "flitting flashes of glow sticks and hear shrieks of laughter or fright\n";
   description += "though the twisting tunnels that surround you. Scurrying past you\n";
   description += "notice a small sized troll with only one shoe.";
   hint = "Trolls Enjoy Broken Glass More than Nasty Old Shoes...";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Glow Stick");
   stuffVec.push_back("Paper Bag with a Hole");
   Cave concreteCaverns(name, intro, description, hint, stuffVec);
   Cave * concreteCavernsPtr = &concreteCaverns;
   
   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Aqua Palace ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "an ornately decorated glass door with iridescent lights refecting from inside";
   description = "You twist the gold handle of the door and walk into a world of aquatic\n";
   description += "wonders. The room is filled with glass structures of all sizes with\n";
   description += "schools of fish and other creatures swimming all around you. You \n";
   description += "wander through a myriad of rooms each more beautiful than the next\n";
   description += "then enter a room filled with a large pool flowing almost to the door.";
   hint = "Lifegaurd Katie is a Great Swim Coach and You Look Good in Mermaid Scales...";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Shark Fin");
   stuffVec.push_back("Mermaid Scale Dress");
   peopleVec.erase(peopleVec.begin(), peopleVec.end());
   peopleVec.push_back("Selkie");
   Aqua aquaPalace(name, intro, description, hint, stuffVec, peopleVec);
   Aqua * aquaPalacePtr = &aquaPalace;

   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Aquarium ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a small golden porthole";
   description = "You twist the heavy knob swinging open the porthole and slide into the\n";
   description += "narrow opening. You are in a clear glass tube surrounded by all forms\n";
   description += "of aquatic life. Squids, octopi, and sharks swirl in the waters around.\n";
   description += "You shimmy through the tube until you arrive in a small room.";
   hint = "Swim with Katie & only go up if you have Friends, Fun or a Mermaid Dress...";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Shark Scale");
   stuffVec.push_back("Tentacles");
   stuffVec.push_back("Whistle");
   peopleVec.erase(peopleVec.begin(), peopleVec.end());
   peopleVec.push_back("Pirate");
   peopleVec.push_back("Tiger Shark");
   Aqua aquarium(name, intro, description, hint, stuffVec, peopleVec);
   Aqua * aquariumPtr = &aquarium;

   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Ten Story Slide ~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a cooper staircase spirals into the distance";
   description = "You step onto the staircase and begin your ascent. The steps gradually\n";
   description += "become steeper and more narrow. You see metal slides circling over and\n";
   description += "around the steps and every now and then you catch a glimpse of color\n";
   description += "zip past. Breathless, you arrive at the top of the staircase and survey\n";
   description += "your surroundings to find a myriad of opening leading down into slides\n";
   description += "of all shapes and sizes";
   hint = "Sometimes You Must Simply Relax & Enjoy the Ride...";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Broken Glass");
   stuffVec.push_back("Glow Stick");
   stuffVec.push_back("Catnip");
   Slide tenStorySlide(name, intro, description, hint, stuffVec);
   Slide * tenStorySlidePtr = &tenStorySlide;
   
   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Aerial Plane  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a circular path made of metal pipes leading out into the night";
   description = "You crawl into the metal structure and feel cool air breeze past\n";
   description += "your cheek. You venture further out into a mass of tangled metal\n";
   description += "spirals far above the city beneath you. In the distance an airplane\n";
   description += "hangs suspended in an eternal flight through twisted steel";
   hint = "Have Fun, Friends or maybe just Mermaid Attire? Enjoy the View at the Top...";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Owl");
   stuffVec.push_back("Gold Tooth");
   stuffVec.push_back("1 Dollar");
   RegRoom aerialPlane(name, intro, description, hint, stuffVec);
   RegRoom * aerialPlanePtr = &aerialPlane;

   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tree Top Tunnels ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "wooden branches bending out just enough to climb inside an ancient tree";
   description = "You climb into the branches and quickly find this is no ordinary tree.\n";
   description += "It is a symbiotic structure of living oak intertwined with drift wood\n";
   description += "and salvaged rope. You weave in between branches and beams intil you\n";
   description += "find yourself under a canopy of leaves and silver streamers standing\n";
   description += "on a large wooden platform";
   hint = "Have Fun, Friends or maybe just Mermaid Scale Attire? Enjoy the View at the Top...";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Porcupine");
   stuffVec.push_back("Mermaid Scale Sneakers");
   stuffVec.push_back("Facedown Penny");
   RegRoom treeTopTunnels(name, intro, description, hint, stuffVec);
   RegRoom * treeTopTunnelsPtr = &treeTopTunnels;

   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Last Chance Lounge ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a steel door";
   description = "You step into a dimly lit lounge with dark sofas and a bar\n";
   description += "made from smooth granite. There are a few poeple relaxing\n";
   description += "on the sofas and sipping on drinks";
   hint = "Make Friends with Everyone, Drink, & Collect Broken Glass...";
   peopleVec.erase(peopleVec.begin(), peopleVec.end());
   peopleVec.push_back("Rosh");
   peopleVec.push_back("Emme");
   peopleVec.push_back("Dan");
   peopleVec.push_back("Bridget");
   peopleVec.push_back("Patrick");
   peopleVec.push_back("Alyssa");
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Ripped Napkin");
   stuffVec.push_back("Broken Bottle");
   stuffVec.push_back("Fresh Coaster");
   stuffVec.push_back("Popcorn");
   Bar lastChanceLounge(name, intro, description, hint, stuffVec, peopleVec);
   Bar * lastChanceLoungePtr = &lastChanceLounge;
   
   name = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Roof Top ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   intro = "a small black ladder leading up into darkness";
   description = "You grip the cool metal and climb. Soon you see nothing except tiny\n";
   description += "glow stick lights flickering above you. Wind whips past your cheek\n";
   description += "and a low alien buzzing sound hums in your ear. As your hands feel\n";
   description += "the top rung of the ladder and  tentatively step off onto solid ground,\n";
   description += "a sudden boom of fireworks explodes the air. Sharp lights illuminate\n";
   description += "you surroundings. You are not alone. An enormous praying mantis looms\n";
   description += "above you looking awfully hungry...";
   hint = "Hope You Have Fun, Friends or some Swanky Mermaid Scale Attire!!!";
   stuffVec.erase(stuffVec.begin(), stuffVec.end());
   stuffVec.push_back("Human Bones");
   stuffVec.push_back("Stuffed Rabbit");
   stuffVec.push_back("Cowboy Hat");
   Roof roofTop(name, intro, description, hint, stuffVec);
   Roof * roofTopPtr = &roofTop;

   //Pass room pointers to the door set methods to link all the pointers of all 10 rooms
   firePitPub.setDoors(concreteCavernsPtr, aquaPalacePtr, firePitPubPtr,
			firePitPubPtr, tenStorySlidePtr, concreteCavePtr);
   
   lastChanceLounge.setDoors(aerialPlanePtr, aquariumPtr, lastChanceLoungePtr, 
			lastChanceLoungePtr, tenStorySlidePtr, treeTopTunnelsPtr);

   roofTop.setDoors(roofTopPtr, roofTopPtr, roofTopPtr, tenStorySlidePtr, roofTopPtr, roofTopPtr);

   concreteCave.setDoors(concreteCavePtr, concreteCavePtr, treeTopTunnelsPtr, 
			firePitPubPtr, aquaPalacePtr, concreteCavernsPtr);

   concreteCaverns.setDoors(lastChanceLoungePtr, concreteCavernsPtr, aerialPlanePtr,
			firePitPubPtr, concreteCavePtr, tenStorySlidePtr);

   aquaPalace.setDoors(lastChanceLoungePtr, aquaPalacePtr, aquariumPtr,
			firePitPubPtr, tenStorySlidePtr, concreteCavePtr);

   aquarium.setDoors(aquariumPtr, lastChanceLoungePtr, roofTopPtr,
			aquaPalacePtr, tenStorySlidePtr, treeTopTunnelsPtr);

   treeTopTunnels.setDoors(treeTopTunnelsPtr, treeTopTunnelsPtr, roofTopPtr,
			concreteCavePtr, aquariumPtr, aerialPlanePtr);

   aerialPlane.setDoors(aerialPlanePtr, lastChanceLoungePtr, roofTopPtr,
			concreteCavernsPtr, treeTopTunnelsPtr, tenStorySlidePtr);

   tenStorySlide.setMultiDoors(aerialPlanePtr, concreteCavernsPtr, treeTopTunnelsPtr, concreteCavePtr,
			aquariumPtr, aquaPalacePtr, lastChanceLoungePtr, firePitPubPtr);

   //Introduce game
   cout << endl << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~ ST. LOUIS CITY MUSEUM ADVENTURE GAME ~~~~~~~~~~~~~~~~~~~";
   cout << endl << endl;
   cout << "An eccentric millionaire has taken the refuse of the city, mangled pipes,\n";
   cout << "torn-up tires, and even the odd airplane or two, and built an awesome playgroud\n";
   cout << "for adults and children alike in a historic manision in downtown St. Louis\n";
   cout << "which residents have fondly named the City Museum.\n" << endl;
   cout << "Now, you've come to this lively place to attend an epic New Year's Eve Party!\n";
   cout << "It's 11:45pm, can you make it to the roof by midnight? Even if you make it in\n";
   cout << "time you still must face the mysterious challenge hiding in the shadows.\n";
   cout << endl << "You pull your bike up outside the building, strap on your trusty\n";
   cout << "fanny pack and open the door to see what adventures await...\n" << endl;
   
   //Introduce first room and get player name then initialize character object
   cout << firePitPub.getName() << endl;
   cout << firePitPub.getDescription() << endl <<endl;
   cout << "The barkeep asks: What's your name?" << endl;
   cout << "You respond: ";
   getline(cin, name);
   Character you(name, &firePitPub);
   Character * youPtr = &you;   
   
   do
   {  //Display room menu in a do while loop with options changing depending upon room type
      cout << endl << "~~~~~ Room Menu Choices ~~~~~" << endl;
      cout << "1) Get Hint\n";
      cout << "2) Search for Stuff\n";
      if(you.getLocation()->getType() != "Slide")
      {	 cout << "3) Look Around for an Exit\n";
      }
      else
      {	 cout << "3) Slide into the Unknown\n";
      }
      if(you.getLocation()->getType() == "Cave")
      {	 cout << "4) Talk to the Troll\n";
      }
      else if(you.getLocation()->getType() == "Roof")
      {	 cout << "4) Battle the Mantis\n";
      }
      else if((you.getLocation()->getType() == "Bar") 
	 || (you.getLocation()->getType() == "Aqua"))
      {	 cout << "4) Mingle with the Locals\n";
      }
      if(you.getLocation()->getType() == "Bar") 
      {	 cout << "5) Drink to Adventure\n";
      }
      else if(you.getLocation()->getType() == "Aqua")
      {	 cout << "5) Take a Swim\n";
      }

      do
      {	 //Get the users menu choice
	 cout << endl << "Make Choice from Room Menu (ex: '1' or '3'): ";
	 cin >> choice;
	 cout << endl;
	 
	 //Display a hint if the user selects 1
	 if(choice == 1)
	 {   cout << you.getLocation()->getHint() << endl;
	 }

	 //Display the loot if the user selects 2
	 else if(choice == 2)
	 {  you.getLocation()->showStuff();
	    do
	    {  cout << endl << "Does " << you.getName() << " Put Stuff in Fanny Pack (y/n)? ";
	       cin >> yesno;
	       cout << endl;
	       //If the user wants to get stuff they can add items any number of times until limit
	       if(yesno == 'y' || yesno == 'Y')
	       {  add = true;
		  cout << "Enter Stuff #: ";
		  cin >> num;
		  cout << endl;
		  stuff = you.getLocation()->getStuff(num);
	          if(stuff != "ERROR")
		  {  you.addPack(stuff);
		  }
	       }
	       else
	       {  add = false;
	       }
	    }while(add);
	 }

	 //If choice is 3 and user is not in the slide room show available exits
	 else if((choice == 3) && (you.getLocation()->getType() != "Slide"))
	 {  you.getLocation()->showDoors();
	    cout << endl << "Does " << you.getName() << " Move (y/n)? ";
	    cin >> yesno;
	    cout << endl;
	    //If the use wishes to exit, get a string cooresponding with a direction available
	    if(yesno == 'y' || yesno == 'Y')
	    {  cout << "Choose from Available Options Above (ex: 'below' 'ahead' or 'right'): ";
	       cin >> destination;
	       roomPtr = you.getLocation()->getDoor(destination);
	       cout << endl;
	       //If the result isn't the same as the current room, change the room and display info
	       if(roomPtr != you.getLocation())
	       {  you.changeLocation(roomPtr);
		  move = true;
		  cout << endl << you.getLocation()->getName() << endl;
		  cout << you.getLocation()->getDescription() << endl;
	       }
	       else
	       {  cout << "ERROR: Invalid Destination" << endl;
	       }
	    }
	 }

	 //If the choice is 3 and it is a slide user can enter any number but won't know the options
	 else if((choice == 3) && (you.getLocation()->getType() == "Slide"))
	 {  cout << "There is no way of knowing what's at the other end of any of these\n";
	    cout << "slippery slopes. Enter any number to shoot down the corresponding slide: ";
	    cin >> num;
	    roomPtr = you.getLocation()->getDoor(num);
	    //Change the room and display info
	    you.changeLocation(roomPtr);
	    cout << endl;
	    move = true;
	    cout << you.getLocation()->getName() << endl;
	    cout << you.getLocation()->getDescription() << endl;
	 }

	 //If the choice is 4 and the room is a cave, the user can pass an object to a troll
	 else if((choice == 4) && (you.getLocation()->getType() == "Cave"))
	 {  cout << endl << "The troll asks if you have some nice broken glass to nibble upon.\n";
	    cout << you.getName() << " searches fanny pack and finds...\n" << endl;
	    you.displayPack();
	    cout << "Does " << you.getName() << " give anything to the troll(y/n)? ";
	    cin >> yesno;
	    cout << endl;
	    //If the user passes an object the troll function will return a pos/neg integer
	    if(yesno == 'y' || yesno == 'Y')
	    {  cout << "Enter Stuff #: ";
	       cin >> num;
	       stuff = you.getPack(num);
	       cout << endl;
	       num = you.getLocation()->troll(stuff);
	       you.changeFunLevel(num);
	    }
	    else
	    {  num = you.getLocation()->troll("nothing");
	       you.changeFunLevel(num);
	    }
	 }

	 //If the choice is 4 and the room is a cave, the player can battle the mantis
	 else if((choice == 4) && (you.getLocation()->getType() == "Roof"))
	 {  //The mantis function returns true of the player wins and false otherwise
	    win = you.getLocation()->mantis(youPtr);
	    finish = true;
	 }

	 //If the choice is 4 and the room is a bar or aqua the player can make friends
	 else if((choice == 4) && ((you.getLocation()->getType() == "Bar")
				    || (you.getLocation()->getType() == "Aqua")))
	 {  you.getLocation()->mingle();
	    do
	    {  cout << endl << "Does " << you.getName() << " Make Friends (y/n)? ";
	       cin >> yesno;
	       cout << endl;
	       //The player can add any friend any number of times until they have enough
	       if(yesno == 'y' || yesno == 'Y')
	       {  add = true;
		  cout << "Enter Person #: ";
		  cin >> num;
		  person = you.getLocation()->makeFriends(num);
	          if(person != "ERROR")
		  {  you.addFriend(person);
		  }
	       }
	       else
	       {  add = false;
	       }
	    }while(add);
	 }

	 //If the choice is 5 and the room is bar the player can drink
	 else if((choice == 5) && (you.getLocation()->getType() == "Bar"))
	 {  you.getLocation()->showDrinks();
	    do
	    {  cout << endl << "Does " << you.getName() << " Drink (y/n)? ";
	       cin >> yesno;
	       cout << endl;
	       //If the player drinks their fun level is increased by the drink number
	       if(yesno == 'y' || yesno == 'Y')
	       {  add = true;
		  cout << "Enter Drink #: ";
		  cin >> num;
		  num = you.getLocation()->getDrink(num);
	          you.changeFunLevel(num);
	       }
	       else
	       {  add = false;
	       }
	    }while(add);
	 }

	 //If the choice is 5 and the type is aqua, the player can swim
	 else if((choice == 5) && (you.getLocation()->getType() == "Aqua"))
	 {  cout << endl << "The water is a bit murky. It might not be safe to swim alone.\n";
	    cout << you.getName() << " looks for a friend and finds...\n" << endl;
	    you.displayFriends();
	    cout << "Does " << you.getName() << " bring a friend(y/n)? ";
	    cin >> yesno;
	    cout << endl;
	    //If the player brings friend "Katie" they gan fun but they lose fun otherwise
	    if(yesno == 'y' || yesno == 'Y')
	    {  cout << "Enter Friend #: ";
	       cin >> num;
	       stuff = you.getFriend(num);
	       cout << endl;
	       num = you.getLocation()->swim(stuff);
	       you.changeFunLevel(num);
	    }
	    else
	    {  num = you.getLocation()->swim("none");
	       you.changeFunLevel(num);
	    }
	 }
	 //If the player doesn't enter a good menu choice they are repromted
	 else
	 {  cout << "ERROR: Invalid Selection\n";
	    if((timeNow + 1)  < 15)
	    {  cout << "Please Select from the Room Menu\n";
	       move = true;
	    }
	 }
      }while((!move) && (!finish) && (!overTime));

      //Time is increased when a player changes rooms
      timeNow++;

      //If the game isn't finished the time status is reported to the user
      if(!finish)
      {	 if(timeNow > 15)
	 {  overTime = true;
         }
	 else if(timeNow < 15)
	 {  cout << endl << (15 - timeNow) << " more minutes until Midnight!\n";
	 }
	 else
	 {  cout << endl << "Last Chance!\n";
	 }
      }

      //Move is reset to false for the beginning of the next room
      move = false;


   //Loop continues until game is finished or time is up   
   }while((!finish) && (!overTime));
   cout << endl;

   //Messages display informing user of the game result
   if(win)
   {  cout << "CONGRATULATIONS!!! You Won the St. Louis City Museum Adventure Game!!!\n" << endl;
   }
   else
   {  cout << "Whomp Whomp... You Lost the St. Louis City Museum Adventure Game!!!\n" << endl;
   }
   if((!win) && (overTime))
   {  cout << "The clock is at midnight and you missed the party. You hear the faint sound\n";
      cout << "of fireworks in the distance and a single tear falls down your cheek\n" << endl;
   }

   return 0;
}
