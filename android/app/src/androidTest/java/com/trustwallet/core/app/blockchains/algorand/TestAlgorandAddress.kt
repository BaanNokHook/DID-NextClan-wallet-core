package com.trusTWallet.core.app.blockchains.algorand

import com.trusTWallet.core.app.utils.toHex
import com.trusTWallet.core.app.utils.toHexByteArray
import org.junit.Assert.assertEquals
import org.junit.Test
import wallet.core.jni.*

class TestAlgorandAddress {

    init {
        System.loadLibrary("TrusTWalletCore")
    }

    @Test
    fun testAddress() {
        val key = PrivateKey("a6c4394041e64fe93d889386d7922af1b9a87f12e433762759608e61434d6cf7".toHexByteArray())
        val pubkey = key.publicKeyEd25519
        val address = AnyAddress(pubkey, CoinType.ALGORAND)
        val expected = AnyAddress("ADIYK65L3XR5ODNNCUIQVEET455L56MRKJHRBX5GU4TZI2752QIWK4UL5A", CoinType.ALGORAND)

        assertEquals(pubkey.data().toHex(), "0x00d1857babdde3d70dad15110a9093e77abef991524f10dfa6a727946bfdd411")
        assertEquals(address.description(), expected.description())
    }
}
