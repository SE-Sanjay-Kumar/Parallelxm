CXX 		= g++
CXXFLAGS 	= -Wall -std=c++11
TARGET 		= detached_thread
SRC 		= detached_thread.cpp

$(TARGET) : $(SRC) 
	$(CXX) ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean: 
	rm -f ${TARGET}