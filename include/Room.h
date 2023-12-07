/**
 * @author James Huston [huston@uleth.ca]
 * @date 2023-11
 */

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
#include <vector>

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
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   */
  Room(std::string title = "room"
       , std::string description = "description"
       , const std::vector<std::string>& connections = {""});

  /**
   * @brief destructor
   */
  virtual ~Room();

  /**
   * @brief getter for RoomState
   * @return the state of the room
   */
  virtual RoomState &getState();

  /**
   * @brief returns the title of the room
   * @return title the title of the room
  */
  virtual std::string getTitle() const;

  /**
   * @brief returns the list of all the rooms the room
   * connects to
   * @return list of rooms the room connects to
  */
  virtual std::vector<std::string> getConnections();

  /**
   * @brief getter for roomtype
   * @return roomtype the type of room the current is
  */
  virtual GameTypes::RoomTypes getRoomType() const;

  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * -> cannot be const, in the case that the user picks up an item.
   * or uses an item.
   * @param in [player] a reference to player to access their data
   * @return true if the player did the action i.e. used item,
   * talked to an npc, solved a thinking puzzle, took an item.
  */
  virtual bool playerTakeAction(Player* player) = 0;

  /**
   * @brief descibes/shows the room to the player
   */
  virtual void display() const = 0;

 protected:
  std::string title;
  std::string description;
  std::vector<std::string> connections;
  RoomState* state;
  GameTypes::RoomTypes roomtype;

  /**
   * @brief depending on the players interactions with
   * the room sets the state of the room accordingly.
   * @param[in] state the new state of the room;
   */
  void setState(RoomState *state);
};

/**
 * @class DialogueRoom in Room.h "Room.h"
 * @brief players will recieve hints and items
 * from npcs
 */
class DialogueRoom : public Room {
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
               , const std::vector<std::string>& connections
               , const NPC &fella);

  /**
   * @brief destructor
   */
  virtual ~DialogueRoom();


  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * @param in [player] a reference to player to access their data
   * @return true if the player did the action i.e.talked to an npc
   */
  bool playerTakeAction(Player* player);

  /**
   * @brief descibes/shows the room to the player
   */
  void display() const;

 private:
  NPC *fella;
};

/**
 * @class ThinkingPuzzleRoom in Room.h "Room.h"
 * @brief class to hold puzzles that require players
 * to use their brains
 */
class ThinkingPuzzleRoom : public Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] dp the object for the dialogue puzzle
   */
  ThinkingPuzzleRoom(std::string title
                     , std::string description
                     , const std::vector<std::string>& connections
                     , const DialoguePuzzle &dp);

  /**
   * @brief destructor
   */
  virtual ~ThinkingPuzzleRoom();


  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * @param in [player] a reference to player to access their data
   * @return true if the player did the right action i.e. entered the correct input
   * false otherwise
  */
  bool playerTakeAction(Player* player);

  /**
   * describes/shows the room to the player
   */
  void display() const;

 private:
  DialoguePuzzle* dp;
};

/**
 * @class ItemPuzzleRoom in Room.h "Room.h"
 * @brief class to hold puzzles that require players
 * to explore the game
 */
class ItemPuzzleRoom : public Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] ip the object of an item puzzle for the room
   */
  ItemPuzzleRoom(std::string title
                 , std::string description
                 , const std::vector<std::string>& connections
                 , const ItemPuzzle &ip);

  /**
   * @brief destructor
   */
  virtual ~ItemPuzzleRoom();

  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * @param in [player] a reference to player to access their data
   * @return true if the player did the action i.e. input the correct item
   * false otherwise
  */
  bool playerTakeAction(Player* player);

  /**
   * @brief describes/shows the room to the player
   */
  void display() const;

 private:
  ItemPuzzle* ip;
};

/**
 * @class ItemRoom in Room.h "Room.h"
 * @brief class of room where players 'find' items
 */
class ItemRoom : public Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] ip the object of an item puzzle for the room
   */
  ItemRoom(std::string title
                 , std::string description
                 , const std::vector<std::string>& connections
                 , const Item &i);

  /**
   * @brief destructor
   */
  virtual ~ItemRoom();

  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * @param in [player] a reference to player to access their data
   * @return true if the player did the action i.e. pick up an item
  */
  bool playerTakeAction(Player* player);

  /**
   * @brief describes/shows the room to the player
   */
  void display() const;

 private:
  Item* item;

  /**
   * @brief function to give the player items
   */
  Item& giveItem();
};

#endif
