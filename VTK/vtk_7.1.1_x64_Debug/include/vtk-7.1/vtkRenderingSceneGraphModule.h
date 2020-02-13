
#ifndef VTKRENDERINGSCENEGRAPH_EXPORT_H
#define VTKRENDERINGSCENEGRAPH_EXPORT_H

#ifdef VTKRENDERINGSCENEGRAPH_STATIC_DEFINE
#  define VTKRENDERINGSCENEGRAPH_EXPORT
#  define VTKRENDERINGSCENEGRAPH_NO_EXPORT
#else
#  ifndef VTKRENDERINGSCENEGRAPH_EXPORT
#    ifdef vtkRenderingSceneGraph_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGSCENEGRAPH_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGSCENEGRAPH_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGSCENEGRAPH_NO_EXPORT
#    define VTKRENDERINGSCENEGRAPH_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGSCENEGRAPH_DEPRECATED
#  define VTKRENDERINGSCENEGRAPH_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGSCENEGRAPH_DEPRECATED_EXPORT VTKRENDERINGSCENEGRAPH_EXPORT __declspec(deprecated)
#  define VTKRENDERINGSCENEGRAPH_DEPRECATED_NO_EXPORT VTKRENDERINGSCENEGRAPH_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGSCENEGRAPH_NO_DEPRECATED
#endif



#endif
