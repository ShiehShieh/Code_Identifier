
package com.google.common.base;

import com.google.gwt.user.client.rpc.SerializationException;
import com.google.gwt.user.client.rpc.SerializationStreamReader;
import com.google.gwt.user.client.rpc.SerializationStreamWriter;


public class PairwiseEquivalence_CustomFieldSerializer {

  private PairwiseEquivalence_CustomFieldSerializer() {}

  public static void deserialize(SerializationStreamReader reader,
      PairwiseEquivalence<?> instance) {}

  public static PairwiseEquivalence<?> instantiate(SerializationStreamReader reader)
      throws SerializationException {
    return create((Equivalence<?>) reader.readObject());
  }

  private static <T> PairwiseEquivalence<T> create(Equivalence<T> elementEquivalence) {
    return new PairwiseEquivalence<T>(elementEquivalence);
  }

  public static void serialize(SerializationStreamWriter writer, PairwiseEquivalence<?> instance)
      throws SerializationException {
    writer.writeObject(instance.elementEquivalence);
  }
}
