#ifndef AVLTREE_GLOBAL_H
#define AVLTREE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AVLTREE_LIBRARY)
#  define AVLTREESHARED_EXPORT Q_DECL_EXPORT
#else
#  define AVLTREESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // AVLTREE_GLOBAL_H
