# SPDX-FileCopyrightText: 2023 Blender Authors
#
# SPDX-License-Identifier: GPL-2.0-or-later

set(INC
  ../include
  ../../blenkernel
  ../../depsgraph
  ../../gpu
  ../../makesrna
  ../../render
  ../../windowmanager
  ../../../../intern/clog
)

set(INC_SYS

)

set(SRC
  editmball_undo.cc
  mball_edit.cc
  mball_ops.cc

  mball_intern.h
)

set(LIB
  PRIVATE bf::blenlib
  PRIVATE bf::dna
  PRIVATE bf::intern::guardedalloc
)

blender_add_lib(bf_editor_metaball "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
