CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g
CXXFLAGS += -DNO_PROBLEM_MAIN

#CXXFLAGS += -fsanitize=address
#LDFLAGS =  -fsanitize=address

SRC = 
SRC += a.cpp
SRC += b.cpp
SRC += c.cpp
SRC += d.cpp
SRC += e.cpp
SRC += f.cpp
SRC += main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)