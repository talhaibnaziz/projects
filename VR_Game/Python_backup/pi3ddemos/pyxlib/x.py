from ctypes import *

X_PROTOCOL = 11
X_PROTOCOL_REVISION = 0

#~ /* Resources */

#~ /*
 #~ * _XSERVER64 must ONLY be defined when compiling X server sources on
 #~ * systems where unsigned long is not 32 bits, must NOT be used in
 #~ * client or library code.
 #~ */

#~ typedef unsigned long XID;
#~ typedef unsigned long Mask;
#~ typedef unsigned long Atom;  /* Also in Xdefs.h */
#~ typedef unsigned long VisualID;
#~ typedef unsigned long Time;
XID = c_ulong
Mask = c_ulong
Atom = c_ulong
VisualID = c_ulong
Time = c_ulong

#~ typedef XID Window;
#~ typedef XID Drawable;
#~ typedef XID Font;
#~ typedef XID Pixmap;
#~ typedef XID Cursor;
#~ typedef XID Colormap;
#~ typedef XID GContext;
#~ typedef XID KeySym;
Window = XID
Drawable = XID
Font = XID
Pixmap = XID
Cursor = XID
Colormap = XID
GContext = XID
KeySym = XID

#~ typedef unsigned char KeyCode;
KeyCode = c_ubyte

# ****************************************************************
# * RESERVED RESOURCE AND CONSTANT DEFINITIONS
# ****************************************************************

NULL = None

#ifndef None
NONE = 0 # universal null resource or null atom 
#endif

ParentRelative = 1 # background pixmap in CreateWindow
#     and ChangeWindowAttributes 

CopyFromParent = 0 # border pixmap in CreateWindow
#        and ChangeWindowAttributes
#       special VisualID and special window
#        class passed to CreateWindow 

PointerWindow = 0 # destination window in SendEvent 
InputFocus = 1 # destination window in SendEvent 

PointerRoot = 1 # focus window in SetInputFocus 

AnyPropertyType = 0 # special Atom, passed to GetProperty 

AnyKey = 0 # special Key Code, passed to GrabKey 

AnyButton = 0 # special Button Code, passed to GrabButton 

AllTemporary = 0 # special Resource ID passed to KillClient 

CurrentTime = 0 # special Time 

NoSymbol = 0 # special KeySym 

# ****************************************************************
# * EVENT DEFINITIONS
# ****************************************************************

#  Input Event Masks. Used as event-mask window attribute and as arguments
#   to Grab requests.  Not to be confused with event names.  

NoEventMask =  0
KeyPressMask =   (1<<0)
KeyReleaseMask =   (1<<1)
ButtonPressMask =  (1<<2)
ButtonReleaseMask =  (1<<3)
EnterWindowMask =  (1<<4)
LeaveWindowMask =  (1<<5)
PointerMotionMask =  (1<<6)
PointerMotionHintMask =  (1<<7)
Button1MotionMask  = (1<<8)
Button2MotionMask = (1<<9)
Button3MotionMask = (1<<10)
Button4MotionMask = (1<<11)
Button5MotionMask = (1<<12)
ButtonMotionMask = (1<<13)
KeymapStateMask  = (1<<14)
ExposureMask  = (1<<15)
VisibilityChangeMask = (1<<16)
StructureNotifyMask = (1<<17)
ResizeRedirectMask = (1<<18)
SubstructureNotifyMask = (1<<19)
SubstructureRedirectMask= (1<<20)
FocusChangeMask  = (1<<21)
PropertyChangeMask = (1<<22)
ColormapChangeMask = (1<<23)
OwnerGrabButtonMask = (1<<24)

#  Event names.  Used in "type" field in XEvent structures.  Not to be
#confused with event masks above.  They start from 2 because 0 and 1
#are reserved in the protocol for errors and replies. 

KeyPress = 2
KeyRelease = 3
ButtonPress = 4
ButtonRelease = 5
MotionNotify = 6
EnterNotify = 7
LeaveNotify = 8
FocusIn  = 9
FocusOut = 10
KeymapNotify = 11
Expose  = 12
GraphicsExpose = 13
NoExpose = 14
VisibilityNotify =15
CreateNotify = 16
DestroyNotify = 17
UnmapNotify  =18
MapNotify  =19
MapRequest = 20
ReparentNotify = 21
ConfigureNotify = 22
ConfigureRequest =23
GravityNotify = 24
ResizeRequest = 25
CirculateNotify = 26
CirculateRequest= 27
PropertyNotify = 28
SelectionClear = 29
SelectionRequest= 30
SelectionNotify = 31
ColormapNotify = 32
ClientMessage = 33
MappingNotify = 34
GenericEvent = 35
LASTEvent = 36 # must be bigger than any event # 


