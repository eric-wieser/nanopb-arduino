#include "pb_encode.h"
#include "pb_decode.h"

class Print;
class Stream;

//! Convert an object implementing Print into a nanopb ostream
pb_ostream_s as_pb_ostream(Print& p);

//! Convert an object implementing Print into a nanopb istream
pb_istream_s as_pb_istream(Stream& p);
