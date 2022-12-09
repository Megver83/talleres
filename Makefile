# Basado en https://stackoverflow.com/a/32160588
appname := month-avl

CXX := g++
CXXFLAGS := -Wall -g

srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	mkdir -p out
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o out/$(appname) $(objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -rf out
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend
