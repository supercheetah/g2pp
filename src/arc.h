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
#ifndef G2ARC_H
#define G2ARC_H

#include <shape.h>

namespace g2 {

/**
	@author Rene Horn <the.rhorn@gmail.com>
*/
class Arc : public Shape
{
public:
    Arc(double x, double y, double radiusX, double radiusY, double angle_start,
        double angle_end, bool filled=false);

    virtual ~Arc();
     Arc(Point point, double radiusX, double radiusY, double angle_start, 
         double angle_end, bool filled=false);
     Arc(Point point, Point radii, double angle_start, double angle_end,
         bool filled=false);

protected:
    virtual void DrawToDevice(int dev) const;
    double m_angle_start, m_angle_end;
    Point m_point, m_radii;
    bool m_filled;
};

}

#endif
