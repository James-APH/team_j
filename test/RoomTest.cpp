/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @date 2023-11
 */

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

#include "Item.h"
#include "Puzzle.h"
#include "Character.h"
#include "RoomState.h"
#include "Room.h"
#include "GameTypes.h"

//I dunno if these tests will even work but its something

TEST(RoomTest, DialogueRoomConstructorTest) {
    NPC* fella = new NPC("", "");
    DialogueRoom* room1 = new DialogueRoom("", "", {""}, *fella);
    EXPECT_EQ(room1->getTitle(), "room");
    delete room1;
    delete fella;
}

TEST(RoomTest, ThinkingPuzzleConstructorTest) {
    DialoguePuzzle* puzzle1 = new DialoguePuzzle("", "");
    ThinkingPuzzleRoom* room2 = new ThinkingPuzzleRoom("", "", {""}, *puzzle1);
    EXPECT_EQ(room2->getTitle(), "room");
    delete room2;
    delete puzzle1;
}

