/**
* @author James Huston [huston@uleth.ca]
* @date 11/2023
*/

#include "include/roomstate.hpp"


FullyExploredRoom::FullyExploredRoom() {}

FullyExploredRoom::~FullyExploredRoom() {}

bool FullyExploredRoom::isExplored() {
  return true;
}

bool FullyExploredRoom::allSecretsFound() {
  return true; 
}



ExploredRoom::ExploredRoom() {}

ExploredRoom::~ExploredRoom() {}

bool ExploredRoom::isExplored() {
  return true;
}

bool ExploredRoom::allSecretsFound() {
  return false;
}




UnexploredRoom::UnexploredRoom() {}

UnexploredRoom::~UnexploredRoom() {}

bool UnexploredRoom::isExplored() {
  return false;
}

bool UnexploredRoom::allSecretsFound() {
  return false
}

