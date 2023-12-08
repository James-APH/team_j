/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @date 2023-11
 */

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <gtest/gtest.h>

#include "Item.h"
#include "Puzzle.h"
#include "Character.h"
#include "RoomState.h"
#include "Room.h"
#include "GameTypes.h"

//I dunno if these tests will even work but its something

TEST(RoomTest, defaultConstructorTest) {
    Room* theRoom = new Room();
    EXPECT_EQ(theRoom->getTitle(), "room");
    delete theRoom;
}

TEST(RoomTest, changeRoomStateTest) {
    Room* theRoom = new Room("Lab", "This is a Lab", {""});
    FullyExploredRoom* room = new FullyExploredRoom();
    ExploredRoom* room2 = new ExploredRoom();
    UnexploredRoom* room3 = new UnexploredRoom();
    theRoom->setState(room);
    EXPECT_EQ(theRoom->getState(), room);
    theRoom->setState(room2);
}

