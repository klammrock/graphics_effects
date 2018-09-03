#ifndef GRAPHICS_CORE_GLOBAL_H
#define GRAPHICS_CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GRAPHICS_CORE_LIBRARY)
#  define GRAPHICS_CORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define GRAPHICS_CORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GRAPHICS_CORE_GLOBAL_H