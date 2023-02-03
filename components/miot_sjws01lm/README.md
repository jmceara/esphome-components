# Xiaomi Flood Sensor (SJWS01LM)

<img src="miot_sjws01lm.png" alt="SJWS01LM" width="200"/>

> You colud automaticaly get bindkey from Xiaomi Cloud by configuring `xiaomi_account` property in [MIOT](../miot/) platform.

Sample configuration:
```yaml
external_components:
  - source: github://dentra/esphome-components

binary_sensor:
  - platform: miot_sjws01lm
    # String (Required), device MAC-address.
    mac_address: "device-mac-address"
    # String, (Optional), device bind key. Will use "xiaomi_account" from "miot" if absent to automaticaly get the bindkey.
    bindkey: "device-bind-key"
    # String, (Optional), the name of binary sensor
    name: "$name Water Leak"
    # Sensor (Optional), Battey Level, %
    battery_level:
      name: "$name Battery Level"
    # Sensor (Optional), Battey Voltage, V
    battery_voltage:
      name: "$name Battery Voltage"
```

Now signal strength of a BLE device (RSSI) is not a part of this component, but you could easily add it:
```yaml
sensor:
  - platform: ble_rssi
    mac_address: "device-mac-address"
    name: "SJWS01LM RSSI"
```
