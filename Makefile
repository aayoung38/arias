
.PHONY = all clean obj

CC = g++
CFLAGS = -c
LINKERFLAG = -l
INCLUDEFLAG = -I
OUTPUTFLAG = -o

COMMONTYPES=common/types
NOTEDIR=common/types/note
GUITARDIR=common/types/instrument/guitar
EXCEPTIONDIR=common/exceptions
PLATFORMDIR=platform/linux

INCDIRS= $(INCLUDEFLAG) $(COMMONTYPES) $(INCLUDEFLAG) $(NOTEDIR) $(INCLUDEFLAG) $(GUITARDIR) $(INCLUDEFLAG) $(EXCEPTIONDIR) $(INCLUDEFLAG) common

noteobjs = $(NOTEDIR)/notevalue.o $(NOTEDIR)/note.o $(NOTEDIR)/noteletter.o $(NOTEDIR)/noteinterval.o
guitarobjs = $(GUITARDIR)/guitarnote.o $(GUITARDIR)/guitarstring.o $(GUITARDIR)/guitar.o
platformobjs = $(PLATFORMDIR)/main.o

all: $(noteobjs) $(guitarobjs) $(platformobjs)


deps := $(patsubst %.o,%.d,$(noteobjs)) 

# Tell the current Makefile to read onje or more other Makefiles before continuing
-include $(deps)
DEPFLAGS= -MMD -MF $(@:.o=.d)

arias: $(PLATFORMDIR)/main.o ${noteobjs} $(guitarobjs) common/audiogenerator.o
	g++ $^ -o arias

#obj:
#	mkdir $(OBJDIR)

%.o: %.cpp
	@echo $@
	$(CC) $(CFLAGS) $(INCDIRS)/ $< $(DEPFLAGS) $(OUTPUTFLAG) $@

clean:
	@echo "Cleaning up..."
	find . -name "*.d" -type f -delete
	find . -name "*.o" -type f -delete
  
