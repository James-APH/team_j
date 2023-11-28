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
   * @param title the title of the room
   * @param description the description of the room
   * @throw bad_input if title is empty
   * @throw bad_input if description is empty
   */
  virtual Room(std::sring title, std::string description)
  
  /**
   * @brief destructor
   */
  virtual ~Room();

  /**
   * @brief outputs the attributes of a room
   */
  virtual void display();

 private:
  std::string title;
  std::string description;
  RoomState* _state;

  /**
   * @brief puts the attributes of a room into a string
   * @return string the string of room attributes
   */
  std::string toString();

};

/**
 * @class PuzzleRoom in Room.h "Room.h"
 * @brief
 */
class PuzzleRoom : Room {
 public:

 private:
};

/**
 * @class ThinkingPuzzleRoom in Room.h "Room.h"
 * @brief
 */
class ThinkingPuzzleRoom : PuzzleRoom {
 public:

 private:
};

/**
 * @class ItemPuzzleRoom in Room.h "Room.h"
 * @brief
 */
class ItemPuzzleRoom : PuzzleRoom {
 public:

 private:
};

/**
 * @class DialogueRoom in Room.h "Room.h"
 * @brief
 */
class DialogueRoom : Room {
 public:


 private:
};



#endif
