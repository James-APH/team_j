/**
* @author James Huston [huston@uleth.ca]
* @date 2023-12
*/

#include <string>
#include <vector>
#include <algorithm>

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
  roomlist->insert(new DialogueRoom("Garden", "", {"", "", "South Hall", "", "", ""}, *craig));
  roomlist->insert(new ItemRoom("South Hall", "", {"", "", "Ball Room", "", "", ""}, *yellowKeyCard));
  roomlist->insert(new DialogueRoom("Ball Room", "", {"", "", "North Hall", "East Hall", "South Hall", "Stairway"}, *rose));
  roomlist->insert(new ItemPuzzleRoom("East Hall", "", {"", "", "", "Library", "Study Room", ""}, *yellowItemPuzzle));
  roomlist->insert(new ThinkingPuzzleRoom("Study Room", "", {"", "", "East Hall", "", "Cabinet", ""}, *studyPuzzle));
  roomlist->insert(new ItemRoom("Cabinent", "", {"", "", "Study Room", "", "", ""}, *blueKeyCard));
  roomlist->insert(new ThinkingPuzzleRoom("Library", "", {"", "", "Secret Passage", "", "", "East Hall"}, *libraryPuzzle));
  roomlist->insert(new ItemRoom("Secret Passage", "", {"", "", "", "", "Library", ""}, *knife));
  roomlist->insert(new ItemPuzzleRoom("North Hall", "", {"", "", "", "Bed Room", "Ball Room", ""}, *blueItemPuzzle));
  roomlist->insert(new DialogueRoom("Bed Room", "", {"", "", "", "North Hall", "", ""}, *steph));
  roomlist->insert(new DialogueRoom("Stairway", "", {"Attic", "Cellar", "", "Ball Room", "", "", ""}, *brent));
  roomlist->insert(new ThinkingPuzzleRoom("Attic", "", {"", "Stairway", "Crawl Space", "", "", ""}, *atticPuzzle));
  roomlist->insert(new ItemRoom("Crawl Space", "", {"", "", "End", "", "Attic", ""}, *pictureFrame));
  roomlist->insert(new ItemRoom("Cellar", "", {"Stairway", "", "", "", "", ""}, *will));
  roomlist->insert(new DialogueRoom("End", "", {"", "", "", "", "Crawl Space", ""}, *craig2));
  roomlist->solidify();
}

Game::~Game() {}

void Game::playGame() {
  std::string playAnswer;
  std::cout << "Would you like to play a game? [y/n]" << std::endl;
  std::cin >> playAnswer;
  setCurrentNode(roomlist->getHead());
  while(playAnswer == "y") {
    while(currentNode->getRoom()->getTitle() != "End") {
        std::cout << "Would you like to move rooms"
                     " or interact with the current"
                     " one? [m/i]" << std::endl;
        char takeActionChoice;
        std::cin >> takeActionChoice;
      if (takeActionChoice = 'm') {
        moveRoom();
      } else {
        interact();
      }
    }
    int murderAnswer;
    std::cout << "Who do you think did it?\n" << std::endl;
    std::cout << "1 - Brent\n2 - Rose\n3 - Stephanie\n4 - Craig" << std::endl;
    std::cin >> murderAnswer;
    displaySplashScreen(murderAnswer);
    std::cout << "Would you like to play again? [y/n]" << std::endl;
    std::cin >> playAnswer;
  }
}

void Game::displaySplashScreen(int condition) {
  switch(condition) {
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
        std::cout << "Craig will remember this" << std::endl;
        break;
  }
}

void Game::moveRoom() {
  if (currentNode->getRoom()->getRoomType() == GameTypes::PUZZLE_ROOM) {
    if(currentNode->getRoom()->getState().isExplored() &&
       !currentNode->getRoom()->getState().roomDone()) {
      std::cout << "The current room has not been finished you can"
                   " only move to the previous" << std::endl;
      currentNode = previousNode;
    }
  } else {
    std::vector<char> connectionLabels = getConnectionLabels();
    getRoomOptions(connectionLabels);
    char newRoom;
    std::cin >> newRoom;
    while(std::find(connectionLabels.begin(),
                    connectionLabels.end(), newRoom) ==
                    connectionLabels.end()) {
      std::cout << "Please enter a valid room:";
      std::cin >> newRoom;
    }
    previousNode = currentNode;
    switch(newRoom) {
      case 'u':
        currentNode = currentNode->getUpNode();
      break;
      case 'd':
        currentNode = currentNode->getDownNode();
      break;
      case 'n':
        currentNode = currentNode->getNorthNode();
      break;
      case 'e':
        currentNode = currentNode->getEastNode();
      break;
      case 's':
        currentNode = currentNode->getSouthNode();
      break;
      case 'w':
        currentNode = currentNode->getWestNode();
      break;
    }
  }
}

void Game::getRoomOptions(std::vector<char> connectionLabels) {
  std::cout << "Would you like to go to any of these rooms?\n";
  for(int i = 0; i < connectionLabels.size(); i++) {
    switch(connectionLabels[i]) {
      case 'u':
        "The " + currentNode->getRoom()->getConnections()[0] + "[u]\n";
      break;
      case 'd':
        "The " + currentNode->getRoom()->getConnections()[1] + "[d]\n";
      break;
      case 'n':
        "The " + currentNode->getRoom()->getConnections()[2] + "[n]\n";
      break;
      case 'e':
        "The " + currentNode->getRoom()->getConnections()[3] + "[e]\n";
      break;
      case 's':
        "The " + currentNode->getRoom()->getConnections()[4] + "[s]\n";
      break;
      case 'w':
        "The " + currentNode->getRoom()->getConnections()[5] + "[w]\n";
      break;
    }
  }
}

std::vector<char> Game::getConnectionLabels() {
  std::vector<char> connectionLabels;
    if (currentNode->getRoom()->getConnections()[0] != "")
      connectionLabels.push_back('u');
    if (currentNode->getRoom()->getConnections()[1] != "")
      connectionLabels.push_back('d');
    if (currentNode->getRoom()->getConnections()[2] != "")
      connectionLabels.push_back('n');
    if (currentNode->getRoom()->getConnections()[3] != "")
      connectionLabels.push_back('e');
    if (currentNode->getRoom()->getConnections()[4] != "")
      connectionLabels.push_back('s');
    if (currentNode->getRoom()->getConnections()[5] != "")
      connectionLabels.push_back('w');
  return connectionLabels;
}

void Game::interact() {
  currentNode->getRoom()->playerTakeAction(player);
}

void Game::setCurrentNode(RoomNode* currentNode) {
  this->currentNode = currentNode;
}

void Game::setPreviousNode(RoomNode* previousNode) {
  this->previousNode = previousNode;
}

RoomNode* Game::getCurrentNode() {
  return currentNode;
}

RoomNode* Game::getPreviousNode() {
  return previousNode;
}


  
// void Game::readData(std::string&, std::string&, std::string&
//                   , std::string start, std::string end) {
// }

// void Game::readData(std::string&, std::string&
//                   , std::string start, std::string end) {
//}
