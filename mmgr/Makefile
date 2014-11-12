CXXFLAGS=-Wall # -DDEBUG_BUILD 
OPTFLAGS=-O3

LIB_DIR=../lib

CXX=g++
FPIC= -fPIC -c
SHARED= -shared 
LIB_OBJECT=libmmgr.so
OBJECT=mmgr.o
SRC_FILE=mmgr.cpp
HEAD_FILE=mmgr.h nommgr.h



all : $(LIB_OBJECT)

$(LIB_OBJECT) : $(OBJECT)
	$(CXX) $^ $(SHARED) $(OPTFLAGS) -fPIC -o $@
	mv $@ $(LIB_DIR)

$(OBJECT) : $(SRC_FILE) $(HEAD_FILE)
	$(CXX) $(OPTFLAGS) $(FPIC) $< -o $@

clean:
	rm $(LIB_DIR)/$(LIB_OBJECT); rm $(OBJECT);
