/**
 * @author James Huston [huston@uleth.ca]
 * @date 12/2023
 * 
 * 
*/

#ifndef GAMETYPES_H_INCLUDED
#define GAMETYPES_H_INCLUDED

/**
 * @class GameTypes in GameTypes.h "GameTypes.h"
 * @brief collection of types.
 * 
*/
class GameTypes {
  enum PuzzleTypes {
    THINKING,
    ITEM,
  };

  enum RoomTypes {
    THINKING_PUZZLE_ROOM,
    DIALOGUE_ROOM,
    ITEM_ROOM,
    ITEM_PUZZLE_ROOM
  };
};

#endif // GAMETYPES_H_INCLUDED