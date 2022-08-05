//---------------------------------------------------
// Purpose:     Header file for the Room class
// Author:      Jordan Lyle
//---------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

class Room
{
private:
   string roomName;
   string Description;
   int maxGold;
   int Food;
   int Creature;
   string roomItem;

public:
// Constructor
   Room();
// Destructor
   ~Room();
// Setters
   void setRoomName(const string name);
   void setMaxGold(const int gold);  
   void setFoodName(const int food);
   void setCreature(const int creature);
   void setRoomItem(const string Item);
   void setDescription(const string description);
// Getters
   string getRoomName() const;
   int getMaxGold() const;
   int getFoodName() const;
   int getCreature() const;
   string getRoomItem() const;
   string getDescription() const;
// Other Functions
   void printRoomInformation();
   int findGold();
   int eatFood(int health, int foodType);
   int fightCreature(int health, int creatureType);
   string foundItem();
};
