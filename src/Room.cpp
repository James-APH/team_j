/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @date 2023-11
 */

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>

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

  std::string fileName;
  if (title == "Garden") {
    fileName = "src/GameText/rooms/garden.txt";
  } else if (title == "Ball Room") {
    fileName = "src/GameText/rooms/ballroom.txt";
  } else if (title == "Bed Room") {
    fileName = "src/GameText/rooms/bedroom.txt";
  } else if (title == "Cellar") {
    fileName = "src/GameText/rooms/cellar.txt";
  } else if (title == "Library") {
    fileName = "src/GameText/rooms/library.txt";
  } else if (title == "Stairway") {
    fileName = "src/GameText/rooms/staircase.txt";
  } else if (title == "Study Room") {
    fileName = "src/GameText/rooms/study.txt";
  } else if (title == "Crawl Space") {
    fileName = "src/GameText/rooms/secretPassage.txt";
  } else if (title == "Attic") {
    fileName = "src/GameText/rooms/atticAfter.txt";
  } else {
    fileName = "src/GameText/rooms/hallway.txt";
  }

  std::ifstream fs;
  fs.open(fileName);
  std::string line;
  std::string temp;
  while (!fs.eof()) {
    getline(fs, line);
    temp += line;
    temp.push_back('\n');
  }
  this->description = temp;

  fs.close();

  if (!connections.empty())
    this->connections = connections;
}

Room::~Room() {
  delete state;
}

RoomState &Room::getState() {
  return *state;
}

void Room::playerEnterRoom(Player* player) {
  this->player = player;
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
    const std::vector<std::string>& connections, const NPC &fella) :
    Room(title, description, connections) {
  this->roomtype = GameTypes::DIALOGUE_ROOM;
  this->fella = new NPC(fella);
}

DialogueRoom::~DialogueRoom() {
  delete fella;
}

bool DialogueRoom::playerTakeAction() {
  std::string input = "";
  while (input != "y" && input != "n") {
    std::cout << "Would you like to talk to " + fella->getName() + "? [y/n]"
              << std::endl;
    std::cin >> input;
  }
  if (input == "y") {
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
    std::string description, const std::vector<std::string>& connections,
    const DialoguePuzzle &dialoguePuzzle) : Room(title, description, connections) {
  this->roomtype = GameTypes::PUZZLE_ROOM;
  this->dialoguePuzzle = new DialoguePuzzle(dialoguePuzzle);
}

ThinkingPuzzleRoom::~ThinkingPuzzleRoom() {
  delete dialoguePuzzle;
}

bool ThinkingPuzzleRoom::playerTakeAction() {
  std::string takeAction = "";
  std::string input = "";
  if (state->roomDone()) {
    std::cout << "You have completed this puzzle already!" << std::endl;
    return true;
  }
  while (input != "s" && input != "l") {
    std::cout << "Would you like to solve the puzzle or leave? [s/l]" << std::endl;
    std::cin >> input;
  }
  if (input == "s") {
    while (!dialoguePuzzle->wasSolved() && takeAction != "q") {
      dialoguePuzzle->getInput(takeAction);
      std::cout << "Enter your answer to the puzzle or enter [q] to quit: " << std::endl;
      std::cin >> takeAction;
    }
  }
  if (dialoguePuzzle->wasSolved()) {
    state = new FullyExploredRoom();
    return true;
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
//You can't leave and you can't use item

ItemPuzzleRoom::ItemPuzzleRoom(std::string title, std::string description,
    const std::vector<std::string>& connections, const ItemPuzzle &itemPuzzle) :
    Room(title, description, connections) {
  this->roomtype = GameTypes::PUZZLE_ROOM;
  this->itemPuzzle = new ItemPuzzle(itemPuzzle);
}

ItemPuzzleRoom::~ItemPuzzleRoom() {
  delete itemPuzzle;
}

bool ItemPuzzleRoom::playerTakeAction() {
  std::string takeAction = "";
  std::string input = "";
  if (state->roomDone()) {
    std::cout << "You've completed this puzzle already!" << std::endl;
    return true;
  }
  while (input != "s" && input != "l") {
    std::cout << "Would you like to solve the puzzle or leave? [s/l]" << std::endl;
    std::cin >> input;
  }
  if (input == "s") {
    std::string answer;
    std::cout << ip->toString() << std::endl;
    std::cout << "Open inventory to use item, or exit [u/e]" << std::endl;
    std::cin >> answer;
    if (answer != "u" && answer != "e") {
      while (answer != "u" && answer != "e") {
        std::cout << "Enter [u] or [e]" << std::endl;
        std::cin >> answer;
      }
    }

    if (answer == "u") {
      std::string quitCondition;
      while (!ip->wasSolved()) {
          ip->checkItem(player->useItem());
          std::cout << "Enter [i] to inspect you inventory again\n"
                       "Or enter [q] to quit" << std::endl;
          std::cin >> quitCondition;
          if (quitCondition == "q") {
            break;
          }
          if (ip->wasSolved()) {
            state = new FullyExploredRoom();
            return true;
      }
      }
     
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
                   itemPuzzle->getExpectedItemName() <<
              " required to unlock more rooms!";
  stringReader << '\n' << '\n';
  std::cout << stringReader.str() << std::endl;
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

bool ItemRoom::playerTakeAction() {
  std::string input = "";
  while (input != "y" && input != "n") {
    std::cout << "Would you like to pick up this: " + item->getName() + "? [y/n]" << std::endl;
    std::cin >> input;
  }
  if (input == "y") {
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
