// PiUsb.h   Function definitions
// Revised 5/18/2010
// Revised 5/30/2010  Larry Fisher

#define PI_NO_ERROR 0
#define PI_DEVICE_NOT_FOUND 1
#define PI_OBJECT_NOT_FOUND 2
#define PI_CANNOT_CREATE_OBJECT 3

#define PI_SHUTTER_OPEN 1
#define PI_SHUTTER_CLOSED 0

#define PI_FLIPPER_EXTENDED 1
#define PI_FLIPPER_RETRACTED 0



// Shutter Functions
void * __stdcall piConnectShutter(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectShutter(void * devicePtr);
int __stdcall piSetShutterState(int ShutterState, void * devicePtr);  // Return Error Number
int __stdcall piGetShutterState(int * CurrentShutterState, void * devicePtr); // Return Error Number

// Flipper Functions
void * __stdcall piConnectFlipper(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectFlipper(void * devicePtr);
int __stdcall piSetFlipperState(int FlipperStatevoid, void * devicePtr); // Return Error Number
int __stdcall piGetFlipperState(int *CurrentFlipperState, void * devicePtr); // Return Error Number

// USB Motor Functions
// All returned int values are the ErrorNumber
void * __stdcall piConnectMotor(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectMotor(void * devicePtr);
int __stdcall piHomeMotor(int Velocity, void * devicePtr);
int __stdcall piSetMotorVelocity(int Velocity, void * devicePtr);
int __stdcall piHaltMotor(void * devicePtr);
int __stdcall piRunMotorToPosition( int Position, int Velocity, void * devicePtr);
int __stdcall piGetMotorHomeStatus(BOOL * AtHome, void * devicePtr);
int __stdcall piGetMotorMovingStatus(BOOL * Moving, void * devicePtr);
int __stdcall piGetMotorVelocity(int * ReportedVelocity, void * devicePtr);
int __stdcall piGetMotorPosition(int * ReportedPosition, void * devicePtr);

// USB Twister Functions
// All returned int values are the ErrorNumber
void * __stdcall piConnectTwister(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectTwister(void * devicePtr);
int __stdcall piSetTwisterPositionZero(void * devicePtr);
int __stdcall piRunTwisterToPosition( int Position, int Velocity, void * devicePtr);
int __stdcall piRunTwisterContinuous( int Direction, int Velocity, void * devicePtr);
int __stdcall piHaltTwister(void * devicePtr);
int __stdcall piGetTwisterMovingStatus(BOOL * Moving, void * devicePtr);
int __stdcall piGetTwisterPosition(int * ReportedPosition, void * devicePtr);
int __stdcall piGetTwisterVelocity(int * ReportedVelocity, void * devicePtr);

// Filter Wheel Functions
// All returned int values are the ErrorNumber
void * __stdcall piConnectFilter(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectFilter(void * devicePtr);
int __stdcall piSetFilterPosition(int Position, void * devicePtr);
int __stdcall piGetFilterPosition(int * ReportedPosition, void * devicePtr);

// Gradient Wheel Functions
// All returned int values are the ErrorNumber
void * __stdcall piConnectGWheel(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectGWheel(void * devicePtr);
int __stdcall piSetGWheelPostion(int Position, void * devicePtr);
int __stdcall piGetGWheelPosition(int * ReportedPosition, void * devicePtr);
int __stdcall piJogGWheel(BOOL * Direction, void * devicePtr);

// Relay Functions
// All returned int values are the ErrorNumber
void * __stdcall piConnectRelay(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectRelay(void * devicePtr);
int __stdcall piSetRelayStates(int RelayStates, void * devicePtr);  // Bit 0 = relay 1, Bit 1 = relay 2...etc.
int __stdcall piGetRelayStates(int * ReportedStates, void * devicePtr);

// Laser Functions
// All returned int values are the ErrorNumber
void * __stdcall piConnectLaser(int * ErrorNumber, int SerialNum); // Return Device pointer
void __stdcall piDisconnectLaser(void * devicePtr);
int __stdcall piSetLaserStates(int LaserStates, void * devicePtr);  // Bit 3 controls laser
int __stdcall piGetLaserStates(int * ReportedStates, void * devicePtr);
