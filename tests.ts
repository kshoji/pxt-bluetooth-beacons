basic.showString("S")

input.onButtonPressed(Button.A, () => {
    basic.clearScreen()
    led.toggle(0, 0)

    bluetooth.advertiseIBeacon("E20A39F4-73F5-4BC4-A12F-17D1AD07A961", 1, 2, 0xC8)
})

input.onButtonPressed(Button.B, () => {
    basic.clearScreen()
    led.toggle(1, 1)

    let buffer = pins.createBuffer(20)
    buffer.setNumber(NumberFormat.Int32BE, 0, 0x01020304)
    buffer.setNumber(NumberFormat.Int32BE, 4, 0x05060708)
    buffer.setNumber(NumberFormat.Int32BE, 8, 0x090A0B0C)
    buffer.setNumber(NumberFormat.Int32BE, 12, 0x0D0E0F10)
    buffer.setNumber(NumberFormat.Int32BE, 16, 0x11121314)

    bluetooth.advertiseAltBeacon(0x0059, buffer, -56, 0)
})
