CXX = g++
CXXFLAGS = -std=c++11 -Wall -DGL_SILENCE_DEPRECATION
INCLUDES = -I/opt/homebrew/include
LIBS = -L/opt/homebrew/lib -lglfw -framework OpenGL
 
SRCS = main.cpp snake.cpp food.cpp
OBJS = $(SRCS:.cpp=.o)

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) main

help:
	@echo "Available Commands"
	@echo "========================"
	@echo "main - Build the program"
	@echo "clean - Clean up the program"