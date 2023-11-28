/**
* @Author James Huston [huston@uleth.ca]
* @date 2023-11
*/

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>

/**
 * @class Character in character.h "character.h"
 * @brief superclass for different character types
 */
class Character {
 public:
  /**
  * @brief constructor
  * @param [in] name the name of the character
  * @throw bad_input if name is empty
  */
  virtual Character(std::string name);

  /**
  * @brief destructor
  */
  virtual ~Character();

  /**
  * @brief outputs all attributes of a character
  */
  void display();

  /**
  * @brief sets the dialogue of a character 
  * @param [in] fileName the name of the file
  * containing dialogue
  * @throw bad_input if the file does not exist
  * @throw incomplete_settings if the file
  */
  void setDialogue(std::string fileName);

 protected:
  std::string name;
  std::string dialogue;

  /**
  * @brief puts all of the information from
  * character into a string
  */
  std::string toString();
};

/**
 * @class NPC in character.h "character.h"
 * @brief class for npc character type
 */
class NPC : protected Character {
 public:
  /**
  * @brief constructor
  * @param [in] name the name of the character
  * @throw bad_input if name is empty
  */
  virtual Character(std::string name);

  /**
  * @brief destructor
  */
  virtual ~Character();

  /**
  * @brief outputs all attributes of a character
  */
  void display();

  /**
  * @brief sets the dialogue of a character 
  * @param [in] fileName the name of the file
  * containing dialogue
  * @throw bad_input if file does not exist
  * @throw incomplete_settings if file is empty
  */
  void setDialogue(std::string fileName);

 private:
  std::string name;
  std::string dialogue;

  /**
  * @brief puts all of the information from
  * character into a string
  */
  std::string toString();
};

/**
 * @class Player in character.h "character.h"
 * @brief class for player character type
 */
class Player : protected Character {
 public:
  /**
  * @brief constructor
  * @param [in] name the name of the character
  * @throw bad_input if name is empty
  */
  Player(std::string name);

  /**
  * @brief destructor
  */
  ~Character();

  /**
  * @brief function to allow user to pickUp items
  * from ground and NPC's
  * @param [in] &item the item that is being picked up
  * @throw bad_input if the item reference is a
  * nullptr
  */
  void pickUp(const Item &item);

  /**
   * @brief function to allow user to drop items
   * @param [in] name the name of the item that 
   * the user would like to drop
   */
  void drop(std::string name);

  /**
   * @brief function to allow the user to move to
   * a different room.
   * @param [in] question the question for which room
   * the user would like to move to
   * @param [in] options the list of possible options
   * @throw bad_input if the question is empty
   * @throw bad_input if there are options, but
   * the entrees are empty.
   * @throw invalid_size if there are no options
   * @return char the answer for the location
   * the user would like to move to
   */
  char getMoveRoomChoice(std::string question,
                         const std::string options[]);

  /**
   * @brief function to allow the user to choose
   * what activity they do in a room
   * @param [in] question the question for what
   * the user is allowed to do
   * @param [in] options the list of possible options
   * @throw bad_input if the question is empty
   * @throw bad_input if there are options, but 
   * the entrees are empty
   * @throw invalid_size if there are no options
   * @return char the answer for the activity 
   * the user would like to do
   */
  char getRoomActivityChoice(std::string question,
                             const std::string options[]);

  /**
   * @brief function to allow the user to make 
   * an accusation
   * @param [in] question the question for 
   * which person the user would like to accuse
   * @param [in] options the list of possible options
   * @throw bad_input if the question is empty
   * @throw bad_input if there are options, but 
   * the entrees are empty
   * @throw invalid_size if there are no options
   * @return char the answer for the person the
   * user would like to accuse
   */
  char accuse(std::string question,
              const std::string options[]);

  /**
  * @brief outputs all attributes of a character
  */
  void display();

  /**
  * @brief sets the dialogue of a character 
  * @param [in] fileName the name of the file
  * containing dialogue
  * @throw bad_input if the file does not exist
  * @throw incomplete_settings if the file
  * is empty
  */
  void setDialogue(std::string fileName);

 private:
  std::string name;
  std::string dialogue;

  /**
  * @brief puts all of the information from
  * character into a string
  */
  std::string toString();
};

#endif
