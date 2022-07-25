Simple toolchain for DSC 56800 controllers using docker and cmake
=================================================================

- Florian Dupeyron
- July 2022

This project gives an image construction scheme for DSC 56800 architectures, as well as
an example project using this toolchain under CMake.


Image building
--------------

1. Go to NXP's website and download the last update zip **(link TODO)**
2. Place the downloaded zip in the `data` folder
3. Generate the image
```bash
> cd docker
> docker build -t buildenv:dsp56800 .
```


Project building
----------------

1. Download the MCUXpresso SDK for your target on NXP's website **(link TODO)**, and extract it to the `SDK` folder of this repo
2. Call the `build.sh` script at the root of this repo

