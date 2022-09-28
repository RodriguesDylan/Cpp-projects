# For cpp projects 
# Dylan Rodrigues 2022
# Usage :
# make				# compile source code into objects into executable	
# make clean		# remove all objects
# make fullclean 	# remove all objects and executable
# make debug		# print source files and object files

appname = casino

CXX = g++
CXXFLAGS = -g -Wall -Wextra

SRCS=$(wildcard *.cpp)
OBJS=$(subst .cpp,.o,$(SRCS))

all: ${appname}

${appname}: ${OBJS}
	@echo "Creating executable..."
	${CXX} ${CXXFLAGS} -lm ${OBJS} -o casino
# Optional lazy auto clean 
	@echo "Cleaning up..."
	rm -rf *.o

%.o: %.cpp
	@echo "Creating object..."
	${CXX} $< -c

clean:
	@echo "Cleaning up..."
	rm -rf *.o 

fullclean: clean
	@echo "Cleaning executable..."
	rm casino

debug:
	@echo ${SRCS}
	@echo ${OBJS}
