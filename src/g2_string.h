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
#ifndef G2G2_STRING_H
#define G2G2_STRING_H

#include <g2exception.h>
#include <shape.h>

namespace g2 {

/**
    @author Rene Horn <the.rhorn@gmail.com>
*/
class g2_String : public Shape
{
public:
    g2_String(double x, double y, const char *text, bool filled=false);

    virtual ~g2_String();
    g2_String(double x, double y, const char *text, size_t textLength, 
              bool filled=false);
    g2_String(Point point, const char *text, bool filled=false);
    g2_String(Point point, const char *text, size_t textLength,
              bool filled=false);
    void FontSize(double font_size);
    double FontSize() throw( g2exception );

protected:
    virtual void DrawToDevice(int dev) const;
    void CommonInit();
    Point m_point;
    char *m_text;
    size_t m_textLen;
    double m_fontSize;
}; //g2_String

} //g2

#endif //G2G2_STRING_H
