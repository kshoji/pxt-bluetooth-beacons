/** 
 * A class to advertise BLE Beacons
 */
#include "MicroBit.h"
#include "pxt.h"
#include "ble/GapAdvertisingData.h"
#include "BluetoothBeaconService.h"

namespace
{
const uint8_t IBEACON_PAYLOAD[] = {
    0x4C, 0x00,                                     // Vendor ID
    0x02,                                           // Packet Type
    0x15,                                           // Length
    0xE2, 0x0A, 0x39, 0xF4, 0x73, 0xF5, 0x4B, 0xC4, // UUID (changeable)
    0xA1, 0x2F, 0x17, 0xD1, 0xAD, 0x07, 0xA9, 0x61, // UUID (changeable)
    0x00, 0x00,                                     // Major (changeable)
    0x00, 0x00,                                     // Minor (changeable)
    0xC8,                                           // Measured Power (changeable)
};                                                  // Length 25

const uint8_t ALTBEACON_PAYLOAD[] = {
    0x00, 0x00,                                                 // manufacturer ID (changeable)
    0xBE, 0xAC,                                                 // beacon Code
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // beacon ID (changeable)
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // beacon ID (changeable)
    0x00,                                                       // reference RSSI (changeable)
    0x00,                                                       // Reserved (changeable)
};                                                              // Length 26
}

/**
 * Constructor
 * @param dev BLE device
 */
BluetoothBeaconService::BluetoothBeaconService(BLEDevice *dev) : ble(*dev)
{
}

void BluetoothBeaconService::advertiseIBeacon(ManagedString uuid, uint16_t major, uint16_t minor, int8_t calibratedPower)
{
    uint8_t iBeaconPayload[25];
    memcpy(iBeaconPayload, IBEACON_PAYLOAD, 25);
    UUID uuidData = UUID(uuid.toCharArray());
    if (uuidData.getLen() == 16)
    {
        memcpy(&iBeaconPayload[4], uuidData.getBaseUUID(), 16);
        iBeaconPayload[20] = (major >> 8) & 0xff;
        iBeaconPayload[21] = major & 0xff;
        iBeaconPayload[22] = (minor >> 8) & 0xff;
        iBeaconPayload[23] = minor & 0xff;
        iBeaconPayload[24] = calibratedPower;

        advertiseRawData(iBeaconPayload, 25);
    }
}

void BluetoothBeaconService::advertiseAltBeacon(uint16_t manufacturerId, ManagedBuffer beaconId, int8_t refRSSI, uint8_t reserved)
{
    if (beaconId.length() == 20)
    {
        if (refRSSI > 0)
        {
            refRSSI = 0;
        }

        uint8_t altBeaconPayload[26];
        memcpy(altBeaconPayload, ALTBEACON_PAYLOAD, 26);
        altBeaconPayload[0] = manufacturerId & 0xff;
        altBeaconPayload[1] = (manufacturerId >> 8) & 0xff;

        memcpy(&altBeaconPayload[4], beaconId.getBytes(), 20);

        altBeaconPayload[24] = refRSSI;
        altBeaconPayload[25] = reserved;
        advertiseRawData(altBeaconPayload, 26);
    }
}

void BluetoothBeaconService::advertiseRawData(const uint8_t *data, uint8_t len)
{
    ble.gap().stopAdvertising();
    ble.gap().clearAdvertisingPayload();

    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED |
                                           GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::MANUFACTURER_SPECIFIC_DATA, data, len);

    ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_NON_CONNECTABLE_UNDIRECTED);
    ble.gap().setAdvertisingInterval(1000); // 1000 milli seconds
    ble.gap().startAdvertising();
}
