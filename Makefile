CXX = g++
CXXFLAGS = -std=c++11 -Wall -DGL_SILENCE_DEPRECATION
INCLUDES = -I/opt/homebrew/Cellar/glfw/3.4/include
LIBS = -L/opt/homebrew/Cellar/glfw/3.4/lib -lglfw -framework OpenGL
 
main: Snake.cpp
	$(CXX) $(CXXFLAGS) Snake.cpp $(INCLUDES) $(LIBS) -o main