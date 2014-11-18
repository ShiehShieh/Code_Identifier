
package com.google.common.base;

import com.google.common.annotations.GwtCompatible;
import com.google.gwt.user.client.rpc.SerializationException;
import com.google.gwt.user.client.rpc.SerializationStreamReader;
import com.google.gwt.user.client.rpc.SerializationStreamWriter;


@GwtCompatible
public class Present_CustomFieldSerializer {
  public static void deserialize(SerializationStreamReader reader, Present<?> instance) {}

  public static Present<Object> instantiate(SerializationStreamReader reader)
      throws SerializationException {
    return (Present<Object>) Optional.of(reader.readObject());
  }

  public static void serialize(SerializationStreamWriter writer, Present<?> instance)
      throws SerializationException {
    writer.writeObject(instance.get());
  }
}
