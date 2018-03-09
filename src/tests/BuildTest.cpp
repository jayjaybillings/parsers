
/**----------------------------------------------------------------------------
 Copyright  2015-, UT-Battelle, LLC
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 * Neither the name of fern nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 Author(s): Jay Jay Billings (jayjaybillings <at> gmail <dot> com)
 -----------------------------------------------------------------------------*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Parsers

#include <boost/test/included/unit_test.hpp>
#include <build.h>
#include <vector>

using namespace std;
using namespace fire;

/**
 * A simple test struct for the tests.
 */
struct TestStruct {
	int A;
	double B;
	int C;
	TestStruct() : A(5), B(0.0), C(0) {};
	TestStruct(int value) : A(value), B(0.0), C(0) {};
	TestStruct(int value, double otherValue, int finalValue) : A(value), B(otherValue), C(finalValue) {};
};


/**
 * This operation checks build<TestStruct>().
 */
BOOST_AUTO_TEST_CASE(checkBuild) {

	TestStruct myStruct = build<TestStruct>();
	BOOST_REQUIRE_EQUAL(5,myStruct.A);
	BOOST_REQUIRE_CLOSE(0.0,myStruct.B,1.0e-8);
	BOOST_REQUIRE_EQUAL(0,myStruct.C);

	return;
}

/**
 * This operation checks build<TestStruct>(int).
 */
BOOST_AUTO_TEST_CASE(checkBuildWith2Args) {

	TestStruct myStruct = build<TestStruct,int>(2);
	BOOST_REQUIRE_EQUAL(2,myStruct.A);
	BOOST_REQUIRE_CLOSE(0.0,myStruct.B,1.0e-8);
	BOOST_REQUIRE_EQUAL(0,myStruct.C);

	return;
}

/**
 * This operation checks build<TestStruct>(Args...).
 */
BOOST_AUTO_TEST_CASE(checkVariadicBuild) {

	TestStruct myStruct = build<TestStruct,int,double,int>(2,5.0,10);
	BOOST_REQUIRE_EQUAL(2,myStruct.A);
	BOOST_REQUIRE_CLOSE(5.0,myStruct.B,1.0e-8);
	BOOST_REQUIRE_EQUAL(10,myStruct.C);

	return;
}

/**
 * This operation checks  the container verison of build<>().
 */
BOOST_AUTO_TEST_CASE(checkContainerBuild) {

	vector<TestStruct> testContainer = build<vector,TestStruct>(8);
	BOOST_REQUIRE_EQUAL(8,testContainer.size());

	return;
}
