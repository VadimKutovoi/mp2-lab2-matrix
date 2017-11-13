#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> a(3), b;
	for (int i = 0; i < a.GetSize(); i++) {
		for (int j = i; j < a.GetSize(); j++) {
			a[i][j] = i + j;
		}
	}
	b = a;
	
	for (int i = 0; i < a.GetSize(); i++) {
		for (int j = i; j < a.GetSize(); j++) {
			EXPECT_TRUE(a[i][j] == b[i][j]);
		}
	}
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> a(1);
	a[0][0] = 1;

	TMatrix<int> b(a);
	b[0][0] = 2;
	
	EXPECT_NE(a[0][0], b[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> a(5);
	
	EXPECT_EQ(5, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> a(1);
	
	a[0][0] = 1;

	EXPECT_EQ(1, a[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> a(1);

	ASSERT_ANY_THROW(a[-1][-1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(1);

	ASSERT_ANY_THROW(a[3][3] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> a(5);

	ASSERT_NO_THROW(a = a);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> a(5), b(5);

	ASSERT_NO_THROW(a = b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> a(5), b(2);
	b = a;
	
	EXPECT_EQ(5, b.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> a(5), b(2);
	
	ASSERT_NO_THROW(a = b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> a(2), b(2);
	
	for (int i = 0; i < a.GetSize(); i++) {
		for (int j = i; j < a.GetSize(); j++) {
			a[i][j] = 1;
			b[i][j] = 1;
		}
	}
	
	EXPECT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a(5);
	
	EXPECT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> a(5), b(2);
	
	EXPECT_FALSE(a == b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a(3), b(3), res;
	
	for (int i = 0; i < a.GetSize(); i++) {
		for (int j = i; j < a.GetSize(); j++) {
			a[i][j] = 1;
			b[i][j] = 1;
		}
	}
	res = a + b;
	
	for (int i = 0; i < res.GetSize(); i++) {
		for (int j = i; j < res.GetSize(); j++) {
			EXPECT_EQ(2, res[i][j]);
		}
	}
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a(1), b(2);
	
	ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a(3), b(3), res;
	for (int i = 0; i < a.GetSize(); i++) {
		for (int j = i; j < a.GetSize(); j++) {
			a[i][j] = 1;
			b[i][j] = 1;
		}
	}
	res = a - b;
	for (int i = 0; i < res.GetSize(); i++) {
		for (int j = i; j < res.GetSize(); j++) {
			EXPECT_EQ(0, res[i][j]);
		}
	}
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a(1), b(2);
	
	ASSERT_ANY_THROW(a - b);
}


