/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Parker Regier [tyre.regier@uleth.ca]
 * @date 2023-11
 */


#include "RoomState.h"

RoomState::RoomState() {}

RoomState::~RoomState() {}


FullyExploredRoom::FullyExploredRoom() {}

FullyExploredRoom::~FullyExploredRoom() {}

bool FullyExploredRoom::isExplored() {
  return true;
}

bool FullyExploredRoom::roomDone() {
  return true;
}



ExploredRoom::ExploredRoom() {}

ExploredRoom::~ExploredRoom() {}

bool ExploredRoom::isExplored() {
  return true;
}

bool ExploredRoom::roomDone() {
  return false;
}




UnexploredRoom::UnexploredRoom() {}

UnexploredRoom::~UnexploredRoom() {}

bool UnexploredRoom::isExplored() {
  return false;
}

bool UnexploredRoom::roomDone() {
  return false;
}

