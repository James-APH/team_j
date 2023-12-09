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

TEST(RoomTest, DialogueRoomConstructorTest) {
    NPC* fella = new NPC("", "");
    DialogueRoom* room = new DialogueRoom("", "", {""}, *fella);
    EXPECT_EQ(room->getTitle(), "room");
    delete room;
    delete fella;
}

TEST(RoomTest, ThinkingPuzzleConstructorTest) {
    DialoguePuzzle* puzzle = new DialoguePuzzle("", "");
    ThinkingPuzzleRoom* room = new ThinkingPuzzleRoom("", "", {""}, *puzzle);
    EXPECT_EQ(room->getTitle(), "room");
    delete room;
    delete puzzle;
}

TEST(RoomTest, ItemPuzzleConstructorTest) {
    Item* object = new Item();
    ItemPuzzle* puzzle = new ItemPuzzle("", *object);
    ItemPuzzleRoom* room = new ItemPuzzleRoom("", "", {""}, *puzzle);
    EXPECT_EQ(room->getTitle(), "room");
    delete room;
    delete puzzle;
    delete object;
}

TEST(RoomTest, ItemRoomConstructorTest) {
    Item* object = new Item();
    ItemRoom* room = new ItemRoom("", "", {""}, *object);
    EXPECT_EQ(room->getTitle(), "room");
    delete room;
    delete object;
}
