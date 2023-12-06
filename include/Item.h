/** 
 * @author - James Huston [jamzhuston@gmail.com]
 * @date 11/2023 12/2023
*/

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>

/**
 * @class Item in Item.h "Item.h"
 * @brief Abstract superclass for different item types:
 */ 
class Item {
 public:
  /**
  * @brief Constructor initializes name, and image of item
  * @ param[in] name the name of the item
  * @ param[in] useLocation the location the item will be used
  * @ param[in] description the description of the item
  * @throw bad_input if the 
  * @throw bad_input if name is empty
  * @throw bad_input if description is empty
  */
  Item(std::string name = "name", std::string useLocation = "location",
       std::string description = "description");

  /**
  * @brief copy constructor
  * @param[in] item, the item that is being copied
  * @throw bad_input if item is nullptr
  */
  Item(const Item &item);

  /**
  * @brief Default Destructor
  */
  virtual ~Item();

  /**
  * @brief gets the name of the item
  * @return string the name of the item
  */
  std::string getName() const;

  /**
  * @brief gets the description of the item
  * @return string the description of the item
  */
  std::string getDescription() const;

  /**
   * @brief gets the location where the item should be used 
   * @brief returns the location where the item should be used
   */
  std::string getUselocation() const;

  /**
  * @brief checks if two items are equivalent
  * @return true if the items are equivalent
  * @throw bad_input if item is nullptr
  */ 
  bool equals(const Item& item) const;

  /**
  * @brief puts the information in from item into a string
  * @return string string of item details
  */
  std::string toString() const;

 private:
  std::string name;
  std::string description;
  std::string useLocation;
};

#endif
