nanopb-arduino
==============

A simple [PlatformIO](https://platformio.org/) library for wrapping Arduino's [`Stream`](https://www.arduino.cc/en/Reference/Stream) and `Print` objects into [Nanopb](https://koti.kapsi.fi/jpa/nanopb/)'s `pb_istream_s` and `pb_ostream_s`.

Exposes two functions that do exactly what you'd expect:

* `pb_istream_s as_pb_istream(Stream& p)`
* `pb_ostream_s as_pb_ostream(Print& p)`

In most cases, all you'll need is:

```c++
#include <pb_arduino.h>

pb_istream_s pb_in = as_pb_istream(Serial);
pb_ostream_s pb_out = as_pb_ostream(Serial);
```

and then use `pb_encode(&pb_out, ...)` and `pb_decode(&pb_in)`.

This isn't restricted to [`Serial`](https://www.arduino.cc/en/reference/serial), and will work for any object that implements
`Stream`, such as `File` (returned from [`SD.open`](https://www.arduino.cc/en/Reference/SDopen) and the ethernet [`Client`](https://www.arduino.cc/en/Reference/ClientConstructor).

---

This can be used on top of [PacketIO](https://github.com/eric-wieser/packet-io), with

```c++
#include <pb_arduino.h>
#include <cobs/Stream.h>
#include <cobs/Print.h>

COBSStream cobs_in(Serial);
pb_istream_s pb_in = as_pb_istream(cobs_in);

COBSPrint cobs_out(Serial);
pb_ostream_s pb_out = as_pb_ostream(cobs_out);
```

and then calling `cobs_out.end()` after each `pb_encode`, and `cobs_in.next()` after each `pb_decode`.
