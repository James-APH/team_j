/**
 * @author James Huston [huston@uleth.ca]
 * @date 12/2023
 *
 *
 */

#include <vector>
#include <algorithm>

#include "Room.h"
#include "RoomList.h"
#include "RoomState.h"

RoomNode::RoomNode(Room *r)
{
    this->room = r;
}

RoomNode::~RoomNode()
{
    if (room != nullptr)
        delete room;
    up = nullptr;
    down = nullptr;
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;
}

Room *RoomNode::getRoom()
{
    return room;
}

RoomNode *RoomNode::getUpNode()
{
    return up;
}

RoomNode *RoomNode::getDownNode()
{
    return down;
}

RoomNode *RoomNode::getNorthNode()
{
    return north;
}

RoomNode *RoomNode::getEastNode()
{
    return east;
}

RoomNode *RoomNode::getSouthNode()
{
    return south;
}

RoomNode *RoomNode::getWestNode()
{
    return west;
}

void RoomNode::setUpNode(RoomNode *up)
{
    this->up = up;
}

void RoomNode::setDownNode(RoomNode *down)
{
    this->down = down;
}

void RoomNode::setNorthNode(RoomNode *north)
{
    this->north = north;
}

void RoomNode::setEastNode(RoomNode *east)
{
    this->east = east;
}

void RoomNode::setSouthNode(RoomNode *south)
{
    this->south = south;
}

void RoomNode::setWestNode(RoomNode *west)
{
    this->south = south;
}

void RoomNode::setNextNode(RoomNode *nextNode)
{
    this->next = next;
}

RoomNode *RoomNode::getNextNode()
{
    return next;
}

RoomList::RoomList()
{
    head = nullptr;
    tail = nullptr;
}

RoomList::~RoomList()
{
    RoomNode *current = head;
    while (current != nullptr)
    {

        current = current->getNextNode();
    }
}

void RoomList::insert(Room *room)
{
    RoomNode *temp = new RoomNode(room);
    if (head == nullptr)
    {
        temp->setNextNode(nullptr);
        head = temp;
        tail = temp;
    }
    else
    {
        temp->setNextNode(nullptr);
        tail->setNextNode(temp);
        tail = temp;
    }
}

void RoomList::solidify()
{
    RoomNode *current = head;
    while (current != nullptr)
    {
        std::vector<std::string> _connections = current->getRoom()->getConnections();
        RoomNode *temp = current->getNextNode();
        while (temp != nullptr)
        {
            std::string tempTitle = temp->getRoom()->getTitle();
            if (std::find(_connections.begin(), _connections.end(), tempTitle) != _connections.end())
            {
                if (_connections[0] == tempTitle)
                {
                    current->setUpNode(temp);
                }
                else if (_connections[1] == tempTitle)
                {
                    current->setDownNode(temp);
                }
                else if (_connections[2] == tempTitle)
                {
                    current->setNorthNode(temp);
                }
                else if (_connections[3] == tempTitle)
                {
                    current->setEastNode(temp);
                }
                else if (_connections[4] == tempTitle)
                {
                    current->setWestNode(temp);
                }
                else
                {
                    current->setSouthNode(temp);
                }
            }
        }
        current = current->getNextNode();
    }
}

bool RoomList::RoomsDone()
{
    RoomNode *current = head;
    while (current != nullptr)
    {
        if (!(current->getRoom()->getState().isExplored() && current->getRoom()->getState().roomDone()))
            return false;
        current = current->getNextNode();
    }
    return true;
}
