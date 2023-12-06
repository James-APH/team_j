/**
 * @author James Huston [huston@uleth.ca]
 * @date 12/2023
 *
 */

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
#include <vector>


#include "Room.h"
#include "RoomList.h"
#include "Puzzle.h"
#include "Item.h"
#include "Character.h"

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
 * NPC dave("", "");
    NPC mick("", "");
    roomlist->insert(new DialogueRoom("Garden", "its a garden",
    {"", "", "Front Hall", "", "", ""}, dave));
 */
class Game {
 public:
  Game();

  ~Game();

  void playGame();



 private:
  RoomList* roomlist = new RoomList();
  std::vector<NPC*> npcList;
  std::vector<Puzzle*> puzzleList;
  std::vector<Item*> itemList;

  void displaySplashScreen();

  void setRoomList();

  void setItems();

  void setPuzzles();

  void setNPCs();
  
  void readData(std::string&, std::string&, std::string&, std::string start, std::string end);

  void readData(std::string&, std::string&, std::string start, std::string end);
};


#endif
