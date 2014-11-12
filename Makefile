CXX =g++
MAKE = make
RM =rm
TIME = /usr/bin/time -f "Elapsed time %E" 2>&1
EXE = gpu_sw
SUBDIR_TARGETS=mmgr raster scenes util
FPIC= -fPIC -c
OPTFLAGS=-O3 -Wno-deprecated
SHARED= -shared 
TOPDIR = .
INCLUDE = -I $(TOPDIR) \
		  -I /usr/include \
		  -I $(TOPDIR)/raster \
		  -I $(TOPDIR)/util
 
all : gpu_sw 

#LUR.o : LUR.cpp
#	$(CXX) $(OPTFLAGS) $(INCLUDE) $^ -o $@

gpu_sw : LUR.cpp
	@for d in $(SUBDIR_TARGETS) ; do ($(MAKE) -C $$d all); done
	$(CXX) $(OPTFLAGS) $(INCLUDE) -o $@ $^ -L $(TOPDIR)/lib -lmmgr -lraster -lscenes -lutil -lglut -lIL -lILU -L/usr/lib64 -lGL -lGLU

clean : 
	@for d in $(SUBDIR_TARGETS) ; do ($(MAKE) -C $$d clean); done
	rm gpu_sw 
	
