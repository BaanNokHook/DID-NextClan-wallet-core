// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.trusTWallet.core.app.blockchains.Polkadot

import com.trusTWallet.core.app.utils.toHex
import com.trusTWallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestPolkadotAddress {

    init {
        System.loadLibrary("TrusTWalletCore")
    }

    @Test
    fun testAddress() {

        val key = PrivateKey("0xd65ed4c1a742699b2e20c0c1f1fe780878b1b9f7d387f934fe0a7dc36f1f9008".toHexByteArray())
        val pubkey = key.publicKeyEd25519
        val address = AnyAddress(pubkey, CoinType.POLKADOT)
        val expected = AnyAddress("12TWBQPiG5yVSf3jQSBkTAKBKqCShQ5fm33KQhH3Hf6VDoKW", CoinType.POLKADOT)

        assertEquals(pubkey.data().toHex(), "0x53d82211c4aadb8c67e1930caef2058a93bc29d7af86bf587fba4aa3b1515037")
        assertEquals(address.description(), expected.description())
    }
}
