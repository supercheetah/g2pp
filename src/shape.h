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
#ifndef G2SHAPE_H
#define G2SHAPE_H

#include <g2.h>

#ifndef size_t
typedef unsigned size_t;
#endif

namespace g2 {

typedef enum
{
    QUASIPIXEL,
    RELATIVE_PT,
    NORMAL_PT
} PointType;

struct Point
{
    inline Point(): ptype(NORMAL_PT) {}
    inline Point(double x_, double y_) { x=x_; y=y_;}
    double x, y;
    PointType ptype;
};

class Device;

Device& operator <<(Device& dout, const Point& point);

/**
    @author Rene Horn <the.rhorn@gmail.com>
*/
class Shape{
    friend Device& operator<<(Device& dout, const Shape& shape);
public:
    Shape();

    virtual ~Shape();

protected:
    virtual void DrawToDevice(int dev) const = 0;
};

Device& operator<<(Device& dout, const Shape& shape);

} //namespace g2

#endif //G2SHAPE_H
