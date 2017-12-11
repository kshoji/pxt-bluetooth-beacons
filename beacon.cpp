#include "pxt.h"
#include "BluetoothBeaconService.h"
using namespace pxt;
/**
 * A set of functions to advertise beacon with Bluetooth
 */
namespace bluetooth
{
BluetoothBeaconService *pBeaconInstance = nullptr;
BluetoothBeaconService *getBeaconService()
{
    if (pBeaconInstance == nullptr)
    {
        pBeaconInstance = new BluetoothBeaconService(uBit.ble);
    }
    return pBeaconInstance;
}

//%
void advertiseIBeacon(StringData *uuid, uint16_t major, uint16_t minor, int8_t calibratedPower)
{
    ManagedString uuidStr(uuid);
    getBeaconService()->advertiseIBeacon(uuidStr, major, minor, calibratedPower);
}

//%
void advertiseAltBeacon(uint16_t manufacturerId, BufferData *beaconId, int8_t refRSSI, uint8_t reserved)
{
    ManagedBuffer beaconIdBuffer(beaconId);
    getBeaconService()->advertiseAltBeacon(manufacturerId, beaconIdBuffer, refRSSI, reserved);
}
}
