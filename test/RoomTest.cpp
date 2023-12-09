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
    NPC* fella = new NPC("Rose", "");
    DialogueRoom* room = new DialogueRoom("Garden", "", {""}, *fella);
    EXPECT_EQ(room->getTitle(), "Garden");
    delete room;
    delete fella;
}

TEST(RoomTest, ThinkingPuzzleConstructorTest) {
    DialoguePuzzle* puzzle = new DialoguePuzzle("", "");
    ThinkingPuzzleRoom* room = new ThinkingPuzzleRoom("Library", "",
                                                      {""}, *puzzle);
    EXPECT_EQ(room->getTitle(), "Library");
    delete room;
    delete puzzle;
}

TEST(RoomTest, ItemPuzzleConstructorTest) {
    Item* object = new Item();
    ItemPuzzle* puzzle = new ItemPuzzle("", *object);
    ItemPuzzleRoom* room = new ItemPuzzleRoom("East Hall", "", {""}, *puzzle);
    EXPECT_EQ(room->getTitle(), "East Hall");
    delete room;
    delete puzzle;
    delete object;
}

TEST(RoomTest, ItemRoomConstructorTest) {
    Item* object = new Item();
    ItemRoom* room = new ItemRoom("Crawl Space", "", {""}, *object);
    EXPECT_EQ(room->getTitle(), "Crawl Space");
    delete room;
    delete object;
}
