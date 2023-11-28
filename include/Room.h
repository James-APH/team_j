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
  Room(std::string title, std::string description);

  /**
   * @brief destructor
   */
  ~Room();

  /**
   * @brief getter for RoomState
   * @return the state of the room
   */
  virtual RoomState &getState() = 0;

  /**
   * @brief adds the player to the room, so they
   * can either talk to npc's or manipulate puzzles
   * @param [in] player the player
   */
  virtual void addPlayerToRoom(const Player &player) = 0;

  /**
   * @brief removes a player from a room when they leave
   * so that they do not exist in 9 rooms at once.
   */
  virtual void removePlayerFromRoom() = 0;

  /**
   * @brief allows player to interact with the room
   */
  virtual void playerTakeAction() = 0;

  /**
   * @brief descibes/shows the room to the player
   */
  virtual void display() = 0;

 private:
  std::string title;
  std::string description;
  RoomState *state;
  Player *player;

  /**
   * @brief depending on the players interactions with
   * the room sets the state of the room accordingly.
   */
  virtual void setState() = 0;

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
class DialogueRoom : Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of
   * the room.
   * @param [in] fella the NPC that exists in the
   * room
   */
  DialogueRoom(std::string title, std::string description, const NPC &fella);

  /**
   * @brief destructor
   */
  ~DialogueRoom();

  /**
   * @brief getter for RoomState
   * returns the state of the room
   */
  RoomState &getState();

  /**
   * @brief adds the player to the room, so they
   * can either talk to npc's or manipulate puzzles
   * @param [in] player the player
   */
  void addPlayerToRoom(const Player &player);

  /**
   * @brief removes a player from a room when they leave
   * so that they do not exist in 9 rooms at once.
   */
  void removePlayerFromRoom();

  /**
   * @brief allows player to interact with the room
   */
  void playerTakeAction();

  /**
   * @brief descibes/shows the room to the player
   */
  void display();

 private:
  std::string title;
  std::string description;
  NPC *fella;
  RoomState *state;
  Player *player;

  /**
   * @brief depending on the players interactions with
   * the room sets the state of the room accordingly.
   */
  void setState();

  /**
   * @brief puts all of room information into a
   * string
   * @return string the string of room information
   */
  std::string toString();
};

/**
 * @class PuzzleRoom in Room.h "Room.h"
 * @brief derived class from room, parent
 * class for ThinkingPuzzleRoom and
 * ItemPuzzleRoom
 */
class PuzzleRoom : Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   */
  PuzzleRoom(std::string title, std::string description);

  /**
   * @brief destructor
   */
  ~PuzzleRoom();

  /**
   * @brief getter for RoomState
   * returns the state of the room
   */
  RoomState &getState();

  /**
   * @brief adds the player to the room, so they
   * can manipulate puzzles
   * @param [in] player the player
   */
  void addPlayerToRoom(const Player &player);

  /**
   * @brief removes a player from a room when they leave
   * so that they do not exist in nine rooms at once.
   */
  void removePlayerFromRoom();

  /**
   * @brief allows the player to interact with the room 
   * (puzzles, npcs)
   */
  void playerTakeAction();

  /**
   * @brief describes / shows the room to the player
   *
   */
  void display();

 private:
  std::string title;
  std::string description;
  Puzzle *puzzle;
  RoomState *state;
  Player *player;

  /**
   * @brief depending on the players interactions 
   * with the room, sets the state of the room accordingly.
   */ 
  void setState();

  /**
   * @brief puts all of room information into a string
   * @return string the string of room information.
   */
  std::string toString();
};

/**
 * @class ThinkingPuzzleRoom in Room.h "Room.h"
 * @brief class to hold puzzles that require players
 * to use their brains
 */
class ThinkingPuzzleRoom : Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] dp the object for the dialogue puzzle
   */
  ThinkingPuzzleRoom(std::string title, std::string description
                     , const DialoguePuzzle &dp);

  /**
   * @brief destructor
   */
  ~ThinkingPuzzleRoom();

  /**
   * @brief getter for RoomState
   * returns the state of the room
   */
  RoomState &getState();

  /**
   * @brief adds the player to the room, so they 
   * can manipulate puzzles
   * @param [in] player the player
   */
  void addPlayerToRoom(const Player &player);

  /**
   * @brief removes the player from the room
   */
  void removePlayerFromRoom();

  /**
   * @brief allows the player to interact with the room
   */
  void playerTakeAction();

  /**
   * describes/shows the room to the player
   */
  void display();

 private:
  std::string title;
  std::string description;
  Puzzle *puzzle;
  RoomState *state;
  Player *player;

  /**
   * @brief depending on the players interactions with
   * the room sets the state of the room accordingly
   */
  void setState();

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
class ItemPuzzleRoom : Room {
 public:
  /**
   * @brief constructor
   * @param [in] title the title of the room
   * @param [in] description the description of the room
   * @param [in] ip the object of an item puzzle for the room
   */
  ItemPuzzleRoom(std::string title, std::string description
                 , const ItemPuzzle &ip);

  /**
   * @brief destructor
   */
  ~ItemPuzzleRoom();

  /**
   * @brief getter for RoomState
   * @return the state of the room
   */
  RoomState &getState();

  /**
   * @brief adds the player to the room, so they
   * can interact with the puzzle
   * @param [in] player the player
   */
  void addPlayerToRoom(const Player &player);

  /**
   * @brief removes the player from the room
   */
  void removePlayerFromRoom();

  /**
   * @brief allows the player to interact with the room
   */
  void playerTakeAction();

  /**
   * @brief describes/shows the room to the player
   */
  void display();

 private:
  std::string title;
  std::string description;
  Puzzle *puzzle;
  RoomState *state;
  Player *player;

  /**
   * @brief depending on the players interactions with
   * the room sets the state of the room accordingly
   */
  void setState();

  /**
   * @brief puts all of room information into a string
   * @return string the string of room information
   */
  std::string toString();
};

#endif
