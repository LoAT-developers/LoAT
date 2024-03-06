/** @file iop_include.h Includes all io device headers */


#ifndef FAUDES_IOP_INCLUDE_H
#define FAUDES_IOP_INCLUDE_H

#include "iop_xdevice.h"
#include "iop_vdevice.h"
#include "iop_sdevice.h"
#include "iop_comedi.h"
#include "iop_simplenet.h"
#include "iop_serial.h"
#include "iop_modbus.h"
#include "iop_wago.h"
#include "iop_d3ripURT.h"   
#include "iop_d3ripDART.h"

#endif



/**
 
@defgroup IODevicePlugin I/O Device PlugIn


@ingroup AllPlugins


<p>
This plug-in maps logical faudes events to physical events. The latter are to be executed 
on and sensed by specific hard- or software. Individual device classes must be explicitely
enabled in <tt>Makefile.plugin</tt>. The above list shows devices available 
in this build of libFAUDES.
</p>

<p>
Note: this plug-in is in an early stage of development, some design issues are not
yet resolved. 
</p>

<p>
Note: In contrast to the libFAUDES core, the iodevice plug-in 
not meant to be platform independant.
It has been developed for Linux and thus freely uses POSIX threads, BSD sockets, the
comedi framework and real-time kernel extensions. This being said, a simple platform 
abstraction layer adapts relevant system calls for Windows and, thus, provides
the Modbus device and the Simplenet device.
</p>

@section IodLicense License

<p>
This plug-in is distributed with libFAUDES and under the terms of the LGPL. 
However, some devices may require separate installation of non-open source code 
to compile.
<br>
<br>
<br>
Copyright (c) 2008, Thomas Moor.
<br>
Copyright (c) 2009, Thomas Moor, Thomas Wittmann.
<br>
Copyright (c) 2010-2013, Thomas Moor.
</p>

*/

