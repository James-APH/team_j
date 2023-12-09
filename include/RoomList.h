/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Parker Regier [tyre.regier@uleth.ca]
 * @date 2023-11
 */

#ifndef ROOMLIST_H_INCLUDED
#define ROOMLIST_H_INCLUDED

#include "Room.h"


class RoomNode {
 public:
  /**
   * @brief constructor for RoomNodes
   * @param r pointer to Room object
   * @throw de_trop_nullptr if r is nullptr
   */
  RoomNode(Room* r);


  /**
   * @brief destuctor
   */
  ~RoomNode();

  /**
   * @brief returns a pointer to a room
   * @return _room, a pointer to a room
   */
  Room* getRoom();

  /**
   * @brief returns a pointer to a possible room
   *  that is above the current room
   * @return if there is a room above the current room
   * returns a pointer to that room.
   * else returns nullptr
   */
  RoomNode* getUpNode();

  /**
   * @brief returns a pointer to a possible room
   * that is below the current room
   * @return if there is a room below the current room
   * returns a pointer to that room.
   * else returns nullptr
   */
  RoomNode* getDownNode();

  /**
   * @brief returns a pointer to a possible room
   * that is north of the current room.
   * @return if there is a room to the north of the current room
   * returns a pointer to that room.
   * else returns nullptr
   */
  RoomNode* getNorthNode();

  /**
   * @brief returns a pointer to a possible room
   * that is east of the current room.
   * @return if there is a room to the east of the current room
   * returns a pointer to that room.
   * else returns nullptr
   */
  RoomNode* getEastNode();

  /**
   * @brief returns a pointer to a possible room
   * that is south of the current room.
   * @return if there is a room to the south of the current room
   * returns a pointer to that room.
   * else returns nullptr
   *
   */
  RoomNode* getSouthNode();

  /**
   * @brief returns a pointer to a possible room
   * that is west of the current room.
   * @return if there is a room to the west of the current room
   * returns a pointer to that room.
   * else returns nullptr
   */
  RoomNode* getWestNode();

  /**
   * @brief setter for the next node on each roomNode
   * @details the pointers to other rooms cannot exist
   * until the other rooms are created, so on creation
   * of each node we set the previous nodes nextNode
   * pointer to the current and then to set all of the
   * up, down, north... pointers we loop through the singly
   * linked list.
   * @param[in] nextNode the nextNode in the list.
   */
  void setNextNode(RoomNode* nextNode);

  /**
   * @brief getter for next node
   * @return the next node in the linked list
   */
  RoomNode* getNextNode();

  /**
   * @brief sets the current rooms up pointer
   * @param [in] up the pointer to the room above the current
   * @throw de_trop_nullptr if up is nullptr
   */
    void setUpNode(RoomNode* up);

  /**
   * @brief sets the current rooms down pointer
   * @param [in] down the pointer to the room below the current
   * @throw de_trop_nullptr if up is nullptr
   */
  void setDownNode(RoomNode* down);

  /**
   * @brief sets the current rooms north pointer
   * @param [in] north the pointer to the room north of the current
   * @throw de_trop_nullptr if up is nullptr
   */
  void setNorthNode(RoomNode* north);

  /**
   * @brief sets the current rooms east pointer
   * @param [in] east the pointer to the room east of the current
   * @throw de_trop_nullptr if up is nullptr
   */
  void setEastNode(RoomNode* east);

  /**
   * @brief sets the current rooms south pointer
   * @param south the pointer to the room south of the current
   * @throw de_trop_nullptr if up is nullptr
   */
  void setSouthNode(RoomNode* south);

  /**
   * @brief sets the current rooms west pointer
   * @param west the pointer to the room west of the current
   * @throw de_trop_nullptr if up is nullptr
   */
  void setWestNode(RoomNode* west);

  /**
  * @brief sets the previousNode
  * @param previousNode the previousNode
  * @throw de_trop_nullptr if previousNode is nullptr
  */
  void setPreviousNode(RoomNode* previousNode);

  /**
   * @brief getter for previousNode
  */
  RoomNode* getPreviousNode();

 private:
  // up down nesw
  Room* room;
  RoomNode* up;
  RoomNode* down;
  RoomNode* north;
  RoomNode* east;
  RoomNode* south;
  RoomNode* west;
  RoomNode* next;
  RoomNode* previousNode;
};

class RoomList {
 public:
  /**
   * @brief default constructor
   */
  RoomList();

  /**
   * @brief destructor
   */
  ~RoomList();

  /**
   * @brief inserts new rooms into the list
   * @param[in] room the room to be added
   * @throw de_trop_nullptr if room is nullptr
   */
  void insert(Room* room);


  /**
   * @brief makes the room list into a circly linked list
  */
  void circley();


  /**
   * @brief method to be called once all nodes have been set to
   * make the connections between each node.
   */
  void solidify();

  /**
   * @brief checks if all of the rooms have been explored
   * @return true if all of the rooms have been explored
   * false otherwise.
   */
  bool RoomsDone();

  /**
   * @brief getter for head
  */
  RoomNode* getHead();

 private:
  const int UP = 0, DOWN = 1, NORTH = 2, EAST = 3, SOUTH = 4, WEST = 5;
  RoomNode* head;
  RoomNode* tail;
};

#endif //ROOMLIST_H_INCLUDED

