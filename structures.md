# File Structures

Warning: These can change!

### Ronapp (RAPP)
```C
struct RAPP {
    char Magic[0x4]; // RAPP
    uint16_t IconSize; 
    char Title[0x10]; // App title.
    char Icon[0x400]; // Preview. Can be dropped if we need more space for the executable. 
    REXE *Game;
}
```

### Ronexecutable (REXE)
```C
struct REXE {
    char Magic[0x4]; // REXE
    char *Instructions; // Cannot execeed the Nano 33 BLE integer count of 65535.
}
```