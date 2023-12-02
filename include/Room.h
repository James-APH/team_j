/**
 * @Author James Huston [huston@uleth.ca]
 * @date 2023-11
 */

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>

#include "Item.h"
#include "Puzzle.h"
#include "Character.h"
#include "RoomState.h"
#include "GameTypes.h"


/**
 * @class Room in Room.h "Room.h"
 * @brief abstract super class for Room types
 */
class Room {
 public:
  /**
   * @brief default constructor
   */
  Room();

  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   */
  Room(std::string title
       , std::string description
       , const std::vector<std::string> connections);

  /**
   * @brief destructor
   */
  ~Room();

  /**
   * @brief getter for RoomState
   * @return the state of the room
   */
  RoomState &getState();

  /**
   * @brief returns the title of the room
   * @return title the title of the room
  */
  std::string getTitle();

  /**
   * @brief returns the list of all the rooms the room
   * connects to
   * @return list of rooms the room connects to
  */
  std::vector<std::string> getConnections();

  /**
   * @brief getter for roomtype
   * @return roomtype the type of room the current is
  */
  GameTypes::RoomTypes getRoomType();

  /**
   * @brief descibes/shows the room to the player
   */
  virtual void display() = 0;

 protected:
  std::string title;
  std::string description;
  std::vector<std::string> connections;
  RoomState *state;
  GameTypes::RoomTypes roomtype;

  /**
   * @brief depending on the players interactions with
   * the room sets the state of the room accordingly.
   * @param[in] state the new state of the room;
   */
  void setState(RoomState *state);

  /**
   * @brief puts all of room information into a
   * string
   * @return string the string of room information
   */
  virtual std::string toString() = 0;
};

/**
 * @class DialogueRoom in Room.h "Room.h"
 * @brief players will recieve hints and items
 * from npcs
 */
class DialogueRoom : protected Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of
   * the room.
   * @param [in] fella the NPC that exists in the
   * room
   */
  DialogueRoom(std::string title
               , std::string description
               , const std::vector<std::string> connections
               , const NPC &fella);

  /**
   * @brief destructor
   */
  ~DialogueRoom();

  /**
   * @brief allows player to talk to the npc.
   */
  void converse();

  /**
   * @brief descibes/shows the room to the player
   */
  void display();

 private:
  NPC *fella;

  /**
   * @brief puts all of room information into a
   * string
   * @return string the string of room information
   */
  std::string toString();
};

/**
 * @class ThinkingPuzzleRoom in Room.h "Room.h"
 * @brief class to hold puzzles that require players
 * to use their brains
 */
class ThinkingPuzzleRoom : protected Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] dp the object for the dialogue puzzle
   */
  ThinkingPuzzleRoom(std::string title
                     , std::string description
                     , const std::vector<std::string> connections
                     , const DialoguePuzzle &dp);

  /**
   * @brief destructor
   */
  ~ThinkingPuzzleRoom();


  /**
   * @brief allows the player to
   * attempt to solve the puzzle
   * @param answer, the answer to the puzzle
   */
  void playerTryPuzzle(std::string answer);

  /**
   * describes/shows the room to the player
   */
  void display();

 private:
  DialoguePuzzle* dp;

  /**
   * @brief puts all of the rooms information into a string
   * @return string the string of room information
   */
  std::string toString();
};

/**
 * @class ItemPuzzleRoom in Room.h "Room.h"
 * @brief class to hold puzzles that require players
 * to explore the game
 */
class ItemPuzzleRoom : protected Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] ip the object of an item puzzle for the room
   */
  ItemPuzzleRoom(std::string title
                 , std::string description
                 , const std::vector<std::string> connections
                 , const ItemPuzzle &ip);

  /**
   * @brief destructor
   */
  ~ItemPuzzleRoom();

  /**
   * @brief allows the player to interact with the room
   */
  void playerTakeAction();

  /**
   * @brief describes/shows the room to the player
   */
  void display();

 private:
  ItemPuzzle* ip;


  /**
   * @brief puts all of room information into a string
   * @return string the string of room information
   */
  std::string toString();
};

/**
 * @class ItemRoom in Room.h "Room.h"
 * @brief class of room where players 'find' items
 */
class ItemRoom : protected Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] ip the object of an item puzzle for the room
   */
  ItemRoom(std::string title
                 , std::string description
                 , const std::vector<std::string> connections
                 , const Item &i);

  /**
   * @brief destructor
   */
  ~ItemRoom();

  /**
   * @brief allows the player to input
   * one of their items to solve the rooms puzzle
   */
  void playerUseItem(const Item &i);

  /**
   * @brief describes/shows the room to the player
   */
  void display();

 private:
  Item* item;

  /**
   * @brief function to give the player items
   */
  Item& giveItem();

  /**
   * @brief puts all of room information into a string
   * @return string the string of room information
   */
  std::string toString();
};

#endif