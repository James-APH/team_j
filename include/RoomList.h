/**
 * @author James Huston [huston@uleth.ca]
 * @date 12/2023
 * 
 * 
*/

#ifndef ROOMLIST_H_INCLUDED
#define ROOMLIST_H_INCLUDED

#include "Room.h"

class RoomNode {
  public:
   /**
    * @brief constructor for RoomNodes
    * @param r pointer to Room object
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
    * @brief setters for connected rooms:
    * @param [in] up the room ? above the current room
    * @param [in] down the room ? below the current room
    * @param [in] north the room ? north to the current room
    * @param [in] east the room ? east of the current room
    * @param [in] south the room ? south of the current room
    * @param [in] west the room ? west of the current room
    */

    /**
     * @brief sets the current rooms up pointer
     * @param up the pointer to the room above the current
     * 
    */
    void setUpNode(RoomNode* up);

    /**
     * @brief sets the current rooms down pointer
     * @param down the pointer to the room below the current
     * 
    */
    void setDownNode(RoomNode* down);

    /**
     * @brief sets the current rooms north pointer
     * @param north the pointer to the room north of the current
     * 
    */
    void setNorthNode(RoomNode* north);

    /**
     * @brief sets the current rooms east pointer
     * @param east the pointer to the room east of the current
     * 
    */
    void setEastNode(RoomNode* east);

    /**
     * @brief sets the current rooms south pointer
     * @param south the pointer to the room south of the current
     * 
    */
    void setSouthNode(RoomNode* south);

    /**
     * @brief sets the current rooms west pointer
     * @param west the pointer to the room west of the current
     * 
    */
    void setWestNode(RoomNode* west);

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
    */
    void insert(Room* room);

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

    
  private:
    RoomNode* head;
    RoomNode* tail;

};

#endif //ROOMLIST_H_INCLUDED