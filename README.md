# bluetooth-beacons

This PXT package allows the micro:bit to act as iBeacon / AltBeacon advertiser.

## Usage

On MakeCode workspace, open the menu item `Add Package...`, and specify the package id `github:kshoji/pxt-bluetooth-beacons`.

### iBeacon
To advertise BLE iBeacon packets, write code like this.

```blocks
bluetooth.advertiseIBeacon("E20A39F4-73F5-4BC4-A12F-17D1AD07A961", 1, 2, -56);
```

Arguments: `uuid`, `majorId`, `minorId`, and `txPower`. 

* The `uuid` argument is string style, and it can omit the hyphens.
* The `majorId` `minorId` arguments are numbers from 0 to 65535.
* The `txPower` argument is a number (dBm) from -128 to 127.

### AltBeacon
To advertise BLE AltBeacon packets, write code like this.

```blocks
let beaconId = pins.createBuffer(20)
beaconId.setNumber(NumberFormat.Int32BE, 0, 0x01020304)
beaconId.setNumber(NumberFormat.Int32BE, 4, 0x05060708)
beaconId.setNumber(NumberFormat.Int32BE, 8, 0x090A0B0C)
beaconId.setNumber(NumberFormat.Int32BE, 12, 0x0D0E0F10)
beaconId.setNumber(NumberFormat.Int32BE, 16, 0x11121314)

bluetooth.advertiseAltBeacon(0x0059, beaconId, -56)
```

Arguments: `manufacturerId`, `beaconId`, and `txPower`. 

* The `manufacturerId` argument is a number from 0 to 65535.
* The `beaconId` argument is a buffer with 20 bytes.
* The `txPower` argument is a number (dBm) from 0 to -127.

## Supported targets

* for PXT/microbit

(The metadata above is needed for package search.)

## License

Source code:
[MIT](https://github.com/kshoji/pxt-bluetooth-beacons/blob/master/LICENSE)


icon.png:
Culmstock: Culmstock Beacon
[cc-by-sa/2.0](http://creativecommons.org/licenses/by-sa/2.0/) - © [Martin Bodman](https://www.geograph.org.uk/profile/1578) - [geograph.org.uk/p/213525](https://www.geograph.org.uk/photo/213525)


```package
bluetooth
bluetooth-beacons=github:kshoji/pxt-bluetooth-beacons
```
