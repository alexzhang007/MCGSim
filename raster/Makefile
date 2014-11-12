CXX =g++
MAKE = make
RM =rm
TIME = /usr/bin/time -f "Elapsed time %E" 2>&1
LIB_OBJECT=libraster.so
LIB_DIR=../lib
TOP_DIR=..
INCLUDE =  -I .  \
		   -I  $(TOP_DIR) \
		   -I /usr/include \
		   -I  $(TOP_DIR)/util \
		   -I  $(TOP_DIR)/raster
OPTFLAGS=-O3 -Wno-deprecated
SHARED= -shared
FPIC= -fPIC -c
OBJECT_TARGETS = colorunit.o  depthunit.o  edgefunc.o  rasterizer.o  statistics.o  textureunit.o  tilerasterizer.o

all : $(OBJECT_TARGETS) $(LIB_OBJECT)

$(OBJECT_TARGETS): %.o: %.cpp 
	$(CXX) $< $(OPTFLAGS) $(INCLUDE) $(FPIC) -o $@

$(LIB_OBJECT) : $(OBJECT_TARGETS)
	$(CXX) $^ $(SHARED) $(OPTFLAGS) -fPIC -o $@
	mv $@ $(LIB_DIR)


clean :
	rm $(OBJECT_TARGETS)
