/**
 * @Author James Huston [huston@uleth.ca]
 * @date 2023-11
 */


#include <string>
#include <vector>

#include "Item.h"
#include "Puzzle.h"
#include "Character.h"
#include "RoomState.h"
#include "Room.h"
#include "GameTypes.h"

  Room::Room() {

  }

  Room::Room(std::string title
       , std::string description
       , const std::vector<std::string> connections) {

       }


  Room::~Room() {

  }


  RoomState& Room::getState() {
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

  DialogueRoom::DialogueRoom(std::string title
               , std::string description
               , const std::vector<std::string> connections
               , const NPC &fella) {

               }


  DialogueRoom::~DialogueRoom() {
  }


  void DialogueRoom::converse() {

  }


  void DialogueRoom::display() {

  }


  std::string DialogueRoom::toString() {

  }

//------------------------------------------------------------------

ThinkingPuzzleRoom::ThinkingPuzzleRoom(std::string title
                     , std::string description
                     , const std::vector<std::string> connections
                     , const DialoguePuzzle &dp) {

                     }


ThinkingPuzzleRoom::~ThinkingPuzzleRoom() {

}


  void ThinkingPuzzleRoom::playerTryPuzzle(std::string answer) {

  }


  void ThinkingPuzzleRoom::display() {

  }



  std::string ThinkingPuzzleRoom::toString() {

  }

//------------------------------------------------------------------------

  ItemPuzzleRoom::ItemPuzzleRoom(std::string title
                 , std::string description
                 , const std::vector<std::string> connections
                 , const ItemPuzzle &ip) {

                 }


  ItemPuzzleRoom::~ItemPuzzleRoom() {

  }



  void ItemPuzzleRoom::playerTakeAction() {

  }


  void ItemPuzzleRoom::display() {

  }




  std::string ItemPuzzleRoom::toString() {

  }

//------------------------------------------------------------------------

  ItemRoom::ItemRoom(std::string title
                 , std::string description
                 , const std::vector<std::string> connections
                 , const Item &i) {

                 }


 ItemRoom::~ItemRoom() {

 }


  void ItemRoom::playerUseItem(const Item &i) {

  }


  void ItemRoom::display() {

  }


  Item& ItemRoom::giveItem() {

  }


  std::string ItemRoom::toString() {
    
  }

