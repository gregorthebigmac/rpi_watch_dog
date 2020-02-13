# rpi_watch_dog

This is a hacky (but *solid*) solution for when you have machine(s) on a UPS but they can't seem to recognize it as a battery, and won't gracefully shutdown when power to the mains goes out, and they're running on battery power.

The rpi in this scenario would NOT be on the UPS, and it's there purely as an easy, networked "canary in the coal mine" for when the power goes out, and the rpi can even be used to wake devices on LAN when the power comes back on. Simply put your machine(s) hostnames and IPs in the config file, and tweak settings to taste, and set it and forget it.
