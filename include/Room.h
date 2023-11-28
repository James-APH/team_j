/**
* @Author James Huston [huston@uleth.ca]
* @date 2023-11
*/

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
#include <Item.h>
#include <Puzzle.h>
#include <Character.h>

/**
 * @class Room in Room.h "Room.h"
 * @brief 
 */
class Room {
 public:
  Room(std::string title, std::string description);
  ~Room();
  virtual RoomState& getState() = 0;
  virtual void addPlayerToRoom(const Player& player) = 0;
  virtual void removePlayerFromRoom() = 0;
  virtual void playerTakeAction() = 0;
  virtual void display() = 0;

 private:
  std::string title;
  std::string description;
  RoomState* state;
  Player* player;
  virtual void setState() = 0;
  virtual string toString() = 0;
};


/**
 * @class DialogueRoom in Room.h "Room.h"
 * @brief players will recieve hints and items
 * from npcs
 */
class DialogueRoom : Room {
 public:
  DialogueRoom(std::string title, std::string description
               , const NPC &fella);
  ~DialogueRoom();
  RoomState& getState();
  void addPlayerToRoom(const Player& player);
  void removePlayerFromRoom();
  void playerTakeAction();
  void display();

 private:
  std::string title;
  std::string description;
  NPC* fella;
  RoomState* state;
  Player* player;

  void setState();
  string toString();
};

/**
 *
 *
 */
class PuzzleRoom : Room {
 public:
  PuzzleRoom(std::string title, std::string description, std::string puzzleDescription);
  ~PuzzleRoom();
  RoomState& getState();
  void addPlayerToRoom(const Player& player);
  void removePlayerFromRoom();
  void playerTakeAction();
  void display();

 private:
  std::string title;
  std::string description;
  Puzzle* puzzle;
  RoomState* state;
  Player* player;

  void setState();
  string toString();
};

class ThinkingPuzzleRoom : Room {
 public:
  ThinkingPuzzleRoom(std::string title
               , std::string description
               , std::string puzzleDescription
               , const DialoguePuzzle &dp);
  ~ThinkingPuzzleRoom();
  RoomState& getState();
  void addPlayerToRoom(const Player& player);
  void removePlayerFromRoom();
  void playerTakeAction();
  void display();

 private:
  std::string title;
  std::string description;
  Puzzle* puzzle;
  RoomState* state;
  Player* player;

  void setState();
  string toString();
};



class ItemPuzzleRoom : Room {
 public:
  ItemPuzzleRoom(std::string title
               , std::string description
               , std::string puzzleDescription
               , const ItemPuzzle &ip);
  ~ItemPuzzleRoom();
  RoomState& getState();
  void addPlayerToRoom(const Player& player);
  void removePlayerFromRoom();
  void playerTakeAction();
  void display();

 private:
  std::string title;
  std::string description;
  Puzzle* puzzle;
  RoomState* state;
  Player* player;

  void setState();
  string toString();
};

#endif
