#include "pch.h"
#include "CppUnitTest.h"
#include "../SE_individual_hw/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace IntersectTest1
{
	TEST_CLASS(IntersectTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line l1 = Line(1, 1, 2, 2);
			Line l2 = Line(1, 1, 3, 1);
			Point p = cal_intersection(l1, l2);
			Point p0 = Point(1, 1);
			Assert::AreEqual(p, p0);
		}
	};
}
namespace Microsoft { 
	namespace VisualStudio { 
		namespace CppUnitTestFramework { 
			template<>             
			static std::wstring ToString<Point>(const Point& p) { 
			return L"Some string representing coordinate."; 
			} 
		} 
	} 
}