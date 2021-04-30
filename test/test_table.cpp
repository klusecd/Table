#include "gtest.h"
#include "table.h"
#include "hash_table.h"
/*
TEST(UTable, new_unordered_table_empty) {
	Unordered_table ut({});
	ASSERT_EQ(ut.get_size(), 0);
}

TEST(UTable, can_insert)
{
	Unordered_table ut({ {0,1}, {3,5}, {1, 7} });
	ut.insert(2, 3);
	ASSERT_EQ(ut.get_value_by_key(2), 3);
}

TEST(UTable, can_delete)
{
	Unordered_table ut({ {0,1}, {3,5}, {1, 7} });
	ut.erase(3);
	ASSERT_EQ(ut.get_size() , 2);
}

TEST(UTable, get_value)
{
	Unordered_table ut({ {0,1}, {3,5}, {1, 7} });
	ASSERT_EQ(ut.get_value_by_key(1), 7);
}


TEST(OTable, new_unordered_table_empty) {
	Ordered_table ut({});
	ASSERT_EQ(ut.get_size(), 0);
}

TEST(OTable, can_insert)
{
	Ordered_table ut({ {0,1}, {3,5}, {1, 7} });
	ut.insert(2, 3);
	ASSERT_EQ(ut.get_value_by_key(2), 3);
}

TEST(OTable, can_delete)
{
	Ordered_table ut({ {0,1}, {3,5}, {1, 7} });
	ut.erase(3);
	ASSERT_EQ(ut.get_size(), 2);
}

TEST(OTable, get_value)
{
	Ordered_table ut({ {0,1}, {3,5}, {1, 7} });
	ASSERT_EQ(ut.get_value_by_key(1), 7);
}
*/

TEST(Hashtable, can_create_empty_table) {
	Hash_table a(0);
	ASSERT_EQ(a.get_size(), 0);
}

TEST(Hashtable, can_get_value) {
	Hash_table a(1);
	a.insert(1, 10);
	ASSERT_EQ(a.get_value_by_key(1), 10);
}

TEST(Hashtable, can_insert_get_size) {
	Hash_table a(1);
	a.insert(1, 2);
	a.insert(3, 2);
	ASSERT_EQ(a.get_size(), 2);
}

TEST(Hashtable, can_insert_get_val) {
	Hash_table a(2);
	a.insert(1, 2);
	a.insert(2, 2);
	ASSERT_EQ(a.get_value_by_key(1)+ a.get_value_by_key(2), 4);
}

TEST(Hashtable, can_erase) {
	Hash_table a(3);
	a.insert(0, 1);
	a.insert(1, 2);
	a.insert(2, 4);
	a.erase(1);
	ASSERT_EQ(a.get_size(), 2);
}

TEST(Hashtable, can_insert_and_erase_get_size) {
	Hash_table a(3);
	a.insert(0, 1);
	a.insert(1, 2);
	a.insert(2, 4);
	a.insert(3, 4);
	a.erase(1);
	ASSERT_EQ(a.get_size(), 3);
}
