#include <gtest.h>
#include "queue.h"
TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<double> x);
}

TEST(Queue, constructor_with_parametr) {
	ASSERT_NO_THROW(Queue<int>x(3));
}

TEST(Queue, can_push_right) {
	Queue<bool> x;
	ASSERT_NO_THROW(x.push(true));
}

TEST(Queue, can_get_size) {
	Queue<double> x;
	x.push(2.41);
	x.push(2.41);
	x.push(2.41);
	x.push(2.41);
	EXPECT_EQ(4,x.getsize());
}

TEST(Queue, can_check_empty) {
	Queue<int> x;
	EXPECT_TRUE(x.empty());
}

TEST(Queue, cant_pop_if_queue_is_empty) {
	Queue<int> x;
	ASSERT_ANY_THROW(x.pop());
}

TEST(Queue, can_give_front_value) {
	Queue<int> x;
	x.push(1);
	x.push(2);
	x.push(3);
	EXPECT_EQ(1, x.front());
}

TEST(Queue, cant_give_front_value_if_stack_is_empty) {
	Queue<int>x;
	ASSERT_ANY_THROW(x.front());
}

TEST(Queue, resize_work_correctly) {
	Queue<int>x;
	x.push(1);
	x.push(2);
	x.pop();
	x.push(3);
	x.pop();
	x.pop();
	x.push(4);
	x.push(5);
	x.push(6);
	EXPECT_EQ(3, x.getsize());
}
