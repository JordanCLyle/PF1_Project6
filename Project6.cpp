//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Author: John Gauch
// Editor: Jordan Lyle
//------------------------------------------------------------

#include "player.h"
#include "room.h"

int main()
{
   // Initialize game
   srandom(time(NULL));

   // Create room1
   Room room1;
   room1.setRoomName("Entrance");
   room1.setMaxGold(10);
   room1.setFoodName(1);
   room1.setCreature(1);
   room1.setRoomItem("3D Glasses");
   room1.setDescription("A mysterious door appears before you and you decide to enter,\nunknowing of the dangers ahead of you.\n");
   // Create room2
   Room room2;
   room2.setRoomName("Amusement House");
   room2.setMaxGold(150);
   room2.setFoodName(2);
   room2.setCreature(2);
   room2.setRoomItem("7-Sided Die");
   room2.setDescription("This room looks very similar to an old playhouse you used to play in.\nDo you dare to look into the ballpit?\n");
   // Create player
   int gold = 0;
   int health = MAX_HEALTH;
   Player player;
   player.setName("John");
   player.setGold(0);
   player.setHealth(MAX_HEALTH);
   player.setItems("");

   // Call Room methods
    room1.printRoomInformation();
    room2.printRoomInformation();
   // Call Player methods
    player.Print();
   // Call Room methods
    cout << endl << room1.getDescription();
    gold = gold + room1.findGold();
    health = health - room1.fightCreature(health, room1.getCreature());
    health = room1.eatFood(health, room1.getFoodName());
    int x = 0;
    // User Prompt for Picking up Item
    while (x == 0)
    { 
        string Question = room1.foundItem();
        if (Question == "Yes")
        {
            player.addItem(room1.getRoomItem());
            cout << "Item Added to Backpack" << endl;
            x = 1;
        }
        else if (Question == "No")
        {
            cout << "Okay then!" << endl;
            x = 1;
        }
        else
        {
            x = 0;
            cout << "Invalid input, please enter the correct input." << endl << endl;
        }
    }
   // Call Player methods
    player.setGold(gold);
    player.setHealth(health);
    player.Print();
   // Call Room methods
    cout << endl << room2.getDescription();
    gold = gold + room2.findGold();
    health = health - room2.fightCreature(health, room2.getCreature());
    health = room2.eatFood(health, room2.getFoodName());
    x = 0;
    // User Prompt for Picking up Item
    while (x == 0)
    { 
        string Question = room2.foundItem();
        if (Question == "Yes")
        {
            player.addItem(room2.getRoomItem());
            cout << "Item Added to Backpack" << endl;
            x = 1;
        }
        else if (Question == "No")
        {
            cout << "Okay then!" << endl;
            x = 1;
        }
        else
        {
            x = 0;
            cout << "Invalid input, please enter the correct input." << endl << endl;
        }
    }
    // Call Player methods
    player.setGold(gold);
    player.setHealth(health);
    player.Print();
   return 0;
}
