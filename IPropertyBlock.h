/**----------------------------------------------------------------------------
 Copyright (c) 2015-, Jay Jay Billings
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
#ifndef PARSERS_IPROPERTYBLOCK_H_
#define PARSERS_IPROPERTYBLOCK_H_

#include <string>
#include <vector>

namespace fire {

/**
 * This class is defines the basic interface for managing property objects.
 * Properties are basic key-value pairs that are organized in one or more
 * blocks in a source.
 */
class IPropertyBlock {
public:

	/**
	 * This is a convenience operation that returns all properties in the
	 * block.
	 * @return the list of all property keys in the block
	 */
    virtual const std::vector<std::string> & getKeys() = 0;

    /**
     * This is a convenience operation that returns all values in the block.
     * @return the list of all values in the block
     */
    virtual const std::vector<std::string> & getValues() = 0;

    /**
     * This operation returns the property value associated with the key.
     * @param key the property key
     * @return the property value associated with the key
     */
    virtual std::string getValue(const std::string & key) = 0;

    /**
     * This operation returns the name of the property block.
     * @return the block name
     */
    virtual std::string getName() = 0;

    /**
     * This operation returns the number of key-value pairs in the block.
     * @return the number of key-value pairs
     */
    virtual int size() = 0;
};

} /* namespace fire */

#endif /* PARSERS_IPROPERTYBLOCK_H_ */