#  Key masks. Used as modifiers to GrabButton and GrabKey, results of QueryPointer,
#   state in various key-, mouse-, and button-related events. 

ShiftMask = (1<<0)
LockMask = (1<<1)
ControlMask = (1<<2)
Mod1Mask = (1<<3)
Mod2Mask = (1<<4)
Mod3Mask = (1<<5)
Mod4Mask = (1<<6)
Mod5Mask = (1<<7)

#  modifier names.  Used to build a SetModifierMapping request or
#   to read a GetModifierMapping request.  These correspond to the
#   masks defined above. 
ShiftMapIndex = 0
LockMapIndex = 1
ControlMapIndex = 2
Mod1MapIndex = 3
Mod2MapIndex = 4
Mod3MapIndex = 5
Mod4MapIndex = 6
Mod5MapIndex = 7


#  button masks.  Used in same manner as Key masks above. Not to be confused
#   with button names below. 

Button1Mask = (1<<8)
Button2Mask  =(1<<9)
Button3Mask = (1<<10)
Button4Mask = (1<<11)
Button5Mask = (1<<12)

AnyModifier = (1<<15)  # used in GrabButton, GrabKey 


#  button names. Used as arguments to GrabButton and as detail in ButtonPress
#   and ButtonRelease events.  Not to be confused with button masks above.
#   Note that 0 is already defined above as "AnyButton".  

Button1  = 1
Button2  = 2
Button3  = 3
Button4  = 4
Button5  = 5

#  Notify modes 

NotifyNormal = 0
NotifyGrab = 1
NotifyUngrab = 2
NotifyWhileGrabbed= 3

NotifyHint = 1 # for MotionNotify events 

#  Notify detail 

NotifyAncestor = 0
NotifyVirtual = 1
NotifyInferior = 2
NotifyNonlinear = 3
NotifyNonlinearVirtual = 4
NotifyPointer = 5
NotifyPointerRoot =6
NotifyDetailNone =7

#  Visibility notify 

VisibilityUnobscured = 0
VisibilityPartiallyObscured= 1
VisibilityFullyObscured = 2

#  Circulation request 

PlaceOnTop = 0
PlaceOnBottom = 1

#  protocol families 

FamilyInternet = 0 # IPv4 
FamilyDECnet = 1
FamilyChaos = 2
FamilyInternet6 = 6 # IPv6 

#  authentication families not tied to a specific protocol 
FamilyServerInterpreted = 5

#  Property notification 

PropertyNewValue =0
PropertyDelete =1

#  Color Map notification 

ColormapUninstalled= 0
ColormapInstalled =1

#  GrabPointer, GrabButton, GrabKeyboard, GrabKey Modes 

GrabModeSync = 0
GrabModeAsync = 1

#  GrabPointer, GrabKeyboard reply status 

GrabSuccess = 0
AlreadyGrabbed = 1
GrabInvalidTime = 2
GrabNotViewable = 3
GrabFrozen = 4

#  AllowEvents modes 

AsyncPointer = 0
SyncPointer  = 1
ReplayPointer = 2
AsyncKeyboard = 3
SyncKeyboard = 4
ReplayKeyboard = 5
AsyncBoth = 6
SyncBoth = 7

#  Used in SetInputFocus, GetInputFocus 

RevertToNone = NONE
RevertToPointerRoot = PointerRoot
RevertToParent = 2

# ****************************************************************
# * ERROR CODES
# ****************************************************************

Success    = 0 # everything's okay 
BadRequest   = 1 # bad request code 
BadValue   = 2 # int parameter out of range 
BadWindow   = 3 # parameter not a Window 
BadPixmap   = 4 # parameter not a Pixmap 
BadAtom    = 5 # parameter not an Atom 
BadCursor   = 6 # parameter not a Cursor 
BadFont    = 7 # parameter not a Font 
BadMatch   = 8 # parameter mismatch 
BadDrawable   = 9 # parameter not a Pixmap or Window 
BadAccess   = 10 # depending on context:
#     - key/button already grabbed
#     - attempt to free an illegal
#       cmap entry
#    - attempt to store into a read-only
#       color map entry.
#     - attempt to modify the access control
#       list from other than the local host.
#    
BadAlloc  = 11 # insufficient resources 
BadColor  = 12 # no such colormap 
BadGC   = 13 # parameter not a GC 
BadIDChoice  = 14 # choice not in range or already used 
BadName   = 15 # font or color name doesn't exist 
BadLength  = 16 # Request length incorrect 
BadImplementation = 17 # server is defective 

