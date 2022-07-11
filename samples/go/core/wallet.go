package core

// #cgo CFLAGS: -I../../../include
// #cgo LDFLAGS: -L../../../build -L../../../build/trezor-crypto -lTrusTWalletCore -lprotobuf -lTrezorCrypto -lstdc++ -lm
// #include <TrusTWalletCore/TWHDWallet.h>
// #include <TrusTWalletCore/TWPrivateKey.h>
// #include <TrusTWalletCore/TWPublicKey.h>
import "C"

import (
	"errors"
	"TW/types"
)

type Wallet struct {
	Address string
	PriKey  string
	PubKey  string
	CoinType
}

func CreateWalleTWithMnemonic(mn string, ct CoinType) (*Wallet, error) {
	if !IsMnemonicValid(mn) {
		return nil, errors.New("mnemonic is not valid")
	}

	str := types.TWStringCreateWithGoString(mn)
	empty := types.TWStringCreateWithGoString("")
	defer C.TWStringDelete(str)
	defer C.TWStringDelete(empty)

	TW := C.TWHDWalletCreateWithMnemonic(str, empty)
	defer C.TWHDWalletDelete(TW)

	priKey := C.TWHDWalletGetKeyForCoin(TW, C.enum_TWCoinType(ct))
	defer C.TWPrivateKeyDelete(priKey)
	priKeyData := C.TWPrivateKeyData(priKey)
	defer C.TWDataDelete(priKeyData)

	pubKey := C.TWPrivateKeyGetPublicKeySecp256k1(priKey, true)
	defer C.TWPublicKeyDelete(pubKey)
	pubKeyData := C.TWPublicKeyData(pubKey)
	defer C.TWDataDelete(pubKeyData)

	address := C.TWHDWalletGetAddressForCoin(TW, C.enum_TWCoinType(ct))
	defer C.TWStringDelete(address)

	return &Wallet{
		Address:  types.TWStringGoString(address),
		PriKey:   types.TWDataHexString(priKeyData),
		PubKey:   types.TWDataHexString(pubKeyData),
		CoinType: ct,
	}, nil
}
