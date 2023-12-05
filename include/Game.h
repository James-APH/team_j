/**
* @Author James Huston [huston@uleth.ca]
* @date 2023-11
*
*
*
*
*
*
*/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Room.h"
#include "RoomList.h"
#include "Puzzle.h"
#include "Item.h"
/**
 * @class Game in Game.h "Game.h"
 * @details this class will handle
 * the majority of the game logic, i.e
 * the output the user will actually see
 * for future james, in this class
 * we will add a function to start the 
 * game, a function to output splash screens
 * a function to play the game
 * a function to build all of the npcs
 * a function to build all of the rooms
 * a list of all of the rooms (I may use 
 * another class to manage this)
 */
class Game {
 public:
  Game() {
    NPC dave("", "");
    NPC mick("", "");
    roomlist->insert(new DialogueRoom("Garden", "its a garden",
    {"", "", "Front Hall", "", "", ""}, dave));
    //Room* newRoom = new DialogueRoom("f", "f", {"", ""}, dave);
  }
  RoomList* setRoomList();


 private:
  RoomList* roomlist = new RoomList();
};


#endif
