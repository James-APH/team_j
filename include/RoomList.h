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
    RoomNode(Room r);

    Room* getRoom();

    RoomNode* getUpNode();

    RoomNode* getDownNode();

    RoomNode* getNorthNode();

    RoomNode* getEastNode();

    RoomNode* getSouthNode();

    RoomNode* getWestNode();


    void setNodes(RoomNode* up, RoomNode* down, RoomNode* north
                , RoomNode* east, RoomNode* south, RoomNode* west);

  private:
  // up down nesw
    const Room* room;
    RoomNode* up;
    RoomNode* down;
    RoomNode* north;
    RoomNode* east;
    RoomNode* south;
    RoomNode* west;
};

class RoomList {
    RoomList();

    void insert(Room* room);

    bool RoomsDone();

    
  private:
    RoomNode* head;
    RoomNode* tail;
    int amountOfRooms;

};


#endif //ROOMLIST_H_INCLUDED