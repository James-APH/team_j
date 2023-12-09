/**
* @author James Huston [huston@uleth.ca]
* @date 2023-12
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

#include "Room.h"
#include "RoomList.h"
#include "Puzzle.h"
#include "Item.h"
#include "Character.h"
#include "Game.h"



Game::Game(std::string playerName) {
  // {up, down, north, east, south, west}
  //  up            north
  //            west     east
  //  down          south
  player = new Player(playerName, *map);
  roomlist->insert(new DialogueRoom("Garden", "",
  {"", "", "South Hall", "", "", ""}, *craig));
  roomlist->insert(new ItemRoom("South Hall", "",
  {"", "", "Ball Room", "", "", ""}, *yellowKeyCard));
  roomlist->insert(new DialogueRoom("Ball Room", "",
  {"", "", "North Hall", "East Hall"
  , "South Hall", "Stairway"}, *rose));
  roomlist->insert(new ItemPuzzleRoom("East Hall", "",
  {"", "", "", "Library", "Study Room", "Ball Room"}, *yellowItemPuzzle));
  roomlist->insert(new ThinkingPuzzleRoom("Study Room", "",
  {"", "", "East Hall", "", "Cabinet", ""}, *studyPuzzle));
  roomlist->insert(new ItemRoom("Cabinet", "",
  {"", "", "Study Room", "", "", ""}, *blueKeyCard));
  roomlist->insert(new ThinkingPuzzleRoom("Library", "",
  {"", "", "Secret Passage", "", "", "East Hall"}, *libraryPuzzle));
  roomlist->insert(new ItemRoom("Secret Passage", "",
  {"", "", "", "", "Library", ""}, *knife));
  roomlist->insert(new ItemPuzzleRoom("North Hall", "",
  {"", "", "", "Bed Room", "Ball Room", ""}, *blueItemPuzzle));
  roomlist->insert(new DialogueRoom("Bed Room", "",
  {"", "", "", "North Hall", "", ""}, *steph));
  roomlist->insert(new DialogueRoom("Stairway", "",
  {"Attic", "Cellar", "", "Ball Room", "", "", ""}, *brent));
  roomlist->insert(new ThinkingPuzzleRoom("Attic", "",
  {"", "Stairway", "Crawl Space", "", "", ""}, *atticPuzzle));
  roomlist->insert(new ItemRoom("Crawl Space", "",
  {"", "", "End", "", "Attic", ""}, *pictureFrame));
  roomlist->insert(new ItemRoom("Cellar", "",
  {"Stairway", "", "", "", "", ""}, *will));
  roomlist->insert(new DialogueRoom("End", "",
  {"", "", "", "", "Crawl Space", ""}, *craig2));
  roomlist->circley();
  roomlist->solidify();
}

Game::~Game() {}

void Game::playGame() {
  setCurrentNode(roomlist->getHead());
  std::cout << "\n\n\nMurder Mystery" << std::endl;
  std::string takeActionChoice;

  std::string playAnswer;
  std::cout << "\nWould you like to play a game? [y/n]" << std::endl;
  std::cin >> playAnswer;
  setCurrentNode(roomlist->getHead());
  //currentNode->getRoom()->playerEnterRoom();
 
    while (currentNode->getRoom()->getTitle() != "End") {
        currentNode->getRoom()->display();
        std::cout << "\nWould you like to:\n"
                     "\n* Move rooms [m]"
                     "\n* Interact   [i]"
                     "\n* View Inven [v]"
                     "\n* Accuse     [a]"<< "\n" << std::endl;

        std::cin >> takeActionChoice;
      if (takeActionChoice == "m") {
        moveRoom();
      } else if (takeActionChoice == 'i') {
      } else if (takeActionChoice == "i"){
        interact();
      } else if (takeActionChoice == 'v') {
      } else if (takeActionChoice == "v"){
        inventory();
      } else if (takeActionChoice == 'a') {
      } else if (takeActionChoice == "a"){
        accuse();
        break;
      }
  }
}

void Game::accuse() {
    int murderAnswer;
    std::cout << "\nWho do you think did it?\n"
     << std::endl;
    std::cout << "\n1 - Brent\n2 - Rose\n3 - Stephanie\n4 - Craig"
     << std::endl;
    std::cin >> murderAnswer;
    displaySplashScreen(murderAnswer);
}

void Game::inventory() {
  player->listInventory();
}

void Game::displaySplashScreen(int condition) {
  switch (condition) {
      case 1:
        std::cout << "\nNo Duh" << std::endl;
        break;
      case 2:
        std::cout << "\nwrong" << std::endl;
        break;
      case 3:
        std::cout << "\nwrong" << std::endl;
        break;
      case 4:
        std::cout << "\nCraig will remember this"
        << std::endl;
        break;
  }
}

void Game::moveRoom() {
  if (currentNode->getRoom()->getRoomType() == GameTypes::PUZZLE_ROOM 
  && !currentNode->getRoom()->isDone()) {
      std::cout << "\nThe current room has not been finished you can"
                   " only move to the previous" << std::endl;
     currentNode = currentNode->getPreviousNode();
  } else {
    std::vector<unsigned> pathways(getPathways());
    listRoomOptions(pathways);
    int move;
    std::cin >> move;
    if (move < UP || move > WEST) {
      while (move < UP || move > WEST) {
        std::cout << "Please enter a valid room:";
        std::cin >> move;
      }
    }
    RoomNode* temp = currentNode;
    if (move == UP) {
      currentNode = currentNode->getUpNode();
      currentNode->getRoom()->playerEnterRoom(player); 
    } else if (move == DOWN) {
      currentNode = currentNode->getDownNode();
      currentNode->getRoom()->playerEnterRoom(player); 
    } else if (move == NORTH) {
      currentNode = currentNode->getNorthNode();
      currentNode->getRoom()->playerEnterRoom(player); 
    } else if (move == EAST) {
      currentNode = currentNode->getEastNode();
      currentNode->getRoom()->playerEnterRoom(player); 
    } else if (move == SOUTH) {
      currentNode = currentNode->getSouthNode();
      currentNode->getRoom()->playerEnterRoom(player); 
    } else {
      currentNode = currentNode->getWestNode();
      currentNode->getRoom()->playerEnterRoom(player); 
    }
    currentNode->setPreviousNode(temp);
  }
}

std::vector<unsigned> Game::getPathways() {
  std::vector<unsigned> path;
  for (int i = 0; i < 6; i++) {
    if (currentNode->getRoom()->getConnections()[i] != "") {
      path.push_back(i);
    }
  }
  return path;
}

void Game::listRoomOptions(std::vector<unsigned> pathways) {
  std::cout << "Would you like to go to any of these rooms?" << std::endl;
  for (auto a : pathways) {
    if (a == 0) {
      std::cout << std::setw(15) << std::right
                << currentNode->getUpNode()->getRoom()->getTitle()
                << " [" << UP << "]"
                << std::endl;
    } else if (a == 1) {
      std::cout << std::setw(15) << std::right
                << currentNode->getDownNode()->getRoom()->getTitle()
                << " [" << DOWN << "]"
                << std::endl;
    } else if (a == 2) {
      std::cout << std::setw(15) << std::right
                <<  currentNode->getNorthNode()->getRoom()->getTitle()
                << " [" << NORTH << "]"
                << std::endl;
    } else if (a == 3) {
      std::cout << std::setw(15) << std::right
                << currentNode->getEastNode()->getRoom()->getTitle()
                << " [" << EAST << "]"
                << std::endl;
    } else if (a == 4) {
      std::cout << std::setw(15) << std::right
                << currentNode->getSouthNode()->getRoom()->getTitle()
                << " [" << SOUTH << "]"
                << std::endl;
    } else {
      std::cout << std::setw(15) << std::right
                << currentNode->getWestNode()->getRoom()->getTitle()
                << " [" << WEST << "]"
                << std::endl;
    }
  }
}

void Game::interact() {
  currentNode->getRoom()->playerTakeAction();
}

void Game::setCurrentNode
(RoomNode* currentNode) {
  this->currentNode = currentNode;
}


RoomNode* Game::getCurrentNode() {
  return currentNode;
}





// void Game::readData(std::string&
//                   , std::string&, std::string&
//                   , std::string start
//                   , std::string end) {
// }

// void Game::readData(std::string&, std::string&
//              , std::string start, std::string end) {
//}
