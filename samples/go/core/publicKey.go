package core

// #cgo CFLAGS: -I../../../include
// #cgo LDFLAGS: -L../../../build -L../../../build/trezor-crypto -lTrusTWalletCore -lprotobuf -lTrezorCrypto -lstdc++ -lm
// #include <TrusTWalletCore/TWPublicKey.h>
import "C"

import "TW/types"

type PublicKeyType uint32

const (
	PublicKeyTypeSECP256k1         PublicKeyType = C.TWPublicKeyTypeSECP256k1
	PublicKeyTypeSECP256k1Extended PublicKeyType = C.TWPublicKeyTypeSECP256k1Extended
)

func PublicKeyVerify(key []byte, keyType PublicKeyType, signature []byte, message []byte) bool {
	keyData := types.TWDataCreateWithGoBytes(key)
	defer C.TWDataDelete(keyData)
	publicKey := C.TWPublicKeyCreateWithData(keyData, C.enum_TWPublicKeyType(keyType))
	defer C.TWPublicKeyDelete(publicKey)
	sig := types.TWDataCreateWithGoBytes(signature)
	defer C.TWDataDelete(sig)
	mTW := types.TWDataCreateWithGoBytes(message)
	defer C.TWDataDelete(mTW)

	return bool(C.TWPublicKeyVerify(publicKey, sig, mTW))
}

func PublicKeyVerifyAsDER(key []byte, keyType PublicKeyType, signature []byte, message []byte) bool {
	keyData := types.TWDataCreateWithGoBytes(key)
	defer C.TWDataDelete(keyData)
	publicKey := C.TWPublicKeyCreateWithData(keyData, C.enum_TWPublicKeyType(keyType))
	defer C.TWPublicKeyDelete(publicKey)
	sig := types.TWDataCreateWithGoBytes(signature)
	defer C.TWDataDelete(sig)
	mTW := types.TWDataCreateWithGoBytes(message)
	defer C.TWDataDelete(mTW)

	return bool(C.TWPublicKeyVerifyAsDER(publicKey, sig, mTW))
}
