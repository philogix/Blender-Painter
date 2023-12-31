/* SPDX-FileCopyrightText: 2012-2022 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup freestyle
 * \brief Class to define the Postscript rendering of a stroke
 */

#include "PSStrokeRenderer.h"
#include "Canvas.h"

namespace Freestyle {

PSStrokeRenderer::PSStrokeRenderer(const char *iFileName)
{
  if (!iFileName) {
    iFileName = "freestyle.ps";
  }
  // open the stream:
  _ofstream.open(iFileName, ios::out);
  if (!_ofstream.is_open()) {
    cerr << "couldn't open the output file " << iFileName << endl;
  }
  _ofstream << "%!PS-Adobe-2.0 EPSF-2.0" << endl;
  _ofstream << "%%Creator: Freestyle (http://artis.imag.fr/Software/Freestyle)" << endl;
  _ofstream << "%%BoundingBox: " << 0 << " " << 0 << " " << Canvas::getInstance()->width() << " "
            << Canvas::getInstance()->height() << endl;
  _ofstream << "%%EndComments" << endl;
}

void PSStrokeRenderer::RenderStrokeRep(StrokeRep *iStrokeRep) const
{
  RenderStrokeRepBasic(iStrokeRep);
}

void PSStrokeRenderer::RenderStrokeRepBasic(StrokeRep *iStrokeRep) const
{
  vector<Strip *> &strips = iStrokeRep->getStrips();
  Strip::vertex_container::iterator v[3];
  StrokeVertexRep *svRep[3];
  Vec3r color[3];
  for (vector<Strip *>::iterator s = strips.begin(), send = strips.end(); s != send; ++s) {
    Strip::vertex_container &vertices = (*s)->vertices();
    v[0] = vertices.begin();
    v[1] = v[0];
    ++(v[1]);
    v[2] = v[1];
    ++(v[2]);

    while (v[2] != vertices.end()) {
      svRep[0] = *(v[0]);
      svRep[1] = *(v[1]);
      svRep[2] = *(v[2]);

      color[0] = svRep[0]->color();
      // color[1] = svRep[1]->color();
      // color[2] = svRep[2]->color();

      _ofstream << "newpath" << endl;
      _ofstream << (color[0])[0] << " " << (color[0])[1] << " " << (color[0])[2] << " setrgbcolor"
                << endl;
      _ofstream << svRep[0]->point2d()[0] << " " << svRep[0]->point2d()[1] << " moveto" << endl;
      _ofstream << svRep[1]->point2d()[0] << " " << svRep[1]->point2d()[1] << " lineto" << endl;
      _ofstream << svRep[2]->point2d()[0] << " " << svRep[2]->point2d()[1] << " lineto" << endl;
      _ofstream << "closepath" << endl;
      _ofstream << "fill" << endl;

      ++v[0];
      ++v[1];
      ++v[2];
    }
  }
}

} /* namespace Freestyle */
