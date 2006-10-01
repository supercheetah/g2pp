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
#ifndef G2ELLIPSE_H
#define G2ELLIPSE_H

#include <shape.h>

namespace g2 {

/**
	@author Rene Horn <the.rhorn@gmail.com>
*/
class Ellipse : public Shape
{
public:
    Ellipse(double x, double y, double radiusX, double radiusY,
            bool filled=false);

    virtual ~Ellipse();
    Ellipse(Point point, double radiusX, double radiusY, bool filled=false);
    Ellipse(Point point, Point radii, bool filled=false);

protected:
    virtual void DrawToDevice(int dev) const;
    Point m_point, m_radii;
    double m_filled;
};

}

#endif
