/***************************************************************************
 *   Copyright (C) 2006 by Rene Horn                                       *
 *   the.rhorn@gmail.com                                                   *
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
#include "ellipse.h"

namespace g2 {

Ellipse::Ellipse(double x, double y, double radiusX, double radiusY,
                 bool filled)
    : Shape(), m_point(x,y), m_radii(radiusX,radiusY), m_filled(filled)
{
}


Ellipse::~Ellipse()
{
}


void Ellipse::DrawToDevice(int dev) const
{
    if(m_filled)
        g2_filled_ellipse(dev, m_point.x, m_point.y, m_radii.x, m_radii.y);
    else
        g2_ellipse(dev, m_point.x, m_point.y, m_radii.x, m_radii.y);
}

}


/*!
    \fn g2::Ellipse::Ellipse(Point point, double radiusX, double radiusY, bool filled=false)
 */
 g2::Ellipse::Ellipse(Point point, double radiusX, double radiusY, bool filled)
    :Shape(), m_point(point), m_radii(radiusX,radiusY), m_filled(filled)
{
}


/*!
    \fn g2::Ellipse::Ellipse(Point point, Point radii, bool filled=false)
 */
 g2::Ellipse::Ellipse(Point point, Point radii, bool filled)
    :Shape(), m_point(point), m_radii(radii), m_filled(filled)
{
}
