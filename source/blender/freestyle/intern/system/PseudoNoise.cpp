/* SPDX-FileCopyrightText: 2008-2022 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup freestyle
 * \brief Class to define a pseudo Perlin noise
 */

#include "BLI_math_base.h"
#include "BLI_utildefines.h"

#include "PseudoNoise.h"
#include "RandGen.h"

static int modf_to_index(Freestyle::real x, uint range)
{
  if (isfinite(x)) {
    Freestyle::real tmp;
    int i = abs(int(modf(x, &tmp) * range));
    BLI_assert(i >= 0 && i < range);
    return i;
  }

  return 0;
}

namespace Freestyle {

real PseudoNoise::_values[];

void PseudoNoise::init(long seed)
{
  RandGen::srand48(seed);
  for (uint i = 0; i < NB_VALUE_NOISE; i++) {
    _values[i] = -1.0 + 2.0 * RandGen::drand48();
  }
}

real PseudoNoise::linearNoise(real x)
{
  real tmp;
  int i = modf_to_index(x, NB_VALUE_NOISE);
  real x1 = _values[i], x2 = _values[(i + 1) % NB_VALUE_NOISE];
  real t = modf(x * NB_VALUE_NOISE, &tmp);
  return x1 * (1 - t) + x2 * t;
}

static real LanczosWindowed(real t)
{
  if (fabs(t) > 2) {
    return 0;
  }
  if (fabs(t) < M_EPSILON) {
    return 1.0;
  }
  return sin(M_PI * t) / (M_PI * t) * sin(M_PI * t / 2.0) / (M_PI * t / 2.0);
}

real PseudoNoise::smoothNoise(real x)
{
  real tmp;
  int i = modf_to_index(x, NB_VALUE_NOISE);
  int h = i - 1;
  if (UNLIKELY(h < 0)) {
    h = NB_VALUE_NOISE + h;
  }

  real x1 = _values[i], x2 = _values[(i + 1) % NB_VALUE_NOISE];
  real x0 = _values[h], x3 = _values[(i + 2) % NB_VALUE_NOISE];

  real t = modf(x * NB_VALUE_NOISE, &tmp);
  real y0 = LanczosWindowed(-1 - t);
  real y1 = LanczosWindowed(-t);
  real y2 = LanczosWindowed(1 - t);
  real y3 = LanczosWindowed(2 - t);
#if 0
  cerr << "x0=" << x0 << "  x1=" << x1 << "  x2=" << x2 << "  x3=" << x3 << endl;
  cerr << "y0=" << y0 << "  y1=" << y1 << "  y2=" << y2 << "  y3=" << y3 << "  :" << endl;
#endif
  return (x0 * y0 + x1 * y1 + x2 * y2 + x3 * y3) / (y0 + y1 + y2 + y3);
}

real PseudoNoise::turbulenceSmooth(real x, uint nbOctave)
{
  real y = 0;
  real k = 1.0;
  for (uint i = 0; i < nbOctave; i++) {
    y = y + k * smoothNoise(x * k);
    k = k / 2.0;
  }
  return y;
}

real PseudoNoise::turbulenceLinear(real x, uint nbOctave)
{
  real y = 0;
  real k = 1.0;
  for (uint i = 0; i < nbOctave; i++) {
    y = y + k * linearNoise(x * k);
    k = k / 2.0;
  }
  return y;
}

} /* namespace Freestyle */
