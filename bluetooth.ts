namespace bluetooth {
    /**
     * Advertise iBeacon
     */
    //% blockId="bluetooth_advertise_ibeacon"
    //% block="beacons|advertise iBeacon with uuid %uuid|, major %major|, minor %minor| and calibratedPower %calibratedPower"
    //% parts="bluetooth"
    //% shim=bluetooth::advertiseIBeacon
    export function advertiseIBeacon(uuid: string, major: number, minor: number, calibratedPower: number) {
        return;
    }

    /**
     * Advertise AltBeacon
     */
    //% blockId="bluetooth_advertise_altbeacon"
    //% block="beacons|advertise AltBeacon with manufacturerId %manufacturerId|, beaconId %beaconId|, refRSSI %refRSSI|, and reserved %reserved"
    //% parts="bluetooth"
    //% shim=bluetooth::advertiseAltBeacon
    export function advertiseAltBeacon(manufacturerId: number, beaconId: Buffer, refRSSI: number, reserved: number) {
        return;
    }
}
