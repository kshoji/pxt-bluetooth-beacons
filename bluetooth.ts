namespace bluetooth {
    /**
     * Advertise iBeacon
     * @param uuid string style, and it can omit the hyphens.
     * @param major [0-65535] eg: 0
     * @param minor [0-65535] eg: 0
     * @param calibratedPower [-128-127] RSSI dBm at 1m eg: -56
     */
    //% blockId="bluetooth_advertise_ibeacon"
    //% block="iBeacon|advertise iBeacon with UUID %uuid|, Major %major|, Minor %minor| and RSSI at 1m %calibratedPower"
    //% parts="bluetooth"
    //% shim=bluetooth::advertiseIBeacon
    export function advertiseIBeacon(uuid: string, major: number, minor: number, calibratedPower: number) {
        return;
    }

    /**
     * Advertise AltBeacon
     * @param manufacturerId [0-65535] see also Bluetooth SIG's Company Identifiers list. eg: 89
     * @param beaconId Buffer, create with `pins.createBuffer(20)`
     * @param refRSSI [-127-0] RSSI dBm at 1m eg: -56
     * @param reserved [0-255] Manufacturer specific data. eg: 0
     */
    //% blockId="bluetooth_advertise_altbeacon"
    //% block="AltBeacon|advertise AltBeacon with Manufacturer ID %manufacturerId|, Beacon ID %beaconId|, RSSI at 1m %refRSSI|, and Reserved %reserved"
    //% parts="bluetooth"
    //% shim=bluetooth::advertiseAltBeacon
    export function advertiseAltBeacon(manufacturerId: number, beaconId: Buffer, refRSSI: number, reserved: number) {
        return;
    }
}
