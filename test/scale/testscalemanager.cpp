#include "gtest/gtest.h"
#include "scalemanager.h"
#include <cmath>
TEST (ScaleManagerTest, PositiveNos) { 
    EXPECT_EQ (18.0, sqrt (324.0));
    EXPECT_EQ (25.4, sqrt (645.16));
    EXPECT_EQ (50.332, sqrt (2533.310224));
}

TEST (ScaleManagerTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, sqrt (0.0));
    //ASSERT_EQ (‑1, sqrt (‑22.0));
}

