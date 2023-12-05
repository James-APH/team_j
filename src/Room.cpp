/**
 * @Author James Huston [huston@uleth.ca]
 * @date 2023-11
 */

#include <string>
#include <vector>
#include <sstream>

#include "Item.h"
#include "Puzzle.h"
#include "Character.h"
#include "RoomState.h"
#include "Room.h"
#include "GameTypes.h"

Room::Room(std::string title, std::string description,
    const std::vector<std::string>& connections) {
  if (title != "")
    this->title = title;
  if (description != "")
    this->description = description;
  if (!connections.empty())
    this->connections = connections;
}

Room::~Room() {
  delete state;
}

RoomState &Room::getState() {
  return *state;
}

std::string Room::getTitle() {
  return title;
}

std::vector<std::string> Room::getConnections() {
  return connections;
}

GameTypes::RoomTypes Room::getRoomType() {
  return roomtype;
}

void Room::setState(RoomState *state) {
  this->state = state;
}

//----------------------------------------------------------

DialogueRoom::DialogueRoom(std::string title, std::string description,
    const std::vector<std::string>& connections, const NPC &fella) :
    Room(title, description, connections) {
  this->roomtype = GameTypes::DIALOGUE_ROOM;
  this->fella = new NPC(fella);
}

DialogueRoom::~DialogueRoom() {
  delete fella;
}

bool DialogueRoom::playerTakeAction(Player &player) {
  char input;
  std::cout << "Would you like to talk to " + fella->getName() + "? [y/n]"
    << std::endl;
  std::cin >> input;
  while (input != 'y' || input != 'n') {
    std::cout << "Would you like to talk to " + fella->getName() + "? [y/n]"
      << std::endl;
    std::cin >> input;
  }
  if (input == 'y') {
    fella->display();
    state = new FullyExploredRoom();
    return true;
  } else {
    state = new ExploredRoom();
    return false;
  }
}

void DialogueRoom::display() {
}

std::string DialogueRoom::toString() {
}

//------------------------------------------------------------------

ThinkingPuzzleRoom::ThinkingPuzzleRoom(std::string title,
    std::string description, const std::vector<std::string>& connections,
    const DialoguePuzzle &dp) : Room(title, description, connections) {
  this->roomtype = GameTypes::THINKING_PUZZLE_ROOM;
  this->dp = new DialoguePuzzle(dp);
}

ThinkingPuzzleRoom::~ThinkingPuzzleRoom() {
  delete dp;
}

bool ThinkingPuzzleRoom::playerTakeAction(Player &player) {
  char input;
  std::cout << "Would you like to attempt to solve the puzzle"
    " detective? [y/n]" << std::endl;
  std::cin >> input;
  while (input != 'y' || input != 'n') {
    std::cout << "Would you like to Would you like to attempt to"
      " solve the puzzle? [y/n]" << std::endl;
    std::cin >> input;
  }
  if (input == 'y') {
    dp->display();
    std::string answer;
    while (!dp->wasSolved()) {
      std::cout << "Enter your answer to the puzzle or enter [q] to quit"
        << std::endl;
      if (answer == "q") {
        break;
      } else {
        dp->getInput(answer);
      }
    }
    if (dp->wasSolved()) {
    state = new FullyExploredRoom();
    return true;
    }
  }
    state = new ExploredRoom();
    return false;
}

void ThinkingPuzzleRoom::display() {
}

std::string ThinkingPuzzleRoom::toString() {
  std::string display;
}

//------------------------------------------------------------------------

ItemPuzzleRoom::ItemPuzzleRoom(std::string title, std::string description,
    const std::vector<std::string>& connections, const ItemPuzzle &ip) :
    Room(title, description, connections) {
  this->roomtype = GameTypes::ITEM_PUZZLE_ROOM;
  this->ip = new ItemPuzzle(ip);
}

ItemPuzzleRoom::~ItemPuzzleRoom() {
}

bool ItemPuzzleRoom::playerTakeAction(Player &player) {
  char input;
  std::cout << "Would you like to attempt to solve the puzzle"
    " detective? [y/n]" << std::endl;
  std::cin >> input;
  while (input != 'y' || input != 'n') {
    std::cout << "Would you like to Would you like to attempt to solve the"
      " puzzle? [y/n]" << std::endl;
    std::cin >> input;
  }
  if (input == 'y') {
    ip->display();
    std::string answer;
    while (!ip->wasSolved()) {
      std::cout << "Enter your answer to the puzzle or enter [q] to quit"
        << std::endl;
      if (answer == "q") {
        break;
      } else {
        ip->checkItem(player.useItem());
      }
    }
    if (ip->wasSolved()) {
    state = new FullyExploredRoom();
    return true;
    }
  }
    state = new ExploredRoom();
    return false;
}

void ItemPuzzleRoom::display() {
}

std::string ItemPuzzleRoom::toString() {
}

//------------------------------------------------------------------------

ItemRoom::ItemRoom(std::string title, std::string description,
    const std::vector<std::string>& connections,
    const Item &i) : Room(title, description, connections) {
  this->roomtype = GameTypes::ITEM_ROOM;
  this->item = new Item(i);
}

ItemRoom::~ItemRoom() {
  delete item;
}

bool ItemRoom::playerTakeAction(Player &player) {
  char input;
  std::cout << "Would you like to pick up this: " +
    item->getName() + "? [y/n]" << std::endl;
  std::cin >> input;
  if (input != 'y' || input != 'n') {
    while (input != 'y' || input != 'n') {
      std::cout <<  "Would you like to pick up this: " +
        item->getName() + "? [y/n]" << std::endl;
      std::cin >> input;
    }
  }
  if (input == 'y') {
    item->display();
    player.pickUp(giveItem());
    state = new FullyExploredRoom();
    return true;
  } else {
    state = new ExploredRoom();
    return false;
  }
}

void ItemRoom::display() {
}

Item &ItemRoom::giveItem() {
  return *item;
}

std::string ItemRoom::toString() {
}
