###### CONFIGURATION START ############

# Silo (www.hdfgroup.org/HDF5) and HDF5 (www.hdfgroup.org/HDF5) library
# locations.  These macros can be left undefined if visualization is not required.

#SILO_LOC = /usr/local/tools/silo-4.8
SILO_LOC = 

# HDF5 library location (www.hdfgroup.org/HDF5).  This macro can
# be undefined if visualization is not required.
#HDF5_LOC = /usr/local/tools/hdf5-intel-serial-1.8.8
HDF5_LOC = 

# BLAS and LAPACK library locations.  It may not be necessary
# to specify these depending upon the linker defaults
LAPACK_LOC =
BLAS_LOC =

FLANN_LOC =
#FLANN_LOC = ../flann/flann/src/cpp

CXX = g++
CXXFLAGS = -std=c++0x -O3

###### CONFIGURATION END ############

CM_LIB = ../CM/lib/libcm.a

INCLUDE_DIRS = -I../CM/include

ifneq ($(strip $(FLANN_LOC)),)
INCLUDE_DIRS +=  -I$(FLANN_LOC) -I$(FLANN_LOC)/flann
CXXFLAGS += -DFLANN
endif

SILO_LIB =
ifneq ($(strip $(SILO_LOC)),)
INCLUDE_DIRS += -I$(SILO_LOC)/include/
SILO_LIB += -Wl,-rpath,$(realpath $(SILO_LOC))/lib -L $(SILO_LOC)/lib -lsiloh5
CXXFLAGS += -DSILO 
endif

HDF5_LIB =
ifneq ($(strip $(HDF5_LOC)),)
HDF5_LIB += -Wl,-rpath,$(HDF5_LOC)/lib -L $(HDF5_LOC)/lib -lhdf5
endif

LAPACK =
ifneq ($(strip $(LAPACK_LOC)),)
LAPACK += -L$(LAPACK_LOC)
endif
LAPACK += -llapack

ifneq ($(strip $(BLAS_LOC)),)
LAPACK += -L$(BLAS_LOC)
endif
LAPACK += -lblas

CXXFLAGS += $(INCLUDE_DIRS)

all: lulesh

dummy: ;

.cxxflags: dummy
	@[ -f $@ ] || touch $@
	@echo "CXXFLAGS=$(CXXFLAGS)" | cmp -s $@ - || echo "CXXFLAGS=$(CXXFLAGS)" > $@

MAKEDEPEND = gcc -MM -MT $*.o $(CXXFLAGS) -o $*.d.tmp $<
%.o: %.cc .cxxflags
	@$(MAKEDEPEND)
	cp $*.d.tmp $*.d
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' < $*.d.tmp >> $*.d
	rm -f $*.d.tmp
	$(CXX) -c $(CXXFLAGS) -c -o $@ $< 

LULESH_SRC=$(shell ls *.cc)
LULESH_OBJS=$(LULESH_SRC:.cc=.o)
LULESH_DEPS=$(LULESH_SRC:.cc=.d)

-include $(LULESH_DEPS)

lulesh: $(LULESH_OBJS) $(CM_LIB)
	$(CXX) -o $@ ${LULESH_OBJS} $(CM_LIB) $(SILO_LIB) $(HDF5_LIB) $(LAPACK) -lm

clean:
	rm -f *~ lulesh $(LULESH_OBJS) $(LULESH_DEPS)
