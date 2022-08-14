#!/bin/bash
make && ./hidden_message -m "This is a test." -w 166 -h 144 > test.ppm && ./image_decoder -p test.ppm