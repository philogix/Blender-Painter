# SPDX-FileCopyrightText: 2014-2023 Blender Authors
#
# SPDX-License-Identifier: GPL-2.0-or-later

"""
This module contains core classes of the Freestyle Python API,
including data types of view map components (0D and 1D elements), base
classes for user-defined line stylization rules (predicates,
functions, chaining iterators, and stroke shaders), and operators.

Class hierarchy:

- :class:`BBox`
- :class:`BinaryPredicate0D`
- :class:`BinaryPredicate1D`
- :class:`Id`
- :class:`Interface0D`

  - :class:`CurvePoint`

    - :class:`StrokeVertex`

  - :class:`SVertex`
  - :class:`ViewVertex`

    - :class:`NonTVertex`
    - :class:`TVertex`

- :class:`Interface1D`

  - :class:`Curve`

    - :class:`Chain`

  - :class:`FEdge`

    - :class:`FEdgeSharp`
    - :class:`FEdgeSmooth`

  - :class:`Stroke`
  - :class:`ViewEdge`

- :class:`Iterator`

  - :class:`AdjacencyIterator`
  - :class:`CurvePointIterator`
  - :class:`Interface0DIterator`
  - :class:`SVertexIterator`
  - :class:`StrokeVertexIterator`
  - :class:`ViewEdgeIterator`

    - :class:`ChainingIterator`

  - :class:`orientedViewEdgeIterator`

- :class:`Material`
- :class:`Noise`
- :class:`Operators`
- :class:`SShape`
- :class:`StrokeAttribute`
- :class:`StrokeShader`
- :class:`UnaryFunction0D`

  - :class:`UnaryFunction0DDouble`
  - :class:`UnaryFunction0DEdgeNature`
  - :class:`UnaryFunction0DFloat`
  - :class:`UnaryFunction0DId`
  - :class:`UnaryFunction0DMaterial`
  - :class:`UnaryFunction0DUnsigned`
  - :class:`UnaryFunction0DVec2f`
  - :class:`UnaryFunction0DVec3f`
  - :class:`UnaryFunction0DVectorViewShape`
  - :class:`UnaryFunction0DViewShape`

- :class:`UnaryFunction1D`

  - :class:`UnaryFunction1DDouble`
  - :class:`UnaryFunction1DEdgeNature`
  - :class:`UnaryFunction1DFloat`
  - :class:`UnaryFunction1DUnsigned`
  - :class:`UnaryFunction1DVec2f`
  - :class:`UnaryFunction1DVec3f`
  - :class:`UnaryFunction1DVectorViewShape`
  - :class:`UnaryFunction1DVoid`

- :class:`UnaryPredicate0D`
- :class:`UnaryPredicate1D`
- :class:`ViewMap`
- :class:`ViewShape`
- :class:`IntegrationType`
- :class:`MediumType`
- :class:`Nature`
"""


# module members
from _freestyle import (
    AdjacencyIterator,
    BBox,
    BinaryPredicate0D,
    BinaryPredicate1D,
    Chain,
    ChainingIterator,
    Curve,
    CurvePoint,
    CurvePointIterator,
    FEdge,
    FEdgeSharp,
    FEdgeSmooth,
    Id,
    IntegrationType,
    Interface0D,
    Interface0DIterator,
    Interface1D,
    Iterator,
    Material,
    MediumType,
    Nature,
    Noise,
    NonTVertex,
    Operators,
    SShape,
    SVertex,
    SVertexIterator,
    Stroke,
    StrokeAttribute,
    StrokeShader,
    StrokeVertex,
    StrokeVertexIterator,
    TVertex,
    UnaryFunction0D,
    UnaryFunction0DDouble,
    UnaryFunction0DEdgeNature,
    UnaryFunction0DFloat,
    UnaryFunction0DId,
    UnaryFunction0DMaterial,
    UnaryFunction0DUnsigned,
    UnaryFunction0DVec2f,
    UnaryFunction0DVec3f,
    UnaryFunction0DVectorViewShape,
    UnaryFunction0DViewShape,
    UnaryFunction1D,
    UnaryFunction1DDouble,
    UnaryFunction1DEdgeNature,
    UnaryFunction1DFloat,
    UnaryFunction1DUnsigned,
    UnaryFunction1DVec2f,
    UnaryFunction1DVec3f,
    UnaryFunction1DVectorViewShape,
    UnaryFunction1DVoid,
    UnaryPredicate0D,
    UnaryPredicate1D,
    ViewEdge,
    ViewEdgeIterator,
    ViewMap,
    ViewShape,
    ViewVertex,
    orientedViewEdgeIterator,
)
