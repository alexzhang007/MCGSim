# Mobile Computer Graphics Simulator (MCGSim)

URL Source : http://cs.lth.se/eda075 
Purpose    : compile the Microsoft Visual Solution version into Linux version
Modifier   : Alex Zhang (cgzhangwei@gmail.com)
Date       : 11-11-2014

# Compile under Codeblocks

1. C++ exception compile error using g++ compiler
   solution : declare and definition function to be void* operator new (size_t ) throw (std::bad_alloc); 
   void* operator new (size_t ) throw (std::bad_alloc) { ... }
2. ILvoid uncompatible issue
   remove the function parameter ILvoid.
3. how to tell codeblocks the path of dynamic link file (.dll)
   Project-> Build Option -> Linker settings :
   change the Link libraries : to the *.lib files. cpp files still cannot find the correct link functions

# Reorganized Hierarchy

+---util     : original cpp and h under main
+---scenes   : all scene
+---textures : picture
+---GL       : opengl glut.h
+---IL       : download from sourceforge to compile the library file and copy it here. 
+---raster   : graphics rasterize pipeline
+---mmgr     : memory management statistics

# Compiler under Linux

1. Generate the libmmgr.so and mv it to LIBRARY_DIR
2. make under the sub-directory under scenes to change it to depend the standard GL library
3. libglut.so is copied from the freeglut-2.8.1
4. libIL.so and libILU.so is from the DevIL-1.6.6.tar.gz.
   #ifdef WIN32
     _vsnprintf(buff, 1024, fmt, ap);
   #else 
	  vsnprintf(buff, 1024, fmt, ap);
   #endif
5. modify the (ILvoid) to ()
6. add the LIDBRARY_DIR into LD_LIBRARY_PATH

# How to run

1. make ;
2. ./gpu_sw 
