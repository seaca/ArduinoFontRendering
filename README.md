Tiny font rendering engine on Arduino


- interface
(char code, font size)     (image data)
         |                    ^
         |          I2C       |
         |                    |
         v                    |
      +---------------------------+
      |    Arduino                |
      +---------------------------+
            |   ^
            |   |  SPI
            v   |
         +--------------------+
         | font ROM (SD Mem)  |
         +--------------------+
         
         
- input format
(not defined)

-output format
  64 x 64 pixel data.
  Each pixel is a byte, if 0 then black and otherwise white.
