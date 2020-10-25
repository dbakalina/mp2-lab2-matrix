#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> a(5);
	for (int i = 0; i < a.GetSize(); i++)
	{
		a[i] = 1;
	}
	TVector<int> b(a);
	EXPECT_EQ(b, a);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i * 3;
	}
	TVector<int> v1(v);
	EXPECT_NE(&v[0], &v1[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-2] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector <int> v(100);
	ASSERT_ANY_THROW(v[200]=1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector <int> a(5);
	a[0] = 1;
	TVector <int> b(a);
	a = a;
	EXPECT_EQ(a, b);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector <int> a(5),b(5);
	b[0] = 1;
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector <int> b(5), a(4);
	b[0] = 1;
	a = b;
	EXPECT_EQ(5, a.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector <int> a(5), b(3);
	b[0] = 1;
	a = b;
	EXPECT_EQ(a, b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector <int> a(5), b(5);
	EXPECT_EQ(true, a == b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector <int> a(5);
	EXPECT_EQ(true, a == a);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector <int> a(5), b(4);
	EXPECT_EQ(false, a == b);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector <int> a(5), b(5);

	b = b + 5;
	for (int i = a.GetStartIndex(); i < (a.GetSize()) + a.GetStartIndex(); i++)
	{
		a[i] += 5;
	}
	EXPECT_EQ(a, b);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector <int> a(5), b(5);
	b = b - 5;
	for (int i = a.GetStartIndex(); i < (a.GetSize()) + a.GetStartIndex(); i++)
	{
		a[i] -= 5;
	}
	EXPECT_EQ(a, b);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector <int> a(5), b(5);
	b = b * 5;
	for (int i = a.GetStartIndex(); i < (a.GetSize()) + a.GetStartIndex(); i++)
	{
		a[i] *= 5;
	}
	EXPECT_EQ(a, b);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector <int> a(5), b(5),res(5);
	for (int i = 0; i < a.GetSize(); i++)
	{
		a[i] = 1;
	}
	for (int i = 0; i < b.GetSize(); i++)
	{
		b[i] = 2;
	}
	res = a + b;
	EXPECT_EQ(res, a + b);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector <int> a(5), b(4);
	ASSERT_ANY_THROW (a + b);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector <int> a(5), b(5), res(5);
	for (int i = 0; i < a.GetSize(); i++)
	{
		a[i] = 5;
	}
	for (int i = 0; i < b.GetSize(); i++)
	{
		b[i] = 2;
	}
	res = a - b;
	EXPECT_EQ(res, a - b);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector <int> a(5), b(4);
	ASSERT_ANY_THROW(a - b);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector <int> a(5), b(5), res(5);
	for (int i = 0; i < a.GetSize(); i++)
	{
		a[i] = 1;
	}
	for (int i = 0; i < b.GetSize(); i++)
	{
		b[i] = 5;
	}
	res = a * b;
	EXPECT_EQ(res, a * b);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector <int> a(5), b(4);
	ASSERT_ANY_THROW(a * b);
}

