//
//  Game.hpp
//  Tester
//
//  Created by James Huston on 2023-12-07.
//

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

    roomlist->insert(new DialogueRoom("Garden", "its a garden",
    {"", "", "Front Hall", "", "", ""}, dave));
 */
class Game {
 public:
  Game(std::string playerName = "Detective");

  virtual ~Game();

  void playGame();



 private:
  const int UP = 0, DOWN = 1, NORTH = 2, EAST = 3, SOUTH = 4, WEST = 5;

  Player* player;

  RoomNode* currentNode;
  RoomNode* previousNode;





  RoomList* roomlist = new RoomList();
  // Item declarations:
  Item* yellowKeyCard = new Item
  ("Key Card", "East Hallway", "It opens doors");

  Item* blueKeyCard = new Item
  ("Key Card", "North Hallway", "It opens doors");

  Item* redKeyCard = new Item
  ("Key Card", "West Hallway", "It opens doors");

  Item* knife = new Item
  ("It's a knife", "Garden End", "It kills people");

  Item* pictureFrame = new Item
  ("It's a picture", "Garden End", "Hey is that brent");

  Item* will = new Item
  ("It's a will", "Garden End", "Hey is that brent");

  Item* map = new Item
  ("Its a map of the building", "Everywhere", "unset");

  // Item puzzle declarations:
  ItemPuzzle* yellowItemPuzzle = new ItemPuzzle
  ("this lock requires a yellow key card", *yellowKeyCard);

  ItemPuzzle* blueItemPuzzle = new ItemPuzzle
  ("This lock requires a blue key card", *blueKeyCard);

  ItemPuzzle* redItemPuzzle = new ItemPuzzle
  ("This lock requires a red key card", *redKeyCard);

  // Dialogue Puzzle
  DialoguePuzzle* studyPuzzle = new DialoguePuzzle("a", "a");
  DialoguePuzzle* libraryPuzzle = new DialoguePuzzle("b", "b");
  DialoguePuzzle* atticPuzzle = new DialoguePuzzle("c", "c");

  // NPC declarations
  NPC* craig = new NPC("Craig", "Craig dialogue");
  NPC* steph = new NPC("Stephanie", "Steph dialogue");
  NPC* rose = new NPC("Rose", "Rose dialogue");
  NPC* brent = new NPC("Brent", "Brent dialogue");
  NPC* craig2 = new NPC("Craig", "Craig dialogue 2");

  void setCurrentNode(RoomNode* currentNode);

  void setPreviousNode(RoomNode* previousNode);

  RoomNode* getCurrentNode();

  RoomNode* getPreviousNode();

  void accuse();

  void inventory();

  void displaySplashScreen(int condition);

  char getRoomActionChoice();

  void moveRoom();

  void interact();

  std::vector<unsigned> getPathways();


  void listRoomOptions(std::vector<unsigned> pathways);

// void readData(std::string&, std::string&, std::string&
//             , std::string start, std::string end);

// void readData(std::string&, std::string&
//             , std::string start, std::string end);
};


#endif
