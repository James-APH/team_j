/**
* @author James Huston [huston@uleth.ca]
* @author Raven Huery [raven.huery@uleth.ca]
* @date 12/2023
*/


#include "RoomState.h"
#include <gtest/gtest.h>

TEST(RoomStateTest, FullyExploredIsExploredTest) {
    FullyExploredRoom* room = new FullyExploredRoom();
    EXPECT_EQ(room->isExplored(), true);
    delete room;
}

TEST(RoomStateTest, FullyExploredIsDoneTest) {
    FullyExploredRoom* room = new FullyExploredRoom();
    EXPECT_EQ(room->roomDone(), true);
    delete room;
}

TEST(RoomStateTest, ExploredIsExploredTest) {
    ExploredRoom* room = new ExploredRoom();
    EXPECT_EQ(room->isExplored(), true);
    delete room;
}

TEST(RoomStateTest, ExploredIsDoneTest) {
    ExploredRoom* room = new ExploredRoom();
    EXPECT_EQ(room->roomDone(), false);
    delete room;
}

TEST(RoomStateTest, UnexploredIsExploredTest) {
    UnexploredRoom* room = new UnexploredRoom();
    EXPECT_EQ(room->isExplored(), false);
    delete room;
}

TEST(RoomStateTest, UnexploredIsDoneTest) {
    UnexploredRoom* room = new UnexploredRoom();
    EXPECT_EQ(room->roomDone(), false);
    delete room;
}


