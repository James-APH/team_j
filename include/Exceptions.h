/**
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Nicole Wilson [n.wilson@uleth.ca]
 * @author Dr. Anvik [john.anvik@uleth.ca]
 * @date 12/2023
*/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
 * @brief Useless nullpointer as input
*/
class de_trop_nullptr: public std::runtime_error {
 public:
    /**
     * @param errMessage An error message
    */
    explicit de_trop_nullptr(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

/**
 * @brief Received bad input from user
*/
class bad_input: public std::runtime_error {
 public:
    /**
     * @param errMessage An error message
    */
    explicit bad_input(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

/**
 * @brief Received empty string as input
*/
class empty_string: public std::runtime_error {
 public:
    /**
     * @param errMessage An error message
    */
    explicit empty_string(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

#endif //EXCEPTIONS_H_INCLUDED
