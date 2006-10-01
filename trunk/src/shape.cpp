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
#include "shape.h"
#include "device.h"

namespace g2 {

Device& operator <<(Device& dout, const Point& point)
{
    switch(point.ptype) {
        case NORMAL_PT:
            g2_plot(dout.m_device, point.x, point.y);
            break;
        case QUASIPIXEL:
            g2_plot_QP(dout.m_device, point.x, point.y);
            break;
        case RELATIVE_PT:
            g2_plot_r(dout.m_device, point.x, point.y);
            break;
    }
    return dout;
}

Device& operator<<(Device& dout, const Shape& shape)
{
    shape.DrawToDevice( dout.m_device);
    return dout;
}

Shape::Shape()
{
}


Shape::~Shape()
{
}


}
