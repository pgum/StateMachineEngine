CXX=g++-4.9
CXXFLAGS=-Wall -Werror -std=c++14
IFLAGS=./Include
LFLAGS_TESTS=catch.runner
OBJDIR=./Obj
SRCDIR=./Source
OBJS=$(OBJDIR)/Message.o $(OBJDIR)/State.o $(OBJDIR)/StateMachine.o $(OBJDIR)/test.o $(OBJDIR)/catch.runner.o
TSTFWK=/CatchRunner
TSTDIR=./Tests
TSTEXE=run.test

all: $(OBJDIR) $(TSTEXE)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean: 
	-@rm -f $(OBJDIR)/*.o ; rmdir $(OBJDIR)

$(OBJDIR)/catch.runner.o: $(TSTDIR)$(TSTFWK)/catch.runner.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Message.o: $(SRCDIR)/Message.cpp
	$(CXX) $(CXXFLAGS) -I$(IFLAGS) -c $< -o $@

$(OBJDIR)/State.o: $(SRCDIR)/State.cpp
	$(CXX) $(CXXFLAGS) -I$(IFLAGS) -c $^ -o $@

$(OBJDIR)/StateMachine.o: $(SRCDIR)/StateMachine.cpp
	$(CXX) $(CXXFLAGS) -I$(IFLAGS) -c $< -o $@

$(OBJDIR)/test.o: $(TSTDIR)/test.cpp
	$(CXX) $(CXXFLAGS) -I$(IFLAGS) -I$(TSTDIR)$(TSTFWK) -c $< -o $@

$(TSTEXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(IFLAGS) -L$(TSTDIR)$(TSTFWK) $(OBJS) -o $(TSTEXE)

