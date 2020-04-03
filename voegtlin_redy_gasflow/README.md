# Vögtlin Instruments Red-y gasflow monitoring

## Requirements

 - libmodbus

## Build

For Ubuntu,

```
sudo apt install libmodbus-dev
```

TODO: Create Makefile

Compile,

```
gcc -std=c11 test.c `pkg-config --cflags --libs libmodbus`
```

## Run

TODO: follow symbolic link to avoid long device name

```
./a.out /dev/...
```
