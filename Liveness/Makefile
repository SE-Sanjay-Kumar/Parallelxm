CXX 		= g++
CXXFLAGS 	= -Wall -std=c++17
TARGET 		= live_lock
SRC 		= live_lock.cpp

$(TARGET) : $(SRC) 
	$(CXX) ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean: 
	rm -f ${TARGET}