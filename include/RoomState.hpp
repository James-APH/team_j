/**
 * @author James Huston [huston@uleth.ca]
 * @date 2023-11
 */
#ifndef ROOMSTATE.HPP
#define ROOMSTATE.HPP

/**
 * @class RoomState in roomstate.hpp "roomstate.hpp"
 * @brief Interface for all the possible room states after exploring a room
 */
class RoomState {
  /**
  * @brief DefaultConstructor
  */
  RoomState();
  
  /**
  * @brief Default Destructor
  */
  virtual ~RoomState();

  /**
  * @brief Used to determine if a room has been explored
  * @return true if room has been explored, false otherwise
  */
  virtual bool isExplored() = 0;

  /**
  * @brief used to determine if all the secrets have been found
  * @return true if all secrets have been found, false otherwise
  */
  virtual bool allSecretsFound() = 0;

};

/**
 * @class FullyExploredRoom roomstate.hpp "roomstate.hpp"
 * @brief State of a room that has been fully explored
 */
class FullyExploredRoom : RoomState {
 /**
  * @brief DefaultConstructor
  */
  FullyExploredRoom();
  
  /**
  * @brief Default Destructor
  */
  ~FullyExploredRoom();

  /**
  * @brief In this state the room has been explored.
  * @return true.
  */
  bool isExplored();

  /**
  * @brief In this state all the secrets have been found.
  * @return true.
  */
  bool allSecretsFound();
};


/**
 * @class ExploredRoom roomstate.hpp "roomstate.hpp"
 * @brief State of a room that has been entered, but not explored
 */
class ExploredRoom : RoomState {
 /**
  * @brief DefaultConstructor
  */
  ExploredRoom();
  
  /**
  * @brief Default Destructor
  */
  ~ExploredRoom();

  /**
  * @brief In this state the room has been explored.
  * @return true.
  */
  bool isExplored();

  /**
  * @brief In this state no or some secrets have been found
  * @return false
  */
  bool allSecretsFound();
};

/**
 * @class UnexploredRoom roomstate.hpp "roomstate.hpp"
 * @brief State of a roomthat has not been explored
 */
class UnexploredRoom : RoomState {
 /**
  * @brief DefaultConstructor
  */
  UnexploredRoom();
  
  /**
  * @brief Default Destructor
  */
  ~UnexploredRoom();

  /**
  * @brief In this state the room has not been explored
  * @return ralse.
  */
  bool isExplored();

  
  /**
  * @brief In this state the no secretes have been found
  * @return false
  */
  bool allSecretsFound();
};

#endif

