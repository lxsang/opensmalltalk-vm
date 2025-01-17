/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.3024 uuid: 417aa150-be4e-4631-b35b-948afa18e190
   from
	SecurityPlugin VMMaker.oscog-eem.3024 uuid: 417aa150-be4e-4631-b35b-948afa18e190
 */
static char __buildInfo[] = "SecurityPlugin VMMaker.oscog-eem.3024 uuid: 417aa150-be4e-4631-b35b-948afa18e190 " __DATE__ ;


#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#include "SecurityPlugin.h"
#include "sqMemoryAccess.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveCanWriteImage(void);
EXPORT(sqInt) primitiveDisableImageWrite(void);
EXPORT(sqInt) primitiveGetSecureUserDirectory(void);
EXPORT(sqInt) primitiveGetUntrustedUserDirectory(void);
EXPORT(sqInt) secCanConnectToPort(sqInt addr, sqInt port);
EXPORT(sqInt) secCanCreatePathOfSize(char *dirName, sqInt dirNameSize);
EXPORT(sqInt) secCanCreateSocketOfType(sqInt netType, sqInt socketType);
EXPORT(sqInt) secCanDeleteFileOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanDeletePathOfSize(char *dirName, sqInt dirNameSize);
EXPORT(sqInt) secCanGetFileTypeOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanListPathOfSize(char *pathName, sqInt pathNameSize);
EXPORT(sqInt) secCanOpenAsyncFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag);
EXPORT(sqInt) secCanOpenFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag);
EXPORT(sqInt) secCanRenameFileOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanRenameImage(void);
EXPORT(sqInt) secCanSetFileTypeOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanWriteImage(void);
EXPORT(sqInt) secCanListenOnPort(sqInt socket, sqInt port);
EXPORT(sqInt) secDisableFileAccess(void);
EXPORT(sqInt) secDisableSocketAccess(void);
EXPORT(sqInt) secHasEnvironmentAccess(void);
EXPORT(sqInt) secHasFileAccess(void);
EXPORT(sqInt) secHasSocketAccess(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static sqInt (*methodReturnBool)(sqInt boolean);
static sqInt (*methodReturnString)(char *aCString);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern sqInt methodReturnBool(sqInt boolean);
extern sqInt methodReturnString(char *aCString);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "SecurityPlugin VMMaker.oscog-eem.3024 " INT_EXT;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* SecurityPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return ioInitSecurity();
}

	/* SecurityPlugin>>#primitiveCanWriteImage */
EXPORT(sqInt)
primitiveCanWriteImage(void)
{
	methodReturnBool(ioCanWriteImage());
	return 0;
}

	/* SecurityPlugin>>#primitiveDisableImageWrite */
EXPORT(sqInt)
primitiveDisableImageWrite(void)
{
	ioDisableImageWrite();
	return 0;
}


/*	Primitive. Return the secure directory for the current user. */

	/* SecurityPlugin>>#primitiveGetSecureUserDirectory */
EXPORT(sqInt)
primitiveGetSecureUserDirectory(void)
{
    char *dirName;

	dirName = ioGetSecureUserDirectory();
	if (!(failed())) {
		methodReturnString(dirName);
	}
	return 0;
}


/*	Primitive. Return the untrusted user directory name. */

	/* SecurityPlugin>>#primitiveGetUntrustedUserDirectory */
EXPORT(sqInt)
primitiveGetUntrustedUserDirectory(void)
{
    char *dirName;

	dirName = ioGetUntrustedUserDirectory();
	if (!(failed())) {
		methodReturnString(dirName);
	}
	return 0;
}

	/* SecurityPlugin>>#secCanConnect:ToPort: */
EXPORT(sqInt)
secCanConnectToPort(sqInt addr, sqInt port)
{
	return ioCanConnectToPort(addr, port);
}

	/* SecurityPlugin>>#secCanCreatePath:OfSize: */
EXPORT(sqInt)
secCanCreatePathOfSize(char *dirName, sqInt dirNameSize)
{
	return ioCanCreatePathOfSize(dirName, dirNameSize);
}

	/* SecurityPlugin>>#secCanCreate:SocketOfType: */
EXPORT(sqInt)
secCanCreateSocketOfType(sqInt netType, sqInt socketType)
{
	return ioCanCreateSocketOfType(netType, socketType);
}

	/* SecurityPlugin>>#secCanDeleteFile:OfSize: */
EXPORT(sqInt)
secCanDeleteFileOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanDeleteFileOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanDeletePath:OfSize: */
EXPORT(sqInt)
secCanDeletePathOfSize(char *dirName, sqInt dirNameSize)
{
	return ioCanDeletePathOfSize(dirName, dirNameSize);
}

	/* SecurityPlugin>>#secCanGetFileType:OfSize: */
EXPORT(sqInt)
secCanGetFileTypeOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanGetFileTypeOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanListPath:OfSize: */
EXPORT(sqInt)
secCanListPathOfSize(char *pathName, sqInt pathNameSize)
{
	return ioCanListPathOfSize(pathName, pathNameSize);
}

	/* SecurityPlugin>>#secCanOpenAsyncFile:OfSize:Writable: */
