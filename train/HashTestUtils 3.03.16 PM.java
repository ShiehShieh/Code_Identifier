

package com.google.common.hash;

import static org.junit.Assert.assertEquals;

import com.google.common.base.Charsets;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.Sets;
import com.google.common.primitives.Ints;
import com.google.common.testing.EqualsTester;

import org.junit.Assert;

import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.Random;
import java.util.Set;


final class HashTestUtils {
  private HashTestUtils() {}


  static byte[] ascii(String string) {
    byte[] bytes = new byte[string.length()];
    for (int i = 0; i < string.length(); i++) {
      bytes[i] = (byte) string.charAt(i);
    }
    return bytes;
  }

  interface HashFn {
    byte[] hash(byte[] input, int seed);
  }

  static void verifyHashFunction(HashFn hashFunction, int hashbits, int expected) {
    int hashBytes = hashbits / 8;

    byte[] key = new byte[256];
    byte[] hashes = new byte[hashBytes * 256];

    for (int i = 0; i < 256; i++) {
      key[i] = (byte) i;
      int seed = 256 - i;
      byte[] hash = hashFunction.hash(Arrays.copyOf(key, i), seed);
      System.arraycopy(hash, 0, hashes, i * hashBytes, hash.length);
    }

    byte[] result = hashFunction.hash(hashes, 0);

    int verification = Integer.reverseBytes(Ints.fromByteArray(result));

    if (expected != verification) {
      throw new AssertionError("Expected: " + Integer.toHexString(expected)
          + " got: " + Integer.toHexString(verification));
    }
  }

  static final Funnel<Object> BAD_FUNNEL = new Funnel<Object>() {
    @Override public void funnel(Object object, PrimitiveSink bytePrimitiveSink) {
      bytePrimitiveSink.putInt(object.hashCode());
    }
  };

