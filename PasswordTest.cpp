/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, multiple_letters)
{
    Password p;
    int actual = p.count_leading_characters("aaaaZ");
    ASSERT_EQ(4, actual);
}
TEST(PasswordTest, switch_after_one)
{
    Password p;
    int actual = p.count_leading_characters("abbb");
    ASSERT_EQ(1, actual);
}
TEST(PasswordTest, empty_string)
{
    Password p;
    int actual = p.count_leading_characters("");
    ASSERT_EQ(0, actual);
}


TEST(PasswordTest, mixed_case_true)
{
    Password p;
    int actual = p.count_leading_characters("Ab");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, mixed_case_all_lowercase_false)
{
    Password p;
    int actual = p.count_leading_characters("abc");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case_all_uppercase_false)
{
    Password p;
    int actual = p.count_leading_characters("ABC");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_case_empty_string_false)
{
    Password p;
    int actual = p.count_leading_characters("");
    ASSERT_FALSE(actual);
}
