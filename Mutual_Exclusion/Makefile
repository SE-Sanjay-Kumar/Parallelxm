CXX 		= g++
CXXFLAGS 	= -Wall -std=c++11
TARGET 		= atomic_obj
SRC 		= atomic_obj.cpp

$(TARGET) : $(SRC) 
	$(CXX) ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean: 
	rm -f ${TARGET}