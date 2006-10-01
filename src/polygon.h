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
#ifndef G2POLYGON_H
#define G2POLYGON_H

#include <shape.h>

namespace g2 {

typedef enum {
    NormalPoly,
    PolyLine,
    FilledPoly
} PolygonType;

/**
	@author Rene Horn <the.rhorn@gmail.com>
*/
class Polygon : public Shape
{
public:
    Polygon(Point *pt_list, size_t num_points, PolygonType poly_type,
            bool deletePoints=false);

    virtual ~Polygon();

protected:
    virtual void DrawToDevice(int dev) const;
    bool m_deletePoints;
    static double *m_pointsBuffer;
    static size_t m_refCount;
    PolygonType m_polyType;
    Point *m_points;
    size_t m_pointCount;
};

}

#endif