FirstExtensionError = 128
LastExtensionError = 255

# ****************************************************************
# * WINDOW DEFINITIONS
# ****************************************************************

#  Window classes used by CreateWindow 
#  Note that CopyFromParent is already defined as 0 above 

InputOutput  = 1
InputOnly  = 2

#  Window attributes for CreateWindow and ChangeWindowAttributes 

CWBackPixmap=  (1<<0)
CWBackPixel = (1<<1)
CWBorderPixmap = (1<<2)
CWBorderPixel =    (1<<3)
CWBitGravity = (1<<4)
CWWinGravity = (1<<5)
CWBackingStore   =    (1<<6)
CWBackingPlanes   =   (1<<7)
CWBackingPixel   =   (1<<8)
CWOverrideRedirect =(1<<9)
CWSaveUnder = (1<<10)
CWEventMask = (1<<11)
CWDontPropagate   =   (1<<12)
CWColormap = (1<<13)
CWCursor  =    (1<<14)

#  ConfigureWindow structure 

CWX  = (1<<0)
CWY  = (1<<1)
CWWidth  = (1<<2)
CWHeight = (1<<3)
CWBorderWidth = (1<<4)
CWSibling = (1<<5)
CWStackMode = (1<<6)


#  Bit Gravity 

ForgetGravity = 0
NorthWestGravity =1
NorthGravity  =2
NorthEastGravity= 3
WestGravity = 4
CenterGravity = 5
EastGravity  =6
SouthWestGravity= 7
SouthGravity = 8
SouthEastGravity= 9
StaticGravity = 10

#  Window gravity + bit gravity above 

UnmapGravity = 0

#  Used in CreateWindow for backing-store hint 

NotUseful   =   0
WhenMapped   =  1
Always    =  2

#  Used in GetWindowAttributes reply 

IsUnmapped = 0
IsUnviewable = 1
IsViewable = 2

#  Used in ChangeSaveSet 

SetModeInsert   =  0
SetModeDelete =    1

#  Used in ChangeCloseDownMode 

DestroyAll    =    0
RetainPermanent   =   1
RetainTemporary   =   2

#  Window stacking method (in configureWindow) 

Above     =  0
Below    =   1
TopIf    =   2
BottomIf    =   3
Opposite     =  4

#  Circulation direction 

RaiseLowest    =   0
LowerHighest   =   1

#  Property modes 

PropModeReplace =  0
PropModePrepend =  1
PropModeAppend  =  2

# ****************************************************************
# * GRAPHICS DEFINITIONS
# ****************************************************************

#  graphics functions, as in GC.alu 

GXclear =  0x0  # 0 
GXand =  0x1  # src AND dst 
GXandReverse=  0x2  # src AND NOT dst 
GXcopy  = 0x3  # src 
GXandInverted = 0x4  # NOT src AND dst 
GXnoop=   0x5  # dst 
GXxor =  0x6  # src XOR dst 
GXor =  0x7  # src OR dst 
GXnor =  0x8  # NOT src AND NOT dst 
GXequiv =  0x9  # NOT src XOR dst 
GXinvert = 0xa  # NOT dst 
GXorReverse = 0xb  # src OR NOT dst 
GXcopyInverted = 0xc  # NOT src 
GXorInverted = 0xd  # NOT src OR dst 
GXnand  = 0xe  # NOT src OR NOT dst 
GXset =  0xf  # 1 

#  LineStyle 

LineSolid = 0
LineOnOffDash = 1
LineDoubleDash = 2

#  capStyle 

CapNotLast = 0
CapButt  = 1
CapRound = 2
CapProjecting = 3

#  joinStyle 

JoinMiter = 0
JoinRound = 1
JoinBevel = 2

#  fillStyle 

FillSolid = 0
FillTiled = 1
FillStippled = 2
FillOpaqueStippled =3

#  fillRule 

EvenOddRule = 0
WindingRule  =1

#  subwindow mode 

ClipByChildren = 0
IncludeInferiors= 1

#  SetClipRectangles ordering 

Unsorted = 0
YSorted  = 1
YXSorted = 2
YXBanded = 3

#  CoordinateMode for drawing routines 

