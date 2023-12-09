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


TEST(TestNPC, defaultNPCConstructorTest) {
    NPC* anon = new NPC("Craig", "Lol");
    EXPECT_EQ(anon->getName(), "Craig");

    delete anon;
}

TEST(TestNPC, copyNPCConstructorTest) {
    NPC* solidAnon = new NPC("Rose", "Ur ded kiddo :3");
    NPC* liquidAnon = new NPC(*solidAnon);

    EXPECT_EQ(liquidAnon->getName(), "Rose");

    delete liquidAnon;
    delete solidAnon;
}
