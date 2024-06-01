CXX 		= g++
CXXFLAGS 	= -Wall -std=c++20
TARGET 		= race_condition
SRC 		= race_condition.cpp

$(TARGET) : $(SRC) 
	$(CXX) ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean: 
	rm -f ${TARGET}