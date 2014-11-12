CXX =g++
MAKE = make
RM =rm
TIME = /usr/bin/time -f "Elapsed time %E" 2>&1
LIB_OBJECT=libscenes.so
LIB_DIR=../lib
OPTFLAGS=-O3 -Wno-deprecated
SHARED= -shared
SUBDIR_TARGETS = IsectTrisScene  ProjectScene  TextureScene  TexturedQuadScene  UmbrellaScene
CLEAN_DIRS     = $(SUBDIR_TARGETS)
OBJECT_TARGETS = IsectTrisScene/IsectTrisScene.o  \
				 ProjectScene/ProjectScene.o \
				 TextureScene/TextureScene.o \
				 TexturedQuadScene/TexturedQuadScene.o  \
				 UmbrellaScene/UmbrellaScene.o

all :  
	@for d in $(SUBDIR_TARGETS) ; do ($(MAKE) -C $$d all); done
	$(CXX) $(OBJECT_TARGETS) $(SHARED) $(OPTFLAGS) -fPIC -o $(LIB_OBJECT)
	mv $(LIB_OBJECT) $(LIB_DIR)

clean : 
	@for d in $(CLEAN_DIRS); do ($(MAKE) -C $$d clean); done
	rm $(LIB_DIR)/$(LIB_OBJECT) ;

