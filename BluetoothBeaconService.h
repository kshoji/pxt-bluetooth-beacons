#ifndef __BLEBEACON_H__
#define __BLEBEACON_H__

#include "ble/BLE.h"

/** 
 * A class to advertise BLE Beacons
 */
class BluetoothBeaconService
{
  public:
    /**
     * Constructor
     * @param dev BLE device
     */
    BluetoothBeaconService(BLEDevice *device);

    /**
     * Advertise as iBeacon
     * 
     * @param uuid UUID format string. like 'xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx'
     * @param major major ID
     * @param minor minor ID
     * @param calibratedPower 2’s complement of measured TX power
     */
    void advertiseIBeacon(ManagedString uuid, uint16_t major, uint16_t minor, int8_t calibratedPower);

    /**
     * Advertise as AltBeacon
     * 
     * @param manufacturerId mfg ID
     * @param beaconId 20 bytes
     * @param refRSSI reference RSSI from 0 to -127
     */
    void advertiseAltBeacon(uint16_t manufacturerId, ManagedBuffer beaconId, int8_t refRSSI, uint8_t reserved);

  private:
    BLEDevice &ble;

    void advertiseRawData(const uint8_t *data, uint8_t len);
};

#endif /* __BLEBEACON_H__ */
