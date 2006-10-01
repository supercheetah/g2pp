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
#ifndef G2LINE_H
#define G2LINE_H

#include <shape.h>

namespace g2 {

typedef enum {
    TO_GRAPHICCURSOR,
    FROM_GRAPHICCURSOR,
    NORMAL_LINE
} LineType;

/**
    @author Rene Horn <the.rhorn@gmail.com>
*/
class Line : public Shape
{
public:
    Line(double x1, double y1, double x2, double y2);

    virtual ~Line();
    Line(Point p1, Point p2);
    Line(double x, double y, LineType linetype=FROM_GRAPHICCURSOR);
    Line(Point point, LineType linetype=FROM_GRAPHICCURSOR);

protected:
    virtual void DrawToDevice(int dev) const;
    Point m_p1, m_p2;
    LineType m_linetype;
};

} //namespace g2

#endif //G2LINE_H
