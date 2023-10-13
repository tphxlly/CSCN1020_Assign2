#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int*, int*), getArea(int*, int*), setLength( int, int*), setWidth(int, int*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(GetPerimeter)
		{
			//This tests the getPerimeter function using 2l+2w=p
			//where l=6, w=6, and the expected p = 24
			int length = 6;
			int width = 6;
			int result = getPerimeter(&length, &width);
			Assert::AreEqual(24, result);
		}

		TEST_METHOD(GetArea)
		{
			//This tests the getArea function using l*w=a
			//where l=6, w=6, and the expected a = 36
			int length = 6;
			int width = 6;
			int result = getArea(&length, &width);
			Assert::AreEqual(36, result);
		}

		TEST_METHOD(SetLength1)
		{
			//This tests the setLength function using a value of 5
			//to determine whether the function will build correctly
			int length;
			setLength(5, &length);
			int result = *(&length);
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(SetLength2)
		{
			//This tests the setLength function using a preset length value
			//to test whether setLength will change the value of length
			int length = 50;
			setLength(25, &length);
			int result = *(&length);
			Assert::AreEqual(25, result);
		}

		TEST_METHOD(SetLength3)
		{
			//This tests the setLength function using a value lower than the
			//requirement parameters to test if the function logic is correct
			//The predetermined value is 1, so if an invalid value is assigned to length,
			//it shouldn't be accepted, and length should still be set to 1.
			int length=1;
			setLength(0, &length);
			int result = *(&length);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(SetWidth1)
		{
			//This tests the setWidth function using a value of 5
			//to determine whether the function will build correctly
			int width;
			setLength(5, &width);
			int result = *(&width);
			Assert::AreEqual(5, result);
		}

		TEST_METHOD(SetWidth2)
		{
			//This tests the setWidth function using a preset length value
			//to test whether setWidth will change the value of length
			int width = 50;
			setLength(25, &width);
			int result = *(&width);
			Assert::AreEqual(25, result);
		}

		TEST_METHOD(SetWidth3)
		{
			//This tests the setWidth function using a value higher than the
			//requirement parameters to test if the function logic is correct
			//The predetermined value is 1, so if an invalid value is assigned to width,
			//it shouldn't be accepted, and width should still be set to 1.
			int width = 1;
			setLength(100, &width);
			int result = *(&width);
			Assert::AreEqual(1, result);
		}


	};
}
