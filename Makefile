CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a
OBJECTS = main.o Beatmap.o BeatmapParser.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
