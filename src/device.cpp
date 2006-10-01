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
#include "device.h"
#include "shape.h"

#ifdef DEBUG
#  include <cassert>
#  include <iostream>
using std::cerr;
using std::endl;
#endif

const char *DEVICETYPE_ERROR="DeviceType for this constructor can only be used"
                             " with ";

namespace g2 {

#ifdef G2_USE_HASH_MAP
hash_map<int, Device*> GlobalTracker;

/*!
    \fn g2::Device::LastUsed()
 */
Device* Device::LastUsed()
{
    return GlobalTracker[g2_ld()];
}
#else
/*!
    \fn g2::Device::LastUsed()
 */
int g2::Device::LastUsed()
{
    return g2_ld();
}
#endif

#if defined G2_USE_FIG || defined G2_USE_PS
Device::Device(const char *filename, DeviceType deviceType)
{
#ifdef DEBUG
    assert(false
#ifdef G2_USE_FIG
           ||(deviceType==FIG)
#endif
#ifdef G2_USE_PS
           ||(deviceType==EPSF)
#endif
           || ((cerr << DEVICETYPE_ERROR << "FIG or EPSF" << endl) && false));

#endif //DEBUG
    CommonInit();
    m_deviceType = deviceType;
#ifdef G2_USE_FIG
    if(FIG==deviceType)
        m_device = g2_open_FIG(filename);
    else
#endif
#ifdef G2_USE_PS
        m_device = g2_open_EPSF(filename);
#endif
    ;
}
#endif //G2_USE_FIG || defined G2_USE_PS

Device::~Device()
{
    g2_close(m_device);
}


}

#if defined G2_USE_PNG || defined G2_USE_JPG || defined G2_USE_PS || G2_USE_GD
/*!
    \fn g2::Device::Device(const char *filename, int width, int height, DeviceType deviceType=png)
 */
 g2::Device::Device(const char *filename, int width, int height, 
                    DeviceType deviceType)
{
#ifdef DEBUG
    assert(false
#if defined G2_USE_PNG || defined G2_USE_GD 
           ||(deviceType==PNG)
#endif
#if defined G2_USE_JPG || defined G2_USE_GD
           ||(deviceType==JPG)
#endif
#ifdef G2_USE_PS
           ||(deviceType==EPSF_CLIP)
#endif
           || ((cerr << DEVICETYPE_ERROR << "JPG, PNG, or EPSF_CLIP") 
               && false));
#endif //DEBUG
    CommonInit();
    m_deviceType = deviceType;
#if defined G2_USE_PNG || defined G2_USE_GD
    if(deviceType==PNG)
        m_device = g2_open_gd(filename, width, height, g2_gd_png);
    else 
#endif
#if defined G2_USE_JPG || defined G2_USE_GD
        if(deviceType==JPG)
            m_device = g2_open_gd(filename, width, height, g2_gd_jpeg);
    else
#endif
#ifdef G2_USE_PS
        m_device = g2_open_EPSF_CLIP(filename, width, height);
#endif
    ;
}
#endif //defined G2_USE_PNG || defined G2_USE_JPG || defined G2_USE_PS || G2_USE_GD

#ifdef G2_USE_PS
/*!
    \fn g2::Device::Device(const char *filename, g2_PS_paper paper, g2_PS_orientation orientation)
 */
 g2::Device::Device(const char *filename, g2_PS_paper paper,
                    g2_PS_orientation orientation, DeviceType deviceType)
{
#ifdef DEBUG
    assert((deviceType==PS)
           || ((cerr << DEVICETYPE_ERROR << "PS" << endl) && false));
#endif
    CommonInit();
    m_deviceType = deviceType;
    m_device = g2_open_PS(filename, paper, orientation);
}
#endif //G2_USE_PS

#ifdef G2_USE_X11
/*!
    \fn g2::Device::Device(int width, int height, DeviceType deviceType=X11)
 */
 g2::Device::Device(int width, int height, DeviceType deviceType)
{
#ifdef DEBUG
    assert((deviceType==X11)
           || ((cerr << DEVICETYPE_ERROR << "X11" << endl) && false));
#endif
    CommonInit();
    m_deviceType = deviceType;
    m_device = g2_open_X11(width, height);
}

