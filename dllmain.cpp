void SwapOBSPresent() {
	uintptr_t OBS = reinterpret_cast<uintptr_t>((HMODULE)get_base_address(_(L"graphics-hook64.dll"))); //get the base address

	present_original = *reinterpret_cast<present_fn*>(OBS + 0x354B0); //for obs 25.0.8 only
	*reinterpret_cast<present_fn*>(OBS + 0x354B0) = present_hooked; //present 
}

bool DllMain(HMODULE Module, DWORD  reason_for_call, LPVOID lpReserved)
{
	if (reason_for_call == 1)
	{
		//entry
		SwapOBSPresent(); 
	}

	return 1;
}