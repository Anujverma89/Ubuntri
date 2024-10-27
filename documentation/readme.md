* comilation command for c 
gcc `pkg-config --cflags gtk4` hello.c -o hello `pkg-config --libs gtk4`

* compiliation command for cpp
g++ `pkg-config --cflags gtk4` hello.c -o hello `pkg-config --libs gtk4`
