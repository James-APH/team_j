/**
 * @Author James Huston [huston@uleth.ca]
 * @date 2023-11
 */


#include <string>

#include "Item.h"
#include "Puzzle.h"
#include "Character.h"
#include "RoomState.h"

  Room(std::string title
       , std::string description
       , const std::string connections[]) {
  if(title == "" || description == "") {
     // throw
  }
  if(connections.length() == 0) {
    //throw
  }
  this.title = title;
  this.description = description;


}


  ~Room();




  DialogueRoom(std::string title
             , std::string description
             , const std::string connections[]
             , const NPC &fella);


  ~DialogueRoom();


  RoomState &getState();


  void listConnections();


  void converse();


  void display();


  void setState();


  std::string toString();







ThinkingPuzzleRoom(std::string title
                 , std::string description
                 , const std::string connections[]
                 , const DialoguePuzzle &dp);




~ThinkingPuzzleRoom();



RoomState &getState();



void listConnections();



void playerTryPuzzle(std::string answer);



void display();



void setState();



std::string toString();



ItemPuzzleRoom(std::string title
             , std::string description
             , const std::string connections[]
             , const ItemPuzzle &ip);


~ItemPuzzleRoom();


RoomState &getState();


void listConnections();


void playerTakeAction();


void display();


void setState();


std::string toString();



ItemPuzzleRoom(std::string title
             , std::string description
             , const std::string connections[]
             , const Item &i);


~ItemPuzzleRoom();


RoomState &getState();



void listConnections();



void playerUseItem(const Item &i);



void display();



void setState();



Item& giveItem();



std::string toString();


