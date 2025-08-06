# How to use

To try it out use `./run`.
To clean created images use `./clean`.
This repo uses submodules, remember to fetch them.

# Notes
One of the submodules is my fork of nOS-V. This is, of course, temporary.
The images are very bloated and are not for production. One of the final steps will be to use multi stage builds to streamline them and provide both ubuntu and alpine variants.
The whole docker-compose is only a test, there is some sketchy stuff.