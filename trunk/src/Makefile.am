bin_PROGRAMS = g2pp
g2pp_SOURCES = g2pp.cpp

# set the include path found by configure
INCLUDES= $(all_includes)

# the library search path.
g2pp_LDFLAGS = $(all_libraries) 
lib_LTLIBRARIES = libg2++.la
libg2___la_SOURCES = arc.cpp circle.cpp device.cpp ellipse.cpp mouse.cpp \
			pen.cpp shape.cpp rectangle.cpp triangle.cpp g2_string.cpp line.cpp \
			g2exception.cpp polygon.cpp manipulator.cpp dashes.cpp fontsize.cpp quasipixelmanip.cpp \
			background.cpp linewidth.cpp spline.cpp multipointshape.cpp

include_HEADERS = arc.h circle.h device.h ellipse.h mouse.h pen.h rectangle.h \
				shape.h triangle.h g2_string.h g2exception.h line.h polygon.h g2++.h \
	background.h dashes.h fontsize.h linewidth.h manipulator.h quasipixelmanip.h
noinst_HEADERS = arc.h circle.h device.h ellipse.h mouse.h pen.h rectangle.h \
			shape.h triangle.h g2_string.h line.h g2exception.h polygon.h g2++.h \
			manipulator.h dashes.h fontsize.h quasipixelmanip.h background.h linewidth.h spline.h \
	multipointshape.h
g2pp_LDADD = $(top_builddir)/src/libg2++.la -lgd -lX11 -lg2

