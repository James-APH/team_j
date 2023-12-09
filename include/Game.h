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
  /**
   * @brief default constructor
   * @param [in] playerName the name of the Player
  */
  Game(std::string playerName = "Detective");

  /**
   * @brief destructor
  */
  virtual ~Game();

  /**
   * @brief function to initiate and run the game. 
  */
  void playGame();



 private:
  const int UP = 0, DOWN = 1, NORTH = 2, EAST = 3, SOUTH = 4, WEST = 5;

  Player* player;

  RoomNode* currentNode;





  RoomList* roomlist = new RoomList();
  // Item declarations:
  Item* yellowKeyCard = new Item
  ("YellowKeyCard", "East Hallway", "It opens doors");

  Item* blueKeyCard = new Item
  ("BlueKeyCard", "North Hallway", "It opens doors");

  Item* redKeyCard = new Item
  ("RedKeyCard", "West Hallway", "It opens doors");

  Item* knife = new Item
  ("It's a knife", "Garden End", "That crest look complicated (a rearing"
   " lion in front of crossed swords)");

  Item* pictureFrame = new Item
  ("It's a picture", "Garden End", "Hey is that brent standing beside Scott?");

  Item* will = new Item
  ("It's a will", "Garden End", "It was drafted a long time ago. Looks like"
   " Scott is the one to inherit everything");

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

  /**
   * @brief setter for currentNode
   * @param [in] current node the current room
   * @throw de_trop_nullptr if currentNode is nullptr
  */
  void setCurrentNode(RoomNode* currentNode);

  /**
   * @brief setter for previousNode
   * @param [in] previous node the previous room
   * 
  */
  void setPreviousNode(RoomNode* previousNode);

  /**
  * @brief getter for currentNode
  */
  RoomNode* getCurrentNode();

  /**
   * @brief getter for previousNode
  */
  RoomNode* getPreviousNode();

  /**
   * @brief function to allow player to make an
   * accusation.
  */
  void accuse();

  /**
   * @brief function to allow the user to interact with the inventory
  */
  void inventory();

  /**
   * @brief function to output a splash screen depending on
   *  what stage of the game they are on
   * @param [in] condition the number value corresponding to stage
   * 
  */
  void displaySplashScreen(int condition);

  char getRoomActionChoice();

  /**
   * @brief function to change the current room the player is in
  */
  void moveRoom();

  /**
   * @brief function to allow the user to interact with the room
  */
  void interact();

  /**
   * @brief function to get a list of rooms that the current one is
   * actually connected to.
  */
  std::vector<unsigned> getPathways();

  /**
   * @brief function to list the possible rooms the player could move to.
   * @param [in] pathways a list of unsigned values corresponding to the
   * rooms the current room is connected to.
   * @throw bad_input if an element in pathways is greater than 5.
  */
  void listRoomOptions(std::vector<unsigned> pathways);


  void setRoomState();
// void readData(std::string&, std::string&, std::string&
//             , std::string start, std::string end);

// void readData(std::string&, std::string&
//             , std::string start, std::string end);
};


#endif
