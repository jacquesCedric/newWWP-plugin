# WUPS plugin template

A simple repo for building WUPS plugins with Docker. Used for traditional WUPS version (circa 2018)


# Usage
Populate the ```libs``` and ```src``` folders with project files, then build with the following, subbing ```{PROJECT_NAME}``` for your project name:

```
# Build docker image
docker build . -t {PROJECT_NAME}

# make 
docker run -it --rm -v ${PWD}:/project {PROJECT_NAME} make
```

Project files can be cleaned up with:

```
# make clean
docker run -it --rm -v ${PWD}:/project {PROJECT_NAME} make clean
```

## Wii U Plugin System?
This is here to simplify building plugins for the [Wii U Plugin System (WUPS)](https://github.com/Maschell/WiiUPluginSystem/). To be able to use this plugin you have to place the resulting `.mod` file into the following folder:

```
sd:/wiiu/plugins
```

When the file is placed on the SDCard you can load it with [plugin loader](https://github.com/Maschell/WiiUPluginSystem/).



