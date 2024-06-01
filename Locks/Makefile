CXX 		= g++
CXXFLAGS 	= -Wall -std=c++17
TARGET 		= shared_mutex
SRC 		= shared_mutex.cpp

$(TARGET) : $(SRC) 
	$(CXX) ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean: 
	rm -f ${TARGET}