EXPORT(sqInt)
secCanOpenAsyncFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag)
{
	return ioCanOpenAsyncFileOfSizeWritable(fileName, fileNameSize, writeFlag);
}

	/* SecurityPlugin>>#secCanOpenFile:OfSize:Writable: */
EXPORT(sqInt)
secCanOpenFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag)
{
	return ioCanOpenFileOfSizeWritable(fileName, fileNameSize, writeFlag);
}

	/* SecurityPlugin>>#secCanRenameFile:OfSize: */
EXPORT(sqInt)
secCanRenameFileOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanRenameFileOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanRenameImage */
EXPORT(sqInt)
secCanRenameImage(void)
{
	return ioCanRenameImage();
}

	/* SecurityPlugin>>#secCanSetFileType:OfSize: */
EXPORT(sqInt)
secCanSetFileTypeOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanSetFileTypeOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanWriteImage */
EXPORT(sqInt)
secCanWriteImage(void)
{
	return ioCanWriteImage();
}

	/* SecurityPlugin>>#secCan:ListenOnPort: */
EXPORT(sqInt)
secCanListenOnPort(sqInt socket, sqInt port)
{
	return ioCanListenOnPort(socket, port);
}

	/* SecurityPlugin>>#secDisableFileAccess */
EXPORT(sqInt)
secDisableFileAccess(void)
{
	return ioDisableFileAccess();
}

	/* SecurityPlugin>>#secDisableSocketAccess */
EXPORT(sqInt)
secDisableSocketAccess(void)
{
	return ioDisableSocketAccess();
}

	/* SecurityPlugin>>#secHasEnvironmentAccess */
EXPORT(sqInt)
secHasEnvironmentAccess(void)
{
	return ioHasEnvironmentAccess();
}

	/* SecurityPlugin>>#secHasFileAccess */
EXPORT(sqInt)
secHasFileAccess(void)
{
	return ioHasFileAccess();
}

	/* SecurityPlugin>>#secHasSocketAccess */
EXPORT(sqInt)
secHasSocketAccess(void)
{
	return ioHasSocketAccess();
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
    sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
		methodReturnBool = interpreterProxy->methodReturnBool;
		methodReturnString = interpreterProxy->methodReturnString;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "SecurityPlugin";
void* SecurityPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "primitiveCanWriteImage\000\377\000", (void*)primitiveCanWriteImage},
	{(void*)_m, "primitiveDisableImageWrite\000\377\000", (void*)primitiveDisableImageWrite},
	{(void*)_m, "primitiveGetSecureUserDirectory\000\377\000", (void*)primitiveGetSecureUserDirectory},
	{(void*)_m, "primitiveGetUntrustedUserDirectory\000\377\000", (void*)primitiveGetUntrustedUserDirectory},
	{(void*)_m, "secCanConnectToPort", (void*)secCanConnectToPort},
	{(void*)_m, "secCanCreatePathOfSize", (void*)secCanCreatePathOfSize},
	{(void*)_m, "secCanCreateSocketOfType", (void*)secCanCreateSocketOfType},
	{(void*)_m, "secCanDeleteFileOfSize", (void*)secCanDeleteFileOfSize},
	{(void*)_m, "secCanDeletePathOfSize", (void*)secCanDeletePathOfSize},
	{(void*)_m, "secCanGetFileTypeOfSize", (void*)secCanGetFileTypeOfSize},
	{(void*)_m, "secCanListPathOfSize", (void*)secCanListPathOfSize},
	{(void*)_m, "secCanOpenAsyncFileOfSizeWritable", (void*)secCanOpenAsyncFileOfSizeWritable},
	{(void*)_m, "secCanOpenFileOfSizeWritable", (void*)secCanOpenFileOfSizeWritable},
	{(void*)_m, "secCanRenameFileOfSize", (void*)secCanRenameFileOfSize},
	{(void*)_m, "secCanRenameImage", (void*)secCanRenameImage},
	{(void*)_m, "secCanSetFileTypeOfSize", (void*)secCanSetFileTypeOfSize},
	{(void*)_m, "secCanWriteImage", (void*)secCanWriteImage},
	{(void*)_m, "secCanListenOnPort", (void*)secCanListenOnPort},
	{(void*)_m, "secDisableFileAccess", (void*)secDisableFileAccess},
	{(void*)_m, "secDisableSocketAccess", (void*)secDisableSocketAccess},
	{(void*)_m, "secHasEnvironmentAccess", (void*)secHasEnvironmentAccess},
	{(void*)_m, "secHasFileAccess", (void*)secHasFileAccess},
	{(void*)_m, "secHasSocketAccess", (void*)secHasSocketAccess},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else // ifdef SQ_BUILTIN_PLUGIN

#if SPURVM
#endif // SPURVM

#endif // ifdef SQ_BUILTIN_PLUGIN
