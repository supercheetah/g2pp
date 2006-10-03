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
#ifndef G2SPLINE_H
#define G2SPLINE_H

#include <shape.h>
#include <g2exception.h>
#include <multipointshape.h>

namespace g2 {

typedef enum {
    NORMAL_SPLINE,
    B_SPLINE,
    FILLED_SPLINE,
    FILLED_B_SPLINE,
    RASPIN,
    FILLED_RASPIN,
    PARA_3,
    FILLED_PARA_3,
    PARA_5,
    FILLED_PARA_5
} SplineType;

/**
    @author Rene Horn <the.rhorn@gmail.com>
*/
class Spline : public MultiPointShape
{
public:
    Spline(int num_points, Point *points, int num_interpolated_points, 
           SplineType spline_type=NORMAL_SPLINE) throw( g2exception );

    virtual ~Spline();
    Spline(int num_points, Point *points, SplineType spline_type=PARA_3) 
            throw( g2exception );
    Spline(int num_points, Point *points, double tension, 
           SplineType spline_type=RASPIN) throw( g2exception );
protected:
    virtual void DrawToDevice(int dev) const;
    int m_numInterpolatedPoints;
    double m_tension;
    SplineType m_splineType;
};

} //namespace g2

#endif
