# SPDX-FileCopyrightText: 2023 Blender Foundation
#
# SPDX-License-Identifier: GPL-2.0-or-later

if(CMAKE_COMPILER_IS_GNUCC)
  # NOTE: Resolved up-stream, quiet noisy compiler warnings for now.
  add_cxx_flag("-Wno-uninitialized")
  # Needed as build-type options may be added after the CXX flag added above.
  remove_cxx_flag("-Wuninitialized")
endif()

set(INC
  include
)

set(INC_SYS
)

set(SRC
  include/fmt/core.h
  include/fmt/format-inl.h
  include/fmt/format.h
  src/format.cc
)

set(LIB
)

blender_add_lib(extern_fmtlib "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
