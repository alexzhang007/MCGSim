CXXFLAGS=-Wall # -DDEBUG_BUILD 
OPTFLAGS=-O3 -Wno-deprecated
LIB_DIR=../lib
TOP_DIR=../..
CXX=g++
FPIC= -fPIC -c
SHARED= -shared 
OBJECT=IsectTrisScene.o
SRC_FILE=IsectTrisScene.cpp
HEAD_FILE=	IsectTrisScene.h 
INCLUDE =  -I  $(TOP_DIR) \
		   -I /usr/include \
		   -I  $(TOP_DIR)/util \
		   -I  $(TOP_DIR)/raster

all : $(OBJECT)

$(OBJECT) : $(SRC_FILE) $(HEAD_FILE)
	$(CXX) $(OPTFLAGS) $(INCLUDE) $(FPIC) $(SRC_FILE) -o $@

clean:
	rm $(OBJECT);
