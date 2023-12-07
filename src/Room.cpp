/**
 * @author James Huston [huston@uleth.ca]
 * @date 2023-11
 */

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

Room::Room(std::string title, std::string description,
    const std::vector<std::string> connections) {
  this->state = new UnexploredRoom();
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

std::string Room::getTitle() const {
  return title;
}

std::vector<std::string> Room::getConnections() {
  return connections;
}

GameTypes::RoomTypes Room::getRoomType() const {
  return roomtype;
}

void Room::setState(RoomState *state) {
  this->state = state;
}

//----------------------------------------------------------

DialogueRoom::DialogueRoom(std::string title, std::string description,
    const std::vector<std::string> connections, const NPC &fella) :
    Room(title, description, connections) {
  this->roomtype = GameTypes::DIALOGUE_ROOM;
  this->fella = new NPC(fella);
}

DialogueRoom::~DialogueRoom() {
  delete fella;
}

bool DialogueRoom::playerTakeAction(Player *player) {
  char input;
  std::cout << "Would you like to talk to " + fella->getName() + "? [y/n]"
    << std::endl;
  std::cin >> input;
  if (input != 'y' && input != 'n') {
      while (input != 'y' && input != 'n') {
      std::cout << "Would you like to talk to " + fella->getName() + "? [y/n]"
        << std::endl;
      std::cin >> input;
    }
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

void DialogueRoom::display() const {
  std::ostringstream stringReader;
  stringReader << std::setw(25);
  stringReader << title;
  stringReader << '\n' << '\n';
  stringReader << description;
  stringReader << '\n' << '\n';
  std::cout << stringReader.str() << std::endl;
}

//------------------------------------------------------------------

ThinkingPuzzleRoom::ThinkingPuzzleRoom(std::string title,
    std::string description, const std::vector<std::string> connections,
    const DialoguePuzzle &dp) : Room(title, description, connections) {
  this->roomtype = GameTypes::PUZZLE_ROOM;
  this->dp = new DialoguePuzzle(dp);
}

ThinkingPuzzleRoom::~ThinkingPuzzleRoom() {
  delete dp;
}

bool ThinkingPuzzleRoom::playerTakeAction(Player *player) {
  char input;
  std::cout << "Would you like to attempt to solve the puzzle"
               " detective? [y/n]" << std::endl;
  std::cin >> input;
  if (input != 'y' && input != 'n') {
    while (input != 'y' && input != 'n') {
      std::cout << "Would you like to attempt to attempt to"
                   " solve the puzzle? [y/n]" << std::endl;
        std::cin >> input;
    }
  }
  if (input == 'y') {
    std::cout << dp->toString() << std::endl;
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

void ThinkingPuzzleRoom::display() const {
    std::ostringstream stringReader;
  stringReader << std::setw(25);
  stringReader << title;
  stringReader << '\n' << '\n';
  stringReader << description;
  stringReader << '\n' << '\n';
  stringReader << "This room is locked, solve a complicated"
                  " question to unlock more rooms:\n";
  std::cout << stringReader.str() << std::endl;
}

//------------------------------------------------------------------------

ItemPuzzleRoom::ItemPuzzleRoom(std::string title, std::string description,
    const std::vector<std::string> connections, const ItemPuzzle &ip) :
    Room(title, description, connections) {
  this->roomtype = GameTypes::PUZZLE_ROOM;
  this->ip = new ItemPuzzle(ip);
}

ItemPuzzleRoom::~ItemPuzzleRoom() {
}

bool ItemPuzzleRoom::playerTakeAction(Player *player) {
  char input;
  std::cout << "Do you have the item required"
    " detective? [y/n]" << std::endl;
  std::cin >> input;
  if (input != 'y' && input != 'n') {
    while (input != 'y' && input != 'n') {
      std::cout << "Do you have the item required"
        " detective? [y/n]" << std::endl;
      std::cin >> input;
    }
  }
  if (input == 'y') {
    std::cout << ip->toString() << std::endl;
    std::string answer;
    while (!ip->wasSolved()) {
      std::cout << "Give the correct item or enter [q] to leave"
        << std::endl;
      if (answer == "q") {
        break;
      } else {
        ip->checkItem(player->useItem());
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

void ItemPuzzleRoom::display() const {
  std::ostringstream stringReader;
  stringReader << std::setw(25);
  stringReader << title;
  stringReader << '\n' << '\n';
  stringReader << description;
  stringReader << '\n' << '\n';
  stringReader << "This room is a dead end " <<
                   ip->getExpectedItemName() <<
              " required to unlock more rooms!";
  stringReader << '\n' << '\n';
  std::cout << stringReader.str() << std::endl;
}

//------------------------------------------------------------------------

ItemRoom::ItemRoom(std::string title, std::string description,
    const std::vector<std::string> connections,
    const Item &i) : Room(title, description, connections) {
  this->roomtype = GameTypes::ITEM_ROOM;
  this->item = new Item(i);
}

ItemRoom::~ItemRoom() {
  delete item;
}

bool ItemRoom::playerTakeAction(Player* player) {
  char input;
  std::cout << "Would you like to pick up this: " +
    item->getName() + "? [y/n]" << std::endl;
  std::cin >> input;
  if (input != 'y' && input != 'n') {
    while (input != 'y' && input != 'n') {
      std::cout <<  "Would you like to pick up this: " +
        item->getName() + "? [y/n]" << std::endl;
      std::cin >> input;
    }
  }
  if (input == 'y') {
    std::cout << item->toString() << std::endl;
    player->pickUp(giveItem());
    state = new FullyExploredRoom();
    return true;
  } else {
    state = new ExploredRoom();
    return false;
  }
}

void ItemRoom::display() const {
  std::ostringstream stringReader;
  stringReader << std::setw(25);
  stringReader << title;
  stringReader << '\n' << '\n';
  stringReader << description;
  stringReader << '\n' << '\n';
  stringReader << "In this room you see a" << item->getName();
  std::cout << stringReader.str() << std::endl;
}

Item &ItemRoom::giveItem() {
  return *item;
}
