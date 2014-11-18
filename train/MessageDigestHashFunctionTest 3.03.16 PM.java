

package com.google.common.hash;

import com.google.common.base.Charsets;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;

import junit.framework.TestCase;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;


public class MessageDigestHashFunctionTest extends TestCase {
  private static final ImmutableSet<String> INPUTS = ImmutableSet.of("", "Z", "foobar");


  private static final ImmutableMap<String, HashFunction> ALGORITHMS =
      new ImmutableMap.Builder<String, HashFunction>()
          .put("MD5", Hashing.md5())
          .put("SHA", Hashing.sha1())
          .put("SHA1", Hashing.sha1())
          .put("sHa-1", Hashing.sha1())
          .put("SHA-1", Hashing.sha1())
          .put("SHA-256", Hashing.sha256())
          .put("SHA-512", Hashing.sha512())
          .build();

  public void testHashing() {
    for (String stringToTest : INPUTS) {
      for (String algorithmToTest : ALGORITHMS.keySet()) {
        assertMessageDigestHashing(HashTestUtils.ascii(stringToTest), algorithmToTest);
      }
    }
  }

  public void testPutAfterHash() {
    Hasher sha1 = Hashing.sha1().newHasher();

    assertEquals("2fd4e1c67a2d28fced849ee1bb76e7391b93eb12",
        sha1.putString("The quick brown fox jumps over the lazy dog", Charsets.UTF_8)
            .hash()
            .toString());
    try {
      sha1.putInt(42);
      fail();
    } catch (IllegalStateException expected) {
    }
  }

  public void testHashTwice() {
    Hasher sha1 = Hashing.sha1().newHasher();

    assertEquals("2fd4e1c67a2d28fced849ee1bb76e7391b93eb12",
        sha1.putString("The quick brown fox jumps over the lazy dog", Charsets.UTF_8)
            .hash()
            .toString());
    try {
      sha1.hash();
      fail();
    } catch (IllegalStateException expected) {
    }
  }

  public void testToString() {
    assertEquals("Hashing.md5()", Hashing.md5().toString());
    assertEquals("Hashing.sha1()", Hashing.sha1().toString());
    assertEquals("Hashing.sha256()", Hashing.sha256().toString());
    assertEquals("Hashing.sha512()", Hashing.sha512().toString());
  }

  private static void assertMessageDigestHashing(byte[] input, String algorithmName) {
    try {
      MessageDigest digest = MessageDigest.getInstance(algorithmName);
      assertEquals(
          HashCode.fromBytes(digest.digest(input)),
          ALGORITHMS.get(algorithmName).hashBytes(input));
      for (int bytes = 4; bytes <= digest.getDigestLength(); bytes++) {
        assertEquals(
            HashCode.fromBytes(Arrays.copyOf(digest.digest(input), bytes)),
            new MessageDigestHashFunction(algorithmName, bytes, algorithmName).hashBytes(input));
      }
      try {
        int maxSize = digest.getDigestLength();
        new MessageDigestHashFunction(algorithmName, maxSize + 1, algorithmName);
        fail();
      } catch (IllegalArgumentException expected) {
      }
    } catch (NoSuchAlgorithmException nsae) {
      throw new AssertionError(nsae);
    }
  }
}
