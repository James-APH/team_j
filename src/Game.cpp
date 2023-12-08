/**
* @author James Huston [huston@uleth.ca]
* @date 2023-12
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

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
  {"", "", "", "Library", "Study Room", ""}, *yellowItemPuzzle));
  roomlist->insert(new ThinkingPuzzleRoom("Study Room", "",
  {"", "", "East Hall", "", "Cabinet", ""}, *studyPuzzle));
  roomlist->insert(new ItemRoom("Cabinent", "",
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
  std::cout << "Murder Mystery" << std::endl;

  std::string playAnswer;
  std::cout << "Would you like to play a game? [y/n]" << std::endl;
  std::cin >> playAnswer;
  setCurrentNode(roomlist->getHead());
  while (playAnswer == "y") {
    while (currentNode->getRoom()->getTitle() != "End") {
        currentNode->getRoom()->display();
        std::cout << "Would you like to:"
                     "\n* Move rooms [m]"
                     "\n* Interact   [i]"
                     "\n* View Inven [v]" << std::endl;
        char takeActionChoice;
        std::cin >> takeActionChoice;
      if (takeActionChoice == 'm') {
        moveRoom();
      } else {
        interact();
      }
    }
    int murderAnswer;
    std::cout << "Who do you think did it?\n"
     << std::endl;
    std::cout << "1 - Brent\n2 - Rose\n3 - Stephanie\n4 - Craig"
     << std::endl;
    std::cin >> murderAnswer;
    displaySplashScreen(murderAnswer);
    std::cout << "Would you like to play again? [y/n]"
     << std::endl;
    std::cin >> playAnswer;
  }
  delete currentNode;
}

void Game::displaySplashScreen(int condition) {
  switch (condition) {
      case 1:
        std::cout << "No Duh" << std::endl;
        break;
      case 2:
        std::cout << "wrong" << std::endl;
        break;
      case 3:
        std::cout << "wrong" << std::endl;
        break;
      case 4:
        std::cout << "Craig will remember this"
        << std::endl;
        break;
  }
}

void Game::moveRoom() {
  if (currentNode->getRoom()->getRoomType() == GameTypes::PUZZLE_ROOM) {
    if (currentNode->getRoom()->getState().isExplored() &&
       !currentNode->getRoom()->getState().roomDone()) {
      std::cout << "The current room has not been finished you can"
                   " only move to the previous" << std::endl;
      currentNode = previousNode;
    }
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
    previousNode = currentNode;
    if (move == UP) {
      currentNode = currentNode->getUpNode();
    } else if (move == DOWN) {
      currentNode = currentNode->getDownNode();
    } else if (move == NORTH) {
      currentNode = currentNode->getNorthNode();
    } else if (move == EAST) {
      currentNode = currentNode->getEastNode();
    } else if (move == SOUTH) {
      currentNode = currentNode->getSouthNode();
    } else {
      currentNode = currentNode->getWestNode();
    }
  }
}

std::vector<unsigned>& Game::getPathways() {
  std::vector<unsigned> pathways;
  for (int i = 0; i < 6; i++) {
    if(currentNode->getRoom()->getConnections()[i] != "") {
      pathways.push_back(i);
    }
  }
  return pathways;
}


void Game::listRoomOptions(std::vector<unsigned> pathways) {
  std::cout << "Would you like to go to any of these rooms?" << std::endl;
  for(auto a : pathways) {
    if (a == 0) {
      std::cout << currentNode->getNorthNode()->getRoom()->getTitle()
                << std::setw(15)
                << std::left << " [" << UP << "]"
                << std::endl;
    } else if (a == 1) {
      std::cout << currentNode->getNorthNode()->getRoom()->getTitle()
                << std::setw(15)
                << std::left << " [" << DOWN << "]"
                << std::endl;
    } else if (a == 2) {
      std::cout << currentNode->getNorthNode()->getRoom()->getTitle()
                << std::setw(15)
                << std::left << " [" << NORTH << "]"
                << std::endl;
    } else if (a == 3) {
      std::cout << currentNode->getNorthNode()->getRoom()->getTitle()
                << std::setw(15)
                << std::left << " [" << EAST << "]"
                << std::endl;
    } else if (a == 4) {
      std::cout << currentNode->getNorthNode()->getRoom()->getTitle()
                << std::setw(15)
                << std::left << " [" << SOUTH << "]"
                << std::endl;
    } else {
      std::cout << currentNode->getNorthNode()->getRoom()->getTitle()
                << std::setw(15)
                << std::left << " [" << WEST << "]"
                << std::endl;
    }
  }  
}



void Game::interact() {
  currentNode->getRoom()->
  playerTakeAction(player);
}

void Game::setCurrentNode
(RoomNode* currentNode) {
  this->currentNode = currentNode;
}

void Game::setPreviousNode
(RoomNode* previousNode) {
  this->previousNode = previousNode;
}

RoomNode* Game::getCurrentNode() {
  return currentNode;
}

RoomNode* Game::getPreviousNode() {
  return previousNode;
}



// void Game::readData(std::string&
//                   , std::string&, std::string&
//                   , std::string start
//                   , std::string end) {
// }

// void Game::readData(std::string&, std::string&
//              , std::string start, std::string end) {
//}
