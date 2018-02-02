# direct-syscall
A simple example on how to initiate a direct syscall on WoW64.

Note that function stubs can be different, depending on your current OS version.
This example shows how to close a handle to an object by using NtClose. 
We're processing a devirtualization in this case (since we're calling wow64cpu.dll!X86SwitchTo64BitMode) before going into the actual syscall execution. This is a simple way to evade usermode hooks (except hooks registered on Wow32Reserved). The syscall ordinal also changes depending on your OS version.

A better way would be to devirtualize the execution in your x86-environment directly to execute x64 syscalls from WoW64 (also known as "Heavens Gate". 

Important: This will not work on 32 Bit Windows versions, since clean x86 environments initiate the SYSENTER instruction to invoke an interrupt between usermode -> kernelmode.


