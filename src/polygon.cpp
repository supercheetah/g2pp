/***************************************************************************
 *   Copyright (C) 2006 by Rene Horn   *
 *   the.rhorn@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "polygon.h"

#include <cstdlib>

namespace g2 {
    
Polygon::Polygon(Point *points, size_t num_points, PolygonType poly_type)
    : MultiPointShape(num_points, points), m_polyType(poly_type)
{
}


Polygon::~Polygon()
{
}


void Polygon::DrawToDevice(int dev) const
{

    CopyPointsToBuffer();
    switch(m_polyType) {
        case NORMAL_POLY:
            g2_polygon(dev, m_numPoints, m_pointsBuffer);
            break;
        case POLY_LINE:
            g2_poly_line(dev, m_numPoints, m_pointsBuffer);
            break;
        case FILLED_POLY:
            g2_poly_line(dev, m_numPoints, m_pointsBuffer);
            break;
    }
}

} //namespace g2
