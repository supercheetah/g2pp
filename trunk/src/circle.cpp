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
#include "circle.h"
#include <cmath>

namespace g2 {

Circle::Circle(double x, double y, double radius, bool filled)
 : Shape()
{
    m_point.x=x;
    m_point.y=y;
    m_radius=radius;
    m_filled=filled;
}


Circle::~Circle()
{
}


void Circle::DrawToDevice(int dev) const
{
    if(m_filled)
        g2_filled_circle(dev, m_point.x, m_point.y, m_radius);
    else
        g2_circle(dev, m_point.x, m_point.y, m_radius);
}

}


/*!
    \fn g2::Circle::Circle(Point point, double radius, bool filled=false)
 */
 g2::Circle::Circle(Point point, double radius, bool filled)
{
    m_point.x=point.x;
    m_point.y=point.y;
    m_radius=radius;
    m_filled=filled;
}


/*!
    \fn g2::Circle::Circle(Point point, Point radial_point, bool filled=false)
 */
 g2::Circle::Circle(Point point, Point radial_point, bool filled)
{
    m_point.x=point.x;
    m_point.y=point.y;
    m_radius=sqrt(  pow(fabs(m_point.x - radial_point.x),2.0)
                  + pow(fabs(m_point.y - radial_point.y),2.0));
    m_filled=filled;
}
