/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Parker Regier [tyre.regier@uleth.ca]
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
   * @param [in] connections a list of the rooms that 
   * "this" room is connected to
   * @throw empty_string if title is empty
   * @throw empty_string if description is empty
   * @throw invalid_size if connections size != 6
   * @throw empty_string if all strings in connections
   * are empty strings.
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
   * @brief adds the player to the current room
   * @param [in] player the player in question
   * @throw de_trop_nullptr if player is nullptr
  */
  void playerEnterRoom(Player* player);


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
   * @brief sets the state to explored, when the player enters a room
  */
  void entered();

  /**
   * @brief getter for roomtype
   * @return roomtype the type of room the current is
  */
  virtual GameTypes::RoomTypes getRoomType() const;

  virtual bool isDone();
  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * -> cannot be const, in the case that the user picks up an item.
   * or uses an item.
   * @param in [player] a reference to player to access their data
   * @return true if the player did the action i.e. used item,
   * talked to an npc, solved a thinking puzzle, took an item.
  */
  virtual bool playerTakeAction() = 0;

  /**
   * @brief descibes/shows the room to the player
   */
  virtual void display() const = 0;

 protected:
  Player* player;
  std::string title;
  std::string description;
  std::vector<std::string> connections;
  RoomState* state;
  GameTypes::RoomTypes roomtype;

  /**
   * @brief depending on the players interactions with
   * the room sets the state of the room accordingly.
   * @param[in] state the new state of the room;
   * @throw de_trop_nullptr if state is nullptr
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
   * @param [in] description the description of the room.Player *player
   * @param [in] connections a list of the rooms that 
   * "this" room is connected to
   * @param [in] fella the NPC that exists in the
   * room
   * @throw empty_string if title is empty
   * @throw empty_string if description is empty
   * @throw invalid_size if connections size != 6
   * @throw bad_input if all strings in connections
   * are empty strings.
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
   * @return true if the player did the action i.e.talked to an npc
   */
  bool playerTakeAction();

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
   * @param [in] connections a list of the rooms that 
   * "this" room is connected to
   * @param [in] dialoguePuzzle the object for the dialogue puzzle
   * @throw empty_string if title is empty
   * @throw empty_string if description is empty
   * @throw invalid_size if connections size != 6
   * @throw empty_string if all strings in connections
   * are empty strings.
   */
  ThinkingPuzzleRoom(std::string title
                     , std::string description
                     , const std::vector<std::string>& connections
                     , const DialoguePuzzle &dialoguePuzzle);

  /**
   * @brief destructor
   */
  virtual ~ThinkingPuzzleRoom();


  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * @return true if the player did the right action i.e. entered the correct input
   * false otherwise
  */
  bool playerTakeAction();

  /**
   * describes/shows the room to the player
   */
  void display() const;

 private:
  DialoguePuzzle* dialoguePuzzle;
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
   * @param [in] connections a list of the rooms that 
   * "this" room is connected to
   * @param [in] ip the object of an item puzzle for the room
   * @throw empty_string if title is empty
   * @throw empty_string if description is empty
   * @throw invalid_size if connections size != 6
   * @throw empty_string if all strings in connections
   * are empty strings.
   */
  ItemPuzzleRoom(std::string title
                 , std::string description
                 , const std::vector<std::string>& connections
                 , const ItemPuzzle &itemPuzzle);

  /**
   * @brief destructor
   */
  virtual ~ItemPuzzleRoom();

  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * @return true if the player did the action i.e. input the correct item
   * false otherwise
  */
  bool playerTakeAction();

  /**
   * @brief describes/shows the room to the player
   */
  void display() const;

 private:
  ItemPuzzle* itemPuzzle;
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
   * @param [in] connections a list of the rooms that 
   * "this" room is connected to
   * @param [in] item the object of an item puzzle for the room
   * @throw empty_string if title is empty
   * @throw empty_string if description is empty
   * @throw invalid_size if connections size != 6
   * @throw emptry_string if all strings in connections
   * are empty strings.
   */
  ItemRoom(std::string title
                 , std::string description
                 , const std::vector<std::string>& connections
                 , const Item &item);

  /**
   * @brief destructor
   */
  virtual ~ItemRoom();

  /**
   * @brief a function to allow the player to manipulate data in the rooms
   * @return true if the player did the action i.e. pick up an item
  */
  bool playerTakeAction();

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
