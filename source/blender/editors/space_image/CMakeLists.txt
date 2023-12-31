# SPDX-FileCopyrightText: 2023 Blender Authors
#
# SPDX-License-Identifier: GPL-2.0-or-later

set(INC
  ../include
  ../../blenfont
  ../../blenkernel
  ../../blenloader
  ../../blentranslation
  ../../bmesh
  ../../depsgraph
  ../../draw
  ../../gpu
  ../../imbuf
  ../../makesrna
  ../../render
  ../../windowmanager
  ../../../../intern/clog

  # RNA_prototypes.h
  ${CMAKE_BINARY_DIR}/source/blender/makesrna
)

set(INC_SYS
)

set(SRC
  image_buttons.cc
  image_draw.cc
  image_edit.cc
  image_ops.cc
  image_sequence.cc
  image_undo.cc
  space_image.cc

  image_intern.h
)

set(LIB
  bf_blenkernel
  PRIVATE bf::blenlib
  PRIVATE bf::dna
  bf_editor_uvedit
  PRIVATE bf::intern::guardedalloc
)

if(WITH_IMAGE_OPENJPEG)
  add_definitions(-DWITH_OPENJPEG)
endif()

if(WITH_IMAGE_OPENEXR)
  add_definitions(-DWITH_OPENEXR)
endif()

if(WITH_IMAGE_CINEON)
  add_definitions(-DWITH_CINEON)
endif()

if(WITH_IMAGE_WEBP)
  add_definitions(-DWITH_WEBP)
endif()

blender_add_lib(bf_editor_space_image "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")

# RNA_prototypes.h dna_type_offsets.h
add_dependencies(bf_editor_space_image bf_rna)
