/***
 * @author Raven Huery [raven.huery@uleth.ca]
 * @date 2023-12
*/

#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <list>

#include "Item.h"
#include "Character.h"
#include "Exceptions.h"

TEST(TestCharacter, defaultConctrustorTest) {
    Character* character = new Character();
    Character* char2 = new Character("");
    EXPECT_EQ(character->getName(), "anonymous");
    
    EXPECT_THROW(char2->getName(), bad_input);

    delete character;
    delete char2;
}

TEST(TestCharacter, defaultNPCConstructorTest) {
    NPC* anon = new NPC("Robert", "My name is Robert"); 
    NPC* anon2 = new NPC("", "lol");
    EXPECT_EQ(anon->getName(), "anonymous");
    EXPECT_THROW(anon2->getName(), bad_input);

    delete anon;
    delete anon2;
}

