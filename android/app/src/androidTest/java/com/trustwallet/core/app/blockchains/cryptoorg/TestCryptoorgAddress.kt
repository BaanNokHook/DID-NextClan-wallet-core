// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

package com.trusTWallet.core.app.blockchains.cryptoorg

import com.trusTWallet.core.app.utils.toHex
import com.trusTWallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestCryptoorgAddress {

    init {
        System.loadLibrary("TrusTWalletCore")
    }

    @Test
    fun testAddress() {
        val key = PrivateKey("7105512f0c020a1dd759e14b865ec0125f59ac31e34d7a2807a228ed50cb343e".toHexByteArray())
        val pubkey = key.getPublicKeySecp256k1(true)
        val address = AnyAddress(pubkey, CoinType.CRYPTOORG)
        val expected = AnyAddress("cro1z53wwe7md6cewz9sqwqzn0aavpaun0gw39h3rd", CoinType.CRYPTOORG)

        assertEquals(pubkey.data().toHex(), "0x03ed997e396cf4292f5fce5a42bba41599ccd5d96e313154a7c9ea7049de317c77")
        assertEquals(address.description(), expected.description())
    }
}
