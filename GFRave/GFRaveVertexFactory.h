/* Copyright 2008-2010, Technische Universitaet Muenchen,
   Authors: Christian Hoeppner & Sebastian Neubert

   This file is part of GENFIT.

   GENFIT is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   GENFIT is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GENFIT.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 *  @author Johannes Rauch (Technische Universit&auml;t M&uuml;nchen, original author)
 *
 */

/** @addtogroup GFRave
 * @{
 */


#ifndef GFRAVEVERTEXFACTORY_H
#define GFRAVEVERTEXFACTORY_H

#include<vector>

#include "GFRaveMagneticField.h"
#include "GFRavePropagator.h"
#include "GFRaveVertex.h"

#include "rave/Vertex.h"
#include "rave/VertexFactory.h"
#include "rave/Ellipsoid3D.h"

#include "GFTrack.h"



class GFRaveVertexFactory {
 public:
  GFRaveVertexFactory();

  std::vector <  GFRaveVertex* > * create ( const std::vector < GFTrack* > &, bool use_beamspot=false ) const;

  void setBeamspot(const TVector3 & pos, const TMatrixT<double> & cov);
  void setMethod(const std::string & method) {fMethod = method;}

 private:

  // data members
  rave::VertexFactory* fFactory;
  GFRaveMagneticField* fMagneticField;
  GFRavePropagator* fPropagator;

  rave::Ellipsoid3D fBeamspot;
  std::string fMethod;

};

#endif

/** @} */

