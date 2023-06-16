run:
	  g++ game.cpp score.cpp Direction.hpp object.cpp items.cpp map.cpp snake.cpp gate.cpp -o game -lncursesw
	  g++ game.cpp score.cpp direction.hpp object.cpp items.cpp map.cpp snake.cpp -o game -lncursesw