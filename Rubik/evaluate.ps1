Set-ExecutionPolicy RemoteSigned
g++ .\Rubik.cpp
Measure-Command {cat .\1.in | .\a.exe > out.out }