#include <stdio.h>
#include <Windows.h>
#include <winternl.h>

// since we're using the stdcall calling convention, we, as a caller, are responsible for cleaning up the stack
// the compiler will automatically generate the function prologue/epilogue in common function creation cases
_declspec(naked) NTSTATUS _stdcall NtClose(HANDLE hObject)
{
	_asm
	{
		mov eax, 0x3000F // move NtClose ordinal to eax (defined in SSDT)
		call dword ptr fs:[0xC0] // X86SwitchTo64BitMode
		ret 4 // clean up the stack and jump to return address
	}
}

int main()
{
	HANDLE hObject = OpenProcess(PROCESS_VM_READ, false, 10488);

	if (hObject != INVALID_HANDLE_VALUE)
		NtClose(hObject);
	
	return 0;
}