  static enum RandomHasherAction {
    PUT_BOOLEAN() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        boolean value = random.nextBoolean();
        for (PrimitiveSink sink : sinks) {
          sink.putBoolean(value);
        }
      }
    },
    PUT_BYTE() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        int value = random.nextInt();
        for (PrimitiveSink sink : sinks) {
          sink.putByte((byte) value);
        }
      }
    },
    PUT_SHORT() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        short value = (short) random.nextInt();
        for (PrimitiveSink sink : sinks) {
          sink.putShort(value);
        }
      }
    },
    PUT_CHAR() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        char value = (char) random.nextInt();
        for (PrimitiveSink sink : sinks) {
          sink.putChar(value);
        }
      }
    },
    PUT_INT() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        int value = random.nextInt();
        for (PrimitiveSink sink : sinks) {
          sink.putInt(value);
        }
      }
    },
    PUT_LONG() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        long value = random.nextLong();
        for (PrimitiveSink sink : sinks) {
          sink.putLong(value);
        }
      }
    },
    PUT_FLOAT() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        float value = random.nextFloat();
        for (PrimitiveSink sink : sinks) {
          sink.putFloat(value);
        }
      }
    },
    PUT_DOUBLE() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        double value = random.nextDouble();
        for (PrimitiveSink sink : sinks) {
          sink.putDouble(value);
        }
      }
    },
    PUT_BYTES() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        byte[] value = new byte[random.nextInt(128)];
        random.nextBytes(value);
        for (PrimitiveSink sink : sinks) {
          sink.putBytes(value);
        }
      }
    },
    PUT_BYTES_INT_INT() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        byte[] value = new byte[random.nextInt(128)];
        random.nextBytes(value);
        int off = random.nextInt(value.length + 1);
        int len = random.nextInt(value.length - off + 1);
        for (PrimitiveSink sink : sinks) {
          sink.putBytes(value);
        }
      }
    },
    PUT_STRING() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        char[] value = new char[random.nextInt(128)];
        for (int i = 0; i < value.length; i++) {
          value[i] = (char) random.nextInt();
        }
        String s = new String(value);
        for (PrimitiveSink sink : sinks) {
          sink.putUnencodedChars(s);
        }
      }
    },
    PUT_STRING_LOW_SURROGATE() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        String s = new String(new char[] { randomLowSurrogate(random) });
        for (PrimitiveSink sink : sinks) {
          sink.putUnencodedChars(s);
        }
      }
    },
    PUT_STRING_HIGH_SURROGATE() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        String s = new String(new char[] { randomHighSurrogate(random) });
        for (PrimitiveSink sink : sinks) {
          sink.putUnencodedChars(s);
        }
      }
    },
    PUT_STRING_LOW_HIGH_SURROGATE() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        String s = new String(new char[] {
            randomLowSurrogate(random), randomHighSurrogate(random)});
        for (PrimitiveSink sink : sinks) {
          sink.putUnencodedChars(s);
        }
      }
    },
    PUT_STRING_HIGH_LOW_SURROGATE() {
      @Override void performAction(Random random, Iterable<? extends PrimitiveSink> sinks) {
        String s = new String(new char[] {
            randomHighSurrogate(random), randomLowSurrogate(random)});
        for (PrimitiveSink sink : sinks) {
          sink.putUnencodedChars(s);
        }
      }
    };

    abstract void performAction(Random random, Iterable<? extends PrimitiveSink> sinks);

    private static final RandomHasherAction[] actions = values();

    static RandomHasherAction pickAtRandom(Random random) {
      return actions[random.nextInt(actions.length)];
    }
  }
  

  static void checkNoFunnels(HashFunction function) {
    Random rand = new Random(0);
    int keyBits = 32;
    int hashBits = function.bits();

    for (int i = 0; i < keyBits; i++) {
      int same = 0x0;
      int diff = 0x0;
      int count = 0;
      int maxCount = (int) (4 * Math.log(2 * keyBits * hashBits) + 1);
      while (same != 0xffffffff || diff != 0xffffffff) {
        int key1 = rand.nextInt();
        int key2 = key1 ^ (1 << i);
        int hash1 = function.hashInt(key1).asInt();
        int hash2 = function.hashInt(key2).asInt();
        same |= ~(hash1 ^ hash2);
        diff |= (hash1 ^ hash2);

        count++;
        if (count > maxCount) {
          Assert.fail("input bit(" + i + ") was found not to affect all " +
               hashBits + " output bits; The unaffected bits are " +
               "as follows: " + ~(same & diff) + ". This was " +
               "determined after " + count + " trials.");
        }
      }
    }
  }

  static void checkAvalanche(HashFunction function, int trials, double epsilon) {
    Random rand = new Random(0);
    int keyBits = 32;
    int hashBits = function.bits();
    for (int i = 0; i < keyBits; i++) {
      int[] same = new int[hashBits];
      int[] diff = new int[hashBits];
      for (int j = 0; j < trials; j++) {
        int key1 = rand.nextInt();
        int key2 = key1 ^ (1 << i);
        int hash1 = function.hashInt(key1).asInt();
        int hash2 = function.hashInt(key2).asInt();
        for (int k = 0; k < hashBits; k++) {
          if ((hash1 & (1 << k)) == (hash2 & (1 << k))) {
            same[k] += 1;
          } else {
            diff[k] += 1;
          }
        }
      }
      for (int j = 0; j < hashBits; j++) {
        double prob = (double) diff[j] / (double) (diff[j] + same[j]);
        Assert.assertEquals(0.50d, prob, epsilon);
      }
    }
  }


  static void checkNo2BitCharacteristics(HashFunction function) {
    Random rand = new Random(0);
    int keyBits = 32;

    for (int i = 0; i < keyBits; i++) {
      for (int j = 0; j < keyBits; j++) {
        if (j <= i) continue;
        int count = 0;
        int maxCount = 20;
        boolean diff = false;

        while (!diff) {
          int delta = (1 << i) | (1 << j);
          int key1 = rand.nextInt();
          int key2 = key1 ^ delta;

          int hash1 = function.hashInt(key1).asInt();
          int hash2 = function.hashInt(key2).asInt();

          if ((hash1 ^ hash2) != delta) {
            diff = true;
            continue;
          }


          count++;
          if (count > maxCount) {
            Assert.fail("2-bit delta (" + i + ", " + j + ") is likely a " +
                 "characteristic for this hash. This was " +
                 "determined after " + count + " trials");
          }
        }
      }
    }
  }


  static void check2BitAvalanche(HashFunction function, int trials, double epsilon) {
    Random rand = new Random(0);
    int keyBits = 32;
    int hashBits = function.bits();
    for (int bit1 = 0; bit1 < keyBits; bit1++) {
      for (int bit2 = 0; bit2 < keyBits; bit2++) {
        if (bit2 <= bit1) continue;
        int delta = (1 << bit1) | (1 << bit2);
        int[] same = new int[hashBits];
        int[] diff = new int[hashBits];
        for (int j = 0; j < trials; j++) {
          int key1 = rand.nextInt();
          int key2 = key1 ^ delta;
          int hash1 = function.hashInt(key1).asInt();
          int hash2 = function.hashInt(key2).asInt();
          for (int k = 0; k < hashBits; k++) {
            if ((hash1 & (1 << k)) == (hash2 & (1 << k))) {
              same[k] += 1;
            } else {
              diff[k] += 1;
            }
          }
        }
        for (int j = 0; j < hashBits; j++) {
          double prob = (double) diff[j] / (double) (diff[j] + same[j]);
          Assert.assertEquals(0.50d, prob, epsilon);
        }
      }
    }
  }


  static void assertInvariants(HashFunction hashFunction) {
    int objects = 100;
    Set<HashCode> hashcodes = Sets.newHashSetWithExpectedSize(objects);
    for (int i = 0; i < objects; i++) {
      Object o = new Object();
      HashCode hashcode1 = hashFunction.hashObject(o, HashTestUtils.BAD_FUNNEL);
      HashCode hashcode2 = hashFunction.hashObject(o, HashTestUtils.BAD_FUNNEL);
      Assert.assertEquals(hashcode1, hashcode2);
      Assert.assertEquals(hashFunction.bits(), hashcode1.bits());
      Assert.assertEquals(hashFunction.bits(), hashcode1.asBytes().length * 8);
      hashcodes.add(hashcode1);
    }
    Assert.assertTrue(hashcodes.size() > objects * 0.95);

    assertHashBytesThrowsCorrectExceptions(hashFunction);
    assertIndependentHashers(hashFunction);
    assertShortcutsAreEquivalent(hashFunction, 512);
  }

  static void assertHashBytesThrowsCorrectExceptions(HashFunction hashFunction) {
    hashFunction.hashBytes(new byte[64], 0, 0);

    try {
      hashFunction.hashBytes(new byte[128], -1, 128);
      Assert.fail();
    } catch (IndexOutOfBoundsException expected) {}
    try {
      hashFunction.hashBytes(new byte[128], 64, 256 /* too long len */);
      Assert.fail();
    } catch (IndexOutOfBoundsException expected) {}
    try {
      hashFunction.hashBytes(new byte[64], 0, -1);
      Assert.fail();
    } catch (IndexOutOfBoundsException expected) {}
  }

  static void assertIndependentHashers(HashFunction hashFunction) {
    int numActions = 100;
    HashCode expected1 = randomHash(hashFunction, new Random(1L), numActions);
    HashCode expected2 = randomHash(hashFunction, new Random(2L), numActions);

    Random random1 = new Random(1L);
    Random random2 = new Random(2L);
    Hasher hasher1 = hashFunction.newHasher();
    Hasher hasher2 = hashFunction.newHasher();
    for (int i = 0; i < numActions; i++) {
      RandomHasherAction.pickAtRandom(random1).performAction(random1, ImmutableSet.of(hasher1));
      RandomHasherAction.pickAtRandom(random2).performAction(random2, ImmutableSet.of(hasher2));
    }

    Assert.assertEquals(expected1, hasher1.hash());
    Assert.assertEquals(expected2, hasher2.hash());
  }

  static HashCode randomHash(HashFunction hashFunction, Random random, int numActions) {
    Hasher hasher = hashFunction.newHasher();
    for (int i = 0; i < numActions; i++) {
      RandomHasherAction.pickAtRandom(random).performAction(random, ImmutableSet.of(hasher));
    }
    return hasher.hash();
  }

  private static void assertShortcutsAreEquivalent(HashFunction hashFunction, int trials) {
    Random random = new Random(42085L);
    for (int i = 0; i < trials; i++) {
      assertHashBytesEquivalence(hashFunction, random);
      assertHashIntEquivalence(hashFunction, random);
      assertHashLongEquivalence(hashFunction, random);
      assertHashStringEquivalence(hashFunction, random);
      assertHashStringWithSurrogatesEquivalence(hashFunction, random);
    }
  }

  private static void assertHashBytesEquivalence(HashFunction hashFunction, Random random) {
    int size = random.nextInt(2048);
    byte[] bytes = new byte[size];
    random.nextBytes(bytes);
    assertEquals(hashFunction.hashBytes(bytes),
        hashFunction.newHasher(size).putBytes(bytes).hash());
    int off = random.nextInt(size);
    int len = random.nextInt(size - off);
    assertEquals(hashFunction.hashBytes(bytes, off, len),
        hashFunction.newHasher(size).putBytes(bytes, off, len).hash());
  }

  private static void assertHashIntEquivalence(HashFunction hashFunction, Random random) {
    int i = random.nextInt();
    assertEquals(hashFunction.hashInt(i),
        hashFunction.newHasher().putInt(i).hash());
  }

  private static void assertHashLongEquivalence(HashFunction hashFunction, Random random) {
    long l = random.nextLong();
    assertEquals(hashFunction.hashLong(l),
        hashFunction.newHasher().putLong(l).hash());
  }

  private static final ImmutableSet<Charset> CHARSETS = ImmutableSet.of(
      Charsets.ISO_8859_1,
      Charsets.US_ASCII,
      Charsets.UTF_16,
      Charsets.UTF_16BE,
      Charsets.UTF_16LE,
      Charsets.UTF_8);

  private static void assertHashStringEquivalence(HashFunction hashFunction, Random random) {
    new EqualsTester()
        .addEqualityGroup(
            hashFunction.hashUnencodedChars("abc"),
            hashFunction.newHasher().putUnencodedChars("abc").hash(),
            hashFunction.newHasher().putUnencodedChars("ab").putUnencodedChars("c").hash(),
            hashFunction.newHasher().putUnencodedChars("a").putUnencodedChars("bc").hash(),
            hashFunction.newHasher().putUnencodedChars("a").putUnencodedChars("b")
                .putUnencodedChars("c").hash(),
            hashFunction.newHasher().putChar('a').putUnencodedChars("bc").hash(),
            hashFunction.newHasher().putUnencodedChars("ab").putChar('c').hash(),
            hashFunction.newHasher().putChar('a').putChar('b').putChar('c').hash())
        .testEquals();

    int size = random.nextInt(2048);
    byte[] bytes = new byte[size];
    random.nextBytes(bytes);
    String string = new String(bytes);
    assertEquals(hashFunction.hashUnencodedChars(string),
        hashFunction.newHasher().putUnencodedChars(string).hash());
    for (Charset charset : CHARSETS) {
      assertEquals(hashFunction.hashString(string, charset),
          hashFunction.newHasher().putString(string, charset).hash());
    }
  }

  private static void assertHashStringWithSurrogatesEquivalence(
      HashFunction hashFunction, Random random) {
    int size = random.nextInt(8) + 1;
    char[] chars = new char[size];
    for (int i = 0; i < chars.length; i++) {
      chars[i] = random.nextBoolean() ? randomLowSurrogate(random) : randomHighSurrogate(random);
    }
    String string = new String(chars);
    assertEquals(hashFunction.hashUnencodedChars(string),
        hashFunction.newHasher().putUnencodedChars(string).hash());
  }

  static char randomLowSurrogate(Random random) {
    return (char) (Character.MIN_LOW_SURROGATE
        + random.nextInt(Character.MAX_LOW_SURROGATE - Character.MIN_LOW_SURROGATE + 1));
  }

  static char randomHighSurrogate(Random random) {
    return (char) (Character.MIN_HIGH_SURROGATE
        + random.nextInt(Character.MAX_HIGH_SURROGATE - Character.MIN_HIGH_SURROGATE + 1));
  }
}
