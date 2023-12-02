/**
 * @author James Huston [huston@uleth.ca]
 * @date 11/2023
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

   
    void setUpNode(RoomNode* up);

    void setDownNode(RoomNode* down);

    void setNorthNode(RoomNode* north);

    void setEastNode(RoomNode* east);

    void setSouthNode(RoomNode* south);

    void setWestNode(RoomNode* west);

  protected:
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


    void setAmountOfRooms(int rooms);

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
    int amountOfRooms;

};

#endif //ROOMLIST_H_INCLUDED