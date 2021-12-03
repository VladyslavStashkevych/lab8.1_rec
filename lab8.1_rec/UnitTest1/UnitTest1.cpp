#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../lab8.1_rec/lab8.1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:
	TEST_METHOD(TestMethod1) {
		char s[100] = "aaabbbccc";
		char g[100] = "******";
		int* arr = new int[34];
		char* c = new char[101];
		char* tmp = new char[strlen(s) * 2 / 3 + 1];
		char* t = tmp;
		tmp[0] = '\0';
		size_t len = strlen(s);
		int count = 0; 
		count = Count(s, "abc", arr, count, 0, false, 0);
		c = Change(s, tmp, t, 0, arr, len, 0);
		Assert::AreEqual(3, count);
		Assert::AreEqual(g, c);
	}
	};
}
