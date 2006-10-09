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
#include "arc.h"

namespace g2 {

Arc::Arc(double x, double y, double radiusX, double radiusY, 
         double angle_start, double angle_end, bool filled)
    : Shape(), m_point(x,y), m_radii(radiusX,radiusY),
      m_angle_start(angle_start), m_angle_end(angle_end), m_filled(filled)
{
}


Arc::~Arc()
{
}


void Arc::DrawToDevice(int dev) const
{
    if(m_filled)
        g2_filled_arc(dev, m_point.x, m_point.y, m_radii.x, m_radii.y, 
                      m_angle_start, m_angle_end);
    else
        g2_arc(dev, m_point.x, m_point.y, m_radii.x, m_radii.y, 
               m_angle_start, m_angle_end);
}

}


/*!
    \fn g2::Arc::Arc(Point point, double radiusX, double radiusY, double angle_start, double angle_end, bool filled=false)
 */
 g2::Arc::Arc(Point point, double radiusX, double radiusY, double angle_start, 
              double angle_end, bool filled)
    :Shape(), m_point(point), m_radii(radiusX, radiusY), 
     m_angle_start(angle_start), m_angle_end(angle_end), m_filled(filled)
{
}


/*!
    \fn g2::Arc::Arc(Point point, Point radii, double angle_start, double angle_end, bool filled=false)
 */
 g2::Arc::Arc(Point point, Point radii, double angle_start, double angle_end, 
              bool filled)
    :Shape(), m_point(point), m_radii(radii), m_angle_start(angle_start),
     m_angle_end(angle_end), m_filled(filled)
{
}
