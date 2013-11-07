#/usr/common/usg/cmake/2.8.8/bin/cmake
##
## build_visit generated host.cmake
## created: Mon Nov 15 17:10:11 PST 2010
## system: Linux hopper02 2.6.27.48-0.12-default #1 SMP 2010-09-20 11:03:26 -0400 x86_64 x86_64 x86_64 GNU/Linux
## updated: Tue Jul 16 04:35:19 PDT 2013
## system: Linux hopper05 2.6.32.36-0.5-default #1 SMP 2011-04-14 10:12:31 +0200 x86_64 x86_64 x86_64 GNU/Linux
## by: ghweber

##
## Set the VISITHOME and VISITARCH variables.
##
SET(VISITHOME /usr/common/graphics/installs/visit_3rdparty)
SET(VISITARCH linux-x86_64_gcc-4.7)
#SET(VISIT_VERBOSE_MAKEFILE TRUE)
VISIT_OPTION_DEFAULT(VISIT_INSTALL_PROFILES_TO_HOSTS "nersc" TYPE STRING)
VISIT_OPTION_DEFAULT(CMAKE_INSTALL_PREFIX /usr/common/graphics/visit)
VISIT_OPTION_DEFAULT(VISIT_INSTALL_THIRD_PARTY ON)
VISIT_OPTION_DEFAULT(CMAKE_BUILD_TYPE Release)

##
## Do not build Tuvok
##
VISIT_OPTION_DEFAULT(VISIT_TUVOK OFF)

##
## Compiler flags.
##
VISIT_OPTION_DEFAULT(VISIT_C_COMPILER gcc TYPE FILEPATH)
VISIT_OPTION_DEFAULT(VISIT_CXX_COMPILER g++ TYPE FILEPATH)
VISIT_OPTION_DEFAULT(VISIT_C_FLAGS "-m64 -fvisibility=hidden -DVIZSCHEMA_DECOMPOSE_DOMAINS" TYPE STRING)
VISIT_OPTION_DEFAULT(VISIT_MPI_C_FLAGS "-I/opt/cray/mpt/default/gni/mpich2-gnu/47/include" TYPE STRING)
VISIT_OPTION_DEFAULT(VISIT_CXX_FLAGS "-m64 -fvisibility=hidden -DVIZSCHEMA_DECOMPOSE_DOMAINS")
#SET(VISIT_EXE_LINKER_FLAGS "-Wl,--rpath,/opt/gcc/4.3.3/snos/lib64")
# Get these via CC -v
VISIT_OPTION_DEFAULT(VISIT_MPI_CXX_FLAGS "-I/opt/cray/mpt/default/gni/mpich2-gnu/47/include" TYPE STRING)
VISIT_OPTION_DEFAULT(VISIT_MPI_LD_FLAGS "-L/opt/cray/mpt/default/gni/mpich2-gnu/47/lib -L/opt/cray/pmi/default/lib64 -L/opt/cray/xe-sysroot/default/usr/lib/alps" TYPE STRING)
VISIT_OPTION_DEFAULT(VISIT_PARALLEL_RPATH "/opt/cray/mpt/default/gni/mpich2-gnu/47/lib;/opt/cray/pmi/default/lib64;/opt/cray/xe-sysroot/default/usr/lib/alps" TYPE STRING)
VISIT_OPTION_DEFAULT(VISIT_MPI_LIBS mpich pmi alpslli alpsutil pthread rt)
VISIT_OPTION_DEFAULT(VISIT_PARALLEL ON)
VISIT_OPTION_DEFAULT(VISIT_CREATE_SOCKET_RELAY_EXECUTABLE ON)

##
## VisIt Thread Option
##
VISIT_OPTION_DEFAULT(VISIT_THREAD OFF TYPE BOOL)

##############################################################
##
## Database reader plugin support libraries
##
## The HDF4, HDF5 and NetCDF libraries must be first so that
## their libdeps are defined for any plugins that need them.
##
## For libraries with LIBDEP settings, order matters.
## Libraries with LIBDEP settings that depend on other
## Library's LIBDEP settings must come after them.
##############################################################
##

##
## Mesa
##
VISIT_OPTION_DEFAULT(VISIT_MESA_DIR ${VISITHOME}/mesa/7.10.2/${VISITARCH})

##
## Python
##
VISIT_OPTION_DEFAULT(VISIT_PYTHON_DIR ${VISITHOME}/python/2.7.3/${VISITARCH})

##
## Qt
##
VISIT_OPTION_DEFAULT(VISIT_QT_BIN ${VISITHOME}/qt/4.8.3/${VISITARCH}/bin)

##
## R
##
VISIT_OPTION_DEFAULT(VISIT_R_DIR ${VISITHOME}/R/2.13.2/${VISITARCH}/lib/R)

##
## VTK
##
VISIT_OPTION_DEFAULT(VISIT_VTK_DIR ${VISITHOME}/vtk-r/6.0.0/${VISITARCH})
##

##
## AdvIO
##
VISIT_OPTION_DEFAULT(VISIT_ADVIO_DIR ${VISITHOME}/AdvIO/1.2/${VISITARCH})

##
## Boxlib
##
VISIT_OPTION_DEFAULT(VISIT_BOXLIB_DIR ${VISITHOME}/boxlib/1.0.7/${VISITARCH})

##
## CCMIO
##
VISIT_OPTION_DEFAULT(VISIT_CCMIO_DIR ${VISITHOME}/ccmio/2.6.1/${VISITARCH})

