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

TEST(TestPlayer, defaultPlayerConstructor) {
    Item thing1;
    Player* thatsMe = new Player("Fabio", thing1);

    EXPECT_EQ(thatsMe->getName(), "Fabio");
    delete thatsMe;
}

