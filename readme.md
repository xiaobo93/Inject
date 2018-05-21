
readme.md

BlackHack  2017最新创建傀儡进程的手法。

原理使用的是：windows NTFS机制。

在实际应用中，我们想制定父进程，进行伪装。将NtCreateProcessEx函数的第四个参数，指向我们制定的进程的句柄。

原文档引用：

# Inject-dll-by-Process-Doppelganging
Process Doppelgänging

### SRC：

https://www.blackhat.com/docs/eu-17/materials/eu-17-Liberman-Lost-In-Transaction-Process-Doppelganging.pdf

### Credits:
	Vyacheslav Rusakov @swwwolf
	Tom Bonner @thomas_bonner
	
### Source Code：

https://gist.github.com/hfiref0x/a9911a0b70b473281c9da5daea9a177f

### Modified part：

- Add a header file(ntos.h) in my way.
- Some changes to the c file.
- Build by Visual Studio 2012.
- Support Windows x86.