##
## CFITSIO
##
VISIT_OPTION_DEFAULT(VISIT_CFITSIO_DIR ${VISITHOME}/cfitsio/3006/${VISITARCH})

##
## SZIP
##
VISIT_OPTION_DEFAULT(VISIT_SZIP_DIR ${VISITHOME}/szip/2.1/${VISITARCH})

##
## ZLIB
##
VISIT_OPTION_DEFAULT(VISIT_ZLIB_DIR ${VISITHOME}/zlib/1.2.7/${VISITARCH})

##
## HDF4
##
#VISIT_OPTION_DEFAULT(VISIT_HDF4_DIR ${VISITHOME}/hdf4/4.2.9/${VISITARCH})
#VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz /usr/lib64 jpeg TYPE STRING)
#VISIT_OPTION_DEFAULT(VISIT_HDF4_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz ${VISITHOME}/vtk-r/6.0.0/${VISITARCH}/lib vtkjpeg-6.0 TYPE STRING)

##
## HDF5
##
VISIT_OPTION_DEFAULT(VISIT_HDF5_DIR ${VISITHOME}/hdf5/1.8.7/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_HDF5_LIBDEP ${VISITHOME}/szip/2.1/${VISITARCH}/lib sz ${VISITHOME}/zlib/1.2.7/${VISITARCH}/lib z TYPE STRING)

##
## CGNS
##
VISIT_OPTION_DEFAULT(VISIT_CGNS_DIR ${VISITHOME}/cgns/3.0.8/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_CGNS_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## FastBit
##
VISIT_OPTION_DEFAULT(VISIT_FASTBIT_DIR ${VISITHOME}/fastbit/1.2.0/${VISITARCH})

##
## GDAL
##
VISIT_OPTION_DEFAULT(VISIT_GDAL_DIR ${VISITHOME}/gdal/1.7.1/${VISITARCH})

##
## H5Part
##
VISIT_OPTION_DEFAULT(VISIT_H5PART_DIR ${VISITHOME}/h5part/1.6.6/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_H5PART_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Ice-T
##
VISIT_OPTION_DEFAULT(VISIT_ICET_DIR ${VISITHOME}/icet/1.0.0/${VISITARCH})

##
## ITAPS
##
## MOAB implementation
#ITAPS_INCLUDE_DIRECTORIES(MOAB ${VISITHOME}/itaps/1.2/MOAB/4.0.1RC2/${VISITARCH}/include)
#ITAPS_FILE_PATTERNS(MOAB *.cub)
#ITAPS_LINK_LIBRARIES(MOAB iMesh MOAB hdf5_hl hdf5 sz z netcdf_c++ netcdf vtkGraphics)
#ITAPS_LINK_DIRECTORIES(MOAB  ${VISITHOME}/itaps/1.2/MOAB/4.0.1RC2/${VISITARCH}/lib  ${VISITHOME}/hdf5/1.8.7/${VISITARCH}/lib  ${VISITHOME}/szip/2.1/${VISITARCH}/lib  ${VISITHOME}/netcdf/4.1.1/${VISITARCH}/lib)
## FMDB implementation
#ITAPS_INCLUDE_DIRECTORIES(FMDB ${VISITHOME}/itaps/1.2/FMDB/1.2/${VISITARCH}/include)
#ITAPS_FILE_PATTERNS(FMDB *.sms)
#ITAPS_LINK_LIBRARIES(FMDB FMDB SCORECModel SCORECUtil vtkGraphics)
#ITAPS_LINK_DIRECTORIES(FMDB ${VISITHOME}/itaps/1.2/FMDB/1.2/${VISITARCH}/lib)
## GRUMMP implementation
#ITAPS_INCLUDE_DIRECTORIES(GRUMMP ${VISITHOME}/itaps/1.2/GRUMMP/0.6.3/${VISITARCH}/include)
#ITAPS_FILE_PATTERNS(GRUMMP *.bdry *.smesh *.vmesh)
#ITAPS_LINK_LIBRARIES(GRUMMP iMesh_GRUMMP GR_3D GR_surf GR_2D GR_geom GR_base SUMAAlog_lite OptMS vtkGraphics cgm dl)
#ITAPS_LINK_DIRECTORIES(GRUMMP ${VISITHOME}/itaps/1.2/GRUMMP/0.6.3/${VISITARCH}/lib)

##
## NetCDF
##
VISIT_OPTION_DEFAULT(VISIT_NETCDF_DIR ${VISITHOME}/netcdf/4.1.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_NETCDF_LIBDEP HDF5_LIBRARY_DIR hdf5_hl HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## PySide
##
VISIT_OPTION_DEFAULT(VISIT_PYSIDE_DIR ${VISITHOME}/pyside/1.1.1/${VISITARCH})

##
## Silo
##
VISIT_OPTION_DEFAULT(VISIT_SILO_DIR ${VISITHOME}/silo/4.9.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_SILO_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} TYPE STRING)

##
## Xdmf
##
VISIT_OPTION_DEFAULT(VISIT_XDMF_DIR ${VISITHOME}/Xdmf/2.1.1/${VISITARCH})
VISIT_OPTION_DEFAULT(VISIT_XDMF_LIBDEP HDF5_LIBRARY_DIR hdf5 ${VISIT_HDF5_LIBDEP} VTK_LIBRARY_DIRS vtklibxml2-6.0 TYPE STRING)
