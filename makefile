app:
	g++ z.cpp src/generators.cpp src/Person.cpp src/tests.cpp src/UI.cpp src/viewer.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system