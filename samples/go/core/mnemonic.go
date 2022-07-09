package core

// #cgo CFLAGS: -I../../../include
// #cgo LDFLAGS: -L../../../build -L../../../build/trezor-crypto -lTrusTWalletCore -lprotobuf -lTrezorCrypto -lstdc++ -lm
// #include <TrusTWalletCore/TWMnemonic.h>
import "C"

import "TW/types"

func IsMnemonicValid(mn string) bool {
	str := types.TWStringCreateWithGoString(mn)
	defer C.TWStringDelete(str)
	return bool(C.TWMnemonicIsValid(str))
}
