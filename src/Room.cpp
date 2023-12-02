/**
 * @Author James Huston [huston@uleth.ca]
 * @date 2023-11
 */


#include <string>

#include "Item.h"
#include "Puzzle.h"
#include "Character.h"
#include "RoomState.h"
#include "Room.h"

  Room::Room() {

  }

  Room::Room(std::string title
       , std::string description
       , const std::vector<std::string> connections) {

       }


  Room::~Room() {

  }

//----------------------------------------------------------

  DialogueRoom::DialogueRoom(std::string title
               , std::string description
               , const std::vector<std::string> connections
               , const NPC &fella) {

               }


  DialogueRoom::~DialogueRoom() {
  }


  RoomState& DialogueRoom::getState() {
    return *state;
  }


  std::string  DialogueRoom::getTitle() {
    return title;
  }


  std::vector<std::string>  DialogueRoom::getConnections() {
    return connections;
  }


  void DialogueRoom::converse() {

  }


  void DialogueRoom::display() {

  }


  void DialogueRoom::setState() {

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


RoomState& ThinkingPuzzleRoom::getState() {

}



  std::string ThinkingPuzzleRoom::getTitle() {

  }


  std::vector<std::string> ThinkingPuzzleRoom::getConnections() {

  }


  void ThinkingPuzzleRoom::playerTryPuzzle(std::string answer) {

  }


  void ThinkingPuzzleRoom::display() {

  }


  void ThinkingPuzzleRoom::setState() {

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


  RoomState& ItemPuzzleRoom::getState() {

  }


  std::string ItemPuzzleRoom::getTitle() {

  }


  std::vector<std::string> ItemPuzzleRoom::getConnections() {

  }


  void ItemPuzzleRoom::playerTakeAction() {

  }


  void ItemPuzzleRoom::display() {

  }


  void ItemPuzzleRoom::setState() {

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


  RoomState& ItemRoom::getState() {

  }


  std::string ItemRoom::getTitle() {

  }


  std::vector<std::string> ItemRoom::getConnections() {

  }

  void ItemRoom::playerUseItem(const Item &i) {

  }


  void ItemRoom::display() {

  }


  void ItemRoom::setState() {

  }


  Item& ItemRoom::giveItem() {

  }


  std::string ItemRoom::toString() {
    
  }

