# README and reminders for portability

## What next - reminder for the Condog

Test it on command line
Add ui
Allow multiple users to join a room
Make it so that you can connect accross network

## Boost installation in current windows env

### Setup CMake in current directory
cmake 'Visual Studio 17 2022' .
(Replace with build system)

### Build once cmake is setup to directory
cmake --build .

Boost is installed to C:/Program Files/boost traditionally, not to the project dir.
To access this location using CMakeLists, you need to use find package() and windows
environment variables.

Useful links in case of forgetting:

Setting environment variables:
https://www.c-sharpcorner.com/article/how-to-addedit-path-environment-variable-in-windows-11/

Find packages using cmake:
https://stackoverflow.com/questions/6646405/how-do-you-add-boost-libraries-in-cmakelists-txt

Boost websocket chat app tutorials:
https://www.geeksforgeeks.org/synchronous-chatting-application-using-c-boostasio/

Advanced Boost usage:
https://www.geeksforgeeks.org/advanced-c-boost-library/


### Thoughts on learning things in the programming space

Learning things through official resources creates a breadcrumb trail of interesting things to follow up on