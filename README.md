# QuickHull + Qt

C++ implementation (QuickHull)[https://en.wikipedia.org/wiki/Quickhull] algorithm for finding the convex hull around a set of points in the 2d plane.
There are Boost.Test tests available for the project (requires Boost) and a simple Qt GUI for creating a set of points and finding the hull.

## Build

### Requirements
- A CMakeLists.txt file defines the projects to build, so `cmake` is required in order to build the project. 
- Qt5 is required for the UI - can be installed easily on MacOS with `brew install qt` or through package manager on *Nix
- Boost is required for the Boost.Test unittests, again easily installed with `brew install boost` or through *Nix package manager

### Building

```bash
cmake . # Run from root folder of project to build in the root
# or 
mkdir bin && cd bin && cmake ..  # to build in bin folder
``` 

