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

TEST(TestPlayer, defaultPlayerConstructor) {
    Item thing1;
    Player* thatsMe = new Player("Fabio", thing1);

    EXPECT_EQ(thatsMe->getName(), "Fabio");
//If it gets implemented plz check that default items in inventory are there
    EXPECT_EQ(thatsMe->findItem(thing1), true);
    delete thatsMe;
}

// TEST(TestPlayer, playerPickupItemTest) {
//     Item thing1, thing2;
//     Player* thatsMe = new Player("Fabio", thing1);

//     EXPECT_EQ(thatsMe->findItem(thing2), false);
//     thatsMe->pickUp(thing2);
//     EXPECT_EQ(thatsMe->findItem(thing2), true);
//     delete thatsMe;
// }

