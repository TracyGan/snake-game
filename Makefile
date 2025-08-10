CXX = g++
CXXFLAGS = -std=c++11 -Wall -DGL_SILENCE_DEPRECATION
INCLUDES = -I/opt/homebrew/Cellar/glfw/3.4/include
LIBS = -L/opt/homebrew/Cellar/glfw/3.4/lib -lglfw -framework OpenGL
 
main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(INCLUDES) $(LIBS) -o main