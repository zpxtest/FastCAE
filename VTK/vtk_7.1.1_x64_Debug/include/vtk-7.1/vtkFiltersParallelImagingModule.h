
#ifndef VTKFILTERSPARALLELIMAGING_EXPORT_H
#define VTKFILTERSPARALLELIMAGING_EXPORT_H

#ifdef VTKFILTERSPARALLELIMAGING_STATIC_DEFINE
#  define VTKFILTERSPARALLELIMAGING_EXPORT
#  define VTKFILTERSPARALLELIMAGING_NO_EXPORT
#else
#  ifndef VTKFILTERSPARALLELIMAGING_EXPORT
#    ifdef vtkFiltersParallelImaging_EXPORTS
        /* We are building this library */
#      define VTKFILTERSPARALLELIMAGING_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSPARALLELIMAGING_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSPARALLELIMAGING_NO_EXPORT
#    define VTKFILTERSPARALLELIMAGING_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSPARALLELIMAGING_DEPRECATED
#  define VTKFILTERSPARALLELIMAGING_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSPARALLELIMAGING_DEPRECATED_EXPORT VTKFILTERSPARALLELIMAGING_EXPORT __declspec(deprecated)
#  define VTKFILTERSPARALLELIMAGING_DEPRECATED_NO_EXPORT VTKFILTERSPARALLELIMAGING_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSPARALLELIMAGING_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkFiltersImagingModule.h"
#include "vtkFiltersParallelModule.h"

#endif
