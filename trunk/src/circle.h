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
#ifndef G2CIRCLE_H
#define G2CIRCLE_H

#include <shape.h>

namespace g2 {

/**
	@author Rene Horn <the.rhorn@gmail.com>
*/
class Circle : public Shape
{
public:
    Circle(double x, double y, double radius, bool filled=false);

    virtual ~Circle();
    Circle(Point point, double radius, bool filled=false);
    Circle(Point point, Point radial_point, bool filled=false);

protected:
    virtual void DrawToDevice(int dev) const;
    double m_radius;
    Point m_point;
    bool m_filled;
};

}

#endif
