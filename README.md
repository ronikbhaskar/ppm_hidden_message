# PPM Hidden Message

A quick evening project that converts a string into a PPM file. I also added a simple decoder.

The main premise is that whether a pixel has an RGB 255 of (0,0,0) or (1,1,1), it'll look the roughly same to the human eye: black. This way, you can hide messages in seemingly meaningless files.

For an example of how to use it, see `example.sh`.

Of course, this has two main flaws:

1. No one really uses .ppm files anymore, so their very existence will raise suspicion.
2. Once you realize what's going on, the files are not very difficult to decode.

Still, this is more of a proof-of-concept, hiding secret messages in images. This can definitely be developed further with non-black images.
