# - Try to find ZMQ_PP
# Once done this will define
#
#  ZMQ_PP_FOUND - system has ZMQ_PP
#  ZMQ_PP_INCLUDE_DIRS - the ZMQ_PP include directory
#  ZMQ_PP_LIBRARIES - Link these to use ZMQ_PP
#  ZMQ_PP_DEFINITIONS - Compiler switches required for using ZMQ_PP
#
#  Copyright (c) 2011 Lee Hambley <lee.hambley@gmail.com>
#
#  Redistribution and use is allowed according to the terms of the New
#  BSD license.
#  For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

if (ZMQ_PP_LIBRARIES AND ZMQ_PP_INCLUDE_DIRS)
  # in cache already
  set(ZMQ_PP_FOUND TRUE)
else (ZMQ_PP_LIBRARIES AND ZMQ_PP_INCLUDE_DIRS)

  find_path(ZMQ_PP_INCLUDE_DIR
    NAMES
      zmqpp.hpp
    PATHS
      /usr/include
      /usr/local/include
      /opt/local/include
      thirtparty/zmqpp/src/zmqpp
  )

  find_library(ZMQ_PP_LIBRARY
    NAMES
      zmqpp
    PATHS
      /usr/lib
      /usr/local/lib
      /opt/local/lib
      thirtparty/zmqpp/build/max-g++
  )

  set(ZMQ_PP_INCLUDE_DIRS
    ${ZMQ_PP_INCLUDE_DIR}
  )

  if (ZMQ_PP_LIBRARY)
    set(ZMQ_PP_LIBRARIES
        ${ZMQ_PP_LIBRARIES}
        ${ZMQ_PP_LIBRARY}
    )
  endif (ZMQ_PP_LIBRARY)

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(ZMQ_PP DEFAULT_MSG ZMQ_PP_LIBRARIES ZMQ_PP_INCLUDE_DIRS)

  # show the ZMQ_PP_INCLUDE_DIRS and ZMQ_PP_LIBRARIES variables only in the advanced view
  mark_as_advanced(ZMQ_PP_INCLUDE_DIRS ZMQ_PP_LIBRARIES)

endif (ZMQ_PP_LIBRARIES AND ZMQ_PP_INCLUDE_DIRS)
