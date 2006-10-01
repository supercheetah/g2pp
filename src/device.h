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
#ifndef G2DEVICE_H
#define G2DEVICE_H

#ifdef G2_USE_HASH_MAP
#include <ext/hash_map>
using __gnu_cxx::hash_map;
#endif

#include <g2.h>
#include <pen.h>
#include <g2exception.h>

#ifdef G2_USE_FIG
#  include <g2_FIG.h>
#endif

#if defined G2_USE_PNG || defined G2_USE_GD || defined G2_USE_JPG
#  include <g2_gd.h>
#endif

#ifdef G2_USE_PS
#  include <g2_PS.h>
#endif

#ifdef G2_USE_X11
#  include <g2_X11.h>
#endif

#if !defined G2_USE_FIG && !defined G2_USE_PNG && !defined G2_USE_GD \
        && !defined G2_USE_JPG && !defined G2_USE_PS \
        && !defined G2_USE_X11
#  warning "Warning: No device type(s) set.  E.g. #define G2_USE_PNG"
#endif

namespace g2 {

enum DeviceType {
#ifdef G2_USE_FIG
    FIG,
#endif
#if defined G2_USE_PNG || defined G2_USE_GD
    PNG,
#endif
#if defined G2_USE_JPG || defined G2_USE_GD
    JPG,
#endif
#ifdef G2_USE_PS
    PS,
    EPSF,
    EPSF_CLIP,
#endif
#ifdef G2_USE_X11
    X11,
#endif
    VD
};

struct Point;
class Shape;
class Mouse;

/**
    @author Rene Horn <the.rhorn@gmail.com>
*/
class Device {
    friend Device& operator>> (Device &din, Mouse mouse);
    friend Device& operator>> (Device &din, Ink ink) throw( g2exception );
    friend Device& operator<< (Device &dout, Pen pen);
    friend Device& operator<< (Device& dout, const Point& point);
    friend Device& operator<< (Device& dout, const Shape& shape);
public:
//start: c'tor
#if defined G2_USE_FIG || defined G2_USE_PS
    Device(const char *filename,
//start: default DeviceType
#if defined G2_USE_FIG
           DeviceType deviceType=FIG);
#elif defined G2_USE_PS
           DeviceType deviceType=PS);
#else
#  error "Error: unknown usage, shouldn't even get here."
#endif //end: default DeviceType

#endif //end: c'tor

    ~Device();
    Device(DeviceType deviceType=VD);
    void Attach(Device &device) throw( g2exception );
    void Detach(Device &device) throw( g2exception );
    void MoveGraphicCursor(double x, double y);
    void MoveGraphicCursor(Point point);
    bool Autoflush();
    void Autoflush(bool autoflush);
    void SetOrigin(double x_origin, double y_origin, 
                   double x_mul, double y_mul);
    void SetOrigin(Point origin, Point mult_scale);
    static void SetLastUsed(Device &device);
    void Flush();
    void Clear();
    void Save();
#ifdef G2_USE_HASH_MAP
    static Device* LastUsed();
#endif

#ifdef G2_USE_X11
     Device(int width, int height, int x, int y, char *window_name,
            char *icon_name, char *icon_data, int icon_width,
            int icon_height, DeviceType deviceType=X11);
     Device(int width, int height, DeviceType deviceType=X11);
#endif //G2_USE_X11

//start: compile c'tor
#if defined G2_USE_JPG || defined G2_USE_PNG \
        || defined G2_USE_PS || G2_USE_GD
     Device(const char *filename, int width, int height,
//start: default DeviceType
#if defined G2_USE_PNG ||G2_USE_GD 
            DeviceType devicetype=PNG);
#elif defined G2_USE_JPG
            DeviceType devicetype=JPG);
#elif defined G2_USE_PS
            DeviceType devicetype=EPSF_CLIP);
#else
#  error "Error: unknown usage, shouldn't even get here"
#endif //end: default DeviceType

#endif //end: compile c'tor

#ifdef G2_USE_PS
     Device(const char *filename, g2_PS_paper paper,
            g2_PS_orientation orientation, DeviceType deviceType=PS);
#endif

protected:
    int m_device;
    DeviceType m_deviceType;
    Pen m_pen;
    bool m_isAutoflush;
    void CommonInit();
#ifdef G2_USE_HASH_MAP
    hash_map<int, Device*> m_deviceTracker;
    const static bool m_trackAttached=true;
#else
    const static bool m_trackAttached=false;
#endif
}; //class Device

} //namespace g2

#endif //G2DEVICE_H
