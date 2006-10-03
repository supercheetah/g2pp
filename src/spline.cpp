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
#include "spline.h"

#include <cstdlib>

namespace g2 {

Spline::Spline(int num_points, Point *points, int num_interpolated_points, 
               SplineType spline_type) throw( g2exception )
    : MultiPointShape(num_points, points)
{
    switch(spline_type) {
        case RASPIN:
        case FILLED_RASPIN:
        case PARA_3:
        case FILLED_PARA_3:
        case PARA_5:
        case FILLED_PARA_5:
            throw g2exception("Invalid spline construction.  Cannot use with "
                              "this type.", INVALID_SPLINE);
            break;
        default:
            break;
    }
    
    m_numInterpolatedPoints=num_interpolated_points;
    m_splineType=spline_type;
}


Spline::~Spline()
{
}


void Spline::DrawToDevice(int dev) const
{
    CopyPointsToBuffer();
    
    switch( m_splineType ){
        case NORMAL_SPLINE:
            g2_spline(dev, m_numPoints, m_pointsBuffer, 
                      m_numInterpolatedPoints);
            break;
        case B_SPLINE:
            g2_b_spline(dev, m_numPoints, m_pointsBuffer, 
                        m_numInterpolatedPoints);
            break;
        case FILLED_SPLINE:
            g2_filled_spline(dev, m_numPoints, m_pointsBuffer, 
                             m_numInterpolatedPoints);
            break;
        case FILLED_B_SPLINE:
            g2_filled_b_spline(dev, m_numPoints, m_pointsBuffer, 
                               m_numInterpolatedPoints);
            break;
        case RASPIN:
            g2_raspln(dev, m_numPoints, m_pointsBuffer, m_tension);
            break;
        case FILLED_RASPIN:
            g2_filled_raspln(dev, m_numPoints, m_pointsBuffer, m_tension);
            break;
        case PARA_3:
            g2_para_3(dev, m_numPoints, m_pointsBuffer);
            break;
        case PARA_5:
            g2_para_5(dev, m_numPoints, m_pointsBuffer);
            break;
        case FILLED_PARA_3:
            g2_filled_para_3(dev, m_numPoints, m_pointsBuffer);
            break;
        case FILLED_PARA_5:
            g2_filled_para_5(dev, m_numPoints, m_pointsBuffer);
            break;
    }
}

} //namespace g2


/*!
    \fn g2::Spline::Spline(int num_points, Point *points, SplineType spline_type)
 */
 g2::Spline::Spline(int num_points, Point *points, SplineType spline_type) 
         throw( g2exception )
    :MultiPointShape(num_points, points) 
{
    switch( spline_type ) {
        case PARA_3:
        case PARA_5:
        case FILLED_PARA_3:
        case FILLED_PARA_5:
            break;
        default:
            throw g2exception("Invalid spline construction.  Cannot use with "
                              "this type.", INVALID_SPLINE);
            break;
    }
    
    m_splineType=spline_type;
}


/*!
    \fn g2::Spline::Spline(int num_points, Point *points, double tension, SplineType spline_type)
 */
 g2::Spline::Spline(int num_points, Point *points, double tension, 
                    SplineType spline_type) throw( g2exception )
    :MultiPointShape(num_points, points)
{
    switch( spline_type ){
        case RASPIN:
        case FILLED_RASPIN:
            break;
        default:
            throw g2exception("Invalid spline construction.  Cannot use with "
                              "this type.", INVALID_SPLINE);
            break;
    }
    m_tension=tension;
}
