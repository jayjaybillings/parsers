/**----------------------------------------------------------------------------
 Copyright  2016-, UT-Battelle, LLC
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
#ifndef PARSERS_STRINGUTILS_H_
#define PARSERS_STRINGUTILS_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <string>

namespace fire {

/**
 * This is a utility function used for splitting strings.
 * @param the strings to be split
 * @param a delimiter that marks where tokens should be split.
 * @return a vector with a string for each entry in the original.
 */
inline std::vector<std::string> splitString(const std::string & line,
		const std::string & delimiter) {

	std::string value;
	std::istringstream ss(line);
	std::vector < std::string > lineVec;
	//Split the line and push each element into the line list.
	while (std::getline(ss, value, *delimiter.c_str())) {
	      lineVec.push_back(value);
	}
	return lineVec;
}

/**
 * This is a utility function used for splitting strings. It is a
 * convenience function for calling splitLine(line,delimiter) with
 * delimiter equal to a single whitespace character.
 * @param the strings to be split
 * @return a vector with a string for each entry in the original.
 */
inline std::vector<std::string> splitString(const std::string & line) {
	std::string delimiter = " ";
	return splitString(line,delimiter);
}

} /* namespace fire */

#endif /* PARSERS_STRINGUTILS_H_ */
