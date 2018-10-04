# Parsers

Parsers is a simple set of file parsing utilities for scientific libraries.

## Documentation

Documentation in Parsers is generated via Doxygen by running "make doc" during the 
build. 

You can run "make doc" from build directory to generate the API documentation. Doxygen handles most of the required documentation without developer 
intervention. This means that in some cases there may be classes that seem to 
have minimal documentation in the source, like classes that implement interfaces 
and provide no additional functionality, but are in fact quite well documented 
by Doxygen. Most IDEs will also auto-generate descriptions for developers too, 
so the author(s) see no need to cover every piece of code with comments.

## Prerequisites
You will need git and cmake to build Parsers.

## Checkout and build

From a shell, execute the following commands to compile the code:


```bash
git clone https://github.com/jayjaybillings/parsers
mkdir parsers-build
cd parsers-build
cmake ../parsers -DCMAKE_BUILD_TYPE=Debug -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=4.5
make
```

The commands above will get the code running, but it will not run the tests, generate the 
documentation, or install the libraries. Issue the following commands to do that:
```bash
make test
make doc
make install
```


Build flags, such as -Wall, can be set by prepending the CXX_FLAGS variable to 
the cmake command as such

```bash
CXX_FLAGS='-Wall' cmake ../parsers -DCMAKE_BUILD_TYPE=Debug -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=4.5
```

Optimization flags should be handled by setting -DCMAKE_BUILD_TYPE=Release 
instead of Debug. Likewise, an optimized build with debug information can be 
acheived by setting -DCMAKE_BUILD_TYPE=RelWithDebugInfo.

## License

See the LICENSE file licensing and copyright information. In short, 3-clause BSD.

## Questions
Questions can be directed to me at billingsjj <at> ornl <dot> gov.
