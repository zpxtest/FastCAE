
#ifndef VTKCOMMONTRANSFORMS_EXPORT_H
#define VTKCOMMONTRANSFORMS_EXPORT_H

#ifdef VTKCOMMONTRANSFORMS_STATIC_DEFINE
#  define VTKCOMMONTRANSFORMS_EXPORT
#  define VTKCOMMONTRANSFORMS_NO_EXPORT
#else
#  ifndef VTKCOMMONTRANSFORMS_EXPORT
#    ifdef vtkCommonTransforms_EXPORTS
        /* We are building this library */
#      define VTKCOMMONTRANSFORMS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONTRANSFORMS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONTRANSFORMS_NO_EXPORT
#    define VTKCOMMONTRANSFORMS_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONTRANSFORMS_DEPRECATED
#  define VTKCOMMONTRANSFORMS_DEPRECATED __declspec(deprecated)
#  define VTKCOMMONTRANSFORMS_DEPRECATED_EXPORT VTKCOMMONTRANSFORMS_EXPORT __declspec(deprecated)
#  define VTKCOMMONTRANSFORMS_DEPRECATED_NO_EXPORT VTKCOMMONTRANSFORMS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKCOMMONTRANSFORMS_NO_DEPRECATED
#endif



#endif
