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


TEST(TestNPC, defaultNPCConstructorTest) {
    NPC* anon = new NPC("Robert", "Lol");
    EXPECT_EQ(anon->getName(), "Robert");

    delete anon;
}

TEST(TestNPC, noNameNPCConstructTest) {
    NPC* anon2 = new NPC("", "");
    EXPECT_THROW(anon2->getName(), bad_input);

    delete anon2;
}

TEST(TestNPC, copyNPCConstructorTest) {
    NPC solidAnon = NPC("Jhonfrey", "Ur ded kiddo :3");
    NPC* liquidAnon = new NPC(solidAnon);

    EXPECT_EQ(liquidAnon->getName(), "Jhonfrey");

    delete liquidAnon;
}