CoordModeOrigin = 0 # relative to the origin 
CoordModePrevious =   1 # relative to previous point 

#  Polygon shapes 

Complex  = 0 # paths may intersect 
Nonconvex = 1 # no paths intersect, but not convex 
Convex  = 2 # wholly convex 

#  Arc modes for PolyFillArc 

ArcChord = 0 # join endpoints of arc 
ArcPieSlice = 1 # join endpoints to center of arc 

#  GC components: masks used in CreateGC, CopyGC, ChangeGC, OR'ed into
#   GC.stateChanges 

GCFunction   =  (1<<0)
GCPlaneMask   =    (1<<1)
GCForeground  =    (1<<2)
GCBackground  =    (1<<3)
GCLineWidth   =    (1<<4)
GCLineStyle   =    (1<<5)
GCCapStyle    =    (1<<6)
GCJoinStyle  =(1<<7)
GCFillStyle  =(1<<8)
GCFillRule = (1<<9)
GCTile   =(1<<10)
GCStipple  =(1<<11)
GCTileStipXOrigin= (1<<12)
GCTileStipYOrigin =(1<<13)
GCFont   = (1<<14)
GCSubwindowMode = (1<<15)
GCGraphicsExposures = (1<<16)
GCClipXOrigin = (1<<17)
GCClipYOrigin = (1<<18)
GCClipMask = (1<<19)
GCDashOffset = (1<<20)
GCDashList = (1<<21)
GCArcMode = (1<<22)

GCLastBit = 22
# ****************************************************************
# * FONTS
# ****************************************************************

#  used in QueryFont -- draw direction 

FontLeftToRight = 0
FontRightToLeft = 1

FontChange = 255

# ****************************************************************
# *  IMAGING
# ****************************************************************

#  ImageFormat -- PutImage, GetImage 

XYBitmap = 0 # depth 1, XYFormat 
XYPixmap = 1 # depth == drawable depth 
ZPixmap  = 2 # depth == drawable depth 

# ****************************************************************
# *  COLOR MAP STUFF
# ****************************************************************

#  For CreateColormap 

AllocNone = 0 # create map with no entries 
AllocAll = 1 # allocate entire map writeable 


#  Flags used in StoreNamedColor, StoreColors 

DoRed  = (1<<0)
DoGreen  = (1<<1)
DoBlue  = (1<<2)

# ****************************************************************
# * CURSOR STUFF
# ****************************************************************

#  QueryBestSize Class 

CursorShape = 0 # largest size that can be displayed 
TileShape = 1 # size tiled fastest 
StippleShape = 2 # size stippled fastest 

# ****************************************************************
# * KEYBOARD/POINTER STUFF
# ****************************************************************

AutoRepeatModeOff= 0
AutoRepeatModeOn= 1
AutoRepeatModeDefault =2

LedModeOff = 0
LedModeOn = 1

#  masks for ChangeKeyboardControl 

KBKeyClickPercent= (1<<0)
KBBellPercent = (1<<1)
KBBellPitch  = (1<<2)
KBBellDuration = (1<<3)
KBLed  = (1<<4)
KBLedMode = (1<<5)
KBKey  = (1<<6)
KBAutoRepeatMode =(1<<7)

MappingSuccess =  0
MappingBusy    =  1
MappingFailed = 2

MappingModifier  = 0
MappingKeyboard  = 1
MappingPointer  = 2

# ****************************************************************
# * SCREEN SAVER STUFF
# ****************************************************************

DontPreferBlanking= 0
PreferBlanking  = 1
DefaultBlanking  = 2

DisableScreenSaver = 0
DisableScreenInterval = 0

DontAllowExposures = 0
AllowExposures  = 1
DefaultExposures = 2

#  for ForceScreenSaver 

ScreenSaverReset = 0
ScreenSaverActive = 1

# ****************************************************************
# * HOSTS AND CONNECTIONS
# ****************************************************************

#  for ChangeHosts 

HostInsert = 0
HostDelete  = 1

#  for ChangeAccessControl 

EnableAccess = 1
DisableAccess = 0

#  Display classes  used in opening the connection
# * Note that the statically allocated ones are even numbered and the
# * dynamically changeable ones are odd numbered 

StaticGray = 0
GrayScale = 1
StaticColor = 2
PseudoColor = 3
TrueColor = 4
DirectColor = 5


#  Byte order  used in imageByteOrder and bitmapBitOrder 

LSBFirst = 0
MSBFirst = 1
