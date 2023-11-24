/* @Authors - James Huston | jamzhuston@gmail.com |
 *          - 
 *          -
 * Created 10/30/2023
 *
*/

#ifndef ITEM.HPP
#define ITEM.HPP

#include <iostream>
#include <string>
#include <fstream>


/**
 * @class Item in Item.hpp "Item.hpp"
 * @brief Abstract superclass for different item types:
 */ 
class Item {
  public:
  Item();

  Item(std::string name, std::string fileName);

  virtual ~Item();

  template<class T>
  virtual ostream& createOstream(ostream& out, const T&);
  
  void setDescription();

  virtual void inspectItem();

  protected:
  std::string name;
  std::string description;
};


class ClueItem : Item {
  public:
  
  ClueItem();
  
  ~SecretItem();

  ostream& createOstream(ostream& out, const ClueItem&);

  friend ostream& operator<<(ostream& os, const ClueItem&);

  void inspectItem();  
};

class SecretItem : Item {
  public:

  SecretItem();

  ~SecretItem();

  ostream& createOstream(ostream& out, const SecretItem&);

  friend ostream& operator<<(ostream& os, const SecretItem&);

  void inspectItem();
};

#endif
