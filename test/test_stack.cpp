#include <gtest.h>
#include "stack.h"
TEST(Stack, can_create_queue) {
	ASSERT_NO_THROW(Stack<double> x);
}

TEST(Stack, constructor_with_paramter) {
	ASSERT_NO_THROW(Stack<double> x(5.2));
}

TEST(Stack, can_push_right) {
	Stack<int> x;
	ASSERT_NO_THROW(x.push(4));
}
TEST(Stack, can_get_size) {
	Stack<int>x;
	x.push(1);
	x.push(1);
	x.push(1);
	EXPECT_EQ(3, x.getsize());
}
TEST(Stack, can_check_empty) {
	Stack<int>x;
	EXPECT_TRUE(x.empty());
}
TEST(Stack, cant_pop_if_stack_is_empty) {
	Stack<int>x;
	ASSERT_ANY_THROW(x.pop());
}
TEST(Stack, can_give_top_element) {
	Stack<int>x(1);
	x.push(2);
	x.push(3);
	EXPECT_EQ(3, x.top());
}
TEST(Stack, cant_give_top_element_if_stack_is_empty) {
	Stack<int>x;
	ASSERT_ANY_THROW(x.top());
}

TEST(Stack, test_many_pushes_and_pops) {
	Stack<int>x(1);
	for (int i = 2; i < 21; i++) {
		x.push(i);
	}
	for (int i = 20; i > 0; i--) {
		EXPECT_EQ(x.top(), i);
		x.pop();
	}
}