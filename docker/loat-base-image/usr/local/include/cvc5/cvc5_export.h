
#ifndef CVC5_EXPORT_H
#define CVC5_EXPORT_H

#ifdef CVC5_STATIC_DEFINE
#  define CVC5_EXPORT
#  define CVC5_NO_EXPORT
#else
#  ifndef CVC5_EXPORT
#    ifdef cvc5_obj_EXPORTS
        /* We are building this library */
#      define CVC5_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define CVC5_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef CVC5_NO_EXPORT
#    define CVC5_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef CVC5_DEPRECATED
#  define CVC5_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef CVC5_DEPRECATED_EXPORT
#  define CVC5_DEPRECATED_EXPORT CVC5_EXPORT CVC5_DEPRECATED
#endif

#ifndef CVC5_DEPRECATED_NO_EXPORT
#  define CVC5_DEPRECATED_NO_EXPORT CVC5_NO_EXPORT CVC5_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef CVC5_NO_DEPRECATED
#    define CVC5_NO_DEPRECATED
#  endif
#endif

#endif /* CVC5_EXPORT_H */
