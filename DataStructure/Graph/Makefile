CXX             = g++ 
SRCS            = $(wildcard *.cpp) $(wildcard *.c)
OBJS            = $(SRCS:.cpp=.o)
TARGET          = run
INC             = -I/usr/local/include/boost \
				  -I../PriorityQueue \
 
all : $(TARGET)
	$(CXX) -o $(TARGET) $(OBJS) $(INC) $(LIB_DIRS) $(LIBS)
 
$(TARGET):
	$(CXX) -c $(SRCS) $(INC) $(LIB_DIRS) $(LIBS)
 
clean :
	rm -f $(TARGET)
	rm -f *.o