/*!
    \fn g2::Device::Device(int width, int height, int x, int y, char *window_name, char *icon_name, char *icon_data, int icon_width, int icon_height, DeviceType deviceType)
 */
 g2::Device::Device(int width, int height, int x, int y, char *window_name,
                    char *icon_name, char *icon_data, int icon_width,
                    int icon_height, DeviceType deviceType)
{
#ifdef DEBUG
    assert((deviceType==X11)
           || ((cerr << DEVICETYPE_ERROR << "X11" << endl) && false));
#endif
    CommonInit();
    m_deviceType = deviceType;
    m_device = g2_open_X11X(width, height, x,y, window_name, icon_name,
                            icon_data, icon_width, icon_height);
}
#endif //G2_USE_X11


/*!
    \fn g2::Device::Device()
 */
 g2::Device::Device(DeviceType deviceType)
{
#ifdef DEBUG
    assert((deviceType==VD)
           || ((cerr << DEVICETYPE_ERROR << "VD" << endl) && false));
#endif
    m_deviceType = deviceType;
    m_device = g2_open_vd();
}


/*!
    \fn g2::Device::Attach(Device device)
 */
void g2::Device::Attach(Device &device) throw( g2exception )
{
    if(VD!=m_deviceType)
        throw g2exception("This is a non-virtual device--cannot attach.",
                          NONATTACHABLE_DEVICE);
#ifdef G2_USE_HASH_MAP
    if(m_trackAttached)
        if(m_deviceTracker[device.m_device]!=&device)
            throw g2exception("That device is already attached.", IS_ATTACHED);
#endif
    g2_attach(m_device, device.m_device);
#ifdef G2_USE_HASH_MAP
    if(m_trackAttached)
        m_deviceTracker[device.m_device] = &device;
#endif
}

/*!
    \fn g2::Device::Detach(const Device &device)
 */
void g2::Device::Detach(Device &device) throw( g2exception )
{
    if(VD!=m_deviceType)
        throw g2exception("This is a non-virtual device--nothing to detach.",
                          NONATTACHABLE_DEVICE);
#ifdef G2_USE_HASH_MAP
    if(m_trackAttached) {
        if(m_deviceTracker[device.m_device]!=&device)
            throw g2exception("That device is not attached.", NOT_ATTACHED);
    }
#endif
    g2_detach(m_device, device.m_device);
#ifdef G2_USE_HASH_MAP
    if(m_trackAttached)
        m_deviceTracker.erase(device.m_device);
#endif
}


/*!
    \fn g2::Device::MoveGraphicCursor(double x, double y)
 */
void g2::Device::MoveGraphicCursor(double x, double y)
{
    g2_move(m_device, x,y);
}


/*!
    \fn g2::Device::MoveGraphicCursor(Point point)
 */
void g2::Device::MoveGraphicCursor(Point point)
{
    if(point.ptype==RELATIVE_PT)
        g2_move_r(m_device, point.x, point.y);
    else
        g2_move(m_device, point.x, point.y);
}


/*!
    \fn g2::Device::CommonInit()
 */
void g2::Device::CommonInit()
{
    m_isAutoflush=false;
#ifdef G2_USE_HASH_MAP
    if(m_trackAttached)
        g2::GlobalTracker[m_device]=this;
#endif
}


/*!
    \fn g2::Device::Autoflush()
 */
bool g2::Device::Autoflush()
{
    return m_isAutoflush;
}


/*!
    \fn g2::Device::Autoflush(bool on_off)
 */
void g2::Device::Autoflush(bool autoflush)
{
    g2_set_auto_flush(m_device, autoflush);
}


/*!
    \fn g2::Device::SetOrigin(int dev, double x_origin, double y_origin, double x_mul, double y_mul)
 */
void g2::Device::SetOrigin(double x_origin, double y_origin,
                           double x_mul, double y_mul)
{
    g2_set_coordinate_system(m_device, x_origin, y_origin, x_mul, y_mul); 
}


/*!
    \fn g2::Device::SetOrigin(Point origin, Point mult_scale)
 */
void g2::Device::SetOrigin(Point origin, Point mult_scale)
{
    g2_set_coordinate_system(m_device, origin.x, origin.y,
                             mult_scale.x, mult_scale.y);
}


/*!
    \fn g2::Device::SetLastUsed(Device &device)
 */
void g2::Device::SetLastUsed(Device &device)
{
    g2_set_ld(device.m_device);
}


/*!
    \fn g2::Device::Flush()
 */
void g2::Device::Flush()
{
    g2_flush(m_device);
}


/*!
    \fn g2::Device::Clear()
 */
void g2::Device::Clear()
{
    g2_clear(m_device);
}


/*!
    \fn g2::Device::Save()
 */
void g2::Device::Save()
{
    g2_save(m_device);
}