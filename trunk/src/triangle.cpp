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
#include "triangle.h"

namespace g2 {

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, 
                   double y3, bool filled)
 : Shape()
{
    m_filled=filled;
    m_p1.x=x1;
    m_p2.x=x2;
    m_p3.x=x3;
    m_p1.y=y1;
    m_p2.y=y2;
    m_p3.y=y3;
}


Triangle::~Triangle()
{
}


void Triangle::DrawToDevice(int dev) const
{
    if(m_filled)
        g2_filled_triangle(dev, m_p1.x, m_p1.y, m_p2.x, m_p2.y, m_p3.x, 
                           m_p3.y);
    else
        g2_triangle(dev, m_p1.x, m_p1.y, m_p2.x, m_p2.y, m_p3.x, 
                    m_p3.y);
}

}


/*!
    \fn g2::Triangle::Triangle(Point p1, Point p2, Point p3, bool filled=false)
 */
 g2::Triangle::Triangle(Point p1, Point p2, Point p3, bool filled)
{
    m_filled=filled;
    m_p1=p1;
    m_p2=p2;
    m_p3=p3;
}
