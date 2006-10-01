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
#include "line.h"

#ifdef DEBUG
#  include <cassert>
#  include <iostream>
using std::cerr;
using std::endl;
#endif

namespace g2 {

Line::Line(double x1, double y1, double x2, double y2)
 : Shape()
{
    m_p1.x=x1;
    m_p1.y=y1;
    m_p2.x=x2;
    m_p2.y=y2;
    m_linetype=NORMAL_LINE;
}


Line::~Line()
{
}


void Line::DrawToDevice(int dev) const
{
    switch( m_linetype )
    {
        case NORMAL_LINE:
            g2_line(dev, m_p1.x, m_p1.y, m_p2.x, m_p2.y);
            break;
        case FROM_GRAPHICCURSOR:
            g2_line_r(dev, m_p1.x, m_p1.y);
            break;
        case TO_GRAPHICCURSOR:
            g2_line_to(dev, m_p1.x, m_p1.y);
            break;
    }
}

}


/*!
    \fn g2::Line::Line(Point p1, Point p2)
 */
 g2::Line::Line(Point p1, Point p2)
{
    m_p1=p1;
    m_p2=p2;
    m_linetype=NORMAL_LINE;
}


/*!
    \fn g2::Line::Line(double x, double y, LineType linetype=FROM_GRAPHICCURSOR)
 */
 g2::Line::Line(double x, double y, LineType linetype)
{
    m_linetype=linetype;
    m_p1.x=x;
    m_p2.y=y;
}


/*!
    \fn g2::Line::Line(Point point, LineType linetype=FROM_GRAPHICCURSOR)
 */
 g2::Line::Line(Point point, LineType linetype)
{
    m_linetype=linetype;
    m_p1=point;
}
