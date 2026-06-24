CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# 1. Сборка и получение исполняемого файла
all: build

build: ChessMath.o
	$(CXX) $(CXXFLAGS) main.cpp ChessMath.o -o a.out

# Компиляция объекта библиотеки
ChessMath.o: ChessMath.cpp ChessMath.h
	$(CXX) $(CXXFLAGS) -c ChessMath.cpp -o ChessMath.o

# 2. Сборка с отладочными символами (-g)
debug: CXXFLAGS += -g
debug: build_debug

build_debug: ChessMath_debug.o
	$(CXX) $(CXXFLAGS) main.cpp ChessMath.o -o a.out_debug

ChessMath_debug.o: ChessMath.cpp ChessMath.h
	$(CXX) $(CXXFLAGS) -c ChessMath.cpp -o ChessMath.o

# 3. Очистка директории от лишних файлов
clean:
	rm -f *.o a.out a.out_debug libchessmath.so libchessmath.a libchessmath.dll app.exe main.exe old_app
