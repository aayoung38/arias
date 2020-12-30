
.PHONY = all clean

CC = g++

LINKERFLAG = -l

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp%)

all: ${BINS}

%: %.o
	@echo "Checking..."
	${CC} ${LINKERFLAG} $< -o $@
	
%.o: %.cpp
	@echo "Creating object..."
	${CC} -c $<
	
clean:
	@echo "Cleaning up..."
	rm  -rvf *.o ${BINS}
	
  
