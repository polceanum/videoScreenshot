# videoScreenshot
Tool to save screenshot from video with frame number. Output will be saved as PNG under "screenshots" folder.

# compilation
```bash
git clone https://github.com/polceanum/videoScreenshot.git
cd videoScreenshot
mkdir build
cd build
cmake ..
make
```

# running
```bash
./videoScreenshot /path/to/video.avi
```

# commands

p == pause video

0 == advance 1 frame (10^0)

1 == advance 10 frames (10^1)

2 == advance 100 frames (10^2)

3 == advance 1000 frames (10^3)

s == save screenshot

q == quit
