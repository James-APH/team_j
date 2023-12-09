/**
 * @author James Huston [huston@uleth.ca]
 * @author Raven Huery [raven.huery@uleth.ca]
 * @author Parker Regier [tyre.regier@uleth.ca]
 * @date 2023-11
 */

#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <list>

#include "Item.h"
#include "Character.h"

TEST(TestCharacter, defaultConctrustorTest) {
    Character* character = new Character();
    Character* char2 = new Character("");
    EXPECT_EQ(character->getName(), "anonymous");

    delete character;
    delete char2;
}

