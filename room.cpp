//---------------------------------------------------
// Purpose:     Implementation file for the Room class
// Author:      Jordan Lyle
//---------------------------------------------------
#include "room.h"

//------------------------------------------------------------
// Purpose: Constructor function
//------------------------------------------------------------
Room::Room()
{
   roomName = "none";
   Description = "none";
   maxGold = 0;
   Food = 0;
   Creature = 0;
   roomItem = "none";
}

//------------------------------------------------------------
// Purpose: Destructor function
//------------------------------------------------------------
Room::~Room()
{
}

//------------------------------------------------------------
// Purpose: Set Name value
//------------------------------------------------------------
void Room::setRoomName(const string name)
{
   roomName = name;
}

//------------------------------------------------------------
// Purpose: Set Gold value
//------------------------------------------------------------
void Room::setMaxGold(const int gold)
{
   maxGold = gold;
}

//------------------------------------------------------------
// Purpose: Set Food name
//------------------------------------------------------------
void Room::setFoodName(const int food)
{
   Food = food;
}

//------------------------------------------------------------
// Purpose: Set Creature name
//------------------------------------------------------------
void Room::setCreature(const int creature)
{
   Creature = creature;
}

//------------------------------------------------------------
// Purpose: Set Description of Room
//------------------------------------------------------------
void Room::setDescription(const string description)
{
   Description = description;
}

//------------------------------------------------------------
// Purpose: Set Items value
//------------------------------------------------------------
void Room::setRoomItem(const string Item)
{
   roomItem = Item;
}

//------------------------------------------------------------
// Purpose: Get Name value
//------------------------------------------------------------
string Room::getRoomName() const
{
   return roomName;
}

//------------------------------------------------------------
// Purpose: Get Gold value
//------------------------------------------------------------
int Room::getMaxGold() const
{
   return maxGold;
}

//------------------------------------------------------------
// Purpose: Get Food name
//------------------------------------------------------------
int Room::getFoodName() const
{
   return Food;
}

//------------------------------------------------------------
// Purpose: Get Creature name
//------------------------------------------------------------
int Room::getCreature() const
{
   return Creature;
}

//------------------------------------------------------------
// Purpose: Get Items value
//------------------------------------------------------------
string Room::getRoomItem() const
{
   return roomItem;
}

//------------------------------------------------------------
// Purpose: Get Room description
//------------------------------------------------------------
string Room::getDescription() const
{
   return Description;
}

//------------------------------------------------------------
// Purpose: Prints Room Information
//------------------------------------------------------------
void Room::printRoomInformation()
{
   cout << "\nRoom Information" << endl;
   cout << "Room Name:   " << roomName << endl;
   cout << "Description: " << endl << Description << endl << endl;
   cout << "Max Gold:   " << maxGold << endl;
   cout << "Food: " << Food << endl;
   cout << "Creature:  " << Creature << endl;
   cout << "Item: " << roomItem << endl;
}
//------------------------------------------------------------
// Purpose: Uses maxGold to determine how much gold a player gets from each room
//------------------------------------------------------------
int Room::findGold()
{
    int gold = 1 + random() % maxGold;
    if (gold < maxGold/2)
        cout << "\nYou find " << gold << " gold pieces on the floor.";
    else
        cout << "\nYou find a huge mound of " << gold << " gold pieces!";
    return gold;
}
//------------------------------------------------------------
// Purpose: Increases health via "eating food" located in the room (stops when either health is max or food is out)
//------------------------------------------------------------
int Room::eatFood(int health, int foodType)
{
switch (foodType)
{
case 1:
// Turkey
    health = health + 30;
    cout << "\nYou find a fresh Turkey waiting for you at the start of your adventure " << "that restores your health by 30" << endl;
    break;
case 2:
// Fries
    health = health + 10;
    cout << "\nYou find some old fries left by an unknown someone " << "which restore your health by 10" << endl;
    break;
default:
    cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
    break;

}
if (health > 100)
{
    health = 100;
}
return health;
}
//------------------------------------------------------------
// Purpose: Decreases health by "fighting a creature" located in the room
//------------------------------------------------------------
int Room::fightCreature(int health, int creatureType)
{
int damage = 0;
switch (creatureType)
{
case 1:
//Silverfish creature
    damage = 1 + random() % 3;
    cout << "\nA small Silverfish bug bites you on your way in, only doing " << damage << " damage to your health.";
    break;
case 2:
//Ghost creature
    damage = 1 + random() % 40;
    cout << "\nA looming ghost becomes aware of your presence, but thankfully you manage to escape only taking " << damage << " damage to your health.";
    break;
default:
    cout << "\nIt is ghostly quiet here, you must be alone\n";
    break;
}
    return damage;
}
//------------------------------------------------------------
// Purpose: Says what item is found in the room, asks the user if they want it, takes the response from the user
//------------------------------------------------------------
string Room::foundItem()
{
    cout << "You found " << roomItem << "!";
    cout << endl << "Would you like to keep the Item? (Yes/No): ";
    string Question;
    cin >> Question;
    return(Question);
}
