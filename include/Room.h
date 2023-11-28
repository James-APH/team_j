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
  /**
   * @brief default constructor
   */
  virtual Room();

  /**
   * @brief constructor
   * @detail by default sets the player to nullptr
   * sets the state to unexplored.
   * @param title the title of the room
   * @param description the description of the room
   * @throw bad_input if title is empty
   * @throw bad_input if description is empty
   */
  virtual Room(std::string title
               , std::string description);
  
  /**
   * @brief destructor
   */
  virtual ~Room();

  /**
   * @brief outputs the attributes of a room
   */
  virtual void display();

  /**
   * @brief
   */
  virtual RoomState& getState();

  /**
   * 
   */
  virtual void addPlayerToRoom(const Player &player);

  /**
   * @brief function to getInput from the player
   * called after display
   * @return char
   * @detail, will either return 
   * q for quit game,
   * n for next room
   * b for previous room
   * ...more may be added
   * in the case of puzzle 
   * p for puzzle
   * this function will call another inside of player
   * to get their input
   */
  virtual char getPlayerInput();

  
 private:
  std::string title;
  std::string description;
  RoomState* _state;
  Player* player;

  virtual void setState();

  /**
   * @brief puts the attributes of a room into a string
   * @return string the string of room attributes
   */
  virtual std::string toString();

};

/**
 * @class PuzzleRoom in Room.h "Room.h"
 * @brief
 */
class PuzzleRoom : Room {
 public:
  PuzzleRoom(std::string title
             , std::string roomDescription
             , std::string puzzleDescription);

  ~PuzzleRoom();

  virtual display();
 
 private:
  Puzzle* puzzle;

  virtual std::string toString();
};

/**
 * @class ThinkingPuzzleRoom in Room.h "Room.h"
 * @brief tells the details of the room and 
 */
class ThinkingPuzzleRoom : PuzzleRoom {
 public:
  ThinkingPuzzleRoom(std::string title
                     , std::string roomDescription
                     , std::string puzzleDescription
                     , const std::string expectedInput);

  ~ThinkingPuzzleRoom();

  void display();

 private:
  std::string expectedInput;

  std::string toString();
};

/**
 * @class ItemPuzzleRoom in Room.h "Room.h"
 * @brief
 */
class ItemPuzzleRoom : PuzzleRoom {
 public:
  ItemPuzzleRoom(std::string title
                 , std::string roomDescription
                 , std::string puzzleDescription
                 , const ItemPuzzle &ip, const Item &item);
  
  ~ItemPuzzleRoom();

  void display();
  

 private:
  Item* item;

  std::string toString();
};

/**
 * @class DialogueRoom in Room.h "Room.h"
 * @brief
 */
class DialogueRoom : Room {
 public:
  DialogueRoom(std::string title
               , std::string roomDescription
               , std::string dialogue);

 ~ItemPuzzleRoom();

 void display();


 private:
  NPC* fella;

 std::string toString();
};





#endif
