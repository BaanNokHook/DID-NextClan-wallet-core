package core

// #cgo CFLAGS: -I../../../include
// #cgo LDFLAGS: -L../../../build -L../../../build/trezor-crypto -lTrusTWalletCore -lprotobuf -lTrezorCrypto -lstdc++ -lm
// #include <TrusTWalletCore/TWCoinType.h>
// #include <TrusTWalletCore/TWCoinTypeConfiguration.h>
import "C"

import "TW/types"

type CoinType uint32

const (
	CoinTypeBitcoin  CoinType = C.TWCoinTypeBitcoin
	CoinTypeBinance  CoinType = C.TWCoinTypeBinance
	CoinTypeEthereum CoinType = C.TWCoinTypeEthereum
	CoinTypeTron     CoinType = C.TWCoinTypeTron
)

func (c CoinType) GetName() string {
	name := C.TWCoinTypeConfigurationGetName(C.enum_TWCoinType(c))
	defer C.TWStringDelete(name)
	return types.TWStringGoString(name)
}

func (c CoinType) Decimals() int {
	return int(C.TWCoinTypeConfigurationGetDecimals(C.enum_TWCoinType(c)))
}
