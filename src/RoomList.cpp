/**
 * @author James Huston [huston@uleth.ca]
 * @date 12/2023
 */

#include <vector>
#include <algorithm>

#include "Room.h"
#include "RoomList.h"
#include "RoomState.h"


RoomNode::RoomNode(Room *r) {
    this->room = r;
    up = nullptr;
    down = nullptr;
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;
    next = nullptr;
}

RoomNode::~RoomNode() {
    if (room != nullptr)
        delete room;
    up = nullptr;
    down = nullptr;
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;
    next = nullptr;
}

Room *RoomNode::getRoom() {
    return room;
}

RoomNode *RoomNode::getUpNode() {
    return up;
}

RoomNode *RoomNode::getDownNode() {
    return down;
}

RoomNode *RoomNode::getNorthNode() {
    return north;
}

RoomNode *RoomNode::getEastNode() {
    return east;
}

RoomNode *RoomNode::getSouthNode() {
    return south;
}

RoomNode *RoomNode::getWestNode() {
    return west;
}

void RoomNode::setUpNode(RoomNode *up) {
    this->up = up;
}

void RoomNode::setDownNode(RoomNode *down) {
    this->down = down;
}

void RoomNode::setNorthNode(RoomNode *north) {
    this->north = north;
}

void RoomNode::setEastNode(RoomNode *east) {
    this->east = east;
}

void RoomNode::setSouthNode(RoomNode *south) {
    this->south = south;
}

void RoomNode::setWestNode(RoomNode *west) {
    this->west = west;
}

void RoomNode::setNextNode(RoomNode *next) {
    this->next = next;
}

RoomNode *RoomNode::getNextNode() {
    return next;
}



RoomList::RoomList() {
    head = nullptr;
    tail = nullptr;
}

RoomList::~RoomList() {
    RoomNode *current = head;
    while (current != nullptr) {
        current = current->getNextNode();
    }
}

void RoomList::insert(Room *room) {
    RoomNode *temp = new RoomNode(room);
    if (head == nullptr) {
        temp->setNextNode(nullptr);
        head = temp;
        tail = temp;
    } else {
        temp->setNextNode(nullptr);
        tail->setNextNode(temp);
        tail = temp;
    }
}

void RoomList::circley() {
	auto start = head;
	while (start->getNextNode() != nullptr) {
		start = start->getNextNode();
	}
	if (start->getNextNode() == nullptr) {
		start->setNextNode(head);
	}
}

void RoomList::solidify() {
	RoomNode* current = head;
	do {
		std::vector<std::string> tempCons;
		for (auto a : current->getRoom()->getConnections()) {
			tempCons.push_back(a);
		}
		RoomNode* temp = current->getNextNode();
		do {
			std::string tempTitle = temp->getRoom()->getTitle();
            auto a = (std::find(tempCons.begin(), tempCons.end(), tempTitle));
            int index = a - tempCons.begin();
            switch(index) {
                case 0: 
                    current->setUpNode(temp);
                break;
                case 1: 
                    current->setDownNode(temp);
                break;
                case 2:
                    current->setNorthNode(temp);
                break;
                case 3:
                    current->setEastNode(temp);
                break;
                case 4:
                    current->setSouthNode(temp);
                break;
                case 5:
                    current->setWestNode(temp);
                break;
            }		
			temp = temp->getNextNode();
		} while (temp != current);
		
		current = current->getNextNode();
	} while (current != head);	
}

bool RoomList::RoomsDone() {
    RoomNode *current = head;
    while (current != nullptr) {
        if (!(current->getRoom()->getState().isExplored() &&
            current->getRoom()->getState().roomDone()))
            return false;
        current = current->getNextNode();
    }
    return true;
}

RoomNode *RoomList::getHead() {
    return head;
}
